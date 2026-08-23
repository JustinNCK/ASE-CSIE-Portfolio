# Imobiliare — Aplicație Agenție Imobiliară

**Materie:** Programare Avansată Windows (PAW) · **An:** Anul 2

## Ce face

Aplicație Windows Forms pentru gestionarea unui portofoliu de proprietăți imobiliare. Permite adăugarea și vizualizarea locuințelor (apartamente și case) cu proprietățile lor (suprafață, număr camere, preț). Afișează datele într-un ListView.

## Concepte / tehnologii folosite

- Clasă abstractă `Locuinta` cu proprietăți: cod, suprafata, nrCamere, pret
- Moștenire: `Apartament` (+ etaj), `Casa` (+ suprafataCurte)
- Windows Forms (WinForms), ListView, FormAdaugare
- Polimorfism, constructori cu parametri

## Fișiere principale

- `Locuinta.cs` — clasă abstractă de bază
- `Apartament.cs` — moștenire + câmp etaj
- `Casa.cs` — moștenire + câmp suprafataCurte
- `Form1.cs` — fereastra principală cu ListView
- `FormAdaugare.cs` — formular adăugare locuință
- `Program.cs` — punct de intrare
