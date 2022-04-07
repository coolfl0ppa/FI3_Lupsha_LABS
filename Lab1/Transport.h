#pragma once
class TTransport
{
public:
	TTransport();
	TTransport(int _height, int _weight);
	TTransport(const TTransport& p);

	void SetWeight(int _weight);
	void SetHeight(int _height);

	double GetWeight();
	double GetHeight();
	virtual void Print() = 0;

protected:
	int height;
	int weight;
};