#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct Producto {
    int ProductoID;        // Numerado en ciclo iterativo
    int Cantidad;          // entre 1 y 10
    char *TipoProducto;    // Algun valor del arreglo TiposProductos
    float PrecioUnitario;  // entre 10 - 100
}Producto;

typedef struct Cliente {
    int ClienteID;                // Numerado en el ciclo iterativo
    char *NombreCliente;          // Ingresado por usuario
    int CantidadProductosAPedir;  // “CantidadProductosAPedir” (aleatorio entre 1 y 5)
    struct Producto *Productos;   // El tamaño de este arreglo depende de la variable
}Cliente;

float costoTotal(Producto producto);

int main(int argc, char const *argv[])
{
    int cantClientes;
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d",&cantClientes);

    Cliente *clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));

    srand(time(NULL));

    for (int i = 0; i < cantClientes; i++)
    {
        char *nombreCliente =(char *)malloc(12 * sizeof(char));
        printf("Ingrese el nombre del cliente %d\n", i + 1);
        scanf("%s",nombreCliente);

        int cantProductosPedir = rand() % 5 + 1;

        Producto *productos = (Producto *)malloc(cantProductosPedir * sizeof(Producto));

        for (int j = 0; j < cantProductosPedir; j++)
        {
            productos[j].ProductoID = j + 1;
            productos[j].Cantidad = rand() % 10 + 1;
            productos[j].TipoProducto = TiposProductos[rand() % 5];
            productos[j].PrecioUnitario =rand() % 100 + 10;
        }

        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = nombreCliente;
        clientes[i].CantidadProductosAPedir = cantProductosPedir;
        clientes[i].Productos = productos;
    }
    for (int i = 0; i < cantClientes; i++)
    {
        float totalApagar = 0.0;
        printf("-------Cliente numero %d----------\n",clientes[i].ClienteID);
        printf("Nombre del cliente: %s\n",clientes[i].NombreCliente);
        printf("Cantidad de productos: %d\n",clientes[i].CantidadProductosAPedir);
        printf("--------Productos----------------\n");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("Id del producto %d\n",clientes[i].Productos[j].ProductoID);
            printf("Cantidad de este producto %d\n",clientes[i].Productos[j].Cantidad);
            printf("Tipo de producto %s\n",clientes[i].Productos[j].TipoProducto);
            printf("Precio de producto %.2f\n",clientes[i].Productos[j].PrecioUnitario);
            float costo = costoTotal(clientes[i].Productos[j]);
            totalApagar += costo;
        }
        printf("Total a pagar:%.2f\n",totalApagar);
    }
    return 0;
}

float costoTotal(Producto producto){
    return producto.Cantidad * producto.PrecioUnitario;
}
