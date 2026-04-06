#include <stdio.h>
#include <string.h>

int main()
{
    char ID[10];
    char nombre[20];
    int stock = 0;
    float precio = 0.0;
    float ganancias = 0.0;
    int registrado = 0;
    int opc = 0, opc2 = 0;
    int aux;
    int len;
    int unidades;
    int reabastecimiento;
    float descuento;

    do{
        printf("Seleccione una opcion\n");
        printf("1.Registrar producto\n");
        printf("2.Vender producto\n");
        printf("3.Reabastecer producto\n");
        printf("4.Consultar informacion\n");
        printf("5.Ganancias totales\n");
        printf("6.Salir\n");

        do{
            printf(">> ");
            aux = scanf("%d",&opc);
            while(getchar() != '\n');
            if(aux != 1 || opc < 1 || opc > 6){
                printf("Valor ingresado erroneo\n");
            }
        }while(aux != 1 || opc < 1 || opc > 6);

        switch(opc){
            case 1:
                printf("Ingrese el ID del producto: ");
                scanf("%9s", ID);
                while(getchar() != '\n');

                printf("Ingrese el nombre del producto: ");
                fgets(nombre, 20, stdin);
                len = strlen(nombre) - 1;
                if(nombre[len] == '\n') nombre[len] = '\0';

                printf("Ingrese el stock del producto: ");
                do{
                    aux = scanf("%d",&stock);
                    while(getchar() != '\n');
                    if(aux != 1 || stock < 0){
                        printf("Valor ingresado erroneo\n");
                        printf("Ingrese el stock del producto: ");
                    }
                }while(aux != 1 || stock < 0);

                printf("Ingrese el precio del producto: ");
                do{
                    aux = scanf("%f",&precio);
                    while(getchar() != '\n');
                    if(aux != 1 || precio < 0){
                        printf("Valor ingresado erroneo\n");
                        printf("Ingrese el precio del producto: ");
                    }
                }while(aux != 1 || precio < 0);

                ganancias = 0.0;
                registrado = 1;
                printf("Producto registrado con exito\n");
                break;

            case 2:
                if(registrado == 0){
                    printf("Primero debe registrar un producto\n");
                    break;
                }
                if(stock == 0){
                    printf("No hay stock disponible para vender\n");
                    break;
                }

                printf("Ingrese la cantidad de unidades a vender: ");
                do{
                    aux = scanf("%d",&unidades);
                    while(getchar() != '\n');
                    if(aux != 1 || unidades <= 0){
                        printf("Valor ingresado erroneo\n");
                        printf("Ingrese la cantidad de unidades a vender: ");
                    }else if(unidades > stock){
                        printf("Stock insuficiente, solo hay %d unidades\n", stock);
                        printf("Ingrese la cantidad de unidades a vender: ");
                        aux = 0;
                    }
                }while(aux != 1 || unidades <= 0);

                printf("Ingrese el descuento a aplicar en %% (0 si no hay descuento): ");
                do{
                    aux = scanf("%f",&descuento);
                    while(getchar() != '\n');
                    if(aux != 1 || descuento < 0 || descuento > 100){
                        printf("Valor ingresado erroneo\n");
                        printf("Ingrese el descuento a aplicar en %% (0 si no hay descuento): ");
                    }
                }while(aux != 1 || descuento < 0 || descuento > 100);

                stock -= unidades;
                ganancias += (precio * (1 - descuento / 100)) * unidades;

                printf("Venta realizada con exito\n");
                printf("Stock restante: %d\n", stock);
                printf("Ganancias acumuladas: %.2f\n", ganancias);
                break;

            case 3:
                if(registrado == 0){
                    printf("Primero debe registrar un producto\n");
                    break;
                }

                printf("Ingrese la cantidad de unidades a reabastecer: ");
                do{
                    aux = scanf("%d",&reabastecimiento);
                    while(getchar() != '\n');
                    if(aux != 1 || reabastecimiento <= 0){
                        printf("Valor ingresado erroneo\n");
                        printf("Ingrese la cantidad de unidades a reabastecer: ");
                    }
                }while(aux != 1 || reabastecimiento <= 0);

                stock += reabastecimiento;
                printf("Reabastecimiento exitoso\n");
                printf("Stock actual: %d\n", stock);
                break;

            case 4:
                if(registrado == 0){
                    printf("No hay ningun producto registrado\n");
                    break;
                }
                printf("Informacion del producto:\n");
                printf("ID: %s\n", ID);
                printf("Nombre: %s\n", nombre);
                printf("Stock: %d\n", stock);
                printf("Precio: %.2f\n", precio);
                break;

            case 5:
                if(registrado == 0){
                    printf("No hay ningun producto registrado\n");
                    break;
                }
                printf("Ganancias totales: %.2f\n", ganancias);
                break;

            case 6:
                printf("Saliendo del programa...\n");
                break;
        }

        if(opc != 6){
            printf("Desea seleccionar otra opcion 1.Si/2.No: ");
            do{
                aux = scanf("%d",&opc2);
                while(getchar() != '\n');
                if(aux != 1 || (opc2 != 1 && opc2 != 2)){
                    printf("Valor ingresado erroneo\n");
                    printf("Desea seleccionar otra opcion 1.Si/2.No: ");
                }
            }while(aux != 1 || (opc2 != 1 && opc2 != 2));
        }else{
            opc2 = 2;
        }

    }while(opc2 == 1);

    return 0;
}