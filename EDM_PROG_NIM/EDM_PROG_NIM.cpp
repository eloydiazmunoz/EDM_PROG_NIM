#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    cout << "Benvingut al joc Nim!" << endl;
    cout << "Hi ha 3 muntanyes de pedres amb 3, 4 i 5 pedres ." << endl;

    int pedres[] = { 3, 4, 5 };

    while (true) {
        cout << "\nEstat actual del joc: ";
        for (int i = 0; i < 3; ++i) {
            cout << "Muntanya " << i + 1 << ": " << pedres[i] << " pedres ";
        }
        cout << endl;

        int muntanya, pedres_a_retirar;
        cout << "Es el teu torn - Tria una muntanya (1, 2, 3): ";
        cin >> muntanya;

        if (muntanya < 1 || muntanya > 3 || pedres[muntanya - 1] == 0) {
            cout << "Moviment invàlid! Torna-ho a provar." << endl;
            continue;
        }

        cout << "Introdueix pedres vols retirar (1-3): ";
        cin >> pedres_a_retirar;

        if (pedres_a_retirar < 1 || pedres_a_retirar > 3 || pedres_a_retirar > pedres[muntanya - 1]) {
            cout << "Moviment  no valid. Torna-ho a provar: " << endl;
            continue;
        }

        pedres[muntanya - 1] -= pedres_a_retirar;

        if (pedres[0] == 0 && pedres[1] == 0 && pedres[2] == 0) {
            cout << "Has guanyat!" << endl;
            break;
        }

        int muntanya_comp = rand() % 3 + 1;
        int pedres_a_retirar_comp = rand() % min(3, pedres[muntanya_comp - 1]) + 1;

        cout << "La computadora retira " << pedres_a_retirar_comp << " pedres de la muntanya " << muntanya_comp << endl;

        pedres[muntanya_comp - 1] -= pedres_a_retirar_comp;

        if (pedres[0] == 0 && pedres[1] == 0 && pedres[2] == 0) {
            cout << "La computadora guanya!" << endl;
            break;
        }
    }

    return 0;
}