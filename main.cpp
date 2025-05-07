#include <iostream>
#include "Entorno.h"

using namespace std;

int main() {
    Entorno entorno("El Valle Iridiano ");
    int opcion;
    string reino, nombre, energía;

    do {
        cout << "=========MENU========" << endl;
        cout << "1. INICIAR CICLO" << endl;
        cout << "2. HISTORIAL" << endl;
        cout << "3. CARGAR" << endl;
        cout << "4. SALIR DEL SISTEMA" << endl;
        cout << "ELIGE UNA OPCION: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                cout << "========INICIO DEL JUEGO==========" << endl;

                break;
            }
            case 2: {
                cout << "========HISTORIAL DE JUEGO========" << endl;
                break;
            }
            case 3: {
                cout << "========CARGAR JUEGO========" << endl;
            }
            case 4: {
                cout << "========SALIR DE JUEGO========" << endl;
            }
            default: cout << "OPCION INVALIDA" << endl; break;
        }

    } while (opcion != 4);

    return 0;
}
