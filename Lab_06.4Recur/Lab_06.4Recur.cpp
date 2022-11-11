#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double*& p, const int size, const double Min, const double Max, int i)
{
	p[i] = Min + rand() * (Max - Min) / RAND_MAX;
	if (i < size - 1)
		Create(p, size, Min, Max, i + 1);

}
void Vyvid(double*& p, const int size, int i)
{
	cout << p[i] << " ";
	if (i < size - 1)

		Vyvid(p, size, i + 1);
	else

		return;
}


int Count(double*& p, const int size, int k, int i)
{
	if (i < size)
	{
		if (p[i] == 0)
			return Count(p, size, ++k, ++i);

		else return Count(p, size, k, ++i);
	}

	else return k;
}
double minl(double*& p, const int size, int& inmin, int i, double min)
{
	if (p[i] < min) 
	{
		min = p[i];
		inmin = i;
	}
	if (i < size - 1)
		return minl(p, size, inmin, i + 1, min);
	else
		return min;
}

double Sum(double*& p, const int size, double& mini, int& inmin, double S, int i)
{

	S += p[i];
	if (i < size - 1)
		return Sum(p, size, mini, inmin, S, i+1);
	else
		return S;
	

}

void Sort(double*& p, const int size, int i)
{
	for (int j = 0; j < size - i; j++) 
		if (abs(p[j]) > abs(p[j + 1])) 
		{ 
			double tmp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = tmp;
		}

	if (i < size - 1) 
		Sort(p, size, i + 1);
}




int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	double* p;
	p = new double[n];
	double Min = -100.;
	double Max = 100.;
	
	int inmin = 0;
	
	
	
	

	Create(p, n, Min, Max, 0);
	cout << endl;
	Vyvid(p, n, 0.);
	cout << endl;
	cout << endl;
	int k = Count(p, n, 0, 0);
	cout << "1.1)Kilkist = " << k << endl;
	double mini = p[0];
	minl(p, n, inmin, 1, mini);
	cout << endl;
	
	cout << "Minimal =  " << minl(p, n, inmin, 1, mini) << endl;
	cout << endl;

	cout << "1.2)Suma = " << Sum(p, n, mini, inmin, 0., inmin + 1) << endl;
	cout << endl;
	
	
	
	
	Sort(p, n, 1);
	Vyvid(p, n, 0);

}