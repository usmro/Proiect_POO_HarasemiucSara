\# Sistem de Rezervari pentru Cinema



Proiect realizat in cadrul disciplinei \*\*Programare Orientata pe Obiecte (POO)\*\* in C++.

Grupa 3121B - Tema 3 (Sistem de Rezervari pentru un Cinema).



\## Descriere



Aplicatie de tip consola (CLI) care simuleaza un sistem de rezervari la cinema.

Permite gestionarea filmelor, a salilor cu locuri (matrice), realizarea de rezervari

clasice (la casa) si rezervari online (cu email).



\## Functionalitati



\- Afisarea filmelor disponibile (cu gen, durata, tip 2D/3D)

\- Afisarea salilor si schemei de locuri (libere / ocupate)

\- Realizarea de rezervari la casa

\- Realizarea de rezervari online (cu email)

\- Listarea tuturor rezervarilor

\- Gestiunea exceptiilor (loc ocupat, index invalid, sala inexistenta)



\## Compilare si rulare



\### Optiunea 1: Cu Code::Blocks



1\. Deschide `cinema.cbp` in Code::Blocks

2\. Apasa F9 (Build and run)



\### Optiunea 2: Cu Makefile (din terminal)



```bash

make            # compileaza aplicatia

make run        # compileaza si ruleaza

make test       # compileaza si ruleaza testele

make clean      # sterge fisierele compilate

```



\### Optiunea 3: Manual cu g++



```bash

g++ -std=c++11 -Iinclude src/\*.cpp -o cinema.exe

./cinema.exe

```



\## Folosire



Aplicatia ofera un meniu CLI cu urmatoarele comenzi:



| Comanda     | Descriere                              |

|-------------|----------------------------------------|

| `filme`     | Afiseaza filmele disponibile           |

| `sali`      | Afiseaza salile                        |

| `locuri`    | Afiseaza locurile dintr-o sala         |

| `rezerva`   | Realizeaza o rezervare la casa         |

| `online`    | Realizeaza o rezervare online (email)  |

| `listeaza`  | Afiseaza rezervarile facute            |

| `ajutor`    | Reafiseaza meniul                      |

| `iesire`    | Inchide aplicatia                      |



\## Concepte POO folosite



\- \*\*Incapsulare\*\* - atribute private cu getteri/setteri

\- \*\*Mostenire\*\* - `RezervareOnline` extinde `Rezervare`

\- \*\*Polimorfism\*\* - metoda `afiseaza()` suprascrisa

\- \*\*Clase abstracte pure\*\* - interfata `ICinemaService`

\- \*\*Exceptii\*\* - `LocOcupatException`, `IndexInvalidException`

\- \*\*Agregare\*\* - `Cinematograf` agrega `Sala`

\- \*\*STL\*\* - `std::vector`, `std::string`



\## Autor



Student grupa 3121B - Proiect POO

