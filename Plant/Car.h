#pragma once
#include<graphics.h>
#include "Config.h"

class Car
{
public:
	Car(int row)
		:row_(row),
		x_(size_grid/2)
	{
		loadimage(&image, _T("car.jpg"));
	}
	void Show();
	void Clear();
	bool Hit(int x, int y);
public:
	int row_;
	int x_;
	bool attacked = false;
	//int width_ = size_grid;
	//int height_ = size_grid;
	IMAGE image;
	bool car_shown_ = false;
};

