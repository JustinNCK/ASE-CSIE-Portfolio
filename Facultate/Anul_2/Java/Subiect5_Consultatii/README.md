# Subiect 5 — Gestiune Consultații Medicale (Java + SQLite + JSON)

**Materie:** Java · **An:** Anul 2

## Ce face

Aplicație Java pentru gestionarea consultațiilor medicale. Combină persistență SQLite pentru consultații cu JSON pentru specialitățile medicale și manevrele asociate.

## Concepte / tehnologii folosite

- Java OOP cu multiple clase de domeniu
- SQLite (`sqlite-jdbc-3.30.1.jar`) pentru persistență
- JSON (`json-20220320.jar`) pentru date de referință

## Fișiere principale

- `src/Main.java` — punct de intrare
- `src/Consultatii.java` — gestiune consultații cu SQLite
- `src/Manevre.java` — manevre medicale
- `src/SpecialitatiMedicale.java` — specialități din JSON
- `src/consultatii.db`, `src/medicale.json` — date persistență
