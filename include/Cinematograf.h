#ifndef CINEMATOGRAF_H
#define CINEMATOGRAF_H

#include "ICinemaService.h"
#include "Film.h"
#include "Sala.h"
#include "Rezervare.h"
#include <vector>
#include <string>

// Cinematograf - implementeaza interfata ICinemaService (polimorfism!)
class Cinematograf : public ICinemaService {
private:
    std::string nume;
    std::vector<Film*> filme;
    std::vector<Sala*> sali;
    std::vector<Rezervare*> rezervari;

public:
    // Constructor / Destructor
    Cinematograf(std::string nume);
    ~Cinematograf();

    // Getter
    std::string getNume() const;

    // Adaugare obiecte in cinematograf
    void adaugaFilm(Film* film);
    void adaugaSala(Sala* sala);
    void adaugaRezervare(Rezervare* rez);  // pentru RezervareOnline

    // Metode din interfata ICinemaService (override = suprascriere)
    void afiseazaFilme() const override;
    void afiseazaLocuri(int numarSala) const override;
    void realizeazaRezervare(std::string numeClient, int numarSala,
                             int rand, int coloana) override;

    // Metode proprii (in plus fata de interfata)
    void afiseazaSali() const;
    void afiseazaRezervari() const;

    // Cautare
    Sala* gasesteSala(int numarSala) const;
    int getNumarSali() const;
    int getNumarFilme() const;
};

#endif
