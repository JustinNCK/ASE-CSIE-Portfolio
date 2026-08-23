--SET 1
-- 1
SELECT c.id_comanda, c.data, SUM(rc.cantitate * rc.pret) AS valoare_totala
FROM comenzi c, rand_comenzi rc
WHERE c.id_comanda = rc.id_comanda
AND c.data BETWEEN TO_DATE('01-01-1999', 'DD-MM-YYYY') 
AND TO_DATE('31-12-1999', 'DD-MM-YYYY')
GROUP BY c.id_comanda, c.data
HAVING SUM(rc.cantitate * rc.pret) > 2000
ORDER BY c.data;

-- 2
SELECT c.id_comanda, c.data, SUM(rc.cantitate * rc.pret) AS valoare_totala,
CASE 
WHEN SUM(rc.cantitate * rc.pret) < 1000 THEN 100
WHEN SUM(rc.cantitate * rc.pret) BETWEEN 1000 AND 2000 THEN 200
ELSE 300 
END AS cheltuieli_transport
FROM comenzi c, rand_comenzi rc
WHERE c.id_comanda = rc.id_comanda
GROUP BY c.id_comanda, c.data;

-- 3
SELECT c.id_client, rc.id_produs, SUM(rc.cantitate) AS cantitate_totala
FROM comenzi c, rand_comenzi rc
WHERE c.id_comanda = rc.id_comanda
GROUP BY c.id_client, rc.id_produs;

-- 4
SELECT a.nume, d.denumire_departament, LEVEL
FROM angajati a, departamente d
WHERE a.id_departament = d.id_departament
AND a.id_functie = (SELECT id_functie FROM angajati WHERE nume = 'Russell')
AND a.id_angajat IN (SELECT DISTINCT id_manager FROM angajati)
CONNECT BY PRIOR a.id_angajat = a.id_manager
START WITH a.id_manager IS NULL;

-- 5
SELECT a.nume, d.denumire_departament, LEVEL
FROM angajati a, departamente d
WHERE a.id_departament = d.id_departament
AND a.id_functie = (SELECT id_functie FROM angajati WHERE nume = 'Rogers')
AND a.id_angajat NOT IN (SELECT DISTINCT id_manager FROM angajati WHERE id_manager IS NOT NULL)
CONNECT BY PRIOR a.id_angajat = a.id_manager
START WITH a.id_manager IS NULL;

-- 6
SELECT id_departament, denumire_departament
FROM departamente
WHERE id_departament IN (
SELECT id_departament FROM angajati
MINUS
SELECT id_departament FROM angajati WHERE salariul >= 10000);

--SET 2
-- 1
SELECT a.nume, a.salariul, a.data_angajare, f.denumire_functie
FROM angajati a, functii f
WHERE a.id_functie = f.id_functie
AND (f.denumire_functie = 'Programmer' OR f.denumire_functie = 'Accountant')
AND a.data_angajare BETWEEN TO_DATE('01-01-1995', 'DD-MM-YYYY') AND TO_DATE('31-12-1998', 'DD-MM-YYYY');

-- 2
UPDATE rand_comenzi
SET pret = pret * 1.15
WHERE id_produs IN (
SELECT id_produs FROM produse 
WHERE pret_lista < (
SELECT AVG(pret_lista) FROM produse WHERE denumire_produs LIKE '%sound%'));
ROLLBACK;

-- 3
SELECT a.nume, a.data_angajare, f.denumire_functie AS functie, 'Actuala' AS status
FROM angajati a, functii f
WHERE a.id_functie = f.id_functie
AND a.id_departament IN (50, 80)
AND a.data_angajare BETWEEN TO_DATE('01-01-1995', 'DD-MM-YYYY') AND TO_DATE('31-12-1999', 'DD-MM-YYYY')
UNION
SELECT a.nume, a.data_angajare, f.denumire_functie AS functie, 'Istoric' AS status
FROM angajati a, istoric_functii ist, functii f
WHERE a.id_angajat = ist.id_angajat
AND ist.id_functie = f.id_functie
AND a.id_departament IN (50, 80)
AND a.data_angajare BETWEEN TO_DATE('01-01-1995', 'DD-MM-YYYY') AND TO_DATE('31-12-1999', 'DD-MM-YYYY');

-- 4
UPDATE rand_comenzi
SET pret = pret * 0.95
WHERE cantitate < (
SELECT AVG(rc2.cantitate)
FROM rand_comenzi rc2, produse p
WHERE rc2.id_produs = p.id_produs
AND p.denumire_produs LIKE '%CPU%');
ROLLBACK;

-- 5
SELECT p.denumire_produs, SUM(rc.cantitate * rc.pret) AS valoare_totala
FROM produse p, rand_comenzi rc
WHERE p.id_produs = rc.id_produs
GROUP BY p.denumire_produs
HAVING SUM(rc.cantitate * rc.pret) BETWEEN 1500 AND 4000;

-- 6
SELECT c.id_comanda, c.data, SUM(rc.cantitate * rc.pret) AS valoare_totala, COUNT(rc.id_produs) AS nr_produse
FROM comenzi c, rand_comenzi rc
WHERE c.id_comanda = rc.id_comanda
AND c.modalitate = 'online'
AND c.data BETWEEN TO_DATE('01-01-1999', 'DD-MM-YYYY') AND TO_DATE('31-12-2000', 'DD-MM-YYYY')
GROUP BY c.id_comanda, c.data
HAVING COUNT(rc.id_produs) >= 2;

--SET 3
-- 1
SELECT c.id_comanda, p.denumire_produs, rc.pret, rc.cantitate, (rc.pret * rc.cantitate) AS valoare
FROM produse p, rand_comenzi rc, comenzi c
WHERE p.id_produs = rc.id_produs 
AND c.id_comanda = rc.id_comanda
AND p.denumire_produs LIKE '%Monitor%';

-- 2
SELECT a.nume, a.id_departament, COUNT(c.id_comanda) AS nr_comenzi
FROM angajati a, comenzi c
WHERE a.id_angajat = c.id_angajat
AND a.id_departament = 80
AND TO_CHAR(c.data, 'MM') = '11'
GROUP BY a.nume, a.id_departament;

-- 3
UPDATE rand_comenzi
SET pret = pret * 0.90
WHERE pret > (
SELECT AVG(pret) FROM rand_comenzi WHERE id_produs = 3155);
ROLLBACK;

-- 4
SELECT a.nume, f.denumire_functie, COUNT(c.id_comanda) AS nr_comenzi
FROM angajati a, comenzi c, functii f
WHERE a.id_angajat = c.id_angajat
AND a.id_functie = f.id_functie
GROUP BY a.nume, f.denumire_functie
HAVING COUNT(c.id_comanda) >= 2;

-- 5
UPDATE rand_comenzi
SET pret = pret * 1.05
WHERE (cantitate * pret) >= 1000;
ROLLBACK;

-- 6
SELECT a.nume, COUNT(c.id_comanda) AS nr_comenzi, a.salariul,
CASE 
WHEN COUNT(c.id_comanda) BETWEEN 1 AND 2 THEN a.salariul * 0.05
WHEN COUNT(c.id_comanda) BETWEEN 3 AND 5 THEN a.salariul * 0.07
WHEN COUNT(c.id_comanda) > 5 THEN a.salariul * 0.10
ELSE 0 
END AS bonus
FROM angajati a, comenzi c
WHERE a.id_angajat = c.id_angajat(+)
GROUP BY a.nume, a.salariul;