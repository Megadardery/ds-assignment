#include "MatrixCalculator.h"
#include <iostream>
#include "Matrix.h"

void MatrixCalculator::showMenu()
{
	while (true) {
		Matrix<int> mats[2];
		for (int i = 0; i < 2; i++) {
			std::cout << "Enter matrix "<< i+1 << " (rows and columns followed by data): \n";

			std::cin >> mats[i];
			if (mats[i].isInvalid()) {
				--i;
				std::cout << "Invalid matrix entered\n";
				std::cout << "Do you want to exit? (y/n):\n";
				char op;
				std::cin >> op;
				if (op == 'y') return;
			}
		}
		while (true) {

			std::cout << "Which operator do you want to perform (*,+,-,t) to enter new matricies write something else:\n";
			char op;
			std::cin >> op;
			Matrix<int> matres;
			if (op == '*') {
				matres = mats[0] * mats[1];
				if (matres.isInvalid())
					std::cout << "couldn't multiply matricies, not possible because of size\n";
				else
					std::cout << "Result is:\n" << matres;
			}
			else if (op == '+') {
				matres = mats[0] + mats[1];
				if (matres.isInvalid())
					std::cout << "couldn't add matricies, not possible because of size\n";
				else
					std::cout << "Result is:\n" << matres;
			}
			else if (op == '-') {
				matres = mats[0] - mats[1];
				if (matres.isInvalid())
					std::cout << "couldn't subtract matricies, not possible because of size\n";
				else
					std::cout << "Result is:\n" << matres;
			}
			else if (op == 't') {
				std::cout << "Transpose of 1 is: \n" << mats[0].transpose();
				std::cout << "Transpose of 2 is: \n" << mats[1].transpose();
			}
			else {

				std::cout << "Do you want to exit? (y/n)";
				char op;
				std::cin >> op;
				if (op == 'y') return;
				break;
			}
		}
	}
}