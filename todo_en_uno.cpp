

// === Comienzo de Albo.cpp ===

//
// Created by isara on 4/05/2025.
//

#include "Albo.h"

// === Fin de Albo.cpp ===


// === Comienzo de Centella.cpp ===

//
// Created by isara on 4/05/2025.
//

#include "Centella.h"

// === Fin de Centella.cpp ===


// === Comienzo de Criatura.cpp ===

//
// Created by isara on 4/05/2025.
//

#include "Criatura.h"

// === Fin de Criatura.cpp ===


// === Comienzo de Entorno.cpp ===

//
// Created by isara on 4/05/2025.
//

#include "Entorno.h"

// === Fin de Entorno.cpp ===


// === Comienzo de Mapa.cpp ===

//
// Created by isara on 7/05/2025.
//

#include "Mapa.h"

// === Fin de Mapa.cpp ===


// === Comienzo de Metamorfita.cpp ===

//
// Created by isara on 4/05/2025.
//

#include "Metamorfita.h"

// === Fin de Metamorfita.cpp ===


// === Comienzo de Raiz.cpp ===

//
// Created by isara on 4/05/2025.
//

#include "Raiz.h"

// === Fin de Raiz.cpp ===


// === Comienzo de main.cpp ===

#include <iostream>
#include "Entorno.h"

using namespace std;

int main() {
    Entorno entorno("El Valle Iridiano ");
    int opcion, opcionAcciones, fuerzaAtaque;
    string energía, nombreCentella, nombreRaiz, nombreMetamorfita, nombreAlbo, atacante, victima;
    string reinoRaiz = "Raiz";
    string reinoCentella = "Chispa";
    string reinoMetamorfita = "Cambio";
    string reinoAlbo = "Chiscambio";

    do {
        cout << "=========MENU========" << endl;
        cout << "1. INICIAR CICLO" << endl;
        cout << "2. CARGAR" << endl;
        cout << "3. SALIR DEL SISTEMA" << endl;
        cout << "ELIGE UNA OPCION: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                cout << "========INICIO DEL JUEGO==========" << endl;
                cout << "1. Elige los nombres de rus criaturas: " << endl;
                cout << "Raiz :";
                cin >> nombreRaiz;
                cout << "Centella: ";
                cin >> nombreCentella;
                cout << "Metamorfita: ";
                cin >> nombreMetamorfita;
                cout << "Albo: ";
                cin >> nombreAlbo;

                entorno.agregarCriaturaRaiz(nombreRaiz, reinoRaiz);
                entorno.agregarCriaturaCentella(nombreCentella, reinoCentella);
                entorno.agregarCriaturaMetamorfita(nombreMetamorfita, reinoMetamorfita);
                entorno.agregarCriaturaAlbo(nombreAlbo, reinoAlbo);

                entorno.mostrarmapa();

                for (int i = 0; i < 15; ++i) {
                    cout << "==============ESCOGE LA OPCION QUE DESEES==============" << endl;
                    cout << "========= CICLO #" << (i + 1) << " =========" << endl;
                    cout << "1. Mover Criaturas" << endl;
                    cout << "2. Ataca" << endl;
                    cout << "OPCION: ";
                    cin >> opcionAcciones;
                    if (opcionAcciones == 1) {
                        entorno.moverCriaturas();
                        entorno.mostrarmapa();
                    } else if (opcionAcciones == 2) {
                        cout << "INGRESA EL ATACANTE, VICTIMA Y FUERZA DE ATAQUE < 100: ";
                        cin >> atacante >> victima >> fuerzaAtaque;
                        entorno.atacaCriatura(atacante, victima, fuerzaAtaque);
                        entorno.mostrarCriaturas();
                    }
                }
                break;
            }
            case 2: {
                cout << "========SALIR DEL JUEGO========" << endl;
                entorno.guardarDatos("../valleIridiano.json");
                cout << "DATOS GUARDADOS" << endl;
            }
            default: cout << "OPCION INVALIDA" << endl; break;
        }

    } while (opcion != 2);

    return 0;
}

// === Fin de main.cpp ===


// === Comienzo de todo_en_uno.cpp ===


// === Fin de todo_en_uno.cpp ===


// === Comienzo de Albo.h ===

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

// === Fin de Albo.h ===


// === Comienzo de Centella.h ===

//
// Created by isara on 4/05/2025.
//

#ifndef CENTELLA_H
#define CENTELLA_H
#include "Criatura.h"


class Centella : public virtual Criatura {
public:
    Centella(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
        int poder_de_ataque)
        : Criatura(nombre, reino, energia, posicion_x, posicion_y),
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
    json toJson() const override {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion X", posicionX},
        {"posicion Y", posicionY},
        {"poder de Ataque", poderDeAtaque}};
    }

private:
    int poderDeAtaque = 2;

};



#endif //CENTELLA_H

// === Fin de Centella.h ===


// === Comienzo de Criatura.h ===

//
// Created by isara on 4/05/2025.
//

#ifndef CRIATURA_H
#define CRIATURA_H
#include <string>
#include <iostream>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class Criatura {
public:
    Criatura(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y)
        : nombre(nombre),
          reino(reino),
          energia(energia),
          posicionX(posicion_x),
          posicionY(posicion_y) {
    }
    string getNombre() {
        return nombre;
    }
    string getReino() {
        return reino;
    }
    int getEnergia() {
        return energia;
    }
    pair<int, int> getPosicion() {
        return make_pair(posicionX, posicionY);
    }
    virtual void recibirAtaque (const int &dano) = 0;

    int moverse () {

    }
    int recibirEnergia () {

    }
    int mutar () {

    }
    virtual json toJson() const {
        return json{{"nombre", nombre},
        {"reino", reino},
        {"energía", energia},
        {"posicion X", posicionX},
        {"posicion Y", posicionY}};
    }

protected:
    string nombre;
    string reino;
    int energia;
    int posicionX;
    int posicionY;

};



#endif //CRIATURA_H

// === Fin de Criatura.h ===


// === Comienzo de Entorno.h ===

//
// Created by isara on 4/05/2025.
//

#ifndef ENTORNO_H
#define ENTORNO_H

#include <iostream>
#include <fstream>
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

    void mostrarmapa();

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

    void moverCriaturas();

    void atacaCriatura(string criaAtacante, string criaVictima, int poderAtaque) {
        for (Criatura *criaturita : criaturas) {
            if (criaturita -> getNombre() == criaVictima) {
                criaturita -> recibirAtaque(poderAtaque);
            }
        }
    }

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

// === Fin de Entorno.h ===


// === Comienzo de Mapa.h ===

//
// Created by isara on 7/05/2025.
//

#ifndef MAPA_H
#define MAPA_H



class Mapa {
private:
    int filas;
    int columnas;

};



#endif //MAPA_H

// === Fin de Mapa.h ===


// === Comienzo de Metamorfita.h ===

//
// Created by isara on 4/05/2025.
//

#ifndef METAMORFITA_H
#define METAMORFITA_H
#include "Criatura.h"


class Metamorfita : public virtual Criatura{
public:
    Metamorfita(const string &nombre, const string &reino, int energia, int posicion_x, int posicion_y,
        const int &defensas)
        : Criatura(nombre, reino, energia, posicion_x, posicion_y),
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
        {"posicion X", posicionX},
        {"posicion Y", posicionY},
        {"defensas", defensas}};
    }

private:
    int defensas = 5;

};



#endif //METAMORFITA_H

// === Fin de Metamorfita.h ===


// === Comienzo de Raiz.h ===

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

// === Fin de Raiz.h ===

