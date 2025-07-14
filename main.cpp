#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Tablero.h"
#include "Camino.h"
#include "Abismo.h"
#include "Salida.h"
#include "Juego.h"
#include "LogicaDeMovimiento.h"
#include "VistaConsola.h"
#include "Avatar.h"
#include "AvatarInnovador.h"

int main() {
    std::srand(std::time(nullptr)); // inicializar aleatorio

    // Crear tablero
    Tablero tablero;
    tablero.cargarDesdeArchivo("dataTablero.txt");

    // Crear avatares
    IPersonaje* avatarHumano = new Avatar(); // humano
    avatarHumano->setPosicionFila(2);
    avatarHumano->setPosicionColumna(2);

    IPersonaje* avatarInnovador = new AvatarInnovador(4, 4); // innovador

    std::vector<IPersonaje*> jugadores;
    jugadores.push_back(avatarHumano);
    jugadores.push_back(avatarInnovador);

    // Lógica
    LogicaDeMovimiento logica;

    // Crear juego
    Juego juego(&tablero, jugadores, avatarHumano, &logica, true);
    VistaConsola vista(&tablero, jugadores);

    do {
        vista.mostrarJuego();
        vista.mostrarMensaje("Digite su movimiento (WASD):");
        char direccion = vista.getEntradaConsola();

        juego.play(direccion);
    } while (!juego.getWin() && juego.getEstado());

    if (juego.getWin())
        vista.mostrarMensaje("Ganaste el juego, el total de puntos es: " + std::to_string(juego.getPuntaje()));
    else
        vista.mostrarMensaje("Perdiste el juego, el total de puntos es: 0");

    return 0;
}
