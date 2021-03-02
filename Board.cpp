#include "Board.h"
//inicjalizacja mapy
void Board::Init_Map()
{
    for (int i = 0; i < numbers_of_columns; i++)
    {
		std::vector<char> vec;
		for (int j = 0; j < numbers_of_rows; j++)
		{
			vec.push_back('~');
		}
        mapa.push_back(vec);
		rozgrywka.push_back(vec);
		vec.clear();
    }
}
//wyswietlanie mapy
void Board::Print_Map(int a)
{
	if (a == 1)
	{
		for (int i = 0; i < numbers_of_columns; i++)
		{
			for (int j = 0; j < numbers_of_rows; j++)
			{
				std::cout << mapa[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	if (a == 2)
	{
		for (int i = 0; i < numbers_of_columns; i++)
		{
			for (int j = 0; j < numbers_of_rows; j++)
			{
				std::cout << rozgrywka[i][j] << " ";
			}
			std::cout << std::endl;
		}

	}
}
//aktualizowanie mapy
void Board::Update()
{
	int temp = 'a';
	
	for (int i = 0; i < statki.size(); i++)
	{
		for (int j = 0; j < statki[i].punkty.size(); j++)
		{
			int x=statki[i].punkty[j].x;
			int y= statki[i].punkty[j].y;
			mapa[x][y] = (char)temp;
		}
		temp++;
	}
}

//dodawanie statkow do planszy
void Board::Add(Ship pirat)
{

	if (Is_Add(pirat) == true)
	{
		{
			statki.push_back(pirat);
			this->Update();
		}
	}
	else
	{
		std::cout << "Blad dodawania statku." << std::endl;
	}
}

//set/get
void Board::set_numbers_of_columns(int column)
{
	this->numbers_of_columns = column;
}
void Board::set_numbers_of_rows(int rows)
{
	this->numbers_of_rows = rows;
}
int Board::get_numbers_of_columns()
{
	return numbers_of_columns;
}
int Board::get_numbers_of_rows()
{
	return numbers_of_rows;
}

void Board::Set_shooting(bool shooting)
{
	this->shooting = shooting;
}
bool Board::Get_shooting()
{
	return shooting;
}
//koniec set/get
//metoda zwraca inforamacje czy na planszy stoi nie zatopiony jeszcze statek
bool Board::Is_alive()
{

	for (auto&v : mapa)
	{
		for (auto&pole : v)
		{
			if (pole >= 'a' && pole <= 'z')return true;
			
		}
	}
	return false;
}
//zmienia znaki na planszy
void Board::Change_value(int x, int y, char symbol, int wybor)
{
	if ((x >= 0 && x < numbers_of_rows) && (y >= 0 && y < numbers_of_columns))
	{
		//zmiana pola na swojej planszy
		if (wybor == 1)
		{
			rozgrywka[x][y] = symbol;
		}
		//zmiana pola na planszy ze statkami
		if (wybor == 2)
		{
			mapa[x][y] = symbol;
		}
	}
}
//metoda zwraca znak z planszy mapa
char Board::get_at(int x, int y)
{
	if ((x >= 0 && x < numbers_of_rows) && (y >= 0 && y < numbers_of_columns))
	{
		return mapa[x][y];
	}
	else
	{
		std::cout << "Podane pole jest poza plansza";
		return '%';
	}
		
}
//metoda zwraca znak z planszy rozgrywka
char Board::get_place(int x, int y)
{
	if ((x >= 0 && x < numbers_of_rows) && (y >= 0 && y < numbers_of_columns))
	{
		return rozgrywka[x][y];
	}
	else
	{
		std::cout << "Podane pole jest poza plansza";
		return '%';
	}
}
//sprawdzanie czy mozna miejsca dookola czy mozna dodac statek
bool Board::Is_Add(Ship pirat)
{
	for (int i = 0; i < pirat.punkty.size(); i++)
	{
		int x_pir=pirat.punkty[i].x;
		int y_pir = pirat.punkty[i].y;
		//lewy górny
		if (x_pir - 1 >= 0 && y_pir - 1 >= 0)
		{
			if (mapa[x_pir-1][y_pir-1] != '~')return false;
		}
		//nad stakiem
		if (x_pir - 1 >= 0 && y_pir >= 0)
		{	
			if (mapa[x_pir-1][y_pir] != '~')return false;
		}
		//prawy górny nad statkiem
		if (x_pir - 1 >= 0 && y_pir + 1 >= 0)
		{	//zabezpieczenie przed out of range
			//prawy strona mapy
			if (y_pir == numbers_of_columns - 1 )
			{

			}
			else
				if (mapa[x_pir - 1][y_pir + 1] != '~')return false;
		}
		//lewy obok
		if (x_pir >= 0 && y_pir - 1 >= 0)
		{
			if (mapa[x_pir ][y_pir-1] != '~')return false;
		}
		//prawy obok
		if (x_pir  >= 0 && y_pir + 1 >= 0)
		{
			if (y_pir == numbers_of_columns - 1)
			{

			}
			else
				if (mapa[x_pir ][y_pir + 1] != '~')return false;
		}
		//lewy dolny 
		if (x_pir + 1 >= 0 && y_pir - 1 >= 0)
		{
			if (x_pir == numbers_of_rows - 1 )
			{
				
			}
			else
				if (mapa[x_pir + 1][y_pir - 1] != '~')return false;
		}
		//dol
		if (x_pir + 1 >= 0 && y_pir >= 0)
		{
			if (x_pir == numbers_of_rows - 1)
			{

			}
			else
				if (mapa[x_pir+1][y_pir] != '~')return false;
		}
		//prawy dolny
		if (x_pir + 1 >= 0 && y_pir + 1 >= 0)
		{
			if (x_pir == numbers_of_rows-1 || y_pir == numbers_of_columns-1)
			{
				
			}
			else
				if (mapa[x_pir + 1][y_pir + 1] != '~')return false;
		}
		if (mapa[x_pir][y_pir] != '~')return false;
	}
	return true;
}

//Ustawienie rozmiaru planszy 10x10
void Board::Type_Board()
{
	std::cout << "plansze 10x10"<<std::endl;
	numbers_of_columns = 10;
	numbers_of_rows = 10;
  
}

Board::Board()
{
}


Board::~Board()
{
}
