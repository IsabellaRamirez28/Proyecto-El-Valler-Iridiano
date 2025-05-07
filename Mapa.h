//
// Created by isara on 7/05/2025.
//

#ifndef MAPA_H
#define MAPA_H
#include <vector>
#include "Criatura.h"

using namespace std;


class Mapa {
public:
    Mapa(int x, int y)
        : x(x),
          y(y) {

    }
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    void agregarCriatura(Criatura* criatura) {
        criaturas.push_back(criatura);
    }
    void eliminarCriatura(Criatura* criatura) {
        criaturas.erase(remove(criaturas.begin(), criaturas.end(), criatura), criaturas.end());
    }
    const vector<Criatura*>& getCriaturas() const {
        return criaturas;
    }

private:
    int x, y;
    vector<Criatura*> criaturas;

};



#endif //MAPA_H
