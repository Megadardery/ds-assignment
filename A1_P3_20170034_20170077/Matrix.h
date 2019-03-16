#ifndef _MATRIX_H
#define _MATRIX_H

#include <iosfwd>

template<typename T>
class Matrix
{
private:
	T** data;
	int row = 0, col = 0;
	//allocates dynamic memory into the data pointer
	void allocate_memory(const int r, const int c);

public:
	/*Rule of five:
	//if you overload one of the following, you should probably overload the rest
	* Destructor
	* Copy Constructor
	* Copy assignment operator
	* Move Constructor (c++11)
	* Move assignment operator (c++11)
	*/

	// a constructor that takes the rows and columns count and initializes the memory with zeros.
	Matrix(const int r = 0, const int c = 0);
	// a constructor that takes the rows and columns count and initializes the memory with memory from the 1D num array.
	Matrix(const int row, const int col, const T* num);

	// a copy constructor, used when 'matrix mat = mat1;' is called
	Matrix(const Matrix& old);
	// a move constructor, used when old is disposable, such as the return value of a function. 
	Matrix(Matrix&& old);

	// = operators similar to the above two constructor
	Matrix& operator=(const Matrix& old);
	Matrix& operator=(Matrix&& old);

	//overloaded the [] operators so that the matrix' data can be accessed using
	//mat[i][j] instead of mat.data[i][j]
	T* operator[] (int i) const;

	//basic arithmetic operations between two matricies. 
	Matrix operator+ (const Matrix& mat) const;
	Matrix operator- (const Matrix& mat) const;
	Matrix operator* (const Matrix& mat) const;

	//basic arithmetic operations between a matrix and a scalar
	Matrix operator+ (const T scalar) const;
	Matrix operator- (const T scalar) const;
	Matrix operator* (const T scalar) const;

	//basic compound arithmetic operations between two matricies. 
	Matrix& operator+= (const Matrix& mat);
	Matrix& operator-= (const Matrix& mat);
	Matrix& operator*= (const Matrix& mat);

	//basic compound arithmetic operations between a matrix and a scalar
	Matrix& operator+= (const T scalar);
	Matrix& operator-= (const T scalar);
	Matrix& operator*= (const T scalar);

	//iostream handling
	//for input, you first enter the rows and columns then you enter the data.
	template<typename U>
	friend std::istream& operator>> (std::istream& in, Matrix<U>& mat);
	template<typename U>
	friend std::ostream& operator<< (std::ostream& out, const Matrix<U>& mat);

	Matrix transpose() const;

	bool isInvalid() const;

	~Matrix();
};

//As much as the following is 'bad' and defeats the purpose of seperate compilation,
//it is the only way to allow templates in c++.

//notice that Matrix.cpp is not compiled seperately, it needs to be compiled at the same
//time it is included.

//Note, if there is a better way to do this, please help
#include "Matrix.cpp"

#endif
