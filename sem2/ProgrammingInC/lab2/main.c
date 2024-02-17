#include "my_header.h"

// takes char arrays of size 4
int myatoi(unsigned char *arr)
{
	int pot = 1;
	int ans = 0;
	for (int i = 3; i >= 0; i--)
	{
		ans += (arr[i] * pot);
		pot <<= 8;
	}
	return ans;
}

void getChunk(FILE *in, int *errorcode, char *name, int len, unsigned char *data, int save, int pos)
{
	int num;
	num = fread(name, sizeof(char), 4, in);
	if (num < 4)
	{
		*errorcode = ERROR_INVALID_DATA;
		fprintf(stderr, "The name of the chunk could not be read\n");
		return;
	}

	int band = 0;
	if (name[0] == 'I' && (name[1] == 'D') && (name[2] == 'A') &&
		(name[3] == 'T'))
		band = 1;	 // only save IDAT or IHDR chunks
	if (name[0] == 'I' && (name[1] == 'H') && (name[2] == 'D') &&
		(name[3] == 'R'))
		band = 1;
	if (save && band)
	{
		num = fread(data + pos, sizeof(char), len, in);
		// no need to check for errors, because at this point
		// we know we have a correct PNG file.
		// skip CRC at the end
		fseek(in, sizeof(int), SEEK_CUR);
		// Again, all errors have been checked
		pos += len;
	}
	else
	{
		num = fseek(in, len, SEEK_CUR);
		if (num != 0)
		{
			*errorcode = ERROR_INVALID_DATA;
			fprintf(stderr, "some incorrect chunk was given\n");
			return;
		}

		// skiping last 4 bytes of every chunk
		num = fseek(in, sizeof(int), SEEK_CUR);
		if (num != 0)
		{
			fprintf(stderr, "No CRC at the end of some chunk\n");
			*errorcode = ERROR_INVALID_DATA;
			return;
		}
	}
	return;
}

int validatePNG(FILE *in, int *errorcode)
{
	int ans = 0;
	int length;
	int num;
	unsigned char png[8];
	unsigned char firma[8] = { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A };
	num = fread(png, sizeof(char), 8, in);
	if (num < 8)
	{
		*errorcode = ERROR_INVALID_DATA;
		fprintf(stderr, "The input file is not a PNG file\n");
		goto exiterror;
	}
	// validate png signature
	for (int i = 0; i < 8; i++)
	{
		if (firma[i] != png[i])
		{
			*errorcode = ERROR_INVALID_DATA;
			fprintf(stderr, "PNG signature corrupted\n");
			goto exiterror;
		}
	}

	char *keychunks[] = { "IHDR", "IDAT", "IEND" };

	int contend = 0;
	int contihdr = 0;

	while (1)
	{
		unsigned char len[4];
		int num = fread(len, sizeof(char), 4, in);
		if (num < 4)
		{
			if (contend == 1 && num == 0)
			{
				break;
			}
			*errorcode = ERROR_INVALID_DATA;
			fprintf(stderr, "Chunk corrupted, no IEND chunk or more chunks after it\n");
			goto exiterror;
		}
		int x = myatoi(len);
		char name[4];
		char *chunk;
		getChunk(in, errorcode, name, x, chunk, 0, 0);

		// validate error
		if (*errorcode != ERROR_SUCCESS)
		{
			goto exiterror;
		}

		int indice = -1;
		for (int i = 0; i < 3; i++)
		{
			int j;
			for (j = 0; j < 4; j++)
			{
				if (name[j] != keychunks[i][j])
				{
					break;
				}
			}
			if (j == 4)
			{
				indice = i;
				break;
			}
		}

		// validate name
		if (contend)
		{
			*errorcode = ERROR_INVALID_DATA;
			fprintf(stderr, "More chunks after IEND chunk\n");
			goto exiterror;
		}
		if (indice == 0)
		{
			if (contihdr)
			{
				*errorcode = ERROR_INVALID_DATA;
				fprintf(stderr, "IHDR chunk repeated\n");
				goto exiterror;
			}
			contihdr++;
			if (x != 13)
			{
				fprintf(stderr, "IHDR chunk corrupted\n");
				*errorcode = ERROR_INVALID_DATA;
				goto exiterror;
			}
		}
		else if (indice == 1)
		{
			if (!contihdr)
			{
				fprintf(stderr, "No IHDR chunk found\n");
				*errorcode = ERROR_INVALID_DATA;
				goto exiterror;
			}
			ans += x;
		}
		else if (indice == 2)
		{
			if (!contihdr)
			{
				fprintf(stderr, "No IHDR chunk found, anticipated IEND\n");
				*errorcode = ERROR_INVALID_DATA;
				goto exiterror;
			}
			contend++;
		}
	}

	return ans;

exiterror:
	return 0;
}

unsigned char *buildchuncks(FILE *in, int *errorcode, int total, unsigned char *header)
{
	unsigned char *ans = malloc(total);
	if (!ans)
	{
		*errorcode = ERROR_NOT_ENOUGH_MEMORY;
		fprintf(stderr, "The chunks could not be saved (file too large)\n");
		goto exiterror;
	}
	unsigned char len[4];
	int num;
	int x;
	char name[4];

	int pos = 0;

	while (pos < total)
	{
		// get size;
		num = fread(len, sizeof(char), 4, in);
		x = myatoi(len);
		getChunk(in, errorcode, name, x, ans, 1, pos);
		if (name[0] == 'I' && name[1] == 'D' && name[2] == 'A' && name[3] == 'T')
			pos += x;
		if (*errorcode != ERROR_SUCCESS)
		{
			goto exiterror;
		}
	}
	return ans;

exiterror:
	return NULL;
}

int paeth(int a, int b, int c)
{
	int p = a + b - c;
	int pa = abs(p - a);
	int pb = abs(p - b);
	int pc = abs(p - c);
	int pr;
	if (pa <= pb && pa <= pc)
	{
		pr = a;
	}
	else if (pb <= pc)
	{
		pr = b;
	}
	else
	{
		pr = c;
	}
	return pr % 256;
}

void filtering(FILE *out, unsigned char *data, int height, int width, int colortype, int *errorcode, int total)
{
	if (colortype == 2)
	{
		fprintf(out, "%s\n", "P6");
	}
	else
	{
		fprintf(out, "%s\n", "P5");
	}
	fprintf(out, "%d %d\n", width, height);
	fprintf(out, "%d\n", 255);
	int pos = 0;
	int tam = colortype + 1;
	for (int i = 0; i < height; i++)
	{
		int modo = data[pos++];
		// printf("\n%d\n", modo);
		for (int j = 0; j < width; j++)
		{
			for (int k = 0; k < tam; k++)
			{
				int a = pos - tam;
				int b = pos - width - 1;
				int c = pos - width - tam - 1;
				if (j == 0)
				{
					a--;
					c--;
				}
				if (modo == 1)
				{
					data[pos] += (a > 0 ? data[a] : 0);
				}
				else if (modo == 2)
				{
					data[pos] += (b > 0 ? data[b] : 0);
				}
				else if (modo == 3)
				{
					data[pos] += (((int)(a > 0 ? data[a] : 0) + (int)(b > 0 ? data[b] : 0)) >> 1) % 256;
				}
				else if (modo == 4)
				{
					data[pos] += paeth(a > 0 ? data[a] : 0, b > 0 ? data[b] : 0, c > 0 ? data[c] : 0);
				}
				else if (modo != 0)
				{
					*errorcode = ERROR_INVALID_DATA;
					fprintf(stderr, "Unrecognized filter type for png file\n");
					return;
				}
				pos++;
			}
			pos -= tam;
			fwrite(data + pos, sizeof(unsigned char), tam, out);
			pos += tam;
		}
		// printf("pos: %d total: %d", pos, total);
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		fprintf(stderr, "Incorrect number of arguments\n");
		return ERROR_INVALID_PARAMETER;
	}
	FILE *in = fopen(argv[1], "rb");
	if (in == NULL)
	{
		fprintf(stderr, "Input file could not be opened\n");
		return ERROR_FILE_NOT_FOUND;
	}
	int errorcode = ERROR_SUCCESS;

	int total;

	total = validatePNG(in, &errorcode);
	fclose(in);
	if (errorcode != ERROR_SUCCESS)
	{
		return errorcode;
	}

	// read data
	// no error because we cheked before that the file could be opened
	FILE *in1 = fopen(argv[1], "rb");

	// skip signature
	fseek(in1, sizeof(int) * 2, SEEK_CUR);

	// saving header
	unsigned char len[4];
	int headersize;
	char name[4];
	fread(len, sizeof(char), 4, in1);
	headersize = myatoi(len);
	unsigned char *header = malloc(headersize);

	if (header == NULL)
	{
		errorcode = ERROR_NOT_ENOUGH_MEMORY;
		fprintf(stderr, "Chunks could not be fully saved\n");
		fclose(in1);
		return errorcode;
	}
	getChunk(in1, &errorcode, name, headersize, header, 1, 0);

	unsigned char *data = buildchuncks(in1, &errorcode, total, header);

	fclose(in1);
	if (errorcode != ERROR_SUCCESS)
	{
		free(header);
		if (data != NULL)
			free(data);
		return errorcode;
	}

	int height, width, colortype, filter;
	len[0] = header[0];
	len[1] = header[1];
	len[2] = header[2];
	len[3] = header[3];
	width = myatoi(len);
	len[0] = header[4];
	len[1] = header[5];
	len[2] = header[6];
	len[3] = header[7];
	height = myatoi(len);
	colortype = header[9];
	filter = header[11];

	unsigned char *dest = malloc(height * (width * (colortype + 1) + 1));
	if (dest == NULL)
	{
		fprintf(stderr, "Not enought memory for decompression\n");
		errorcode = ERROR_NOT_ENOUGH_MEMORY;
		free(header);
		free(data);
		return errorcode;
	}

	FILE *out = fopen(argv[2], "wb");
#ifdef ZLIB
	uLong dataLen = total;
	uLong destLen = (height * (width * (colortype + 1) + 1));
	int result = uncompress((Bytef *)dest, &destLen, (const Bytef *)data, dataLen);

	if (result == Z_OK)
	{
		filtering(out, dest, height, width, colortype, &errorcode, destLen);
		// no errorcode checking because it is already the end of the code
	}
	else
	{
		errorcode = ERROR_UNKNOWN;
		fprintf(stderr, "decompression error\n");
	}
#endif

	fclose(out);
	free(dest);
	free(data);
	free(header);
	return errorcode;
}