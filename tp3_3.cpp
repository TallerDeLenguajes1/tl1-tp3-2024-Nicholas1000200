#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRES 5
#define MAX_LONGITUD_NOMBRE 12

int main(int argc, char const *argv[])
{
    char *nombre[MAX_NOMBRES];
    char buff[MAX_LONGITUD_NOMBRE];

    for (int i = 0; i < MAX_NOMBRES; i++)
    {
        printf("Ingrese el nombre:");
        gets(buff);

        nombre[i] =(char *)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(nombre[i],buff);
    }

    for (int i = 0; i < MAX_NOMBRES; i++)
    {
        puts(nombre[i]);
        printf("\n");
    }
    
    for (int i = 0; i < MAX_NOMBRES; i++)
    {
        free(nombre[i]);
    }
    

    return 0;
}
