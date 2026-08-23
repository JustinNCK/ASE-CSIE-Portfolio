# Subiect 6 — Turneu Sportiv

**Materie:** Programare Avansată Windows (PAW) · **An:** Anul 2

## Ce face

Aplicație WinForms pentru gestionarea unui turneu sportiv cu echipe și meciuri. Validează unicitatea echipelor și înregistrează rezultatele.

## Concepte / tehnologii folosite

- Clase: `Echipa`, `Meci`, `Turneu`
- `enum Rezultate` pentru rezultatele meciurilor
- `List<T>` pentru colecție de echipe/meciuri
- Validare unicitate echipe la adăugare
- Formulare separate pentru adăugare echipă și înregistrare rezultat

## Fișiere principale

- `Turneu.cs` — logică principală: `List<T>`, validare unicitate
- `Echipa.cs`, `Meci.cs` — modele
- `AdaugaEchipaForm.cs`, `InregistreazaRezultatForm.cs` — formulare
