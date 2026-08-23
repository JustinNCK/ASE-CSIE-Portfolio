using Proiect_gestiuneVanzari;

namespace Proiect
{
    internal class Client : Persoana, ICloneable, IComparable
    {
        private int idClient;
        private string nume;
        private string adresa;

        public Client() {}

        public Client(int idClient, string nume, string adresa)
        {
            this.idClient = idClient;
            this.nume = nume;
            this.adresa = adresa;
        }

        public int IdClient { get => idClient; set => idClient = value; }
        public string Nume { get => nume; set => nume = value; }
        public string Adresa { get => adresa; set => adresa = value; }

        public object Clone()
        {
            return this.MemberwiseClone();
        }

        public int CompareTo(object? obj)
        {
            if (obj == null || obj.GetType() != this.GetType())
                return -1;
            Client c = (Client) obj;

            return this.idClient.CompareTo(idClient);
        }

        public override void AfiseazaDetalii()
        {
            MessageBox.Show("Clientul " + this.nume + " are ID-ul: " + this.idClient);
        }
    }
}