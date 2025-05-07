//
// Created by isara on 4/05/2025.
//

#ifndef METAMORFITA_H
#define METAMORFITA_H
#include "Criatura.h"


class Metamorfita : public virtual Criatura{
public:
    Metamorfita(const string &nombre, const string &reino, int energia, const pair<int, int> &pos, int defensas)
        : Criatura(nombre, reino, energia, pos),
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
        {"posicion", posicion},
        {"defensas", defensas}};
    }
    void mostrarCriaturas() const override {
        cout << "Nombre: " << nombre << endl;
        cout << "Reino: " << reino << endl;
        cout << "Energía: " << energia << endl;
        cout << "Defensas: " << defensas << endl;
    }

private:
    int defensas = 5;

};



#endif //METAMORFITA_H
