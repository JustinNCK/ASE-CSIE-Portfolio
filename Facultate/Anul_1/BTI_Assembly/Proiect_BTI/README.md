# Proiect BTI — Operații în Cod Complement față de 2

**Materie:** Bazele Tehnologiei Informatiei (BTI) · **An:** Anul 1

## Ce face

Program complet în Assembly x86 (16-bit, MASM/TASM) care implementează operații aritmetice în cod complement față de 2. Conține proceduri separate pentru adunare, scădere și conversii (direct → invers → complement). Interacționează cu utilizatorul prin întreruperi DOS (INT 21h) și gestionează stiva explicit.

## Concepte / tehnologii folosite

- Assembly x86 16-bit (MASM/TASM)
- Cod complement față de 2
- Proceduri și apeluri de stivă
- Întreruperi DOS (INT 21h) pentru I/O
- Conversii binar: direct, invers, complement

## Fișiere principale

- `Proiect_BTI.asm` — proiect principal: citire/adunare/afișare numere binare
- `adunareCodComplementar.asm` — adunare în cod complement față de 2
- `codInvCompDir.asm` — conversii cod direct → invers → complement
- `proiectBTI_scadere.asm` — scădere în complement față de 2
- `ceva.asm` — fișier test/scratch
