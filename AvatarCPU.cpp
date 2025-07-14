#include "AvatarCPU.h"

AvatarCPU::AvatarCPU() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

void AvatarCPU::mover(char) {
    // 0-Arriba, 1-Abajo, 2-Izquierda, 3-Derecha
    int dir = std::rand() % 4;
    static const char mapa[4] = {'W','S','A','D'};
    Avatar::mover(mapa[dir]);   // reutiliza la lógica del Avatar normal
}