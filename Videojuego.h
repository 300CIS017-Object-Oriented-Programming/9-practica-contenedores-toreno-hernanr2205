#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
using namespace std;

class Videojuego {
  private:
    string codigo;
    string nombre;
    string genero;
    int nivelDificultad;

   public:
     Videojuego(string codigo, string nombre, string genero, int nivelDificultad);

    string getCodigo() const;
    string getNombre() const;
    string getGenero() const;
    int getNivelDificultad() const;


    void mostrarInfo() const;
};

#endif



};



#endif //VIDEOJUEGO_H
