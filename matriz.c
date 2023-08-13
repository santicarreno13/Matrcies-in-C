#include <stdio.h>

void operacionmatriz(int fila, int columna, float matriz1[][columna], float matriz2[][columna], int operacion);
void multiplicaMatrices(int fila1, int columna1, float matriz1[][columna1], int fila2, int columna2, float matriz2[][columna2]);
void mostrarMatriz(int fila, int columna, float matriz[][columna]);

int main()
{

	int fila1, columna1, fila2, columna2, opcion;

	printf("Digite la cantidad de filas para la 1 matriz\n");
	scanf("%d", &fila1);

	printf("Digite la cantidad de columnas para la 1 matriz\n");
	scanf("%d", &columna1);

	printf("Digite la cantidad de filas para la 2 matriz\n");
	scanf("%d", &fila2);

	printf("Digite la cantidad de columnas para la 2 matriz\n");
	scanf("%d", &columna2);

	// Verificacion de que sean iguales las matrices
	if (fila1 != fila2 || columna1 != columna2)
	{
		printf("Las matrices no tienen el mismo tamaño. \n");
		return 1;
	}

	float matriz1[fila1][columna1], matriz2[fila2][columna2];

	// Introducir datos en la matriz 1
	for (int i = 0; i < fila1; i++)
	{
		for (int j = 0; j < columna1; j++)
		{
			printf("Ingrese el valor para matriz1[%d][%d]: ", i, j);
			scanf("%f", &matriz1[i][j]);
		}
	}

	// Introducir datos en la matriz 2
	for (int i = 0; i < fila2; i++)
	{
		for (int j = 0; j < columna2; j++)
		{
			printf("Ingrese el valor para matriz2[%d][%d]: ", i, j);
			scanf("%f", &matriz2[i][j]);
		}
	}

	printf("1.-Para sumar las matrices \n");
	printf("2.-Para restar las matrices \n");
	printf("3.-Para multiplicar las matrices \n");
	printf("4.-Para inversa de 1 matriz \n");
	printf("5.-Para inversa de 2 matriz\n");
	scanf("%d", &opcion);

	switch (opcion)
	{
	case 1:
		operacionMatriz(fila1, columna1, matriz1, matriz2, 1);
		break;
	case 2:
		operacionMatriz(fila1, columna1, matriz1, matriz2, -1);
		break;
	case 3:
		multiplicaMatriz(fila1, columna1, matriz1, fila2, columna2, matriz2);
		break;
	case 4:
		invertirMatriz(fila1, columna1, matriz1);
		break;
	case 5:
		invertirMatriz(fila2, columna2, matriz2);
		break;
	default:
		printf("El numero ingresado no esta en el rango del 1 al 5.\n");
	}
	return 0;
}

void operacionMatriz(int fila, int columna, float matriz1[][columna], float matriz2[][columna], int operacion)
{
	float resultado[fila][columna];
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			resultado[i][j] = matriz1[i][j] + operacion * matriz2[i][j];
		}
	}
	printf("Resultado de la operacion: \n");
	mostrarMatriz(fila, columna, resultado);
}

void mostrarMatriz(int fila, int columna, float matriz[][columna])
{
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			printf("%.2f\t", matriz[i][j]);
		}
		printf("\n");
	}
}

void multiplicaMatriz(int fila1, int columna1, float matriz1[][columna1], int fila2, int columna2, float matriz2[][columna2])
{
	if (columna1 != fila2)
	{
		printf("No es posible multiplicar las matrices dadas.\n");
		return;
	}

	float resultado[fila1][columna2];
	for (int i = 0; i < fila1; i++)
	{
		for (int j = 0; j < columna2; j++)
		{
			resultado[i][j] = 0;
			for (int k = 0; k < columna1; k++)
			{
				resultado[i][j] += matriz1[i][k] * matriz2[k][j];
			}
		}
	}
	printf("Resultado de la multiplicación:\n");
	mostrarMatriz(fila1, columna2, resultado);
}

void invertirMatriz(int fila, int columna, float matriz[][columna])
{
	for (int i = 0; i < fila / 2; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			float temp = matriz[i][j];
			matriz[i][j] = matriz[fila - 1 - i][j];
			matriz[fila - 1 - i][j] = temp;
		}
	}
	
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna / 2; j++)
		{
			float temp = matriz[i][j];
			matriz[i][j] = matriz[i][columna - 1 - j];
			matriz[i][columna - 1 - j] = temp;
		}
	}
	printf("Matriz invertida:\n");
	mostrarMatriz(fila, columna, matriz);
}