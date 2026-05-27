#include "Film.h"
#include "Culori.h"

#include <iostream>

// Constructor implicit
Film::Film() {
    titlu = "Necunoscut";
    gen = "Necunoscut";
    durata = 0;
    tip = "2D";
}

// Constructor cu parametri
Film::Film(std::string titlu, std::string gen, int durata, std::string tip) {
    this->titlu = titlu;
    this->gen = gen;
    this->durata = durata;
    this->tip = tip;
}

// Getteri
std::string Film::getTitlu() const { return titlu; }
std::string Film::getGen() const { return gen; }
int Film::getDurata() const { return durata; }
std::string Film::getTip() const { return tip; }

// Setteri
void Film::setTitlu(std::string titlu) { this->titlu = titlu; }
void Film::setGen(std::string gen) { this->gen = gen; }
void Film::setDurata(int durata) { this->durata = durata; }
void Film::setTip(std::string tip) { this->tip = tip; }

// Afiseaza informatiile filmului - colorat
void Film::afiseaza() const {
    using namespace Culori;
    std::cout << CYAN_D << "[Film]" << RESET << " "
              << BOLD << titlu << RESET
              << " | Gen: " << GALBEN << gen << RESET
              << " | Durata: " << durata << " min"
              << " | Tip: " << MAGENTA << tip << RESET << std::endl;
}
