# DAA-Practica-2

## Informe sobre instrucciones en algoritmos de ordenación

Los dos programas de ejemplo que implementan algoritmos de ordenación
(`bubble_sort.ram` e `insertion_sort.ram`) comparten la misma maquinaria
RAM (acceso a cintas, memoria dinámica/estática, saltos, aritmética) pero
tienen estructuras y, por tanto, conjuntos de instrucciones ligeramente
distintos.

### Instrucciones comunes

Ambos algoritmos utilizan:
	* **READ/WRITE** para acceder a la cinta de entrada/salida
	* **LOAD/STORE** para mover datos entre registros y memoria dinámica
	* **ADD/SUB** y constantes para incrementar/decrementar índices y contadores
	* **JUMP, JZERO, JGTZ** para controlar los bucles y las condiciones
	* **HALT** al final del programa

En general, hay dos fases idénticas en ambos ficheros: lectura inicial de
valores desde la cinta (`leer_bub` / `leer_ins`) y escritura del resultado
ordenado (`escribir`), las cuales emplean las mismas instrucciones en el
mismo orden.

### Diferencias clave

1. **Estructura de bucles**
	 * *Bubble sort* recorre sucesivas pasadas decrementando un contador `2[0]`
		 y moviendo un puntero `3[0]` a lo largo de la lista. Comprueba pares de
		 valores con `LOAD 3[0][0]` / `SUB 3[0][0]`, y realiza el intercambio
		 mediante cuatro `LOAD/STORE` adicionales cuando es necesario.
	 * *Insertion sort* mantiene dos punteros (`2[0]`, `3[0]`) y un valor de
		 comparación (`4[0]`). El bucle interior (`while_ins`) hace saltos
		 `JGTZ`, `JZERO` para determinar cuándo detenerse y usa `swap_ins` para
		 desplazar el elemento actual en el subarray ya ordenado.

2. **Acceso a memoria**
	 * Bubble utiliza direcciones fijas (`0[0]9`, `0[0]1`) para ajustar los
		 límites del bucle y la longitud de la lista. El acceso indirecto se usa
		 frecuentemente (`5[0][0]`, `3[0][0]`) durante el intercambio.
	 * Insertion también emplea acceso indirecto, pero además incorpora un
		 chequeo extra con `JZERO` en el bucle interno para detectar el final de
		 la lista desplazada.

3. **Manipulación de constantes**
	 * Ambos programas inicializan contadores con `LOAD 0[0]10` o `LOAD 0[0]11`.
		 En insertion se necesita el valor 11 para controlar el primer desplazamiento.

### Recuento de instrucciones ejecutadas (medido en ejecuciones de prueba)

Los contadores se obtuvieron de la salida del programa tras ejecutar cada
algoritmo con la misma `input_tape1.txt` y registrando la línea de resumen
que muestra el total de saltos e instrucciones ejecutadas.

- **Insertion sort:** 386 instrucciones ejecutadas.
- **Bubble sort:** 472 instrucciones ejecutadas.

Estos valores permiten comparar la eficiencia práctica (en número de
instrucciones RAM ejecutadas) de ambas implementaciones concretas usadas en
esta práctica.

### Resumen

La gama de instrucciones utilizada por los dos algoritmos es prácticamente
la misma; la diferencia radica en el orden y la combinación de saltos/memoria
directa durante el bucle principal. Bubble sort emplea más operaciones de
intercambio explícito, mientras que insertion sort recurre a una comprobación
adicional (`JZERO`) en el bucle interno y dos fases de asignación para
desplazar elementos.

