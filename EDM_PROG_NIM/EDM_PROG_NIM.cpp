#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Inicialitza la llavor per a la generació de nombres aleatoris
    srand(time(0));

    // Mostra un missatge de benvinguda al joc Nim
    cout << "Benvingut al joc Nim!" << endl;

    // Mostra informació sobre les muntanyes de pedres
    cout << "Hi ha 3 muntanyes de pedres amb 3, 4 i 5 pedres." << endl;

    // Inicialitza un array que representa la quantitat de pedres a cada muntanya
    int pedres[] = { 3, 4, 5 };

    // Bucle principal del joc
    while (true) {
        // Mostra l'estat actual del joc
        cout << "\nEstat actual del joc: ";
        for (int i = 0; i < 3; ++i) {
            cout << "Muntanya " << i + 1 << ": " << pedres[i] << " pedres ";
        }
        cout << endl;

        // Variables per emmagatzemar la elecció del jugador
        int muntanya, pedres_a_retirar;

        // Demana al jugador que triï una muntanya
        cout << "És el teu torn - Tria una muntanya (1, 2, 3): ";
        cin >> muntanya;

        // Verifica la validesa del moviment del jugador
        if (muntanya < 1 || muntanya > 3 || pedres[muntanya - 1] == 0) {
            cout << "Moviment invàlid! Torna-ho a provar." << endl;
            continue;
        }

        // Demana al jugador que introdueixi la quantitat de pedres a retirar
        cout << "Introdueix les pedres que vols retirar (1-3): ";
        cin >> pedres_a_retirar;

        // Verifica la validesa del nombre de pedres a retirar
        if (pedres_a_retirar < 1 || pedres_a_retirar > 3 || pedres_a_retirar > pedres[muntanya - 1]) {
            cout << "Moviment no vàlid. Torna-ho a provar: " << endl;
            continue;
        }

        // Actualitza la quantitat de pedres a la muntanya seleccionada pel jugador
        pedres[muntanya - 1] -= pedres_a_retirar;

        // Verifica si el jugador ha guanyat
        if (pedres[0] == 0 && pedres[1] == 0 && pedres[2] == 0) {
            cout << "Has guanyat!" << endl;
            break;
        }

        // Genera un moviment aleatori per a la computadora
        int muntanya_comp = rand() % 3 + 1;
        int pedres_a_retirar_comp = rand() % min(3, pedres[muntanya_comp - 1]) + 1;

        // Mostra el moviment de la computadora
        cout << "La computadora retira " << pedres_a_retirar_comp << " pedres de la muntanya " << muntanya_comp << endl;

        // Actualitza la quantitat de pedres a la muntanya seleccionada per la computadora
        pedres[muntanya_comp - 1] -= pedres_a_retirar_comp;

        // Verifica si la computadora ha guanyat
        if (pedres[0] == 0 && pedres[1] == 0 && pedres[2] == 0) {
            cout << "La computadora guanya!" << endl;
            break;
        }
    }

    return 0;
}
