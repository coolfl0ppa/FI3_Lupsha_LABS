#include "Vector.h"

template <class T>
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix();
	TMatrix(int l);
	TMatrix(int w, int l);
	TMatrix(const TMatrix<T>& p);
	~TMatrix();

	TMatrix<T> operator + (const TMatrix<T>& p);
	TMatrix<T> operator - (const TMatrix<T>& p);
	TMatrix<T> operator * (const TMatrix<T>& p);
	TVector<T> operator * (TVector<T>& p);
	TMatrix<T>& operator = (const TMatrix<T>& p);

	bool operator == (const TMatrix<T>& p);
	bool operator != (const TMatrix<T>& p);

	TVector<T>& operator [] (const int i);
	int GetWidth();
	void SetWidth(int w);
	void Resize(int w, int l);
	int GetIndex();

	template <class T>
	friend std::ostream& operator << (std::ostream& B, TMatrix<T>& A);
	template <class T>
	friend std::istream& operator >> (std::istream& B, TMatrix<T>& A);

protected:
	int width;
	int index;
};

template<class T>
inline TMatrix<T>::TMatrix()
{
	index = 0;
	width = 0;
	this->vector = nullptr;
}

template<class T>
inline TMatrix<T>::TMatrix(int l) : TMatrix()
{
	if (l < 0) throw "Error";
	this->length = l;
	width = l;
	this->vector = new TVector<T>[width];
	for (int i = 0; i < length; i++)
		this->vector[i].Resize(length);
}

template<class T>
inline TMatrix<T>::TMatrix(int w, int l) : TMatrix()
{
	if (l < 0 || w < 0) throw "Error";
	this->length = l;
	width = w;
	this->vector = new TVector<T>[width];
	for (int i = 0; i < width; i++)
		this->vector[i].Resize(length);
}

template<class T>
inline TMatrix<T>::TMatrix(const TMatrix<T>& p)
{
	this->length = p.length;
	width = p.width;
	index = p.index;
	if (p.vector == nullptr) this->vector = nullptr;
	else
	{
		this->vector = new TVector<T>[width];
		for (int i = 0; i < width; i++)
			this->vector[i] = p.vector[i];
	}
}

template<class T>
inline TMatrix<T>::~TMatrix()
{
	if (vector != nullptr)
	{
		delete[] vector;
		vector = nullptr;
	}
	width = 0;
	index = 0;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& p)
{
	if (this->length != p.length || width != p.width) throw "Error";
	TMatrix<T> res(*this);
	for (int i = 0; i < width; i++)
		res.vector[i] = this->vector[i] + p.vector[i];
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& p)
{
	if (this->length != p.length || width != p.width) throw "Error";
	TMatrix<T> res(width, this->length);
	for (int i = 0; i < width; i++)
		res.vector[i] = this->vector[i] - p.vector[i];
	return res;
}

template<class T>
inline TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& p)
{
	if (this->length != p.width) throw "Error";
	TMatrix<T> res(width, p.length);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < p.length; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < length; k++)
			{
				res[i][j] += this->vector[i][k] * p.vector[k][j];
			}
		}
	}
	return res;
}

template<class T>
inline TVector<T> TMatrix<T>::operator*(TVector<T>& p)
{
	if (this->length != p.GetLength()) throw "Error";
	TVector<T> res(width, 0);
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			res[i] += this->vector[i][j] * p[j];
		}
	}
	return res;
}

template<class T>
inline TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& p)
{
	if (this == &p) return *this;
	this->length = p.length;
	this->width = p.width;
	if (this->vector != nullptr) delete[] vector;
	if (p.vector == nullptr) vector = nullptr;
	else vector = new TVector<T>[p.width];
	for (int i = 0; i < p.width; i++)
		this->vector[i] = p.vector[i];
	return *this;
}

template<class T>
inline bool TMatrix<T>::operator==(const TMatrix<T>& p)
{
	if (this->length != p.length || width != p.width) return false;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < this->length; j++)
			if (this->vector[i][j] != this->p.vector[i][j]) return false;
	return true;
}

template<class T>
inline bool TMatrix<T>::operator!=(const TMatrix<T>& p)
{
	if (this->length != p.length || width != p.width) return true;
	for (int i = 0; i < width; i++)
		for (int j = 0; j < this->length; j++)
			if (this->vector[i][j] != this->p.vector[i][j]) return true;
	return false;
}

template<class T>
inline TVector<T>& TMatrix<T>::operator[](const int i)
{
	if (i < 0 || i >= this->width) throw "Error";
	return this->vector[i];
}

template<class T>
inline int TMatrix<T>::GetWidth()
{
	return width;
}

template<class T>
inline void TMatrix<T>::SetWidth(int w)
{
	this->Resize(this->length, w);
}

template<class T>
inline void TMatrix<T>::Resize(int w, int l)
{
	TVector<T>* vector1 = new TVector<T>[w];
	if (this->vector != nullptr)
	{
		int minW, minL;
		if (width > w) minW = w;
		else minW = width;
		if (this->length > l) minL = l;
		else minL = this->length;
		for (int i = 0; i < minW; i++)
		{
			vector1[i].Resize(l);
			for (int j = 0; j < minL; j++)
				vector1[i][j] = this->vector[i][j];
		}
		delete[] vector;
	}
	this->vector = vector1;
	this->length = l;
	width = w;
}

template<class T>
inline int TMatrix<T>::GetIndex()
{
	return index;
}

template<class T>
inline std::ostream& operator<<(std::ostream& B, TMatrix<T>& A)
{
	for (int i = 0; i < A.width; i++)
	{
		for (int j = 0; j < A.length; j++)
			B << A[i][j] << "\t";
		B << "\n";
	}
	return B;
}

template<class T>
inline std::istream& operator>>(std::istream& B, TMatrix<T>& A)
{
	std::cout << "Enter " << A.width * A.length << " values of Matrix: \n";
	for (int i = 0; i < A.width; i++)
		for (int j = 0; j < A.length; j++)
			B >> A.vector[i][j];
	return B;
}

template <class T>
TMatrix<T> operator *(TVector<T>& vector, TMatrix<T>& matrix)
{
	if (matrix.GetWidth() != 1) throw "Error";
	TMatrix<T> res(vector.GetLength(), matrix.GetLength());
	for (int i = 0; i < vector.GetLength(); i++)
	{
		for (int j = 0; j < matrix.GetLength(); j++)
		{
			res[i][j] = vector[i] * matrix[0][j];
		}
	}
	return res;
};
