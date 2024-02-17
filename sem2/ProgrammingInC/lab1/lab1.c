#include "return_codes.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define ZERO 0.0F
#define MINEPS 0.0
#define ABSEPS 1e-15

/*
void debug()
{
	printf("kika\n");
	fflush(stdout);
}
*/

#if 0
void print(int n, float (*mat)[n + 1], FILE *out)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			fprintf(stdout, "%g ", mat[i][j]);
		}
		fprintf(stdout, "\n");
	}
	fprintf(stdout, "--------------------------------------------------------------\n");
}
#endif

void sort(int n, float (*mat)[n + 1])
{
	for (int i = 0; i < n; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			if (fabs(mat[i][i]) < fabs(mat[k][i]))
			{
				for (int j = 0; j <= n; j++)
				{
					float temp = mat[i][j];
					mat[i][j] = mat[k][j];
					mat[k][j] = temp;
				}
			}
		}
	}
}

// My guess of what eps should be
// based on observation
// tried different approaches but everything pointed to the same
// see more:
// img1.png
void computeEPS(int n, float (*mat)[n + 1], double *EPS)
{
	double mayor, menor;
	mayor = MINEPS;
	double operator1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			operator1 = mat[i][j];
			if (fabs(operator1) > MINEPS)
			{
				mayor = fabs(operator1);
			}
		}
	}
	if (mayor <= MINEPS)
		return;
	menor = mayor;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			// this should be considered a 0
			operator1 = mat[i][j];
			if (fabs(operator1) <= MINEPS)
			{
				continue;
			}
			if (fabs(operator1) > mayor)
			{
				mayor = fabs(operator1);
			}
			if (fabs(operator1) < menor)
			{
				menor = fabs(operator1);
			}
		}
	}
	if ((menor / mayor) < *EPS)
	{
		// The least value that can be reached on any row
		// and therefore, the least that some cell should
		// influence on another
		*EPS = (menor / mayor);
	}
	//In case of floats, let's also try menor * menor
	if ((menor * menor) < *EPS) {
		*EPS = (menor * menor);
	}

	//let's set EPS to something less than what we computed
	//because what we computed should be the minimum influence
	//of some row on another during reduction
	//then something less is already zero.
	*EPS /= 2;
	if (*EPS < ABSEPS)
	{
		// we need a not too agresive epsilon
		// that does not exceed the limits of a float
		*EPS = ABSEPS;
	}
}

void interchange(int n, float (*mat)[n + 1], int x, int y, int bycol)
{
	float temp;
	if (bycol)
	{
		for (int i = 0; i < n; i++)
		{
			temp = mat[i][x];
			mat[i][x] = mat[i][y];
			mat[i][y] = temp;
		}
	}
	else
	{
		for (int i = 0; i <= n; i++)
		{
			temp = mat[x][i];
			mat[x][i] = mat[y][i];
			mat[y][i] = temp;
		}
	}
}

int eliminate(int n, float (*mat)[n + 1], double EPS)
{
	double operator1, operator2;
	for (int i = 0; i < n; i++)
	{
		operator1 = mat[i][i];
		if (fabs(operator1) < EPS)
		{
			// let's try to exchange columns
			if (i == n - 1)
				return i;
			for (int j = i + 1; j < n; j++)
			{
				operator1 = mat[i][j];
				if (fabs(operator1) > EPS)
				{
					interchange(n, mat, i, j, 1);
					break;
				}
				// There was no column to exchange with
				if (j + 1 == n)
				{
					return i;
				}
			}
		}
		for (int k = i + 1; k < n; k++)
		{
			operator1 = mat[k][i];
			operator2 = mat[i][i];
			double first = (operator1 / operator2);
			for (int j = 0; j <= n; j++)
			{
				operator1 = mat[k][j];
				operator2 = mat[i][j];
				operator1 -= (first * operator2);
				mat[k][j] = operator1;
			}
			mat[k][i] = ZERO;
		}
	}
	return -1;
}

int gaussjordan(int n, float (*mat)[n + 1], FILE *out, double EPS)
{
	// print(n, mat, NULL);
	// debug();
	int return_value = eliminate(n, mat, EPS);
	// printf("%g\n", EPS);
	// print(n, mat, NULL);
	// debug();
	double operator1;
	if (return_value != -1)
	{
		operator1 = mat[return_value][n];
		if (fabs(operator1) < EPS)
		{
			fprintf(out, "many solutions\n");
		}
		else
		{
			fprintf(out, "no solution\n");
		}
	}
	else
	{
		double *ans = malloc(sizeof(double) * n);
		if (ans == NULL)
		{
			return ERROR_MEMORY;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			ans[i] = mat[i][n];
			for (int j = i + 1; j < n; j++)
			{
				operator1 = mat[i][j];
				ans[i] = ans[i] - operator1 * ans[j];
			}
			operator1 = mat[i][i];
			ans[i] /= operator1;
		}
		for (int i = 0; i < n; i++)
		{
			fprintf(out, "%g\n", ans[i]);
		}
		free(ans);
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		fprintf(stderr, "An incorrect number of arguments was given\n");
		return ERROR_INVALID_DATA;
	}
	int errorcode = ERROR_SUCCESS;
	FILE *in;
	FILE *out;
	in = fopen(argv[1], "r");
	if (in == NULL)
	{
		fprintf(stderr, "Could not open input file\n");
		return ERROR_NOT_FOUND;
	}
	out = fopen(argv[2], "w");
	int n;
	int readargs = 1;
	readargs = fscanf(in, "%d", &n);
	if (readargs < 1)
	{
		fprintf(stderr, "empty file or incorrect format for input data");
		errorcode = ERROR_INVALID_DATA;
	}
	// If n is read, we can continue
	if (errorcode == ERROR_SUCCESS)
	{
		float(*mat)[n + 1] = malloc(sizeof(float) * (n + 1) * n);
		if (mat == NULL)
		{
			fprintf(stderr, "The requested amount of memory could not be assigned\n");
			errorcode = ERROR_MEMORY;
		}
		if (errorcode == ERROR_SUCCESS)
		{
			double EPS = 0.1;
			// that amount of memory could be taken, then let's continue
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j <= n; j++)
				{
					readargs = fscanf(in, "%f", &mat[i][j]);
					if (readargs < 1)
					{
						fprintf(stderr, "empty file or incorrect format for input data");
						errorcode = ERROR_INVALID_DATA;
					}
					if (fabs(mat[i][j]) > MINEPS && fabs(mat[i][j]) < EPS) {
						EPS = fabs(mat[i][j]);
					}
				}
			}
			// If the whole matrix could be read, we can continue
			// We do not need to read anymore
			if (errorcode == ERROR_SUCCESS)
			{
				// Gauss-Jordan reduction
				// print(n, mat, out);
				sort(n, mat);
				// print(n, mat, out);
				EPS /= 2;
				computeEPS(n, mat, &EPS);
				errorcode = gaussjordan(n, mat, out, EPS);
				if (errorcode == ERROR_MEMORY)
				{
					fprintf(stderr, "A memory error ocurred");
				}
			}
			// free memory
			// Only when it could be assigned
			free(mat);
		}
	}

	// Close files
	fclose(in);
	fclose(out);
	return errorcode;
}