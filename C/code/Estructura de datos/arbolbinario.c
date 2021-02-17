#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    // Hijos recursivos
    struct nodo* izquierdo;
    struct nodo* derecho;
} Nodo;

typedef Nodo Arbol;

Nodo* CrearNodo(int valor) {
    Nodo* n = (Nodo *) malloc(sizeof(Nodo));
    n->valor = valor;
    n->derecho = n->izquierdo = NULL;
    return n;
}

void DestruirNodo(Nodo* n) {
    n->derecho = n->izquierdo = NULL; // Por si acaso
    free(n);
}

void Insertar(Nodo** arbol, int valor) {
    if (*arbol == NULL) {
        Nodo* n = CrearNodo(valor);
        *arbol = n;
    } else {
        // Los elementos menores a la izq, los elementos
        // mayores a la der.
        int valorRaiz = (*arbol)->valor;
        if (valor < valorRaiz) {
            Insertar(&(*arbol)->izquierdo, valor);
        } else {
            Insertar(&(*arbol)->derecho, valor);
        }
    }
}

void PreOrder(Nodo *arbol) {
    if (arbol) {
        printf("%d,", arbol->valor);
        PreOrder(arbol->izquierdo);
        PreOrder(arbol->derecho);
    }
}

void InOrder(Nodo *arbol) {
    if (arbol) {
        InOrder(arbol->izquierdo);
        printf("%d,", arbol->valor);
        InOrder(arbol->derecho);
    }
}

void PosOrder(Nodo *arbol) {
    if (arbol) {
        PosOrder(arbol->derecho);
        PosOrder(arbol->izquierdo);
        printf("%d,", arbol->valor);
    }
}

int Existe(Nodo* arbol, int valor) {
    if (!arbol) {
        return 0;
    } else if (arbol->valor == valor) {
       return 1;
    } else if (valor < arbol->valor) {
        return Existe(arbol->izquierdo, valor);
    } else {
        return Existe(arbol->derecho, valor);
    }
}

void DeterminarExistencia(Nodo* arbol, int valor) {
    if (Existe(arbol, valor)) {
        printf("El nodo %d existe. \n", valor);
    } else {
        printf("El nodo %d no existe. \n", valor);
    }
}

// Árbol binario de búsqueda
int main()
{
    Arbol *arbol = CrearNodo(10);
    Insertar(&arbol, 5);
    Insertar(&arbol, 11);
    Insertar(&arbol, 50);
    Insertar(&arbol, 3);
    Insertar(&arbol, 1);
    Insertar(&arbol, 17);
    Insertar(&arbol, 85);
    Insertar(&arbol, 12);
    Insertar(&arbol, 4);
    Insertar(&arbol, 8);

    DeterminarExistencia(arbol, 3);
    DeterminarExistencia(arbol, 14);
    DeterminarExistencia(arbol, 50);

    PreOrder(arbol);
    printf("\n");
    InOrder(arbol);
    printf("\n");
    PosOrder(arbol);
    printf("\n");

    return 0;
}
