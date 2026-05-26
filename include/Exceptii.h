
#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

// Exceptie aruncata cand un loc este deja ocupat
class LocOcupatException : public std::exception {
private:
    std::string mesaj;

public:
    LocOcupatException(int rand, int coloana) {
        mesaj = "Eroare: Locul R" + std::to_string(rand + 1) +
                "C" + std::to_string(coloana + 1) + " este deja ocupat!";
    }

    // Suprascriem metoda what() din std::exception
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

// Exceptie aruncata cand un index este invalid (in afara salii)
class IndexInvalidException : public std::exception {
private:
    std::string mesaj;

public:
    IndexInvalidException(const std::string& detaliu) {
        mesaj = "Eroare: Index invalid - " + detaliu;
    }

    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

#endif
