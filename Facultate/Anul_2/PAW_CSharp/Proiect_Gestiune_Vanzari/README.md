# Gestiune Vânzări — Proiect PAW

**Materie:** Programare Avansată Windows (PAW) · **An:** Anul 2

## Ce face

Cel mai complex proiect C# din portofoliu. Aplicație Windows Forms pentru gestionarea vânzărilor: clienți, produse, tranzacții. Demonstrează utilizarea avansată a caracteristicilor limbajului C#.

## Concepte / tehnologii folosite

- Delegați și evenimente (`ModificarePretDelegate`, eveniment `PretModificat`)
- Interfețe multiple: `ICloneable`, `IComparable`, `IEnumerable`, `IReducere` (custom)
- Indexer pe colecție de tranzacții
- Control WinForms custom (`StatusControl`)
- Clonare profundă (deep copy) a array-urilor
- Serializare XML

## Fișiere principale

- `Produs.cs` — `ICloneable`, `IComparable`, delegați, evenimente
- `Tranzactie.cs` — `IEnumerable`, indexer, clonare array
- `Client.cs`, `Persoana.cs` — ierarhie de clase
- `IReducere.cs` — interfață custom
- `StatusControl.cs` — control WinForms custom
- `Form1.cs` — fereastra principală
