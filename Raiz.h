//
// Created by isara on 4/05/2025.
//

#ifndef RAIZ_H
#define RAIZ_H
#include "Criatura.h"


class Raiz : public Criatura {
public:
    Raiz(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
        int poder_de_reproduccion)
        : Criatura(nombre, reino, energia, posicion_x, posicion_y),
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
    json toJson() const override {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion X", posicionX},
        {"posicion Y", posicionY},
        {"poder de reproduccion", poderDeReproduccion}};
    }

private:
    int poderDeReproduccion;

};



#endif //RAIZ_H
