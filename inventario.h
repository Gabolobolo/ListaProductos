//Archivo que contiene las declaraciones de las funciones usadas en productos.c//

//Bibliotecas//
#include <stdio.h>
#include <string.h>

//Definicion de las constantes (maximo numero de productos, longitud maxima del nombre del producto)//
#define maxproductos 10
#define longitunombre 25

//Declaracion de variables con "extern" para usar en ambos archivos//
extern char nombres[maxproductos][longitunombre];
extern int cantidades[maxproductos];
extern float precioUnidad[maxproductos];
extern float preciototal[maxproductos];
extern int cantidadproduc;

//Definicion de la funcion que calcula el precio total de un producto//
void calcularpreciototal(int a) {
  preciototal[a] = cantidades[a] * precioUnidad[a];
}

//Añadir a la lista//
void anadir() {

  if (cantidadproduc >= maxproductos) {
      printf("No hay más espacio\n");
      return;
  }

  printf("Ingrese el nombre del producto: ");
  scanf(" %25[^\n]", nombres[cantidadproduc]);

//Verifica que el producto no exista//
  for (int i = 0; i < cantidadproduc; i++) {
      if (strcmp(nombres[i], nombres[cantidadproduc]) == 0) {
          printf("Ese producto ya existe\n");
          return;
      }
  }

  printf("Ingrese la cantidad: ");
  if (scanf("%d", &cantidades[cantidadproduc]) < 1) {
      printf("Cantidad inválida.\n");
      return;
  }

  printf("Ingrese el precio unitario: ");
  if (scanf("%f", &precioUnidad[cantidadproduc]) < 1) {
      printf("Precio inválido.\n");
      return;
  }

  calcularpreciototal(cantidadproduc);
  cantidadproduc++;
  printf("Producto añadido correctamente.\n");
}

//Modificar la cantidad y precio de un producto//
void editar() {
  char nombre[longitunombre];
  printf("Ingrese el nombre del producto a editar: ");
  scanf(" %26[^\n]", nombre);

  for (int i = 0; i < cantidadproduc; i++) {
      if (strcmp(nombres[i], nombre) == 0) {
          printf("Ingrese la nueva cantidad: ");
          if (scanf("%d", &cantidades[i]) <= 0) {
              printf("Cantidad inválida.\n");
              return;
          }

          printf("Ingrese el nuevo precio unitario: ");
          if (scanf("%f", &precioUnidad[i]) <=0 ) {
              printf("Precio inválido.\n");
              return;
          }

          calcularpreciototal(i);
          printf("Producto editado correctamente.\n");
          return;
      }
  }

  printf("Producto no encontrado\n");
}

void eliminar() {
  char nombre[longitunombre];
  printf("Ingrese el nombre del producto a eliminar: ");
  scanf(" %24[^\n]", nombre); 

  for (int i = 0; i < cantidadproduc; i++) {
      if (strcmp(nombres[i], nombre) == 0) {
          for (int j = i; j < cantidadproduc - 1; j++) {
              strcpy(nombres[j], nombres[j + 1]);
              cantidades[j] = cantidades[j + 1];
              precioUnidad[j] = precioUnidad[j + 1];
              preciototal[j] = preciototal[j + 1];
          }
          cantidadproduc--;
          printf("Producto eliminado correctamente.\n");
          return;
      }
  }

  printf("Producto no encontrado\n");
}

void lista() {
  if (cantidadproduc == 0) {
      printf("No hay productos en el inventario.\n");
      return;
  }

  printf("Lista de productos:\n\n");
  printf("| %-20s | %-10s | %-15s | %-15s |\n", "Nombre", "Cantidad", "Precio Unitario", "Precio Total");
  printf("|----------------------|------------|------------------|------------------|\n");
  for (int i = 0; i < cantidadproduc; i++) {
      printf("| %-20s | %-10d | $%-15.2f | $%-15.2f |\n",
             nombres[i], cantidades[i], precioUnidad[i], preciototal[i]);
  }
}
