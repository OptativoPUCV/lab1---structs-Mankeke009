#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) { 
  int nMayor = arr[0];
  for(int i = 0; i < size; i++){
    if(arr[i] > nMayor){
      nMayor = arr[i];
    }
  }
  return nMayor; 
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) {
  int aux;
  for (int i = 0; i < size / 2; i++){
    aux = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = aux;
  }
  
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
newsize apunta a una dirección válida que no ha sido inicializada con nigún valor específico. 
*newsize debe almacenar el tamaño del nuevo arreglo que se retorna.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) { 
  int *newArr = (int *)malloc(size * sizeof(int));
  int cont = 0;
  for(int i = 0; i < size; i++){
    if(arr[i] % 2 == 0){
      newArr[cont] = arr[i];
      cont ++;
    }
  }
  *newSize = cont;
  
  return newArr; 
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados de menor a mayor y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado de menor a mayor.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) {
  int tallaT = size1 + size2;
  int cont1 = 0;
  int cont2 = 0;
  for(int i = 0; i < tallaT;i++){
    if(cont1 < size1 && cont2 < size2){
      if(arr1[cont1] < arr2[cont2]){
        result[i] = arr1[cont1];
        cont1 ++;
      }
      else{
        result[i] = arr2[cont2];
        cont2 ++;
      }
    }
    else if (cont1 < size1) {
        result[i] = arr1[cont1];
        cont1++;
    } 
    else {
        result[i] = arr2[cont2];
        cont2++;
    } 
  }
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) {
  int ascendente = 1;
  int descendente = 1;

  for (int i = 0; i < size - 1; i++) {
      if (arr[i] > arr[i + 1]) {
          ascendente = 0;
      }
      if (arr[i] < arr[i + 1]) {
          descendente = 0;
      }
  }

  if (ascendente == 1) {
      return 1;
  } else if (descendente == 1) {
      return -1;
  } else {
      return 0;
  }
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,int anioNacimiento, int anioPublicacion) {
  libro -> anioPublicacion = anioPublicacion;
  libro->autor.anioNacimiento = anioNacimiento;
  strcpy(libro->autor.nombre, nombreAutor);
  strcpy(libro->titulo, titulo);

  
}
/*Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
Puedes guiarte con lo que vimos en las clases (diapos).
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) { 
  Nodo *inicio = NULL;
  Nodo *ultimo = NULL;

  for(int i = 0; i < size; i++){
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->numero = arr[i];
    nuevoNodo->siguiente = NULL;

    if(inicio == NULL){
      inicio = nuevoNodo;
      ultimo = nuevoNodo;
    }
    else{
      ultimo->siguiente = nuevoNodo;
      ultimo = nuevoNodo;
    }    
  }

  return inicio;
}
