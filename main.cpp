#include <iostream>
#include "Entorno.h"

using namespace std;

int main() {
    Entorno entorno("El Valle Iridiano", 10, 10);
    int opcion, opcionAcciones, fuerzaAtaque;
    string energía, nombreCentella, nombreRaiz, nombreMetamorfita, nombreAlbo, atacante, victima;
    string reinoRaiz = "Raiz";
    string reinoCentella = "Chispa";
    string reinoMetamorfita = "Cambio";
    string reinoAlbo = "Chiscambio";

    do {
        cout << "=========MENU========" << endl;
        cout << "1. INICIAR CICLO" << endl;
        cout << "2. SALIR DEL SISTEMA" << endl;
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
                entorno.mostrarCriaturas();

                entorno.mostrarmapa();

                for (int i = 0; i < 5; ++i) {
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
                break;
            }
            default: cout << "OPCION INVALIDA" << endl; break;
        }

    } while (opcion != 2);

    return 0;
}
