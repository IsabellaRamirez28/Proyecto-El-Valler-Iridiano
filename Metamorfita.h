//
// Created by isara on 4/05/2025.
//

#ifndef METAMORFITA_H
#define METAMORFITA_H
#include "Criatura.h"


class Metamorfita : public virtual Criatura{
public:
    Metamorfita(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
        const int &defensas)
        : Criatura(nombre, reino, energia, posicion_x, posicion_y),
          defensas(defensas) {
    }
    int getDefensas() const {
        return defensas;
    }
    void recibirAtaque(const int &dano) override {
        if (energia > 0) {
            energia *= defensas;
            energia -= dano;
            if (energia < 0) {
                energia = 0;
            }
            cout << energia << endl;
        }
    }
    json toJson() const override {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion X", posicionX},
        {"posicion Y", posicionY},
        {"defensas", defensas}};
    }

private:
    int defensas = 5;

};



#endif //METAMORFITA_H
