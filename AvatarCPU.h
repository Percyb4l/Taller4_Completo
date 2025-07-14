#ifndef AVATARCPU_H
#define AVATARCPU_H

#include "Avatar.h"
#include <cstdlib>
#include <ctime>

class AvatarCPU : public Avatar {
public:
    AvatarCPU();
    void mover(char direccion) override;  // El char es ignorado
};

#endif

