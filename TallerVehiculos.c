#include <stdio.h>

int main () {
    int DiaIngreso, MesIngreso, AnoIngreso, PorcentajeServicio, PrecioFinal, DiaEntrega, FechaEntrega;
    char NombreCliente[80], HoraIngreso[10], MarcaVehiculo[25], ModeloVehiculo[20], ColorVehiculo[20], PlacasVehiculo[10], TipoServicio[20], RegistroEspacio[10], ClaveEmpleado[10], NombreEncargado[80];

printf("Estudiante: Miguel Diaz\n");
printf("Matricula: **********\n");
printf("Grupo: **********\n");
printf("\nIntroduce Dia de ingreso\n");
scanf("%d", &DiaIngreso);
printf("Introduce Mes de ingreso\n");
scanf("%d", &MesIngreso);
printf("Introduce Año de ingreso\n");
scanf("%d", &AnoIngreso);
printf("Introduce Hora de ingreso\n");
scanf("%s", HoraIngreso);
printf("introduce Nombre del cliente\n");
scanf(" %79[^\n]", NombreCliente);
printf("introduce Marca del vehiculo\n");
scanf("%s", MarcaVehiculo);
printf("introduce Modelo del vehiculo\n");
scanf("%s", ModeloVehiculo);
printf("introduce Color del vehiculo\n");
scanf("%s", ColorVehiculo);
printf("introduce Número de placas del vehiculo\n");
scanf("%s", PlacasVehiculo);
printf("Introduce Tipo de servicio\n");
scanf("%s", TipoServicio);
printf("introduce Porcentaje de servicio\n");
scanf("%d", &PorcentajeServicio);
printf("introduce Registro del espacio\n");
scanf("%s", RegistroEspacio);
printf("introduce Clave del empleado\n");
scanf("%s", ClaveEmpleado);
printf("introduce Nombre del encargado\n");
scanf (" %79[^\n]", NombreEncargado);

PrecioFinal = 1200*(100 + PorcentajeServicio)/100;
DiaEntrega = DiaIngreso + 3;

printf("\nComprobante del cliente\n");
printf("Taller: Hermanos Benavidez\n");
printf("Cliente: %s\n", NombreCliente);
printf("Fecha de Ingreso: %d/%d/%d\n", DiaIngreso, MesIngreso, AnoIngreso);
printf("Hora de Ingreso: %s\n", HoraIngreso);
printf("Placas del vehiculo: %s\n", PlacasVehiculo);
printf("Tipo de servicio: %s\n", TipoServicio);
printf("Precio Final: %d\n", PrecioFinal);
printf("Vehiculo: %s,%s\n", MarcaVehiculo, ModeloVehiculo);
printf("Color del Vehiculo: %s\n", ColorVehiculo);
printf("Fecha de entrega: %d/%d/%d\n", DiaEntrega, MesIngreso, AnoIngreso);
printf("\nComprobante de la Empresa\n");
printf("Fecha de ingreso: %d/%d/%d\n", DiaIngreso, MesIngreso, AnoIngreso);
printf("Vehiculo: %s,%s\n", MarcaVehiculo, ModeloVehiculo);
printf("Espacio asignado: %s\n", RegistroEspacio);
printf("Empleado: %s\n", ClaveEmpleado);
printf("Nombre del encargado %s\n", NombreEncargado);
printf("Fecha de entrega %d/%d/%d\n", DiaEntrega, MesIngreso, AnoIngreso);
}
