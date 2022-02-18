#pragma once
#include <functional>
#include <graphics.h>
using namespace std;

using BulletShowFun = function<void(int x_, int y_, int width_, int height_)>;

inline void show0(int x_, int y_, int width_, int height_)
{
	printf("bullet\n");
	circle(x_, y_, min(width_ / 2, height_ / 2));
}

class Bullet
{
public:
	Bullet(BulletShowFun show=show0,int x=500, int y=500, int width = 10, int height = 6)
		:show_(show),
		x_(x),
		y_(y),
		width_(width),
		height_(height)
	{

	}
	void Show();
	void Clear();
public:
	BulletShowFun show_;
	int x_;
	int y_;
	int width_;
	int height_;
};

