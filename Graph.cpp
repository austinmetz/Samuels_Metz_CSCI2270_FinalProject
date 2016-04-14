#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <istream>
#include <queue>

using namespace std;

Graph::Graph()
{
    //ctor
}

void Graph::addVertex(string name)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == name)
        {
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = name;
        v.district = -1;
        vertices.push_back(v);

    }
}

void Graph::addEdge(string v1, string v2, int weight)
{
    for(int i = 0; i < vertices.size(); i++)
        {
            if(vertices[i].name == v1)
            {
                for(int j = 0; j < vertices.size(); j++)
                {
                    if(vertices[j].name == v2 && i != j)
                    {
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    av.v->visited = false;
                    av.v->visited2 = false;
                    vertices[i].adj.push_back(av);
                    //another vertex for edge in other direction
                    }
                }
            }
        }
}

void Graph::displayEdges()
{
    //loop through all vertices and adjacent vertices

    for(int i = 0; i < vertices.size(); i++)
    {

        cout<< vertices[i].district<<":"<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
           cout<<vertices[i].adj[j].v->name;
            if (j != vertices[i].adj.size()-1)
            {
                cout<<"***";
            }
        }
        cout<<endl;
    }

}

void Graph::BFTraversalLabel(string startingCity, int distID)
{
    vertex *v = findVertex(startingCity);
    queue <vertex*> q;
    v->visited = true;
    v->district = distID;
    q.push(v);
    while(!q.empty())
    {
        vertex *n = q.front();
        q.pop();
        for(int x = 0; x < n->adj.size(); x++)
        {
            if(!n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->district = n->district;
                q.push(n->adj[x].v);
            }
        }
    }

}

vertex* Graph::findVertex(string name)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == name)
        {
            return &vertices[i];
        }
    }
    return NULL;
}

void Graph::shortestPath(string city1, string city2)
{
    vertex* x = findVertex(city1);
    vertex* p = findVertex(city2);
    if(x == NULL or p == NULL)
    {
        cout<<"One or more cities doesn't exist"<<endl;
    }
    else if(x->district != p->district)
    {
        cout<<"No safe path between cities"<<endl;
    }
    else if(x->district == -1 or p->district == -1)
    {
        cout<<"Please identify the districts before checking distances"<<endl;
    }
    else
    {
        vertex *v = BFTraversalLabelSP(city1, city2);
        string myArray[v->distance+1];
        int sup = v->distance;
        for(int i = sup; i>=0; i--)
        {
            myArray[i] = v->name;
            v = v->parent;
        }
        cout<<sup;
        for(int i = 0; i <= sup; i++)
        {
            cout<<","<<myArray[i];
        }
        cout<<endl;
    }
}

vertex* Graph::BFTraversalLabelSP(string city1, string city2)
{
    vertex* v = findVertex(city1);
    v->visited2 = true;
    v->distance = 0;
    v->parent = NULL;
    queue<vertex*> q;
    q.push(v);
    while(!q.empty())
    {
        vertex* n = q.front();
        q.pop();
        for(int x = 0; x < n->adj.size(); x++)
        {
            if(!n->adj[x].v->visited2)
            {
                n->adj[x].v->distance = n->distance+1;
                n->adj[x].v->parent = n;
                if(n->adj[x].v->name == city2)
                {
                    return n->adj[x].v;
                }
                else
                {
                    n->adj[x].v->visited2 = true;
                    n->adj[x].v->parent = n;
                    q.push(n->adj[x].v);
                }
            }
        }
    }
    return NULL;
}

void Graph::assignDistricts()
{
    int distID = 1;
    for(int u = 0; u < vertices.size(); u++)
    {
        if(vertices[u].district == -1)
        {
            BFTraversalLabel(vertices[u].name, distID);
            distID++;
        }

    }
}

Graph::~Graph()
{
    //dtor
}
