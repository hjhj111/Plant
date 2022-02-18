#include<tuple>
#include "Plants.h"

void Plants::Action()
{
	ExMessage msg;
	auto gotten = peekmessage(&msg);
	if (!gotten)
	{
		return;
	}
	if (msg.lbutton)
	{
		int chosen_col = GetPlantCol(msg.x, msg.y);
		if (chosen_col != -1)
		{
			chosen_col_ = chosen_col;
		}
		else
		{
			int plant_row = -1;
			int plant_col = -1;
			if (chosen_col_ != -1)
			{
				std::tie(plant_col, plant_row) = GetPlantPos(msg.x, msg.y);
				if (plant_col != -1)
				{
					Plant plant = plants_[chosen_col_];//(plant_col * size_grid + size_grid / 2, plant_row * size_grid + size_grid / 2, 300000, 0.0001, width_map);
					plant.x_ = plant_col * size_grid + size_grid / 2;
					plant.y_ = plant_row * size_grid + size_grid / 2;
					plant.AttachZombies(zombies_ptr_);
					plants_planted_.emplace_back(move(plant));
					plants_planted_shown.emplace_back(false);
					
					//AttachZombies();
					chosen_col_ = -1;
				}
			}
		}

		
	}

}

void Plants::Show()
{
	//÷≤ŒÔ¡–±Ì
	if (!plants_list_shown)
	{
		for (int i = 0; i < plants_.size(); i++)
		{
			auto& plant = plants_[i];
			plant.ShowInList(i);
		}
		plants_list_shown = true;
	}
	Action();
	for (int i = 0; i < plants_planted_.size(); i++)
	{
		if (plants_planted_shown[i])
		{
			//continue;
		}
		auto& plant = plants_planted_[i];
		//printf("one plant show begin\n");
		plant.Show();
		//printf("one plant show end\n");
		plants_planted_shown[i] = true;
	}
}

void Plants::AttachZombies(list<Zombie>& zombies_ptr)
{
	//for (auto& plant : plants_)
	//{
	//	plant.AttachZombies(zombies_ptr);
	//}
	zombies_ptr_ = move(shared_ptr<list<Zombie>>(&zombies_ptr));
}
