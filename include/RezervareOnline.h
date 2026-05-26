
#ifndef REZERVAREONLINE_H
#define REZERVAREONLINE_H

#include "Rezervare.h"
#include <string>

// RezervareOnline - mosteneste din Rezervare si adauga emailul clientului
// Demonstreaza: MOSTENIRE si POLIMORFISM (suprascriere metoda virtuala afiseaza)
class RezervareOnline : public Rezervare {
private:
    std::string emailClient;

public:
    // Constructor - apeleaza constructorul clasei de baza
    RezervareOnline(std::string numeClient, std::string emailClient,
                    Film* film, Sala* sala, int rand, int coloana);

    // Getter / Setter pentru noul atribut
    std::string getEmailClient() const;
    void setEmailClient(std::string email);

    // Suprascriem metoda afiseaza() - polimorfism!
    void afiseaza() const override;
};

#endif
