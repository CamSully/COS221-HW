/* shortestPath.cpp 
* Author: Cameron Sullivan
* Date: 11-1-17
* This code finds the shortest path from a source vertex to a destination vertex on a graph by using the breadth-first search algorithm.
*/

#include "Tree.h"
#include "Edge.h"
#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Cameron Sullivan - COS 221 - HW 10 Output" << endl;
	// Create a vector for the given vertices of the graph.
	vector<int> vertices;
	for (int i = 0; i < 6; i++) {
		vertices.push_back(i);
	}

	// Create a 2D array for the given edges of the graph.
	int edges[][2] = {
		{0,1}, {0,2},
		{1,0}, {1,3},
		{2,0}, {2,3}, {2,4},
		{3,1}, {3,2}, {3,4}, {3,5},
		{4,2}, {4,3}, {4,5},
		{5,3}, {5,4}
	};

	// Create a graph from the vertices and edges.
	Graph<int> numsGraph(vertices, edges, 16);

	// Read in the source and destination vertices.
	int source, destination;
	cout << "Enter the source vertex (integer index)." << endl;
	cin >> source;
	cout << "Enter the destination vertex (integer index)." << endl;
	cin >> destination;
	cout << endl;

	// If the user enters invalid input, end the program.
	if ((source < 0 || source > 5) || (destination < 0 || destination > 5)) {
		cout << "Error: the entered vertex does not exist." << endl;
		return 0;
	}

	// Create a minimal spanning tree of the graph.
	Tree numsTree = numsGraph.bfs(source);
	// Translate the path to the destination into a vector of vertices traveled to get there.
	vector<int> minimalPath = numsTree.getPath(destination);

	cout << "Number of vertices: " << numsTree.getNumberOfVerticesFound() << endl;
	cout << "Graph: " << endl;
	numsGraph.printEdges();
	cout << endl;
	cout << "Shortest path between the two nodes: " << endl;

	// Print the minimal path between the user's source and destination.
	// minimalPath is iterated in reverse because of the order elements are stored in it.
	for (int i = minimalPath.size() - 1; i >= 0; i--) {
		cout << minimalPath.at(i) << " ";
	}
	cout << endl;

	return 0;
}
