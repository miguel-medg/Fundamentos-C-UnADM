#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Productos {
    int No_producto;
    int Codigo;
    char Nombre[31];
    int Existencia;
    int Vendidos;
} Inventario[10];

void InventarioInicial(struct Productos Inventario[], int *NRegistros);
void RegistroVenta(struct Productos Inventario[], int NRegistros); 
void ReporteFinal(struct Productos Inventario[], int *NRegistros);

int main() {
    int opc, NRegistros = 0;
 printf("==================================================\n");
    printf("Estudiante: ***************\n");
    printf("Matricula: **********\n");
    printf("Grupo: **********\n");
    printf("==================================================\n");
    do {//impresion del menu en bucle
        printf("\nMENU PRINCIPAL\n");
        printf("\n1-Capturar inventario inicial");
        printf("\n2-Registrar una venta");
        printf("\n3-Mostrar reporte del dia");
        printf("\n4-Salir");
        printf("\nElige una opcion:");
        scanf(" %d", &opc);
        while (getchar() != '\n');

        switch (opc) {
            case 1:
                InventarioInicial(Inventario, &NRegistros);
                break;
            case 2:
            	// si no se ha registrado nada
                if (NRegistros == 0)
                    printf("\nPrimero debe capturar el inventario.\n");
                else
                    RegistroVenta(Inventario, NRegistros); 
                break;
            case 3:
                ReporteFinal(Inventario, &NRegistros);
                break;
            case 4:
                break;
            default:
                printf("OPCION INVALIDA");
        }
    } while (opc != 4);
    return 0;
}

// Módulo 1 para registrar productos
void InventarioInicial(struct Productos Inventario[], int *NRegistros) {
    int i;
    int NumProReg;

    printf("\n¿Cuantos productos deseas registrar? (1-10)\n");
    scanf(" %d", &NumProReg);
    while (getchar() != '\n');

    if (NumProReg > 10) {
        printf("\nCAPACIDAD MAXIMA DE 10\n");
    } else {
        for (i = 0; i < NumProReg; i++) {
            printf("\nProducto %d\n", i + 1);
            printf("Codigo:");
            scanf(" %d", &Inventario[i].Codigo);
            while (getchar() != '\n');

            printf("\nNombre:");
            scanf(" %30s", Inventario[i].Nombre);
            while (getchar() != '\n');

            printf("\nExistencia:");
            scanf(" %d", &Inventario[i].Existencia);
            while (getchar() != '\n');

            Inventario[i].Vendidos = 0; 
        }
        *NRegistros = NumProReg;
        printf("\nInventario capturado exitosamente\n");
    }
}

// Módulo 2 para registrar ventas 
void RegistroVenta(struct Productos Inventario[], int NRegistros) {
    int NumProVen, i, CodBus, a, VerVend;
    int encontrado;

    printf("\nREGISTRAR VENTA\n");
    printf("¿Cuantos productos diferentes incluiras en esta venta?:");
    scanf(" %d", &NumProVen);
    while (getchar() != '\n');

    for (i = 0; i < NumProVen; i++) {
        printf("\nProducto %d\n", i + 1);
        printf("Ingresa el codigo del producto:");
        scanf("%d", &CodBus);
        while (getchar() != '\n');

        encontrado = 0;
        // Buscar solo entre los productos registrados
        for (a = 0; a < NRegistros; a++) {
            if (CodBus == Inventario[a].Codigo) {
                encontrado = 1;
                printf("\nIngresa la cantidad:");
                scanf(" %d", &VerVend);
                while (getchar() != '\n');

                if (Inventario[a].Existencia < VerVend) {
                    printf("\nExistencia insuficiente\n");
                    printf("Existencia actual de %s: %d", Inventario[a].Nombre, Inventario[a].Existencia);
                    printf("\nEste producto no se registro en la venta.\n");
                } else {
                    Inventario[a].Vendidos += VerVend; // ACUMULAR, no asignar
                    Inventario[a].Existencia -= VerVend;
                    printf("Venta registrada. Nuevo stock: %d\n", Inventario[a].Existencia);
                }
                break;
            }
        }
        if (!encontrado) {
            printf("\nEl codigo %d no existe en el inventario\n", CodBus);
        }
    }
}

// Módulo 3: Reporte final (igual, pero con corrección de formato)
void ReporteFinal(struct Productos Inventario[], int *NRegistros) {
    int TotalPzsVen = 0;
    int i, e, MasVen = 0;
    int ContVen = 0;
    int num = *NRegistros;

    if (num == 0) {
        printf("\nNo hay productos registrados.\n");
        return;
    }

    // Total de piezas vendidas
    for (i = 0; i < num; i++) {
        TotalPzsVen += Inventario[i].Vendidos;
    }
    printf("\nREPORTE FINAL\n");
    printf("Total de piezas vendidas: %d\n", TotalPzsVen);

    // Producto más vendido
    for (e = 0; e < num; e++) {
        if (Inventario[e].Vendidos > ContVen) {
            ContVen = Inventario[e].Vendidos;
            MasVen = e;
        }
    }
    printf("\nProducto mas vendido:\n");
    printf("Codigo: %d\n", Inventario[MasVen].Codigo);
    printf("Nombre: %s\n", Inventario[MasVen].Nombre);
    printf("Piezas vendidas: %d\n", Inventario[MasVen].Vendidos);

    // Inventario final con alerta
    printf("\nINVENTARIO FINAL\n");
    printf("------------------------\n");
    printf("%-8s %-12s %-8s %-10s %s\n", "COD", "NOMBRE", "EXIST", "VENDIDOS", "ALERTA");
    for (i = 0; i < num; i++) {
        printf("%-8d %-12s %-8d %-10d ",
               Inventario[i].Codigo,
               Inventario[i].Nombre,
               Inventario[i].Existencia,
               Inventario[i].Vendidos);
        if (Inventario[i].Existencia < 3) {
            printf("EXISTENCIA BAJA");
        }
        printf("\n");
    }
    printf("------------------------\n");
}
