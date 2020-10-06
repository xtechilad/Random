// Name = Praveen Kumar
// Course = B.Sc(H) Computer Science
// Roll no = 19HCS4039
// Subject = Computer Networking
//------------------------------Dijkstra Algorithm implementation----------------------------------------
#include<iostream>
#define vertex 5
using namespace std;

int minDistance(int dist[], bool sptSet[]) 
{ 
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int i = 0; i < vertex; i++) 
		if (sptSet[i] == false && dist[i] <= min) 
			min = dist[i], min_index = i; 

	return min_index; 
}
void print(int dist[]) 
{ 
	cout<<"\tVertex \t\t"<<"Distance from Source\n"; 
	for (int i = 0; i < vertex; i++) 
		cout<<"\t"<<i<<"\t\t"<<dist[i]<<"\n"; 
} 
void Dijkstra(int table[vertex][vertex], int src) 
{ 
	int dist[vertex]; 
	bool sptSet[vertex]; 
	for (int i = 0; i < vertex; i++) 
		dist[i] = INT_MAX, sptSet[i] = false; 
	dist[src] = 0; 
	for (int count = 0; count < vertex - 1; count++) { 
		int u = minDistance(dist, sptSet); 
		sptSet[u] = true; 
		for (int v = 0; v < vertex; v++) 
			if (!sptSet[v] && table[u][v] && dist[u] != INT_MAX 
				&& dist[u] + table[u][v] < dist[v]) 
				dist[v] = dist[u] + table[u][v]; 
	}  
	print(dist); 
} 
int main()
{
	cout<<"------------------------------Dijkstra Algorithm implementation----------------------------------------\n\n\n";
	int table[vertex][vertex]={{0,1,0,3,10},
							   {1,0,5,0,0},
							   {0,5,0,2,1},
							   {3,0,2,0,6},
							   {10,0,1,6,0}};
	Dijkstra(table,0);
	return 0;
}
