#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct lineas {
    int ID;
    char Curp[20];
    char Nombre[30];
    char Telefono[11];
    char Operadora[25];
} registros[100];


void registrarNuevaLinea(struct lineas registros[], int *N);
void buscarLinea(const struct lineas registros[], int N);
void eliminarLinea(struct lineas registros[], int N);

int main() {
    int N = 1, opc;


    printf("SISTEMA DE REGISTRO DE LINEAS TELEFONICAS\n");
    printf("===========================\n");
    printf("Nombre completo: Miguel  Diaz \n");
    printf("Matricula: \n");
    printf("Grupo: \n");
    printf("===========================\n");

    do {
        printf("\n===========================\n");
        printf("MENU PRINCIPAL\n");
        printf("===========================\n");
        printf("1 - Lineas Registradas\n");
        printf("2 - Buscar linea\n");
        printf("3 - Eliminar una linea\n");
        printf("4 - Salir\n");
        printf("===========================\n");
        printf("\nSelecciona una opcion (1-4): ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                registrarNuevaLinea(registros, &N);
                break;

            case 2:
                buscarLinea(registros, N);
                break;

            case 3:
                eliminarLinea(registros, N);
                break;

            case 4:
                printf("\nSALIENDO DEL SISTEMA...\n");
                printf("\nHasta pronto!\n");
                break;

            default:
                printf("\nSeleccion invalida\n");
        }

    } while (opc != 4);

    return 0;
}


void registrarNuevaLinea(struct lineas registros[], int *N) {
    if (*N >= 100) {
        printf("El registro esta lleno\n");
        return;
    }

    printf("\n===========================\n");
    printf("Registro de linea nueva\n");
    printf("===========================\n");
    printf("ID asignado: %d\n", *N);
    registros[*N].ID = *N;

    printf("\nCURP (18 digitos): ");
    scanf("%s", registros[*N].Curp);

    printf("Nombre completo: ");
    scanf(" %[^\n]", registros[*N].Nombre);

    printf("Numero Telefonico (10 Numeros): ");
    scanf(" %[^\n]", registros[*N].Telefono);

    printf("\nSelecciona operadora:\n");
    printf("1-Telcel:\n");
    printf("2-AT&T\n");
    printf("3-Unefon\n");
    printf("Opcion (1-3): ");

    int OP;
    scanf("%d", &OP);

    switch (OP) {
        case 1: strcpy(registros[*N].Operadora, "Telcel");   break;
        case 2: strcpy(registros[*N].Operadora, "AT&T");     break;
        case 3: strcpy(registros[*N].Operadora, "Unefon");   break;
        default: printf("\nSeleccion invalida\n");
    }

    printf("===========================\n");
    printf("REGISTRO EXITOSO\n");
    printf("===========================\n");
    printf("Linea registrada con ID:%d\n", *N);

    (*N)++;
}


void buscarLinea(const struct lineas registros[], int N) {
    int BL, encontrado = 0;
    char BCURP[20];
    int i;

    printf("===========================\n");
    printf("BUSCAR LINEA TELEFONICA\n");
    printf("===========================\n");
    printf("\nCriterios de busqueda\n");
    printf("1-Buscar por ID\n");
    printf("2-Buscar por CURP\n");
    printf("\nSelecciona criterio de busqueda (1-2): ");
    scanf("%d", &BL);

    if (BL < 1 || BL > 2) {
        printf("Seleccion invalida\n");
        return;
    }

    if (BL == 1) {
        int idBuscado;
        printf("Ingrese ID a buscar: ");
        scanf("%d", &idBuscado);

        if (idBuscado < 1 || idBuscado >= N) {
            printf("\nID no valida\n");
            return;
        }

        printf("===========================\n");
        printf("INFORMACION DE LA LINEA\n");
        printf("===========================\n");
        printf("ID: %d\n", registros[idBuscado].ID);
        printf("CURP: %s\n", registros[idBuscado].Curp);
        printf("NOMBRE: %s\n", registros[idBuscado].Nombre);
        printf("TELEFONO: %s\n", registros[idBuscado].Telefono);
        printf("OPERADORA: %s\n", registros[idBuscado].Operadora);
    }
    else {  // BL == 2
        printf("Ingrese la CURP: ");
        scanf("%s", BCURP);

        for (i = 1; i < N; i++) {
            if (strcmp(BCURP, registros[i].Curp) == 0) {
                printf("===========================\n");
                printf("INFORMACION DE LA LINEA\n");
                printf("===========================\n");
                printf("ID: %d\n", registros[i].ID);
                printf("CURP: %s\n", registros[i].Curp);
                printf("NOMBRE: %s\n", registros[i].Nombre);
                printf("TELEFONO: %s\n", registros[i].Telefono);
                printf("OPERADORA: %s\n", registros[i].Operadora);
                encontrado = 1;
                break; 
            }
        }

        if (encontrado == 0) {
            printf("\nLinea no encontrada\n");
        }
    }
}

void eliminarLinea(struct lineas registros[], int N) {
    int SelEIDC, encontrado2 = 0;
    char DELETECURP[20];
    char SNopc;
    int pos = -1;
    int i;

    printf("ELIMINAR LINEA TELEFONICA\n");
    printf("\nEliminar linea por:\n");
    printf("1-ID\n");
    printf("2-CURP\n");
    printf("\nSelecciona una opcion (1-2): ");
    scanf("%d", &SelEIDC);

    if (SelEIDC < 1 || SelEIDC > 2) {
        printf("Seleccion invalida\n");
        return;
    }

    if (SelEIDC == 1) {
        int idBuscado;
        printf("Ingresa el ID: ");
        scanf("%d", &idBuscado);

        if (idBuscado < 1 || idBuscado >= N) {
            printf("\nID no valida\n");
            return;
        }

        pos = idBuscado;

        printf("\nLinea encontrada para eliminar\n");
        printf("INFORMACION DE LA LINEA\n");
        printf("===========================\n");
        printf("ID: %d\n", registros[pos].ID);
        printf("CURP: %s\n", registros[pos].Curp);
        printf("NOMBRE: %s\n", registros[pos].Nombre);
        printf("TELEFONO: %s\n", registros[pos].Telefono);
        printf("OPERADORA: %s\n", registros[pos].Operadora);
    }
    else {  // CURP
        printf("Ingrese la CURP: ");
        scanf("%s", DELETECURP);

        for (i = 1; i < N; i++) {
            if (strcmp(DELETECURP, registros[i].Curp) == 0) {
                pos = i;
                encontrado2 = 1;

                printf("\nLinea encontrada para eliminar\n");
                printf("INFORMACION DE LA LINEA\n");
                printf("===========================\n");
                printf("ID: %d\n", registros[i].ID);
                printf("CURP: %s\n", registros[i].Curp);
                printf("NOMBRE: %s\n", registros[i].Nombre);
                printf("TELEFONO: %s\n", registros[i].Telefono);
                printf("OPERADORA: %s\n", registros[i].Operadora);
                break;  // asumimos CURP única
            }
        }

        if (encontrado2 == 0) {
            printf("\nLinea no encontrada\n");
            return;
        }
    }

    // Confirmación
    printf("\nEstas seguro que quieres eliminar esta linea? (S/N): ");
    scanf(" %c", &SNopc);

    if (SNopc == 'S' || SNopc == 's') {
        strcpy(registros[pos].Curp, "");
        strcpy(registros[pos].Nombre, "");
        strcpy(registros[pos].Operadora, "");
        strcpy(registros[pos].Telefono, "");
        printf("\nELIMINACION EXITOSA\n");
    }
    else {
        printf("Operacion cancelada\n");
    }
} 
