#include <stdio.h>
#include <omp.h>

int main(int argc, const char *argv[]) {
  int n = 10000;
  int suma = 0;
  int i;

  int numeros[n];

  for(i = 0; i < n; ++i) {
    numeros[i] = 1;
  }

  // Estamos definiendo una región paralela, es decir, dentro de ese bloque de instrucciones,
  // el compilador abrirá varios hilos de ejecución y lo resolverá de manera paralela el siguiente
  // ciclo for
  #pragma omp parallel private(i)
  {
  for(i = 0; i < n; ++i) {
    suma += numeros[i];
  }
}

  printf("La suma = %d\n", suma);
  return 0;
}
