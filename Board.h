#pragma once
#include <iostream>
#include "Ship.h"
#include <vector>
/// <summary>
/// Klasa obs³uguje plansze  
/// </summary>
class Board
{
private:
    /// <summary>
    /// Wektor w którym przechowuje statki gracza
    /// </summary>
    std::vector<Ship> statki;
	/// <summary>
	/// Wektor w którym przechowuje mape/plansze 
	/// </summary>
	std::vector<std::vector<char>> mapa;
	/// <summary>
	/// Wektor na którym bêdziemy operowaæ podczas gry i zaznaczaæ na nim strzelone pola
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
	/// Zmienna ta daje informacje czy dane pole zosta³o strzelone
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
	/// Wyœwietlenie mapy
	/// </summary>
	/// <param name="a">wybor planszy która ma byæ wyœwietlona</param>
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
	/// Metoda ta ustawia zmienn¹ shooting 
	/// </summary>
	/// <param name="shooting">zmienna odpowiada za informacje czy dane pole na planszy zosta³o strzelone</param>
	void Set_shooting(bool shooting);
	/// <summary>
	/// Metoda zwraca wartoœæ zmiennej shooting
	/// </summary>
	/// <returns>zmienna odpowiada za informacje czy dane pole na planszy zosta³o strzelone</returns>
	bool Get_shooting();
	/// <summary>
	/// Metoda ta ma za zadanie daæ informacjê czy na planszy zosta³y jeszcze jakies niesprzelone statki 
	/// </summary>
	/// <returns>Zwraca prawde jeœli zosta³ jeszcze jakis statek w przeciwnym razie zwraca fa³sz</returns>
	bool Is_alive();
	/// <summary>
	/// Zmienna ta ma za zadanie daæ informacjê czy gracz jest komputerem
	/// </summary>
	bool Is_Computer=false;
	/// <summary>
	/// Metoda ta zmienia wartoœci wspó³rzêdnych na mapie w zale¿noœci czy pole zosta³o trafione czy nie
	/// </summary>
	/// <param name="x">wspó³rzêdna x</param>
	/// <param name="y">wspó³rzêdna y</param>
	/// <param name="symbol">znak na jaki ma byæ zamieniony dany punkt na planszy</param>
	/// <param name="wybor">wybor planszy: mapa czy rozgrywka </param>
	void Change_value(int x, int y, char symbol, int wybor);
	/// <summary>
	/// Metoda wybiera pole z mapy ustawionych statków
	/// </summary>
	/// <param name="x">wspó³rzêdna x</param>
	/// <param name="y">wspó³rzêdna y</param>
	/// <returns>zwraca znak danego pola</returns>
	char get_at(int x, int y);//pobieram pole z mapy ustawionych statkow
	/// <summary>
	/// Metoda wybiera pole z mapy rozgrywki 
	/// </summary>
	/// <param name="x">wspó³rzêdna x</param>
	/// <param name="y">wspó³rzêdna y</param>
	/// <returns></returns>
	char get_place(int x, int y);//pobieram pole z mapy strzeleckiej
	/// <summary>
	/// Metoda sprawdza czy mo¿na dodaæ statek do planszy o wspó³rzêdnych podanych w obiekcie pirat
	/// </summary>
	/// <param name="pirat">obiekt klasy Ship</param>
	/// <returns>zwraca prawdê jeœli mo¿na dodaæ statek o danych wspó³rzêdnych</returns>
	bool Is_Add(Ship pirat);
	/// <summary>
	/// 
	/// </summary>
	Board();
	~Board();
};

