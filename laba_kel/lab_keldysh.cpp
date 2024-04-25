#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
/**
 * Метод прогонки
 * n - число уравнений (строк матрицы)
 * C - диагональ, лежащая над главной 
 * B - главная диагональ матрицы A 
 * A - диагональ, лежащая под главной 
 * F - правая часть (столбец)
 * res - решение
 */

void solveTridiagonalMatrix(int n, double * A, double * B, double * C, double * F, double * res)
{
	double temp;
	for (int i = 1; i < n; i++)
	{
		temp = A[i] / B[i - 1];
		B[i] = B[i] - temp * C[i - 1];
		F[i] = F[i] - temp * F[i - 1];
	}

	res[n - 1] = F[n - 1] / B[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		res[i] = (F[i] - C[i] * res[i + 1]) / B[i];
	}
}

int main(){	
  	const double PI = 3.14;
	const int k = 1;
	int n = 10000;
	double L = 1;
	double eps0 = 1;
	double f_left_condition = 0;
	double f_right_condition = 0;

	double *b = new double[n];
	double *c = new double[n];
	double *a = new double[n];
	double *phi = new double[n];
	double *f = new double[n];

	for (auto i = 0; i < n; i++) {
		c[i] = 1;
		a[i] = 1;
		b[i] = 2;
	}
	for (auto i = 0; i < n; i++) {
		f[i] = -sin(2*PI*(i+1)*n*k/L)/eps0;
		
	}
	f[0] = f[0] + f_left_condition;
	f[n-1] = f[n-1] + f_right_condition;


	solveTridiagonalMatrix(n, a, b, c, f, phi);

	for (auto i = 0; i < n; i++) {
		std::cout << phi[i] << std::endl;
	}

	
	std::ofstream fout("data_keldysh.txt");

	for (auto i = 0; i < n-1; i++) {
		fout << i << " " << phi[i] << std::endl;
	}

	fout.close();
	return 0;

    
}