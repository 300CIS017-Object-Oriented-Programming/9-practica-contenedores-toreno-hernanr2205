#include "Videojuego.h"


Videojuego::Videojuego(string codigo, string nombre, string genero, int nivelDificultad) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->genero = genero;
    

    if (nivelDificultad < 1 || nivelDificultad > 5) {
        this->nivelDificultad = 1;
    } else {
        this->nivelDificultad = nivelDificultad;
    }
}


string Videojuego::getCodigo() const { return codigo; }
string Videojuego::getNombre() const { return nombre; }
string Videojuego::getGenero() const { return genero; }
int Videojuego::getNivelDificultad() const { return nivelDificultad; }


void Videojuego::mostrarInfo() const {
    cout << "Codigo: " << codigo << ", Nombre: " << nombre 
         << ", Genero: " << genero << ", Dificultad: " << nivelDificultad << endl;
}