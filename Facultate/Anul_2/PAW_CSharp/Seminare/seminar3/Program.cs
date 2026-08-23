using System.Data.SqlTypes;

Console.WriteLine("Seminar 3\n\n");

Persoana p1 = new Persoana();
Console.WriteLine(p1);

Persoana p2 = new Persoana("Ionescu", 20);
Console.WriteLine(p2); 

Persoana p3 = (Persoana)p2.Clone();
p3.Nume = "Popescu";
p3.Varsta = 23;
Console.WriteLine(p3);

Persoana p4 = new Persoana("Georgescu", 44);
Console.WriteLine(p4);

List<Persoana> listaPersoane = new List<Persoana>();
listaPersoane.Add(p4);
listaPersoane.AddRange(new Persoana[] { p2, p1, p3 });

Console.WriteLine("\n\nList de persoane contine...");
foreach (Persoana p in listaPersoane)
    Console.WriteLine(p);

//ordonam continutul listei
Console.WriteLine("\n\nLista ORDONATA de persoane contine...");
listaPersoane.Sort();
foreach (Persoana p in listaPersoane)
    Console.WriteLine(p);

Console.WriteLine("\n\nStudenti...");
Student s1 = new Student();
s1.Nume = "Mihaiescu";
s1.Varsta = 33;
s1.NoteV = new int[] { 10, 9, 8, 7 };
s1.NoteL = new List<int> { 9, 8, 8, 7, 7 };
Console.WriteLine(s1);

Student s2 = (Student)s1.Clone();
s2.NoteV[1] = 4;
Console.WriteLine(s2);
s1.medie();
s2.medie();

Console.WriteLine(s1.StudentPromovat());
s1.NoteV[0] = 1;
s1.NoteV[1] = 3;
Console.WriteLine(s1.StudentPromovat());

p1.AfiseazaTipObiect();
s2.AfiseazaTipObiect();