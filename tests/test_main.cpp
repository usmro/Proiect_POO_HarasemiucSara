
// Teste unitare simple pentru sistemul de rezervari
// Nu folosim biblioteci externe - scriem teste manual cu assert-uri

#include "Film.h"
#include "Sala.h"
#include "Rezervare.h"
#include "RezervareOnline.h"
#include "Cinematograf.h"
#include "Exceptii.h"
#include <iostream>
#include <cassert>

using namespace std;

// Contor pentru testele rulate
int teste_trecute = 0;
int teste_totale = 0;

// Macro simplu pentru rularea unui test
#define TEST(nume_test) \
    do { \
        teste_totale++; \
        cout << "[TEST] " << #nume_test << " ... "; \
        if (nume_test()) { \
            cout << "OK" << endl; \
            teste_trecute++; \
        } else { \
            cout << "ESUAT!" << endl; \
        } \
    } while(0)

// Test 1: Crearea unui film si verificarea atributelor
bool test_creare_film() {
    Film f("Dune", "SF", 155, "2D");
    if (f.getTitlu() != "Dune") return false;
    if (f.getGen() != "SF") return false;
    if (f.getDurata() != 155) return false;
    if (f.getTip() != "2D") return false;
    return true;
}

// Test 2: Crearea unei sali si verificarea dimensiunilor
bool test_creare_sala() {
    Sala s(1, 5, 8);
    if (s.getNumar() != 1) return false;
    if (s.getRanduri() != 5) return false;
    if (s.getColoane() != 8) return false;
    // Toate locurile trebuie sa fie libere initial
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (s.esteOcupat(i, j)) return false;
        }
    }
    return true;
}

// Test 3: Ocuparea unui loc
bool test_ocupare_loc() {
    Sala s(1, 5, 8);
    if (s.esteOcupat(2, 3)) return false;  // initial liber
    s.ocupaLoc(2, 3);
    if (!s.esteOcupat(2, 3)) return false;  // dupa ocupare, trebuie ocupat
    return true;
}

// Test 4: Rezervare reusita
bool test_rezervare_reusita() {
    Cinematograf c("Test Cinema");
    Film* f = new Film("Test Film", "Drama", 120, "2D");
    Sala* s = new Sala(1, 3, 5);
    s->setFilm(f);
    c.adaugaFilm(f);
    c.adaugaSala(s);

    try {
        c.realizeazaRezervare("Ion", 1, 0, 0);
        // Locul trebuie sa fie acum ocupat
        if (!s->esteOcupat(0, 0)) return false;
        return true;
    } catch (...) {
        return false;
    }
}

// Test 5: Exceptia pentru loc ocupat
bool test_exceptie_loc_ocupat() {
    Cinematograf c("Test Cinema");
    Film* f = new Film("Test", "Drama", 120, "2D");
    Sala* s = new Sala(1, 3, 5);
    s->setFilm(f);
    c.adaugaFilm(f);
    c.adaugaSala(s);

    c.realizeazaRezervare("Ion", 1, 0, 0);
    // A doua rezervare pe acelasi loc trebuie sa arunce exceptie
    try {
        c.realizeazaRezervare("Maria", 1, 0, 0);
        return false;  // Nu a aruncat exceptie - test esuat
    } catch (const LocOcupatException&) {
        return true;  // Exact ce vroiam
    } catch (...) {
        return false;
    }
}

// Test 6: Exceptia pentru index invalid (in afara salii)
bool test_exceptie_index_invalid() {
    Cinematograf c("Test Cinema");
    Film* f = new Film("Test", "Drama", 120, "2D");
    Sala* s = new Sala(1, 3, 5);
    s->setFilm(f);
    c.adaugaFilm(f);
    c.adaugaSala(s);

    try {
        c.realizeazaRezervare("Ion", 1, 10, 10);  // Sala e doar 3x5
        return false;  // Trebuia sa arunce exceptie
    } catch (const IndexInvalidException&) {
        return true;
    } catch (...) {
        return false;
    }
}

// Test 7: Exceptia pentru sala inexistenta
bool test_exceptie_sala_inexistenta() {
    Cinematograf c("Test Cinema");
    try {
        c.realizeazaRezervare("Ion", 99, 0, 0);  // Nu exista sala 99
        return false;
    } catch (const IndexInvalidException&) {
        return true;
    } catch (...) {
        return false;
    }
}

// Test 8: Mostenirea RezervareOnline
bool test_mostenire_rezervare_online() {
    Film f("Dune", "SF", 155, "2D");
    Sala s(1, 5, 8);
    RezervareOnline ro("Maria", "maria@test.com", &f, &s, 2, 3);
    if (ro.getNumeClient() != "Maria") return false;
    if (ro.getEmailClient() != "maria@test.com") return false;
    if (ro.getRand() != 2) return false;
    if (ro.getColoana() != 3) return false;
    return true;
}

// Test 9: Polimorfism - pointer Rezervare* catre RezervareOnline
bool test_polimorfism() {
    Film f("Dune", "SF", 155, "2D");
    Sala s(1, 5, 8);
    // Pointer la clasa de baza care indica spre clasa derivata
    Rezervare* r = new RezervareOnline("Ana", "ana@x.com", &f, &s, 1, 1);
    // Daca polimorfismul functioneaza, getNumeClient() returneaza "Ana"
    bool ok = (r->getNumeClient() == "Ana");
    delete r;  // destructorul virtual se asigura ca se sterge corect
    return ok;
}

// Test 10: Eliberare loc
bool test_eliberare_loc() {
    Sala s(1, 3, 3);
    s.ocupaLoc(1, 1);
    if (!s.esteOcupat(1, 1)) return false;
    s.elibereazaLoc(1, 1);
    if (s.esteOcupat(1, 1)) return false;
    return true;
}

int main() {
    cout << "====================================" << endl;
    cout << "  TESTE UNITARE - Sistem Cinema" << endl;
    cout << "====================================" << endl;

    TEST(test_creare_film);
    TEST(test_creare_sala);
    TEST(test_ocupare_loc);
    TEST(test_rezervare_reusita);
    TEST(test_exceptie_loc_ocupat);
    TEST(test_exceptie_index_invalid);
    TEST(test_exceptie_sala_inexistenta);
    TEST(test_mostenire_rezervare_online);
    TEST(test_polimorfism);
    TEST(test_eliberare_loc);

    cout << "====================================" << endl;
    cout << "Rezultat: " << teste_trecute << "/" << teste_totale
         << " teste trecute" << endl;
    cout << "====================================" << endl;

    return (teste_trecute == teste_totale) ? 0 : 1;
}
