#ifndef SHORTESTPATHTREE_H
#define SHORTESTPATHTREE_H
#include "Tree.h" // Defined in Listing 24.4
class ShortestPathTree : public Tree
{
public:
	// Create an empty ShortestPathTree
	ShortestPathTree()
	{
	}
	// Construct a tree with root, parent, searchOrders, and cost.
	ShortestPathTree(int root, vector<int>& parent,
	vector<int>& searchOrders, vector<double>& cost): Tree(root, parent, searchOrders)
	{
		this->cost = cost;
	}
	// Return the cost for the path from the source to vertex v.
	double getCost(int v)
	{
		return cost[v];
	}
private:
	vector<double> cost;
};

#endif