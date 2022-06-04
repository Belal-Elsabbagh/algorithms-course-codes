#pragma once
#include <vector>
template<class Number>
class SumOfSubsets
{
public:
	SumOfSubsets(std::vector<Number> set, Number target) :
		number_set(set), target_sum(target), visited_elements(set.size(), false)
	{
		Number s = 0;
		for (Number& i : set)
		{
			s += i;
		}
		sum_of_elements = s;
	};
	Number get_total() { return this->sum_of_elements; }
	void generate_subsets(size_t i, Number sum, Number total);
	void print_solution();
private:
	std::vector<Number> number_set;
	Number target_sum, sum_of_elements;
	std::vector<bool> visited_elements;
	std::vector<std::vector<Number>> solution_subsets;
	void add_set_to_solution(std::vector<bool> set);
	bool isPromising(size_t i, Number sum, Number total);
	void print_possible_solution(std::vector<bool> visited_elements);
};

template<class Number>
void SumOfSubsets<Number>::generate_subsets(size_t i, Number sum, Number total)
{
	if (!isPromising(i, sum, total)) return;
	if (sum == target_sum)
	{
		print_possible_solution(visited_elements);
		return;
	}
	Number pick = number_set[i];
	Number new_sum = pick + sum;
	visited_elements[i] = true;
	generate_subsets(i + 1, new_sum, total - pick);
	visited_elements[i] = false;
	generate_subsets(i + 1, sum, total - pick);
}

template<class Number>
void SumOfSubsets<Number>::print_solution()
{
	if (solution_subsets.empty())
	{
		std::cout << "No solution was found.\n";
		return;
	}
	for (size_t i = 0; i < solution_subsets.size(); i++)
	{
		std::cout << "Subset " << i + 1 << ":\t";
		for (size_t j = 0; j < solution_subsets[i].size(); j++)
			std::cout << solution_subsets[i][j] << " ";
		std::cout << "\n";
	}
}

template<class Number>
void SumOfSubsets<Number>::add_set_to_solution(std::vector<bool> set)
{
	std::vector<Number> sol;
	for (size_t i = 0; i < set.size(); i++)
		if (i) sol.push_back(number_set[i]);
	solution_subsets.push_back(sol);
}

template<class Number>
bool SumOfSubsets<Number>::isPromising(size_t i, Number sum, Number total)
{
	return ((sum + total >= target_sum) && ((sum == target_sum) || (sum + number_set[i] <= target_sum)));
}

template<class Number>
void SumOfSubsets<Number>::print_possible_solution(std::vector<bool> visited_elements)
{
	std::cout << "Subset:\t";
	for (size_t j = 0; j < visited_elements.size(); j++)
		if(visited_elements[j]) std::cout << number_set[j] << " ";
	std::cout << "\n";
}

void TEST_SumOfSubsets()
{
	std::vector<int> set = { 3, 4, 5, 2, 6 };
	int target = 13;
	SumOfSubsets<int> test(set, target);
	test.generate_subsets(0, 0, test.get_total());
}