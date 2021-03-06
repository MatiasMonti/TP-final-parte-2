#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "lista.h"

/**
 * typedef Arbol: TAD de un arbol AVL
 * @clave: clave de ordenamiento
 * @balance: factor de balance entre altura izquierda y derecha
 * @hijos: vector arista hacia los hijos
 *
 * Este TAD ser� utilizado para representar el �rbol Binario de
 * B�squeda Balanceado AVL. Existe el arbol nulo, el �rbol unitario
 * es asimilable a un nodo y cada hijo de un nodo es un sub�rbol,
 * por lo que se omite la definici�n de nodo.
 */
typedef struct Arbol {
    void *clave;
    int balance;
    struct Arbol *izquierda;
    struct Arbol *derecha;
} Arbol;

/**
 * typedef Comparador: firma de funci�n para la comparaci�n de claves
 * @clave1: clave que se va a comparar.
 * @clave2: clave que se va a comparar.
 *
 * Este tipo ser� utilizado para definir la firma de la funci�n
 * comparadora de claves en el ordenamiento del �rbol. La funci�n no
 * debe tener ninguna precondici�n, en particular, las claves podr�an
 * ser nulas. Debe retornar un valor entero en la forma definida por
 * la funci�n standar `strcmp`:
 *  - negativo cuando clave1 es menor que clave2.
 *  - positivo cuando clave1 es mayor que clave2.
 *  - cero cuando clave1 es igual en valor a clave2.
 */
typedef int (*Comparador) (void* clave1, void* clave2);

/**
 * insertarArbol() - M�todo para insertar una nueva clave en el �rbol.
 * @arbol: �rbol al que se quiere insertar la nueva clave.
 * @clave: una nueva clave.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para insertar una nueva clave en el �rbol. Precondici�n: memoria
 * suficiente. Postcondicion: si la clave no existe en el �rbol se aloca
 * memoria para un nuevo �rbol unitario con la clave a insertar; la raiz del
 * �rbol puede haber cambiado; un enlace del �rbol puede haber cambiado para
 * incluir el �rbol unitario con la nueva clave.
 *
 * Return: un Arbol que contiene la clave.
 */
Arbol *insertarArbol(Arbol *arbol, void *clave, Comparador funcion);

/**
 * eliminarArbol() - M�todo para borrar una clave existente en el �rbol.
 * @arbol: �rbol al que se quiere borrar la clave.
 * @clave: una clave existente en el �rbol.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para borrar una clave existente en el �rbol. Precondici�n: ninguna.
 * Postcondicion: si la clave existe en el �rbol se liberar� la memoria de
 * un �rbol unitario; la raiz del �rbol puede haber cambiado; un enlace del
 * �rbol puede haber cambiado para saltear el arbol unitario eliminado; el
 * �rbol unitario que conten�a la clave originalmente puede haber cambiado
 * la clave ahora.
 *
 * Return: un Arbol que no contiene la clave.
 */
Arbol *eliminarArbol(Arbol *arbol, void *clave, Comparador funcion);

/**
 * buscarArbol() - M�todo para buscar una clave existente en el �rbol.
 * @arbol: �rbol en el que se quiere buscar la clave.
 * @clave: una clave existente en el �rbol.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo para buscar una clave existente en el �rbol. Precondici�n: ninguna.
 * Postcondicion: ninguna.
 *
 * Return: un Arbol que contiene la clave en su raiz o el arbol nulo si no.
 */
Arbol *buscarArbol(Arbol *arbol, void *clave, Comparador funcion);

/**
 * preordenArbol() - Genera una lista con el recorrido pre orden del �rbol.
 * @arbol: �rbol que se desea recorrer.
 *
 * El m�todo genera una lista con recorrido pre orden del �rbol. Precondici�n:
 * memoria suficiente. Postcondicion: se alocar� memoria para una lista con
 * cada sublista apuntando a cada subarbol en recorrido "pre orden": la raiz
 * se recorre antes que los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *preordenArbol(Arbol *arbol);

/**
 * postordenArbol() - Genera una lista con recorrido post orden del �rbol.
 * @arbol: �rbol que se desea recorrer.
 *
 * El m�todo genera una lista con recorrido post orden del �rbol. Precondici�n:
 * memoria suficiente. Postcondicion: se alocar� memoria para una lista con
 * cada sublista apuntando cada subarbol en recorrido "post orden": la raiz se
 * recorre despu�s de los hijos.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *postordenArbol(Arbol *arbol);

/**
 * preordenArbol() - Genera una lista con recorrido en orden del �rbol.
 * @arbol: �rbol que se desea recorrer.
 *
 * El m�todo genera una lista con recorrido en orden del �rbol. Precondici�n:
 * memoria suficiente. Postcondicion: se alocar� memoria para una lista con cada
 * sublista apuntando cada subarbol en recorrido "en orden": la raiz se recorre
 * despu�s del hijo con claves menores y antes del hijo con claves mayores.
 *
 * Return: una lista. El arbol nulo devuelve una lista nula.
 */
Lista *enordenArbol(Arbol *arbol);

/* Tipos y m�todos privados */

/**
 * crearArbol() - M�todo para crear un �rbol unitario.
 * @clave: clave con la que se crear� el arbol unitario.
 *
 * M�todo para crear un �rbol unitario. Precondici�n: memoria suficiente.
 * Postcondicion: se alocar� memoria para un �rbol unitario; se inicializar�n
 * sus atributos, sus aristas no conducen a ning�n sub�rbol y est� balanceado
 *
 * Return: un �rbol.
 */
Arbol *crearArbol(void *clave);

/**
 * insertarArbolBalanceado() - Inserci�n balanceada.
 * @destino: arista al sub�rbol d�nde se desea insertar la clave.
 * @clave: clave que se desea insertar.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo que realiza la inserci�n balanceada de la @clave en el sub�rbol al
 * que conduce la arista @destino. Precondici�n: memoria suficiente.
 * Postcondicion: es posible que se aloque memoria para un �rbol unitario y se
 * inicialicen sus atributos; es posible que se modifiquen aristas del �rbol
 * para que est� balanceado y se alteren los factores de equilibrio de varios
 * sub�rboles; puede cambiar el sub�rbol al que conduce la arista @destino.
 *
 * Return: el cambio relativo entre la altura del �rbol al que conduc�a la
 *.        arista @destino y la altura del �rbol al que conduce ahora.
 */
int insertarArbolBalanceado(Arbol **destino, void *clave, Comparador funcion);

/**
 * borrarArbolBalanceado() - Borrado balanceado.
 * @destino: arista al sub�rbol del que se desea borrar la clave.
 * @clave: clave que se desea borrar.
 * @funcion: funci�n comparadora de claves.
 *
 * M�todo que realiza el borrado balanceado de la @clave en el sub�rbol al
 * que conduce la arista @destino. Precondici�n: ninguna.
 * Postcondicion: es posible que se desaloque memoria para un �rbol unitario;
 * es posible que se modifiquen aristas del �rbol para que est� balanceado y
 * se alteren los factores de equilibrio de varios sub�rboles; puede cambiar
 * el sub�rbol al que conduce la arista @destino.
 *
 * Return: el cambio relativo entre la altura del �rbol al que conduc�a la
 *.        arista @destino y la altura del �rbol al que conduce ahora.
 */
int eliminarArbolBalanceado(Arbol **destino, void *clave, Comparador funcion);

/**
 * balancearArbol() - M�todo para balancear un �rbol.
 * @destino: arista al sub�rbol que se desea balancear.
 *
 * M�todo para balancear un �rbol seg�n su factor de equilibrio. Precondici�n:
 * la arista @destino no conduce a un �rbol nulo. Postcondicion: es posible
 * que se modifiquen aristas del �rbol para que est� balanceado y se alteren
 * los factores de equilibrio de los sub�rboles; puede cambiar el sub�rbol
 * al que conduce la arista @destino.
*/
void balancearArbol(Arbol **destino);

/**
 * rotarDerecha() - Cambia la ra�z de un �rbol por la del sub�rbol derecho.
 * @arbol: arista al sub�rbol que se desea rotar.
 *
 * M�todo para cambiar la ra�z de un �rbol por la de su sub�rbol derecho.
 * Precondici�n: la arista @arbol no debe conducir a un �rbol nulo.
 * Postcondicion: se modificaran aristas del �rbol y el sub�rbol derecho y
 * aumentar�n sus factores de equilibrio; la arista @destino conducir� a su
 * sub�rbol derecho.
 */
void rotarDerecha(Arbol **arbol);

/**
 * rotarIzquierda() - Cambia la ra�z de un �rbol por la del sub�rbol izquierdo.
 * @arbol: arista al sub�rbol que se desea rotar.
 *
 * M�todo para cambiar la ra�z de un �rbol por la de su sub�rbol izquierdo.
 * Precondici�n: la arista @arbol no debe conducir a un �rbol nulo.
 * Postcondicion: se modificar�n aristas del �rbol y el sub�rbol izquierdo y
 * disminuir�n sus factores de equilibrio; la arista @destino conducir� a su
 * sub�rbol izquierdo.
 */
void rotarIzquierda(Arbol **arbol);

/**
 * buscarMaximo() - M�todo hallar el m�ximo valor de la clave en un �rbol.
 * @arbol: �rbol del que se desea hallar el m�ximo.
 *
 * M�todo hallar el m�ximo valor de la clave en un �rbol. Precondici�n:
 * el �rbol no debe ser nulo. Postcondicion: ninguna.
 *
 * Return: la m�xima clave del @arbol.
 */
void *buscarMaximo(Arbol *arbol);

#endif // AVL_H_INCLUDED
