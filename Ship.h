#pragma once
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Pozycja.h"

/// <summary>
/// Klasa Statek w kt�re przechowywane s� informacje o statku
/// </summary>
class Ship
{
public:
	/// <summary>
	/// Wektor w kt�rym przechowuje wsp�rz�dne ka�dego maszu statku
	/// </summary>
	std::vector<Pozycja> punkty;
	/// <summary>
	/// Zmienna w kt�rej deklaruje maksymalny rozmiar statku
	/// </summary>
	int max_size_of_ships = 5;
	/// <summary>
	/// Zmienna w kt�rej deklaruje rozmiar statku
	/// </summary>
	int ship_size;
	Ship();
	/// <summary>
	/// Konstruktor klasy Ship
	/// </summary>
	/// <param name="pierwsza">Wsp�rz�dne punktu podanego jako pierwszy</param>
	/// <param name="druga">Wsp�rz�dne punktu podanego jako drugi</param>
	Ship(Pozycja pierwsza, Pozycja druga);
};


