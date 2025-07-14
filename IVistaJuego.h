#ifndef IVISTAJUEGO_H
#define IVISTAJUEGO_H

#include <string>

class IVistaJuego {
public:
    virtual ~IVistaJuego() = default;

    // Métodos obligatorios para cualquier vista:
    virtual void mostrarTablero() const = 0;
    virtual void limpiarPantalla() const = 0;
    virtual void mostrarMensaje(const std::string& mensaje) = 0;

    // Información auxiliar (filas/columnas)
    virtual int getFilas()    const = 0;
    virtual int getColumnas() const = 0;
};

#endif


