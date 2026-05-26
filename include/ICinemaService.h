
#ifndef ICINEMASERVICE_H
#define ICINEMASERVICE_H

#include <string>

// Interfata ICinemaService - clasa abstracta pura
// Defineste serviciile de baza pe care orice cinematograf trebuie sa le ofere.
// O clasa care implementeaza aceasta interfata trebuie sa suprascrie toate
// metodele pure virtuale (cele cu " = 0 ").
class ICinemaService {
public:
    // Destructor virtual - necesar pentru clase abstracte cu mostenire
    virtual ~ICinemaService() {}

    // Metode pure virtuale (= 0) - trebuie obligatoriu implementate
    virtual void afiseazaFilme() const = 0;
    virtual void afiseazaLocuri(int numarSala) const = 0;
    virtual void realizeazaRezervare(std::string numeClient, int numarSala,
                                     int rand, int coloana) = 0;
};

#endif
