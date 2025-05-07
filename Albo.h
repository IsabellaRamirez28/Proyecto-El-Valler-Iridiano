//
// Created by isara on 4/05/2025.
//

#ifndef ALBO_H
#define ALBO_H
#include "Centella.h"
#include "Metamorfita.h"


class Albo : public Metamorfita, public Centella {
public:
    Albo(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
     int poder_de_ataque, const string &defensas, const string &poder_volador)
    : Criatura(nombre, reino, energia, posicion_x, posicion_y),
      Metamorfita(nombre, reino, energia, posicion_x, posicion_y, defensas),
      Centella(nombre, reino, energia, posicion_x, posicion_y, poder_de_ataque),
      poderVolador(poder_volador) {
    }

    string getPoderVolador () const {
        return poderVolador;
    };

private:
    string poderVolador;

};



#endif //ALBO_H
