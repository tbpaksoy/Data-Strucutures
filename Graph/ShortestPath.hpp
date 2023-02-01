#ifndef MAP
#define MAP
#include <map>
#endif
#ifndef VECTOR
#define VECTOR
#include <vector>
#endif
std::map<char, int> Dijkstra(std::map<char, std::map<char, int>> graphs, char startNode, int maxIteration);
