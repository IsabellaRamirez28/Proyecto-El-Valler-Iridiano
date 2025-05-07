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
     int poder_de_ataque, const int &defensas, const int &poder_volador)
    : Criatura(nombre, reino, energia, posicion_x, posicion_y),
      Metamorfita(nombre, reino, energia, posicion_x, posicion_y, defensas),
      Centella(nombre, reino, energia, posicion_x, posicion_y, poder_de_ataque),
      poderVolador(poder_volador) {
    }

    int getPoderVolador () const {
        return poderVolador;
    }
    void recibirAtaque(const int &dano) override {
        if (energia > 0) {
            energia -= dano;
            energia += poderVolador;
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
        {"poder Volador", poderVolador}};
    }

private:
    int poderVolador = 100;

};



#endif //ALBO_H
