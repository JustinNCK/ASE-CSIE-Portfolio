#include "CppUnitTest.h"
#include "..//Lab1_handout/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(TesteUnitare)
	{
	public:
		
		TEST_METHOD(_01TestareSuma)
		{
			long rezultat = suma(3, 5);
			Assert::IsTrue(8 == rezultat, L"Functia suma nu returneaza valoarea corecta\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_02TestarePointerNull)
		{
			float* rezultat = returnare_pointer_null();
			Assert::IsTrue(0 == rezultat, L"Functia nu returneaza un pointer NULL\r\nThe function does not return a NULL pointer");
		}

		TEST_METHOD(_03TestareAdresaVariabila)
		{
			int* rezultat = returnare_pointer_adresa();
			Assert::IsTrue(&variabila == rezultat, L"Functia nu returneaza adresa variabilei variabila\r\nThe function does not return the address of variabila");
		}

		TEST_METHOD(_04TestareReturnareValoare)
		{
			double variabila = 123.45;
			double rezultat = returnare_valoare_de_la_adresa(&variabila);
			Assert::IsTrue(variabila == rezultat, L"Functia nu returneza valoarea de la adresa primita\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_05TestareAdresaIntregUrmator)
		{
			int variabila = 5;
			int* pointer = &variabila;
			int* rezultat = returnare_adresa_intreg_urmator(pointer);
			Assert::IsTrue(++pointer == rezultat, L"Functia nu returneza adresa intregului urmator\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_06TestareAdresaLongPrecedent)
		{
			long vector[] = { 2, 4, 5, 8 };
			long* pointer = &vector[2];
			long rezultat = returnare_adresa_long_precedent(pointer);
			Assert::IsTrue(rezultat == 2, L"Functia nu returneza valoarea long ceruta\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_07TestareDiferentaPointeri)
		{
			int x = 99;
			int* p = &x;
			int* q = p + 4;
			int rezultat = returnare_diferenta_pointeri(q, p);
			Assert::IsTrue(rezultat == 4, L"Functia nu returneza diferenta dintre pointeri corect\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_08TestareDiferentaNegativaPointeri)
		{
			int x = 99;
			int* p = &x;
			int* q = p + 4;
			int rezultat = returnare_diferenta_pointeri(p, q);
			Assert::IsTrue(rezultat == 4, L"Functia nu returneza diferenta dintre pointeri corect\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_09TestareAdresaDeAdresaDeIntreg)
		{
			int x = 99;
			int* p = &x;
			int** q = &p;
			int rezultat = returnare_valoare_adresa_de_adresa(q);
			Assert::IsTrue(rezultat == **q, L"Functia nu returneza valoarea ceruta\r\nThe function does not return the correct value");
		}

		TEST_METHOD(_10TestareAdresaDeAdresaCuParametru)
		{
			int x = 99;
			int* p = &x;
			int** q = &p;
			int rezultat = returneaza_valoarea_adresa_de_adresa_void((void**)q, 'I');
			Assert::IsTrue(rezultat == **q, L"Functia nu functioneaza pentru intreg\r\nThe function does not work for integer");

			long y = 999;
			long* w = &y;
			long** z = &w;
			long rezultat2 = returneaza_valoarea_adresa_de_adresa_void((void**)z, 'L');
			Assert::IsTrue(rezultat2 == **z, L"Functia nu functioneaza pentru long\r\nThe function does not work for long");
		}
	};
}
