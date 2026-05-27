# 🎬 Sistem de Rezervari pentru Cinema

Proiect realizat in cadrul disciplinei **Programare Orientata pe Obiecte (POO)** in C++.

Aplicatie de tip consola (CLI) care simuleaza un sistem complet de rezervari la cinema: gestionare filme, sali cu locuri (matrice), rezervari clasice (la casa) si rezervari online (cu email).

---

## Cuprins

- [Functionalitati](#functionalitati)
- [Structura proiectului](#structura-proiectului)
- [Compilare si rulare](#compilare-si-rulare)
- [Folosire](#folosire)
- [Exemple de utilizare](#exemple-de-utilizare)
- [Teste unitare](#teste-unitare)
- [Concepte POO folosite](#concepte-poo-folosite)
- [Tehnologii](#tehnologii)
- [Autor](#autor)

---

## Functionalitati

- **Afisare filme** disponibile (titlu, gen, durata, tip 2D/3D)
- **Afisare sali** cu informatii despre dimensiuni si filmul curent
- **Vizualizare schema sala** cu locuri colorate (verde = liber, rosu = ocupat)
- **Rezervare la casa** - pentru clientii care vin direct la cinema
- **Rezervare online** - cu email pentru confirmare
- **Listare rezervari** existente, diferentiate vizual (la casa vs online)
- **Gestiune exceptii**: loc deja ocupat, index invalid, sala inexistenta
- **Interfata CLI colorata** (ANSI) pentru o experienta vizuala placuta

---

## Structura proiectului

```
Proiect_POO_HarasemiucSara/
├── src/                        Fisiere sursa (.cpp)
│   ├── Film.cpp
│   ├── Sala.cpp
│   ├── Rezervare.cpp
│   ├── RezervareOnline.cpp
│   ├── Cinematograf.cpp
│   └── main.cpp                Interfata CLI principala
├── include/                    Fisiere header (.h)
│   ├── Film.h
│   ├── Sala.h
│   ├── Rezervare.h
│   ├── RezervareOnline.h
│   ├── Cinematograf.h
│   ├── ICinemaService.h        Interfata (clasa abstracta pura)
│   ├── Exceptii.h              Clase custom de exceptii
│   └── Culori.h                Coduri ANSI pentru terminal colorat
├── tests/
│   └── test_main.cpp           Teste unitare (10 teste)
├── docs/
│   └── documentatie.md         Documentatie completa cu UML
├── Makefile                    Sistem de build (Windows + Linux)
├── cinema.cbp                  Proiect Code::Blocks
├── .gitignore
└── README.md
```

---

## Compilare si rulare

### Pe Windows

**Optiunea 1: Cu Code::Blocks (recomandat)**

1. Deschide `cinema.cbp` in Code::Blocks
2. Apasa **F9** (Build and run)

**Optiunea 2: Cu g++ din PowerShell/CMD**

```
g++ -std=c++11 -Iinclude src/*.cpp -o cinema.exe
.\cinema.exe
```

### Pe Linux (Ubuntu, Debian, etc.)

**Optiunea 1: Cu Makefile (recomandat)**

```
sudo apt install build-essential
make
./cinema
```

**Optiunea 2: Manual cu g++**

```
g++ -std=c++11 -Iinclude src/*.cpp -o cinema
./cinema
```

### Comenzi Makefile disponibile

| Comanda      | Descriere                                    |
|--------------|----------------------------------------------|
| `make`       | Compileaza aplicatia principala              |
| `make run`   | Compileaza si ruleaza aplicatia              |
| `make test`  | Compileaza si ruleaza testele unitare        |
| `make clean` | Sterge executabilele si fisierele temporare  |

---

## Folosire

Aplicatia ofera un meniu interactiv cu urmatoarele comenzi:

| Nr. | Comanda     | Descriere                                |
|-----|-------------|------------------------------------------|
| 1   | `filme`     | Afiseaza filmele disponibile             |
| 2   | `sali`      | Afiseaza salile cinematografului         |
| 3   | `locuri`    | Afiseaza schema de locuri a unei sali    |
| 4   | `rezerva`   | Realizeaza o rezervare la casa           |
| 5   | `online`    | Realizeaza o rezervare online (cu email) |
| 6   | `listeaza`  | Afiseaza toate rezervarile facute        |
| 7   | `ajutor`    | Reafiseaza meniul de comenzi             |
| 0   | `iesire`    | Inchide aplicatia                        |

Comenzile pot fi date fie prin **numar** (ex. `4`), fie prin **nume** (ex. `rezerva`).

---

## Exemple de utilizare

**Vizualizarea filmelor:**

```
cinema> filme

=== Filme disponibile la Cinema Royal ===
1. [Film] Interstellar | Gen: SF | Durata: 169 min | Tip: 2D
2. [Film] Avatar 3 | Gen: Aventura | Durata: 192 min | Tip: 3D
3. [Film] Dune | Gen: SF | Durata: 155 min | Tip: 2D
```

**Realizarea unei rezervari:**

```
cinema> rezerva
  > Nume client: Ion Popescu
  > Numarul salii: 1
  > Randul (1, 2, 3...): 3
  > Coloana (1, 2, 3...): 4
[OK] Rezervare realizata cu succes pentru Ion Popescu!
```

**Vizualizarea schemei salii:**

```
cinema> locuri
  > Numarul salii: 1

+---------------------------------+
|         Sala 1                  |
+---------------------------------+
Ruleaza: Interstellar (2D)
[ ] = liber  [X] = ocupat

      1  2  3  4  5  6  7  8
    ------------------------
R1: [ ][ ][ ][ ][ ][ ][ ][ ]
R2: [ ][ ][ ][ ][ ][ ][ ][ ]
R3: [ ][ ][ ][X][ ][ ][ ][ ]
R4: [ ][ ][ ][ ][ ][ ][ ][ ]
R5: [ ][ ][ ][ ][ ][ ][ ][ ]
```

**Exceptie pentru loc ocupat:**

```
cinema> rezerva
  > Nume client: Maria Ionescu
  > Numarul salii: 1
  > Randul (1, 2, 3...): 3
  > Coloana (1, 2, 3...): 4
[EROARE] Eroare: Locul R3C4 este deja ocupat!
```

---

## Teste unitare

Proiectul include **10 teste unitare** care valideaza:

1. Crearea unui film si verificarea atributelor
2. Crearea unei sali si initializarea locurilor
3. Ocuparea unui loc
4. Realizarea unei rezervari reusite
5. Exceptia pentru loc ocupat
6. Exceptia pentru index invalid
7. Exceptia pentru sala inexistenta
8. Mostenirea `RezervareOnline` din `Rezervare`
9. Polimorfismul (pointer la clasa de baza)
10. Eliberarea unui loc

**Rulare teste:**

```
make test
```

Rezultat asteptat:

```
====================================
  TESTE UNITARE - Sistem Cinema
====================================
[TEST] test_creare_film ... OK
[TEST] test_creare_sala ... OK
[TEST] test_ocupare_loc ... OK
[TEST] test_rezervare_reusita ... OK
[TEST] test_exceptie_loc_ocupat ... OK
[TEST] test_exceptie_index_invalid ... OK
[TEST] test_exceptie_sala_inexistenta ... OK
[TEST] test_mostenire_rezervare_online ... OK
[TEST] test_polimorfism ... OK
[TEST] test_eliberare_loc ... OK
====================================
Rezultat: 10/10 teste trecute
====================================
```

---

## Concepte POO folosite

| Concept                  | Aplicare in proiect                                       |
|--------------------------|-----------------------------------------------------------|
| **Incapsulare**          | Atribute private cu getteri si setteri                    |
| **Mostenire**            | `RezervareOnline` extinde `Rezervare`                     |
| **Polimorfism**          | Metoda virtuala `afiseaza()` suprascrisa                  |
| **Clase abstracte pure** | Interfata `ICinemaService` cu metode pure virtuale (`=0`) |
| **Exceptii**             | `LocOcupatException`, `IndexInvalidException`             |
| **Agregare**             | `Cinematograf` agrega `Film*` si `Sala*`                  |
| **Compozitie**           | `Sala` contine matricea de locuri                         |
| **STL**                  | `std::vector`, `std::string`                              |
| **Destructori virtuali** | Pentru curatare corecta in ierarhia de clase              |
| **`override`**           | Verificare la compilare a suprascrierii                   |

Pentru detalii complete, vezi `docs/documentatie.md`.

---

## Tehnologii

- **Limbaj:** C++ (standard C++11)
- **Compilator:** g++ (MinGW pe Windows / GCC pe Linux)
- **Sistem build:** Make + proiect Code::Blocks (.cbp)
- **Control versiune:** Git + GitHub
- **Editare:** Code::Blocks 20.03

---

## Cerinte sistem

- Compilator C++ care suporta C++11 (g++ 4.8 sau mai nou)
- Terminal cu suport ANSI pentru culori:
  - Windows 10/11 - PowerShell, Windows Terminal, sau cmd.exe modern
  - Linux/Mac - orice terminal modern

---

## Autor

**Student** - Proiect Programare Orientata pe Obiecte (POO)

Tema: Sistem de Rezervari pentru un Cinema

---

## Status

✅ Proiect finalizat - toate cerintele obligatorii si 2 cerinte facultative implementate.
