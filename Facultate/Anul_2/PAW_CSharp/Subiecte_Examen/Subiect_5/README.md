# Subiect 5 — Bibliotecă de Cărți

**Materie:** Programare Avansată Windows (PAW) · **An:** Anul 2

## Ce face

Aplicație WinForms pentru gestionarea unei biblioteci cu împrumuturi de cărți. Include gestionarea datelor de returnare și verificarea depășirii termenului.

## Concepte / tehnologii folosite

- Clase: `Carte`, `Biblioteca`, `Imprumut`
- `DateTime?` (nullable) pentru data returnării
- Proprietate `EsteDepasit` calculată
- Windows Forms: `Form1` (lista cărți), `Imprumuta` (formular împrumut)

## Fișiere principale

- `Carte.cs` — modelul cărții
- `Imprumut.cs` — câmp `DateTime?`, proprietate `EsteDepasit`
- `Imprumuta.cs` — formular adăugare împrumut
- `Form1.cs` — fereastra principală
