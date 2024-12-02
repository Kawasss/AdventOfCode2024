#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

int Part1(std::vector<int>& first, std::vector<int>& second)
{
	std::sort(first.begin(), first.end());
	std::sort(second.begin(), second.end());

	int sum = 0;
	for (int i = 0; i < first.size(); i++)
	{
		sum += std::abs(first[i] - second[i]);
	}
	return sum;
}

int Part2(std::vector<int>& first, std::vector<int>& second)
{
	std::unordered_map<int, int> idCount;

	for (int i = 0; i < second.size(); i++)
	{
		if (idCount.find(second[i]) == idCount.end())
			idCount.emplace(second[i], 1);
		else
			idCount.at(second[i])++;
	}

	int score = 0;
	for (int i = 0; i < first.size(); i++)
	{
		if (idCount.find(first[i]) == idCount.end())
			continue;

		score += first[i] * idCount.at(first[i]);
	}
	return score;
}

int main(int argc, char** argv)
{
	std::ifstream file("input/day1.txt");
	std::vector<int> first, second;

	first.reserve(1024);
	second.reserve(1024);

	int val1 = 0, val2 = 0;
	while (file >> val1 >> val2)
	{
		first.push_back(val1);
		second.push_back(val2);
	}

	//std::cout << Part1(first, second) << '\n';
	std::cout << Part2(first, second) << '\n';
	std::cout << std::endl;
	return 0;
}