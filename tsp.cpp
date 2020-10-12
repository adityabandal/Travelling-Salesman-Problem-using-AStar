#include <bits/stdc++.h>
using namespace std;
#include "AStar.h"
Graph readGraph_nbyn()
{
    std::fstream myfile("./input.txt", std::ios_base::in);
    int n;
    myfile >> n;
    Graph g(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int w;
            myfile >> w;
            g.addEdge(i, j, w);
            cout << w << " ";
        }
        cout << endl;
    }
    return g;
}
int main()
{
    Graph g = readGraph_nbyn();
    int startNode = 2;
    AStar solver(g, startNode);
    bool found = solver.solve();
    if (found)
    {
        cout << "Cost = " << solver.cost << endl;
        cout << "itinerary:\n";
        for (int i : solver.solution.path)
        {
            cout << i + 1 << " -> ";
        }
        cout << startNode + 1;
        cout << endl;
    }
    else
    {
        cout << "!!! PROBLEM !!!" << endl;
    }
    cout << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs " << endl;
    return 0;
}
