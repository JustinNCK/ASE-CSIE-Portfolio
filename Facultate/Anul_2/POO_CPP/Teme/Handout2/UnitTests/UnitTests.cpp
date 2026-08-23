#include "CppUnitTest.h"
#include "..//Handout2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:
		
		TEST_METHOD(_01TestareNumarElementeVector)
		{
			int rezultat = numar_elemente();
			Assert::IsTrue(7 == rezultat, L"Functia suma nu returneaza numarul corect de elemente");
		}

		TEST_METHOD(_02TestareMaximVector)
		{
			float* v = new float[6];
			v[0] = -6.0f;
			v[1] = 2.0f;
			v[2] = 3.5f;
			v[3] = 7.9f;
			v[4] = -99.1f;
			v[5] = 0.2f;
			float rezultat = maxim_vector(nullptr, 2);
			if (rezultat > 0.01)
			{
				Assert::Fail(L"Functia nu returneaza 0 pentru un vector null");
			}
			rezultat = maxim_vector(v, -2);
			if (rezultat > 0.01)
			{
				Assert::Fail(L"Functia nu returneaza 0 pentru o dimensiune negativa");
			}
			rezultat = maxim_vector(v, 6);
			delete[] v;
			Assert::IsTrue(abs(7.9 - rezultat) < 0.01, L"Functia nu returneaza maximul corect");
		}

		TEST_METHOD(_03TestareCopieSir)
		{
			char* sir = new char[25];
			strcpy_s(sir, 15, "Popescu Vasile");
			char* sir_nou = returnare_copie_vector_caractere(sir);
			if (sir_nou == sir)
			{
				Assert::Fail(L"Copia returnata este una superficiala");
			}
			Assert::IsTrue(strcmp(sir_nou, sir) == 0, L"Functia nu returneaza o copie exacta");
			delete[] sir;
			delete[] sir_nou;
		}

		TEST_METHOD(_04TestareLungimeStringuri)
		{
			string s1 = "asdbasghd ghasdg";
			string s2 = "asdn";
			int rezultat = returnare_lungime_stringuri(s1, s2);
			Assert::IsTrue(20 == rezultat, L"Functia nu returneza lungimea corecta");
		}

		TEST_METHOD(_05TestareSiruriEgale)
		{
			string sir1 = "Ion Popescu";
			char sir2[] = "Ion Popescu";
			Assert::IsTrue(siruri_egale(sir1, sir2), L"Functia nu verifica in mod corect daca cele doua siruri sunt egale");
		}

		TEST_METHOD(_06TestareMatriceUnitate)
		{
			int** z = new int* [3];
			for (int i = 0; i < 3; i++)
			{
				z[i] = new int[3];
			}
			z[0][0] = 1; z[0][1] = 0; z[0][2] = 0;
			z[1][0] = 0; z[1][1] = 1; z[1][2] = 0;
			z[2][0] = 0; z[2][1] = 0; z[2][2] = 1;
			long rezultat = matrice_unitate(z, 3, 3);
			if (matrice_unitate(z, 2, 3))
			{
				Assert::Fail(L"Matricea unitate trebuie sa fie patratica");
			}
			Assert::IsTrue(rezultat, L"Functia nu determina corect daca o matrice este unitate");
		}

		TEST_METHOD(_07TestareMinimPeLinii)
		{
			int** z = new int*[4];
			for (int i = 0; i < 4; i++)
			{
				z[i] = new int[3];
			}
			z[0][0] = 1; z[0][1] = 7; z[0][2] = -2;
			z[1][0] = 0; z[1][1] = 1; z[1][2] = 2;
			z[2][0] = 99; z[2][1] = 3; z[2][2] = 1;
			z[3][0] = 98; z[3][1] = -3; z[3][2] = 1;
			int* rezultat = returnare_minim_pe_linii(z, 4, 3);
			Assert::IsTrue(rezultat[0] == -2, L"Functia nu returneza vectorul de valori minime corect");
			Assert::IsTrue(rezultat[1] == 0, L"Functia nu returneza vectorul de valori minime corect");
			Assert::IsTrue(rezultat[2] == 1, L"Functia nu returneza vectorul de valori minime corect");
			Assert::IsTrue(rezultat[3] == -3, L"Functia nu returneza vectorul de valori minime corect");
		}

		TEST_METHOD(_08TestareMinimPeLiniiCaSir)
		{
			int** z = new int* [4];
			for (int i = 0; i < 4; i++)
			{
				z[i] = new int[3];
			}
			z[0][0] = 1; z[0][1] = 7; z[0][2] = -2;
			z[1][0] = 0; z[1][1] = 1; z[1][2] = 2;
			z[2][0] = 99; z[2][1] = 3; z[2][2] = 1;
			z[3][0] = 98; z[3][1] = -3; z[3][2] = 1;
			const char* rezultat = returnare_minim_pe_linii_ca_sir(z, 4, 3);
			Assert::IsTrue(strcmp(rezultat, "-2 0 1 -3") == 0, L"Functia nu returneza sirul de caractere corect");
		}

		TEST_METHOD(_09TestareStergereElement)
		{
			int* v = new int[4];
			v[0] = -6;
			v[1] = 2;
			v[2] = 3;
			v[3] = 7;
			int* rezultat = sterge_element(v, 4, 3);
			Assert::IsTrue(rezultat[0] == -6, L"Functia nu returneza vectorul corect");
			Assert::IsTrue(rezultat[1] == 2, L"Functia nu returneza vectorul corect");
			Assert::IsTrue(rezultat[2] == 7, L"Functia nu returneza vectorul corect");
			v[0] = -6;
			v[1] = 2;
			v[2] = 3;
			v[3] = 7;
			rezultat = sterge_element(v, 4, -6);
			Assert::IsTrue(rezultat[0] == 2, L"Functia nu returneza vectorul corect");
			Assert::IsTrue(rezultat[1] == 3, L"Functia nu returneza vectorul corect");
			Assert::IsTrue(rezultat[2] == 7, L"Functia nu returneza vectorul corect");
			v[0] = -6;
			v[1] = 2;
			v[2] = 3;
			v[3] = 7;
			rezultat = sterge_element(v, 4, 7);
			Assert::IsTrue(rezultat[0] == -6, L"Functia nu returneza vectorul corect");
			Assert::IsTrue(rezultat[1] == 2, L"Functia nu returneza vectorul corect");
			Assert::IsTrue(rezultat[2] == 3, L"Functia nu returneza vectorul corect");
		}

		TEST_METHOD(_10TestareArhivareSir)
		{
			char* rezultat = arhivare_sir("AAABBC");
			Assert::IsTrue((strcmp(rezultat, "3A2BC") == 0), L"Sirul returnat nu este corect");

			rezultat = arhivare_sir("XYYYYYYYZTTT");
			Assert::IsTrue((strcmp(rezultat, "X7YZ3T") == 0), L"Sirul returnat nu este corect");

			rezultat = arhivare_sir("BBBCCD");
			Assert::IsTrue((strcmp(rezultat, "3B2CD") == 0), L"Sirul returnat nu este corect");
		}
	};
}
