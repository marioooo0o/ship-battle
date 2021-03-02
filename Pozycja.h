#pragma once
#include <vector>
/// <summary>
/// Klasa Pozycja wi¹¿e ze sob¹ wspó³rzêdna x i y
/// </summary>
class Pozycja
{
public:
	/// <summary>
	/// Wspó³rzêdna x
	/// </summary>
	int x;
	/// <summary>
	/// Wspo³rzêdna y
	/// </summary>
	int y;
	/// <summary>
	/// Konstruktor klasy Pozycja
	/// </summary>
	/// <param name="x">Wspo³rzêdna x</param>
	/// <param name="y">Wspo³rzêdna y</param>
	Pozycja(int x, int y);
	~Pozycja();
};
