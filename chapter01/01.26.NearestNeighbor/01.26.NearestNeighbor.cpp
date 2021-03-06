#include "pch.h"
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <set>
#include <math.h>
#include <limits>

double CalculateDistance(std::pair<double, double> left, std::pair<double, double> right)
{
	return std::sqrt(
		(left.first - right.first) * (left.first - right.first)
		+
		(left.second - right.second) * (left.second - right.second)
	);
}

std::vector<std::pair<double, double>> NearestNeighbor(std::vector<std::pair<double, double>> &input)
{
	std::set<int> visited_points;
	std::vector<std::pair<double, double>> output;

	std::pair<double, double> current_point = input[0];
	visited_points.insert(0);
	output.push_back(current_point);

	double minimal_distance;
	int minimal_distance_point_index;
	double distance;
	for (int i = 1; i < input.size(); ++i)
	{
		minimal_distance = std::numeric_limits<double>::max();

		for (int j = 0; j < input.size(); ++j)
		{
			if (visited_points.find(j) != visited_points.end())
			{
				continue;
			}

			distance = CalculateDistance(output.back(), input[j]);
			if (distance < minimal_distance)
			{
				minimal_distance = distance;
				current_point = input[j];
				minimal_distance_point_index = j;
			}
		}

		visited_points.insert(minimal_distance_point_index);
		output.push_back(current_point);
	}
	
	output.push_back(input[0]);

	return output;
}

int main()
{
	// 1. Создаём исходные данные
	std::vector<std::pair<double, double>> input = 
	{
		{0, 0},
		{1, 0},
		{-1, 0},
		{3, 0},
		{11,0},
		{-5,0},
		{-21,0}
	};

	// 2. Обрабатываем (решаем задачу)
	std::vector<std::pair<double, double>> output = NearestNeighbor(input);

	// 3. Печатаем выходные данные
	// Для имеющихся исходных данных решение алгоритма NearestNeighbor должно выглядеть так:
	// {0,0} {1,0} {-1,0} {3,0} {-5,0} {11,0} {-21,0} {0,0}
	// (начинаем всегда с первой точки в списке)

	for (auto point: output)
	{
		std::cout << "(" << point.first << ", " << point.second << ")" << std::endl;
	}
}
