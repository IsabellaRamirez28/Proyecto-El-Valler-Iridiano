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
                    Criatura* c = criaturas[0];
                    // Identifica el tipo real y muestra la letra correspondiente
                    if (dynamic_cast<Albo*>(c)) {
                        cout << "A ";
                    } else if (dynamic_cast<Centella*>(c) && !dynamic_cast<Albo*>(c)) {
                        cout << "C ";
                    } else if (dynamic_cast<Metamorfita*>(c) && !dynamic_cast<Albo*>(c)) {
                        cout << "M ";
                    } else if (dynamic_cast<Raiz*>(c)) {
                        cout << "R ";
                    } else {
                        cout << "? ";  // Por si acaso
                    }
                } else {
                    if (i < 4) {
                        cout << ". ";
                    } else if (i < 7) {
                        cout << "_ ";
                    } else {
                        cout << "~ ";
                    }
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

    pair<int, int> generarPosicionAleatoria() {
        return {rand() % filas, rand() % columnas};
    }


    void agregarCriaturaRaiz(const string &nombreRa, const string &reinoRa) {
        pair<int, int> pos = generarPosicionAleatoria();
        Criatura* nueva = new Raiz(nombreRa, reinoRa, energia, pos, 5); // 5 = tasaInteres ejemplo
        criaturas.push_back(nueva);
        mapa[pos.first][pos.second].agregarCriatura(nueva);
    }

    void agregarCriaturaCentella(const string &nombreCent, const string &reinoCent) {
        pair<int, int> pos = generarPosicionAleatoria();
        Criatura* nueva = new Centella(nombreCent, reinoCent, energia, pos, 2); // 2 = poderDeAtaque ejemplo
        criaturas.push_back(nueva);
        mapa[pos.first][pos.second].agregarCriatura(nueva);
    }

    void agregarCriaturaMetamorfita(const string &nombreMeta, const string &reinoMeta) {
        pair<int, int> pos = generarPosicionAleatoria();
        Criatura* nueva = new Metamorfita(nombreMeta, reinoMeta, energia, pos, 5); // 5 = defensas ejemplo
        criaturas.push_back(nueva);
        mapa[pos.first][pos.second].agregarCriatura(nueva);
    }

    void agregarCriaturaAlbo(const string &nombreAlb, const string &reinoAlb) {
        pair<int, int> pos = generarPosicionAleatoria();
        Criatura* nueva = new Albo(nombreAlb, reinoAlb, energia, pos, 2, 5, 10); // poderAtaque, defensas, poderVolador
        criaturas.push_back(nueva);
        mapa[pos.first][pos.second].agregarCriatura(nueva);
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
        for (const auto &criatura : criaturas) {
            criatura->mostrarCriaturas();
        }
    }

private:
    string nombreEntorno;
    int filas, columnas;
    vector<Criatura*> criaturas;
    vector<vector<Mapa>> mapa;
    int energia = 100;
};



#endif //ENTORNO_H
