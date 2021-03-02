#pragma once
#include <iostream>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>     
#include <stdlib.h>     
#include <time.h>
#include "Ship.h"
#include "Board.h"

/// <summary>
/// G³owna klasa projektu odpowiadaj¹ca za rozgrywkê 
/// </summary>
class Game
{
private:
	/// <summary>
	/// Iloœæ wierszy
	/// </summary>
	int rows;
	/// <summary>
	/// Iloœæ kolumn
	/// </summary>
	int column;
	/// <summary>
	/// Inicjalizacja parametów planszy dla drugiego gracza
	/// </summary>
	void init();
	/// <summary>
	/// Metoda ustawia statki gracza "cz³owieka"
	/// </summary>
	/// <param name="Player_Board">Obiekt klasy Board</param>
	/// <param name="player_ship">Obiekt klasy Ship</param>
	void Set_Player_Ships(Board* Player_Board, Ship player_ship);
	/// <summary>
	/// Metoda ustawia statki komputera
	/// </summary>
	/// <param name="Computer_Board">Obiekt klasy Board</param>
	/// <param name="player2_ship">Obiekt klasy Ship</param>
	void Set_Computer_Ships(Board* Computer_Board, Ship player2_ship);
	/// <summary>
	/// Metoda ta losuje w jakim kierunku ustawiæ koniec statka
	/// </summary>
	/// <param name="ship_length">D³ugoœæ statka</param>
	/// <param name="random_number">Losowa liczba odpowiadaj¹ca za kierunek</param>
	/// <param name="x">x pocz¹tka statka</param>
	/// <param name="y">y pocz¹tka statka</param>
	/// <param name="x1">x koñca statka</param>
	/// <param name="y1">y koñca statka</param>
	/// <returns>Zwraca wektor w którym przechowuje wspó³rzêdne koñca statka</returns>
	std::vector<int> random_direction(int ship_length, int random_number, int x, int y, int x1, int y1);
	/// <summary>
	/// Liczba statków
	/// </summary>
	int number_of_ships;
	/// <summary>
	/// Metoda ta ustawia iloœæ statków przed rozgrywk¹
	/// </summary>
	/// <param name="a">Liczba staków 5 masztowych</param>
	/// <param name="b">Liczba staków 4 masztowych</param>
	/// <param name="c">Liczba staków 3 masztowych</param>
	/// <param name="d">Liczba staków 2 masztowych</param>
	/// <param name="e">Liczba staków 1 masztowych</param>
	void set_starting_quantity(int a, int b, int c, int d, int e);
	/// <summary>
	/// Metoda ustawia tryb gry przed rozgrywk¹
	/// </summary>
	void Who_play();
	/// <summary>
	/// Metoda ustawia pomocnicze zmienne
	/// </summary>
	void Set_ships();
	/// <summary>
	/// Metoda odpowiada za strzelanie
	/// </summary>
	/// <param name="Player_Board">Obiekt klasy Board</param>
	/// <param name="Computer_Board">Obiekt klasy Board</param>
	void Shooting(Board* Player_Board, Board* Computer_Board);
	/// <summary>
	/// Zmienna przechowuj¹ca iloœæ statków 1 masztowych
	/// </summary>
	int ship1;
	/// <summary>
	/// Zmienna przechowuj¹ca iloœæ statków 2 masztowych
	/// </summary>
	int ship2;
	/// <summary>
	/// Zmienna przechowuj¹ca iloœæ statków 3 masztowych
	/// </summary>
	int ship3;
	/// <summary>
	/// Zmienna przechowuj¹ca iloœæ statków 4 masztowych
	/// </summary>
	int ship4;
	/// <summary>
	/// Zmienna przechowuj¹ca iloœæ statków 5 masztowych
	/// </summary>
	int ship5;
	/// <summary>
	/// Zmienna pomocnicza przechowuj¹ca iloœæ statków 1 masztowych
	/// </summary>
	int ship1_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj¹ca iloœæ statków 2 masztowych
	/// </summary>
	int ship2_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj¹ca iloœæ statków 3 masztowych
	/// </summary>
	int ship3_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj¹ca iloœæ statków 4 masztowych
	/// </summary>
	int ship4_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj¹ca iloœæ statków 5 masztowych
	/// </summary>
	int ship5_2;
	
public:
	/// <summary>
	/// 
	/// </summary>
	Game();
	~Game();
	/// <summary>
	/// Metoda odpowiada za g³own¹ rozgrywkê
	/// </summary>
	void Run();


	Board gracz1;
	Ship ships;
	Board gracz2;
	Ship ships2;
};

