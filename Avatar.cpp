#include "Avatar.h"

Avatar::Avatar() {
    posicionFila = 0;
    posicionColumna = 0;
}

void Avatar::mover(char direccion) {
    int nuevaFila = getPosicionFila();
    int nuevaColumna = getPosicionColumna();

    switch (direccion) {
        case 'W': case 'w': nuevaFila--; break;
        case 'S': case 's': nuevaFila++; break;
        case 'A': case 'a': nuevaColumna--; break;
        case 'D': case 'd': nuevaColumna++; break;
        default: return;
    }
    setPosicionFila(nuevaFila);
    setPosicionColumna(nuevaColumna);
}
