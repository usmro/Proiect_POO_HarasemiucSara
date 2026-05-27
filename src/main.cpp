#include "Cinematograf.h"
#include "Exceptii.h"
#include "RezervareOnline.h"
#include "Culori.h"
#include <iostream>
#include <string>
#include <limits>

// Pentru activarea ANSI in Windows
// Pentru activarea ANSI in Windows
#ifdef _WIN32
#include <windows.h>
// Macro-ul lipseste in versiuni vechi de MinGW
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif
#endif

using namespace std;
using namespace Culori;

// Activeaza suportul pentru culori ANSI in Windows
void activeazaCulori() {
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    // Setam si encoding-ul pentru caractere speciale
    SetConsoleOutputCP(65001);  // UTF-8
#endif
}

// Banner de pornire cu ASCII art mare
void afiseazaBanner() {
    using namespace Culori;
    cout << "\n";
    cout << CYAN_D << BOLD;
    cout << "   ######  ##  ##   ##  #####  ##   ##    ###    \n";
    cout << "  ##       ##  ###  ## ##      ### ###   ## ##   \n";
    cout << "  ##       ##  ## # ## ####    #######  ##   ##  \n";
    cout << "  ##       ##  ##  ### ##      ## # ##  #######  \n";
    cout << "   ######  ##  ##   ## #####   ##   ## ##     ## \n";
    cout << RESET;
    cout << GALBEN << BOLD;
    cout << "          ~ Sistem de Rezervari Bilete ~          \n";
    cout << RESET << endl;
}

// Meniu colorat
void afiseazaMeniu() {
    cout << "\n" << GALBEN << BOLD;
    cout << "  +----------------- MENIU ------------------+\n" << RESET;
    cout << GALBEN << "  | " << RESET << CYAN_D << "1" << RESET << " - " << "filme       "
         << " - afiseaza filmele disponibile" << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << CYAN_D << "2" << RESET << " - " << "sali        "
         << " - afiseaza salile               " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << CYAN_D << "3" << RESET << " - " << "locuri      "
         << " - schema unei sali              " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << CYAN_D << "4" << RESET << " - " << "rezerva     "
         << " - rezervare la casa             " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << CYAN_D << "5" << RESET << " - " << "online      "
         << " - rezervare online (cu email)   " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << CYAN_D << "6" << RESET << " - " << "listeaza    "
         << " - afiseaza rezervarile          " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << CYAN_D << "7" << RESET << " - " << "ajutor      "
         << " - reafiseaza meniul             " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << "  | " << RESET << ROSU_D << "0" << RESET << " - " << "iesire      "
         << " - inchide aplicatia             " << GALBEN << "  |" << RESET << "\n";
    cout << GALBEN << BOLD;
    cout << "  +------------------------------------------+\n" << RESET;
}

// Mesaj de succes (verde)
void afiseazaSucces(const string& mesaj) {
    cout << VERDE_D << BOLD << "[OK] " << RESET << VERDE << mesaj << RESET << endl;
}

// Mesaj de eroare (rosu)
void afiseazaEroare(const string& mesaj) {
    cout << ROSU_D << BOLD << "[EROARE] " << RESET << ROSU << mesaj << RESET << endl;
}

// Prompt pentru input
void afiseazaPrompt(const string& text) {
    cout << CYAN << "  > " << RESET << text;
}

// Citeste o linie intreaga
string citesteLinie(const string& prompt) {
    afiseazaPrompt(prompt);
    string linie;
    getline(cin, linie);
    return linie;
}

// Citeste un numar intreg (cu validare)
int citesteIntreg(const string& prompt) {
    afiseazaPrompt(prompt);
    int n;
    while (!(cin >> n)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        afiseazaEroare("Valoare invalida. Reincearca:");
        afiseazaPrompt(prompt);
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return n;
}

// Initializeaza cinematograful cu date de test
void initializeazaDate(Cinematograf& cinema) {
    Film* f1 = new Film("Interstellar", "SF", 169, "2D");
    Film* f2 = new Film("Avatar 3", "Aventura", 192, "3D");
    Film* f3 = new Film("Dune", "SF", 155, "2D");
    cinema.adaugaFilm(f1);
    cinema.adaugaFilm(f2);
    cinema.adaugaFilm(f3);

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
    activeazaCulori();  // Activam suportul ANSI pe Windows
    afiseazaBanner();

    Cinematograf cinema("Cinema");
    initializeazaDate(cinema);

    afiseazaMeniu();

    string comanda;
    while (true) {
        cout << "\n" << GALBEN_D << "cinema> " << RESET;
        getline(cin, comanda);

        if (comanda == "0" || comanda == "iesire" || comanda == "exit") {
            cout << CYAN_D << BOLD << "\nLa revedere! Multumim ca ati folosit Cinema!\n"
                 << RESET << endl;
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
                afiseazaEroare(e.what());
            }
        }
        else if (comanda == "4" || comanda == "rezerva") {
            try {
                string nume = citesteLinie("Nume client: ");
                int numarSala = citesteIntreg("Numarul salii: ");
                int rand = citesteIntreg("Randul (1, 2, 3...): ");
                int coloana = citesteIntreg("Coloana (1, 2, 3...): ");
                cinema.realizeazaRezervare(nume, numarSala, rand - 1, coloana - 1);
                afiseazaSucces("Rezervare realizata cu succes pentru " + nume + "!");
            } catch (const LocOcupatException& e) {
                afiseazaEroare(e.what());
            } catch (const IndexInvalidException& e) {
                afiseazaEroare(e.what());
            }
        }
        else if (comanda == "5" || comanda == "online") {
            try {
                string nume = citesteLinie("Nume client: ");
                string email = citesteLinie("Email client: ");
                int numarSala = citesteIntreg("Numarul salii: ");
                int rand = citesteIntreg("Randul (1, 2, 3...): ");
                int coloana = citesteIntreg("Coloana (1, 2, 3...): ");

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

                sala->ocupaLoc(rand - 1, coloana - 1);
                RezervareOnline* ro = new RezervareOnline(nume, email,
                    sala->getFilm(), sala, rand - 1, coloana - 1);
                cinema.adaugaRezervare(ro);
                afiseazaSucces("Rezervare online realizata cu succes! (confirmare la " + email + ")");
            } catch (const LocOcupatException& e) {
                afiseazaEroare(e.what());
            } catch (const IndexInvalidException& e) {
                afiseazaEroare(e.what());
            }
        }
        else if (comanda == "6" || comanda == "listeaza") {
            cinema.afiseazaRezervari();
        }
        else if (comanda == "7" || comanda == "ajutor" || comanda == "help") {
            afiseazaMeniu();
        }
        else if (comanda.empty()) {
            // ignora Enter gol
        }
        else {
            afiseazaEroare("Comanda necunoscuta. Scrie 'ajutor' pentru lista de comenzi.");
        }
    }

    return 0;
}
