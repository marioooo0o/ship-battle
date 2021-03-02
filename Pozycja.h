#pragma once
#include <vector>
/// <summary>
/// Klasa Pozycja wi��e ze sob� wsp�rz�dna x i y
/// </summary>
class Pozycja
{
public:
	/// <summary>
	/// Wsp�rz�dna x
	/// </summary>
	int x;
	/// <summary>
	/// Wspo�rz�dna y
	/// </summary>
	int y;
	/// <summary>
	/// Konstruktor klasy Pozycja
	/// </summary>
	/// <param name="x">Wspo�rz�dna x</param>
	/// <param name="y">Wspo�rz�dna y</param>
	Pozycja(int x, int y);
	~Pozycja();
};
