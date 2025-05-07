//
// Created by isara on 4/05/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H
#include <string>
#include <iostream>
#include "json.hpp"

using namespace std;

class Criatura {
public:
    Criatura(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y)
        : nombre(nombre),
          reino(reino),
          energia(energia),
          posicionX(posicion_x),
          posicionY(posicion_y) {
    }
    string getNombre() {
        return nombre;
    }
    int getEnergia() {
        return energia;
    }
    pair<int, int> getPosicion() {
        return make_pair(posicionX, posicionY);
    }
    int recibirAtaque () {

    }
    int moverse () {

    }
    int recibirEnergia () {

    }
    int mutar () {

    }

private:
    string nombre;
    string reino;
    int energia;
    int posicionX;
    int posicionY;

};



#endif //CRIATURA_H
