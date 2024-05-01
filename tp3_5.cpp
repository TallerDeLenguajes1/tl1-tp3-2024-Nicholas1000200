#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LONGITUD_NOMBRE 12

int main(int argc, char const *argv[])
{
    int bufferNombres;
    printf("Ingrese la cantidad de nombres a ingresar:");
    scanf("%d",&bufferNombres);
    char *nombre[bufferNombres];
    char buff[MAX_LONGITUD_NOMBRE];
    
    for (int i = 0; i < bufferNombres; i++)
    {
        printf("Ingrese el nombre:");
        fflush(stdin);
        gets(buff);

        nombre[i] =(char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombre[i],buff);
    }

    for (int i = 0; i < bufferNombres; i++)
    {
        puts(nombre[i]);
        printf("\n");
    }
    
    for (int i = 0; i < bufferNombres; i++)
    {
        free(nombre[i]);
    }
    

    return 0;
}