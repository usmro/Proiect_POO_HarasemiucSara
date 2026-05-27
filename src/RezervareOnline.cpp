#include "Culori.h"
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

void RezervareOnline::afiseaza() const {
    using namespace Culori;
    std::cout << MAGENTA << "[ONLINE] " << RESET
              << BOLD << numeClient << RESET
              << " (" << CYAN << emailClient << RESET << ")";
    if (film != nullptr) {
        std::cout << " | " << CYAN_D << film->getTitlu() << RESET;
    }
    if (sala != nullptr) {
        std::cout << " | Sala " << sala->getNumar();
    }
    std::cout << " | Loc: " << GALBEN << "R" << rand + 1
              << "C" << coloana + 1 << RESET << std::endl;
}
