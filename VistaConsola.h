#ifndef VISTACONSOLA_H
#define VISTACONSOLA_H

#include "ITablero.h"
#include "IPersonaje.h"
#include "IVistaJuego.h"
#include <vector>
#include <string>

class VistaConsola : public IVistaJuego {
private:
    ITablero* tablero;
    std::vector<IPersonaje*> jugadores;

public:
    VistaConsola(ITablero* tablero, const std::vector<IPersonaje*>& jugadores);

    // → Implementaciones de IVistaJuego
    void mostrarTablero() const override;
    void limpiarPantalla() const override;
    void mostrarMensaje(const std::string& mensaje) override;
    int  getFilas()    const override;
    int  getColumnas() const override;

    // → Función de ayuda (no forma parte de la interfaz, por eso SIN override)
    void mostrarJuego();
    
    // Entrada de usuario
    char getEntradaConsola();
};

#endif

