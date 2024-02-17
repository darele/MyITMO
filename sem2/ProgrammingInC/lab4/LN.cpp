#include "LN.h"

// Output
void LN::print(FILE *out) const
{
	if (notNumber)
	{
		fprintf(out, "%s\n", "NaN");
	}
	else
	{
		if (size == 0)
			return;
		// trailing zeroes if there is any
		int i = size - 1;
		for (; i > 0; i--)
		{
			if (value[i])
				break;
		}
		if (sign)
		{
			// conditions for printing the sign explicitely
			if (i > 0 || value[0])
				fprintf(out, "-");
		}
		// every digit except the last
		for (; i > 0; i--)
		{
			fprintf(out, "%c", value[i] + '0');
		}
		// If the number is zero, this separate line helps
		fprintf(out, "%c\n", value[0] + '0');
	}
}

// Comparators
bool LN::operator<(const LN &op2) const
{
	if (isNotNumber() || op2.isNotNumber())
	{
		return 0;
	}
	return valuecomparator(*this, op2) == -1;
}
bool LN::operator>(const LN &op2) const
{
	if (isNotNumber() || op2.isNotNumber())
	{
		return 0;
	}
	return valuecomparator(*this, op2) == 1;
}
bool LN::operator==(const LN &op2) const
{
	if (isNotNumber() || op2.isNotNumber())
	{
		return 0;
	}
	return valuecomparator(*this, op2) == 0;
}
bool LN::operator!=(const LN &op2) const
{
	if (isNotNumber() || op2.isNotNumber())
	{
		return 1;
	}
	return (*this < op2) || (*this > op2);
}
bool LN::operator<=(const LN &op2) const
{
	if (isNotNumber() || op2.isNotNumber())
	{
		return 0;
	}
	return !(*this > op2);
}
bool LN::operator>=(const LN &op2) const
{
	if (isNotNumber() || op2.isNotNumber())
	{
		return 0;
	}
	return !(*this < op2);
}

size_t LN::getSize() const
{
	return size;
}

void LN::undefine()
{
	if (value != NULL)
		free(value);
	value = NULL;
	size = 0;
	notNumber = 1;
	sign = 0;
}

int LN::operator[](size_t ind) const
{
	if (ind < 0 || ind > size)
		return 0;
	return value[ind];
}

bool LN::getSign() const
{
	return sign;
}

bool LN::isNotNumber() const
{
	return notNumber;
}

void LN::changeSign()
{
	sign = sign ? 0 : 1;
}

bool LN::isZero() const
{
	return size == 1 && value[0] == 0;
}

#if 0
LN::operator long long()
{
	LN min = LN("-9223372036854775808");
	LN max = LN("9223372036854775807");
	if (*this < min || *this > max)
	{
		throw OVERFLOW_ERROR;
	}
	long long ans = 0;
	for (size_t i = size - 1; i > 0; i--)
	{
		ans += value[i];
		ans *= 10;
	}
	ans += value[0];
	if (sign && ans > 0LL)
		ans *= -1;
	return ans;
}
#endif

// Destructor
LN::~LN()
{
	if (value != NULL)
	{
		free(value);
	}
	value = NULL;
}