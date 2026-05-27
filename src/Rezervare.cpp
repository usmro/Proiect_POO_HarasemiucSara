#include "../include/Rezervare.h"
#include "Culori.h"

#include <iostream>

// Constructor implicit
Rezervare::Rezervare() {
    numeClient = "Necunoscut";
    film = nullptr;
    sala = nullptr;
    rand = 0;
    coloana = 0;
}

// Constructor cu parametri
Rezervare::Rezervare(std::string numeClient, Film* film, Sala* sala, int rand, int coloana) {
    this->numeClient = numeClient;
    this->film = film;
    this->sala = sala;
    this->rand = rand;
    this->coloana = coloana;
}

// Destructor (gol pentru moment)
Rezervare::~Rezervare() {
}

// Getteri
std::string Rezervare::getNumeClient() const { return numeClient; }
Film* Rezervare::getFilm() const { return film; }
Sala* Rezervare::getSala() const { return sala; }
int Rezervare::getRand() const { return rand; }
int Rezervare::getColoana() const { return coloana; }

void Rezervare::afiseaza() const {
    using namespace Culori;
    std::cout << VERDE_D << "[CASA] " << RESET
              << BOLD << numeClient << RESET;
    if (film != nullptr) {
        std::cout << " | " << CYAN_D << film->getTitlu() << RESET;
    }
    if (sala != nullptr) {
        std::cout << " | Sala " << sala->getNumar();
    }
    std::cout << " | Loc: " << GALBEN << "R" << rand + 1
              << "C" << coloana + 1 << RESET << std::endl;
}
