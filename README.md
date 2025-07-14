# Taller4_Completo
Taller #4 para la materia de POO Resuelto

## Descripción del proyecto

Este proyecto es un juego de consola desarrollado en C++ como parte del Taller 4 del curso de Programación Orientada a Objetos. El juego consiste en mover un avatar por un tablero, evitando abismos (`0`) y tratando de llegar a la salida (`S`). Se aplican conceptos de **herencia**, **polimorfismo**, **interfaces** y **arquitectura modular**.

## Innovación implementada

Se desarrolló una versión mejorada del avatar, denominada `AvatarInnovador`, que sobrescribe el método `mover()` para permitir desplazamientos en **diagonal**, además de los movimientos tradicionales. Esto se logró mediante el uso de **polimorfismo** y permite una experiencia de juego más estratégica y fluida.

Movimientos disponibles:
- **WASD**: Movimiento clásico (arriba, izquierda, abajo, derecha).
- **QEZC**: Movimiento diagonal (↖ ↗ ↙ ↘).

## Estructura del proyecto

- `main.cpp` – Archivo principal.
- `Juego.*` – Control de la lógica general del juego.
- `Avatar.*`, `AvatarInnovador.*` – Clases de personajes.
- `Ficha.*`, `Camino.*`, `Abismo.*`, `Salida.*` – Tipos de casillas del tablero.
- `VistaConsola.*` – Representación gráfica del juego en consola.
- `Tablero.*` – Clase para cargar y gestionar el tablero desde un archivo.
