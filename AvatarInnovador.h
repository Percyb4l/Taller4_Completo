#ifndef AVATARINNOVADOR_H
#define AVATARINNOVADOR_H

#include "IPersonaje.h"

class AvatarInnovador : public IPersonaje {
private:
    int fila;
    int columna;

public:
    AvatarInnovador(int f = 0, int c = 0);      // posición inicial
    void mover(char direccion) override;        // diagonal
    int  getPosicionFila()   const override;
    int  getPosicionColumna()const override;
    void setPosicionFila(int f) override;
    void setPosicionColumna(int c) override;
};

#endif
