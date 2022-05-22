#pragma once
#include <iostream>

template <class T>
class TVector
{
public:
	TVector();
	TVector(int a, T _vector);
	TVector(const TVector<T>& p);
	~TVector();

	void SetLen(int p);
	int GetLength();

	TVector<T> operator +(const TVector<T>& p);
	TVector<T> operator -(const TVector<T>& p);
	TVector<T> operator *(const TVector<T>& p);
	TVector<T> operator /(const TVector<T>& p);
	TVector<T>& operator =(const TVector<T>& p);
	bool operator ==(const TVector<T>& p);
	bool operator !=(const TVector<T>& p);
	T& operator [](int i);

	// sortirovki
	void BubbleSort();
	void InsertSort();
	void QuickSort(int left = 0, int right = 0);

	template <class T>
	friend std::ostream& operator << (std::ostream& B, TVector<T>& A);
	template <class T>
	friend std::istream& operator >> (std::istream& B, TVector<T>& A);

protected:
	T* vector;
	int length;
};

template<class T>
inline TVector<T>::TVector()
{
	length = 0;
	vector = nullptr;
}

template<class T>
inline TVector<T>::TVector(int a, T _vector)
{
	if (a > 0)
	{
		vector = new T[a];
		length = a;
		for (int i = 0; i < length; i++)
			vector[i] = _vector;
	}
	else throw "Error";
}

template<class T>
inline TVector<T>::TVector(const TVector<T>& p)
{
	if (p.vector == nullptr)
	{
		vector = nullptr;
		length = 0;
	}
	else
	{
		length = p.length;
		vector = new T[length];
		for (int i = 0; i < length; i++)
			vector[i] = p.vector[i];
	}
}

template<class T>
inline TVector<T>::~TVector()
{
	delete[] vector;
	vector = nullptr;
	length = 0;
}

template<class T>
inline void TVector<T>::SetLen(int p)
{
	length = p.length;
}

template<class T>
inline int TVector<T>::GetLength()
{
	return length;
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& p)
{
	if (length == 0) throw "Error";
	if (length != p.length) throw "Error, vectors with different dimension";
	TVector<T> R(length, 0);
	for (int i = 0; i < length; i++)
		R[i] = vector[i] + p.vector[i];
	return R;
}

template<class T>
inline TVector<T> TVector<T>::operator-(const TVector<T>& p)
{
	if (length == 0) throw "Error";
	if (length != p.length) throw "Error";
	TVector<T> R(length, 0);
	for (int i = 0; i < length; i++)
		R[i] = vector[i] - p.vector[i];
	return R;
}

template<class T>
inline TVector<T> TVector<T>::operator*(const TVector<T>& p)
{
	if (length == 0) throw "Error";
	if (length != p.length) throw "Error";
	TVector<T> R(length, 0);
	for (int i = 0; i < length; i++)
		R[i] = vector[i] * p.vector[i];
	return R;
}

template<class T>
inline TVector<T> TVector<T>::operator/(const TVector<T>& p)
{
	if (length == 0) throw "Error";
	if (length != p.length) throw "Error";
	TVector<T> R(length, 0);
	for (int i = 0; i < length; i++)
		if (p.vector[i] == 0) R[i] = 0;
		else R[i] = vector[i] / p.vector[i];
	return R;
}

template<class T>
inline TVector<T>& TVector<T>::operator=(const TVector<T>& p)
{
	if (this == &p) return *this;
	if (vector != nullptr) delete[] vector;
	if (p.vector == nullptr)
	{
		length = 0;
		vector = nullptr;
	}
	else
	{
		length = p.length;
		vector = new T[length];
		for (int i = 0; i < length; i++)
			vector[i] = p.vector[i];
	}
	return *this;
}

template<class T>
inline bool TVector<T>::operator==(const TVector<T>& p)
{
	if (length != p.length) return false;
	for (int i = 0; i < length; i++)
		if (vector[i] != p.vector[i]) return false;
	return true;
}

template<class T>
inline bool TVector<T>::operator!=(const TVector<T>& p)
{
	if (length != p.length) return true;
	for (int i = 0; i < length; i++)
		if (vector[i] != p.vector[i]) return true;
	return false;
}

template<class T>
inline T& TVector<T>::operator[](int i)
{
	if (vector == nullptr)
		throw "Error, length <= 0";
	if (i < 0 || i >= length)
		throw "Error";
	return vector[i];
}

template<class T>
inline void TVector<T>::BubbleSort()
{
	for (int i = 0; i < length; i++)
		for (int j = i + 1; j < length; j++)
			if (vector[j] < vector[i])
			{
				int tmp = vector[j];
				vector[j] = vector[i];
				vector[i] = tmp;
			}
}

template<class T>
inline void TVector<T>::InsertSort()
{
	for (int i = 1; i < length; i++)
	{
		int k = i;
		while (k > 0 && vector[k - 1] > vector[k])
		{
			int tmp = vector[k - 1];
			vector[k - 1] = vector[k];
			vector[k] = tmp;
			k -= 1;
		}
	}
}

template<class T>
inline void TVector<T>::QuickSort(int left, int right)
{
	int i, j;
	if (right == 0)
	{
		left = 0;
		right = length - 1;
	}
	i = left;
	j = right;
	int sr = vector[(left + right) / 2];
	int tmp;
	while (i <= j) {
		while (vector[i] < sr) i++;
		while (vector[j] > sr) j--;
		if (i <= j) {
			tmp = vector[i];
			vector[i] = vector[j];
			vector[j] = tmp;
			i++;
			j--;
		}
	}
	if (left < j) QuickSort(left, j);
	if (right > i) QuickSort(i, right);
}

template<class T>
inline std::ostream& operator<<(std::ostream& B, TVector<T>& A)
{
	std::cout << "(";
	for (int i = 0; i < A.GetLength(); i++)
	{
		if (i + 1 != A.GetLength())
			B << A[i] << ", ";
		else
		{
			B << A[i];
		}
			
	}
	std::cout << ") ";
	return B;
}

template<class T>
inline std::istream& operator>>(std::istream& B, TVector<T>& A)
{
	std::cout << "Enter " << A.length << " values of vector: \n";
	for (int i = 0; i < A.length; i++)
		B >> A[i];
	return B;
}
