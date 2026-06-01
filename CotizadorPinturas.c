#include <stdlib.h>
#include <stdio.h>
float CalcularArea (float Base, float Altura); //Declaracion de modulos//
float CalcularPrecioF (float Area);
int main (){
float Base, Altura, Area, PrecioFinal;

    printf("Nombre: Miguel  Diaz \n");
    printf("Matricula: \n");
    printf("Grupo: \n");
    printf("\nCOTIZADOR PINTURAS RAPIDAS\n");
    printf("Tarifa por m2: $150.00\n");
     printf("Ingrese la base de la pared (metros)\n");
    scanf("%f", &Base);
    printf("Ingrese la altura de la pared (metros)\n");
    scanf("%f", &Altura);

    Area=CalcularArea(Base, Altura); //Area y preciofinal obtienen el valor de los modulos//
    PrecioFinal=CalcularPrecioF(Area);
    
    printf("\n===RECIBO DEL PRESUPUESTO===\n");
    printf("Medidas: %.2f m x %.2f m\n", Base, Altura);
    printf("Area Total= %.2f m2\n", Area);
    printf("Precio Final con IVA: $%.2f MXN\n", PrecioFinal);
    
    return 0;
}

float CalcularArea (float Base, float Altura){ //operaciones//
    return (Base*Altura);
}
float CalcularPrecioF (float Area){
    return ((Area*150.00)*1.16);
}


