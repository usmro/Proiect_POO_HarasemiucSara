#include "../include/Cinematograf.h"
#include "../include/Exceptii.h"
#include "RezervareOnline.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Functii helper pentru meniu
void afiseazaMeniu() {
    cout << "\n========== MENIU CINEMA ==========" << endl;
    cout << "1. filme       - afiseaza filmele disponibile" << endl;
    cout << "2. sali        - afiseaza salile" << endl;
    cout << "3. locuri      - afiseaza locurile dintr-o sala" << endl;
    cout << "4. rezerva     - realizeaza o rezervare" << endl;
    cout << "5. online      - rezervare online (cu email)" << endl;
    cout << "6. listeaza    - afiseaza rezervarile facute" << endl;
    cout << "7. ajutor      - reafiseaza meniul" << endl;
    cout << "0. iesire      - inchide aplicatia" << endl;
    cout << "===================================" << endl;
}

// Citeste o linie intreaga (pentru nume cu spatii)
string citesteLinie(const string& prompt) {
    cout << prompt;
    string linie;
    getline(cin, linie);
    return linie;
}

// Citeste un numar intreg (cu validare)
int citesteIntreg(const string& prompt) {
    cout << prompt;
    int n;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Valoare invalida. Reincearca: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // scapam de \n
    return n;
}

// Initializeaza cinematograful cu date de test (filme, sali)
void initializeazaDate(Cinematograf& cinema) {
    // Adaugam filme
    Film* f1 = new Film("Interstellar", "SF", 169, "2D");
    Film* f2 = new Film("Avatar 3", "Aventura", 192, "3D");
    Film* f3 = new Film("Dune", "SF", 155, "2D");
    cinema.adaugaFilm(f1);
    cinema.adaugaFilm(f2);
    cinema.adaugaFilm(f3);

    // Adaugam sali si le asociem filme
    Sala* s1 = new Sala(1, 5, 8);
    s1->setFilm(f1);
    Sala* s2 = new Sala(2, 6, 10);
    s2->setFilm(f2);
    Sala* s3 = new Sala(3, 4, 6);
    s3->setFilm(f3);
    cinema.adaugaSala(s1);
    cinema.adaugaSala(s2);
    cinema.adaugaSala(s3);
}

int main() {
    cout << "*** Bine ai venit la Cinema USM! ***" << endl;

    // Cream cinematograful si il populam
    Cinematograf cinema("Cinema USM");
    initializeazaDate(cinema);

    afiseazaMeniu();

    // Bucla principala a aplicatiei (CLI)
    string comanda;
    while (true) {
        cout << "\n> ";
        getline(cin, comanda);

        if (comanda == "0" || comanda == "iesire" || comanda == "exit") {
            cout << "La revedere!" << endl;
            break;
        }
        else if (comanda == "1" || comanda == "filme") {
            cinema.afiseazaFilme();
        }
        else if (comanda == "2" || comanda == "sali") {
            cinema.afiseazaSali();
        }
        else if (comanda == "3" || comanda == "locuri") {
            try {
                int numarSala = citesteIntreg("Numarul salii: ");
                cinema.afiseazaLocuri(numarSala);
            } catch (const IndexInvalidException& e) {
                cout << e.what() << endl;
            }
        }
        else if (comanda == "4" || comanda == "rezerva") {
            try {
                string nume = citesteLinie("Nume client: ");
                int numarSala = citesteIntreg("Numarul salii: ");
                int rand = citesteIntreg("Randul (1, 2, 3...): ");
                int coloana = citesteIntreg("Coloana (1, 2, 3...): ");
                // Convertim la indici 0-based intern
                cinema.realizeazaRezervare(nume, numarSala, rand - 1, coloana - 1);
            } catch (const LocOcupatException& e) {
                cout << e.what() << endl;
            } catch (const IndexInvalidException& e) {
                cout << e.what() << endl;
            }
        }
        else if (comanda == "5" || comanda == "online") {
            try {
                string nume = citesteLinie("Nume client: ");
                string email = citesteLinie("Email client: ");
                int numarSala = citesteIntreg("Numarul salii: ");
                int rand = citesteIntreg("Randul (1, 2, 3...): ");
                int coloana = citesteIntreg("Coloana (1, 2, 3...): ");

                // Verificam manual ca locul nu e ocupat (cu exceptii)
                Sala* sala = cinema.gasesteSala(numarSala);
                if (sala == nullptr) {
                    throw IndexInvalidException("Sala " + to_string(numarSala) + " nu exista!");
                }
                if (rand - 1 < 0 || rand - 1 >= sala->getRanduri() ||
                    coloana - 1 < 0 || coloana - 1 >= sala->getColoane()) {
                    throw IndexInvalidException("Loc in afara salii!");
                }
                if (sala->esteOcupat(rand - 1, coloana - 1)) {
                    throw LocOcupatException(rand - 1, coloana - 1);
                }

                // Marcam locul si cream rezervarea online
                sala->ocupaLoc(rand - 1, coloana - 1);
                RezervareOnline* ro = new RezervareOnline(nume, email,
                    sala->getFilm(), sala, rand - 1, coloana - 1);
                cinema.adaugaRezervare(ro);
                cout << "Rezervare online realizata cu succes!" << endl;
            } catch (const LocOcupatException& e) {
                cout << e.what() << endl;
            } catch (const IndexInvalidException& e) {
                cout << e.what() << endl;
            }
        }

        else if (comanda == "6" || comanda == "listeaza") {
            cinema.afiseazaRezervari();
        }
        else if (comanda == "7" || comanda == "ajutor" || comanda == "help") {
            afiseazaMeniu();
        }
        else if (comanda.empty()) {
            // Nu fac nimic la Enter gol
        }
        else {
            cout << "Comanda necunoscuta. Scrie 'ajutor' pentru lista de comenzi." << endl;
        }
    }

    return 0;
}
