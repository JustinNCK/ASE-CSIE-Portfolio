namespace Proiect
{

    //Pentru ca testarea sa functioneze tot codul din Testare_functii_clase.cs trebuie comentat
    //mai trebuie schimbat din  Solution Explorer -> Properties  -> Application -> Output type -> Windows Application
    //aceasta modificare este necesara ca aplicatia sa functioneze
    internal static class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());



        }
    }
}