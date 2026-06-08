#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIBROS 10 


typedef struct {
    int id;               
    char titulo[100];     
    char autor[50];       
    int anio;             
    char estado[20];      
} Libro;


void registrarLibro(Libro biblioteca[], int *cantidad);
void mostrarLibros(Libro biblioteca[], int cantidad);
void buscarLibro(Libro biblioteca[], int cantidad);
void actualizarEstado(Libro biblioteca[], int cantidad);
void eliminarLibro(Libro biblioteca[], int *cantidad);

#endif