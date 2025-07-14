#include "LogicaDeMovimiento.h"
#include "AvatarInnovador.h"
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <iostream>

void LogicaDeMovimiento::mover(std::vector<IPersonaje*>& personajes, char direccion) {
    for (auto* personaje : personajes) {
        // Verifica si el personaje es AvatarInnovador
        AvatarInnovador* innovador = dynamic_cast<AvatarInnovador*>(personaje);
        if (innovador != nullptr) {
            // Movimiento aleatorio en diagonal
            const char diagonales[] = {'q', 'e', 'z', 'c'};
            char dir = diagonales[rand() % 4];
            std::cout << "AvatarInnovador se moverá en dirección: " << dir << "\n";
            innovador->mover(dir);
        } else {
            personaje->mover(direccion);  // humano u otro personaje
        }
    }
}
