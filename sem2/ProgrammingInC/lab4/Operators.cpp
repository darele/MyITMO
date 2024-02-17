#include "LN.h"

// Operators
LN LN::operator+(const LN &op2) const
{
	if (notNumber || op2.notNumber)
	{
		LN ans;
		ans.undefine();
		return ans;
	}

	bool nuevosigno;
	LN ans;
	if (sign == op2.sign)
	{
		// equal signs are summed
		nuevosigno = sign;
		ans = addabsolute(*this, op2);
	}
	else
	{
		// diferent signs are subtracted by absolute value
		if (absolutecomparator(*this, op2) == -1)
		{
			nuevosigno = op2.sign;
		}
		else
		{
			nuevosigno = sign;
		}
		ans = subtractabsolute(*this, op2);
	}
	if (nuevosigno)
		ans.changeSign();
	return ans;
}

LN LN::operator-(const LN &op2) const
{
	if (notNumber || op2.notNumber)
	{
		LN ans;
		ans.undefine();
		return ans;
	}
	LN ans = op2;
	ans.changeSign();
	ans = *this + ans;
	return ans;
}

LN LN::operator-() const
{
	LN ans = *this;
	ans.changeSign();
	return ans;
}

LN LN::operator<<(size_t factor)
{
	char *newvalue = (char *)malloc(size + factor + 1);
	if (newvalue == NULL)
	{
		throw ALLOC_ERROR;
	}
	for (size_t i = 0; i < size; i++)
	{
		newvalue[i + factor] = value[i];
	}
	for (size_t i = 0; i < factor; i++)
	{
		newvalue[i] = 0;
	}
	toHumanReadable(newvalue, size + factor);
	return LN(newvalue);
}

LN LN::operator*(const LN &other) const
{
	LN ans;
	if (isNotNumber() || other.isNotNumber())
	{
		ans.undefine();
		return ans;
	}
	// Some small optimization
	ans = 0_ln;
	if (absolutecomparator(*this, other) == -1)
	{
		for (size_t i = 0; i < getSize(); i++)
		{
			ans += (other.multiply(operator[](i)) << i);
		}
	}
	else
	{
		for (size_t i = 0; i < other.getSize(); i++)
		{
			ans += (multiply(other[i]) << i);
		}
	}
	if (sign != other.sign)
		ans.changeSign();
	return ans;
}

LN LN::operator/(const LN &op2) const
{
	LN ans;
	if (isNotNumber() || op2.isNotNumber())
	{
		ans.undefine();
		return ans;
	}
	if (op2.isZero())
	{
		ans.undefine();
		return ans;
	}
	LN thisabs = absln(*this);
	LN otherabs = absln(op2);
	LN ini = 0_ln;
	LN fin = thisabs;
	LN mid;
	mid = divby2(ini + fin);
	while (ini < fin)
	{
		if (mid * otherabs <= thisabs)
		{
			ini = mid + 1_ln;
		}
		else
		{
			fin = mid - 1_ln;
		}
		mid = divby2(ini + fin);
	}
	if ((mid + 1_ln) * otherabs <= thisabs)
		ans = mid + 1_ln;
	else if (mid * otherabs <= thisabs)
		ans = mid;
	else
		ans = mid - 1_ln;
	if (sign != op2.sign)
		ans.changeSign();
	return ans;
}

LN LN::operator%(const LN &op2) const
{
	if (notNumber || op2.notNumber)
	{
		LN ans;
		ans.undefine();
		return ans;
	}
	LN ans = (*this) - ((*this) / op2) * op2;
	return ans;
}

LN LN::operator~() const
{
	if (notNumber)
	{
		LN ans;
		ans.undefine();
		return ans;
	}
	if (sign)
	{
		LN ans;
		ans.undefine();
		return ans;
	}
	LN ini = 0_ln;
	LN fin = *this;
	LN mid = divby2(ini + fin);
	while (ini < fin)
	{
		if (mid * mid <= *this)
		{
			ini = mid + 1_ln;
		}
		else
		{
			fin = mid - 1_ln;
		}
		mid = divby2(ini + fin);
	}
	if ((mid + 1_ln) * (mid + 1_ln) <= *this)
		return mid + 1_ln;
	else if (mid * mid <= *this)
		return mid;
	else
		return mid - 1_ln;
}

LN &LN::operator+=(const LN &op2)
{
	*this = *this + op2;
	return *this;
}

LN &LN::operator-=(const LN &op2)
{
	*this = *this - op2;
	return *this;
}

LN &LN::operator*=(const LN &op2)
{
	*this = *this * op2;
	return *this;
}

LN &LN::operator/=(const LN &op2)
{
	*this = *this / op2;
	return *this;
}

LN &LN::operator%=(const LN &op2)
{
	*this = *this + op2;
	return *this;
}

LN LN::operator=(const LN &op2)
{
	copy(op2);
	return *this;
}

void LN::operator=(LN &&other)
{
	this->value = other.value;
	this->size = other.size;
	this->sign = other.sign;
	this->notNumber = other.notNumber;
	other.value = nullptr;
}