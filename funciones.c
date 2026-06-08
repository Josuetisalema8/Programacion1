#include <stdio.h>
#include <string.h>
#include "funciones.h"

void registrarLibro(Libro biblioteca[], int *cantidad) {
    if (*cantidad >= MAX_LIBROS) {
        printf("\nError: La biblioteca esta llena (Maximo %d libros).\n", MAX_LIBROS);
        return;
    }

    Libro nuevoLibro;
    int idValido = 0;

    printf("\n--- REGISTRAR NUEVO LIBRO ---\n");
    
    
    while (!idValido) {
        printf("Ingrese ID (entero unico): ");
        scanf("%d", &nuevoLibro.id);
        
        idValido = 1; 
        for (int i = 0; i < *cantidad; i++) {
            if (biblioteca[i].id == nuevoLibro.id) {
                printf("Error: Ese ID ya existe. Intente de nuevo.\n");
                idValido = 0;
                break;
            }
        }
    }

    
    while(getchar() != '\n'); 

    printf("Ingrese Titulo: ");
    scanf("%[^\n]", nuevoLibro.titulo); 
    while(getchar() != '\n');

    printf("Ingrese Autor: ");
    scanf("%[^\n]", nuevoLibro.autor);

    printf("Ingrese Anio de publicacion: ");
    scanf("%d", &nuevoLibro.anio);

    
    strcpy(nuevoLibro.estado, "Disponible");

    biblioteca[*cantidad] = nuevoLibro;
    (*cantidad)++;
    
    printf("Libro registrado con exito.\n");
}

void mostrarLibros(Libro biblioteca[], int cantidad) {
    if (cantidad == 0) {
        printf("\nNo hay libros registrados en la biblioteca.\n");
        return;
    }
    
    printf("\n--- LISTA DE LIBROS ---\n");
    
    printf("%-5s | %-30s | %-20s | %-6s | %-15s\n", "ID", "TITULO", "AUTOR", "ANIO", "ESTADO");
    printf("--------------------------------------------------------------------------------------\n");
    for (int i = 0; i < cantidad; i++) {
        printf("%-5d | %-30.30s | %-20.20s | %-6d | %-15s\n", 
               biblioteca[i].id, 
               biblioteca[i].titulo, 
               biblioteca[i].autor, 
               biblioteca[i].anio, 
               biblioteca[i].estado);
    }
}

void buscarLibro(Libro biblioteca[], int cantidad) {
    if (cantidad == 0) {
        printf("\nLa biblioteca esta vacia.\n");
        return;
    }

    int opcion, idBusqueda;
    char tituloBusqueda[100];
    int encontrado = 0;

    printf("\n--- BUSCAR LIBRO ---\n");
    printf("1. Buscar por ID\n");
    printf("2. Buscar por Titulo\n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingrese el ID a buscar: ");
        scanf("%d", &idBusqueda);
        for (int i = 0; i < cantidad; i++) {
            if (biblioteca[i].id == idBusqueda) {
                printf("\nLibro Encontrado: ID: %d | Titulo: %s | Autor: %s | Anio: %d | Estado: %s\n", 
                       biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
                encontrado = 1;
                break;
            }
        }
    } else if (opcion == 2) {
        while(getchar() != '\n'); 
        printf("Ingrese el Titulo a buscar: ");
        scanf("%[^\n]", tituloBusqueda);
        for (int i = 0; i < cantidad; i++) {
            
            if (strcmp(biblioteca[i].titulo, tituloBusqueda) == 0) {
                printf("\nLibro Encontrado: ID: %d | Titulo: %s | Autor: %s | Anio: %d | Estado: %s\n", 
                       biblioteca[i].id, biblioteca[i].titulo, biblioteca[i].autor, biblioteca[i].anio, biblioteca[i].estado);
                encontrado = 1;
                break;
            }
        }
    } else {
        printf("Opcion invalida.\n");
        return;
    }

    if (!encontrado) {
        printf("\nNo se encontro ningun libro con esos datos.\n");
    }
}

void actualizarEstado(Libro biblioteca[], int cantidad) {
    if (cantidad == 0) {
        printf("\nLa biblioteca esta vacia.\n");
        return;
    }

    int idActualizar;
    printf("\n--- ACTUALIZAR ESTADO ---\n");
    printf("Ingrese el ID del libro que desea actualizar: ");
    scanf("%d", &idActualizar);

    for (int i = 0; i < cantidad; i++) {
        if (biblioteca[i].id == idActualizar) {
            if (strcmp(biblioteca[i].estado, "Disponible") == 0) {
                strcpy(biblioteca[i].estado, "Prestado");
            } else {
                strcpy(biblioteca[i].estado, "Disponible");
            }
            printf("El estado del libro '%s' ha sido actualizado a: %s\n", biblioteca[i].titulo, biblioteca[i].estado);
            return;
        }
    }
    printf("Error: Libro con ID %d no encontrado.\n", idActualizar);
}

void eliminarLibro(Libro biblioteca[], int *cantidad) {
    if (*cantidad == 0) {
        printf("\nLa biblioteca esta vacia.\n");
        return;
    }

    int idEliminar;
    printf("\n--- ELIMINAR LIBRO ---\n");
    printf("Ingrese el ID del libro que desea eliminar: ");
    scanf("%d", &idEliminar);

    for (int i = 0; i < *cantidad; i++) {
        if (biblioteca[i].id == idEliminar) {
            
            for (int j = i; j < (*cantidad) - 1; j++) {
                biblioteca[j] = biblioteca[j + 1];
            }
            (*cantidad)--; 
            printf("Libro eliminado con exito.\n");
            return;
        }
    }
    printf("Error: Libro con ID %d no encontrado.\n", idEliminar);
}