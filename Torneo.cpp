#include "Torneo.h"
#include <iostream>
#include <limits>

Torneo::Torneo() {}

void Torneo::registrarVideojuego(string codigo, string nombre, string genero, int nivelDificultad) {
    if (videojuegosDisponibles.find(codigo) != videojuegosDisponibles.end()) {
        cout << "Error: El videojuego con ese código ya está registrado." << endl;
    } else {
        Videojuego* nuevoJuego = new Videojuego(codigo, nombre, genero, nivelDificultad);
        videojuegosDisponibles[codigo] = nuevoJuego;
        cout << "Videojuego registrado exitosamente." << endl;
    }
}

void Torneo::registrarJugador(string nickname, int nivelRanking) {
    if (jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end()) {
        cout << "Error: El jugador con ese nickname ya está registrado." << endl;
    } else {
        Jugador* nuevoJugador = new Jugador(nickname, nivelRanking);
        jugadoresRegistrados[nickname] = nuevoJugador;
        cout << "Jugador registrado exitosamente." << endl;
    }
}

bool Torneo::inscribirJugadorEnVideojuego(string nickname, string codigoJuego) {
    // Verificamos que el jugador exista
    if (!validarExistenciaJugador(nickname)) {
        cout << "Error: El jugador no está registrado." << endl;
        return false;
    }

    // Verificamos que el videojuego exista
    if (!validarExistenciaVideojuego(codigoJuego)) {
        cout << "Error: El videojuego no está disponible." << endl;
        return false;
    }

    // Verificamos que el jugador no esté inscrito ya
    if (!validarInscripcionUnica(nickname, codigoJuego)) {
        cout << "Error: El jugador ya está inscrito en este videojuego." << endl;
        return false;
    }

    // Inscribir al jugador en el videojuego
    Jugador* jugador = jugadoresRegistrados[nickname];
    Videojuego* videojuego = videojuegosDisponibles[codigoJuego];

    if (jugador->inscribirVideojuego(videojuego)) {
        cout << "Jugador inscrito exitosamente en el videojuego." << endl;
        return true;  // Inscripción exitosa
    }
    return false;
}

void Torneo::mostrarVideojuegosJugador(string nickname) const {
    auto it = jugadoresRegistrados.find(nickname);
    if (it == jugadoresRegistrados.end()) {
        cout << "Error: El jugador no está registrado." << endl;
    } else {
        it->second->mostrarVideojuegos();
    }
}

void Torneo::mostrarPromedioDificultad(string nickname) const {
    auto it = jugadoresRegistrados.find(nickname);
    if (it == jugadoresRegistrados.end()) {
        cout << "Error: El jugador no está registrado." << endl;
    } else {
        float promedio = it->second->calcularPromedioDificultad();
        if (promedio == 0) {
            cout << "El jugador no está inscrito en ningún videojuego." << endl;
        } else {
            cout << "Promedio de dificultad de los videojuegos de " << nickname << ": " << promedio << endl;
        }
    }
}

void Torneo::inicializarVideojuegos() {
    registrarVideojuego("FPS001", "Battle Royale", "Battle Royale", 4);
    registrarVideojuego("MOBA001", "League of Legends", "MOBA", 3);
    registrarVideojuego("FIGHT001", "Street Fighter", "Fighting", 5);
}

void Torneo::inicializarJugadores() {
    registrarJugador("player1", 50);
    registrarJugador("player2", 70);
}

bool Torneo::validarExistenciaJugador(string nickname) const {
    return jugadoresRegistrados.find(nickname) != jugadoresRegistrados.end();
}

bool Torneo::validarExistenciaVideojuego(string codigoJuego) const {
    return videojuegosDisponibles.find(codigoJuego) != videojuegosDisponibles.end();
}

bool Torneo::validarInscripcionUnica(string nickname, string codigoJuego) const {
    auto jugador = jugadoresRegistrados.at(nickname);
    const auto& juegos = jugador->getVideojuegosInscritos();
    for (auto& juego : juegos) {
        if (juego->getCodigo() == codigoJuego) {
            return false;  // Ya está inscrito en este videojuego
        }
    }
    return true;
}
