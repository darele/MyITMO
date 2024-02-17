#include "LN.h"

// Constructors

LN::LN(const char *numero)
{
	size_t charnum = count_symbols(numero);
	size = charnum;
	sign = false;
	value = NULL;
	notNumber = false;
	size_t i = 0;
	if (numero[0] == '-')
	{
		sign = true;
		size--;
		i = 1;
	}
	// ignore leading zeroes
	// the number has at least one digit
	for (; i < charnum - 1; i++)
	{
		if (numero[i] != '0')
			break;
		size--;
	}
	// build the number
	size_t j = size - 1;
	value = (char *)malloc(size);
	if (value == NULL)
	{
		throw ALLOC_ERROR;
	}
	for (; i < charnum; i++, j--)
	{
		value[j] = numero[i] - '0';
	}
	if (size == 1 && value[0] == 0)
	{
		sign = false;
	}
}

LN::LN(long long v)
{
	if (v == 0)
	{
		value = (char *)malloc(1);
		if (value == NULL)
		{
			throw ALLOC_ERROR;
		}
		value[0] = 0;
		size = 1;
		sign = false;
		notNumber = false;
		return;
	}
	long long x = v;
	while (x != 0LL)
	{
		x /= 10;
		size++;
	}
	value = (char *)malloc(size);
	if (value == NULL)
	{
		throw ALLOC_ERROR;
	}
	x = v;
	size_t i = 0;
	while (x != 0LL)
	{
		int temp = (x % 10);
		value[i++] = abs(temp);
		x /= 10;
	}
	if (v >= 0)
	{
		sign = false;
	}
	else
	{
		sign = true;
	}
	notNumber = false;
}

LN::LN(std::string_view numero)
{
	size_t charnum = numero.size();
	size = charnum;
	sign = false;
	value = NULL;
	notNumber = false;
	size_t i = 0;
	if (numero[0] == '-')
	{
		sign = true;
		size--;
		i = 1;
	}
	// ignore leading zeroes
	// the number has at least one digit
	for (; i < charnum - 1; i++)
	{
		if (numero[i] != '0')
			break;
		size--;
	}
	// build the number
	size_t j = size - 1;
	value = (char *)malloc(size);
	if (value == NULL)
	{
		throw ALLOC_ERROR;
	}
	for (; i < charnum; i++, j--)
	{
		value[j] = numero[i] - '0';
	}
	if (size == 1 && value[0] == 0)
	{
		sign = false;
	}
}

// Copy constructor
LN::LN(const LN &other)
{
	// printf("Copy constructor called\n");
	copy(other);
}

// Move constructor
LN::LN(LN &&other) noexcept : size(other.size), sign(other.sign), notNumber(other.notNumber), value(other.value)
{
	// printf("Move constructor called\n");
	other.value = nullptr;
}

// String literal
LN operator"" _ln(const char *s)
{
	return LN{ s };
}