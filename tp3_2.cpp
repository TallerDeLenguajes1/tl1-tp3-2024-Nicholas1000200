#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLUMNAS 12
#define FILAS 5

void cargarMatriz(int matriz[FILAS][COLUMNAS]);
void mostrarMatriz(int matriz[FILAS][COLUMNAS]);
void gananciasPoranio(int matriz[FILAS][COLUMNAS]);
void maxYmin(int matriz[FILAS][COLUMNAS]);
int main(int argc, char const *argv[])
{
    int matriz[FILAS][COLUMNAS];
    srand(time(NULL));
    cargarMatriz(matriz);
    mostrarMatriz(matriz);
    gananciasPoranio(matriz);
    maxYmin(matriz);

    return 0;
}
void cargarMatriz(int matriz[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            matriz[i][j] = rand() % 40001 + 10000;
        }
    }
}
void mostrarMatriz(int matriz[FILAS][COLUMNAS])
{
    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            printf("| %d |", matriz[i][j]);
        }
        printf("\n");
    }
}

void gananciasPoranio(int matriz[FILAS][COLUMNAS])
{
    int promedio[FILAS];

    for (int i = 0; i < FILAS; i++)
    {
        int ganancia = 0;
        for (int j = 0; j < COLUMNAS; j++)
        {
            ganancia += matriz[i][j];
        }
        promedio[i] = ganancia / COLUMNAS;
    }
    for (int index = 0; index < FILAS; index++)
    {
        printf("El promedio de ganancia en el año %d fue de %d\n", index + 1, promedio[index]);
    }
}

void maxYmin(int matriz[FILAS][COLUMNAS])
{
    int maxAnio = 0, minAnio = 0, maxMes = 0, minMes = 0, mayor = matriz[0][0], menor = matriz[0][0];

    for (int i = 0; i < FILAS; i++)
    {
        for (int j = 0; j < COLUMNAS; j++)
        {
            if (mayor < matriz[i][j])
            {
                mayor = matriz[i][j];
                maxAnio = i;
                maxMes = j;
            }
            if (menor > matriz[i][j])
            {
                menor = matriz[i][j];
                minAnio = i;
                minMes = j;
            }
        }
    }
    printf("El valor maximo fue %d en el año %d y mes %d\n", mayor, maxAnio+1, maxMes+1);
    printf("El valor minimos fue %d en el año %d y mes %d\n", menor, minAnio+1, minMes+1);
}
