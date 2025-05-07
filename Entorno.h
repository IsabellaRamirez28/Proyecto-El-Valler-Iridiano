//
// Created by isara on 4/05/2025.
//

#ifndef ENTORNO_H
#define ENTORNO_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Mapa.h"
#include "Albo.h"
#include "Centella.h"
#include "Criatura.h"
#include "Metamorfita.h"
#include "Raiz.h"
using namespace std;

class Entorno {
public:
    Entorno(const string &nombre_entorno, int filas, int columnas)
        : nombreEntorno(nombre_entorno),
          filas(filas),
          columnas(columnas) {
        mapa.resize(filas, vector<Mapa>(columnas, Mapa(0, 0)));
        for (int i = 0; i < filas; ++i)
            for (int j = 0; j < columnas; ++j)
                mapa[i][j] = Mapa(i, j);

        srand(time(0));
    }

    string getNombreEntorno() {
        return nombreEntorno;
    }
    void mostrarmapa() const {
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                const vector<Criatura*>& criaturas = mapa[i][j].getCriaturas();
                if (!criaturas.empty()) {
                    cout << criaturas[0]->getNombre()[0] << " ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
    }
    void moverCriaturas() {
        for (Criatura* criatura : criaturas) {
            pair<int, int> pos = criatura->getPosicion();
            int x = pos.first;
            int y = pos.second;

            int dx = rand() % 3 - 1;
            int dy = rand() % 3 - 1;
            int nuevaX = max(0, min(filas - 1, x + dx));
            int nuevaY = max(0, min(columnas - 1, y + dy));

            mapa[x][y].eliminarCriatura(criatura);
            mapa[nuevaX][nuevaY].agregarCriatura(criatura);
            criatura->setPosicion({nuevaX, nuevaY});
        }
    }

    void agregarCriaturaRaiz(string nombreRa, string reinoRa) {
        criaturas.push_back(new Raiz(nombreRa, reinoRa, energia, tasaInteres, ));
    }

    void agregarCriaturaCentella(string nombreCent, string reinoCent) {
        criaturas.push_back(new Centella(nombreCent, reinoCent, energia, tasaInteres));
    }

    void agregarCriaturaMetamorfita(string nombreMeta, string reinoMeta) {
        criaturas.push_back(new Metamorfita(nombreMeta, reinoMeta, energia, tasaInteres));
    }

    void agregarCriaturaAlbo(string nombreAlb, string reinoAlb) {
        criaturas.push_back(new Albo(nombreAlb, reinoAlb, energia, tasaInteres));
    }

    void guardarDatos(const string& archivo) {
        json j;
        j["Nombre"] = nombreEntorno;
        for (const auto &criatura : criaturas) {
            j["Criaturas"].push_back(criatura->toJson());
        }
        ofstream file( archivo );
        if (!file) return;
        file << j.dump(4);
        file.close();
    }

    void atacaCriatura(string criaAtacante, string criaVictima, int poderAtaque) {
        for (Criatura *criaturita : criaturas) {
            if (criaturita -> getNombre() == criaVictima) {
                criaturita -> recibirAtaque(poderAtaque);
            }
        }
    }

    void mostrarCriaturas() {

    }

private:
    string nombreEntorno;
    int filas, columnas;
    vector<Criatura*> criaturas;
    vector<vector<Mapa>> mapa;
    int energia = 100;
};



#endif //ENTORNO_H
