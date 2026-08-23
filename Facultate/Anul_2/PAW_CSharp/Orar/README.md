# Orar — Aplicație Orar Academic

**Materie:** Programare Avansată Windows (PAW) · **An:** Anul 2

## Ce face

Aplicație Windows Forms pentru gestionarea unui orar academic. Permite adăugarea de ore cu validare automată a suprapunerilor. Implementează un indexer pentru accesul la elementele orarului.

## Concepte / tehnologii folosite

- Clase C#: `Element`, `Ora`, `Orar`
- Indexer pentru accesul la colecție
- Validare suprapunere ore, excepții custom
- Windows Forms (WinForms)

## Fișiere principale

- `Orar.cs` — logica principală: indexer, validare suprapunere, excepții
- `Ora.cs` — reprezentarea unei ore din orar
- `Element.cs` — element de bază
- `FormAdaugare.cs` — formular adăugare
- `Form1.cs` — fereastra principală
