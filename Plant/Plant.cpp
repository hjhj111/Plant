#include "Plant.h"
#include <atlstr.h>
#include<string>
#include <graphics.h>

void Plant::Action()
{
	//clear
	//Sleep(10);
	for (auto& bullet : bullets_)
	{
		bullet.Clear();
	}
	//move
	int span = NowMs() - last_time_point_move_;
	int length = span * speed_;
	//printf("%d", length);
	//length = 10;
	if (length > 0)
	{
		for (int i = 0; i < bullets_.size(); i++)
		{
			auto& bullet = bullets_[i];
			bullet.x_ += length;
			if (bullet.x_ > y_max_)
			{
				bullets_.erase(bullets_.begin() + i);
				i--;
			}
		}
		last_time_point_move_ = NowMs();
	}
	
	//new
	span = NowMs() - last_time_point_new_;
	if ( span> interval_new_)
	{
		//Bullet bullet_new(x_ + size_ / 2, y_ );
		bullet_origin_.x_ = x_ + size_;
		bullet_origin_.y_ = y_;
		bullets_.push_back(bullet_origin_);
		last_time_point_new_ = NowMs();
	}

	//»÷ÖÐ½©Ê¬
	if (!zombies_ptr_->empty())
	{
		for (auto iter = zombies_ptr_->begin(); iter != zombies_ptr_->end();)
		{
			bool flag = true;
			auto& zombie = *iter;
			for (int i=0;i< bullets_.size();i++)
			{
				auto& bullet = bullets_[i];
				if (zombie.Hit(bullet.x_, bullet.y_))
				{
					zombie.state_ = ZombieState::HURT;
					zombie.life_ -= hurt;
					bullets_.erase(bullets_.begin() + i);
					if (zombie.life_ <= 0)
					{
						zombie.Clear();
						iter=zombies_ptr_->erase(iter);
						flag = false;
					}
					break;
				}
			}
			if (flag)
			{
				iter++;
			}
		}

	}
}

void Plant::Show()
{
	Action();
	ShowPlant();
	for (int i = 0; i < bullets_.size(); i++)
	{
		bullets_[i].Show();
	}
	
}

void Plant::ShowPlant()
{
	//circle(x_, y_, size_ / 2);
	putimage(x_ - size_grid / 2, y_ - size_grid / 2, &image_);
	RECT r = { x_ - size_grid / 2, y_ - size_grid / 2 ,x_ /*- size_grid / 4*/, y_ - size_grid / 3 };
	settextcolor(RGB(255, 0, 0));	
	drawtext(CA2T(/*to_string(life_)*/name_.c_str()), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}

void Plant::ShowInList(int col_plant)
{
	//int x_old = x_;
	//int y_old = y_;
	//x_ = col * size_grid + size_grid / 2;
	//y_ = height_map - size_grid / 2;
	ShowPlant();
	//x_ = x_old;
	//y_ = y_old;
}

void Plant::AttachZombies(shared_ptr<list<Zombie>> zombies_ptr)
{
	zombies_ptr_ = move(zombies_ptr);
}
