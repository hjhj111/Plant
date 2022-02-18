#include "Grass.h"
#include "Config.h"
#include <graphics.h>

void Grass::Show()
{
	for (int i = 1; i < row_; i++)
	{
		line(0, i * size_, width_, i * size_);
	}
	for (int j = 1; j < col_; j++)
	{
		line(j * size_, 0, j * size_, height_ - size_grid);
	}
	
	//±³¾°
	if (!background_shown_)
	{
		//putimage(0, 0, &image);
		clearrectangle(0, 0, width_map, height_map);
		
		background_shown_ = true;
	}
	//setcolor(GREEN);
	//rectangle(0, 0, width_map, height_map);
	
}
