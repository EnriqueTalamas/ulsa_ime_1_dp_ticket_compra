// Práctica: Ticket de compra
// main() solo coordina: pide los datos, llama a los módulos y muestra el ticket.
// Deja el comentario "// Paso N" sobre cada bloque, con la numeración de TU receta.
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o ticket
// Ejecutar:
//   macOS:   ./ticket
//   Windows: .\ticket.exe

// ¿Recuerdas qué hace iostream?
    #include <iostream>
    #include <string>

    #include "utilerias.h"
    #include "ticket.h"

    void imprimirLinea(int largo, char simbolo) {
for (int i = 0; i < largo; i++)
std::cout << simbolo;
}
    int main() {
   
    std::string nombre;
    double precio;
    int cantidad;
    double descuento;
    double subtotal;
    double PorcentajeDescuento;

    

    nombre = leerCadena("Escriba el nombre del producto: ");
    precio = leerDecimal("Escriba el precio en pesos: ");
    cantidad = leerEntero("Escriba la cantidad:");
    PorcentajeDescuento = leerDecimal("Escriba el descuento de 0 a 100% "); std::cout << std::endl;

    subtotal = calcularSubtotal( precio,  cantidad);
    descuento = calcularDescuento(subtotal, PorcentajeDescuento);
    

 imprimirLinea(50, '*'); std::cout << std::endl;

imprimirLinea(17, '='); std::cout <<"Ticket de compra";  imprimirLinea(17, '='); std::cout << std::endl;
std::cout <<"-------Nombre: " << (nombre);imprimirLinea(20, '.'); std::cout << std::endl;
std::cout <<"-------Precio: $" << (precio);imprimirLinea(20, '.'); std::cout << std::endl;
std::cout <<"-------Cantidad: " << (cantidad);imprimirLinea(20, '.'); std::cout << std::endl;
std::cout <<"-------Descuento: $" << (descuento);imprimirLinea(20, '.'); std::cout << std::endl;

imprimirLinea(50, '-'); std::cout << std::endl;
std::cout <<"Subtotal: " << (subtotal); std::cout << std::endl;

imprimirLinea(50, '-'); std::cout << std::endl;

std::cout <<"Descuento: $" << (descuento); std::cout << std::endl;
imprimirLinea(50, '-'); std::cout << std::endl;

std::cout <<"IVA = 16%: $" <<((subtotal-descuento)*.16); std::cout << std::endl;
imprimirLinea(50, '-'); std::cout << std::endl;

std::cout <<"--------------Costo final: $" << ((subtotal-descuento)*1.16); imprimirLinea(18, '-'); std::cout << std::endl;
imprimirLinea(50, '-'); std::cout << std::endl;

imprimirLinea(14, '='); std::cout <<"GRACIAS POR SU COMPRA" ; imprimirLinea(15, '='); std::cout << std::endl;

imprimirLinea(50, '*'); std::cout << std::endl;

    return 0;
}
