#include <graphics.h>
#include "Plants.h"
#include "Grass.h"
#include "Zombies.h"
#include "Config.h"
#include "Cars.h"

//#include<Windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")//×¢£º°´Ë³ÐòÐ´

using namespace std;

//const int width = 1200;
//const int height = 600;

//const int plant_size = 20;

int main()
{	
	initgraph(width_map, height_map,SHOWCONSOLE);
	//COLORREF bk()
	//setbkcolor(GREEN);
	setbkmode(TRANSPARENT);
	//Plant plant(20, 20, 300, 0.1, width_map);
	Grass grass(row, col, size_grid, width_map, height_map);
	Zombies zombies(2000000,0.0001);
	Plants plants;
	plants.AttachZombies(zombies.zombies_);
	Cars cars;
	cars.AttachZombies(zombies.zombies_);

	mciSendString(_T("play back.mp3 repeat"), 0, 0, 0);
	while (true)
	{
		//Sleep(10);
		BeginBatchDraw();
		grass.Show();
		plants.Show();
		zombies.Show();
		cars.Show();
		EndBatchDraw();
	}
	
	getchar();
	return 0;
}