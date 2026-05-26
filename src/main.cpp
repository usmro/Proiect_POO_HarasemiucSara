#include "../include/Film.h"
#include "../include/Sala.h"
#include "../include/Rezervare.h"
#include <iostream>

// Test simplu pentru clasele de baza (Etapa II)
// In etapele urmatoare aici va fi interfata CLI
int main() {
    std::cout << "=== Test clase de baza ===" << std::endl;

    // Cream un film
    Film f1("Interstellar", "SF", 169, "2D");
    f1.afiseaza();

    // Cream o sala 5x8
    Sala s1(1, 5, 8);
    s1.setFilm(&f1);

    // Afisam sala (toate locurile libere)
    s1.afiseazaLocuri();

    // Ocupam cateva locuri
    s1.ocupaLoc(2, 3);
    s1.ocupaLoc(0, 0);
    std::cout << "Dupa ocupare locuri:" << std::endl;
    s1.afiseazaLocuri();

    // Cream o rezervare
    Rezervare r1("Ion Popescu", &f1, &s1, 2, 3);
    r1.afiseaza();

    std::cout << "\n=== Test terminat cu succes ===" << std::endl;
    return 0;
}