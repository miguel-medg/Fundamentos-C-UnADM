#include <stdio.h>
#include <conio.h>

int main () {
    int Moneda, Saldo, Cambio, Precio;
    char opc;

    printf("Estudiante: Miguel Diaz\n");
    printf("Matricula: **********\n");
    printf("Grupo: **********\n");

    do {
        Saldo=0, Precio=0;
        printf("Menu de productos\n");
        printf("1- Producto A - $8\n");
        printf("2- Producto B - $12\n");
        printf("3- Producto C - $15\n");
        printf("4- Producto D - $20\n");
        printf("5- Producto E - $25\n");
        printf("6- Salir\n");
        printf("Selecciona un producto\n");
        opc=getche();

        switch (opc)
        {
        case '1': Precio=8;  break;
        case '2': Precio=12; break;
        case '3': Precio=15; break;
        case '4': Precio=20; break;
        case '5': Precio=25; break;
        case '6': printf("Adios\n"); break;
        default:  printf("Seleccion invalida\n"); break;
        }

        if (opc >= '1' && opc <= '5')
        {
            while (Saldo < Precio)
            {
                printf("Introduce una moneda (1,2,5,10):\n");
                scanf("%d", &Moneda);
                if (Moneda==1 || Moneda==2 || Moneda==5 || Moneda==10)
                {
                    Saldo = Saldo + Moneda;
                    printf("Saldo actual: %d\n", Saldo);
                }
                else
                {
                    printf("Moneda no aceptada\n");
                }
            }

            if (Saldo > Precio)
            {
                Cambio = Saldo - Precio;
                printf("Tu cambio es: %d\n", Cambio);
            }
            printf("Producto entregado\n");
            printf("Presione ENTER para volver al menu..\n");
            getche();
        }

    } while (opc != '6');

    return 0;
}
