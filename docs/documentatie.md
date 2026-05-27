# Documentatie Proiect - Sistem de Rezervari Cinema

## 1. Tema proiectului

Tema 3121B: **Sistem de Rezervari pentru un Cinema**

Aplicatia gestioneaza:
- Filmele disponibile la cinema
- Salile de proiectie (fiecare sala are o matrice de locuri)
- Rezervarile facute de clienti

## 2. Obiective

- Aplicarea conceptelor POO: clase, mostenire, polimorfism, encapsulare
- Folosirea exceptiilor pentru tratarea erorilor
- Implementarea unei interfete (clasa abstracta pura)
- Lucrul cu Git (commit-uri, branch-uri)

## 3. Descrierea claselor

### 3.1. Clasa `Film`
Reprezinta un film proiectat la cinema.

Atribute:
- `titlu` (string) - numele filmului
- `gen` (string) - genul filmului (actiune, drama, etc.)
- `durata` (int) - durata in minute
- `tip` (string) - "2D" sau "3D"

### 3.2. Clasa `Sala`
Reprezinta o sala de proiectie cu locuri (matrice).

Atribute:
- `numar` (int) - numarul salii
- `randuri`, `coloane` (int) - dimensiunile matricei de locuri
- `locuri` (matrice de bool) - true = ocupat, false = liber
- `film` (Film*) - filmul care ruleaza in sala

### 3.3. Clasa `Rezervare`
Reprezinta o rezervare a unui loc pentru un film.

Atribute:
- `numeClient` (string) - numele celui care rezerva
- `film` (Film*) - filmul rezervat
- `sala` (Sala*) - sala in care e rezervarea
- `rand`, `coloana` (int) - locul rezervat

### 3.4. Clasa `RezervareOnline` (mosteneste din `Rezervare`)
Adauga functionalitatea de rezervare online.

Atribute suplimentare:
- `emailClient` (string) - emailul clientului

### 3.5. Clasa `Cinematograf`
Agrega mai multe sali si gestioneaza intregul sistem.

Atribute:
- `nume` (string) - numele cinematografului
- `sali` (vector<Sala>) - lista salilor
- `rezervari` (vector<Rezervare*>) - lista rezervarilor

### 3.6. Interfata `ICinemaService` (clasa abstracta pura)
Defineste serviciile de baza ale unui cinematograf.

Metode pure virtuale:
- `void afiseazaFilme()`
- `void afiseazaLocuri(int numarSala)`
- `void realizeazaRezervare(...)`

### 3.7. Clase de exceptii
- `LocOcupatException` - cand locul e deja ocupat
- `IndexInvalidException` - cand indexul (rand/coloana/sala) e invalid

## 4. Diagrama UML simpla

​```
        +-------------------+
        |  ICinemaService   |  <<interface>>
        +-------------------+
        | +afiseazaFilme()  |
        | +afiseazaLocuri() |
        | +realizeazaRezv() |
        +---------+---------+
                  |
                  | implementeaza
                  v
        +-------------------+         +-----------+
        |   Cinematograf    |<>------>|   Sala    |
        +-------------------+ agrega  +-----------+
        | -nume             |         | -numar    |
        | -sali             |         | -locuri   |
        | -rezervari        |         | -film     |
        +-------------------+         +-----+-----+
                                            |
                                            | are
                                            v
                                      +-----------+
                                      |   Film    |
                                      +-----------+
                                      | -titlu    |
                                      | -gen      |
                                      | -durata   |
                                      | -tip      |
                                      +-----------+

        +-------------------+
        |    Rezervare      |
        +-------------------+
        | -numeClient       |
        | -film: Film*      |
        | -sala: Sala*      |
        | -rand, coloana    |
        +---------+---------+
                  |
                  | mosteneste
                  v
        +-------------------+
        |  RezervareOnline  |
        +-------------------+
        | -emailClient      |
        +-------------------+
​```

## 5. Concepte POO folosite

| Concept           | Unde apare                                          |
|-------------------|-----------------------------------------------------|
| Incapsulare       | Toate atributele sunt private, cu getteri/setteri  |
| Mostenire         | `RezervareOnline` extinde `Rezervare`              |
| Polimorfism       | `ICinemaService` -> `Cinematograf`                 |
| Clase abstracte   | Interfata `ICinemaService`                         |
| Exceptii          | `LocOcupatException`, `IndexInvalidException`      |
| Agregare          | `Cinematograf` agrega `Sala`                       |
| Compozitie        | `Sala` contine matricea de locuri                  |

## 6. Etape de dezvoltare

- [x] **Etapa I**: Analiza tema, documentare initiala, diagrama UML
- [ ] **Etapa II**: Implementare clase de baza (Film, Sala, Rezervare)
- [ ] **Etapa III**: Implementare Cinematograf, interfata CLI, exceptii
- [ ] **Etapa IV**: Adaugare RezervareOnline, interfata ICinemaService
- [ ] **Etapa V**: Teste unitare, Makefile, documentare finala
- [ ] **Etapa VI**: Predare proiect



## 7. Posibile imbunatatiri

Proiectul ar putea fi extins in viitor cu urmatoarele functionalitati:

- **Persistenta datelor** - salvare/incarcare filme, sali si rezervari din
  fisier (text sau binar), ca sa nu se piarda dupa inchidere
- **Calcul automat al pretului biletului** in functie de:
  - Tipul filmului (2D / 3D - cu suplimentar)
  - Ziua saptamanii (reducere lunea, weekend cu suplimentar)
  - Categoria de clienti (student, senior, copil)
- **Interfata grafica** (cu o biblioteca precum Qt sau SFML) in loc de CLI
- **Anularea unei rezervari** (eliberare loc + stergere rezervare)
- **Filtrare filme** dupa gen, tip sau durata
- **Programari multiple ale aceluiasi film** in mai multe sali si la mai multe ore
- **Sistem de cautare** dupa numele clientului in lista de rezervari
- **Validare email** la rezervarea online (verificare ca are format corect)
- **Templating C++** - clasa generica `Container<T>` pentru lista de obiecte

## 8. Concluzii

Proiectul aplica conceptele fundamentale ale Programarii Orientate pe Obiecte:
incapsulare, mostenire, polimorfism, clase abstracte si gestiunea exceptiilor.
Structura modulara (header + sursa separate, foldere pentru include/src/tests)
permite extinderea usoara cu noi functionalitati. Folosirea STL (vector, string)
reduce complexitatea codului. Testele unitare valideaza logica de baza si
comportamentul exceptiilor.