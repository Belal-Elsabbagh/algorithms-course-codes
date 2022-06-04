#pragma once
#include <iostream>
#include <vector>
class Fibonacci 
{
public:
	int recursive_fibonacci(int number);
	int iterative_fibonacci(int number);
};

int Fibonacci::recursive_fibonacci(int number)
{
	if (number <= 1) return number;
	return recursive_fibonacci(number - 1) + recursive_fibonacci(number - 2);
}

int Fibonacci::iterative_fibonacci(int number)
{
	if (number == 0 || number == 1) return number;
	if (number < 0) { std::cerr << "INVALID"; return -1; }

	std::vector<int> sequence(number);
	sequence[0] = 0;
	sequence[1] = 1;
	for (size_t i = 2; i <= number; i++)
	{
		sequence[i] = sequence[i - 1] + sequence[i - 2];
	}
	return sequence[number];
}
