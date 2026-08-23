-- 17
CREATE TABLE Salariati_S AS
SELECT id_angajat, nume, prenume, data_angajare, id_functie, salariul, id_manager, id_department
FROM Angajati
WHERE id_department IN (
  SELECT id_department 
  FROM Departamente 
  WHERE denumire_departament IN ('Sales', 'Stocks', 'Shipping')
);

-- 18
ALTER TABLE Salariati_S 
ADD Prima NUMBER(5,2);

-- 19
UPDATE Salariati_S
SET Prima = 0.15;

-- 20
ALTER TABLE Salariati_S
ADD CONSTRAINT pk_salariati_s PRIMARY KEY (id_angajat);

-- 21
ALTER TABLE Salariati_S
MODIFY Prima NOT NULL;

-- 22
ALTER TABLE Salariati_S
SET UNUSED (Prima);

-- 23
ALTER TABLE Salariati_S
DROP UNUSED COLUMNS;

-- 24
UPDATE Salariati_S
SET salariul = salariul * 0.9
WHERE data_angajare < TO_DATE('01-06-2016', 'DD-MM-YYYY');

-- 25
UPDATE Salariati_S
SET salariul = salariul * 1.15
WHERE id_manager IN (120, 121, 122, 123, 124, 125)
  AND id_functie != 'ST_MAN';

-- 26
UPDATE Salariati_S
SET (salariul, id_functie) = (
    SELECT salariul, id_functie 
    FROM Angajati 
    WHERE salariul = (SELECT MAX(salariul) FROM Angajati)
    FETCH FIRST 1 ROWS ONLY
)
WHERE id_department = 50 AND id_manager = 100;

-- 27
DELETE FROM Salariati_S
WHERE data_angajare < ADD_MONTHS(SYSDATE, -36);

ROLLBACK;