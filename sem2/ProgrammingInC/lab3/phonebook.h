#include <stdio.h>

typedef struct phonebook_t
{
	char surname[23];
	char name[23];
	char second_name[23];
	long long number;
	bool operator<(const phonebook_t &other) const;
	bool operator>(const phonebook_t &other) const;
	bool operator<=(const phonebook_t &b) const;
	bool operator>=(const phonebook_t &b) const;
	bool operator==(const phonebook_t &b) const;
	void fill(const char *surname, const char *name, const char *sec, const long long num);
	int strcomp(const char *c1, const char *c2) const;
	void print(FILE *out) const;
} phonebook_t;