//
// Created by isara on 4/05/2025.
//

#ifndef METAMORFITA_H
#define METAMORFITA_H
#include "Criatura.h"


class Metamorfita : public virtual Criatura{
public:
    Metamorfita(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
        const string &defensas)
        : Criatura(nombre, reino, energia, posicion_x, posicion_y),
          defensas(defensas) {
    }
    string getDefensas() const {
        return defensas;
    }

private:
    string defensas;

};



#endif //METAMORFITA_H
