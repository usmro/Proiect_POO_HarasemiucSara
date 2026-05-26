
#include "../include/Cinematograf.h"
#include "../include/Exceptii.h"
#include <iostream>

// Constructor
Cinematograf::Cinematograf(std::string nume) {
    this->nume = nume;
}

// Destructor - eliberam memoria pentru obiectele alocate dinamic
Cinematograf::~Cinematograf() {
    // Stergem rezervarile
    for (unsigned int i = 0; i < rezervari.size(); i++) {
        delete rezervari[i];
    }
    // Stergem salile
    for (unsigned int i = 0; i < sali.size(); i++) {
        delete sali[i];
    }
    // Stergem filmele
    for (unsigned int i = 0; i < filme.size(); i++) {
        delete filme[i];
    }
}

// Getter
std::string Cinematograf::getNume() const {
    return nume;
}

// Adaugare film
void Cinematograf::adaugaFilm(Film* film) {
    filme.push_back(film);
}

// Adaugare sala
void Cinematograf::adaugaSala(Sala* sala) {
    sali.push_back(sala);
}

// Afiseaza toate filmele
void Cinematograf::afiseazaFilme() const {
    std::cout << "\n=== Filme disponibile la " << nume << " ===" << std::endl;
    if (filme.empty()) {
        std::cout << "Nu exista filme momentan.\n" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < filme.size(); i++) {
        std::cout << (i + 1) << ". ";
        filme[i]->afiseaza();
    }
    std::cout << std::endl;
}

// Afiseaza toate salile
void Cinematograf::afiseazaSali() const {
    std::cout << "\n=== Sali la " << nume << " ===" << std::endl;
    if (sali.empty()) {
        std::cout << "Nu exista sali momentan.\n" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < sali.size(); i++) {
        std::cout << "Sala " << sali[i]->getNumar()
                  << " (" << sali[i]->getRanduri() << "x"
                  << sali[i]->getColoane() << ")";
        if (sali[i]->getFilm() != nullptr) {
            std::cout << " - Ruleaza: " << sali[i]->getFilm()->getTitlu();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Afiseaza locurile dintr-o sala
void Cinematograf::afiseazaLocuri(int numarSala) const {
    Sala* sala = gasesteSala(numarSala);
    if (sala == nullptr) {
        throw IndexInvalidException("Sala cu numarul " +
                                     std::to_string(numarSala) + " nu exista!");
    }
    sala->afiseazaLocuri();
}

// Afiseaza toate rezervarile
void Cinematograf::afiseazaRezervari() const {
    std::cout << "\n=== Rezervari ===" << std::endl;
    if (rezervari.empty()) {
        std::cout << "Nu exista rezervari momentan.\n" << std::endl;
        return;
    }
    for (unsigned int i = 0; i < rezervari.size(); i++) {
        std::cout << (i + 1) << ". ";
        rezervari[i]->afiseaza();
    }
    std::cout << std::endl;
}

// Realizeaza o rezervare - arunca exceptii daca ceva nu e ok
void Cinematograf::realizeazaRezervare(std::string numeClient, int numarSala,
                                       int rand, int coloana) {
    // Cautam sala
    Sala* sala = gasesteSala(numarSala);
    if (sala == nullptr) {
        throw IndexInvalidException("Sala " + std::to_string(numarSala) + " nu exista!");
    }

    // Verificam ca indexii sunt valizi
    if (rand < 0 || rand >= sala->getRanduri()) {
        throw IndexInvalidException("Randul " + std::to_string(rand + 1) +
                                     " este in afara salii!");
    }
    if (coloana < 0 || coloana >= sala->getColoane()) {
        throw IndexInvalidException("Coloana " + std::to_string(coloana + 1) +
                                     " este in afara salii!");
    }

    // Verificam daca locul e deja ocupat
    if (sala->esteOcupat(rand, coloana)) {
        throw LocOcupatException(rand, coloana);
    }

    // Marcam locul ca ocupat
    sala->ocupaLoc(rand, coloana);

    // Cream si salvam rezervarea
    Rezervare* rez = new Rezervare(numeClient, sala->getFilm(), sala, rand, coloana);
    rezervari.push_back(rez);

    std::cout << "Rezervare realizata cu succes pentru " << numeClient << "!" << std::endl;
}

// Cauta o sala dupa numar
Sala* Cinematograf::gasesteSala(int numarSala) const {
    for (unsigned int i = 0; i < sali.size(); i++) {
        if (sali[i]->getNumar() == numarSala) {
            return sali[i];
        }
    }
    return nullptr;
}

int Cinematograf::getNumarSali() const { return sali.size(); }
int Cinematograf::getNumarFilme() const { return filme.size(); }
