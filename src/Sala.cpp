#include "../include/Sala.h"
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

// Afiseaza schema salii cu locuri libere/ocupate
void Sala::afiseazaLocuri() const {
    std::cout << "\n=== Sala " << numar << " ===" << std::endl;
    if (film != nullptr) {
        std::cout << "Ruleaza: " << film->getTitlu() << std::endl;
    }
    std::cout << "[ ] = liber  [X] = ocupat\n" << std::endl;

    // Afisam coloanele (numere)
    std::cout << "    ";
    for (int j = 0; j < coloane; j++) {
        std::cout << " " << j + 1 << " ";
    }
    std::cout << std::endl;

    // Afisam fiecare rand
    for (int i = 0; i < randuri; i++) {
        std::cout << "R" << i + 1 << ": ";
        for (int j = 0; j < coloane; j++) {
            if (locuri[i][j]) {
                std::cout << "[X]";
            } else {
                std::cout << "[ ]";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}