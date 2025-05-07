//
// Created by isara on 4/05/2025.
//

#ifndef CENTELLA_H
#define CENTELLA_H
#include "Criatura.h"


class Centella : public virtual Criatura {
public:
    Centella(const string &nombre, const string &reino, int energia, const pair<int, int> &pos, int poder_de_ataque)
        : Criatura(nombre, reino, energia, pos),
          poderDeAtaque(poder_de_ataque) {
    }

    int getPoderDeAtaque() const {
        return poderDeAtaque;
    }
    void recibirAtaque(const int &dano) override {
        if (energia > 0) {
            energia *= poderDeAtaque;
            energia -= dano;
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
        cout << "Poder de Ataque: " << poderDeAtaque << endl;
    }

    json toJson() const override {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion", posicion},
        {"poder de Ataque", poderDeAtaque}};
    }

private:
    int poderDeAtaque = 2;

};



#endif //CENTELLA_H
