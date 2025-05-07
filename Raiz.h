//
// Created by isara on 4/05/2025.
//

#ifndef RAIZ_H
#define RAIZ_H
#include "Criatura.h"


class Raiz : public Criatura {
public:
    Raiz(const string &nombre, const string &reino, int energia, const pair<int, int> &pos, int poder_de_reproduccion)
        : Criatura(nombre, reino, energia, pos),
          poderDeReproduccion(poder_de_reproduccion) {
    }

    int getPoderDeReproduccion() const {
        return poderDeReproduccion;
    }
    void recibirAtaque(const int &dano) override {
        if (energia > 0) {
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
        cout << "Poder de Reproduccion: " << poderDeReproduccion << endl;
    }
    json toJson() const override {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion", posicion},
        {"poder de reproduccion", poderDeReproduccion}};
    }

private:
    int poderDeReproduccion = 3;

};



#endif //RAIZ_H
