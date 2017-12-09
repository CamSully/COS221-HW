/* Summary: I wrote the Kruskal MST function, but it has issues.
* I wanted to test it, but for some reason when I try to execute the function in my tester file,
* It refuses to compile, citing an odd "undefined reference to WeightedGraph error."
* 
* Resources Used:
* https://www.cis.upenn.edu/~matuszek/cit594-2005/Lectures/13-simple-sorting.ppt
* https://www.programiz.com/dsa/kruskal-algorithm
* https://www.youtube.com/watch?v=71UQH7Pr9kU
*/

#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H

#include "Graph.h"
#include "WeightedEdge.h" // Defined in Listing 25.1
#include "MST.h" // Defined in Listing 25.3
#include "ShortestPathTree.h" // Defined in Listing 25.8

template<typename V>
class WeightedGraph : public Graph<V>
{
public:
	// Construct an empty graph
	WeightedGraph();
	// Construct a graph from vertices and edges objects
	WeightedGraph(vector<V>& vertices, vector<WeightedEdge>& edges);
	// Construct a graph with vertices 0, 1, ..., n-1 and
	WeightedGraph(int numberOfVertices, vector<WeightedEdge>& edges);
	// Print all edges in the weighted tree
	void printWeightedEdges();
	// Add a weighted edge
	bool addEdge(int u, int v, double w);
	// Get a minimum spanning tree rooted at vertex 0 (PRIM'S ALGORITHM)
	MST getMinimumSpanningTree();
	// Get a minimum spanning tree rooted at a specified vertex (PRIM'S ALGORITHM)
	MST getMinimumSpanningTree(int startingVertex);
	// Get a minimum spanning tree using KRUSKAL'S algorithm.
	MST getKruskalMST();
	// Find single-source shortest paths
	ShortestPathTree getShortestPath(int sourceVertex);
private:
	int getSubTreeRoot(int vertex);
};

vector<int> parents;
const int INFINITY;

template<typename V>
WeightedGraph<V>::WeightedGraph()
{
}

template<typename V>
WeightedGraph<V>::WeightedGraph(vector<V>& vertices,
vector<WeightedEdge>& edges)
{
	// Add vertices to the graph
	for (unsigned i = 0; i < vertices.size(); i++)
	{
	Graph<V>::addVertex(vertices[i]);
	}
	// Add edges to the graph
	for (unsigned i = 0; i < edges.size(); i++)
	{
	addEdge(edges[i].u, edges[i].v, edges[i].weight);
	}
}

template<typename V>
WeightedGraph<V>::WeightedGraph(int numberOfVertices,
vector<WeightedEdge>& edges)
{
	// Add vertices to the graph
	for (int i = 0; i < numberOfVertices; i++)
	Graph<V>::addVertex(i); // vertices is {0, 1, 2, ..., n-1}
	// Add edges to the graph72
	for (unsigned i = 0; i < edges.size(); i++)
	{
	addEdge(edges[i].u, edges[i].v, edges[i].weight);
	}
}

template<typename V>
void WeightedGraph<V>::printWeightedEdges()
{
	for (int i = 0; i < Graph<V>::getSize(); i++)
	{
	// Display all edges adjacent to vertex with index i
	cout << "Vertex " << Graph<V>::getVertex(i) << "(" << i << "): ";
	// Display all weighted edges
	for (Edge* e: Graph<V>::neighbors[i])
	{
	cout << "(" << e->u << ", " << e->v << ", "
	<< static_cast<WeightedEdge*>(e)->weight << ") ";
	}
	cout << endl;
	}
}

template<typename V>
bool WeightedGraph<V>::addEdge(int u, int v, double w)
{
	return Graph<V>::createEdge(new WeightedEdge(u, v, w));
}

template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTree()
{
	return getMinimumSpanningTree(0);
}

// Finds a minimum spanning tree using Prim's algorithm.
template<typename V>
MST WeightedGraph<V>::getMinimumSpanningTree(int startingVertex)
{
	vector<int> T;     // Vertices in the tree
	vector<int> parent(Graph<V>::getSize());	// Parent of a vertex.
	parent[startingVertex] = -1;     // startingVertex is the root
	double totalWeight = 0;     // Total weight of the tree thus far
	
	// cost[v] stores the cost by adding v to the tree
	vector<double> cost(Graph<V>::getSize());
	for (unsigned i = 0; i < cost.size(); i++)
	{
		cost[i] = INFINITY; // Initial cost set to infinity
	}

	cost[startingVertex] = 0; // Cost of source is 0
	
	// Expand T
	while (T.size() < Graph<V>::getSize())
	{
		// Find smallest cost v in V - T
		int u = -1; // Vertex to be determined
		double currentMinCost = INFINITY;
		// Find the minimum weight edge of the current vertex?
		for (int i = 0; i < Graph<V>::getSize(); i++)
		{
			// If the vertex is not found in the MST AND it has the lowest cost, it is the next vertex in the MST.
			if ((find(T.begin(), T.end(), i) == T.end()) && (cost[i] < currentMinCost))
			{
				currentMinCost = cost[i];
				u = i;
			}
		}
		
		T.push_back(u); // Add a new vertex to T
		totalWeight += cost[u]; // Add cost[u] to the tree
		
		// Adjust cost[v] for v that is adjacent to u and v in V - T
		for (Edge* e: Graph<V>::neighbors[u])
		{
			if (find(T.begin(), T.end(), e->v) == T.end() && cost[e->v] > static_cast<WeightedEdge*>(e)->weight)
			{
				cost[e->v] = static_cast<WeightedEdge*>(e)->weight;
				parent[e->v] = u;
			}
		}
	} 
	
	return MST(startingVertex, parent, T, totalWeight);
}






template<typename V>
MST getKruskalMST() {

	// Vertices, parents, startVertex, totalWeight.
	vector<int> mstVertices; 
	int startVertex;
	double totalWeight = 0;

	// Insert each edge into the sortedEdges vector.
	vector<WeightedEdge*> sortedEdges(Graph<V>::getSize());
		for (int i = 0; i < Graph<V>::getSize(); i++) {
			for (Edge* e: Graph<V>::neighbors[i]) {
				sortedEdges.push_back(static_cast<WeightedEdge*>(e));
			}
		}

	// Sort all edges into ascending weight.
	int outer, inner;
	for (outer = Graph<V>::getSize() - 1; outer > 0; outer--) {
		for (inner = 0; inner < outer; inner++) {
			if (sortedEdges[inner]->weight > sortedEdges[inner + 1]->weight) {
				WeightedEdge* tempEdge = sortedEdges[inner];
				sortedEdges[inner] = sortedEdges[inner + 1];
				sortedEdges[inner + 1] = tempEdge;
			}
		}
	}
	
	// CHECK IF THE EDGE CAUSES A CYCLE!
	// Set the parent of each vertex to itself (so that they default to root).
	for (int i = 0; i < Graph<V>::getSize(); i++) {
		parents[i] = i;
	}
	startVertex = sortedEdges[0]->u;
	parents[startVertex] = -1;
	// Iterate through, testing each edge.
	for (int i = 0; i < Graph<V>::getSize(); i++) {
		int uRoot = WeightedGraph<V>::getSubTreeRoot(sortedEdges[i]->u);
		int vRoot = WeightedGraph<V>::getSubTreeRoot(sortedEdges[i]->v);
		if (uRoot != vRoot) {
			mstVertices.push_back(sortedEdges[i]->u);
			mstVertices.push_back(sortedEdges[i]->v);
			totalWeight += sortedEdges[i]->weight;
			parents[sortedEdges[i]->v] = i;
		}
	}
	return MST(startVertex, parents, mstVertices, totalWeight);
}

template<typename V>
int getSubTreeRoot(int vertex) {
	if (vertex == parents[vertex]) {
		return vertex;
	}
	if (parents[vertex] == -1) {
		return -1;
	}

	else {
		return WeightedGraph<V>::getSubTreeRoot(parents.at(vertex));
	}
}



template<typename V>
ShortestPathTree WeightedGraph<V>::getShortestPath(int sourceVertex)
{
	// T stores the vertices whose path found so far
	vector<int> T;
	// parent[v] stores the previous vertex of v in the path
	vector<int> parent(Graph<V>::getSize());
	parent[sourceVertex] = -1; // The parent of source is set to -1
	// cost[v] stores the cost of the path from v to the source
	vector<double> cost(Graph<V>::getSize());
	for (unsigned i = 0; i < cost.size(); i++)
	{
	cost[i] = INFINITY; // Initial cost set to infinity
	}
	cost[sourceVertex] = 0; // Cost of source is 0
	// Expand T
	while (T.size() < Graph<V>::getSize())
	{
	// Find smallest cost v in V - T
	int u = -1; // Vertex to be determined
	double currentMinCost = INFINITY;
	for (int i = 0; i < Graph<V>::getSize(); i++)
	{
	if (find(T.begin(), T.end(), i)== T.end()
	&& cost[i] < currentMinCost)
	{
	currentMinCost = cost[i];
	u = i;
	}
	}
	if (u == -1) break;
	T.push_back(u); // Add a new vertex to T
	// Adjust cost[v] for v that is adjacent to u and v in V - T
	for (Edge* e: Graph<V>::neighbors[u])
	{
	if (find(T.begin(), T.end(), e->v) == T.end() &&
	cost[e->v] > cost[u] + static_cast<WeightedEdge*>(e)->weight)
	{
	cost[e->v] = cost[u] + static_cast<WeightedEdge*>(e)->weight;
	parent[e->v] = u;
	}
	}
	} // End of while
	// Create a ShortestPathTree
	return ShortestPathTree(sourceVertex, parent, T, cost);
}

#endif
