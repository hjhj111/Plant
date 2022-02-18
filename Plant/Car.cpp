#include "Car.h"

void Car::Show()
{
	//if (!car_shown_)
	//{
	//	putimage(x_-size_grid/2, row_ * size_grid,&image);
	//}
	if (!attacked)
	{
		putimage(x_ - size_grid / 2, row_ * size_grid, &image);
	}
}

void Car::Clear()
{
	clearrectangle(x_ - size_grid / 2, row_ * size_grid, x_ + size_grid / 2, row_ * size_grid + size_grid);
}

bool Car::Hit(int x, int y)
{
	
	//if (x < x_ - width_ / 2)
	//{
	//	return false;
	//}
	if (x > size_grid)
	{
		return false;
	}
	if (y < row_*size_grid)
	{
		return false;
	}
	if (y > row_ * size_grid+size_grid)
	{
		return false;
	}
	return true;
}
