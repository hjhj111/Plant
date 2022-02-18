#pragma once
#include<list>

using namespace std;

#include "Zombie.h"

class Zombies
{
public:
	Zombies(int interval_new,float speed)
		:interval_new_(interval_new),
		speed_(speed),
		last_time_point_move_(NowMs()),
		last_time_point_new_(NowMs())
	{

	}
	void Show();
	void Action();
	
public:
	list<Zombie> zombies_;
	int interval_new_; //毫秒 ms 多久产生新的僵尸
	float speed_;; //僵尸移动速度
	long long last_time_point_move_;
	long long last_time_point_new_;
};

