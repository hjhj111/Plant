#include "Bullet.h"
#include <graphics.h>
#include <stdio.h>


void Bullet::Show()
{
	show_(x_, y_, width_, height_);	
}

void Bullet::Clear()
{
	//clearrectangle(40, 0, 800, 40);
	clearrectangle(x_ - width_ / 2, y_ - height_ / 2, x_ + width_ / 2, y_ + height_ / 2);
}
