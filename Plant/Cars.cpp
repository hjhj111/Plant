#include "Cars.h"

void Cars::Action()
{
	for (int i = 0; i < cars_.size(); i++)
	{
		auto& car = cars_[i];
		for (auto iter = zombies_ptr_->begin(); iter != zombies_ptr_->end();iter++)
		{
			auto& zombie = *iter;
			if (car.Hit(zombie.x_, zombie.y_))
			{
				car.attacked = true;
				car.Clear();
				ClearZombiesRow(i);
				break;
				//car.x_ = 300;

			}
		}
	}
}

void Cars::Show()
{
	Action();
	for (int i = 0; i < cars_.size(); i++)
	{
		cars_[i].Show();
	}
}

void Cars::AttachZombies(list<Zombie>& zombies_ptr)
{
	zombies_ptr_ = move(shared_ptr< list<Zombie>>(&zombies_ptr));
}

void Cars::ClearZombiesRow(int car_row)
{
	for (auto iter = zombies_ptr_->begin(); iter != zombies_ptr_->end();)
	{
		auto& zombie = *iter;
		if (zombie.row_ == car_row)
		{
			zombie.Clear();
			iter=zombies_ptr_->erase(iter);
		}
		else
		{
			iter++;
		}
	}
}
