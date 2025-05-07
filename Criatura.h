//
// Created by isara on 4/05/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H
#include <string>
#include <iostream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Criatura {
public:
    Criatura(const string &nombre, const string &reino, int energia, pair<int, int> pos)
        : nombre(nombre),
          reino(reino),
          energia(energia),
          posicion(pos) {}
    string getNombre() {
        return nombre;
    }
    string getReino() {
        return reino;
    }
    int getEnergia() {
        return energia;
    }
    pair<int, int> getPosicion() const {
        return posicion;
    }
    void setPosicion(pair<int, int> nuevaPos) {
        posicion = nuevaPos;
    }
    virtual void recibirAtaque (const int &dano) = 0;

    int moverse () {

    }
    int recibirEnergia () {

    }
    int mutar () {

    }
    virtual json toJson() const {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion X", posicionX},
        {"posicion Y", posicionY}};
    }

protected:
    string nombre;
    string reino;
    int energia;
    pair<int, int> posicion;

};



#endif //CRIATURA_H
