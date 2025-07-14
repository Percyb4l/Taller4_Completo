#include "VistaConsola.h"
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

VistaConsola::VistaConsola(ITablero* tablero, const std::vector<IPersonaje*>& jugadores)
    : tablero(tablero), jugadores(jugadores) {}

void VistaConsola::mostrarJuego() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    int filas = tablero->getFilas();
    int columnas = tablero->getColumnas();

    std::cout << "Tablero:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            bool hayJugador = false;
            for (auto* jugador : jugadores) {
                if (jugador->getPosicionFila() == i && jugador->getPosicionColumna() == j) {
                    std::cout << "P ";
                    hayJugador = true;
                    break;
                }
            }
            if (!hayJugador) {
                std::cout << tablero->getFicha(i, j)->getTipo() << ' ';
            }
        }
        std::cout << '\n';
    }
    std::cout << "Digita tu movimiento (WASD + QEZC para diagonales): ";
}

void VistaConsola::mostrarMensaje(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}

char VistaConsola::getEntradaConsola() {
    char entrada;
    std::cin >> entrada;
    return entrada;
}

int VistaConsola::getFilas() const {
    return tablero->getFilas();
}

int VistaConsola::getColumnas() const {
    return tablero->getColumnas();
}
void VistaConsola::mostrarTablero() const {
    // Puedes delegar a mostrarJuego (aunque esta no es const, así que puedes imprimir una versión básica si prefieres)
    std::cout << "Visualizacion del tablero no implementada en modo const.\n";
}

void VistaConsola::limpiarPantalla() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

