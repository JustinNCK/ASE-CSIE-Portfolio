# Handout 5 — Imprimantă: Static, Compozitie, Const

**Materie:** Programare Orientată pe Obiecte (POO) · **An:** Anul 2

## Ce face

Modelarea clasei `Imprimanta` cu un `Cartus` — demonstrând: membri `const`, membri statici, metodă statică de calcul și relație de compozitie.

## Concepte / tehnologii folosite

- `const int serialNumber` — câmp constant inițializat în lista de inițializare
- `static string tipImprimanta` — atribut de clasă cu getter/setter statici
- Metodă statică `getTotalPaginiPerProducator()` pe vector de imprimante
- Compozitie (`has-a`): `Imprimanta` conține un `Cartus`
- `getNumarPaginiRamase()`: calcul pages left (nu returnează negativ)
- Regula celor 3 completă pentru `char* producator`
- Teste unitare Microsoft CppUnitTestFramework

## Fișiere principale

- `Handout5/Source.cpp` — clasele `Cartus` și `Imprimanta`
- `UnitTests/UnitTests.cpp` — 10 teste unitare (inclusiv test memory leak)
