Console.WriteLine("Seminar 1 - introductiv");

//Console.WriteLine("Introduceti un nume:");
//string Nume = Console.ReadLine();
//Console.WriteLine("Introduceti o varsta:");
//int Varsta = Convert.ToInt32(Console.ReadLine());
//Console.WriteLine("Ati introdus " + Nume + " cu varsta " + Varsta);
//Console.WriteLine("Ati introdus {0} cu varsta {1}", Nume, Varsta);
//Console.WriteLine($"Ati introdus {Nume} cu varsta {Varsta}");


//// vectori
//int[] vector1 = { 11, 22, 33, 44 };
//int[] vector2 = new int[4] { 21, 22, 23, 24 };
//int[] vector3;
//vector3 = new int[5] { 51, 52, 53, 54, 55 };

//for(int i = 0; i < vector1.Length; i++)
//    Console.Write(vector1[i] + " ");
//Console.WriteLine();

//foreach(int element in vector1)
//    Console.Write(element + " ");
//Console.WriteLine();


//// mutabilitate - poate fi schimbat
//int[] vector1 = { 11, 22, 33, 44 };
//int[] vector2 = vector1;
//vector1[2] = 99;

//Console.WriteLine("\nV1 | V2\n--------");
//for(int i = 0; i < vector1.Length; i++)
//    Console.WriteLine($"{vector1[i]} | {vector2[i]}");

//// imutabilitate
//// compiere

//int[] vector3 = new int[vector1.Length];
//for(int i = 0; i < vector1.Length;i++)
//    vector3[i] = vector1[i];

//vector1[2] = 77;

//Console.WriteLine("\nV1 | V2\n--------");
//for (int i = 0; i < vector1.Length; i++)
//    Console.WriteLine($"{vector1[i]} | {vector3[i]}");


//// clonare
//int[] vector4 = (int[])vector1.Clone();
//vector1[0] = 66;

//Console.WriteLine("\nV1 | V2\n--------");
//for (int i = 0; i < vector1.Length; i++)
//    Console.WriteLine($"{vector1[i]} | {vector4[i]}");


//// matrice - dreptunghiulara
//int[,] matrice1 = new int[3, 4] { { 11, 12, 13, 14 }, { 21, 22, 23, 24 }, { 31, 32, 33, 34 } };

//for (int i = 0; i < matrice1.GetLength(0); i++){
//    for (int j = 0; j < matrice1.GetLength(1); j++)
//        Console.Write(matrice1[i, j] + " ");
//    Console.WriteLine();
//}


//// matrice in zig-zag
//int[][] matrice2 = new int[3][];
//matrice2[0] = new int[4] { 11, 22, 33, 44 };
//matrice2[1] = new int[2] { 55, 66 };
//matrice2[2] = new int[3] { 77, 88, 99 };

//for (int i = 0; i < matrice2.Length; i++){
//    for (int j = 0; j < matrice2[i].Length; j++)
//        Console.Write(matrice2[i][j] + " ");
//    Console.WriteLine();
//}

//// lista
//List<int> lista_numere = new List<int>();
//lista_numere.Add(555);
//lista_numere.Add(111);
//lista_numere.Add(999);
//lista_numere.Add(777);
//lista_numere.Add(333);

//lista_numere.Sort();
//lista_numere.Reverse();

//foreach (int V in lista_numere)
//    Console.WriteLine(V);

int n1 = 11;
int n2 = 22;
Console.WriteLine("Inainte de swap - " + n1 + " " + n2);
swap(n1, n2);
Console.WriteLine("Dupa swap - " + n1 + " " + n2);

void swap(int n1, int n2)
{
    int x = n1;
    n1 = n2;
    n2 = x;
    Console.WriteLine("In swap - " + n1 + " " + n2);
}
