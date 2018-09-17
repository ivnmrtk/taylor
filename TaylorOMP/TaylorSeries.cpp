#include "pch.h"
#include "TaylorSeries.h"
#include <omp.h>
#include <math.h>
#include <iostream>  

using namespace std;

TaylorSeries::TaylorSeries(int _n=0, double _x=0.)
{
	n = _n;
	x = _x;
}

TaylorSeries::~TaylorSeries()
{
}

void TaylorSeries::print()
{
}

double TaylorSeries::calculateSeq()
{
	double res=0;
	double t1 = omp_get_wtime();

	for (int i=0; i < n; i++)
	{
		res += (pow(-1, i) * pow(x, i + 1)) / (i + 1);
	}

	double t2 = omp_get_wtime();
	cout << fixed << "Последовательное вычисление выполнилось за " << t2 - t1 << "секунд с результатом " << res << endl;
	return res;
}

double TaylorSeries::calculatePar()
{
	double res = 0;
	double t1 = omp_get_wtime();

	#pragma omp parallel private(i) for reduction(+:sum) 
	for (int i = 0; i < n; i++)
	{
		res += (pow(-1, i) * pow(x, i + 1)) / (i + 1);
	}

	double t2 = omp_get_wtime();
	cout << fixed << "Паралельное вычисление выполнилось за "  << t2 - t1 << "секунд с результатом " << res << endl;
	return res;
}
