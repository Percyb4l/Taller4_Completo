#ifndef TABLERO_H
#define TABLERO_H

#include "ITablero.h"
#include "Ficha.h"
#include <vector>
#include <string>

class Tablero : public ITablero {
private:
    int filas   = 0;
    int columnas = 0;
    std::vector<std::vector<Ficha*>> tablero;

public:
    ~Tablero() override;
    void cargarDesdeArchivo(const std::string& archivo) override;
    Ficha* getFicha(int fila, int columna) const override;

    int getFilas()    const override { return filas; }
    int getColumnas() const override { return columnas; }

    // Método adicional (opcional)
    int getSize() const;   // devuelve filas (para compatibilidad vieja)

private:
    void limpiarTablero();
};

#endif

