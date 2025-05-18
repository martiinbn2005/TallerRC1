#include <stdio.h>
#include <string.h>
#include "funciones.h"

void ingresarDatos(char nombres[5][30], float *tiempos, int *recursos, int *demandas)
{
    int val1, val2, val3;

    for (int i = 0; i < 5; i++)
    {
        int len = 0;
        printf("\nProducto %d\n", i + 1);

        printf("Nombre del producto: ");
        fflush(stdin);
        fgets(nombres[i], 30, stdin);
        len = strlen(nombres[i]) - 1;
        nombres[i][len] = '\0';

        do
        {
            printf("Tiempo de fabricacion (horas): ");
            val1 = scanf("%f", &tiempos[i]);

            if (tiempos[i] <= 0)
            {
                printf("ERROR. El tiempo debe ser mayor a 0\n");
                val1 = 0;
            }

            if (val1 != 1)
            {
                printf("ERROR. Ingrese un numero valido\n");
                fflush(stdin);
            }

        } while (val1 != 1);

        do
        {
            printf("Recursos necesarios: ");
            val2 = scanf("%d", &recursos[i]);

            if (recursos[i] <= 0)
            {
                printf("ERROR. Los recursos deben ser mayores a 0\n");
                val2 = 0;
            }

            if (val2 != 1)
            {
                printf("ERROR. Ingrese un numero valido\n");
                fflush(stdin);
            }

        } while (val2 != 1);

        do
        {
            printf("Cantidad demandada: ");
            val3 = scanf("%d", &demandas[i]);

            if (demandas[i] <= 0)
            {
                printf("ERROR. La demanda debe ser mayor a 0\n");
                val3 = 0;
            }

            if (val3 != 1)
            {
                printf("ERROR. Ingrese un numero valido\n");
                fflush(stdin);
            }

        } while (val3 != 1);
    }
}

float calcularTiempoTotal(float *tiempos, int *demandas)
{
    float total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += tiempos[i] * demandas[i];
    }
    return total;
}

int calcularRecursosTotales(int *recursos, int *demandas)
{
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += recursos[i] * demandas[i];
    }
    return total;
}

void verificarFactibilidad(float *tiempos, int *recursos, int *demandas, float tiempoDisponible, int recursosDisponibles)
{
    float tiempoTotal = calcularTiempoTotal(tiempos, demandas);
    int recursosTotales = calcularRecursosTotales(recursos, demandas);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles)
    {
        printf("\nSI se puede cumplir la demanda con los recursos y tiempo disponibles.\n");
    }
    else
    {
        printf("\nNO se puede cumplir la demanda:\n");

        if (tiempoTotal > tiempoDisponible)
            printf("- Tiempo requerido: %.2f > %.2f disponible\n", tiempoTotal, tiempoDisponible);

        if (recursosTotales > recursosDisponibles)
            printf("- Recursos requeridos: %d > %d disponibles\n", recursosTotales, recursosDisponibles);
    }
}

void editarProducto(char nombres[5][30], float *tiempos, int *recursos, int *demandas)
{
    char buscado[30];
    int encontrado = 0;
    int len, val1, val2, val3;

    printf("Ingrese el nombre del producto a editar: ");
    fflush(stdin);
    fgets(buscado, 30, stdin);
    len = strlen(buscado) - 1;
    buscado[len] = '\0';

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            printf("Producto encontrado\n");
            printf("Ingrese nuevos valores:\n");

            printf("Nuevo nombre: ");
            fflush(stdin);
            fgets(nombres[i], 30, stdin);
            len = strlen(nombres[i]) - 1;
            nombres[i][len] = '\0';

            do
            {
                printf("Nuevo tiempo de fabricacion: ");
                val1 = scanf("%f", &tiempos[i]);

                if (tiempos[i] <= 0)
                {
                    printf("ERROR. El tiempo debe ser superior a 0\n");
                    val1 = 0;
                }

                if (val1 != 1)
                {
                    printf("ERROR. Ingrese un numero valido\n");
                    fflush(stdin);
                }

            } while (val1 != 1);

            do
            {
                printf("Nuevos recursos necesarios: ");
                val2 = scanf("%d", &recursos[i]);

                if (recursos[i] <= 0)
                {
                    printf("ERROR. La cantidad debe ser superior a 0\n");
                    val2 = 0;
                }

                if (val2 != 1)
                {
                    printf("ERROR. Ingrese un numero valido\n");
                    fflush(stdin);
                }

            } while (val2 != 1);

            do
            {
                printf("Nueva cantidad demandada: ");
                val3 = scanf("%d", &demandas[i]);

                if (demandas[i] <= 0)
                {
                    printf("ERROR. La cantidad demandada debe ser superior a 0\n");
                    val3 = 0;
                }

                if (val3 != 1)
                {
                    printf("ERROR. Ingrese un numero valido\n");
                    fflush(stdin);
                }

            } while (val3 != 1);

            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
        printf("ERROR. Producto no encontrado.\n");
}

void eliminarProducto(char nombres[5][30], float *tiempos, int *recursos, int *demandas)
{
    char buscado[30];
    int encontrado = 0;
    int len;

    printf("Ingrese el nombre del producto a eliminar: ");
    fflush(stdin);
    fgets(buscado, 30, stdin);
    len = strlen(buscado) - 1;
    buscado[len] = '\0';

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(nombres[i], buscado) == 0)
        {
            strcpy(nombres[i], "[ELIMINADO]");
            tiempos[i] = 0;
            recursos[i] = 0;
            demandas[i] = 0;
            printf("Producto eliminado correctamente.\n");
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
        printf("ERROR. Producto no encontrado.\n");
}