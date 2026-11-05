# Receta: Ticket de compra

<!-- Escribe aquí tus recetas en pseudocódigo, ANTES de programar.
     Primero la receta del programa principal (main) y después una receta corta para cada módulo que vas a escribir tú.
     El primer paso de main es solo un ejemplo del formato; el resto es tuyo.
     Si las corriges después de probarlas a mano, deja aquí la versión final. -->

## Receta del programa principal (`main`)

1. Mostrar el título del ticket.
2. Pedir el nombre del producto.
3. Pedir el precio.
4. Pedir la cantidad.
5. Pedir el porcentaje de descuento.
6. Calcular el subtotal.
7. Calcular el descuento.
8. Calcular el total con IVA.
9. Mostrar el ticket de compra.
10. Terminar el programa.

## Recetas de los módulos

### `calcularIVA`

MODULO calcularIVA(subtotal)

1. Multiplicar el subtotal por 0.16.
2. Devolver el IVA.

FIN MODULO
```

### `imprimirTicket`

1. Mostrar el nombre del producto.
2. Mostrar el precio.
3. Mostrar la cantidad.
4. Mostrar el descuento.
5. Mostrar el subtotal.
6. Mostrar el total.
7. Mostrar fin del ticket.
FIN MODULO
```

### `calcularPorcentaje` (Fase 4)

1. Dividir el porcentaje entre 100.
2. Multiplicar la cantidad por el porcentaje.
3. Devolver el resultado.

FIN MODULO
```

### Otros módulos que agregues (por ejemplo, para tu reto)

MODULO calcularDescuento(subtotal, porcentaje)

1. Calcular el porcentaje del subtotal.
2. Devolver el descuento.

FIN MODULO
