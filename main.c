#include <stdio.h>
#include "funciones.h"

int main()
{
    char nombres[5][30];
    float tiempos[5];
    int recursos[5];
    int demandas[5];
    float tiempoDisponible;
    int recursosDisponibles;
    int opc;

    ingresarDatos(nombres, tiempos, recursos, demandas);

    int val1, val2;

    do
    {
        printf("\nIngrese el tiempo total disponible de produccion (en horas): ");
        val1 = scanf("%f", &tiempoDisponible);

        if (tiempoDisponible <= 0)
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
        printf("Ingrese la cantidad total de recursos disponibles: ");
        val2 = scanf("%d", &recursosDisponibles);

        if (recursosDisponibles <= 0)
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
        printf("\nMENU DE OPCIONES\n");
        printf("1. Calcular tiempo total requerido\n");
        printf("2. Calcular recursos totales requeridos\n");
        printf("3. Verificar si se puede cumplir la demanda\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            printf("\nTiempo total requerido: %.2f horas\n", calcularTiempoTotal(tiempos, demandas));
            break;
        case 2:
            printf("\nRecursos totales requeridos: %d unidades\n", calcularRecursosTotales(recursos, demandas));
            break;
        case 3:
            verificarFactibilidad(tiempos, recursos, demandas, tiempoDisponible, recursosDisponibles);
            break;
        case 4:
            editarProducto(nombres, tiempos, recursos, demandas);
            break;
        case 5:
            eliminarProducto(nombres, tiempos, recursos, demandas);
            break;
        case 6:
            printf("\nSaliendo del programa...\n");
            break;
        default:
            printf("ERROR. Opción no válida\n");
            break;
        }

    } while (opc != 6);

    return 0;
}
