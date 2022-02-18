#include "Zombie.h"
#include<graphics.h>
#include <atlstr.h>
#include<string>

using namespace std;
void Zombie::Action()
{
	
}

void Zombie::Show()
{
	if (state_ == ZombieState::WALK)
	{
		//rectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
		putimage(x_ - width_ / 2, y_ - height_ / 2, &image1);
		
		//Sleep(100);
		
		//Sleep(100);
		
	}
	else if (state_ == ZombieState::HURT)
	{
		putimage(x_ - width_ / 2, y_ - height_ / 2, &image3);
	}
	else if (state_ == ZombieState::EAT)
	{
		//ellipse(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
		putimage(x_ - width_ / 2, y_ - height_ / 2, &image2);
	}	
	else if(state_==ZombieState::DIED)
	{
		putimage(x_ - width_ / 2, y_ - height_ / 2, &image3);
	}
	RECT r = { x_ - size_grid / 2 + 30, y_ - size_grid / 2 + 15 ,x_, y_ };
	settextcolor(RGB(255, 0, 0));
	drawtext(CA2T(to_string(life_).c_str()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

}

void Zombie::Clear()
{
	clearrectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
}

bool Zombie::Hit(int x, int y)
{
	if (x < x_ - width_ / 2)
	{
		return false;
	}
	if (x > x_ + width_ / 2)
	{
		return false;
	}
	if (y < y_ - height_ / 2)
	{
		return false;
	}
	if (y > y_ + height_ / 2)
	{
		return false;
	}
	return true;
}
