#pragma once
#include<string>
#include<chrono>
#include<vector>
#include<list>
#include<memory>
using namespace std;

#include <graphics.h>

#include "Bullet.h"
#include "Config.h"
#include "Zombie.h"

class Plant
{
public:
	Plant(Bullet bullet_origin,int x, int y, int interval,float speed, int y_max,const string& name="plant",bool bullet=true)
		:bullet_origin_(bullet_origin),
		name_(name),
		x_(x),
		y_(y),
		size_(40),
		bullet_(bullet),
		interval_new_(interval),
		last_time_point_move_(NowMs()),
		last_time_point_new_(NowMs()),
		speed_(speed),
		y_max_(y_max),
		hurt(RandHurt())
	{
		loadimage(&image_, _T("plant.jpg"), 0, 0, true);
	}
	//Plant(const Plant& plant)
	//{
	//	this->name_ = plant.name_;
	//	this->x_ = plant.x_;
	//	this->y_ = plant.y_;
	//	this->size_ = plant.size_;
	//	this->life_ = plant.life_;
	//	this->ready = plant.ready;
	//	this->image_ = plant.image_;
	//	this->bullet_ = plant.bullet_;
	//	this->bullets_ = plant.bullets_;
	//	this->interval_new_ = plant.interval_new_;
	//	this->speed_ = plant.speed_;
	//	this->last_time_point_move_ = plant.last_time_point_move_;
	//	this->last_time_point_new_ = plant.last_time_point_new_;
	//	this->y_max_ = plant.y_max_;
	//	this->zombies_ptr_ = plant.zombies_ptr_;
	//}
	virtual void Action();
	virtual void Show();
	virtual void ShowPlant();
	void ShowInList(int col_plant);
	void AttachZombies(shared_ptr<list<Zombie>> zombies_ptr);
public:
	string name_;
	int x_;
	int y_;
	int size_;
	int life_=100;

	bool ready=false;
	IMAGE image_;

	//子弹 bullet
	bool bullet_;
	int interval_new_; //毫秒 us 多久产生新的子弹
	float speed_;; //子弹速度
	long long last_time_point_move_;
	long long last_time_point_new_;
	Bullet bullet_origin_;
	vector<Bullet> bullets_;
	int y_max_;

	
	//僵尸交互
	shared_ptr<list<Zombie>> zombies_ptr_;
	int hurt;
};

