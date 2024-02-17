#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* escape(const char* arr, size_t n)
{
	char* temp = (char*) malloc((n + 1) + (n + 1));
	size_t id = 0;
	for (size_t i = 0; i < n; i++, id++)
	{
		char c = arr[i];
		switch (c)
		{
			case '\\':
				temp[id] = '\\';
				id++;
				temp[id] = '\\';
				break;
			case '"':
				temp[id] = '\\';
				id++;
				temp[id] = '"';
				break;
			case '\n':
				temp[id] = '\\';
				id++;
				temp[id] = 'n';
				break;
			case '$':
				temp[id] = '\\';
				id++;
				temp[id] = '$';
				break;
            case '\'':
                temp[id] = '\\';
                id++;
                temp[id] = '\'';
                break;
			default:
				temp[id] = c;
				break;
		}
	}
	temp[id] = 0;
	return temp;
}

int main() {
	const int max_input_size = 100000;
	char* input = (char*) malloc(max_input_size);
	char buffer;
	size_t index = 0;
	while (1) {
		int temp = scanf("%c", &buffer);
		if (temp != 1 || temp == EOF) {
			break;
		}
		input[index++] = buffer;
	}
	input[index] = 0;
	//printf("Input: %s", input);
	char* ans = escape(input, index);
	printf("%s", ans);
	return 0;
}