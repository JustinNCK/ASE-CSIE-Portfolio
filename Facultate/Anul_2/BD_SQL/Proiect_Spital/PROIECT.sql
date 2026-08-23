DROP TABLE INTERNARI CASCADE CONSTRAINTS;
DROP TABLE CONSULTATII CASCADE CONSTRAINTS;
DROP TABLE SALOANE CASCADE CONSTRAINTS;
DROP TABLE MEDICI_INCEPATORI CASCADE CONSTRAINTS;
DROP TABLE MEDICI_SENIORI CASCADE CONSTRAINTS;
DROP TABLE PACIENTI CASCADE CONSTRAINTS;
DROP TABLE DEPARTAMENTE CASCADE CONSTRAINTS;

-- 1. Tabela DEPARTAMENTE
CREATE TABLE DEPARTAMENTE (
    id_departament NUMBER(4) CONSTRAINT pk_departamente PRIMARY KEY,
    nume_departament VARCHAR2(50) NOT NULL,
    locatie VARCHAR2(50)
);

-- 2. Tabela PACIENTI
CREATE TABLE PACIENTI (
    id_pacient NUMBER(10) CONSTRAINT pk_pacienti PRIMARY KEY,
    nume_pacient VARCHAR2(50) NOT NULL,
    prenume_pacient VARCHAR2(50) NOT NULL,
    cnp VARCHAR2(13) NOT NULL, 
    data_nasterii DATE,
    adresa_domiciliu VARCHAR2(100)
);

-- 3. Tabela MEDICI_SENIORI
CREATE TABLE MEDICI_SENIORI (
    id_senior NUMBER(6) CONSTRAINT pk_medici_seniori PRIMARY KEY,
    id_departament NUMBER(4) NOT NULL,
    nume_senior VARCHAR2(50) NOT NULL,
    prenume_senior VARCHAR2(50) NOT NULL,
    specializare_senior VARCHAR2(50),
    grad_profesional VARCHAR2(30),
    CONSTRAINT fk_senior_dept FOREIGN KEY (id_departament) 
        REFERENCES DEPARTAMENTE(id_departament)
);

-- 4. Tabela MEDICI_INCEPATORI
CREATE TABLE MEDICI_INCEPATORI (
    id_incepator NUMBER(6) CONSTRAINT pk_medici_incepatori PRIMARY KEY,
    id_senior_mentor NUMBER(6), 
    nume_incepator VARCHAR2(50) NOT NULL,
    prenume_incepator VARCHAR2(50) NOT NULL,
    telefon_contact VARCHAR2(15),
    an_rezidentiat NUMBER(1) 
);

-- 5. Tabela SALOANE
CREATE TABLE SALOANE (
    id_salon NUMBER(5) CONSTRAINT pk_saloane PRIMARY KEY,
    id_departament NUMBER(4) NOT NULL,
    cod_salon VARCHAR2(10) NOT NULL,
    capacitate NUMBER(2) NOT NULL,
    paturi_ocupate NUMBER(2) DEFAULT 0,
    CONSTRAINT fk_salon_dept FOREIGN KEY (id_departament) 
        REFERENCES DEPARTAMENTE(id_departament)
);

-- 6. Tabela CONSULTATII
CREATE TABLE CONSULTATII (
    id_consultatie NUMBER(10) CONSTRAINT pk_consultatii PRIMARY KEY,
    id_pacient NUMBER(10) NOT NULL,
    id_med_incepator NUMBER(6) NOT NULL,
    data_consultatie DATE DEFAULT SYSDATE, 
    diagnostic_preliminar VARCHAR2(100),
    CONSTRAINT fk_cons_pac FOREIGN KEY (id_pacient) 
        REFERENCES PACIENTI(id_pacient),
    CONSTRAINT fk_cons_inc FOREIGN KEY (id_med_incepator) 
        REFERENCES MEDICI_INCEPATORI(id_incepator)
);

-- 7. Tabela INTERNARI
CREATE TABLE INTERNARI (
    id_internare NUMBER(10) CONSTRAINT pk_internari PRIMARY KEY,
    id_pacient NUMBER(10) NOT NULL,
    id_salon NUMBER(5) NOT NULL,
    id_med_senior NUMBER(6) NOT NULL,
    data_internare DATE NOT NULL,
    data_externare DATE,
    CONSTRAINT fk_int_pac FOREIGN KEY (id_pacient) 
        REFERENCES PACIENTI(id_pacient),
    CONSTRAINT fk_int_salon FOREIGN KEY (id_salon) 
        REFERENCES SALOANE(id_salon),
    CONSTRAINT fk_int_senior FOREIGN KEY (id_med_senior) 
        REFERENCES MEDICI_SENIORI(id_senior)
);

-- Adaugare constrangere UNIQUE pe CNP la pacienti
ALTER TABLE PACIENTI 
ADD CONSTRAINT uk_cnp_pacient UNIQUE (cnp);

-- Adaugare constrangere CHECK la Saloane (capacitate > 0)
ALTER TABLE SALOANE
ADD CONSTRAINT ck_capacitate_ok CHECK (capacitate > 0);

-- Adaugare Cheie Externa la MEDICI_INCEPATORI catre MEDICI_SENIORI
ALTER TABLE MEDICI_INCEPATORI
ADD CONSTRAINT fk_incepator_mentor 
FOREIGN KEY (id_senior_mentor) REFERENCES MEDICI_SENIORI(id_senior);

-- Adaugare constrangere CHECK pentru an_rezidentiat
ALTER TABLE MEDICI_INCEPATORI
ADD CONSTRAINT ck_an_rezidentiat CHECK (an_rezidentiat BETWEEN 1 AND 6);


INSERT INTO DEPARTAMENTE VALUES (10, 'Cardiologie', 'Aripa A');
INSERT INTO DEPARTAMENTE VALUES (20, 'Chirurgie', 'Aripa B');
INSERT INTO DEPARTAMENTE VALUES (30, 'Neurologie', 'Aripa C');
INSERT INTO DEPARTAMENTE VALUES (40, 'Pediatrie', 'Aripa D');
INSERT INTO DEPARTAMENTE VALUES (50, 'UPU', 'Parter');
INSERT INTO DEPARTAMENTE VALUES (60, 'Gastroenterologie', 'Aripa E');
INSERT INTO DEPARTAMENTE VALUES (70, 'Ortopedie', 'Aripa F');
INSERT INTO DEPARTAMENTE VALUES (80, 'Dermatologie', 'Etaj 1');
INSERT INTO DEPARTAMENTE VALUES (90, 'Oncologie', 'Etaj 2');
INSERT INTO DEPARTAMENTE VALUES (100, 'Radiologie', 'Subsol');

INSERT INTO SALOANE VALUES (101, 10, 'C-101', 5, 2);
INSERT INTO SALOANE VALUES (102, 10, 'C-102', 3, 0);
INSERT INTO SALOANE VALUES (201, 20, 'CH-01', 4, 4);
INSERT INTO SALOANE VALUES (202, 20, 'CH-02', 2, 1);
INSERT INTO SALOANE VALUES (301, 30, 'N-301', 3, 2);
INSERT INTO SALOANE VALUES (302, 30, 'N-302', 2, 0);
INSERT INTO SALOANE VALUES (401, 40, 'P-401', 6, 5);
INSERT INTO SALOANE VALUES (402, 40, 'P-402', 4, 1);
INSERT INTO SALOANE VALUES (501, 50, 'U-001', 10, 8);
INSERT INTO SALOANE VALUES (502, 50, 'U-002', 5, 0);


INSERT INTO MEDICI_SENIORI VALUES (100, 10, 'Popescu', 'Ion', 'Cardiologie Interventionala', 'Primar');
INSERT INTO MEDICI_SENIORI VALUES (200, 20, 'Ionescu', 'Maria', 'Chirurgie Generala', 'Primar');
INSERT INTO MEDICI_SENIORI VALUES (300, 30, 'Vasilescu', 'Dan', 'Neurologie', 'Specialist');
INSERT INTO MEDICI_SENIORI VALUES (400, 40, 'Georgescu', 'Elena', 'Pediatrie', 'Primar');
INSERT INTO MEDICI_SENIORI VALUES (500, 50, 'Dumitrescu', 'Andrei', 'Medicina Urgenta', 'Specialist');
INSERT INTO MEDICI_SENIORI VALUES (600, 60, 'Miron', 'Sonia', 'Gastroenterologie', 'Primar');
INSERT INTO MEDICI_SENIORI VALUES (700, 70, 'Nistor', 'Victor', 'Ortopedie', 'Specialist');
INSERT INTO MEDICI_SENIORI VALUES (800, 80, 'Diaconu', 'Alina', 'Dermatologie', 'Primar');
INSERT INTO MEDICI_SENIORI VALUES (900, 90, 'Dragomir', 'Horia', 'Oncologie', 'Specialist');
INSERT INTO MEDICI_SENIORI VALUES (1000, 100, 'Pavel', 'Raluca', 'Radiologie', 'Primar');


INSERT INTO MEDICI_INCEPATORI VALUES (1, 100, 'Alexandrescu', 'Mihai', '0722111111', 1);
INSERT INTO MEDICI_INCEPATORI VALUES (2, 200, 'Barbu', 'Ana', '0722222222', 3);
INSERT INTO MEDICI_INCEPATORI VALUES (3, 300, 'Costea', 'Radu', '0722333333', 2);
INSERT INTO MEDICI_INCEPATORI VALUES (4, 100, 'Dobre', 'Ioana', '0722444444', 1);
INSERT INTO MEDICI_INCEPATORI VALUES (5, 500, 'Enache', 'Florin', '0722555555', 5);
INSERT INTO MEDICI_INCEPATORI VALUES (6, 600, 'Filip', 'Andreea', '0722666666', 4);
INSERT INTO MEDICI_INCEPATORI VALUES (7, 700, 'Gavrila', 'George', '0722777777', 2);
INSERT INTO MEDICI_INCEPATORI VALUES (8, 400, 'Hriscu', 'Iulia', '0722888888', 3);
INSERT INTO MEDICI_INCEPATORI VALUES (9, 900, 'Ilie', 'Stefan', '0722999999', 1);
INSERT INTO MEDICI_INCEPATORI VALUES (10, 1000, 'Jipa', 'Monica', '0722000000', 4);


INSERT INTO PACIENTI VALUES (1000, 'Hetac', 'Iustin', '1990101123456', TO_DATE('01-01-1999', 'DD-MM-YYYY'), 'Str. Libertatii 1');

INSERT INTO PACIENTI VALUES (1, 'Popa', 'Andrei', '1800101123456', TO_DATE('1980-01-01', 'YYYY-MM-DD'), 'Str. Florilor 10');
INSERT INTO PACIENTI VALUES (2, 'Dumitru', 'Elena', '2900505123456', TO_DATE('1990-05-05', 'YYYY-MM-DD'), 'Str. Primaverii 5');
INSERT INTO PACIENTI VALUES (3, 'Stoica', 'Ionut', '1750310123456', TO_DATE('1975-03-10', 'YYYY-MM-DD'), 'Calea Victoriei 100');
INSERT INTO PACIENTI VALUES (4, 'Radu', 'Maria', '2851212123456', TO_DATE('1985-12-12', 'YYYY-MM-DD'), 'Bld. Unirii 20');
INSERT INTO PACIENTI VALUES (5, 'Mihai', 'Cristian', '1920707123456', TO_DATE('1992-07-07', 'YYYY-MM-DD'), 'Str. Toamnei 3');
INSERT INTO PACIENTI VALUES (6, 'Stan', 'Laura', '2980909123456', TO_DATE('1998-09-09', 'YYYY-MM-DD'), 'Str. Sperantei 15');
INSERT INTO PACIENTI VALUES (7, 'Lupu', 'Gabriel', '1681120123456', TO_DATE('1968-11-20', 'YYYY-MM-DD'), 'Str. Aviației 8');
INSERT INTO PACIENTI VALUES (8, 'Marin', 'Ana', '2700430123456', TO_DATE('1970-04-30', 'YYYY-MM-DD'), 'Soseaua Colentina 40');
INSERT INTO PACIENTI VALUES (9, 'Constantin', 'Paul', '1880225123456', TO_DATE('1988-02-25', 'YYYY-MM-DD'), 'Str. Libertatii 12');
INSERT INTO PACIENTI VALUES (10, 'Vasile', 'Carmen', '2950615123456', TO_DATE('1995-06-15', 'YYYY-MM-DD'), 'Str. Mare 1');

INSERT INTO CONSULTATII VALUES (1, 1, 1, SYSDATE-5, 'Angina Pectorala');
INSERT INTO CONSULTATII VALUES (2, 2, 2, SYSDATE-4, 'Apendicita Suspectata');
INSERT INTO CONSULTATII VALUES (3, 3, 3, SYSDATE-3, 'Migrena Cronica');
INSERT INTO CONSULTATII VALUES (4, 4, 4, SYSDATE-2, 'Suflu Sistolic');
INSERT INTO CONSULTATII VALUES (5, 5, 5, SYSDATE-1, 'Traumatism Abdominal');
INSERT INTO CONSULTATII VALUES (6, 6, 6, SYSDATE, 'Gastrita Acuta');
INSERT INTO CONSULTATII VALUES (7, 7, 7, SYSDATE-1, 'Fractura Tibie');
INSERT INTO CONSULTATII VALUES (8, 8, 8, SYSDATE-6, 'Varicela');
INSERT INTO CONSULTATII VALUES (9, 9, 9, SYSDATE-10, 'Anemie Feripriva');
INSERT INTO CONSULTATII VALUES (10, 10, 10, SYSDATE-1, 'Sinuzita Cronica');


INSERT INTO INTERNARI VALUES (701, 1001, 201, 200, TO_DATE('01-11-2023', 'DD-MM-YYYY'), TO_DATE('05-11-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (702, 1005, 101, 100, TO_DATE('04-11-2023', 'DD-MM-YYYY'), NULL);
INSERT INTO INTERNARI VALUES (703, 1002, 301, 300, TO_DATE('02-11-2023', 'DD-MM-YYYY'), TO_DATE('03-11-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (704, 1003, 401, 400, TO_DATE('02-11-2023', 'DD-MM-YYYY'), TO_DATE('06-11-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (705, 1009, 302, 300, TO_DATE('07-11-2023', 'DD-MM-YYYY'), NULL);
INSERT INTO INTERNARI VALUES (706, 1004, 501, 500, TO_DATE('03-11-2023', 'DD-MM-YYYY'), TO_DATE('04-11-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (707, 1006, 201, 200, TO_DATE('04-11-2023', 'DD-MM-YYYY'), TO_DATE('10-11-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (708, 1000, 102, 100, TO_DATE('01-10-2023', 'DD-MM-YYYY'), TO_DATE('03-10-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (709, 1008, 501, 500, TO_DATE('05-11-2023', 'DD-MM-YYYY'), TO_DATE('06-11-2023', 'DD-MM-YYYY'));
INSERT INTO INTERNARI VALUES (710, 1007, 101, 100, TO_DATE('10-11-2023', 'DD-MM-YYYY'), NULL);


SELECT * FROM PACIENTI
WHERE nume_pacient = 'Hetac';

/*
Sa se actualizeze numarul de paturi ocupate in tabela SALOANE. Valoarea
trebuie calculata numarand exact cati pacienti au o internare activa in salonul respectiv
*/
UPDATE SALOANE s
SET paturi_ocupate = (
 SELECT COUNT(*)
 FROM INTERNARI i
 WHERE i.id_salon = s.id_salon AND i.data_externare IS NULL
);

/*
Sa se stearga din baza de date pacientii care nu au avut nicio internare si nicio
consultatie inregistrata vreodata (pacienti inactivi)
*/
DELETE FROM PACIENTI p
WHERE NOT EXISTS (SELECT 1 FROM INTERNARI i WHERE i.id_pacient = p.id_pacient)
AND NOT EXISTS (SELECT 1 FROM CONSULTATII c WHERE c.id_pacient = p.id_pacient);

/*
Sa se majoreze anul de rezidentiat cu 1, dar doar pentru acei medici incepatori al
caror mentor este medic primar (gradul profesional 'Primar')
*/
UPDATE MEDICI_INCEPATORI
SET an_rezidentiat = an_rezidentiat + 1
WHERE id_senior_mentor IN (
 SELECT id_senior
 FROM MEDICI_SENIORI
 WHERE grad_profesional = 'Primar'
);

/*
Sa se seteze data externarii ca fiind data curenta (SYSDATE) pentru toti pacientii
internati in saloane care apartin departamentului 'Cardiologie', deoarece sectia intra in renovare
*/
UPDATE INTERNARI
SET data_externare = SYSDATE
WHERE data_externare IS NULL AND id_salon IN (
 SELECT id_salon
 FROM SALOANE s, DEPARTAMENTE d
 WHERE s.id_departament = d.id_departament AND d.nume_departament = 'Cardiologie'
);

/*
Medicul senior 'Popescu Ion' se pensioneaza. Sa se transfere toti medicii rezidenti care
erau coordonati de el catre medicul senior 'Georgescu Elena'
*/
UPDATE MEDICI_INCEPATORI
SET id_senior_mentor = (SELECT id_senior FROM MEDICI_SENIORI WHERE nume_senior = 'Georgescu' AND prenume_senior = 'Elena')
WHERE id_senior_mentor = (SELECT id_senior FROM MEDICI_SENIORI WHERE nume_senior = 'Popescu' AND prenume_senior = 'Ion');

/*
Sa se stearga toate consultatiile mai vechi de 5 ani care au avut diagnosticul preliminar
'Control de rutina', considerate irelevante pentru istoric
*/
DELETE FROM CONSULTATII
WHERE diagnostic_preliminar = 'Control de rutina' AND data_consultatie < ADD_MONTHS(SYSDATE, -60);

/*
Sa se reduca capacitatea cu 1 loc pentru toate saloanele care nu au avut niciun pacient
internat pe parcursul anului 2023
*/
UPDATE SALOANE s
SET capacitate = capacitate - 1
WHERE capacitate > 0 AND id_salon NOT IN (
 SELECT DISTINCT id_salon
 FROM INTERNARI
 WHERE TO_CHAR(data_internare, 'YYYY') = '2023'
);

/*
Sa se promoveze la gradul de 'Primar' toti medicii specialisti care coordoneaza in
prezent mai mult de 2 medici rezidenti
*/
UPDATE MEDICI_SENIORI s
SET grad_profesional = 'Primar'
WHERE grad_profesional = 'Specialist' AND (SELECT COUNT(*) FROM MEDICI_INCEPATORI i WHERE i.id_senior_mentor = s.id_senior) > 2;

/*
Sa se modifice diagnosticul in 'Viroza Respiratorie Acuta' pentru toate consultatiile
din ultima luna unde diagnosticul actual contine cuvantul 'raceala' (indiferent de scrierea cu litera mare sau mica)
*/
UPDATE CONSULTATII
SET diagnostic_preliminar = 'Viroza Respiratorie Acuta'
WHERE data_consultatie > SYSDATE - 30 AND LOWER(diagnostic_preliminar) LIKE '%raceala%';

/*
Sa se stearga din baza de date saloanele care apartin departamentului 'Pediatrie' si care au capacitatea mai mica de 3 paturi
*/
DELETE FROM SALOANE
WHERE capacitate < 3 AND id_departament = (SELECT id_departament FROM DEPARTAMENTE WHERE nume_departament = 'Pediatrie');

/*
Toti pacientii internati momentan in salonul 'C-101' trebuie mutati in salonul 'C-102' din cauza unei
defectiuni tehnice la instalatia electrica a primului salon
*/
UPDATE INTERNARI
SET id_salon = (SELECT id_salon FROM SALOANE WHERE cod_salon = 'C-102')
WHERE data_externare IS NULL AND id_salon = (SELECT id_salon FROM SALOANE WHERE cod_salon = 'C-101');

/*
Departamentul care are cele mai multe internari inregistrate in total trebuie sa fie mutat
in locatia 'Aripa VIP' pentru a premia performanta
*/
UPDATE DEPARTAMENTE
SET locatie = 'Aripa VIP'
WHERE id_departament = (
SELECT id_departament
FROM ( SELECT s.id_departament, COUNT(*) as nr_internari
 FROM INTERNARI i, SALOANE s
 WHERE i.id_salon = s.id_salon
 GROUP BY s.id_departament
 ORDER BY nr_internari DESC
)
WHERE ROWNUM = 1
);

/*
Sa se stearga medicii incepatori care sunt in anul 1 de rezidentiat,
dar nu au efectuat nicio consultatie pana in prezent
*/
DELETE FROM MEDICI_INCEPATORI m
WHERE an_rezidentiat = 1 AND NOT EXISTS (SELECT 1 FROM CONSULTATII c WHERE c.id_med_incepator = m.id_incepator);

/*
Sa se actualizeze numele si prenumele tuturor pacientilor astfel incat sa fie scrise cu majuscule,
dar doar pentru cei care locuiesc in Bucuresti
*/
UPDATE PACIENTI
SET nume_pacient = UPPER(nume_pacient), prenume_pacient = UPPER(prenume_pacient)
WHERE UPPER(adresa_domiciliu) LIKE '%BUCURESTI%';

/*
Sa se stearga internarile care au data de externare anterioara datei de internare,
acestea fiind considerate erori de operare
*/
DELETE FROM INTERNARI
WHERE data_externare IS NOT NULL AND data_externare < data_internare;


/*
Sa se creeze o secventa pentru generarea automata a ID-urilor,
pornind de la valoarea 1000
*/
CREATE SEQUENCE seq_pacienti
START WITH 1000
INCREMENT BY 1;

/*
Sa se creeze un index pentru optimizarea cautarilor
dupa numele pacientului
*/  
CREATE INDEX idx_nume_pacient ON PACIENTI(nume_pacient);

/*
Sa se creeze un tabel virtual (View) care sa afiseze
doar detaliile despre medicii cardiologi
*/
CREATE OR REPLACE VIEW v_medici_cardiologi AS
SELECT s.nume_senior, s.prenume_senior, s.grad_profesional
FROM MEDICI_SENIORI s, DEPARTAMENTE d
WHERE s.id_departament = d.id_departament AND d.nume_departament = 'Cardiologie';

/*
Sa se creeze un sinonim public pentru tabela de internari
*/
CREATE PUBLIC SYNONYM spital_internari FOR INTERNARI;

/*
Sa se elaboreze un raport de mentorat care sa prezinte toti medicii seniori
alaturi de rezidentii coordonati, specificand 'Fara rezident' unde este cazul
*/
SELECT s.nume_senior || ' ' || s.prenume_senior AS Mentor, 
       NVL(i.nume_incepator || ' ' || i.prenume_incepator, 'Fara rezident') AS Rezident
FROM MEDICI_SENIORI s, MEDICI_INCEPATORI i
WHERE s.id_senior = i.id_senior_mentor(+);

/*
Sa se determine departamentele care gestioneaza un numar de saloane mai mare de 2,
afisand capacitatea totala de cazare a acestora
*/
SELECT d.nume_departament, COUNT(s.id_salon) AS nr_saloane, SUM(s.capacitate) AS total_paturi
FROM DEPARTAMENTE d, SALOANE s
WHERE d.id_departament = s.id_departament
GROUP BY d.nume_departament
HAVING COUNT(s.id_salon) > 2;

/*
Sa se afiseze pacientii care au avut consultatii intr-un interval specific,
folosind conversia TO_DATE si operatorul BETWEEN
*/
SELECT p.nume_pacient, p.prenume_pacient, c.data_consultatie
FROM PACIENTI p, CONSULTATII c
WHERE p.id_pacient = c.id_pacient
AND c.data_consultatie BETWEEN TO_DATE('01-01-2023', 'DD-MM-YYYY') AND SYSDATE;

/*
Sa se selecteze medicii incepatori al caror nume incepe cu litera 'A' sau 'B',
folosind operatorul LIKE
*/
SELECT nume_incepator, prenume_incepator
FROM MEDICI_INCEPATORI
WHERE nume_incepator LIKE 'A%' OR nume_incepator LIKE 'B%';

/*
Sa se categoriseasca pacientii in functie de varsta ('Minor', 'Adult', 'Senior'),
folosind functia CASE si data nasterii
*/
SELECT nume_pacient, 
       CASE 
           WHEN (EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM data_nasterii)) < 18 THEN 'Minor'
           WHEN (EXTRACT(YEAR FROM SYSDATE) - EXTRACT(YEAR FROM data_nasterii)) BETWEEN 18 AND 65 THEN 'Adult'
           ELSE 'Senior'
       END AS categorie_varsta
FROM PACIENTI;

/*
Sa se afiseze detaliile despre internarile curente (nedeterminate),
incluzand numele pacientului si codul salonului
*/
SELECT p.nume_pacient, s.cod_salon, i.data_internare
FROM INTERNARI i, PACIENTI p, SALOANE s
WHERE i.id_pacient = p.id_pacient 
AND i.id_salon = s.id_salon AND i.data_externare IS NULL;

/*
Sa se afiseze gradul profesional al medicilor seniori in format complet
(ex: 'Medic Primar'), folosind functia DECODE
*/
SELECT nume_senior, DECODE(grad_profesional, 'Primar', 'Medic Primar',
'Specialist', 'Medic Specialist', 'Necunoscut') AS grad_complet
FROM MEDICI_SENIORI;

/*
Sa se calculeze numarul de zile trecute de la ultima consultatie
pentru fiecare pacient, folosind functia TRUNC si SYSDATE
*/
SELECT p.nume_pacient, TRUNC(SYSDATE - c.data_consultatie) AS zile_trecute
FROM CONSULTATII c, PACIENTI p
WHERE c.id_pacient = p.id_pacient;

/*
Sa se determine pacientii care au fost internati, dar care nu au avut
nicio consultatie inregistrata (utilizand MINUS)
*/
SELECT id_pacient, nume_pacient FROM PACIENTI 
WHERE id_pacient IN (SELECT id_pacient FROM INTERNARI)
MINUS
SELECT id_pacient, nume_pacient FROM PACIENTI 
WHERE id_pacient IN (SELECT id_pacient FROM CONSULTATII);

/*
Sa se afiseze pacientii si medicii intr-o singura lista comuna
pentru un raport de contacte (utilizand UNION)
*/
SELECT nume_pacient || ' ' || prenume_pacient AS persoana, 'Pacient' AS tip FROM PACIENTI
UNION
SELECT nume_senior || ' ' || prenume_senior, 'Medic Senior' FROM MEDICI_SENIORI;

/*
Sa se afiseze numele departamentului si cea mai veche data de internare
inregistrata in cadrul acelui departament
*/
SELECT d.nume_departament, MIN(i.data_internare) AS prima_internare
FROM DEPARTAMENTE d, SALOANE s, INTERNARI i
WHERE d.id_departament = s.id_departament AND s.id_salon = i.id_salon
GROUP BY d.nume_departament;

/*
Sa se selecteze medicii seniori care apartin departamentului 'Cardiologie',
folosind o subcerere simpla
*/
SELECT nume_senior, specializare_senior
FROM MEDICI_SENIORI
WHERE id_departament = (SELECT id_departament FROM DEPARTAMENTE 
                        WHERE nume_departament = 'Cardiologie');

/*
Sa se afiseze saloanele care au o capacitate mai mare decat
media capacitatii tuturor saloanelor din spital
*/
SELECT cod_salon, capacitate
FROM SALOANE
WHERE capacitate > (SELECT AVG(capacitate) FROM SALOANE);

/*
Sa se determine medicii seniori care au cel putin un medic rezident in subordine,
folosind operatorul EXISTS
*/
SELECT nume_senior, prenume_senior
FROM MEDICI_SENIORI s
WHERE EXISTS (SELECT 1 FROM MEDICI_INCEPATORI i WHERE i.id_senior_mentor = s.id_senior);

/*
Sa se formateze data de nastere a pacientilor in formatul 'Ziua, Zi-Luna-An',
folosind functia TO_CHAR
*/
SELECT nume_pacient, TO_CHAR(data_nasterii, 'Day, DD-Month-YYYY') AS data_formatata
FROM PACIENTI;

/*
Sa se mascheze CNP-ul pacientilor pentru protectia datelor,
afisand doar ultimele 4 cifre
*/
SELECT nume_pacient, RPAD('*', LENGTH(cnp)-4, '*') || SUBSTR(cnp, -4) AS cnp_mascat
FROM PACIENTI;

/*
Sa se afiseze ierarhia medicilor (Mentori -> Rezidenti),
folosind cereri ierarhice (CONNECT BY)
*/
SELECT LEVEL, SYS_CONNECT_BY_PATH(nume, '/') AS cale_ierarhica
FROM (
    SELECT id_senior AS id, NULL AS parent_id, nume_senior AS nume FROM MEDICI_SENIORI
    UNION ALL
    SELECT id_incepator + 1000 AS id, id_senior_mentor AS parent_id, nume_incepator AS nume 
    FROM MEDICI_INCEPATORI
)
START WITH parent_id IS NULL
CONNECT BY PRIOR id = parent_id;

/*
Sa se afiseze departamentele care nu au niciun salon alocat,
folosind o jonctiune externa
*/
SELECT d.nume_departament
FROM DEPARTAMENTE d, SALOANE s
WHERE d.id_departament = s.id_departament(+)
AND s.id_salon IS NULL;

/*
Sa se calculeze numarul total de consultatii efectuate de fiecare medic incepator,
inclusiv pentru cei care nu au consultatii
*/
SELECT m.nume_incepator, COUNT(c.id_consultatie) AS nr_consultatii
FROM MEDICI_INCEPATORI m, CONSULTATII c
WHERE m.id_incepator = c.id_med_incepator(+)
GROUP BY m.nume_incepator;

/*
Sa se selecteze pacientii care au atat internari cat si consultatii inregistrate,
folosind operatorul INTERSECT
*/
SELECT id_pacient, nume_pacient FROM PACIENTI JOIN INTERNARI USING(id_pacient)
INTERSECT
SELECT id_pacient, nume_pacient FROM PACIENTI JOIN CONSULTATII USING(id_pacient);

/*
Sa se afiseze numele complet al pacientului si luna nasterii,
folosind concatenare si TO_CHAR
*/
SELECT nume_pacient || ' ' || prenume_pacient AS nume_complet, TO_CHAR(data_nasterii, 'Month') AS luna_nasterii
FROM PACIENTI;

/*
Sa se determine salonul cu cele mai multe paturi ocupate,
folosind o subcerere in clauza WHERE
*/
SELECT cod_salon, paturi_ocupate
FROM SALOANE
WHERE paturi_ocupate = (SELECT MAX(paturi_ocupate) FROM SALOANE);

/*
Sa se utilizeze view-ul creat anterior pentru a afisa
toti medicii cardiologi
*/
SELECT * FROM v_medici_cardiologi;