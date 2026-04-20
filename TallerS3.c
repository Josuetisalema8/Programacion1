#include <stdio.h>

int main (int argc, char *argv[]) {
    float cal[5][3][3]={0};
    char nombres[5][20];
    char asignaturas[3][20]={"Fisica",
                             "Quimica",
                             "Calculo"};
    int opc = 0, opc2 = 0;
    int contE=0;
    int selE=0;
    float prom[5][3] = {0};

    do{
        printf("\nSeleccione una opcion:\n");
        printf("1. Registrar estudiante\n");
        printf("2. Registrar calificaciones\n");
        printf("3. Promedios por estudiante\n");
        printf("4. Promedios por asignatura\n");
        printf("5. Calificacion mas alta y baja por estudiante\n");
        printf("6. Calificacion mas alta y baja por asignatura\n");
        printf("7. Estudiantes aprobados y reprobados por asignatura\n");
        printf(">> ");
        scanf("%d",&opc);

        switch (opc)
        {
        case 1:
            if (contE >= 5) {
                printf("Ya se registraron 5 estudiantes (maximo permitido).\n");
                break;
            }
            printf("Registre el nombre del estudiante %d:\n", contE+1);
            getchar();
            fgets(nombres[contE], 20, stdin);
            contE++;
            break;

        case 2:
            if (contE == 0) {
                printf("No hay estudiantes registrados.\n");
                break;
            }
            printf("Seleccione el estudiante al que desea registrar las calificaciones:\n");
            for (int i = 0; i < contE; i++) {
                printf("%d. %s", i, nombres[i]);
            }
            scanf("%d", &selE);
            if (selE < 0 || selE >= contE) {
                printf("Seleccion invalida.\n");
                break;
            }
            printf("Ingrese las calificaciones del estudiante %s", nombres[selE]);
            for (int i = 0; i < 3; i++) {
                printf("%s\n", asignaturas[i]);
                prom[selE][i] = 0;
                for (int j = 0; j < 3; j++) {
                    do {
                        printf("  Nota %d: ", j+1);
                        scanf("%f", &cal[selE][i][j]);
                        if (cal[selE][i][j] < 0 || cal[selE][i][j] > 10)
                            printf("  [!] Nota invalida. Ingrese entre 0 y 10.\n");
                    } while (cal[selE][i][j] < 0 || cal[selE][i][j] > 10);
                    prom[selE][i] += cal[selE][i][j];
                }
                prom[selE][i] /= 3;
            }
            break;

        case 3:
        {
            float auxProm = 0;
            printf("\nPromedios por alumno:\n");
            printf("%-20s%-12s%-12s%-12s%-12s\n", "Nombre",
                   asignaturas[0], asignaturas[1], asignaturas[2], "Promedio");
            for (int i = 0; i < contE; i++) {
                auxProm = (prom[i][0] + prom[i][1] + prom[i][2]) / 3;
                printf("%-20s%-12.2f%-12.2f%-12.2f%-12.2f\n",
                       nombres[i], prom[i][0], prom[i][1], prom[i][2], auxProm);
            }
            break;
        }

        case 4:
        {
            printf("\nPromedios por asignatura:\n");
            for (int j = 0; j < 3; j++) {
                float sumaProm = 0;
                for (int i = 0; i < contE; i++) {
                    sumaProm += prom[i][j];
                }
                float promAsig = (contE > 0) ? sumaProm / contE : 0;
                printf("  %-12s: %.2f\n", asignaturas[j], promAsig);
            }
            break;
        }

        case 5:
        {
            printf("\nCalificacion mas alta y baja por estudiante:\n");
            for (int i = 0; i < contE; i++) {
                float maxima = prom[i][0], minima = prom[i][0];
                int iMax = 0, iMin = 0;
                for (int j = 1; j < 3; j++) {
                    if (prom[i][j] > maxima) { maxima = prom[i][j]; iMax = j; }
                    if (prom[i][j] < minima) { minima = prom[i][j]; iMin = j; }
                }
                printf("  %s", nombres[i]);
                printf("    Max: %.2f (%s)  |  Min: %.2f (%s)\n",
                       maxima, asignaturas[iMax], minima, asignaturas[iMin]);
            }
            break;
        }

        case 6:
        {
            printf("\nCalificacion mas alta y baja por asignatura:\n");
            for (int j = 0; j < 3; j++) {
                float maxima = prom[0][j], minima = prom[0][j];
                int iMax = 0, iMin = 0;
                for (int i = 1; i < contE; i++) {
                    if (prom[i][j] > maxima) { maxima = prom[i][j]; iMax = i; }
                    if (prom[i][j] < minima) { minima = prom[i][j]; iMin = i; }
                }
                printf("  %-12s -> Max: %.2f (%s)  |  Min: %.2f (%s)\n",
                       asignaturas[j], maxima, nombres[iMax], minima, nombres[iMin]);
            }
            break;
        }

        case 7:
        {
            printf("\nEstudiantes aprobados y reprobados por asignatura (promedio >= 6):\n");
            for (int j = 0; j < 3; j++) {
                int aprobados = 0, reprobados = 0;
                for (int i = 0; i < contE; i++) {
                    if (prom[i][j] >= 6.0f) aprobados++;
                    else                     reprobados++;
                }
                printf("  %-12s -> Aprobados: %d  |  Reprobados: %d\n",
                       asignaturas[j], aprobados, reprobados);
            }
            break;
        }

        default:
            printf("Opcion invalida. Intente de nuevo.\n");
            break;
        }

        printf("\nDesea seleccionar otra opcion? 1.Si / 2.No: ");
        scanf("%d", &opc2);

    } while (opc2 == 1);

    return 0;
}
