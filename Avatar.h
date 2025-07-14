// Avatar.h
#ifndef AVATAR_H
#define AVATAR_H

#include "Personaje.h"

class Avatar : public Personaje {
public:
    Avatar();
    virtual void mover(char direccion) override;
};

#endif // AVATAR_H
