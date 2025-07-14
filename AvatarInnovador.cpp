#include "AvatarInnovador.h"
#include <iostream>

AvatarInnovador::AvatarInnovador(int f, int c) : fila(f), columna(c) {}

int AvatarInnovador::getPosicionFila() const    { return fila; }
int AvatarInnovador::getPosicionColumna() const { return columna; }
void AvatarInnovador::setPosicionFila(int f)    { fila = f; }
void AvatarInnovador::setPosicionColumna(int c) { columna = c; }

void AvatarInnovador::mover(char direccion) {
    // Teclas diagonales: q(↖) e(↗) z(↙) c(↘)
    std::cout << "AvatarInnovador se puede mover en diagonales (Q, E, Z, C)\n";
    switch (direccion) {
        case 'q': case 'Q': fila--; columna--; break; // ↖
        case 'e': case 'E': fila--; columna++; break; // ↗
        case 'z': case 'Z': fila++; columna--; break; // ↙
        case 'c': case 'C': fila++; columna++; break; // ↘
        default: break;                               // ignora otras teclas
    }
}

