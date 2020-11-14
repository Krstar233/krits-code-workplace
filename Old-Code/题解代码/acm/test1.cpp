#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
void simulation(double dist[], int SIDES)
{
	for (int i = 1; i <= SIDES; i++)
	{
		for (int j = 1; j <= SIDES; j++)
		{
			dist[i+j] += 1.0;		
		}
	}
	for (int k = 2; k <= 2*SIDES; k++)
	{
		dist[k] /= 36.0;
	}
}
int main()
{
	const int SIDES = 6;
	double dist[2 * SIDES + 1] = {0};
	double real[2 * SIDES + 1] = {0};
	double tmp [2 * SIDES + 1] = {0};
	int N = 0;
	
	simulation(dist, SIDES);
	while (true)
	{
		int a = rand() % 6 + 1;
		int b = rand() % 6 + 1;
		int flag = 0;
		
		N++;
		tmp[a + b] ++;
		real[a + b] = tmp[a + b] / N;
		for (int i = 2; i <= 12; i++)
		{
			if (fabs(real[i] - dist[i]) > 1e-3)
				flag = 1;
		}
		if (flag == 0)	break;
	}
	cout << "dist\t\treal\n";
	for (int k = 2; k < SIDES * 2; k++)
	{
		cout << dist[k] << "\t" << real[k] << endl;
	}
	cout << "N = " << N << endl;
	getchar();
}
