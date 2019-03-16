#include <iostream>

#include "BigNumber.h"
using namespace std;

int main()
{
	BigNumber a(1324486001);
	BigNumber b("-1234567890");
	BigNumber c("0001234567890");
	BigNumber d("-1357923459732");
	BigNumber e("134831843401840");

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a + e << endl;
	cout << a - c << endl;
	cout << e + d << endl;
	cout << a - d << endl;
	cout << b + e << endl;
}