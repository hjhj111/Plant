#pragma once
#include<vector>
#include<list>
#include<memory>
using namespace std;

#include "Config.h"
#include "Plant.h"
#include "Zombie.h"



class Plant1:public Plant
{
public:
	Plant1(Bullet bullet_origin, int x, int y, int interval, float speed,
		int y_max, const string& name = "plant1", bool bullet = true)
		:Plant(bullet_origin,x,y,interval,speed,y_max,name,bullet)
	{
		loadimage(&image_, _T("plant1.jpg"), 0, 0, true);
	}	
};

class Plant2 :public Plant
{
public:
	Plant2(Bullet bullet_origin, int x, int y, int interval, float speed,
		int y_max, const string& name = "plant2", bool bullet = true)
		:Plant(bullet_origin, x, y, interval, speed, y_max, name, bullet)
	{
		loadimage(&image_, _T("plant2.jpg"), 0, 0, true);
	}
};

class Plant3 :public Plant
{
public:
	Plant3(Bullet bullet_origin, int x, int y, int interval, float speed,
		int y_max, const string& name = "plant3", bool bullet = true)
		:Plant(bullet_origin, x, y, interval, speed, y_max, name, bullet)
	{
		loadimage(&image_, _T("plant3.jpg"), 0, 0, true);
	}
};

class Plant4 :public Plant
{
public:
	Plant4(Bullet bullet_origin, int x, int y, int interval, float speed,
		int y_max, const string& name = "plant4", bool bullet = true)
		:Plant(bullet_origin, x, y, interval, speed, y_max, name, bullet)
	{
		loadimage(&image_, _T("plant4.jpg"), 0, 0, true);
	}
};

class Plants
{
public:
	Plants()
	{
		//for (int i = 0; i < col; i++)
		//{
		//	plants_.emplace_back(Plant(i * size_grid + size_grid / 2,
		//		height_map - size_grid / 2,
		//		300, 0.1, width_map));
		//}

		Bullet bullet_origin;
		plants_.emplace_back(Plant(bullet_origin,0 * size_grid + size_grid / 2,
			height_map - size_grid / 2,
			300000, 0.0001, width_map));

		auto show1 = [](int x_, int y_, int width_, int height_)
		{
			rectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
		};
		Bullet bullet_origin1(show1);
		plants_.emplace_back(Plant1(bullet_origin1, 1 * size_grid + size_grid / 2,
			height_map - size_grid / 2,
			300000, 0.0001, width_map));

		auto show2 = [](int x_, int y_, int width_, int height_)
		{
			line(x_ - width_ / 2,y_, x_ + width_ / 2, y_);
			//rectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
		};
		Bullet bullet_origin2(show2);
		plants_.emplace_back(Plant2(bullet_origin2, 2 * size_grid + size_grid / 2,
			height_map - size_grid / 2,
			300000, 0.0001, width_map));

		auto show3 = [](int x_, int y_, int width_, int height_)
		{
			line(x_, y_ - height_ / 2, x_, y_ + height_ / 2);
			//rectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
		};
		Bullet bullet_origin3(show3);
		plants_.emplace_back(Plant3(bullet_origin3, 3 * size_grid + size_grid / 2,
			height_map - size_grid / 2,
			300000, 0.0001, width_map));

		auto show4 = [](int x_, int y_, int width_, int height_)
		{
			ellipse(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
			//rectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
		};
		Bullet bullet_origin4(show4);
		plants_.emplace_back(Plant4(bullet_origin4, 4 * size_grid + size_grid / 2,
			height_map - size_grid / 2,
			300000, 0.0001, width_map));
	}
	void Action();
	void Show();
	void AttachZombies(list<Zombie>& zombies_ptr);
public:
	vector<Plant> plants_;
	bool plants_list_shown=false;
	//ÔÔÖÖ
	int chosen_col_=-1;
	vector<Plant> plants_planted_;
	vector<bool> plants_planted_shown;

	shared_ptr<list<Zombie>> zombies_ptr_;
};

