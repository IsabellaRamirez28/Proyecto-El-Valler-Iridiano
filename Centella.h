//
// Created by isara on 4/05/2025.
//

#ifndef CENTELLA_H
#define CENTELLA_H
#include "Criatura.h"


class Centella : public virtual Criatura {
public:
    Centella(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
        int poder_de_ataque)
        : Criatura(nombre, reino, energia, posicion_x, posicion_y),
          poderDeAtaque(poder_de_ataque) {
    }
    int getPoderDeAtaque() const {
        return poderDeAtaque;
    }

private:
    int poderDeAtaque;

};



#endif //CENTELLA_H
