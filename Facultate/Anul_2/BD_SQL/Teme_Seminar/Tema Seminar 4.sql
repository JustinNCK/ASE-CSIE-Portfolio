-- 1
create table Dep (
    ID number(7) primary key,
    Denumire VARCHAR2(25)
);
-- 2
insert into Dep (ID, Denumire)
select id_department, denumire_departament
from Departamente;

select * from Departamente;

-- 3
create table Ang (
    ID NUMBER(7) primary key,
    Prenume varchar2(25),
    Nume varchar2(25),
    Dep_ID number(7) references Dep(ID)
);

-- 4
alter table Ang 
add Varsta number(2);

-- 5
alter table Ang 
add constraint Verifica_varsta check (Varsta between 18 and 65);

-- 6
alter table Ang 
disable constraint Verifica_varsta;

-- 7
alter table Ang 
modify Nume varchar2(30);

-- 8
rename Ang to Ang2;

-- 9
create table Salariati as 
select * from Angajati;

-- 10
insert into Salariati values (
    1, 'Steven', 'Kong', 'SKONG', '515.123.4567', to_date('17-06-1987', 'DD-MM-YYYY'), 'AD_PRES', 24000, 0.1, NULL,  90
);

insert into Salariati values (
    2, 'Neena', 'Koch', 'NKOCH', '515.123.4568', to_date('21-09-1989', 'DD-MM-YYYY'), 'AD_VP', 17000, 0.1,  100, 90
);

insert into Salariati values (
    3, 'Lex', 'Haan', 'LHAAN', '515.123.4569', to_date('13-01-1993', 'DD-MM-YYYY'), 'AD_VP', 17000, 0.2, 100, 90
);

-- 11
update Salariati
set prenume = 'John'
where id_angajat = 3;

-- 12
update Salariati
set email = 'JHAAN'
where id_angajat = 3;

-- 13
update Salariati
set salariul = salariul * 1.10
where salariul < 20000;

-- 14
update Salariati
set id_functie = 'AD_PRES'
where id_angajat = 2;

-- 15
update Salariati
set comision = (select comision from Salariati where id_angajat = 3)
WHERE id_angajat = 2;

-- 16
delete from Salariati
where id_angajat = 1;