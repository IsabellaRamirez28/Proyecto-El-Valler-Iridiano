//
// Created by isara on 4/05/2025.
//

#ifndef ENTORNO_H
#define ENTORNO_H

#include <iostream>
#include <vector>
#include <string>

#include "Albo.h"
#include "Centella.h"
#include "Criatura.h"
#include "Metamorfita.h"
#include "Raiz.h"
using namespace std;

class Entorno {
public:
    Entorno(const string &nombre_entorno)
        : nombreEntorno(nombre_entorno) {
    }
    string getNombreEntorno() {
        return nombreEntorno;
    }
    void agregarCriaturaRaiz(string nombreRa, string reinoRa) {
        criaturas.push_back(new Raiz(nombreRa, reinoRa, energia, tasaInteres));
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

    void mostrarmapa();

    void guardarDatos(const char * str);

    void moverCriaturas();

    void atacaCriatura(string criaAtacante, string criaVictima, int poderAtaque);

private:
    string nombreEntorno;
    vector<Criatura*> criaturas;
    int energia = 100;
    int filas = 10;
    int columnas = 10;
    int posicionCriaturaX;
    int posicionCriaturaY;
};



#endif //ENTORNO_H
