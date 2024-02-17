#include <cstdlib>
#include <new>
#include <string.h>
#ifndef PHONEBOOK_H
	#define PHONEBOOK_H
	#include "phonebook.h"
#endif
#ifndef QUICKSORT_H
	#define QUICKSORT_H
	#include "quicksort.h"
#endif
#ifndef RETURN_H
	#define RETURN_H
	#include "return_codes.h"
#endif
using namespace std;

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		fprintf(stderr, "Invalid number of arguments given");
		return ERROR_INVALID_PARAMETER;
	}
	FILE *in = NULL;
	FILE *out = NULL;
	in = fopen(argv[1], "r");
	if (in == NULL)
	{
		fprintf(stderr, "Could not open input file\n");
		return ERROR_NOT_FOUND;
	}
	int errorcode = ERROR_SUCCESS;
	// read data
	char type[10] = "";
	char mode[10] = "";
	fscanf(in, "%s\n%s", type, mode);
	// size
	int size;
	fscanf(in, "%d", &size);
	if (strcmp(type, "int") == 0)
	{
		int *arr = (int *)malloc(sizeof(int) * size);
		if (arr == NULL)
		{
			fprintf(stderr, "The input array could not be allocated.\n");
			errorcode = ERROR_NOT_ENOUGH_MEMORY;
			goto close_and_exit;
		}
		// read array
		for (int i = 0; i < size; i++)
		{
			fscanf(in, "%d", &arr[i]);
		}
		fclose(in);
		if (strcmp(mode, "ascending") == 0)
			quicksort< int, false >(arr, size);
		else
			quicksort< int, true >(arr, size);
		out = fopen(argv[2], "w");
		for (int i = 0; i < size; i++)
		{
			fprintf(out, "%d\n", arr[i]);
		}
		free(arr);
	}
	else if (strcmp(type, "float") == 0)
	{
		float *arr = (float *)malloc(sizeof(float) * size);
		if (arr == NULL)
		{
			fprintf(stderr, "The input array could not be allocated.\n");
			errorcode = ERROR_NOT_ENOUGH_MEMORY;
			goto close_and_exit;
		}
		for (int i = 0; i < size; i++)
		{
			fscanf(in, "%f", &arr[i]);
		}
		fclose(in);
		if (strcmp(mode, "ascending") == 0)
			quicksort< float, false >(arr, size);
		else
			quicksort< float, true >(arr, size);
		out = fopen(argv[2], "w");
		for (int i = 0; i < size; i++)
		{
			fprintf(out, "%g\n", arr[i]);
		}
		free(arr);
	}
	else if (strcmp(type, "phonebook") == 0)
	{
		phonebook_t *arr = new (nothrow) phonebook_t[size];
		if (arr == nullptr)
		{
			fprintf(stderr, "The input array could not be allocated.\n");
			errorcode = ERROR_NOT_ENOUGH_MEMORY;
			goto close_and_exit;
		}
		char surname[20];
		char name[20];
		char sec[20];
		long long num;
		for (int i = 0; i < size; i++)
		{
			fscanf(in, "%s %s %s %lld\n", surname, name, sec, &num);
			arr[i].fill(surname, name, sec, num);
		}
		fclose(in);
		if (strcmp(mode, "ascending") == 0)
			quicksort< phonebook_t, false >(arr, size);
		else
			quicksort< phonebook_t, true >(arr, size);
		out = fopen(argv[2], "w");
		for (int i = 0; i < size; i++)
		{
			arr[i].print(out);
		}
		delete[] arr;
	}
	else
	{
		fprintf(stderr, "Invalid data type\n");
		errorcode = ERROR_INVALID_PARAMETER;
	}
	goto close_and_exit;

close_and_exit:
	if (in == NULL)
		fclose(in);
	if (out == NULL)
		fclose(out);
	goto exit_code;

exit_code:
	return errorcode;
}