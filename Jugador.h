#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
#include <vector>
#include "Videojuego.h"
using namespace std;

class Jugador {
private:
    string nickname;
    int nivelRanking;
    vector<Videojuego*> videojuegosInscritos;

public:

    Jugador(string nickname, int nivelRanking);


    string getNickname() const;
    int getNivelRanking() const;


    void inscribirEnVideojuego(Videojuego* videojuego);
    void mostrarVideojuegos() const;
    float calcularPromedioDificultad() const;
};

#endif
