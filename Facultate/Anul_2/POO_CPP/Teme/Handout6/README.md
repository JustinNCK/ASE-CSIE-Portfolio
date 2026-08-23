# Handout 6 — Moștenire: TrainRoute → FreightTrainRoute

**Materie:** Programare Orientată pe Obiecte (POO) · **An:** Anul 2

## Ce face

Introducere în moștenire prin ierarhia `TrainRoute` (bază) → `FreightTrainRoute` (derivată). Include supraîncărcarea operatorilor de I/O și metodă virtuală `totalWeight()`.

## Concepte / tehnologii folosite

- Moștenire publică: `FreightTrainRoute : public TrainRoute`
- Metodă `virtual` și `override`: `totalWeight()`
- Destructor virtual
- `operator<<` și `operator>>` (citire/scriere console)
- Deep copy: constructor de copiere + `operator=` pentru `char* trainCode` și `float* weigthPerWagon`
- Test memory leak: `delete` prin pointer de bază (`TrainRoute*`)

## Fișiere principale

- `Handout6/Source.cpp` — ierarhia completă
- `UnitTests/UnitTests.cpp` — 10 teste unitare (inclusiv memory leak)
