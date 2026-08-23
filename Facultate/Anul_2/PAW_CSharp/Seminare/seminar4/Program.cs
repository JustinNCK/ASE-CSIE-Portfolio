
Console.WriteLine("Seminar 4\n\n");

//int n1 = 11;
//int n2 = 22;

//Console.WriteLine($"Inainte de swap - n1 = {n1} n2 = {n2}");
////Console.WriteLine("Inainte de swap - n1 = " + n1 + " n2 = " + n2);
//interschimbare(n1, n2);
//unsafe
//{
//    interschimbare_p(&n1, &n2);
//}
//interschimbare_r(ref n1, ref n2);
//Console.WriteLine($"Dupa swap - n1 = {n1} n2 = {n2}");

//void interschimbare(int n1, int n2)
//{
//    int x = n1;
//    n1 = n2;
//    n2 = x;
//}
//unsafe void interschimbare_p(int* n1, int* n2)
//{
//    int x = *n1;
//    *n1 = *n2;
//    *n2 = x;
//}

//int interschimbare_r(ref int n1, ref int n2){
//    int x = n1;
//    n1 = n2;
//    n2 = x;
//}


//Persoana p = new Persoana();
//p.Afiseaza();

Angajat a = new Angajat(); 
a.Afiseaza();
a.Detalii();
a.CNP();
a.Salariu();

Manager m = new Manager();
m.Afiseaza();
m.Detalii();
m.CNP();
m.Salariu();