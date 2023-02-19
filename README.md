# SimCity


#Cerință
Dându-se de la tastatură comenzi de adăugare/ștergere a unor clădiri sau a unor persoane cu statuturi diferite în acele clădiri, să se facă o statistică asupra anumitor atribute ce țin de anumite tipuri de persoane sau de tipul așezării, așa cum este spus în secțiunea de Date de ieșire. Ceea ce se vrea este crearea unei așezări, care poate fi sat, oraș sau capitală, depinzând de numărul și de tipul clădirilor care se dau de la tastatură să fie adăugate în acea așezare.

#Date de intrare 
Se vor linii până la EOF. O linie este alcătuită din următoarele elemente:
- primul cuvânt va fi acțiunea pe care vreți să o faceți. Această comandă poate fi add sau remove. Dacă această comandă este add atunci se va face o adăugare, iar dacă este remove se va face o ștergere.
- al doilea cuvânt este ceea ce vreți să adăugați sau să ștergeți. Clădirile doar se pot adăuga, nu și șterge, iar persoanele suportă ambele comenzi.
        - dacă vrem să adăugăm o clădire, acest al doilea cuvânt poate fi unul din cuvintele CityHall, Hospital, PoliceStation, House sau Block.
        - dacă vrem să adăugăm sau să ștergem o anumită persoană dintr-o clădire, acest al doilea cuvânt poate fi unul din cuvintele coordinator, employee sau citizen. Pentru fiecare tip de clădire, aceste cuvinte au semnificații diferite astfel:
                - coordinator pot fi doar primarii, proprietarii de case și administratorii de bloc.
                - employee pot fi doar doctorii și polițiștii.
                - citizen pot fi doar angajații primăriei, pacienții spitalului, persoanele arestate, locuitorii caselor și locuitorii blocurilor.
- în continuare există următoarele posibilități:
        - dacă vrem să adăugăm o clădire, următoarea dată de intrare va fi numele clădirii. Pentru case (House) după numele clădirii se va citi și numărul maxim de persoane care pot locui în acea casă, iar pentru blocuri (Block) după numele clădirii se vor citi numărul de etaje al blocului și număr maxim de persoane per etaj. De exemplu, linia add Hospital ReginaMaria trebuie să adauge un spital numit ReginaMaria.
        - dacă vrem să adăugăm o persoană, următoarele date de la intrare vor fi numele persoanei, vârsta persoanei, salariul persoanei și numele clădirii în care vrem să adăugăm acea persoană. Este clar acest lucru depinde de al doilea parametru. Ca exemplu, dacă avem o clădire numită ReginaMaria, aceasta fiind un spital, iar linia noastră este add citizen Andrei 23 222.22 ReginaMaria, este clar că Andrei va fi pacient al spitalului deoarece el are statutul de citizen, iar citizenii unui spital sunt pacienții, doctorii fiind considerați employee. Dacă voiam ca persoana să fie doctor în spital, am fi avut o linie de genul add employee Andrei 23 222.22 ReginaMaria.
        - dacă vrem să ștergem o persoană, următoarele date de la intrare vor fi numele persoanei și numele clădirii. Vor considera că nu există citizen sau employee cu același nume în aceeași instituție. Exemplificând în continuare, dacă avem o linie de forma remove citizen Andrei ReginaMaria se va elimina pacientul Andrei din spitalul ReginaMaria.

#Date de ieșire 
La iesire vom avea o statistică a așezării create astfel:

Type: tipul așezării. Acest tip poate fi "Village", "Town" sau "Capital". Pentru a știi ce tip de așezare avem, se vor va trebui:
          Capital: CityHall >=3, Hospital >= 2, PoliceStation >= 3, House >= 8, Block >= 4
          Town: CityHall >=2, Hospital >= 1, PoliceStation >= 2, House >= 4, Block >= 1
          Village: Orice altceva în afară de condițiile de mai sus
Number of patients in hospitals: numărul total de pacienți din toate spitalele
Average salary for doctors: salariul mediu al tuturor doctorilor din toate spitalele
Average salary for cops: salariul mediu al tuturor polițiștilor din toate secțiile de poliție
Average salary for mayors: salariul mediu al tuturor primarilor din toate primăriile
Average salary for city hall employees: salariul mediu al tuturor angajaților din toate primăriile
Average age of busted in police stations: vârsta medie a tuturor persoanelor arestate din toate secțiile de poliție
Următoarele linii trebuie să fie de forma:
Number of people in House numele_casei: numărul de persoane din acea casă, inclusiv proprietarul dacă există
Number of people in Block numele_blocului: numărul de persoane din acel bloc, inclusiv administratorul dacă există
Liniile de mai sus vor fi puse în ordinea în care au fost date casele și blocurile de la tastatură.
Administrators of house and block: numele persoanelor care sunt și administratori de bloc și proprietari de casă. Dacă nu există nicio persoană se va pune cuvântul Nobody.
