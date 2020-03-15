Tema 6. Clasa ”Lista_circulara” (implementata dinamic)
Se considera Class Nod{ int info; Nod* next;}
- constructori de inițializare și parametrizati pentru clasa Nod;
- destructor pentru clasa Nod;
Clasa Lista_circulara are:
- cel puțin un membru privat „Nod*” reprezentând nodul considerat prim;
- metoda publica de adaugare a unui element pe o poziție;
- supraincarcare a operatorului >>, realizata prin utilizarea succesiva a metodei decarata anterior;
- metoda publica de stergere a unui element de pe o poziție;
- metoda publica pentru inversarea legaturilor listei;
- metoda publica care primește parametrul întreg k și realizatea eliminarea elementelor listei circulare din k în k pana la golirea acesteia (elementele vor fi afisate în ordinea în care sunt eliminate);
- supraincarcarea operatorului +, care sa efectueze concatenarea a doua liste circulare, rezultand într-o noua lista circulara (ca în exemplul de mai jos).
Lista_circulara L1 = { 1 → 2 → 3 → 1} , L2 = {4 → 5 → 6 → 4}
L1 + L2 = { 1 → 2 → 3 → 4 → 5 → 6 → 1}.

Proiectul nu este complet.
Daca actiunile sunt execute succesiv programul functioneaza.
Am facut:
-constructori/destructori pentru clasa Nod
-metoda de adaugare/citire/stregere/inserare
-supraincarcare de operatori(>>/<<)
Nu am facut:
-inversare de legaturi
-concatenare liste
Daca pun variabilele int info si Nod *next in class Nod pe private imi da eroare de compilare.

