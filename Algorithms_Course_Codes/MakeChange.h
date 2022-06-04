#pragma once
#include <iostream>
#include <vector>
class MakeChange 
{
public:
	static int make_change(std::vector<int> coin_set, unsigned int value, std::vector<int>& solution)
	{
		int amount = value,
			coin_count = 0;
		while (amount > 0)
		{
			for (int& i : coin_set)
			{
				int current_coin = i;

				if (current_coin > amount) continue;

				solution.push_back(current_coin);
				coin_count++;
				amount -= current_coin;
				break;
			}
		}
		return coin_count;
	}
};

