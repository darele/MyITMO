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

void printSubstring(const char* s, size_t beg, size_t e) {
    for (size_t i = beg; i < e; i++) {
        printf("%c", s[i]);
    }
}

int main() {
    const char* src = "?";
	const char* shell = "&";
    char findQuestion = '?';
	char findAmp = "&";
    const char* pointerP = strchr(src, findQuestion);
	const char* pointerQ = strchr(src, findAmp);
    size_t p = pointerP - src;
	size_t q = pointerQ - src;
    size_t srcLength = strlen(src);
	size_t shellLength = strlen(shell);
    const char* escapedSource = escape(src, srcLength);
	const char* escapedShell = escape(shell, shellLength);
    printSubstring(src, 0, p);
	printSubstring(escapedShell, 0, shellLength);
	printSubstring(src, p + 1, q);
    printSubstring(escapedSource, 0, strlen(escapedSource));
    printSubstring(src, q + 1, srcLength);
    return 0; 
}

