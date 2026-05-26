
#ifndef CINEMATOGRAF_H
#define CINEMATOGRAF_H

#include "Film.h"
#include "Sala.h"
#include "Rezervare.h"
#include <vector>
#include <string>

// Clasa Cinematograf - agrega Sali, Filme si Rezervari
class Cinematograf {
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

    // Afisari
    void afiseazaFilme() const;
    void afiseazaSali() const;
    void afiseazaLocuri(int numarSala) const;
    void afiseazaRezervari() const;

    // Realizeaza o rezervare - poate arunca exceptii!
    void realizeazaRezervare(std::string numeClient, int numarSala,
                             int rand, int coloana);

    // Cautare
    Sala* gasesteSala(int numarSala) const;
    int getNumarSali() const;
    int getNumarFilme() const;
};

#endif
