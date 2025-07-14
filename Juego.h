#ifndef JUEGO_H
#define JUEGO_H

#include "ITablero.h"
#include "IPersonaje.h"
#include "LogicaDeMovimiento.h"
#include <vector>

class Juego {
private:
    ITablero* tablero;
    std::vector<IPersonaje*> jugadores;
    IPersonaje* jugadorHumano;
    LogicaDeMovimiento* logica;
    bool estado;
    bool win;
    int puntaje;

public:
    Juego(ITablero* t, std::vector<IPersonaje*> jug, IPersonaje* jugadorHumano, LogicaDeMovimiento* l, bool e);
    void mover();
    void play(char direccion);
    bool getEstado() const;
    bool getWin() const;
    int getPuntaje() const;
};

#endif
