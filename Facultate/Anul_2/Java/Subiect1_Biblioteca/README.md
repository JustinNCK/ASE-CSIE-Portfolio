# Subiect 1 — Gestiune Librarie cu SQLite

**Materie:** Java · **An:** Anul 2

## Ce face

Aplicație Java care gestionează o bibliotecă de cărți cu bază de date SQLite. Include operații CRUD pe o tabelă de titluri și calcule de preț per volum.

## Concepte / tehnologii folosite

- Java OOP: clase, constructori, metode
- SQLite via `sqlite-jdbc`
- Citire/scriere fișiere text

## Fișiere principale

- `src/Main.java` — punct de intrare, orchestrare
- `src/PretVolum.java` — logică calcul preț per volum
- `src/TableaTitluri.java` — operații pe tabela SQLite
- `src/Titluri.db` — baza de date SQLite
