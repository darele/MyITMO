#include "LN.h"

// Helping functions
size_t count_symbols(const char *numero)
{
	size_t ans;
	for (ans = 0; numero[ans]; ans++)
		;
	return ans;
}

LN absln(const LN &op)
{
	LN ans = op;
	if (ans.getSign())
		ans.changeSign();
	return ans;
}

int absolutecomparator(const LN &op1, const LN &op2)
{
	//-1 this < op2
	// 0 this == op2
	// 1 this > op2
	if (op1.getSize() > op2.getSize())
		return 1;
	if (op1.getSize() < op2.getSize())
		return -1;
	size_t i = op1.getSize() - 1;
	while (i > 0)
	{
		if (op1[i] < op2[i])
			return -1;
		if (op2[i] < op1[i])
			return 1;
		i--;
	}
	return op1[i] < op2[i] ? -1 : op1[i] > op2[i];
	return 0;
}

int valuecomparator(const LN &op1, const LN &op2)
{
	//-1 this < op2
	// 0 this == op2
	// 1 this > op2

	// Comparing 0
	if (op1.isZero() && op2.isZero())
		return 0;

	if (op1.getSign() && !op2.getSign())
		return -1;
	if (op2.getSign() && !op1.getSign())
		return 1;
	if (op1.getSign())
	{
		// In case of negative numbers, the least
		// absolute value is greater
		int temp = absolutecomparator(op1, op2);
		if (temp == -1)
			return 1;
		if (temp == 1)
			return -1;
		return temp;
	}
	return absolutecomparator(op1, op2);
}

LN addabsolute(const LN &op1, const LN &op2)
{
	int carry = 0;
	size_t menor = op1.getSize() < op2.getSize() ? op1.getSize() : op2.getSize();
	size_t i;
	size_t newsize = 0;
	for (i = 0; i < menor; i++)
	{
		carry = ((op1[i] + op2[i] + carry) > 9);
		newsize++;
	}
	for (; i < op1.getSize(); i++)
	{
		carry = ((op1[i] + carry) > 9);
		newsize++;
	}
	for (; i < op2.getSize(); i++)
	{
		carry = ((op2[i] + carry) > 9);
		newsize++;
	}
	if (carry)
		newsize++;
	char *ans = (char *)malloc(newsize + 1);
	if (ans == NULL)
	{
		throw ALLOC_ERROR;
	}
	carry = 0;
	for (i = 0; i < menor; i++)
	{
		ans[i] = (op1[i] + op2[i] + carry) % 10;
		carry = ((op1[i] + op2[i] + carry) > 9);
	}
	for (; i < op1.getSize(); i++)
	{
		ans[i] = (op1[i] + carry) % 10;
		carry = ((op1[i] + carry) > 9);
	}
	for (; i < op2.getSize(); i++)
	{
		ans[i] = (op2[i] + carry) % 10;
		carry = ((op2[i] + carry) > 9);
	}
	if (carry)
		ans[i] = 1;
	toHumanReadable(ans, newsize);
	return LN{ ans };
}

LN subtractabsolute(const LN &op1, const LN &op2)
{
	int carry = 0;
	size_t menor = op1.getSize() < op2.getSize() ? op1.getSize() : op2.getSize();
	size_t i;
	size_t newsize = op1.getSize() + op2.getSize() - menor;
	char *ans = (char *)malloc(newsize + 1);
	if (ans == NULL)
	{
		throw ALLOC_ERROR;
	}
	int temp = absolutecomparator(op1, op2);
	for (i = 0; i < menor; i++)
	{
		if (temp == 1)
		{
			ans[i] = (op1[i] - op2[i] - carry + 10) % 10;
			carry = ((op1[i] - op2[i] - carry) < 0);
		}
		else
		{
			ans[i] = (op2[i] - op1[i] - carry + 10) % 10;
			carry = ((op2[i] - op1[i] - carry) < 0);
		}
	}
	for (; i < op1.getSize(); i++)
	{
		ans[i] = (op1[i] - carry + 10) % 10;
		carry = ((op1[i] - carry) < 0);
	}
	for (; i < op2.getSize(); i++)
	{
		ans[i] = (op2[i] - carry + 10) % 10;
		carry = ((op2[i] - carry) < 0);
	}
	// ignore leading zeros
	size_t j = newsize - 1;
	while (j > 0 && ans[j] == 0)
	{
		j--;
		newsize--;
	}
	// In this case, only the part of the number that is not leading zero is returned
	//(the rest is just zeros)
	toHumanReadable(ans, newsize);
	return LN{ ans };
}

// Expects a string of digits in LN form
// Reverses and add '0' to its values so that it becomes
// human readable
// adds 0 to the final character, so that it could be used
// In the const char * constructor.
// Expects string legth to be size + 1
void toHumanReadable(char *ans, size_t size)
{
	// reverse string
	size_t i;
	for (i = 0; i < size - i - 1; i++)
	{
		char temp = ans[i];
		ans[i] = ans[size - i - 1];
		ans[size - i - 1] = temp;
	}
	// Human readable
	for (i = 0; i < size; i++)
	{
		ans[i] += '0';
	}
	// zero terminate
	ans[size] = 0;
}

void LN::copy(const LN &op2)
{
	if (value != NULL)
		free(value);
	value = NULL;
	value = (char *)malloc(op2.getSize());
	if (value == NULL)
	{
		throw ALLOC_ERROR;
	}
	notNumber = op2.isNotNumber();
	sign = op2.getSign();
	size = op2.getSize();
	for (size_t i = 0; i < op2.getSize(); i++)
	{
		value[i] = op2[i];
	}
}

LN LN::multiply(int factor) const
{
	LN ans = 0_ln;
	for (int i = 0; i < factor; i++)
	{
		ans += *this;
	}
	return ans;
}

LN divby2(const LN &op)
{
	// own verification because for 1 is also true
	if (op.getSize() == 1 && op[0] <= 1)
	{
		LN ans = 0_ln;
		return ans;
	}
	size_t newsize = op.getSize();
	if (op[op.getSize() - 1] == 1)
		newsize--;
	char *newvalue = (char *)malloc(newsize + 1);
	size_t i = op.getSize() - 1;
	i -= (op[op.getSize() - 1] == 1);
	int carry = (op[op.getSize() - 1] == 1);
	for (; i > 0; i--)
	{
		newvalue[i] = ((op[i] + 10 * carry) / 2);
		carry = (op[i] & 1);
	}
	newvalue[0] = ((op[0] + 10 * carry) / 2);
	toHumanReadable(newvalue, newsize);
	return LN{ newvalue };
}