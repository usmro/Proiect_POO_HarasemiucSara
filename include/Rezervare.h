#ifndef REZERVARE_H
#define REZERVARE_H

#include "Film.h"
#include "Sala.h"
#include <string>

// Clasa Rezervare - reprezinta o rezervare a unui loc pentru un film
class Rezervare {
protected:  // protected pentru ca mosteneste RezervareOnline
    std::string numeClient;
    Film* film;
    Sala* sala;
    int rand;
    int coloana;

public:
    // Constructori
    Rezervare();
    Rezervare(std::string numeClient, Film* film, Sala* sala, int rand, int coloana);

    // Destructor virtual (pentru mostenire corecta)
    virtual ~Rezervare();

    // Getteri
    std::string getNumeClient() const;
    Film* getFilm() const;
    Sala* getSala() const;
    int getRand() const;
    int getColoana() const;

    // Metoda virtuala - poate fi suprascrisa in RezervareOnline
    virtual void afiseaza() const;
};

#endif
