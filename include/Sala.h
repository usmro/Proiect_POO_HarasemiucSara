#ifndef SALA_H
#define SALA_H

#include "Film.h"
#include <vector>

// Clasa Sala - reprezinta o sala de cinema cu matrice de locuri
class Sala {
private:
    int numar;
    int randuri;
    int coloane;
    std::vector<std::vector<bool>> locuri;  // true = ocupat, false = liber
    Film* film;  // filmul care ruleaza in sala (poate fi NULL)

public:
    // Constructori
    Sala();
    Sala(int numar, int randuri, int coloane);

    // Getteri
    int getNumar() const;
    int getRanduri() const;
    int getColoane() const;
    Film* getFilm() const;
    bool esteOcupat(int rand, int coloana) const;

    // Setteri
    void setFilm(Film* film);

    // Metode
    void ocupaLoc(int rand, int coloana);  // marcheaza locul ca ocupat
    void elibereazaLoc(int rand, int coloana);
    void afiseazaLocuri() const;  // afiseaza schema salii
};

#endif