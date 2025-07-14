#include "Juego.h"

Juego::Juego(ITablero* t, std::vector<IPersonaje*> jug, IPersonaje* jugadorHumano, LogicaDeMovimiento* l, bool e)
    : tablero(t), jugadores(std::move(jug)), jugadorHumano(jugadorHumano), logica(l), estado(e), win(false), puntaje(0) {}

void Juego::mover() {
    for (auto* jugador : jugadores) {
        int fila = jugador->getPosicionFila();
        int col = jugador->getPosicionColumna();
        auto* ficha = tablero->getFicha(fila, col);
        if (ficha->getTipo() == '0') {
            estado = false;
            break;
        }
    }
}

void Juego::play(char direccion) {
    if (!estado) return;

    logica->mover(jugadores, direccion);

    for (auto* jugador : jugadores) {
        int fila = jugador->getPosicionFila();
        int col = jugador->getPosicionColumna();
        char tipo = tablero->getFicha(fila, col)->getTipo();
        if (tipo == '0') {
            estado = false;
        }
        if (tipo == 'S') {
            win = true;
            puntaje = 100;
        }
    }
}

bool Juego::getEstado() const {
    return estado;
}

bool Juego::getWin() const {
    return win;
}

int Juego::getPuntaje() const {
    return puntaje;
}
