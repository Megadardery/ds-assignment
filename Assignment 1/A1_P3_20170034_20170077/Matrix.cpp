#include "Matrix.h"
#include <iomanip>
template<typename T>
void Matrix<T>::allocate_memory(const int r, const int c)
{
	row = r;
	col = c;
	if (row + col == 0) return;	//An empty Matrix should not be initialized.

	data = new int*[row];
	for (int i = 0; i < row; i++) {
		data[i] = new int[col];
		for (int j = 0; j < col; j++) {
			data[i][j] = 0;
		}
	}
}
template<typename T>
Matrix<T>::Matrix(const int r, const int c)
{
	allocate_memory(r, c);
}
template<typename T>
Matrix<T>::Matrix(const int row, const int col, const T * num) : Matrix(row, col)
{
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			(*this)[i][j] = *(num++);
}
template<typename T>
Matrix<T>::Matrix(const Matrix<T> & old)
{
	*this = old;
}
template<typename T>
Matrix<T>::Matrix(Matrix<T> && old)
{
	*this = std::move(old);
}

//deep copy by new allocation and copying each item
template<typename T>
Matrix<T> & Matrix<T>::operator=(const Matrix<T> & old)
{
	if (this->row + this->col != 0)
		this->~Matrix();

	allocate_memory(old.row, old.col);

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			(*this)[i][j] = old[i][j];
	}
	return *this;
}

//old is disposable, so we make this point to the old data and mark the old Matrix as empty
template<typename T>
Matrix<T> & Matrix<T>::operator=(Matrix<T> && old)
{
	if (this->row + this->col != 0)
		this->~Matrix();
	data = old.data;
	row = old.row; col = old.col;
	old.row = old.col = 0;
	return *this;
}

template<typename T>
inline T* Matrix<T>::operator[](int i) const
{
	return data[i];
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> & mat) const
{
	Matrix matx = *this;
	matx += mat;
	return matx;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> & mat) const
{
	Matrix matx = *this;
	matx -= mat;
	return matx;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> & mat) const
{
	if (col != mat.row) return Matrix(0, 0);
	Matrix matx(row, mat.col);
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < mat.col; ++j)
			for (int k = 0; k < col; ++k)
				matx[i][j] += (*this)[i][k] * mat[k][j];

	return matx;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const T scalar) const
{
	Matrix mat = *this;
	mat += scalar;
	return mat;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const T scalar) const
{
	Matrix mat = *this;
	mat -= scalar;
	return mat;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const T scalar) const
{
	Matrix mat = *this;
	mat *= scalar;
	return mat;
}

template<typename T>
Matrix<T> & Matrix<T>::operator+=(const Matrix<T> & mat)
{
	if (col != mat.col || row != mat.row)
		return *this = Matrix(0, 0);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] += mat[i][j];
	return *this;
}
template<typename T>
Matrix<T> & Matrix<T>::operator-=(const Matrix<T> & mat)
{
	if (col != mat.col || row != mat.row)
		return *this = Matrix(0, 0);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] -= mat[i][j];
	return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator*=(const Matrix & mat)
{
	return *this = *this * mat;
}
template<typename T>
Matrix<T> & Matrix<T>::operator+=(const T scalar)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] += scalar;
	return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator-=(const T scalar)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] -= scalar;
	return *this;
}

template<typename T>
Matrix<T> & Matrix<T>::operator*=(const T scalar)
{
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			(*this)[i][j] *= scalar;
	return *this;
}

template<typename T>
Matrix<T> Matrix<T>::transpose() const
{
	Matrix newmat(col, row);
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			newmat[j][i] = (*this)[i][j];
	return newmat;
}

template<typename T>
bool Matrix<T>::isInvalid() const
{
	return col + col == 0;
}

template<typename T>
Matrix<T>::~Matrix()
{
	if (row + col != 0) {
		for (int i = 0; i < row; i++) {
			delete[] data[i];
		}
		delete[] data;
	}
}
template<typename T>
std::istream & operator>>(std::istream & in, Matrix<T> & mat)
{
	int row, col;
	in >> row >> col;
	mat.allocate_memory(row, col);

	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			in >> mat[i][j];
	return in;
}
template<typename T>
std::ostream & operator<<(std::ostream & out, const Matrix<T> & mat)
{
	for (int i = 0; i < mat.row; ++i) {
		for (int j = 0; j < mat.col; ++j)
			out << std::setw(5) << mat[i][j];
		out << '\n';
	}
	return out;
}