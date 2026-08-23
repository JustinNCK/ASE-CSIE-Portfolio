# Handout 3 — Prima Clasă: Autoturism

**Materie:** Programare Orientată pe Obiecte (POO) · **An:** Anul 2

## Ce face

Introducere în POO C++ prin modelarea clasei `Autoturism`. Exerciții cu constructori, destructor, metodă de discount și lucrul cu obiecte în colecții.

## Concepte / tehnologii folosite

- `class Autoturism` cu câmpuri: `marca`, `model`, `putere`, `pret`
- Constructor implicit (valori default: `"Necunoscuta"`, `"Necunoscut"`, `0`, `5000`)
- Constructor cu parametri
- Destructor (setare `fisierDeschis = false`)
- Metodă `discount(int procent)` cu validare [1-50]
- `enum tipAplicatie` cu valorile 5, 10, 15
- Funcții cu vector de obiecte și matrice de pointeri

## Fișiere principale

- `Handout3/Source.cpp` — implementare clasă + funcții
- `UnitTests/UnitTests.cpp` — 10 teste unitare
