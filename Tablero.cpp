#include "Tablero.h"
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>

Tablero::~Tablero() {
    limpiarTablero();
}

void Tablero::cargarDesdeArchivo(const std::string& archivo) {
    limpiarTablero();

    std::ifstream file(archivo);
    if (!file.is_open()) {
        throw std::runtime_error("No se pudo abrir el archivo: " + archivo);
    }

    // ---------------------------------------------
    // 1. Intentar leer las dimensiones en la 1ª línea
    //    Formato esperado: filas columnas
    // ---------------------------------------------
    std::string primeraLinea;
    if (!std::getline(file, primeraLinea)) {
        throw std::runtime_error("El archivo está vacío.");
    }

    std::istringstream dims(primeraLinea);
    if (!(dims >> filas >> columnas)) {
        // Si no contiene números, asumimos que la primera línea es parte del tablero
        // Reiniciar lectura y tratamos todo como tablero
        file.clear();
        file.seekg(0);
        filas = columnas = 0;
    }

    std::string linea;
    int filaIdx = 0;
    while (std::getline(file, linea)) {
        if (linea.empty()) continue;          // saltar líneas vacías
        std::istringstream stream(linea);
        std::vector<Ficha*> filaActual;
        char tipoFicha;
        int colIdx = 0;

        while (stream >> tipoFicha) {
            Ficha* nuevaFicha = nullptr;
            switch (tipoFicha) {
                case '1': nuevaFicha = new Camino(filaIdx, colIdx, '1'); break;
                case '0': nuevaFicha = new Abismo(filaIdx, colIdx, '0'); break;
                case 'S': nuevaFicha = new Salida(filaIdx, colIdx, 'S'); break;
                default : nuevaFicha = new Camino(filaIdx, colIdx, tipoFicha); // genérico
            }
            filaActual.push_back(nuevaFicha);
            ++colIdx;
        }

        if (columnas == 0) columnas = colIdx; // calcula columnas si no venían
        tablero.push_back(std::move(filaActual));
        ++filaIdx;
    }

    if (filas == 0) filas = filaIdx;  // calcula filas si no venían
}

Ficha* Tablero::getFicha(int fila, int columna) const {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        return nullptr;
    }
    return tablero[fila][columna];
}

void Tablero::limpiarTablero() {
    for (auto& fila : tablero) {
        for (auto& ficha : fila) delete ficha;
        fila.clear();
    }
    tablero.clear();
    filas = columnas = 0;
}

int Tablero::getSize() const {
    return filas;   // compatibilidad con versiones anteriores
}
