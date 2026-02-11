#include <iostream>
using namespace std;
#include <vector>


int controllaVincita(vector<int>estrazione, vector<int>giocata, int nde, int ndg) {
    int i, j, vittoria, numero;

    vittoria = 0;
    i = 0;
    while (i <= ndg - 1) {
        numero = giocata[i];
        if (cercaNumero(estrazione, nde, numero)) {
            vittoria = vittoria + 1;
        }
        i = i + 1;
    }
    string c[5];

    j = 0;
    c[0] = "1 numero";
    c[1] = "2 numeri";
    c[2] = "3 numeri";
    c[3] = "4 numeri";
    c[4] = " 5 numeri";
    while (j - 1 != vittoria) {
        if (j == vittoria) {
            cout << c[j - 1] << endl;
        }
        j = j + 1;
    }
    
    return vittoria;
}

void estrazioneNumeri(int n, vector<int>estrazione) {
    int i;

    i = 0;
    while (i < n) {
        estrazione[i] = 1 + rand() % 90;
        cout << estrazione[i] << endl;
        i = i + 1;
    }
}

void gioca(int z, vector<int>giocata) {
    int i;

    i = 0;
    while (i < z) {
        cout << "che numero scegli?" << endl;
        cin >> giocata[i];
        i = i + 1;
    }
}

int visualizzaMenu() {
    int scelta;

    do {
        cout << "Menu di gioco: 1 Gioca al lotto 2 Estrazione numeri del lotto 3 Controlla vincita 0 Esci " << endl;
        cin >> scelta;
    } while (scelta > 4 || scelta >= 4 && scelta != 0);
    
    return scelta;
}




int main() {
    int scelta, n, i, z, j, vittoria, numero;
    bool trovato;

    n = 5;
    int estrazione[n];

    do {
        scelta = visualizzaMenu();
        cout << "Hai scelto: " << scelta << endl;
        if (scelta == 1) {
            cout << "quanti numeri puoi giocare ?" << endl;
            cin >> z;
            int giocata[z];

            gioca(z, giocata);
        }
        if (scelta == 2) {
            estrazioneNumeri(n, estrazione);
        }
        if (scelta == 3) {
            controllaVincita(estrazione, giocata, n, z);
        }
    } while (scelta != 0);
    return 0;
}

