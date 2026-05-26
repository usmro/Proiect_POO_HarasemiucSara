#ifndef FILM_H
#define FILM_H

#include <string>

// Clasa Film - reprezinta un film proiectat la cinema
class Film {
private:
    std::string titlu;
    std::string gen;
    int durata;       // durata in minute
    std::string tip;  // "2D" sau "3D"

public:
    // Constructori
    Film();
    Film(std::string titlu, std::string gen, int durata, std::string tip);

    // Getteri (incapsulare - acces la atributele private)
    std::string getTitlu() const;
    std::string getGen() const;
    int getDurata() const;
    std::string getTip() const;

    // Setteri
    void setTitlu(std::string titlu);
    void setGen(std::string gen);
    void setDurata(int durata);
    void setTip(std::string tip);

    // Metoda pentru afisare
    void afiseaza() const;
};

#endif