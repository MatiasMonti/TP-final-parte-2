#ifndef CLAVES_H_INCLUDED
#define CLAVES_H_INCLUDED
#include "cliente.h"

/**
 * typedef Clave: TAD que representa la Clave de un Cliente
 * @cliente: enlace al Cliente en caso de modificaci�n (no es clave).
 * @posicion: posici�n del registro Cliente en el archivo (no es clave).
 * @edad: edad del Cliente y clave secundaria.
 * @apellido: apellido del Cliente y clave primaria.
 *
 * Este TAD ser� utilizado para representar la Clave de un Cliente
 * en el Indice y por consecuencia el tipo de los argumentos para la
 * funci�n comparadora en los m�todos del AVL y en las funciones de
 * persistencia y recuperaci�n del Indice.
 */
typedef struct {
    Cliente *cliente;
    int posicion;
    int edad;
    char *apellido;
} Clave;

int compararClave(void *clave1, void *clave2);
Clave *recuperarClave(FILE *indice);
int persistirClave(Clave *clave, FILE *indice);

#endif // CLAVES_H_INCLUDED
