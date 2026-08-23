-- 1
SELECT * FROM angajati
WHERE salariul BETWEEN 8000 and 10000;

-- 2   
SELECT * FROM angajati
WHERE id_functie LIKE 'SA_REP';

-- 3
SELECT * FROM angajati
WHERE id_functie LIKE '%ACCOUNT%' OR id_functie LIKE 'SA_REP';

-- 4
SELECT * FROM angajati
WHERE id_departament = (SELECT id_deparatament FROM angajati WHERE nume = 'Smith');

-- 5
SELECT * FROM produse
WHERE pret_lista = (SELECT MIN(pret_lista) FROM produse);

-- 6
SELECT * FROM angajati
WHERE email LIKE '_A%' OR email LIKE '_B%' OR email LIKE '_C%';
-- SUBSTR(email, 2, 1) IN ('A', 'B', 'c')

-- 7
SELECT * FROM angajati
WHERE telefon LIKE '___.123.____';

-- 8
SELECT * FROM angajati
WHERE data_angajare < TO_DATE('January 01, 2000', 'Month dd,YYYY');

-- 9
SELECT * FROM angajati
WHERE data_angajare BETWEEN TO_DATE('January 01, 2000', 'Month dd,YYYY') AND TO_DATE('January 31, 2000', 'Month dd,YYYY');

-- 10
SELECT a.nume, a.prenume, a.salariul, a.id_functie, d.denumire_departament  FROM angajati a, departamente d
WHERE a.id_departament = d.id_departament AND d.denumire_departament = 'IT';

-- 11
SELECT a.nume, a.prenume, a.salariul, a.id_functie FROM angajati a, departamente d
WHERE a.id_departament(+) = d.id_departament AND d.denumire_departament LIKE '%IT%';

-- 12
SELECT c.*, a.nume FROM angajati a, comenzi c
WHERE a.id_angajat(+) = c.id_angajat;

-- 13
SELECT p.*, rc.id_comanda FROM produse p, rand_comenzi rc
WHERE p.id_produs = rc.id_produs(+);

-- 14
SELECT a.nume, a.salariul, a.data_angajare FROM angajati a, departamente d
WHERE a.id_departament = d.id_departament AND d.denumire_departament = 'Sales'
ORDER BY a.salariul ASC, a.data_angajare DESC;

-- 15
SELECT a.nume, a.id_functie, a.comision, d.denumire_departament FROM angajati a, departamente d
WHERE a.id_departament = d.id_departament AND a.comision IS NOT NULL;