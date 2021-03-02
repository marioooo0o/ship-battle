#include "Game.h"


Game::Game()
{
	
}


Game::~Game()
{

}
//glowna petla projektu
void Game::Run()
{
	std::cout << "Witaj w grze statki!\n Wygenerowano ";
	gracz1.Type_Board();
	this->set_starting_quantity(ship5, ship4, ship3, ship2, ship1);
	number_of_ships = ship1 + ship2 + ship3 + ship4 + ship5;
	this->Set_ships();
	this->init();
	srand(time(NULL));
	this->Who_play();
	std::cout << "Mapy zostaly poprawnie dodanie zaczynamy strzelanie:" << std::endl;
	while (1)
	{
		Shooting(&gracz1, &gracz2);
		std::cout << "Mapa gracza nr 1:" << std::endl;
		gracz1.Print_Map(2);
		Sleep(2500);
		while (gracz1.Get_shooting())
		{
			Shooting(&gracz1, &gracz2);
			if (gracz2.Is_alive() != true)break;	
		}
		if (gracz2.Is_alive() != true)break;

		//Gracz2 strzela	
		Shooting(&gracz2, &gracz1);
		std::cout << "Mapa gracza nr 2:"<<std::endl;
		gracz2.Print_Map(2);
		Sleep(2500);
		while (gracz2.Get_shooting())
		{
			Shooting(&gracz2, &gracz1);
			if (gracz1.Is_alive() != true)break;
		}
		if (gracz1.Is_alive() != true)break;

	}
	if (gracz1.Is_alive() == true)
	{
		std::cout << "Wygral gracz 1"<<std::endl;
	}
	else if (gracz2.Is_alive() == true)
	{
		std::cout << "Wygral gracz 2"<<std::endl;
	}
	else std::cout << "Remis" << std::endl;
	std::cout << "Koniec";
	getchar();
	Sleep(50000);
}
//inicjalizacja dla planszy drugiego gracza
void Game::init()
{
	rows = gracz1.get_numbers_of_rows();
	column = gracz1.get_numbers_of_columns();
	gracz2.set_numbers_of_rows(rows);
	gracz2.set_numbers_of_columns(column);

}
//metoda ustawiania statkow gracza
void Game::Set_Player_Ships(Board* Player_Board, Ship player_ship)
{
	this->Set_ships();
	number_of_ships = ship1 + ship2 + ship3 + ship4 + ship5;
	Player_Board->Is_Computer = false;
	Player_Board->Init_Map();
	int temp=0;//ile statkow zbudowano
	int x, y, x1, y1;

	while (temp < number_of_ships)
	{
		std::cout << "Podaj x poczatkowe: ";
		std::cin >> x;
		std::cout << "Podaj y poczatkowe: ";
		std::cin >> y;
		std::cout << "Podaj x koncowe: ";
		std::cin >> x1;
		std::cout << "Podaj y koncowe: ";
		std::cin >> y1;
		player_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
		if (player_ship.ship_size == 5  && ship5 > 0 )
		{
			
			if (Player_Board->Is_Add(player_ship) == true)
			{
				temp++;
				ship5--;
			}
			Player_Board->Add(player_ship);
			
			std::cout << "Liczba 5-cio masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
		}
		if (player_ship.ship_size == 4 && ship4 > 0)
		{
			if (Player_Board->Is_Add(player_ship) == true)
			{
				temp++;
				ship4--;
			}
			Player_Board->Add(player_ship);
			if (ship4 == 0)
			{
				std::cout << "Liczba 4-o masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
		if (player_ship.ship_size == 3 && ship3 > 0)
		{		
			if (Player_Board->Is_Add(player_ship) == true)
			{
				temp++;
				ship3--;
			}
			Player_Board->Add(player_ship);
			if (ship3 == 0)
			{
				std::cout << "Liczba 3-y masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}

		}
		if (player_ship.ship_size == 2 && ship2_2 > 0)
		{
			if (Player_Board->Is_Add(player_ship) == true)
			{
				temp++;
				ship2--;
			}
			Player_Board->Add(player_ship);
			if (ship2 == 0)
			{
				std::cout << "Liczba 2-u masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
		if (player_ship.ship_size == 1 && ship1 > 0)
		{
			if (Player_Board->Is_Add(player_ship) == true)
			{
				temp++;
				ship1--;
			}
			Player_Board->Add(player_ship);
			if (ship1 == 0)
			{
				std::cout << "Liczba 1-no masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
		Player_Board->Print_Map(1);
	}
	

}
//metoda ustawiana statkow komputera
void Game::Set_Computer_Ships(Board * Computer_Board, Ship computer_ship)
{
	this->Set_ships();
	this->number_of_ships = ship1 + ship2 + ship3 + ship4 + ship5;
	Computer_Board->Is_Computer=true;
	Computer_Board->Init_Map();
	int ships_bulit = 0;//ile statkow zbudowano
	int x = 0, y = 0, x1 = 0, y1 = 0;
	int direction;
	
	
	while (ships_bulit < number_of_ships)
	{
			while (ship5 > 0)
			{
				x = rand() % gracz1.get_numbers_of_rows();
				y = rand() % gracz1.get_numbers_of_columns();
				direction = rand() % 4;
				std::vector<int>wspolrzedne=random_direction(5, direction, x, y, x1, y1);
				x1 = wspolrzedne[0];
				y1 = wspolrzedne[1];
				computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
				while ((x1 < 0 || x1 >= gracz1.get_numbers_of_rows())|| (y1<0 || y1 >= gracz1.get_numbers_of_columns()))
				{
					x = rand() % gracz1.get_numbers_of_rows();
					y = rand() % gracz1.get_numbers_of_columns();
					direction = rand() % 4;
					std::vector<int>wspolrzedne = random_direction(5, direction, x, y, x1, y1);
					x1 = wspolrzedne[0];
					y1 = wspolrzedne[1];
					computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
				}

				if (Computer_Board->Is_Add(computer_ship) == true)
				{
					ships_bulit++;
					ship5--;
					Computer_Board->Add(computer_ship);
				}
				
				if (ship5 == 0)
				{
					std::cout << "Liczba 5-cio masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
				}
			}
			
	
		//dodanie 4 masztowgego
		while (ship4 > 0)
		{
			x = rand() % gracz1.get_numbers_of_rows();
			y = rand() % gracz1.get_numbers_of_columns();
			direction = rand() % 4;
			std::vector<int>wspolrzedne = random_direction(4, direction, x, y, x1, y1);
			x1 = wspolrzedne[0];
			y1 = wspolrzedne[1];
			computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			while ((x1 < 0 || x1 >= gracz1.get_numbers_of_rows()) || (y1 < 0 || y1 >= gracz1.get_numbers_of_columns()))
			{
				x = rand() % gracz1.get_numbers_of_rows();
				y = rand() % gracz1.get_numbers_of_columns();
				direction = rand() % 4;
				std::vector<int>wspolrzedne = random_direction(4, direction, x, y, x1, y1);
				x1 = wspolrzedne[0];
				y1 = wspolrzedne[1];
				computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			}

			if (Computer_Board->Is_Add(computer_ship) == true)
			{
				ships_bulit++;
				ship4--;
				Computer_Board->Add(computer_ship);
			}
			if (ship4 == 0)
			{
				std::cout << "Liczba 4-o masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
		//dodanie 3 masztowego
		while (ship3 > 0)
		{
			x = rand() % gracz1.get_numbers_of_rows();
			y = rand() % gracz1.get_numbers_of_columns();
			direction = rand() % 4;
			std::vector<int>wspolrzedne = random_direction(3, direction, x, y, x1, y1);
			x1 = wspolrzedne[0];
			y1 = wspolrzedne[1];
			computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			while ((x1 < 0 || x1 >= gracz1.get_numbers_of_rows()) || (y1 < 0 || y1 >= gracz1.get_numbers_of_columns()))
			{
				x = rand() % gracz1.get_numbers_of_rows();
				y = rand() % gracz1.get_numbers_of_columns();
				direction = rand() % 4;
				std::vector<int>wspolrzedne = random_direction(3, direction, x, y, x1, y1);
				x1 = wspolrzedne[0];
				y1 = wspolrzedne[1];
				computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			}

			if (Computer_Board->Is_Add(computer_ship) == true)
			{
				ships_bulit++;
				ship3--;
				Computer_Board->Add(computer_ship);
			}
			if (ship3 == 0)
			{
				std::cout << "Liczba 3-y masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
		//dodanie 2 masztowego
		while (ship2 > 0)
		{	
			x = rand() % gracz1.get_numbers_of_rows();
			y = rand() % gracz1.get_numbers_of_columns();
			direction = rand() % 4;
			std::vector<int>wspolrzedne = random_direction(2, direction, x, y, x1, y1);
			x1 = wspolrzedne[0];
			y1 = wspolrzedne[1];
			computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			while ((x1 < 0 || x1 >= gracz1.get_numbers_of_rows()) || (y1 < 0 || y1 >= gracz1.get_numbers_of_columns()))
			{
				x = rand() % gracz1.get_numbers_of_rows();
				y = rand() % gracz1.get_numbers_of_columns();
				direction = rand() % 4;
				std::vector<int>wspolrzedne = random_direction(2, direction, x, y, x1, y1);
				x1 = wspolrzedne[0];
				y1 = wspolrzedne[1];
				computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			}

			if (Computer_Board->Is_Add(computer_ship) == true)
			{
				ships_bulit++;
				ship2--;
				Computer_Board->Add(computer_ship);
			}

			if (ship2 == 0)
			{
				std::cout << "Liczba 2-u masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
		//dodanie jedno masztowgo
		while (ship1 > 0)
		{
			x = rand() % gracz1.get_numbers_of_rows();
			y = rand() % gracz1.get_numbers_of_columns();
			direction = rand() % 4;
			std::vector<int>wspolrzedne = random_direction(1, direction, x, y, x1, y1);
			x1 = wspolrzedne[0];
			y1 = wspolrzedne[1];
			computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			while ((x1 < 0 || x1 >= gracz1.get_numbers_of_rows()) || (y1 < 0 || y1 >= gracz1.get_numbers_of_columns()))
			{
				x = rand() % gracz1.get_numbers_of_rows();
				y = rand() % gracz1.get_numbers_of_columns();
				direction = rand() % 4;
				std::vector<int>wspolrzedne = random_direction(1, direction, x, y, x1, y1);
				x1 = wspolrzedne[0];
				y1 = wspolrzedne[1];
				computer_ship = Ship(Pozycja(x, y), Pozycja(x1, y1));
			}

			if (Computer_Board->Is_Add(computer_ship) == true)
			{
				ships_bulit++;
				ship1--;
				Computer_Board->Add(computer_ship);
			}
			if (ship1 == 0)
			{
				std::cout << "Liczba 1-no masztowych staktow mozliwych do wstawienia zostala wykorzystana." << std::endl;
			}
		}
	}
	Computer_Board->Print_Map(1);
	
	


}

//metoda losuje w jakim kierunku postawic koniec statka
std::vector<int> Game::random_direction(int ship_length, int random_number, int x, int y, int x1, int y1)
{
	std::vector<int> result;
	if (random_number == 0)
	{
		x1 = x - ship_length+1;
		y1 = y;
		
	}
	else if (random_number == 1)
	{
		x1 = x;
		y1 = y + ship_length - 1;
	}
	else if (random_number == 2)
	{
		x1 = x + ship_length - 1;
		y1 = y;
	}
	else
	{
		x1 = x;
		y1 = y - ship_length + 1;
	}
	result.push_back(x1);
	result.push_back(y1);
	return result;
}
//metoda ustawia ilosc statkow przed rozgrywka
void Game::set_starting_quantity(int a, int b, int c, int d, int e)
{
	std::cout << "Podaj jakie rozmiary statkow chcesz umiescic na planszy:" << std::endl;
	std::cout << "Czy chcesz dodac jakies statki 5 - cio masztowe?" << std::endl;
	std::cout << "Jesli tak to ile: ";
	std::cin >> a;
	while (a < 0 || a>=2)
	{
		std::cout << "Liczba statkow 5 - cio masztowych musi byc liczba nieujemna, mniesza od 2\nPodaj liczbe statkow 5 - cio masztowych jeszcze raz:";
		std::cin >> a;
	}

	this->ship5 = a;
	this->ship5_2 = ship5;
	std::cout << "Czy chcesz dodac jakies statki 4 - o masztowe?" << std::endl;
	std::cout << "Jesli tak to ile: ";
	std::cin >> b;
	while (b <= 0 || b>2)
	{
		std::cout << "Na planszy musisz postawic jeden lub 2 statki 4 - o masztowe!";
		std::cin >> b;
	}
	this->ship4 = b;
	this->ship4_2 = ship4;


	std::cout << "Czy chcesz dodac jakies statki 3-y masztowe?" << std::endl;
	std::cout << "Jesli tak to ile: ";
	std::cin >> c;
	while (c <= 0 || c>=3)
	{
		std::cout << "Na planszy musisz postawic conajmniej jeden statek 3-y masztowy!";
		std::cin >> c;
	}
	
	this->ship3 = c;
	this->ship3_2 = ship3;

	std::cout << "Czy chcesz dodac jakies statki 2-u masztowe?" << std::endl;
	std::cout << "Jesli tak to ile: ";
	std::cin >> d;
	while (d <= 0 || d>=4)
	{
		std::cout << "Na planszy musisz postawic nieujemna i mniejsza od 4 liczbe statow 2-u masztowych!";
		std::cin >> d;
	}
	this->ship2 = d;
	this->ship2_2 = ship2;

	std::cout << "Czy chcesz dodac jakies statki 1-dno masztowe?" << std::endl;
	std::cout << "Jesli tak to ile: ";
	std::cin >> e;
	while (e <= 0 || e>=5)
	{
		std::cout << "Na planszy musisz postawic nieujemna mniejsza od 5 liczbe statkow 1-dno masztowych!";
		std::cin >> e;
	}
	this->ship1 = e;
	this->ship1_2 = ship1;
}
//metoda przed rozgrywka pozwalajaca wybrac tryb gry
void Game::Who_play()
{
	int wybor;
	std::cout << "Podaj jak chcesz zagrac:" << std::endl;
	std::cout << "1. Grasz przeciwko komputerowi!." << std::endl;
	std::cout << "2. Komputer vs komputer!.\nWybierz 1 lub 2:" << std::endl;
	std::cin >> wybor;
	if (wybor == 1)
	{
		std::cout << "Gracz1 mapa: " << std::endl;
		Game::Set_Player_Ships(&gracz1, ships);
		std::cout << "Gracz2 mapa: " << std::endl;
		Game::Set_Computer_Ships(&gracz2, ships2);
	}
	else if (wybor == 2)
	{
		std::cout << "Gracz1 mapa: " << std::endl;
		Game::Set_Computer_Ships(&gracz1, ships);
		std::cout << "Gracz2 mapa: " << std::endl;
		Game::Set_Computer_Ships(&gracz2, ships2);
	}
	else
		std::cout << "Wybor poza zakresem.";
	while (wybor != 1 && wybor != 2)
	{
		std::cout << "Podaj wybor jeszcze raz:";
		std::cin >> wybor;
	}
}
//set pomocniczy
void Game::Set_ships()
{
	this->ship1 = ship1_2;
	this->ship2 = ship2_2;
	this->ship3 = ship3_2;
	this->ship4 = ship4_2;
	this->ship5 = ship5_2;
}
//metoda odpowiadajaca za strzelanie
void Game::Shooting(Board * Player_Board, Board * Computer_Board)
{

	Player_Board->Set_shooting(false);
	/*
	#-trafione
	%-poza plansza
	X-strzelone pole ale nie statek
	*/
	int x, y;
	char pole;
	char pole_mojej_planszy;
	bool temp;
	//wykluczenie strzelania w to samo miejsce i poza plansze
	do
	{
		if (Player_Board->Is_Computer)
		{
			x = rand() % Player_Board->get_numbers_of_rows();
			y = rand() % Player_Board->get_numbers_of_columns();
		}
		else
		{
			std::cout << "Podaj x: ";
			std::cin >> x;
			std::cout << "Podaj y: ";
			std::cin >> y;
		}

		pole = Computer_Board->get_at(x, y);
		pole_mojej_planszy = Player_Board->get_place(x, y);
		if (pole == '#' || pole == '%'|| pole_mojej_planszy =='X')
		{
			temp = true;
		}
		else
		{
			temp = false;
		}
	} while (temp);

	if (pole >= 'a' && pole <= 'z')
	{
		Player_Board->Change_value(x, y, '#', 1);
		Computer_Board->Change_value(x, y, '#', 2);
		Player_Board->Set_shooting(true);
		std::cout << "Trafiony!"<<std::endl;
	}
	else if (pole == '~')
	{
		Player_Board->Change_value(x, y, 'X', 1);
		Computer_Board->Change_value(x, y, 'X', 2);
	}
}
