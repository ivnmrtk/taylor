#pragma once
class TaylorSeries
{
public:

	//string  exp = "ln(1+x) -1<x<1 ";

	TaylorSeries(int _n, double _x);

	~TaylorSeries();

	void print();

	double calculateSeq();

	double calculatePar();


private:
	unsigned int n;
	double x;
};

