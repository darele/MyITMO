#include <cstring>
#include <stdio.h>
#ifndef PHONEBOOK_H
	#define PHONEBOOK_H
	#include "phonebook.h"
#endif

bool phonebook_t::operator<(const phonebook_t &b) const
{
	if (strcomp(surname, b.surname) >= 0)
	{
		if (strcomp(surname, b.surname) == 0)
		{
			if (strcomp(name, b.name) >= 0)
			{
				if (strcomp(name, b.name) == 0)
				{
					if (strcomp(second_name, b.second_name) >= 0)
					{
						if (strcomp(second_name, b.second_name) == 0)
						{
							return number < b.number;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

bool phonebook_t::operator>(const phonebook_t &b) const
{
	if (strcomp(surname, b.surname) < 1)
	{
		if (strcomp(surname, b.surname) == 0)
		{
			if (strcomp(name, b.name) < 1)
			{
				if (strcomp(name, b.name) == 0)
				{
					if (strcomp(second_name, b.second_name) < 1)
					{
						if (strcomp(second_name, b.second_name) == 0)
						{
							return number > b.number;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

bool phonebook_t::operator<=(const phonebook_t &b) const
{
	return !(*this > b);
}

bool phonebook_t::operator>=(const phonebook_t &b) const
{
	return !(*this < b);
}

bool phonebook_t::operator==(const phonebook_t &b) const
{
	return !(*this > b) && !(*this < b);
}

void phonebook_t::fill(const char *surname, const char *name, const char *sec, const long long num)
{
	strcpy(this->surname, surname);
	strcpy(this->name, name);
	strcpy(this->second_name, sec);
	this->number = num;
}

void phonebook_t::print(FILE *out) const
{
	fprintf(out, "%s %s %s %lld\n", surname, name, second_name, number);
}

int phonebook_t::strcomp(const char *c1, const char *c2) const
{
	// 0 = equal
	// 1 = c1 < c2
	//-1 = c1 > c2
	while (*c1 && *c2)
	{
		if (*c1 < *c2)
		{
			return 1;
		}
		else if (*c1 > *c2)
		{
			return -1;
		}
		c1++;
		c2++;
	}
	if (*c1 == 0 && *c2 == 0)
	{
		return 0;
	}
	return (*c1 == 0) ? 1 : -1;
}