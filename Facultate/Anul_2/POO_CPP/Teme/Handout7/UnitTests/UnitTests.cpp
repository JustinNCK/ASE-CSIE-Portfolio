#include "CppUnitTest.h"
#include <fstream>
#include <math.h>
#define private public
#include "..//Handout7/Source.cpp"
#undef private

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:

		TEST_METHOD(_01TestareConstructorCuParametri)
		{
			TrainRoute x("Bucuresti", "Timisoara", "RE1245");
			Assert::IsTrue(x.departure == "Bucuresti",
				L"Constructorul nu initializeaza corect statia de plecare");
			Assert::IsTrue(x.destination == "Timisoara",
				L"Constructorul nu initializeaza corect statia destinatie");
			Assert::IsTrue(strcmp(x.trainCode,"RE1245")  == 0,
				L"Constructorul implicit nu initializeaza corect codul trenului");
		}
		TEST_METHOD(_02TestareCeiTrei)
		{
			TrainRoute* pi = new TrainRoute("Craiova", "Calafat", "R5678");
			char* pointer = pi->trainCode;
			delete pi;
			Assert::IsTrue(pointer != pi->trainCode,
				L"Destructorul nu sterge zona de memorie alocata dinamic");

			TrainRoute t("Bacau", "Roman", "R5678");
			TrainRoute r = t;

			Assert::IsTrue(t.departure == r.departure,
				L"Constructorul nu copiaza corect statia de plecare");
			Assert::IsTrue(t.destination == r.destination,
				L"Constructorul nu copiaza corect destinatia");
			Assert::IsTrue(strcmp(t.trainCode, r.trainCode) == 0,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.trainCode != r.trainCode,
				L"Constructorul nu copiaza corect numarul trenului");
			TrainRoute x("", "", "");
			x = t;

			Assert::IsTrue(t.departure == x.departure,
				L"Operatorul= nu copiaza corect statia de plecare");
			Assert::IsTrue(t.destination == x.destination,
				L"Operatorul= nu copiaza corect destinatia");
			Assert::IsTrue(strcmp(t.trainCode, x.trainCode) == 0,
				L"Operatorul= nu copiaza corect numarul trenului");
			Assert::IsTrue(t.trainCode != x.trainCode,
				L"Operatorul= nu copiaza corect numarul trenului");
		}

		TEST_METHOD(_03TestareAfisaresiCitireConsola)
		{
			TrainRoute r("Bacau", "Iasi", "IC777");
			stringstream out;
			out << r;
			string result = out.str();
			Assert::IsTrue(result.find("Departure: Bacau") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Departure");
			Assert::IsTrue(result.find("Destination: Iasi") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Destination");
			Assert::IsTrue(result.find("Train code: IC777") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Train code");

			string value = "Bucuresti Nord\nPloiesti Vest\nRE 123456789";
			stringstream in;
			in << value;
			TrainRoute t("ceva", "altceva", "");
			in >> t;
			Assert::IsTrue(t.departure == "Bucuresti Nord",
				L"Operatorul de citire nu citeste corect departure");
			Assert::IsTrue(t.destination == "Ploiesti Vest",
				L"Operatorul de citire nu citeste corect destination");
			Assert::IsTrue(strcmp(t.trainCode, "RE 123456789") == 0,
				L"Operatorul de citire nu citeste corect train code");
		}

		TEST_METHOD(_04TestareConstructorImplicitDerivata)
		{
			FreightTrainRoute t;
			Assert::IsTrue(t.departure == "",
				L"Constructorul nu initializeaza corect statia de plecare");
			Assert::IsTrue(t.destination == "",
				L"Constructorul nu initializeaza corect statia destinatie");
			Assert::IsTrue(strcmp(t.trainCode, "Necunoscut") == 0,
				L"Constructorul implicit nu initializeaza corect codul trenului");
		}

		TEST_METHOD(_05TestareConstructorParametriDerivata)
		{
			FreightTrainRoute t("Bucuresti Nord", "Oradea", "Marfar 123");
			Assert::IsTrue(t.departure == "Bucuresti Nord",
				L"Constructorul nu initializeaza corect statia de plecare");
			Assert::IsTrue(t.destination == "Oradea",
				L"Constructorul nu initializeaza corect statia destinatie");
			Assert::IsTrue(strcmp(t.trainCode, "Marfar 123") == 0,
				L"Constructorul implicit nu initializeaza corect codul trenului");
			Assert::IsTrue(t.nbOfWagons == 0,
				L"Constructorul nu initializeaza corect numarul de vagoane");
			Assert::IsTrue(t.weigthPerWagon == nullptr,
				L"Constructorul nu initializeaza corect vectorul de greutati");
		}

		TEST_METHOD(_06TestareSetWeight)
		{
			FreightTrainRoute t("Bucuresti Nord", "Oradea", "Marfar 123");
			float weights[] = { 30.5f, 20.0f, 12.7f, 15.88f };
			t.setWeigth(4, weights);
			Assert::IsTrue(t.nbOfWagons == 4,
				L"SetWeight nu initializeaza corect numarul de vagoane");
			Assert::IsTrue(t.weigthPerWagon != weights,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[0] - 30.5f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[1] - 20.0f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[2] - 12.7f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[3] - 15.88f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");

			float* pointer = t.weigthPerWagon;
			float weights2[] = { 12.5f, 10.0f, 5.7f};
			new int[3];
			t.setWeigth(3, weights2);
			Assert::IsTrue(t.nbOfWagons == 3,
				L"SetWeight nu initializeaza corect numarul de vagoane");
			Assert::IsTrue(t.weigthPerWagon != weights2,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(t.weigthPerWagon != pointer,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[0] - 12.5f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[1] - 10.0f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[2] - 5.7f) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
		}

		TEST_METHOD(_07TestareCeiTreiDerivata)
		{
			FreightTrainRoute* pi = new FreightTrainRoute("Craiova", "Calafat", "R5678");
			float weights[] = { 30.5f, 20.0f, 12.7f, 15.88f };
			pi->setWeigth(4, weights);
			char* pointer = pi->trainCode;
			float* pointer2 = pi->weigthPerWagon;
			delete pi;
			Assert::IsTrue(pointer != pi->trainCode,
				L"Destructorul nu sterge zona de memorie alocata dinamic");
			Assert::IsTrue(pointer2 != pi->weigthPerWagon,
				L"Destructorul nu sterge zona de memorie alocata dinamic");

			FreightTrainRoute t("Bacau", "Roman", "R5678");
			t.setWeigth(4, weights);
			FreightTrainRoute r = t;

			Assert::IsTrue(t.departure == r.departure,
				L"Constructorul nu copiaza corect statia de plecare");
			Assert::IsTrue(t.destination == r.destination,
				L"Constructorul nu copiaza corect destinatia");
			Assert::IsTrue(strcmp(t.trainCode, r.trainCode) == 0,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.trainCode != r.trainCode,
				L"Constructorul nu copiaza corect numarul trenului");
			Assert::IsTrue(t.nbOfWagons == r.nbOfWagons,
				L"Constructorul nu initializeaza corect numarul de vagoane");
			Assert::IsTrue(t.weigthPerWagon != r.weigthPerWagon,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[0] - r.weigthPerWagon[0]) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[1] - r.weigthPerWagon[1]) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[2] - r.weigthPerWagon[2]) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[3] - r.weigthPerWagon[3]) < 0.01,
				L"Constructorul nu initializeaza corect vectorul de greutati");
			FreightTrainRoute x("", "", "");
			x = t;

			Assert::IsTrue(t.departure == x.departure,
				L"Operatorul= nu copiaza corect statia de plecare");
			Assert::IsTrue(t.destination == x.destination,
				L"Operatorul= nu copiaza corect destinatia");
			Assert::IsTrue(strcmp(t.trainCode, x.trainCode) == 0,
				L"Operatorul= nu copiaza corect numarul trenului");
			Assert::IsTrue(t.trainCode != x.trainCode,
				L"Operatorul= nu copiaza corect numarul trenului");
			Assert::IsTrue(t.nbOfWagons == x.nbOfWagons,
				L"Operatorul= nu initializeaza corect numarul de vagoane");
			Assert::IsTrue(t.weigthPerWagon != x.weigthPerWagon,
				L"Operatorul= nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[0] - x.weigthPerWagon[0]) < 0.01,
				L"Operatorul= nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[1] - x.weigthPerWagon[1]) < 0.01,
				L"Operatorul= nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[2] - x.weigthPerWagon[2]) < 0.01,
				L"Operatorul= nu initializeaza corect vectorul de greutati");
			Assert::IsTrue(abs(t.weigthPerWagon[3] - x.weigthPerWagon[3]) < 0.01,
				L"Operatorul= nu initializeaza corect vectorul de greutati");
		}

		TEST_METHOD(_08TestareAfisaresiCitireConsola)
		{
			FreightTrainRoute r("Bacau", "Iasi", "IC777");
			float weights[] = { 30.5f, 20.0f, 12.7f, 15.88f };
			r.setWeigth(4, weights);
			stringstream out;
			out << r;
			string result = out.str();
			Assert::IsTrue(result.find("Departure: Bacau") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Departure");
			Assert::IsTrue(result.find("Destination: Iasi") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Destination");
			Assert::IsTrue(result.find("Train code: IC777") != string::npos,
				L"Operatorul de afisare nu afiseaza corect Train code");
			Assert::IsTrue(result.find("Nb of wagons: 4") != string::npos,
				L"Operatorul de afisare nu afiseaza corect numarul de vagoane");
			Assert::IsTrue(result.find("Weigth per wagon: 30 20 12 15") != string::npos,
				L"Operatorul de afisare nu afiseaza corect greutatile vagoanelor");

			string value = "Bucuresti Nord\nPloiesti Vest\nRE 123456789\n2\n4.5\n3.5";
			stringstream in;
			in << value;
			FreightTrainRoute t("ceva", "altceva", "");
			in >> t;
			Assert::IsTrue(t.departure == "Bucuresti Nord",
				L"Operatorul de citire nu citeste corect departure");
			Assert::IsTrue(t.destination == "Ploiesti Vest",
				L"Operatorul de citire nu citeste corect destination");
			Assert::IsTrue(strcmp(t.trainCode, "RE 123456789") == 0,
				L"Operatorul de citire nu citeste corect train code");
			Assert::IsTrue(t.nbOfWagons == 2,
				L"Operatorul de citire nu citeste corect numarul de vagoane");
			Assert::IsTrue(abs(t.weigthPerWagon[0] - 4.5f) < 0.01,
				L"Operatorul de citire nu citeste corect greutatile vagoanelor");
			Assert::IsTrue(abs(t.weigthPerWagon[1] - 3.5f) < 0.01,
				L"Operatorul de citire nu citeste corect greutatile vagoanelor");
		}

		TEST_METHOD(_09TestareTotalWeight)
		{
			TrainRoute* t;
			FreightTrainRoute* x = new FreightTrainRoute("Bacau", "Iasi", "IC777");
			float weights[] = { 30.5f, 20.0f, 12.7f, 15.88f };
			x->setWeigth(4, weights);
			t = x;
			int total = x->totalWeight();
			Assert::IsTrue(total == 79,
				L"Metoda totalWeight nu este supradefinita corect");
		}

		TEST_METHOD(_10TestareTotalMemoryLeaks)
		{
			TrainRoute* t = new FreightTrainRoute("Bacau", "Iasi", "IC777");
			float weights[] = { 30.5f, 20.0f, 12.7f, 15.88f };
			FreightTrainRoute* x = (FreightTrainRoute*)t;
			x->setWeigth(4, weights);
			float* pointer = x->weigthPerWagon;
			delete t;
			Assert::IsFalse(abs(pointer[0] - 30.5f) < 0.01,
				L"Nu sunt evitate memory leaks");
			Assert::IsFalse(abs(pointer[1] - 20.0f) < 0.01,
				L"Nu sunt evitate memory leaks");
		}
	};
}
