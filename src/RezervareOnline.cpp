
#include "RezervareOnline.h"
#include <iostream>

// Constructor - apeleaza constructorul clasei de baza (Rezervare)
RezervareOnline::RezervareOnline(std::string numeClient, std::string emailClient,
                                  Film* film, Sala* sala, int rand, int coloana)
    : Rezervare(numeClient, film, sala, rand, coloana) {
    this->emailClient = emailClient;
}

// Getter / Setter
std::string RezervareOnline::getEmailClient() const {
    return emailClient;
}

void RezervareOnline::setEmailClient(std::string email) {
    this->emailClient = email;
}

// Suprascriem metoda afiseaza() - adaugam emailul
void RezervareOnline::afiseaza() const {
    std::cout << "[ONLINE] Rezervare pentru: " << numeClient
              << " (email: " << emailClient << ")";
    if (film != nullptr) {
        std::cout << " | Film: " << film->getTitlu();
    }
    if (sala != nullptr) {
        std::cout << " | Sala: " << sala->getNumar();
    }
    std::cout << " | Loc: R" << rand + 1 << "C" << coloana + 1 << std::endl;
}
