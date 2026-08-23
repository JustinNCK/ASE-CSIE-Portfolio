/*
Cerinta
Sa se creeze dinamic o tabela numita STATISTICI_MEDICI_HI.
Sa se parcurga toti medicii incepatori folosind un cursor
implicit inclus intr-o structura repetitiva de tip FOR,
formatand numele lor cu majuscule (utilizand o functie la
nivel de rand). Pentru fiecare medic, sa se calculeze numarul
total de consultatii efectuate (utilizand o functie de grup).
Daca numarul de consultatii este mai mare decat 0, medicul
primeste statusul 'Activ', altfel primeste 'Inactiv' (utilizand
o structura alternativa). Datele obtinute se vor insera dinamic
in noua tabela creata folosind comenzi LMD lansate prin EXECUTE IMMEDIATE.

Rezolvare
*/

set serveroutput on

DECLARE
    v_comanda_ldd VARCHAR2(200);
    v_comanda_lmd VARCHAR2(200);
    v_nr_consultatii NUMBER;
    v_status VARCHAR2(20);

BEGIN
    BEGIN
        EXECUTE IMMEDIATE 'DROP TABLE STATISTICI_MEDICI_HI';
    EXCEPTION
        WHEN OTHERS THEN NULL;
    END;

    v_comanda_ldd := 'CREATE TABLE STATISTICI_MEDICI_HI (nume_medic VARCHAR2(100), nr_cons NUMBER, status VARCHAR2(20))';
    EXECUTE IMMEDIATE v_comanda_ldd;

    FOR rec IN (
        SELECT id_incepator, UPPER(nume_incepator) || ' ' || UPPER(prenume_incepator) AS nume_complet 
        FROM MEDICI_INCEPATORI_HI
    ) 
    LOOP
        SELECT COUNT(id_consultatie) INTO v_nr_consultatii
        FROM CONSULTATII_HI
        WHERE id_med_incepator = rec.id_incepator;

        IF v_nr_consultatii > 0 THEN
            v_status := 'Activ';
        ELSE
            v_status := 'Inactiv';
        END IF;

        v_comanda_lmd := 'INSERT INTO STATISTICI_MEDICI_HI VALUES (''' || rec.nume_complet || ''', ' || v_nr_consultatii || ', ''' || v_status || ''')';
        EXECUTE IMMEDIATE v_comanda_lmd;
    END LOOP;
    
    DBMS_OUTPUT.PUT_LINE('Tabela STATISTICI_MEDICI_HI a fost creata si populata cu succes!');
    DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/

select * from STATISTICI_MEDICI_HI;

/*
Cerinta
Sa se declare trei colectii de date diferite: un tablou
indexat (index by table) pentru stocarea numelui complet
al pacientilor, un tablou imbricat (nested table) pentru
denumirile departamentelor si un vector de lungime variabila
(varray) pentru numele medicilor seniori. Sa se populeze
aceste colectii cu primele 3 inregistrari din tabelele
corespunzatoare utilizand operatii de tip BULK COLLECT.
La final, sa se parcurga fiecare colectie si sa se afiseze
continutul pe ecran.

Rezolvare
*/
set serveroutput on

DECLARE
    TYPE t_idx_pacienti IS TABLE OF VARCHAR2(100) INDEX BY PLS_INTEGER;
    v_pacienti t_idx_pacienti;

    TYPE t_nst_departamente IS TABLE OF VARCHAR2(100);
    v_departamente t_nst_departamente;

    TYPE t_vry_medici IS VARRAY(10) OF VARCHAR2(100);
    v_medici t_vry_medici;

BEGIN
    SELECT nume_pacient || ' ' || prenume_pacient BULK COLLECT INTO v_pacienti
    FROM PACIENTI_HI WHERE ROWNUM <= 3;

    DBMS_OUTPUT.PUT_LINE('--- COLECTIA 1: INDEX BY TABLE (Pacienti) ---');
    FOR i IN v_pacienti.FIRST .. v_pacienti.LAST LOOP
        IF v_pacienti.EXISTS(i) THEN DBMS_OUTPUT.PUT_LINE('Pacient ' || i || ': ' || v_pacienti(i)); END IF;
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(' ');

    SELECT nume_departament BULK COLLECT INTO v_departamente
    FROM DEPARTAMENTE_HI WHERE ROWNUM <= 3;

    DBMS_OUTPUT.PUT_LINE('--- COLECTIA 2: NESTED TABLE (Departamente) ---');
    FOR i IN 1 .. v_departamente.COUNT LOOP
        DBMS_OUTPUT.PUT_LINE('Departament ' || i || ': ' || v_departamente(i));
    END LOOP;
    DBMS_OUTPUT.PUT_LINE(' ');

    SELECT nume_senior BULK COLLECT INTO v_medici
    FROM MEDICI_SENIORI_HI WHERE ROWNUM <= 3;

    DBMS_OUTPUT.PUT_LINE('--- COLECTIA 3: VARRAY (Medici Seniori) ---');
    FOR i IN 1 .. v_medici.COUNT LOOP
        DBMS_OUTPUT.PUT_LINE('Medic ' || i || ': ' || v_medici(i));
    END LOOP;

    DBMS_OUTPUT.PUT_LINE('---------------------------------------------');
    DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/

/*
Cerinta
Sa se construiasca un bloc PL/SQL care preia un ID de pacient
prin intermediul unei variabile de substitutie. Blocul va verifica
si trata urmatoarele posibile erori: id negativ (exceptie explicita),
impartire la zero (ZERO_DIVIDE), prea multe randuri returnate (TOO_MANY_ROWS),
pacient inexistent (NO_DATA_FOUND) si pacient fara consultatii
(exceptie explicita). Toate aceste 5 exceptii vor fi tratate in
sectiunea dedicata a blocului.

Rezolvare
*/
set serveroutput on

DECLARE
    v_id_pacient NUMBER := &p_id;
    v_nume_pacient PACIENTI_HI.nume_pacient%TYPE;
    v_nr_consultatii NUMBER;
    v_test_calcul NUMBER;

    e_id_negativ EXCEPTION;
    e_fara_consultatii EXCEPTION;

BEGIN
    IF v_id_pacient < 0 THEN RAISE e_id_negativ; END IF;
    IF v_id_pacient = 0 THEN v_test_calcul := 100 / v_id_pacient; END IF;

    IF v_id_pacient = 9999 THEN
        SELECT nume_pacient INTO v_nume_pacient FROM PACIENTI_HI; 
    END IF;

    SELECT nume_pacient INTO v_nume_pacient FROM PACIENTI_HI WHERE id_pacient = v_id_pacient;

    SELECT COUNT(id_consultatie) INTO v_nr_consultatii FROM CONSULTATII_HI WHERE id_pacient = v_id_pacient;

    IF v_nr_consultatii = 0 THEN RAISE e_fara_consultatii; END IF;

    DBMS_OUTPUT.PUT_LINE('Pacientul ' || v_nume_pacient || ' procesat cu succes (' || v_nr_consultatii || ' consultatii).');
    DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');

EXCEPTION
    WHEN NO_DATA_FOUND THEN
        DBMS_OUTPUT.PUT_LINE('Eroare Implicita: Nu a fost gasit niciun pacient cu id-ul introdus.');
        DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');
    WHEN TOO_MANY_ROWS THEN
        DBMS_OUTPUT.PUT_LINE('Eroare Implicita: Interogarea a returnat prea multe randuri.');
        DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');
    WHEN ZERO_DIVIDE THEN
        DBMS_OUTPUT.PUT_LINE('Eroare Implicita: S-a incercat o impartire la zero (ID=0).');
        DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');
    WHEN e_id_negativ THEN
        DBMS_OUTPUT.PUT_LINE('Eroare Explicita: ID-ul pacientului nu poate sa fie un numar negativ.');
        DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');
    WHEN e_fara_consultatii THEN
        DBMS_OUTPUT.PUT_LINE('Eroare Explicita: Pacientul gasit nu are nicio consultatie.');
        DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE('Eroare neprevazuta: ' || SQLERRM);
END;
/

/*
Cerinta
Sa se scrie un bloc PL/SQL in care sa se actualizeze numarul de paturi
ocupate din salonul cu codul '101' si sa se verifice numarul de inregistrari
afectate folosind atributele unui cursor implicit. Apoi, folosind un cursor
explicit fara parametri, sa se parcurga toate departamentele spitalului.
Pentru fiecare departament parcurs, sa se afiseze medicii seniori arondati
acestuia, utilizand un al doilea cursor explicit, de data aceasta cu parametru
care primeste ID-ul departamentului curent.

Rezolvare
*/
set serveroutput on

DECLARE
    CURSOR c_departamente IS
        SELECT id_departament, nume_departament 
        FROM DEPARTAMENTE_HI ORDER BY id_departament;

    CURSOR c_medici(p_id_dept NUMBER) IS
        SELECT nume_senior, prenume_senior 
        FROM MEDICI_SENIORI_HI WHERE id_departament = p_id_dept;
        
    v_linii_afectate NUMBER;

BEGIN
    UPDATE SALOANE_HI SET paturi_ocupate = paturi_ocupate + 1 WHERE id_salon = 101;
    v_linii_afectate := SQL%ROWCOUNT;
    
    IF v_linii_afectate > 0 THEN
        DBMS_OUTPUT.PUT_LINE('Cursor implicit: S-au actualizat ' || v_linii_afectate || ' saloane.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Cursor implicit: Nu s-a gasit salonul.');
    END IF;

    DBMS_OUTPUT.PUT_LINE('--- LISTA MEDICI PE DEPARTAMENTE ---');
    FOR v_dept IN c_departamente LOOP
        DBMS_OUTPUT.PUT_LINE('Departamentul ' || v_dept.id_departament || ': ' || v_dept.nume_departament);
        FOR v_medic IN c_medici(v_dept.id_departament) LOOP
            DBMS_OUTPUT.PUT_LINE('   -> Medic Senior: ' || v_medic.nume_senior || ' ' || v_medic.prenume_senior);
        END LOOP;
    END LOOP;
    
    ROLLBACK;
    DBMS_OUTPUT.PUT_LINE('---------------------------------------------');
    DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/

/*
Cerinta
Sa se creeze in mod independent 3 proceduri stocate si 3 functii
stocate, care opereaza pe tabelele bazei de date. Separat, sa se
construiasca un pachet PACHET_SPITAL_HI care sa includa alte 2
subprograme (o procedura pentru stergerea unei consultatii si o functie
pentru calculul capacitatii totale a unui departament). La final, se va
utiliza un bloc anonim pentru a testa cateva dintre aceste subprograme
si a demonstra functionalitatea lor.

Rezolvare
*/
set serveroutput on

CREATE OR REPLACE PROCEDURE p_adauga_departament(p_id NUMBER, p_nume VARCHAR2, p_locatie VARCHAR2) IS
BEGIN
    INSERT INTO DEPARTAMENTE_HI (id_departament, nume_departament, locatie) VALUES (p_id, p_nume, p_locatie);
END;
/

CREATE OR REPLACE PROCEDURE p_modifica_capacitate(p_id_salon NUMBER, p_capacitate_noua NUMBER) IS
BEGIN
    UPDATE SALOANE_HI SET capacitate = p_capacitate_noua WHERE id_salon = p_id_salon;
END;
/

CREATE OR REPLACE PROCEDURE p_modifica_diagnostic(p_id_cons NUMBER, p_diagnostic VARCHAR2) IS
BEGIN
    UPDATE CONSULTATII_HI SET diagnostic_preliminar = p_diagnostic WHERE id_consultatie = p_id_cons;
END;
/

CREATE OR REPLACE FUNCTION f_get_nr_consultatii(p_id_pacient NUMBER) RETURN NUMBER IS
    v_nr NUMBER;
BEGIN
    SELECT COUNT(id_consultatie) INTO v_nr FROM CONSULTATII_HI WHERE id_pacient = p_id_pacient;
    RETURN v_nr;
END;
/

CREATE OR REPLACE FUNCTION f_locuri_disponibile(p_id_salon NUMBER) RETURN NUMBER IS
    v_locuri NUMBER;
BEGIN
    SELECT capacitate - paturi_ocupate INTO v_locuri FROM SALOANE_HI WHERE id_salon = p_id_salon;
    RETURN NVL(v_locuri, -1);
END;
/

CREATE OR REPLACE FUNCTION f_get_nume_medic(p_id_senior NUMBER) RETURN VARCHAR2 IS
    v_nume_complet VARCHAR2(100);
BEGIN
    SELECT nume_senior || ' ' || prenume_senior INTO v_nume_complet FROM MEDICI_SENIORI_HI WHERE id_senior = p_id_senior;
    RETURN v_nume_complet;
EXCEPTION
    WHEN NO_DATA_FOUND THEN RETURN 'Medic Inexistent';
END;
/

CREATE OR REPLACE PACKAGE pachet_spital_hi IS
    PROCEDURE sterge_consultatie(p_id_cons NUMBER);
    FUNCTION total_capacitate_dept(p_id_dept NUMBER) RETURN NUMBER;
END pachet_spital_hi;
/

CREATE OR REPLACE PACKAGE BODY pachet_spital_hi IS
    PROCEDURE sterge_consultatie(p_id_cons NUMBER) IS
    BEGIN
        DELETE FROM CONSULTATII_HI WHERE id_consultatie = p_id_cons;
    END sterge_consultatie;

    FUNCTION total_capacitate_dept(p_id_dept NUMBER) RETURN NUMBER IS
        v_total NUMBER;
    BEGIN
        SELECT SUM(capacitate) INTO v_total FROM SALOANE_HI WHERE id_departament = p_id_dept;
        RETURN NVL(v_total, 0);
    END total_capacitate_dept;
END pachet_spital_hi;
/

DECLARE
    v_nr_cons NUMBER;
    v_capacitate_totala NUMBER;

BEGIN
    p_modifica_capacitate(101, 15);
    v_nr_cons := f_get_nr_consultatii(1);
    
    v_capacitate_totala := pachet_spital_hi.total_capacitate_dept(10);
    
    DBMS_OUTPUT.PUT_LINE('--- REZULTATE TESTARE ---');
    DBMS_OUTPUT.PUT_LINE('Pacientul 1 are ' || v_nr_cons || ' consultatii.');
    DBMS_OUTPUT.PUT_LINE('Departamentul 10 are capacitatea totala: ' || v_capacitate_totala);
    DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');
    
    ROLLBACK;

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/

/*
Cerinta
Sa se implementeze 4 declansatori (triggeri) pentru a asigura
integritatea si securitatea bazei de date a spitalului: 2 la
nivel de rand (pentru verificarea capacitatii salonului si
logicii datelor de externare) si 2 la nivel de instructiune
(pentru programul de lucru si blocarea stergerii pacientilor
din baza de date). La final, se va utiliza un bloc anonim pentru
a testa functionarea declansatorilor.

Rezolvare
*/
set serveroutput on

CREATE OR REPLACE TRIGGER trg_verif_capacitate
BEFORE UPDATE ON SALOANE_HI
FOR EACH ROW
BEGIN
    IF :NEW.paturi_ocupate > :OLD.capacitate THEN
        RAISE_APPLICATION_ERROR(-20001, 'Eroare: Paturile ocupate nu pot depasi capacitatea!');
    END IF;
END;
/

CREATE OR REPLACE TRIGGER trg_verif_externare
BEFORE INSERT OR UPDATE ON INTERNARI_HI
FOR EACH ROW
BEGIN
    IF :NEW.data_externare IS NOT NULL AND :NEW.data_externare < :NEW.data_internare THEN
        RAISE_APPLICATION_ERROR(-20002, 'Eroare: Data externarii nu poate fi anterioara!');
    END IF;
END;
/

CREATE OR REPLACE TRIGGER trg_program_spital
BEFORE INSERT OR UPDATE OR DELETE ON CONSULTATII_HI
BEGIN
    IF TO_CHAR(SYSDATE, 'HH24') < '08' OR TO_CHAR(SYSDATE, 'HH24') >= '20' THEN
        RAISE_APPLICATION_ERROR(-20003, 'Eroare: Modificari permise doar intre 08:00 - 20:00!');
    END IF;
END;
/

CREATE OR REPLACE TRIGGER trg_protectie_pacienti
BEFORE DELETE ON PACIENTI_HI
BEGIN
    RAISE_APPLICATION_ERROR(-20004, 'Eroare: Este strict interzisa stergerea fizica a pacientilor!');
END;
/

DECLARE
    v_mesaj_eroare VARCHAR2(500);

BEGIN
    DBMS_OUTPUT.PUT_LINE('--- TESTARE FUNCTIONARE TRIGGERI ---');
    
    BEGIN
        UPDATE SALOANE_HI SET paturi_ocupate = 100 WHERE id_salon = 101;
    EXCEPTION
        WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE('Test trg_verif_capacitate -> ' || SQLERRM);
    END;

    BEGIN
        DELETE FROM PACIENTI_HI WHERE id_pacient = 1;
    EXCEPTION
        WHEN OTHERS THEN DBMS_OUTPUT.PUT_LINE('Test trg_protectie_pacienti -> ' || SQLERRM);
    END;

    DBMS_OUTPUT.PUT_LINE('---------------------------------------------');
    DBMS_OUTPUT.PUT_LINE('Rezolvat de Hetac Iustin');

EXCEPTION
    WHEN OTHERS THEN
        DBMS_OUTPUT.PUT_LINE(SQLERRM);
END;
/