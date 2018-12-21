/*	Disjoint Set (Or Union-Find) | (Detect Cycle in an Undirected Graph) 

******************     Weather a graph(UNDIRECTED) contain a cycle or not ?   ********************************************

				 Disjoint-set is a ---> data structure

keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.

A union-find algorithm:
	 performs two useful operations on such a data structure:
	 	
	 	1.Find : finds element in same subset
	 	2.Union : joins 2 subset into a single set

For each edge:
	make subsets using both the vertices of the edge.
If both the vertices are in the same subset, a cycle is found.

			0------1
			\     / 
			 \   /
			  \2/



initially initialize  all slots of parent array are initialized to -1 
(means there is only one item in every subset).

					0   1   2
					-1 -1  -1 

process all edge one by one:
	Edge 0-1:
		In which subset 0 is ?

		In which subset 1 is ?
	They r in different subset!!!
	
	so Take Union:
		so make 1 parent of 0 (or other way).

			0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
			
			1  -1  -1

	Edge 1-2:
		where is 1? --- subset 1
		where is 2? --- subset 2
		    -- in Different subset ---> take union

		    0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
			
			1   2  -1

	Edge 0-2:
		where is 0?
		where is 2?

		---- in same subset ----
		if we include this Edge THERE IS A CYCLE!!!!:)







*/


// A union-find algorithm to detect cycle in a graph 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 



// a structure to represent an edge in graph 
struct Edge 
{ 
	int src, dest; 
}; 

// graph is made of Vertex and edges
//it has following info: no. of vertices , no. of edges , and n EDGE structure

struct Graph 
{ 
	// V-> Number of vertices, E-> Number of edges 
	int V, E; 

	// graph is represented as an array of edges 
	struct Edge* edge; 
}; 

// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) 
{ 
	struct Graph* graph = 
		(struct Graph*) malloc( sizeof(struct Graph) ); 
	graph->V = V; 
	graph->E = E; 

	graph->edge = 
		(struct Edge*) malloc( graph->E * sizeof( struct Edge ) ); 
		// number of edges - into size of each edge!!!!
	return graph; 
} 

// A utility function to find the subset of an element i 
int find(int parent[], int i) 
{ 
	if (parent[i] == -1) 
		return i;        
	return find(parent, parent[i]);
} 

// A utility function to do union of two subsets 
void Union(int parent[], int x, int y) 
{ 
	int xset = find(parent, x); 
	int yset = find(parent, y); 
	if(xset!=yset){ 
	parent[xset] = yset; 
	} 
} 

// The main function to check whether a given graph contains 
// cycle or not 
int isCycle( struct Graph* graph ) 
{ 
	// Allocate memory for creating V subsets 
	int *parent = (int*) malloc( graph->V * sizeof(int) ); 

	// Initialize all subsets as single element sets
	//memset?? :- copies "-1" to "parent" first "V" times
	//The C library function void *memset(void *str, int c, size_t n) 
	//copies the character c (an unsigned char)
	// to the first n characters of the string pointed to, by the argument str.
	//
	  
	memset(parent, -1, sizeof(int) * graph->V); 

	// Iterate through all edges of graph, find subset of both 
	// vertices of every edge, if both subsets are same, then 
	// there is cycle in graph. 
	for(int i = 0; i < graph->E; ++i) 
	{ 
		int x = find(parent, graph->edge[i].src); 
		int y = find(parent, graph->edge[i].dest); 

		if (x == y) 
			return 1; 

		Union(parent, x, y); 
	} 
	return 0; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us create the following graph 
		0 
		| \ 
		| \ 
		1-----2 */	
	int V = 3, E = 3; 
	struct Graph* graph = createGraph(V, E); 

	// add edge 0-1 
	graph->edge[0].src = 0; 
	graph->edge[0].dest = 1; 

	// add edge 1-2 
	graph->edge[1].src = 1; 
	graph->edge[1].dest = 2; 

	// add edge 0-2 
	graph->edge[2].src = 0; 
	graph->edge[2].dest = 2; 

	if (isCycle(graph)) 
		printf( "graph contains cycle" ); 
	else
		printf( "graph doesn't contain cycle" ); 

	return 0; 
} 
