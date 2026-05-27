#include "../include/Sala.h"
#include "Culori.h"

#include <iostream>

// Constructor implicit - sala goala
Sala::Sala() {
    numar = 0;
    randuri = 0;
    coloane = 0;
    film = nullptr;
}

// Constructor cu parametri - creeaza sala cu dimensiunile date
Sala::Sala(int numar, int randuri, int coloane) {
    this->numar = numar;
    this->randuri = randuri;
    this->coloane = coloane;
    this->film = nullptr;

    // Initializam matricea cu false (toate locurile libere)
    locuri.resize(randuri, std::vector<bool>(coloane, false));
}

// Getteri
int Sala::getNumar() const { return numar; }
int Sala::getRanduri() const { return randuri; }
int Sala::getColoane() const { return coloane; }
Film* Sala::getFilm() const { return film; }

bool Sala::esteOcupat(int rand, int coloana) const {
    return locuri[rand][coloana];
}

// Setter pentru film
void Sala::setFilm(Film* film) {
    this->film = film;
}

// Marcheaza un loc ca ocupat
void Sala::ocupaLoc(int rand, int coloana) {
    locuri[rand][coloana] = true;
}

// Elibereaza un loc
void Sala::elibereazaLoc(int rand, int coloana) {
    locuri[rand][coloana] = false;
}

void Sala::afiseazaLocuri() const {
    using namespace Culori;

    // Antet sala
    std::cout << "\n" << CYAN_D << BOLD;
    std::cout << "+---------------------------------+\n";
    std::cout << "|         Sala " << numar << "                  |\n";
    std::cout << "+---------------------------------+" << RESET << std::endl;

    if (film != nullptr) {
        std::cout << GALBEN << "Ruleaza: " << BOLD << film->getTitlu()
                  << RESET << " (" << MAGENTA << film->getTip() << RESET << ")" << std::endl;
    }

    std::cout << VERDE << "[ ]" << RESET << " = liber  "
              << ROSU << "[X]" << RESET << " = ocupat\n" << std::endl;

    // Capul de tabel cu numere de coloane
    std::cout << "    ";
    for (int j = 0; j < coloane; j++) {
        std::cout << CYAN << " " << j + 1 << " " << RESET;
    }
    std::cout << "\n    ";
    for (int j = 0; j < coloane; j++) {
        std::cout << "---";
    }
    std::cout << std::endl;

    // Randurile cu locuri
    for (int i = 0; i < randuri; i++) {
        std::cout << CYAN << "R" << i + 1 << ": " << RESET;
        for (int j = 0; j < coloane; j++) {
            if (locuri[i][j]) {
                std::cout << ROSU << "[X]" << RESET;
            } else {
                std::cout << VERDE << "[ ]" << RESET;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
