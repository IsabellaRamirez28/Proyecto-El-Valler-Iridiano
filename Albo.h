//
// Created by isara on 4/05/2025.
//

#ifndef ALBO_H
#define ALBO_H
#include "Centella.h"
#include "Metamorfita.h"


class Albo : public Metamorfita, public Centella {
public:
    Albo(const string &nombre, const string &reino, int energia, const pair<int, int> &pos,
     int poder_de_ataque, const int &defensas, const int &poder_volador)
    : Criatura(nombre, reino, energia, pos),
      Metamorfita(nombre, reino, energia, pos, defensas),
      Centella(nombre, reino, energia, pos, poder_de_ataque),
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

    void mostrarCriaturas() const override {
        cout << "Nombre: " << nombre << endl;
        cout << "Reino: " << reino << endl;
        cout << "Energía: " << energia << endl;
        cout << "PoderVolador: " << poderVolador << endl;
    }

    json toJson() const override {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion", posicion},
        {"poder Volador", poderVolador},
        {"defensa", getDefensas()},
        {"poder de ataque", getPoderDeAtaque()}};
    }

private:
    int poderVolador = 100;

};



#endif //ALBO_H
