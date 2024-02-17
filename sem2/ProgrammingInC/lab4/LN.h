#ifndef BIG_INT
#define BIG_INT

#include <string_view>

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <stdio.h>
#define ALLOC_ERROR "There is not enough memory to complete the operation.\n"
#define OVERFLOW_ERROR "The number is too big to be stored in a long long.\n"

class LN
{
  private:
	bool notNumber = 0;
	bool sign = 0;
	char *value = NULL;
	size_t size = 0;

  public:
	// Constructors
	LN(const char *numero);
	LN(long long v = 0);
	LN(std::string_view numero);
	LN(const LN &other);
	LN(LN &&other) noexcept;

	// Helping
	void copy(const LN &op2);
	LN multiply(int factor) const;

	// Output
	void print(FILE *out) const;

	// Comparators
	bool operator<(const LN &op2) const;
	bool operator>(const LN &op2) const;
	bool operator==(const LN &op2) const;
	bool operator!=(const LN &op2) const;
	bool operator<=(const LN &op2) const;
	bool operator>=(const LN &op2) const;

	// Operators
	LN operator+(const LN &op2) const;
	LN operator-(const LN &op2) const;
	LN operator-() const;
	LN operator<<(size_t factor);
	LN operator*(const LN &op2) const;
	LN operator/(const LN &op2) const;
	LN operator%(const LN &op2) const;
	LN operator~() const;
	LN operator=(const LN &other);
	void operator=(LN &&other);
	LN &operator+=(const LN &op2);
	LN &operator-=(const LN &op2);
	LN &operator*=(const LN &op2);
	LN &operator/=(const LN &op2);
	LN &operator%=(const LN &op2);

	operator long long();

	// Others
	size_t getSize() const;
	void undefine();
	int operator[](size_t ind) const;
	bool getSign() const;
	bool isNotNumber() const;
	void changeSign();
	bool isZero() const;

	// destructor
	~LN();
};

// String constructor
LN operator"" _ln(const char *s);

// Helping functions
LN absln(const LN &op);
int absolutecomparator(const LN &op1, const LN &op2);
int valuecomparator(const LN &op1, const LN &op2);
LN divby2(const LN &op1);

// More helping functions
size_t count_symbols(const char *numero);
LN addabsolute(const LN &op1, const LN &op2);
LN subtractabsolute(const LN &op1, const LN &op2);
void toHumanReadable(char *numero, size_t size);

#endif