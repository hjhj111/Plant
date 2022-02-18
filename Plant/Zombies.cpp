#include "Zombies.h"

void Zombies::Show()
{
	Action();
	for (auto& zombie : zombies_)
	{
		zombie.Show();
	}
}

void Zombies::Action()
{
	//clear
	for (auto& zombie : zombies_)
	{
		zombie.Clear();
	}
	//move
	int span = NowMs() - last_time_point_move_;
	//printf("%d \n", span);
	int length = span * speed_;
	if (length > 0)
	{
		for (auto iter = zombies_.begin(); iter != zombies_.end();)
		{
			auto& zombie = *iter;
			zombie.x_ -= length;
			if (zombie.x_ < 0)
			{
				iter = zombies_.erase(iter);
			}
			else
			{
				iter++;
			}
		}
		last_time_point_move_ = NowMs();
	}
	
	//new
	span = NowMs() - last_time_point_new_;
	if (span > interval_new_)
	{
		Zombie zombie(RandRow(),1,60,90);
		zombies_.emplace_back(zombie);
		last_time_point_new_ = NowMs();
	}
	
}


