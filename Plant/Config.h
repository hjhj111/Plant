#pragma once
#include<chrono>
#include<random>

using namespace std;

extern int width_map;
extern int height_map;
extern int row;
extern int col;
extern int size_grid;

inline long long NowMs()
{
	return chrono::duration_cast<chrono::microseconds>
		(chrono::high_resolution_clock::now().time_since_epoch()).count();
}

inline unsigned int RandRow()
{
	//return 0;
	//return rand() % row;
	default_random_engine en(rand());
	uniform_int_distribution<unsigned int> dis(0, row - 2);
	return dis(en);
}

inline unsigned int RandLife()
{
	default_random_engine en(rand());
	uniform_int_distribution<unsigned int> dis(0, 500);
	return dis(en);
}

inline unsigned int RandHurt()
{
	default_random_engine en(rand());
	uniform_int_distribution<unsigned int> dis(10, 20);
	return dis(en);
}

inline int GetPlantCol(int x, int y)
{
	if (y<height_map && y>height_map - size_grid)
	{
		if (x < width_map && x>0)
		{
			return x / size_grid;
		}
	}
	return -1;
}

inline pair<int, int> GetPlantPos(int x, int y)
{
	if (y>0&& y<height_map - size_grid)
	{
		if (x < width_map && x>size_grid)
		{
			return make_pair(x / size_grid,y/size_grid);
		}
	}
	return make_pair(-1,-1);
}
