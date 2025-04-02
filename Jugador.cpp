#include "Jugador.h"
#include <iostream>
#include <numeric>

Jugador::Jugador(string nickname, int nivelRanking)
    : nickname(nickname), nivelRanking(nivelRanking) {}

string Jugador::getNickname() const {
    return nickname;
}

int Jugador::getNivelRanking() const {
    return nivelRanking;
}

const vector<Videojuego*>& Jugador::getVideojuegosInscritos() const {
    return videojuegosInscritos;
}

bool Jugador::inscribirVideojuego(Videojuego* videojuego) {
    // Verificamos si el jugador ya está inscrito en el videojuego
    for (auto juego : videojuegosInscritos) {
        if (juego->getCodigo() == videojuego->getCodigo()) {
            return false;  // El jugador ya está inscrito
        }
    }
    videojuegosInscritos.push_back(videojuego);
    return true;
}

void Jugador::mostrarVideojuegos() const {
    if (videojuegosInscritos.empty()) {
        cout << nickname << " no está inscrito en ningún videojuego." << endl;
    } else {
        cout << "Videojuegos de " << nickname << ":" << endl;
        for (auto videojuego : videojuegosInscritos) {
            videojuego->mostrarInfo();
        }
    }
}

float Jugador::calcularPromedioDificultad() const {
    if (videojuegosInscritos.empty()) {
        return 0;  // Si no está inscrito en ningún videojuego, no hay promedio
    }

    float totalDificultad = 0;
    for (auto videojuego : videojuegosInscritos) {
        totalDificultad += videojuego->getNivelDificultad();
    }
    return totalDificultad / videojuegosInscritos.size();
}
