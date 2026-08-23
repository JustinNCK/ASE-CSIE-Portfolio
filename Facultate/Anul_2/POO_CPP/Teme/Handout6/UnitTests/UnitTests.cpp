#include "CppUnitTest.h"
#include <fstream>
#define private public
#include "..//Handout6/Source.cpp"
#undef private

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:

		TEST_METHOD(_01TestareConstructorCuParametri)
		{
			TrainRoute x("Bucuresti", "Timisoara");
			Assert::IsTrue(x.departure == "Bucuresti",
				L"Constructorul nu initializeaza corect statia de plecare");
			Assert::IsTrue(x.destination == "Timisoara",
				L"Constructorul nu initializeaza corect statia destinatie");
			Assert::IsTrue(x.nbOfStops == 0,
				L"Constructorul nu initializeaza corect numarul de opriri");
			Assert::IsTrue(x.distances == nullptr,
				L"Constructorul nu initializeaza corect vectorul de distante");
			Assert::IsTrue(x.trainCode == nullptr,
				L"Constructorul implicit nu initializeaza corect numarul trenului");
		}

		TEST_METHOD(_02TestareSetTrip)
		{
			TrainRoute x("Bucuresti", "Timisoara");
			int distante[] = { 50, 70, 75, 20, 10 };
			x.setTrip(distante, 6);
			Assert::IsTrue(x.distances != distante,
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(x.distances[0] == 50,
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(x.distances[1] == 70,
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(x.distances[4] == 10,
				L"SetTrip nu initializeaza corect vectorul de distante");
		}

		TEST_METHOD(_03TestareSetTrainCode)
		{
			TrainRoute x("Bucuresti", "Timisoara");
			char* code1 = "RE12345";
			char* code2 = "R4567";
			x.setTrainCode(code1);
			char* code = x.trainCode;

			x.setTrainCode(code2);
			Assert::IsTrue(x.trainCode != code,
				L"SetTrainCode nu functioneaza corect");
			Assert::IsTrue(x.trainCode != code2,
				L"SetTrainCode nu functioneaza corect");
			Assert::IsTrue(strcmp(x.trainCode, code2) == 0,
				L"SetTrainCode nu functioneaza corect");
		}

		TEST_METHOD(_04TestareCeiTrei)
		{
			TrainRoute* pi = new TrainRoute("Craiova", "Calafat");
			char* pointer = pi->trainCode;
			int* pointer2 = pi->distances;
			delete pi;
			Assert::IsTrue(pointer != pi->trainCode,
				L"Destructorul nu sterge zona de memorie alocata dinamic");
			Assert::IsTrue(pointer2 != pi->distances,
				L"Destructorul nu sterge zona de memorie alocata dinamic");

			TrainRoute t("Bacau", "Roman");
			int distante[] = { 50, 70, 75, 20, 10 };
			t.setTrip(distante, 6);
			t.setTrainCode("R12345");

			TrainRoute r = t;

			Assert::IsTrue(t.departure == r.departure,
				L"Constructorul nu copiaza corect statia de plecare");
			Assert::IsTrue(t.destination == r.destination,
				L"Constructorul nu copiaza corect destinatia");
			Assert::IsTrue(t.nbOfStops == r.nbOfStops,
				L"Constructorul nu copiaza corect numarul de opriri");
			Assert::IsTrue(strcmp(t.trainCode, r.trainCode) == 0,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.trainCode != r.trainCode,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.distances != r.distances,
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(t.distances[0] == r.distances[0],
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(t.distances[1] == r.distances[1],
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(t.distances[4] == r.distances[4],
				L"SetTrip nu initializeaza corect vectorul de distante");

			TrainRoute x("", "");
			x = t;

			Assert::IsTrue(t.departure == x.departure,
				L"Constructorul nu copiaza corect statia de plecare");
			Assert::IsTrue(t.destination == x.destination,
				L"Constructorul nu copiaza corect destinatia");
			Assert::IsTrue(t.nbOfStops == x.nbOfStops,
				L"Constructorul nu copiaza corect numarul de opriri");
			Assert::IsTrue(strcmp(t.trainCode, x.trainCode) == 0,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.trainCode != x.trainCode,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.distances != x.distances,
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(t.distances[0] == x.distances[0],
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(t.distances[1] == x.distances[1],
				L"SetTrip nu initializeaza corect vectorul de distante");
			Assert::IsTrue(t.distances[4] == x.distances[4],
				L"SetTrip nu initializeaza corect vectorul de distante");
		}

		TEST_METHOD(_05TestareOperatorMaiMic)
		{
			TrainRoute tr1("a", "a");
			TrainRoute tr2("b", "b");

			int d1[] = { 100, 200, 30 };
			int d2[] = { 120, 20, 50 };
			tr1.setTrip(d1, 4);
			tr2.setTrip(d2, 4);
			bool result = tr1 < tr2;

			Assert::IsFalse(result,
				L"Operatorul < nu functioneaza corect");
			tr2.setTrip(d1, 4);
			tr1.setTrip(d2, 4);
			result = tr1 < tr2;
			Assert::IsTrue(result,
				L"Operatorul < nu functioneaza corect");
		}

		TEST_METHOD(_06TestareOperatorPlusEgal)
		{
			TrainRoute t("x", "y");
			int d[] = { 100, 200, 150 };
			t.setTrip(d, 4);
			t += 90;
			Assert::IsTrue(t.distances != d, 
				L"Operatorul += nu functioneaza corect");
			Assert::IsTrue(t.distances[0] == 100,
				L"Operatorul += nu functioneaza corect");
			Assert::IsTrue(t.distances[1] == 200,
				L"Operatorul += nu functioneaza corect");
			Assert::IsTrue(t.distances[2] == 150,
				L"Operatorul += nu functioneaza corect");
			Assert::IsTrue(t.distances[3] == 90,
				L"Operatorul += nu functioneaza corect");
			Assert::IsTrue(t.nbOfStops == 5,
				L"Operatorul += nu functioneaza corect");
		}

		TEST_METHOD(_07TestareAfisareConsola)
		{
			TrainRoute r("Bacau", "Iasi");
			int d[] = { 100, 200, 150 };
			r.setTrip(d, 4);
			r.setTrainCode("RE5678");
			stringstream out;
			out << r;
			string result = out.str();
			Assert::IsTrue(result.find("Departure: Bacau") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Departure");
			Assert::IsTrue(result.find("Destination: Iasi") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Destination");
			Assert::IsTrue(result.find("Train code: RE5678") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Train code");
			Assert::IsTrue(result.find("Number of stops: 4") != string::npos,
				L"Operatorul de afisare nu afiseaza corect NbOfStops");
			Assert::IsTrue(result.find("Distances between stops: 100 200 150") != string::npos,
				L"Operatorul de afisare nu afiseaza corect distantele");
		}

		TEST_METHOD(_08TestareCitireConsola)
		{
			string value = "Bucuresti Nord\nPloiesti Vest\nRE 123456789\n5\n5\n6\n10\n12";
			stringstream in;
			in << value;
			TrainRoute r("ceva", "altceva");
			in >> r;
			Assert::IsTrue(r.departure == "Bucuresti Nord",
				L"Operatorul de citire nu citeste corect departure");
			Assert::IsTrue(r.destination == "Ploiesti Vest",
				L"Operatorul de citire nu citeste corect destination");
			Assert::IsTrue(strcmp(r.trainCode, "RE 123456789") == 0,
				L"Operatorul de citire nu citeste corect train code");
			Assert::IsTrue(r.nbOfStops == 5,
				L"Operatorul de citire nu citeste corect nbOfStops");
			Assert::IsTrue(r.distances[0] == 5,
				L"Operatorul de citire nu citeste corect distances");
			Assert::IsTrue(r.distances[1] == 6,
				L"Operatorul de citire nu citeste corect distances");
			Assert::IsTrue(r.distances[2] == 10,
				L"Operatorul de citire nu citeste corect distances");
			Assert::IsTrue(r.distances[3] == 12,
				L"Operatorul de citire nu citeste corect distances");
		}

		TEST_METHOD(_09TestareScriereCitireText)
		{
			TrainRoute r("Bucuresti Obor", "Rosirorii de Vede");
			int d[] = { 100, 200, 150 };
			r.setTrip(d, 4);
			r.setTrainCode("RE 5678");
			ofstream f("fisier.txt");
			f << r;
			f.close();

			ifstream g("fisier.txt");
			TrainRoute t("a", "b");
			g >> t;
			g.close();

			Assert::IsTrue(t.departure == r.departure,
				L"Eroare citire/scriere statia de plecare");
			Assert::IsTrue(t.destination == r.destination,
				L"Eroare citire/scriere destinatie");
			Assert::IsTrue(t.nbOfStops == r.nbOfStops,
				L"Eroare citire/scriere numarul de opriri");
			Assert::IsTrue(strcmp(t.trainCode, r.trainCode) == 0,
				L"Eroare citire/scriere numarul trenului");
			Assert::IsTrue(t.trainCode != r.trainCode,
				L"Eroare citire/scriere numarul trenului");
			Assert::IsTrue(t.distances != r.distances,
				L"Eroare citire/scriere vector de distante");
			Assert::IsTrue(t.distances[0] == r.distances[0],
				L"Eroare citire/scriere vector de distante");
			Assert::IsTrue(t.distances[1] == r.distances[1],
				L"Eroare citire/scriere vector de distante");
			Assert::IsTrue(t.distances[2] == r.distances[2],
				L"Eroare citire/scriere vector de distante");
		}

		TEST_METHOD(_10TestareScriereCitireBinara)
		{
			TrainRoute* r = new TrainRoute("Bucuresti Obor", "Rosirorii de Vede");
			int d[] = { 100, 200, 150 };
			r->setTrip(d, 4);
			r->setTrainCode("RE 5678");
			r->serialize("train.dat");
			delete r;

			TrainRoute t("a", "b");
			t.deserialize("train.dat");

			Assert::IsTrue(t.departure == "Bucuresti Obor",
				L"Eroare citire/scriere statia de plecare");
			Assert::IsTrue(t.destination == "Rosirorii de Vede",
				L"Eroare citire/scriere destinatie");
			Assert::IsTrue(t.nbOfStops == 4,
				L"Eroare citire/scriere numarul de opriri");
			Assert::IsTrue(strcmp(t.trainCode, "RE 5678") == 0,
				L"Eroare citire/scriere numarul trenului");
			Assert::IsTrue(t.distances[0] == 100,
				L"Eroare citire/scriere vector de distante");
			Assert::IsTrue(t.distances[1] == 200,
				L"Eroare citire/scriere vector de distante");
			Assert::IsTrue(t.distances[2] == 150,
				L"Eroare citire/scriere vector de distante");
		}
	};
}
