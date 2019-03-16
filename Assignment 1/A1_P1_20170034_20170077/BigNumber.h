#ifndef _BIGNUMBER_H
#define _BIGNUMBER_H
#include <iostream>
#include <vector>
#include <string>

class BigNumber
{
private:
	//digits are stored each in a character, stored in reverse order.
	//for example, "1234" is stored as {4,3,2,1}
	//the actual numbers are stored, not their ascii equivalent.
	std::vector<char> data;
	bool negative = false;
	void clear();
	//helper function gets two numbers a and b,
	//sets first to be a pointer to the absolutly bigger one and second to the other
	friend bool biggersmaller(const BigNumber &a, const BigNumber &b, const BigNumber*& first, const BigNumber*& second);

	friend BigNumber add_digits(const BigNumber& a, const BigNumber& b);
	friend BigNumber subtract_digits(const BigNumber& a, const BigNumber& b);

public:
	BigNumber();
	BigNumber(const std::string& num);
	BigNumber(const int num);

	bool initalize_from_string(const std::string& num);		//returns whether it was successful or not.
	BigNumber operator+ (const BigNumber& b) const;
	BigNumber operator- (const BigNumber& b) const;
	BigNumber operator-() const;

	BigNumber& operator= (const BigNumber& b);

	int size() const;

	friend std::ostream& operator<<(std::ostream& out, const BigNumber& big);
	friend std::istream& operator>>(std::istream& in, BigNumber& big);
};

#endif	