# Handout 7 — Moștenire Avansată și Memory Management

**Materie:** Programare Orientată pe Obiecte (POO) · **An:** Anul 2

## Ce face

Continuarea Handout 6 cu accent pe corectitudinea memory management-ului în context de moștenire și pe completarea operatorilor pentru clasa derivată.

## Concepte / tehnologii folosite

- Destructor virtual și lanț de dealocări corecte
- `operator=` cascadat (`z = y = x`)
- Apel explicit al operatorului bazei: `TrainRoute::operator=()`
- Test exhaustiv memory leak prin pointer de bază
- Regula celor 3 completă în context de moștenire

## Fișiere principale

- `Handout7/Source.cpp` — implementare completă
- `UnitTests/UnitTests.cpp` — teste unitare cu memory leak detection
