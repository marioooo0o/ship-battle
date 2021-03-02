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
/// G�owna klasa projektu odpowiadaj�ca za rozgrywk� 
/// </summary>
class Game
{
private:
	/// <summary>
	/// Ilo�� wierszy
	/// </summary>
	int rows;
	/// <summary>
	/// Ilo�� kolumn
	/// </summary>
	int column;
	/// <summary>
	/// Inicjalizacja paramet�w planszy dla drugiego gracza
	/// </summary>
	void init();
	/// <summary>
	/// Metoda ustawia statki gracza "cz�owieka"
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
	/// Metoda ta losuje w jakim kierunku ustawi� koniec statka
	/// </summary>
	/// <param name="ship_length">D�ugo�� statka</param>
	/// <param name="random_number">Losowa liczba odpowiadaj�ca za kierunek</param>
	/// <param name="x">x pocz�tka statka</param>
	/// <param name="y">y pocz�tka statka</param>
	/// <param name="x1">x ko�ca statka</param>
	/// <param name="y1">y ko�ca statka</param>
	/// <returns>Zwraca wektor w kt�rym przechowuje wsp�rz�dne ko�ca statka</returns>
	std::vector<int> random_direction(int ship_length, int random_number, int x, int y, int x1, int y1);
	/// <summary>
	/// Liczba statk�w
	/// </summary>
	int number_of_ships;
	/// <summary>
	/// Metoda ta ustawia ilo�� statk�w przed rozgrywk�
	/// </summary>
	/// <param name="a">Liczba stak�w 5 masztowych</param>
	/// <param name="b">Liczba stak�w 4 masztowych</param>
	/// <param name="c">Liczba stak�w 3 masztowych</param>
	/// <param name="d">Liczba stak�w 2 masztowych</param>
	/// <param name="e">Liczba stak�w 1 masztowych</param>
	void set_starting_quantity(int a, int b, int c, int d, int e);
	/// <summary>
	/// Metoda ustawia tryb gry przed rozgrywk�
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
	/// Zmienna przechowuj�ca ilo�� statk�w 1 masztowych
	/// </summary>
	int ship1;
	/// <summary>
	/// Zmienna przechowuj�ca ilo�� statk�w 2 masztowych
	/// </summary>
	int ship2;
	/// <summary>
	/// Zmienna przechowuj�ca ilo�� statk�w 3 masztowych
	/// </summary>
	int ship3;
	/// <summary>
	/// Zmienna przechowuj�ca ilo�� statk�w 4 masztowych
	/// </summary>
	int ship4;
	/// <summary>
	/// Zmienna przechowuj�ca ilo�� statk�w 5 masztowych
	/// </summary>
	int ship5;
	/// <summary>
	/// Zmienna pomocnicza przechowuj�ca ilo�� statk�w 1 masztowych
	/// </summary>
	int ship1_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj�ca ilo�� statk�w 2 masztowych
	/// </summary>
	int ship2_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj�ca ilo�� statk�w 3 masztowych
	/// </summary>
	int ship3_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj�ca ilo�� statk�w 4 masztowych
	/// </summary>
	int ship4_2;
	/// <summary>
	/// Zmienna pomocnicza przechowuj�ca ilo�� statk�w 5 masztowych
	/// </summary>
	int ship5_2;
	
public:
	/// <summary>
	/// 
	/// </summary>
	Game();
	~Game();
	/// <summary>
	/// Metoda odpowiada za g�own� rozgrywk�
	/// </summary>
	void Run();


	Board gracz1;
	Ship ships;
	Board gracz2;
	Ship ships2;
};

