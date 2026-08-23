Console.WriteLine("Seminar 2\n\n");

Persoana p1 = new Persoana();
p1.id = 11;
p1.Nume = "Ionescu";
//p1.SetNume("Ionescu");
//Console.WriteLine(p1.id + " " + p1.Nume + " ");
Console.WriteLine(p1);

Persoana p2 = new Persoana(22, "Popescu", 22);
Console.WriteLine(p2);

Persoana p3 = p2;
p3.id = 33;
p3.Nume = "Georgescu";
Console.WriteLine("P2 --> " + p2);
Console.WriteLine("P3 --> " + p3);

Persoana p4 = new Persoana(p3);
p4.id = 44;
Console.WriteLine("P3 --> " + p3);
Console.WriteLine("P4 --> " + p4);

Persoana p5 = (Persoana)p4.Clone();
p5.id = 55;
Console.WriteLine("P4 --> " + p4);
Console.WriteLine("P5 --> " + p5);


// vector de persoane
Console.WriteLine("\n\n\nVector Persoane");
Persoana[] vec_pers = new Persoana[] { p3, p1, p5, p2, p4 };
foreach (Persoana p in vec_pers)
    Console.WriteLine(p);
// ordonare persoane dupa id
Array.Sort(vec_pers);
Console.WriteLine("Vector ordonat");
foreach (Persoana p in vec_pers)
    Console.WriteLine(p);

// Student
Console.WriteLine("\n\nStudent");
Student s1 = new Student();
Console.WriteLine(s1);

s1 = s1 + 0.5f;
Console.WriteLine(s1);
s1 = 1.75f + s1;
Console.WriteLine(s1);
s1 += 2.15f;
Console.WriteLine(s1);