#pragma once
#include<graphics.h>
#include"Config.h"

enum class ZombieState
{
	WALK,
	HURT,
	EAT,
	DIED
};
class Zombie
{
public:
	Zombie(int row, int speed,int width=20, int height=30, ZombieState state = ZombieState::WALK)
		:row_(row),
		width_(width),
		height_(height),
		state_(state),
		speed_(speed),
		life_(RandLife())
	{
		x_ = width_map-size_grid/2;
		y_ = row_ * size_grid+size_grid/2;
		loadimage(&image1, _T("walk1.jpg"));
		loadimage(&image2, _T("eat1.jpg"));
		loadimage(&image3, _T("died1.jpg"));
	}
	virtual void Action();
	virtual void Show();
	virtual void Clear();
	bool Hit(int x, int y);
public:
	int x_;
	int y_;
	int row_;
	int width_;
	int height_;
	ZombieState state_;
	int life_=100;//ÉúÃüÖµ Âú·Ö100
	int speed_;

	IMAGE image1;
	IMAGE image2;
	IMAGE image3;
};

