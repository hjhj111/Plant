#pragma once
#include<vector>
#include<list>
#include<memory>

using namespace std;

#include "Car.h"
#include "Zombie.h"

class Cars
{
public:
	Cars()
	{
		for (int i = 0; i < row - 1; i++)
		{
			Car car(i);
			cars_.emplace_back(car);
		}
		
	}
	void Action();
	void Show();
	void AttachZombies(list<Zombie>& zombies_ptr);
	void ClearZombiesRow(int car_row);
public:
	vector<Car> cars_;
	//½©Ê¬½»»¥
	shared_ptr<list<Zombie>> zombies_ptr_;
};

