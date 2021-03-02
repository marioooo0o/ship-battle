#pragma once
#include <iostream>
#include "Ship.h"
#include <vector>
/// <summary>
/// Klasa obs�uguje plansze  
/// </summary>
class Board
{
private:
    /// <summary>
    /// Wektor w kt�rym przechowuje statki gracza
    /// </summary>
    std::vector<Ship> statki;
	/// <summary>
	/// Wektor w kt�rym przechowuje mape/plansze 
	/// </summary>
	std::vector<std::vector<char>> mapa;
	/// <summary>
	/// Wektor na kt�rym b�dziemy operowa� podczas gry i zaznacza� na nim strzelone pola
	/// </summary>
	std::vector<std::vector<char>> rozgrywka;
	/// <summary>
	/// Zmienna ta przechowuje liczbe column planszy
	/// </summary>
	int numbers_of_columns;
	/// <summary>
	/// Zmiennna ta przechowuje liczbe wierszy planszy
	/// </summary>
	int numbers_of_rows;
	/// <summary>
	/// Zmienna ta daje informacje czy dane pole zosta�o strzelone
	/// </summary>
	bool shooting = false;
 
	
public:
	/// <summary>
	/// Inicjalizacja mapy
	/// </summary>
	void Init_Map();
	/// <summary>
	/// Ustalenie rozmiaru planszy
	/// </summary>
	void Type_Board();
	/// <summary>
	/// Wy�wietlenie mapy
	/// </summary>
	/// <param name="a">wybor planszy kt�ra ma by� wy�wietlona</param>
	void Print_Map(int a);
	/// <summary>
	/// Aktualizacja wektora mapa o nowe statki
	/// </summary>
	void Update();
	/// <summary>
	/// Metoda ta dodaje nowy statek do wektora statki i aktualizuje mape
	/// </summary>
	/// <param name="pirat">Statek - obiekt klasy staki </param>
	void Add(Ship pirat);
	/// <summary>
	/// Metoda ta ustawia liczbe kolumn
	/// </summary>
	/// <param name="column">liczba kolumn</param>
	void set_numbers_of_columns(int column);
	/// <summary>
	/// Metoda ta ustawia liczbe wierszy
	/// </summary>
	/// <param name="rows">liczba wierszy</param>
	void set_numbers_of_rows(int rows);
	/// <summary>
	/// Metoda zwraca liczbe kolumn
	/// </summary>
	/// <returns>liczba kolumn</returns>
	int get_numbers_of_columns();
	/// <summary>
	/// Metoda zwraca liczbe wierszy
	/// </summary>
	/// <returns>liczba wierszy</returns>
	int get_numbers_of_rows();
	/// <summary>
	/// Metoda ta ustawia zmienn� shooting 
	/// </summary>
	/// <param name="shooting">zmienna odpowiada za informacje czy dane pole na planszy zosta�o strzelone</param>
	void Set_shooting(bool shooting);
	/// <summary>
	/// Metoda zwraca warto�� zmiennej shooting
	/// </summary>
	/// <returns>zmienna odpowiada za informacje czy dane pole na planszy zosta�o strzelone</returns>
	bool Get_shooting();
	/// <summary>
	/// Metoda ta ma za zadanie da� informacj� czy na planszy zosta�y jeszcze jakies niesprzelone statki 
	/// </summary>
	/// <returns>Zwraca prawde je�li zosta� jeszcze jakis statek w przeciwnym razie zwraca fa�sz</returns>
	bool Is_alive();
	/// <summary>
	/// Zmienna ta ma za zadanie da� informacj� czy gracz jest komputerem
	/// </summary>
	bool Is_Computer=false;
	/// <summary>
	/// Metoda ta zmienia warto�ci wsp�rz�dnych na mapie w zale�no�ci czy pole zosta�o trafione czy nie
	/// </summary>
	/// <param name="x">wsp�rz�dna x</param>
	/// <param name="y">wsp�rz�dna y</param>
	/// <param name="symbol">znak na jaki ma by� zamieniony dany punkt na planszy</param>
	/// <param name="wybor">wybor planszy: mapa czy rozgrywka </param>
	void Change_value(int x, int y, char symbol, int wybor);
	/// <summary>
	/// Metoda wybiera pole z mapy ustawionych statk�w
	/// </summary>
	/// <param name="x">wsp�rz�dna x</param>
	/// <param name="y">wsp�rz�dna y</param>
	/// <returns>zwraca znak danego pola</returns>
	char get_at(int x, int y);//pobieram pole z mapy ustawionych statkow
	/// <summary>
	/// Metoda wybiera pole z mapy rozgrywki 
	/// </summary>
	/// <param name="x">wsp�rz�dna x</param>
	/// <param name="y">wsp�rz�dna y</param>
	/// <returns></returns>
	char get_place(int x, int y);//pobieram pole z mapy strzeleckiej
	/// <summary>
	/// Metoda sprawdza czy mo�na doda� statek do planszy o wsp�rz�dnych podanych w obiekcie pirat
	/// </summary>
	/// <param name="pirat">obiekt klasy Ship</param>
	/// <returns>zwraca prawd� je�li mo�na doda� statek o danych wsp�rz�dnych</returns>
	bool Is_Add(Ship pirat);
	/// <summary>
	/// 
	/// </summary>
	Board();
	~Board();
};

