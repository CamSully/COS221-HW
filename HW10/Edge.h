/* Edge class header. Simulates an edge of a graph.
* Originally written by D. Liang, Introduction to Programming with C++, 3rd edition.
*/

#ifndef EDGE_H
#define EDGE_H

class Edge
{
	public:
		int u;
		int v;
		
		Edge(int u, int v)
		{
			this->u = u;
			this->v = v;
		}
};
#endif
