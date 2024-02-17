#include <string.h>
#ifndef RETURN
#	define RETURN
#	include "return_codes.h"
#endif
#include "LN.h"

int readline(char *line, FILE *in, size_t &size)
{
	int x;
	while (1)
	{
		x = fscanf(in, "%c", line + size);
		if (x == -1)
			break;
		if (line[size] == '\n' || line[size] == 0 || line[size] == '\0')
			break;
		size++;
	}
	line[size] = 0;
	return x;
}

size_t numbers(FILE *in, size_t &maxw)
{
	char c[1];
	size_t ans = 0;
	size_t temp = 0;
	int x;
	bool symbol = false;
	bool number = false;
	size_t curw = 0;
	while (1)
	{
		x = fscanf(in, "%c", c);
		if (x == -1)
			break;
		if (c[0] == '\n' || c[0] == 0)
		{
			maxw = maxw > curw ? maxw : curw;
			if (number)
				temp++;
			else if (symbol)
				if (temp > 0)
					temp--;
			ans = ans > temp ? ans : temp;
			symbol = false;
			number = false;
			curw++;
			continue;
		}
		curw++;
		if (c[0] >= '0' && c[0] <= '9')
		{
			number = true;
		}
		else if (c[0] == 'N' || c[0] == 'n')
		{
			number = true;
		}
		else if (c[0] != '~' && c[0] != '_')
		{
			symbol = true;
		}
	}
	maxw = maxw > curw ? maxw : curw;
	if (number)
		temp++;
	else if (symbol)
		if (temp > 0)
			temp--;
	ans = ans > temp ? ans : temp;
	return ans;
}

void push(LN *nums, size_t &head, LN val)
{
	nums[head++] = val;
}

LN pop(LN *nums, size_t &head)
{
	if (head == 0)
		return 0_ln;
	return nums[--head];
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		fprintf(stderr, "Incorrect number of arguments given");
		return ERROR_INVALID_PARAMETER;
	}
	FILE *in, *out;
	in = out = NULL;
	in = fopen(argv[1], "r");
	if (in == NULL)
	{
		fprintf(stderr, "Input file %s, could not be opened.\n", argv[1]);
		return ERROR_FILE_NOT_FOUND;
	}
	int errorcode = ERROR_SUCCESS;

	try
	{
		size_t maxw = 0;
		size_t numeros = numbers(in, maxw);
		LN *nums = new (std::nothrow) LN[numeros];
		size_t head = 0;
		if (nums == nullptr)
		{
			fprintf(stderr, "Could not allocate memory for %zu numbers.\n", numeros);
			errorcode = ERROR_NOT_ENOUGH_MEMORY;
			goto closeAndExit;
		}
		fseek(in, 0, SEEK_SET);
		char *line = (char *)malloc(maxw + 1);
		if (line == NULL)
		{
			fprintf(stderr, "Could not allocate memory for %zu characters.\n", maxw);
			errorcode = ERROR_NOT_ENOUGH_MEMORY;
			goto closeAndExit;
		}
		LN a, b;
		while (1)
		{
			size_t s = 0;
			int x = readline(line, in, s);
			// parse number
			if (line[0] >= '0' && line[0] <= '9')
			{
				push(nums, head, LN(line));
			}
			else if (line[0] == '-')
			{
				// if line lenght is more than 1, it is surely a negative number
				if (s > 1)
				{
					push(nums, head, LN(line));
				}
				else
				{
					// Let's parse - operator
					b = pop(nums, head);
					a = pop(nums, head);
					push(nums, head, a - b);
				}
			}
			else if (line[0] == 'N' || line[0] == 'n')
			{
				// reading nans
				push(nums, head, 1_ln / 0_ln);
			}

			// Parse operators
			if (line[0] == '+')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				push(nums, head, a + b);
			}
			else if (line[0] == '*')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				push(nums, head, a * b);
			}
			else if (line[0] == '/')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				push(nums, head, a / b);
			}
			else if (line[0] == '%')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				push(nums, head, a % b);
			}
			else if (line[0] == '~')
			{
				a = pop(nums, head);
				push(nums, head, ~a);
			}
			else if (line[0] == '_')
			{
				a = pop(nums, head);
				push(nums, head, -a);
			}
			else if (line[0] == '<')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				if (s > 1 && line[1] == '=')
					push(nums, head, LN((long long)(a <= b)));
				else
					push(nums, head, LN((long long)(a < b)));
			}
			else if (line[0] == '>')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				if (s > 1 && line[1] == '=')
					push(nums, head, LN((long long)(a >= b)));
				else
					push(nums, head, LN((long long)(a > b)));
			}
			else if (line[0] == '=')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				push(nums, head, LN((long long)(a == b)));
			}
			else if (line[0] == '!')
			{
				b = pop(nums, head);
				a = pop(nums, head);
				push(nums, head, LN((long long)(a != b)));
			}

			if (x == -1)
				break;
		}

		out = fopen(argv[2], "wt");
		while (head > 0)
		{
			nums[--head].print(out);
		}
		delete[] nums;
		goto closeAndExit;
	} catch (const char *m)
	{
		fprintf(stderr, "Error: %s\n", m);
		if (strcmp(m, ALLOC_ERROR) == 0)
		{
			errorcode = ERROR_NOT_ENOUGH_MEMORY;
		}
		else if (strcmp(m, OVERFLOW_ERROR) == 0)
		{
			errorcode = ERROR_UNSUPPORTED;
		}
		else
		{
			errorcode = ERROR_UNKNOWN;
		}
		goto closeAndExit;
	}

	goto closeAndExit;
closeAndExit:
	if (in != NULL)
	{
		fclose(in);
	}
	if (out != NULL)
	{
		fclose(out);
	}

	return errorcode;
}