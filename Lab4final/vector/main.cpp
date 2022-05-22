#include"Vector.h"
#include <clocale>
#include <malloc.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Matrix.h"
using namespace std;
void line()
{
	std::cout << "\n\n";
}
int main()
{
	// vectora
	TVector<int> vec1(4, 6);
	TVector<int> vec2(4, 2);
	TVector<int> vec3(vec2);
	cin >> vec2;
	vec3 = vec1 + vec2;
	cout << "vec3 = vec1 + vec2 =\n" << vec1 << "+  " << vec2 << "=  " << vec3 << "\n";
	line();
	vec3 = vec1 - vec2;
	cout << "vec3 = vec1 - vec2 =\n" << vec1 << "-  " << vec2 << "=  " << vec3 << "\n";
	line();
	vec1 = vec2 * vec3;
	cout << "vec1 = vec2 * vec3 =\n" << vec2 << "*  " << vec3 << "=  " << vec1 << "\n";
	line();
	vec3 = vec1 / vec2;
	cout << "vec3 = vec1 / vec2 =\n" << vec1 << "/  " << vec2 << "=  " << vec3 << "\n";
	line();
	// sortirovki
	TVector<int> vec11(10, 5);
	srand(time(NULL));
	for (int i = 0; i < vec11.GetLength(); i++)
	{
		vec11[i] = rand() % 50 + 10;
	}
	vec11.QuickSort();
	std::cout << vec11 << "QuickSort";
	line();
	TVector<int> vec12(10, 5);
	srand(time(NULL));
	for (int i = 0; i < vec12.GetLength(); i++)
	{
		vec12[i] = rand() % 50 + 10;
	}

	vec12.BubbleSort();
	std::cout << vec12 << "BubbleSort";
	line();
	TVector<int> vec13(10, 5);
	srand(time(NULL));
	for (int i = 0; i < vec13.GetLength(); i++)
	{
		vec13[i] = rand() % 50 + 10;
	}
	vec13.InsertSort();
	std::cout << vec13 << "InsertSort";
	line();
	// matrix
	TMatrix<int> Matrix1;
	TMatrix<int> Matrix2(2, 3);
	TMatrix<int> Matrix3(Matrix2);
	TMatrix<int> Matrix4(4, 5);
	int** indexes;
	std::cin >> Matrix2;
	std::cout << Matrix2;
	line();

	for (int i = 0; i < Matrix3.GetWidth(); i++)
		for (int j = 0; j < Matrix3.GetLength(); j++)
			Matrix3[i][j] = rand();
	cout << "Matrix3 = \n" << Matrix3;
	line();

	Matrix1 = Matrix2 + Matrix3;
	cout << "Matrix1 = Matrix2 + Matrix3 =\n"
		<< Matrix2 << "\n + \n\n" << Matrix3 << "\n = \n\n" << Matrix1 << "\n";
	line();

	Matrix2 = Matrix3 - Matrix1;
	cout << "Matrix2 = Matrix3 - Matrix1 =\n"
		<< Matrix3 << "\n - \n\n" << Matrix1 << "\n = \n\n" << Matrix2 << "\n";
	line();

	Matrix1.Resize(2, 2);
	Matrix2.Resize(2, 2);
	Matrix3.Resize(2, 2);
	Matrix3 = Matrix2 * Matrix1;
	cout << "Matrix3 = Matrix2 * Matrix1 =\n"
		<< Matrix2 << "\n * \n\n" << Matrix1 << "\n = \n\n" << Matrix3 << "\n";
	line();

	for (int i = 0; i < Matrix4.GetWidth(); i++)
		for (int j = 0; j < Matrix4.GetLength(); j++)
			Matrix4[i][j] = rand() % 50;
	vec1 = Matrix4 * vec2;
	cout << "vec1 = Matrix4 * vec2 = \n" << Matrix4 << "\n *\n\n" << vec2 << "\n\n =\n\n" << vec1;
	line();
}