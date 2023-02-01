#include "ShortestPath.hpp"
#include <limits>
#include <algorithm>
#include <set>
#ifndef IO
#define IO
#include <iostream>
#endif
std::map<char, int> Dijkstra(std::map<char, std::map<char, int>> graphs, char startNode, int maxIteration)
{
    std::vector<char> visited;
    visited.push_back(startNode);
    std::map<char, int> result;
    result.insert(std::pair<char, int>(startNode, 0));
    std::vector<char> notVisited;
    for (auto p0 : graphs)
    {
        for (auto p1 : p0.second)
        {
            char c = p1.first;
            if (!result.count(c))
            {
                result.insert(std::pair<char, int>(c, std::numeric_limits<int>::max()));
            }
        }
    }

    char active = visited[visited.size() - 1];
    int tried = 0;

    while (visited.size() != result.size() && tried < maxIteration)
    {
        std::cout << active << std::endl;
        for (auto p : graphs[active])
        {
            if (std::count(visited.begin(), visited.end(), p.first))
                continue;
            if (result[p.first] > p.second)
            {
                result[p.first] = result[active] + p.second;
            }
        }
        std::vector<std::pair<char, int>> ordered;
        for (auto p : result)
        {
            ordered.push_back(p);
        }
        std::sort(ordered.begin(), ordered.end(), [](std::pair<char, int> a, std::pair<char, int> b)
                  { return a.second < b.second; });
        visited.push_back(active);
        for (auto p : ordered)
        {
            if (std::count(visited.begin(), visited.end(), p.first))
                continue;
            active = p.first;
            break;
        }
        tried++;
    }
    return result;
}