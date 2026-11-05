# Práctica: Ticket de compra

> Llena cada sección en la fase que se indica. Las instrucciones completas están en `PRACTICA.md`.
> Si una pregunta no aplica (por ejemplo, no hiciste el Experimento C o no tuviste dudas), escribe `No aplica`. Si te sobran filas en una tabla, bórralas.

## 1. Descripción del problema (Fase 1)
Lo que hace mi programa es generar un ticket de compra de cualquier producto con sus datos iva, descuento, subtotal, total. Lo que soluciona este codigo es muy importante pues una muestra fisica de lo que una persona esta adquiriendo. Esto hace que se guarde un registro y mantenga un orden.

_____

## 2. Entradas y salidas (Fase 1)
Entradas: nombre, precio, cantidad y descuento. 
Salidas: ticket de compra con el subtotal, el descuento, el IVA y el total.

**Entradas:**

| Entrada | Tipo de dato | Función de `utilerias.h` |
|---|---|---|
| _nombre____ | _string____ | _inline std::string leerCadena____ |
| precio | _double____ | __inline double leerDecimal___ |
| cantidad  | __int___ | __inline int leerEntero___ |
| descuento | __double___ | __inline double leerDecimal___ |

**Salida** (¿qué datos muestra el ticket?):
__muestra un ticket de compra con el subtotal, el descuento, el IVA y el total___

**¿El IVA se calcula sobre el subtotal o sobre lo que queda después del descuento? ¿Por qué?**
___Sobre lo que queda despues del descuento el total__

## 3. Restricciones e invariante (Fases 1 y 2)

**Restricciones** (¿qué debe cumplirse?):

| Dato | ¿Qué valores son válidos? | ¿Por qué? |
|---|---|---|
| Nombre del producto | ___Letras, números y espacios__ | __Porque es necesario identificar el producto correctamente.___ |
| Precio | ___Tinen que ser numeros mayores a 0__ | _Porque no se puede se;alar un precio con letras____ |
| Cantidad | __Tienen que ser numeros mayores a 0___ | __Porque no se puede utilizar letras para se;alar una cantidad___ |
| Descuento (%) | __de 0 a 100__ | ___porque va del minimo al maxiomo del precio del producto __ |

**¿Qué hace mi programa si el usuario escribe un dato fuera de rango?**
__El programa vuelve a pedir el dato hasta que el usuario escriba un valor válido.___

**¿Puede el total salir negativo? ¿Por qué?**
_No, porque el descuento solo puede estar entre 0 y 100 %, por lo que nunca será mayor que el subtotal.____

**Invariante 1** (después del ciclo que valida el precio, ¿qué es siempre cierto sobre `precio`?):
___Que sea un numero mayor a 0__

**Invariante 2** (¿qué relación se cumple siempre entre el subtotal, el descuento, el IVA y el total?):
__El total siempre se calcula restando el descuento al subtotal y después aplicando el IVA.___

## 4. Casos resueltos a mano (Fase 1)

| Caso | Nombre | Precio | Cantidad | Descuento (%) | Subtotal | Descuento ($) | IVA | Total |
|---|---|---|---|---|---|---|---|---|
| 1 (sin descuento) | Papas | __50___ | __2___ | _0____ | __100___ | __0___ | __16___ | ___116__ |
| 2 (con descuento) | _Dulce____ | __200___ | _1____ | ___20__ | ___200__ | __40___ | __25.60___ | ____185.60_ |
| 3 (precio con centavos) | __Pluma_ | __15.50__ | __3___ | __10_ | _46.50__ | _4.65__ | _6.70___ | __48.55___ |

## 5. Tipo de dato abstracto (Fase 1)

| TDA | Datos (¿qué tiene?) | Operaciones (¿qué se puede hacer con él?) |
|---|---|---|
| Producto | nombre (texto), _precio____, ___cantidad__ | calcular su subtotal |
| __Ticket___ | __producto, descuento, IVA, total___ | ___calcular descuento y total a pagar__ |

**Jerarquías:** una tienda vende productos por pieza (un cuaderno) y productos por peso (un kilo de tortillas). ¿Los dos son productos? ¿Qué datos tienen en común y cuál cambia?
__Los dos son productos. Ambos tienen nombre y precio. Lo que cambia es la forma de medir la cantidad, ya que uno se vende por piezas y el otro por peso.___

## 6. Análisis descendente (Fase 2)
<!-- Completa el árbol. Marca con (ya existe) las partes que ya resuelve una función de utilerias.h o de ticket.h. -->

```
Generar ticket de compra
├── 1. Mostrar bienvenida
├── 2. Pedir los datos
│     ├── 2.1 Pedir el nombre del producto
│     ├── 2.2 Pedir el precio (y validar que __que sea mayor a 0___)
│     ├── 2.3 __Pedir la cantidad__
│     └── 2.4 __Pedir el descuento___
├── 3. Calcular los importes
│     ├── 3.1 Calcular el subtotal
│     ├── 3.2 ___Calcular el descuento__
│     ├── 3.3 __Calcular el IVA___
│     └── 3.4 __Calcular el total___
└── 4. _Mostrar el ticket____
```

**Análisis ascendente: ¿qué partes del árbol ya estaban resueltas por una función que existe? ¿Cuáles?**
___Las de pedir datos y calcular, con leerCadena, leerDecimal, leerEntero, calcularSubtotal y calcularDescuento.__

**¿Alguna parte del árbol hacía más de una cosa? ¿Cómo la dividiste?**
_Si calcular los importes. Lo dividí en subtotal, descuento, iva y total.____

## 7. Módulos y receta (Fase 2)

| Módulo | ¿Qué recibe? | ¿Qué devuelve? | ¿Función o procedimiento? |
|---|---|---|---|
| `calcularSubtotal` | precio, cantidad | el subtotal | Función |
| `calcularDescuento` | subtotal, porcentaje | el monto del descuento | Función |
| `calcularIVA` | __subtotal y descuento___ | _El iva____ | __Funcion___ |
| `imprimirTicket` | __nombre, precio, cantidad, subtotal, descuento, IVA y total__| _nada_ | __Procedimiento___ |
| ___`calcularTotal`__ | __subtotal, descuento e IVA___ | ___Le precio total__ | __Funcion___ |

<!-- Tu receta va en el archivo RECETA.md. Aquí solo responde las preguntas. -->

**¿Probé mi receta a mano con mis 3 casos?** Si
**¿Tuve que corregirla? ¿Qué cambié?** __Si el orden de los procedimientos___

## 8. Cómo compilar y ejecutar (Fase 3)

Compilar (desde la carpeta del proyecto):

```bash
g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
```

Ejecutar en macOS:

```bash
./ticket
```

Ejecutar en Windows:

```bash
.\ticket.exe
```

**¿En qué sistema operativo trabajé?** __En Windows___

## 9. Ejemplo de ejecución (Fase 3)
Escriba el nombre del producto: Cuaderno
Escriba el precio en pesos: 50
Escriba la cantidad:2
Escriba el descuento de 0 a 100% 10

**************************************************
=================Ticket de compra=================
-------Nombre: Cuaderno....................
-------Precio: $50....................
-------Cantidad: 2....................
-------Descuento: $10....................
--------------------------------------------------
Subtotal: 100
--------------------------------------------------
Descuento: $10
--------------------------------------------------
IVA = 16%: $14.4
--------------------------------------------------
--------------Costo final: $104.4-----------------
--------------------------------------------------
==============GRACIAS POR SU COMPRA===============
**************************************************

## 10. De la receta al código (Fase 3)
<!-- Para cada paso de TU receta, escribe el módulo o la instrucción de C++ que lo implementa. Agrega las filas que necesites. -->

| Paso de la receta | Módulo o instrucción de C++ que lo implementa |
|---|---|
| 1. Mensaje de bienvenida | __std::cout << "Ticket de compra";___ |
| 2.Pedir el nombre del producto____ | __leerCadena()___ |
|_3. Pedir precio, cantidad y descuento____ | __leerDecimal() y leerEntero()___ |
| 4. Calcular subtotal y descuento____ | _calcularSubtotal() y calcularDescuento()____ |
| 5. Mostrar el ticket y el total____ | ___std::cout__ |

**¿Hubo algún paso de mi receta que me costó traducir a C++? ¿Cuál y por qué?**
_____

**Formato del ticket: ¿qué ancho usé en `std::setw` y por qué? ¿Qué pasa si uso un número menor que el largo de la etiqueta más larga?**
__Nada mas seguir el orden__

**¿Convertí el ancho de las líneas del ticket (36) en una constante? ¿Cómo la llamé? Si no, ¿por qué?**
__No utilicé ninguna constante; usé los valores directamente en el código.___

## 11. Experimentos y depuración (Fase 3)

**Experimento A: depuración de `calcularDescuento`**

| Paso de depuración | Lo que hice o encontré |Nombre: po, precio: 100, cantidad: 1, descuento: 20%.
|---|---|
| 1. Reproduce: ¿con qué datos falló? | __El valor de descuento mostraba números extraños.___ |
| 2. Aísla: ¿qué valor intermedio estaba mal? (salidas `[DEBUG]`) | _____ |
| 3. Explica: ¿cuál era la causa? | ___Se usaba subtotal antes de calcularlo.__ |
| 4. Corrige: ¿qué cambiaste? | ___Primero calculé subtotal y después descuento.__ |
| 5. Limpia: ¿comentaste tus salidas `[DEBUG]`? | ___eliminé o comenté las salidas de depuración.__ |

**La prueba con 0 % pasó aunque la función tenía un error. ¿Qué me enseña eso sobre elegir mis casos de prueba?**
____Que debo probar varios casos y no solo uno._

**Experimento B: al cambiar el IVA a 8 %, ¿cuántas líneas tuve que cambiar? ¿Qué mejoraría?**
___Tuve que cambiar 1 línea. Mejoraría usando una constante para el IVA.__

**¿Mi ticket seguía diciendo `IVA (16%)`? ¿Qué hice al respecto?**
__si, actualice el texto para que mostrara el porcentaje correcto.___

**Experimento C (opcional): al cambiar el parámetro dentro de `calcularIVA`, ¿cambió la variable de `main()`? ¿Por qué?**
__No, porque el parámetro se pasa por valor y solo cambia dentro de la funcion.___

## 12. La constante "Le atendio" (Fase 3)

**¿Dónde definí la constante con mi nombre?** (marca una)
- [si] Constante local dentro de `imprimirTicket`
- [ ] Constante a nivel de la librería, en `ticket.h`
- [ ] Función que siempre devuelve la misma cadena

**¿Por qué elegí esa opción?**
__Porque solo se utiliza al imprimir el ticket.___

**¿Qué otras partes del programa podrían necesitar el nombre de quien atiende? (un mensaje de bienvenida, un ticket de devolución...)**
__El mensaje de bienvenida o un ticket de devolucion.___

**Si mañana atiende otra persona, ¿en cuántos lugares tengo que cambiar el nombre?**
_En un lugar nada mas____

**Si el nombre se leyera del teclado o de un archivo, ¿cuánto código tendría que cambiar con mi opción?**
__Muy poco, solo la parte donde se obtiene el nombre.___

## 13. Tabla de pruebas (Fase 4)
<!-- Los datos de entrada de cada caso están en PRACTICA.md, Fase 4. -->

| # | Caso | Esperado (subtotal / descuento / IVA / total) | Obtenido | ¿Pasó? |
|---|---|---|---|---|
| 1 | Sin descuento | 100.00 / 0.00 / 16.00 / 116.00 | __100.00 / 0.00 / 16.00 / 116.00___ | _si____ |
| 2 | Con descuento | 100.00 / 10.00 / 14.40 / 104.40 | __100.00 / 10.00 / 14.40 / 104.40 ___ | _si____ |
| 3 | Descuento de 15 % | 600.00 / 90.00 / 81.60 / 591.60 | ___600.00 / 90.00 / 81.60 / 591.60__ | ___si__ |
| 4 | Precio con centavos | 19.99 / 0.00 / 3.20 / 23.19 | ___19.99 / 0.00 / 3.20 / 23.19__ | _si____ |
| 5 | Descuento total | 90.00 / 90.00 / 0.00 / 0.00 | __90.00 / 90.00 / 0.00 / 0.00___ | __si___ |
| 6 | Precio inválido | vuelve a pedir el precio dos veces; 40.00 / 0.00 / 6.40 / 46.40 | __40.00 / 0.00 / 6.40 / 46.40___ | ___si__ |
| 7 | Cantidad inválida | vuelve a pedir la cantidad dos veces; 20.00 / 0.00 / 3.20 / 23.20 | __20.00 / 0.00 / 3.20 / 23.20___ | __si___ |
| 8 | Descuento inválido | vuelve a pedir el descuento dos veces; 100.00 / 20.00 / 12.80 / 92.80 | _100.00 / 20.00 / 12.80 / 92.80____ | __si___ |
| 9 | Texto en el precio | vuelve a pedir el precio una vez; 100.00 / 0.00 / 16.00 / 116.00 | ___100.00 / 0.00 / 16.00 / 116.00__ | ___si__ |
| 10 | Nombre con espacios | muestra el nombre completo; 25.50 / 0.00 / 4.08 / 29.58 | _25.50 / 0.00 / 4.08 / 29.58____ | __si___ |
| 11 | Nombre vacío | vuelve a pedir el nombre una vez; 12.00 / 0.00 / 1.92 / 13.92 | __12.00 / 0.00 / 1.92 / 13.92___ | __si___ |
| 12 | Caso propio 1: __Descuento 50 %___ | __200.00 / 100.00 / 16.00 / 116.00___ | __200.00 / 100.00 / 16.00 / 116.00___ | _si__ |
| 13 | Caso propio 2: __Cantidad 5___ | __250.00 / 0.00 / 40.00 / 290.00___ | _250.00 / 0.00 / 40.00 / 290.00____ | __si___ |

**En el caso 4 el IVA real es 3.1984. ¿Por qué mi ticket muestra 3.20?**
__Porque el valor se redondea a dos decimales para mostrarlo en el ticket.___

**En el caso 10, ¿el ticket siguió alineado? Si no, ¿qué corregí?**
__Sí, siguió alineado porque el programa acepta nombres con espacios completos.___

## 14. Generalización (Fase 4)

**¿Qué cálculo hacen `calcularDescuento` y `calcularIVA`? ¿Qué cambia entre una y otra?**
__Si, el ticket siguió alineado y no fue necesario corregirlo___

**Receta de `calcularPorcentaje`** (también va en `RECETA.md`):

```text
1. Recibir una cantidad y un porcentaje.
2. Dividir el porcentaje entre 100.
3. Multiplicar la cantidad por el porcentaje.
4. Devolver el resultado.
```

**¿Cómo quedaron el descuento y el IVA después del cambio?**
____Quedaron calculados usando la función calcularPorcentaje._

**¿Volví a correr toda la tabla de pruebas después del cambio? ¿Todo siguió pasando?**
___Si, volvi a ejecutar las pruebas y todas bien.__

**¿Agregué `calcularPorcentaje` a mi tabla de módulos (sección 7)?** Si

**¿En qué otro programa podría reutilizar `calcularPorcentaje`?**
_En un programa para calcular impuestos.___

## 15. Revisión de calidad (Fase 4)

| Principio | Pregunta | ¿Lo cumple? | Evidencia |
|---|---|---|---|
| Correcto | ¿Pasa todas las pruebas de la tabla? | _si____ | __Todos los casos de prueba pasaron.___ |
| Robusto | ¿Resiste datos inválidos sin fallar ni terminar? | __si___ | __Vuelve a pedir los datos cuando son inválidos.___ |
| Legible | ¿Otra persona entiende tu código sin que se lo expliques? | _si____ | __Esta bien estructurado.___ |
| Modular | ¿Cada función hace una sola cosa? | __si___ | _____ |
| Sin números mágicos | ¿Los valores fijos tienen nombre? | ___no__ | _El IVA (1.16) está escrito directamente en el código.____ |
| Fácil de mantener | Si cambia el IVA o quien atiende, ¿cuántas líneas cambias? | _3____ | __Solo habría que modificar 3 líneas.___ |
| Reutilizable | ¿Alguna de tus funciones serviría en otro programa? | _si____ | __calcularSubtotal() y calcularDescuento()___ |

## 16. Reto obligatorio (Fase 4)

**¿Qué reto elegí?** (número y nombre; el 4 no cuenta como obligatorio) ___Calcular el iva __

**¿Por qué lo elegí?**
__Porque me ayudara a calcular el total___

**¿Cómo lo resolví? ¿Qué módulos agregué o cambié?**
__Metiendo el valor del iva en los modulos___

**¿Hice algún otro reto opcional? ¿Cuál?**
_No____

## 17. Bitácora de mejoras (Fase 4)

| # | ¿Qué falló o qué quise mejorar? | ¿Qué cambié? | ¿Funcionó? |
|---|---|---|---|
| 1 | _El descuento mostraba un valor incorrecto.____ | __Corregí el cálculo usando primero el subtotal.___ | __si___ |
| 2 | ____El programa mostraba números extraños en el descuento._ | __Revisé las variables y corregí el orden___ | __Si___ |

## 18. Dudas para el profesor (Fase 3)

| Duda | Lo que ya intenté |
|---|---|
| __Como organizo mejor los modulos ___ | __Separe las funciones___ |

## 19. Reflexión final

**¿Qué aprendí con esta práctica?**
_Aprendi a usar funciones, dividir un programa en módulos____

**Ahora que terminé, ¿qué cambiaría de mi proceso?**
__Hacer una constante con el iva___

**¿Qué fue lo más difícil y cómo lo resolví?**
__Encontrar el error del descuento, revisando las variables___

**¿Qué pregunta me quedó sin responder?**
___¿Cómo puedo organizar mejor los módulos?__

**Comparado con las prácticas anteriores, donde todo estaba en `main()`, ¿dividir el programa en módulos me facilitó o me complicó el trabajo? ¿Por qué?**
_Me facilito el trabajo porque cada función tenía una tarea específica____

**¿Cómo encontré el error de `calcularDescuento`? ¿Lo habría encontrado si solo hubiera probado sin descuento?**
_Lo encontre probando diferentes valores y revisando los resultados del descuento____

## 20. Commits (Fase 5)

**¿Cuántos commits hice durante la práctica?** ___6__

**Si hice menos de 3, ¿por qué?**
___Si para guardar mis cambios__

## 21. Lista de verificación antes de entregar (Fase 5)

- [si ] Llené las secciones 1 a 20 (no quedan `__no___`; escribí `No aplica` donde corresponde)
- [si ] Completé el árbol de análisis descendente y la tabla de módulos
- [ si] Escribí en `RECETA.md` la receta de `main` y la de cada módulo, antes de programar
- [ si] Cada bloque de `main.cpp` tiene su comentario `// Paso N`, de acuerdo con mi receta
- [si ] Corregí el error de `calcularDescuento` y documenté cómo lo encontré
- [ si] Hice los Experimentos A y B y dejé el código correcto al terminar
- [si ] Mi ticket se ve alineado y termina con la línea "Le atendio:", leída de una constante
- [si ] Justifiqué dónde definí la constante con mi nombre
- [si ] Escribí `calcularPorcentaje` y volví a correr todas las pruebas
- [si ] Hice al menos uno de los retos y lo documenté
- [si ] No queda ninguna salida `[DEBUG]` activa
- [si ] Mi programa compila sin advertencias
- [si ] Probé todos los casos de la tabla
- [si ] Revisé los principios de calidad de mi programa
- [ si] No modifiqué `utilerias.h`
- [si ] Tengo al menos 3 commits con mensajes claros (o justifiqué por qué no)
- [si ] Hice `git push` y verifiqué mi fork en GitHub
- [ si] Mi fork se llama `ulsa_ime_1_dp_ticket_compra`, mis módulos están en `include/ticket.h` y mi programa principal en `src/main.cpp`
- [ si] Entregué el enlace de mi fork en Classroom
