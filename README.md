```markdown
# Estructuras de Datos en C - Casos de Prueba

## Stack (Pila)

Comportamiento LIFO (Last In, First Out). El ultimo elemento en entrar es el primero en salir.

### Casos de Prueba

| Operacion | Entrada | Resultado Esperado |
|-----------|---------|---------------------|
| Crear stack | capacidad = 5 | Stack creado con size=0, capacity=5 |
| Crear stack | capacidad = 0 | Retorna NULL (falla) |
| is_empty | stack recien creado | true |
| push | item = 2 | true, size=1 |
| push | item = 9 | true, size=2 |
| push | item = 7 | true, size=3 |
| push | item = 6 | true, size=4 |
| push | item = 3 | true, size=5 |
| is_full | size=5, capacity=5 | true |
| push | item = 5 | false (falla), size sigue 5 |
| peek | ninguno | retorna 3, no cambia size |
| pop | ninguno | retorna 3, size=4 |
| pop | ninguno | retorna 6, size=3 |
| pop | ninguno | retorna 7, size=2 |
| pop | ninguno | retorna 9, size=1 |
| pop | ninguno | retorna 2, size=0 |
| is_empty | size=0 | true |
| peek | stack vacio | retorna false, status indica error |
| pop | stack vacio | retorna false, status indica error |

### Orden de los elementos

Pushes: 2, 9, 7, 6, 3
Pops: 3, 6, 7, 9, 2 (orden inverso)

---

## Queue (Cola)

Comportamiento FIFO (First In, First Out). El primer elemento en entrar es el primero en salir.

### Casos de Prueba

| Operacion | Entrada | Resultado Esperado |
|-----------|---------|---------------------|
| Crear queue | ninguno | head=NULL, tail=NULL, size=0 |
| is_empty | queue recien creado | true |
| enqueue | value = 4 | head=4, tail=4, size=1 |
| enqueue | value = 5 | head=4, tail=5, size=2 |
| enqueue | value = 6 | head=4, tail=6, size=3 |
| size | queue con 3 elementos | 3 |
| peek | ninguno | retorna 4 (primer elemento) |
| dequeue | ninguno | retorna 4, size=2, head ahora es 5 |
| peek | ninguno | retorna 5 |
| dequeue | ninguno | retorna 5, size=1, head ahora es 6 |
| peek | ninguno | retorna 6 |
| dequeue | ninguno | retorna 6, size=0, head=NULL, tail=NULL |
| is_empty | size=0 | true |
| peek | queue vacio | retorna 0, status=false |
| dequeue | queue vacio | retorna 0, status=false |

### Orden de los elementos

Enqueues: 4, 5, 6
Dequeues: 4, 5, 6 (mismo orden)

---

## Hash Table (Tabla Hash)

Almacena pares clave-valor. Usa una funcion hash para determinar donde guardar cada par.

### Casos de Prueba

| Operacion | Entrada | Resultado Esperado |
|-----------|---------|---------------------|
| Crear tabla | ninguno | TABLE_SIZE slots, todos NULL |
| ht_set | clave="name1", valor="em" | Guarda en slot hash("name1") |
| ht_set | clave="name2", valor="hola" | Guarda en slot hash("name2") |
| ht_set | clave="name3", valor="picsa" | Guarda en slot hash("name3") |
| ht_get | clave="name2" | retorna "hola" |
| ht_get | clave="name1" | retorna "em" |
| ht_get | clave inexistente | retorna NULL |
| ht_set | misma clave "name2", valor="adios" | Reemplaza valor anterior |
| ht_get | clave="name2" | retorna "adios" |

### Colisiones

Si dos claves diferentes producen el mismo hash:

| Operacion | Entrada | Resultado Esperado |
|-----------|---------|---------------------|
| ht_set | claveA, valor="x" | Guarda en slot N |
| ht_set | claveB, valor="y" | Mismo slot N, se encadena (linked list) |
| ht_get | claveA | Encuentra "x" recorriendo la lista |
| ht_get | claveB | Encuentra "y" recorriendo la lista |

### Eliminacion

| Escenario | Resultado Esperado |
|-----------|---------------------|
| Eliminar unico elemento en slot | Slot queda NULL |
| Eliminar primer elemento de cadena | Head apunta al siguiente |
| Eliminar elemento del medio de cadena | Nodo anterior apunta al siguiente |
| Eliminar ultimo elemento de cadena | Nodo anterior apunta a NULL |
| Eliminar clave inexistente | No pasa nada (retorna sin error) |

---

## Resumen Rapido

| Estructura | Acceso | Insercion | Eliminacion | Orden |
|------------|--------|-----------|-------------|-------|
| Stack | O(1) al tope | O(1) al tope | O(1) al tope | LIFO |
| Queue | O(1) al frente | O(1) al final | O(1) al frente | FIFO |
| Hash Table | O(1) promedio | O(1) promedio | O(1) promedio | Desordenado |

### Cuando usar cada una

- **Stack**: Deshacer operaciones (Ctrl+Z), evaluar expresiones, backtracking
- **Queue**: Procesos en espera, impresion de documentos, BFS
- **Hash Table**: Busquedas rapidas por clave, cache, conteo de frecuencias
```
