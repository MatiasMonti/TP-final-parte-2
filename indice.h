#ifndef __INDICE__
#define __INDICE__
#include <stdio.h>
#include "avl/avl.h"

/**
 * typedef Indice: TAD de Indice implementado como Arbol AVL.
 *
 * Este TAD ser� utilizado para representar el Indice implementado como
 * un �rbol AVL. Como no posee otro atributo, pues se utilizar� un solo
 * Indice, es directamente un sin�nimo del �rbol AVL: el registro de
 * Clave y su funci�n comparadora son directamente parte de la
 * implementaci�n.
 */
typedef Arbol Indice;

/**
 * typedef Iterador: TAD de Iterador para Indice implementado con �rbol AVL.
 *
 * Este TAD ser� utilizado para representar el Iterador del Indice
 * implementado como �rbol AVL. Como no posee otro atributo es
 * directamente un sin�nimo de Lista/Pila de subarboles.
 */
typedef Lista Iterador;

/**
 * typedef Persistente: firma de funci�n para persistir claves
 * @clave: clave que se va a persistir en el archivo.
 * @archivo: archivo en el cual se guardar� la clave.
 *
 * Este tipo ser� utilizado para definir la firma del metodo
 * encargado de persistir las claves en archivo. Precondiciones:
 * el archivo ya estar� abierto.
 *
 * Return: un entero como `fwrite`: 1 es exito, 0 es error.
 */
typedef int (*Persistente) (void *clave, FILE* archivo);

/**
 * typedef Recuperador: firma de funci�n para recuperar una clave
 * @direccionClave: direcci�n en memoria de la clave que se quiere recuperar.
 * @archivo: archivo del cual se recuperar� la clave.
 *
 * Este tipo ser� utilizado para definir la firma del metodo
 * encargado de recuperar las claves de un archivo. Precondiciones:
 * el archivo ya estar� abierto y no habr� llegado al final; hay
 * suficiente memoria para reconstituir la clave.
 */
typedef int (*Recuperador) (void **clave, FILE *archivo);

/**
 * agregarClaveIndice() - M�todo para agregar una nueva clave al Indice.
 * @indice: indice al que se quiere insertar la nueva clave.
 * @clave: una nueva clave.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para insertar una nueva clave al Indice. Precondici�n: memoria
 * suficiente para el nodo de la estructura con la que se haya implementado
 * el Indice. Postcondicion: si la clave no existe en el Indice se aloca
 * memoria el nodo de la estructura con la que se haya implementado el Indice;
 * el Indice puede haber cambiado.
 *
 * Return: un Indice que contiene la clave.
 */
Indice *agregarClaveIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * borrarClaveIndice() - M�todo para borrar una clave existente del Indice.
 * @indice: Indice al que se quiere borrar la clave.
 * @clave: una clave existente en el Indice.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para borrar una clave existente en del Indice. Precondici�n: ninguna.
 * Postcondicion: si la clave existe en el �rbol se liberar� la memoria de
 * un nodo de la estructura que implementa el Indice; el Indice puede haber
 * cambiado.
 *
 * Return: un Indice que no contiene la clave.
 */
Indice *borrarClaveIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * obtenerVistaMenorIndice() - Obtener un sub Indice con claves menores.
 * @indice: Indice del que se quiere obtener un sub Indice.
 * @clave: una clave que ser� mayor o igual a todas las del sub Indice.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para obtener un sub Indice con las claves menores a la clave.
 * Precondici�n: memoria suficiente para crear los nodos de la estructura
 * elegida para implementar el Indice en cantidad necesaria para obtener
 * un sub Indice con las claves menores. Postcondicion: se crearan los
 * nodos de la estructura elegida para implementar el Indice en cantidad
 * suficiente para obtener un sub Indice con las claves menores.
 *
 * Return: un nuevo Indice s�lo con las claves menores a la clave.
 */
Indice *obtenerVistaMenorIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * obtenerVistaMayorIndice() - Obtener un sub Indice con claves mayores.
 * @indice: Indice del que se quiere obtener un sub Indice.
 * @clave: una clave que ser� menor o igual a todas las del sub Indice.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para obtener un sub Indice con las claves mayores a la clave.
 * Precondici�n: memoria suficiente para crear los nodos de la estructura
 * elegida para implementar el Indice en cantidad necesaria para obtener
 * un sub Indice con las claves mayores. Postcondicion: se crearan los
 * nodos de la estructura elegida para implementar el Indice en cantidad
 * suficiente para obtener un sub Indice con las claves mayores.
 *
 * Return: un nuevo Indice s�lo con las claves mayores a la clave.
 */
Indice *obtenerVistaMayorIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * persistirIndice() - Almacena el Indice en un archivo.
 * @indice: Indice que se desea almacenar.
 * @funcion: funci�n para persistir claves.
 * @archivo: archivo en el cual se desea almacenar el Indice.
 *
 * M�todo para almacena el Indice en un archivo. Precondici�n: el archivo
 * ya ha sido abierto con exito para escribir en el; debe haber suficiente
 * memoria en el medio de almacenamiento. Postcondicion: se escribir� en
 * el archivo. El Indice nulo no posee consecuencias.
 */
void persistirIndice(Indice *indice, Persistente funcion, FILE* archivo);

/**
 * recuperarIndice() - Recupera un Indice almacenado en un archivo.
 * @funcion: funci�n para recuperar claves de un archivo.
 * @archivo: archivo del cual se desea recuperar el Indice.
 *
 * M�todo para recuperar un Indice de un archivo. Precondici�n: el archivo
 * ya ha sido abierto con exito para lectura desde la posici�n inicial; debe
 * haber suficiente memoria para recrear el Indice. Postcondicion: se alocar�
 * memoria para reconstituir el Indice.
 *
 * Return: un nuevo Indice recuperado del archivo.
 */
Indice *recuperarIndice(Recuperador funcion, FILE* archivo);

/**
 * obtenerIterador() - M�todo para obtener un Iterador en orden del Indice.
 * @indice: Indice que se desea recorre.
 *
 * M�todo para obtener un Iterador en orden del Indice. Precondici�n:
 * memoria suficiente para crear la estructura con la que se haya
 * implementado el Iterador del Indice. Postcondicion: se alocar� la memoria
 * suficiente para la estructura que implementa el Iterador.
 *
 * Return: un Iterador.
 */
Iterador *obtenerIterador(Indice *indice);

/**
 * siguienteIterador() - M�todo para obtener la siguiente clave de un Iterador.
 * @iterador: Iterador que recorre el Indice.
 *
 * M�todo para obtener la siguiente clave en la iteracion de un Indice.
 * Precondici�n: el Indice no debe modificarse durante la iteraci�n; memoria
 * suficiente para modificar la estructura con la que se haya implementado el
 * Iterador del Indice; no deben ingresarse datos nulos como claves.
 * Postcondicion: se liberar� y alocar� la memoria suficiente para la
 * estructura que implementa el Iterador; el Iterador se modificar�.
 *
 * Return: una clave.
 */
void *siguienteIterador(Iterador **iterador);

/* M�todos y Tipos privados */

/**
 * enum HijosArbol - Enumeraci�n de la posesi�n de hijos de un nodo Arbol.
 * @SIN_HIJOS: El nodo no tiene hijos.
 * @HIJO_IZQ: El nodo s�lo tiene un hijo en la rama izquierda.
 * @HIJO_DER: El nodo s�lo tiene un hijo en la rama derecha.
 * @DOS_HIJOS: El nodo tiene hijos en ambas ramas izquierda.
 *
 * Enumeraci�n que describe los distintos casos para la posesi�n de hijos
 * por un sub Arbol, Arbol unitario o nodo de un Arbol. Ser� utilizado
 * para la persistencia del Indice implementado como Arbol AVL de manera
 * de evitar o bien persistir claves nulas en archivo o bien utilizar la
 * funcion comparadora de claves con cada clave recuperada.
 */
 enum HijosArbol {SIN_HIJOS, HIJO_IZQ, HIJO_DER, DOS_HIJOS};

/**
 * buscarClaveIndice() - M�todo para buscar una clave existente en el Indice.
 * @indice: indice en el que se quiere buscar la clave.
 * @clave: una clave existente en el indice.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para buscar una clave existente en el Indice. Precondici�n: ninguna.
 * Postcondicion: ninguna.
 *
 * Return: la clave encontrada o en su defecto NULL.
 */
void *buscarClaveIndice(Indice *indice, void *clave, Comparador funcion);

/**
 * liberarVistaMayor() - M�todo para liberar de la memoria la vista.
 * @vista: indice en el que se quiere buscar la clave.
 *
 * M�todo para liberar de la memoria la vista creada con `obtenerVistaMayor`.
 * Precondici�n: ninguna. Postcondicion: se liberar� memoria.
 */
void liberarVistaMayor(Indice *vista);

/**
 * liberarVistaMenor() - M�todo para liberar de la memoria la vista.
 * @vista: indice en el que se quiere buscar la clave.
 *
 * M�todo para liberar de la memoria la vista creada con `obtenerVistaMenor`.
 * Precondici�n: ninguna. Postcondicion: se liberar� memoria.
 */
void liberarVistaMenor(Indice *vista);

#endif //__INDICE__
