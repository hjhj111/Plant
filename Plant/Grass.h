#pragma once
#include<list>

#include<graphics.h>

class Grass
{
public:
	Grass(int row, int col,int size,int width,int height)
		:row_(row),
		col_(col),
		size_(size),
		width_(width),
		height_(height)
	{
		loadimage(&image, _T("background.jpg"));
	}

	void Show();
public:
	int row_;
	int col_;
	int size_;
	int width_;
	int height_;	

	IMAGE image;
	bool background_shown_ = false;
};

