#ifndef TORNEO_H
#define TORNEO_H

#include <map>
#include <string>
#include "Videojuego.h"
#include "Jugador.h"
using namespace std;

class Torneo {
private:
    map<string, Videojuego*> videojuegosDisponibles; // Catálogo global de videojuegos
    map<string, Jugador*> jugadoresRegistrados; // Jugadores registrados en el torneo

public:
    Torneo();

    // Métodos para registrar videojuegos y jugadores
    void registrarVideojuego(string codigo, string nombre, string genero, int nivelDificultad);
    void registrarJugador(string nickname, int nivelRanking);

    // Inscribir un jugador en un videojuego
    bool inscribirJugadorEnVideojuego(string nickname, string codigoJuego);

    // Consultar videojuegos de un jugador
    void mostrarVideojuegosJugador(string nickname) const;

    // Calcular promedio de dificultad de videojuegos inscritos
    void mostrarPromedioDificultad(string nickname) const;

    // Métodos de inicialización
    void inicializarVideojuegos();
    void inicializarJugadores();

    // Validaciones
    bool validarExistenciaJugador(string nickname) const;
    bool validarExistenciaVideojuego(string codigoJuego) const;
    bool validarInscripcionUnica(string nickname, string codigoJuego) const;
};

#endif
