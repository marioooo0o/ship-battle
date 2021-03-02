#pragma once
#include <cstdlib>
#include <vector>
#include <iostream>
#include "Pozycja.h"

/// <summary>
/// Klasa Statek w które przechowywane s¹ informacje o statku
/// </summary>
class Ship
{
public:
	/// <summary>
	/// Wektor w którym przechowuje wspó³rzêdne ka¿dego maszu statku
	/// </summary>
	std::vector<Pozycja> punkty;
	/// <summary>
	/// Zmienna w której deklaruje maksymalny rozmiar statku
	/// </summary>
	int max_size_of_ships = 5;
	/// <summary>
	/// Zmienna w której deklaruje rozmiar statku
	/// </summary>
	int ship_size;
	Ship();
	/// <summary>
	/// Konstruktor klasy Ship
	/// </summary>
	/// <param name="pierwsza">Wspó³rzêdne punktu podanego jako pierwszy</param>
	/// <param name="druga">Wspó³rzêdne punktu podanego jako drugi</param>
	Ship(Pozycja pierwsza, Pozycja druga);
};


