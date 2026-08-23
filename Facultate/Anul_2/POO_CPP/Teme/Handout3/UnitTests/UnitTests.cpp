#include "CppUnitTest.h"
#include "..//Handout3/Source.cpp"
#include<math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:
		
		TEST_METHOD(_01TestareInterschimbare)
		{
			int x = 99;
			int y = 200;
			interschimbare(x, y);
			Assert::IsTrue(x == 200, L"Functia de interschimbare nu functioneaza corect");
			Assert::IsTrue(y == 99, L"Functia de interschimbare nu functioneaza corect");
		}

		TEST_METHOD(_02TestareModificareEnum)
		{
			tipAplicatie rezultat = modificare_enum("aplicatieWeb");
			Assert::IsTrue(rezultat == 5, L"Functia nu seteaza corect o aplicatie web");
			rezultat = modificare_enum("aplicatieMobila");
			Assert::IsTrue(rezultat == 10, L"Functia nu seteaza corect o aplicatie mobila");
			rezultat = modificare_enum("aplicatieDesktop");
			Assert::IsTrue(rezultat == 15, L"Functia nu seteaza corect o aplicatie desktop");
		}

		TEST_METHOD(_03TestareConstructorImplicit)
		{
			Autoturism a;
			Assert::IsTrue(a.marca == "Necunoscuta", 
				L"Constructorul nu initializeaza corect marca");
			Assert::IsTrue(a.model == "Necunoscut",
				L"Constructorul nu initializeaza corect modelul");
			Assert::IsTrue(a.putere == 0,
				L"Constructorul nu initializeaza corect puterea");
			Assert::IsTrue(abs(a.pret - 5000) < 0.01,
				L"Constructorul nu initializeaza corect pretul");
		}

		TEST_METHOD(_04TestareConstructorCuParametri)
		{
			Autoturism a("Dacia", "Logan", 60);
			Assert::IsTrue(a.marca == "Dacia",
				L"Constructorul nu initializeaza corect marca");
			Assert::IsTrue(a.model == "Logan",
				L"Constructorul nu initializeaza corect modelul");
			Assert::IsTrue(a.putere == 60,
				L"Constructorul nu initializeaza corect puterea");
			Assert::IsTrue(abs(a.pret - 5000) < 0.01,
				L"Constructorul nu initializeaza corect pretul");
		}

		TEST_METHOD(_05TestareMetodaDiscount)
		{
			Autoturism a;
			a.pret = 9876;
			a.discount(0);
			Assert::IsTrue(abs(a.pret - 9876) < 0.01,
				L"Metoda discount accepta valori mai mici de 1");
			a.discount(51);
			Assert::IsTrue(abs(a.pret - 9876) < 0.01,
				L"Metoda discount accepta valori mai mari de 50");
			a.discount(25);
			Assert::IsTrue(abs(a.pret - 7407) < 0.01,
				L"Metoda nu aplica discountul in mod corect");
		}

		TEST_METHOD(_06TestareDestructor)
		{
			fisierDeschis = true;
			Autoturism* pa = new Autoturism();
			delete pa;
			Assert::IsFalse(fisierDeschis, 
				L"Destructorul nu seteaza fisierDeschis pe false");
		}

		TEST_METHOD(_07TestareNumarInmatriculare)
		{
			Autoturism a;
			a.seteazaNumarInmatriculare("B101ABC");
			char* rezultat = a.obtineNumarInmatriculare();
			Assert::IsTrue(strcmp(rezultat, "B101ABC") == 0,
				L"Metodele nu prelucreaza corect numarul de inmatriculare");
		}

		TEST_METHOD(_08TestareValoreaFlota)
		{
			Autoturism masini[3];
			Autoturism a1, a2, a3;
			a1.pret = 1111.5;
			a2.pret = 2222.5;
			a3.pret = 3333.4;
			masini[0] = a1; masini[1] = a2; masini[2] = a3;
			double rezultat = calcul_valoare_flota(masini, 3);
			Assert::IsTrue(abs(rezultat - 6667.4) < 0.01, L"Functia nu returneza corect valoarea flotei");
		}

		TEST_METHOD(_09TestareCeaMaiTareDinParcare)
		{
			Autoturism a1, a2, a3;
			a1.pret = 200.5;
			a2.pret = 200.7;
			a3.pret = 154.5;
			Autoturism** vector = new Autoturism*[3];
			vector[0] = &a1; vector[1] = &a2; vector[2] = &a3;
			double rezultat = cea_mai_tare_din_parcare(vector, 3);
			Assert::IsTrue(abs(200.7 - rezultat) < 0.01, 
				L"Masina identificata nu e cea mai tare din parcare");
		}

		TEST_METHOD(_10TestareLocuriLibere)
		{
			Autoturism a1, a2, a3, a4, a5, a6;
			a1.putere = 200;
			a2.putere = 180;
			a3.putere = 120;
			a4.putere = 320;
			a5.putere = 150;
			a6.putere = 90;
			Autoturism*** matrice = new Autoturism** [3];
			for (int i = 0; i < 3; i++)
			{
				matrice[i] = new Autoturism*[3];
			}
			matrice[0][0] = &a1;
			matrice[0][1] = &a2;
			matrice[0][2] = &a3;
			matrice[1][0] = nullptr;
			matrice[1][1] = &a4;
			matrice[1][2] = &a5;
			matrice[2][0] = nullptr;
			matrice[2][1] = &a6;
			matrice[2][2] = nullptr;

			int** rezultat = locuri_libere(matrice, 3, 3);
			Assert::IsTrue(rezultat[0][0] == 200,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[0][1] == 180,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[0][2] == 120,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[1][0] == 0,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[1][1] == 320,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[1][2] == 150,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[2][0] == 0,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[2][1] == 90,
				L"Matricea returnata nu are valorile corecte");
			Assert::IsTrue(rezultat[2][2] == 0,
				L"Matricea returnata nu are valorile corecte");
		}
	};
}
