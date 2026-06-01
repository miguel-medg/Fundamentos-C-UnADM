#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Estudiantes {
    int NO;
    char Fecha[15];
    char Matricula[5];
    char Estudiante[20];
    int Estado;
    char PAE[8];
};

void registrarEstudiante(struct Estudiantes Registros[], int *NRegistros, int *N);
void asignacionPAE(struct Estudiantes Registros[], int NRegistros, int *CupoDAN, int *CupoPIN, int *CupoDEB);
void consultarDemanda(struct Estudiantes Registros[], int NRegistros);

int main() {
    struct Estudiantes Registros[6];
    int NRegistros = 1;
    int opc, N = 1;
    int CupoDEB = 0, CupoDAN = 0, CupoPIN = 0;

    printf("==================================================\n");
    printf("Unidad didactica: Fundamentos de programacion\n");
    printf("Estudiante: Miguel Diaz\n");
    printf("Matricula: **********\n");
    printf("Grupo: **********\n");
    printf("==================================================\n");
    printf("\nPROGRAMA DE ACTIVIDADES EXTRACURRICULARES\n");

    do {
        printf("\n1-Registro estudiante.\n");
        printf("2-Asignacion PAE.\n");
        printf("3-Consultar demanda PAEs.\n");
        printf("4-Salir.\n");
        printf("\nSelecciona una opcion: ");
        scanf(" %d", &opc);
        while (getchar() != '\n');

        switch (opc) {
            case 1: registrarEstudiante(Registros, &NRegistros, &N); break;
            case 2: asignacionPAE(Registros, NRegistros, &CupoDAN, &CupoPIN, &CupoDEB); break;
            case 3: consultarDemanda(Registros, NRegistros); break;
            case 4: printf("\nGRACIAS POR USAR EL PROGRAMA DE ACTIVIDADES EXTRACURRICULARES\n"); break;
            default: printf("\nSeleccion invalida\n"); break;
        }

    } while (opc != 4);

    return 0;
}

void registrarEstudiante(struct Estudiantes Registros[], int *NRegistros, int *N) {
    if (*NRegistros > 6) {
        printf("\nYA NO SE PUEDEN REGISTRAR MAS ESTUDIANTES\n");
    } else {
        printf("\nRegistro No.: %d\n", *N);
        Registros[*N].NO = *N;

        printf("\nFecha (DD/MM/AA): ");
        scanf(" %s", Registros[*N].Fecha);
        while (getchar() != '\n');

        printf("\nMatricula: ");
        scanf(" %4s", Registros[*N].Matricula);
        while (getchar() != '\n');

        printf("\nEstudiante: ");
        scanf(" %[^\n]", Registros[*N].Estudiante);
        Registros[*N].Estado = 1;
        while (getchar() != '\n');

        if (Registros[*N].Estado == 0)
            printf("\nEstudiante Asignado\n");
        else
            printf("\nEstudiante Registrado\n");

        (*NRegistros)++;
        (*N)++;
    }
    system("pause");
}

void asignacionPAE(struct Estudiantes Registros[], int NRegistros, int *CupoDAN, int *CupoPIN, int *CupoDEB) {
    char MComp[5];
    int opcPAE, i;

    printf("\nASIGNACION PAE\n");
    printf("\nIngresa la matricula: ");
    scanf("%4s", MComp);
    while (getchar() != '\n');

    for (i = 1; i < NRegistros; i++) {
        if (strcmp(MComp, Registros[i].Matricula) == 0) {
            printf("\nNo. registro: %d", Registros[i].NO);
            printf("\nFecha de registro: %s", Registros[i].Fecha);
            printf("\nEstudiante: %s", Registros[i].Estudiante);

            if (Registros[i].Estado == 1)
                printf("\nESTADO: REGISTRADO");
            else {
                printf("\nESTADO: ASIGNADO - %s", Registros[i].PAE);
                printf("\nESTUDIANTE CUENTA CON REGISTRO Y PAE ASIGNADO\n");
            }

            if (Registros[i].Estado == 1) {
                printf("\nSelecciona PAE\n");
                printf("1-DANZA\n");
                printf("2-PINTURA\n");
                printf("3-DEBATE\n");
                printf("\nEscribe el numero: ");
                scanf("%d", &opcPAE);
                while (getchar() != '\n');

                switch (opcPAE) {
                    case 1:
                        if (*CupoDAN < 2) { printf("\nESTUDIANTE ASIGNADO AL PAE DE DANZA\n"); strcpy(Registros[i].PAE, "DANZA"); Registros[i].Estado = 0; (*CupoDAN)++; }
                        else printf("PAE SIN CUPO\n");
                        break;
                    case 2:
                        if (*CupoPIN < 2) { printf("\nESTUDIANTE ASIGNADO AL PAE DE PINTURA\n"); strcpy(Registros[i].PAE, "PINTURA"); Registros[i].Estado = 0; (*CupoPIN)++; }
                        else printf("PAE SIN CUPO\n");
                        break;
                    case 3:
                        if (*CupoDEB < 2) { printf("\nESTUDIANTE ASIGNADO AL PAE DE DEBATE\n"); strcpy(Registros[i].PAE, "DEBATE"); Registros[i].Estado = 0; (*CupoDEB)++; }
                        else printf("PAE SIN CUPO\n");
                        break;
                    default: printf("Opcion no valida\n");
                }
            }
            break;
        }
    }

    if (i == NRegistros)
        printf("\nMatricula no encontrada\n");
}

void consultarDemanda(struct Estudiantes Registros[], int NRegistros) {
    int p;

    printf("\nDANZA:");
    for (p = 1; p < NRegistros; p++)
        if (strcmp(Registros[p].PAE, "DANZA") == 0) printf("\n%s", Registros[p].Estudiante);

    printf("\nPINTURA:");
    for (p = 1; p < NRegistros; p++)
        if (strcmp(Registros[p].PAE, "PINTURA") == 0) printf("\n%s", Registros[p].Estudiante);

    printf("\nDEBATE:");
    for (p = 1; p < NRegistros; p++)
        if (strcmp(Registros[p].PAE, "DEBATE") == 0) printf("\n%s", Registros[p].Estudiante);

    printf("\n");
}
