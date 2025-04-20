#include <stdio.h>

int main() {
    int dia, mes, anio;

    printf("Ingrese la fecha (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &dia, &mes, &anio);

    // Validacion basica de fecha
    if (anio < 1 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        printf("Fecha invalida.\n");
        return 1;
    }

    // Bisiesto
    int es_bisiesto = ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0));

    // Dias por mes
    int dias_mes[] = { 0, 31, (es_bisiesto ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Validacion del dia segun mes
    if (dia > dias_mes[mes]) {
        printf("Fecha invalida.\n");
        return 1;
    }

    // Fechas especiales
    int es_anio_nuevo = (mes == 1 && dia == 1);
    int es_navidad = (mes == 12 && dia == 25);
    int es_finde_mes = (dia == dias_mes[mes]);

    // Mostrar resultados
    printf("La fecha ingresada es: %02d/%02d/%04d\n", dia, mes, anio);
    if (es_bisiesto) {
        printf("Es un anio bisiesto.\n");
    }
    if (es_anio_nuevo) {
        printf("Es Anio Nuevo.\n");
    }
    if (es_navidad) {
        printf("Es Navidad.\n");
    }
    if (es_finde_mes) {
        printf("Es fin de mes.\n");
    }

    return 0;
}
