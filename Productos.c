//Funciones y variables definidas en inventario.h//
#include "funciones.c"

//Se declaran las variables globales para almacenar los nombres de los productos//
char nombres[maxproductos][longitunombre];
int cantidades[maxproductos];
float precioUnidad[maxproductos];
float preciototal[maxproductos];
int cantidadproduc = 0;

//Menu interactivo en bucle "do-while" (permite editar la lista de productos)
int main() {
  int opcion;

  do {
      printf("\nSeleccione la opcion que quiere usar:\n");
      printf("Anadir Producto: 1\n");
      printf("Editar Producto: 2\n");
      printf("Eliminar Producto: 3\n");
      printf("Lista de productos: 4\n");
      printf("Finalizar: 5\n");
      printf("Ingrese una opcion: ");
      scanf("%d", &opcion);

      switch (opcion) {
          case 1:
              anadir();
              break;
          case 2:
              editar();
              break;
          case 3:
              eliminar();
              break;
          case 4:
              lista();
              break;
          case 5:
              printf("Saliendo...\n");
              break;
          default:
              printf("Opcion invalida, elija nuevamente.\n");
      }
  } while (opcion != 5);

    return 0;
  }



