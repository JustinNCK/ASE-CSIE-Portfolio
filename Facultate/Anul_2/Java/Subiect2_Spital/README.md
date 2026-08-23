# Subiect 2 — Sistem Gestiune Spital (Java + SQLite + JSON)

**Materie:** Java · **An:** Anul 2

## Ce face

Aplicație Java care gestionează un spital cu persistență duală: bază de date SQLite pentru pacienți și fișier JSON pentru secții. Demonstrează integrarea OOP cu persistării prin două tehnologii diferite în același proiect.

## Concepte / tehnologii folosite

- Java OOP: clase, encapsulare
- Persistență SQLite via `sqlite-jdbc-3.41.2.1.jar`
- Schimb de date JSON via `json-20240303.jar`
- Operații CRUD pe două entități separate

## Fișiere principale

- `src/Main.java` — punct de intrare
- `src/Pacienti.java` — gestiune pacienți cu SQLite
- `src/Sectii.java` — gestiune secții cu JSON
- `src/spital.db` — baza de date SQLite
- `src/sectii.json` — date secții în format JSON
