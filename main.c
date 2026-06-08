#include <stdio.h>
#include "funciones.h"

int main() {
    Libro miBiblioteca[MAX_LIBROS];
    int cantidadLibros = 0; 
    int opcion;

    do {
        printf("\n====== SISTEMA DE BIBLIOTECA ======\n");
        printf("1. Registrar libro\n");
        printf("2. Mostrar lista de libros\n");
        printf("3. Buscar libro\n");
        printf("4. Actualizar estado de un libro\n");
        printf("5. Eliminar libro\n");
        printf("6. Salir\n");
        printf("===================================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarLibro(miBiblioteca, &cantidadLibros);
                break;
            case 2:
                mostrarLibros(miBiblioteca, cantidadLibros);
                break;
            case 3:
                buscarLibro(miBiblioteca, cantidadLibros);
                break;
            case 4:
                actualizarEstado(miBiblioteca, cantidadLibros);
                break;
            case 5:
                eliminarLibro(miBiblioteca, &cantidadLibros);
                break;
            case 6:
                printf("\nSaliendo del sistema... Hasta pronto!\n");
                break;
            default:
                printf("\nOpcion no valida. Por favor intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}