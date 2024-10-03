#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)

{

	setvbuf(stdin, NULL, _IONBF, 0);

	setvbuf(stdout, NULL, _IONBF, 0);

	int i = 0, j = 0, r, min = -100, max = 100;

	int elem_c, m = 100, n = 100;


	int** mas = (int**)malloc(sizeof(int*) * n);


	for (int i = 0; i < n; i++)

	{

		mas[i] = (int*)malloc(sizeof(int) * m);

	}


	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < m; j++)

		{

			mas[i][j] = min + rand() % (max - min + 1);

			//printf("%d ",mas[i][j]);

		}

	}

	int** mass = (int**)malloc(sizeof(int*) * n);


	for (int i = 0; i < n; i++)

	{

		mass[i] = (int*)malloc(sizeof(int) * m);

	}


	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < m; j++)

		{

			mass[i][j] = min + rand() % (max - min + 1);

			//printf("%d ",mas[i][j]);

		}

	}

	int** c = (int**)malloc(sizeof(int*) * n);


	for (int i = 0; i < n; i++)

	{

		c[i] = (int*)malloc(sizeof(int) * m);

	}


	for (int i = 0; i < n; i++)

	{

		for (int j = 0; j < m; j++)

		{

			c[i][j] = min + rand() % (max - min + 1);

			//printf("%d ",mas[i][j]);

		}

	}

	clock_t starttime;

	starttime = clock();

	for (i = 0; i < n; i++)

	{

		for (j = 0; j < n; j++)

		{

			elem_c = 0;

			for (r = 0; r < n; r++)

			{

				elem_c = elem_c + mas[i][r] * mass[r][j];

				mass[i][j] = elem_c;

			}

		}

	}



	float t = (float)(clock() - starttime) / (float)CLOCKS_PER_SEC;

	printf("%f", t);

	getchar();

	getchar();

	getchar();

	return(0);

}