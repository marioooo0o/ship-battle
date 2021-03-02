#include "Ship.h"


Ship::Ship()
{
}
//konstruktor klasy
Ship::Ship(Pozycja pierwsza, Pozycja druga)
{
    bool poziom = false;
    bool pion = false;
	bool size = false;

    if (pierwsza.x == druga.x) 
    {
        poziom = true;
    } 

    if (pierwsza.y == druga.y)
    {
        pion = true;
    }

	if (poziom || pion)
	{
			if (poziom)
			{
				if(abs(pierwsza.y - druga.y)+1 <= max_size_of_ships)
				{
					if (pierwsza.y <= druga.y)
					{
						for (int i = pierwsza.y; i <= druga.y; i++)
						{
							punkty.push_back(Pozycja(pierwsza.x, i));
						}
					}
					else
					{
						for (int i = druga.y; i <= pierwsza.y; i++)
						{
							punkty.push_back(Pozycja(pierwsza.x, i));
						}
					}
					ship_size = (abs(pierwsza.y - druga.y) + 1);
				}
				else
					std::cout << "Podano niepoprawny statek"<<std::endl;
			}
			else if (pion)
			{
				if (abs(pierwsza.x - druga.x)+1 <= max_size_of_ships)
				{
					if (pierwsza.x <= druga.x)
					{
						for (int i = pierwsza.x; i <= druga.x; i++)
						{
							punkty.push_back(Pozycja(i, pierwsza.y));
						}
					}
					else
					{
						for (int i = druga.x; i <= pierwsza.x; i++)
						{
							punkty.push_back(Pozycja(i, pierwsza.y));
						}
					}
					ship_size = (abs(pierwsza.x - druga.x) + 1);
				}
				else
					std::cout << "Podano niepoprawny statek"<<std::endl;
			}
	}
	else
		std::cout << "Podano niepoprawny statek"<<std::endl;
	
    
}


