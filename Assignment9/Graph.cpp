#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vertex* findVertex(string name, vector<vertex*> vertices){
    for (int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            return vertices[i];
        }
    }
    return NULL;
}

void Graph::createEdge(string v1, string v2, int num){
    if (v1 == v2){
        cout << "Cannot create connection to the same vertex." << endl;
        return;
    }
    vertex* vp1 = findVertex(v1, vertices);
    vertex* vp2 = findVertex(v2, vertices);
    if (vp1 == NULL){
        cout << "Vertex 1 does not exist" << endl;
        return;
    }
    if (vp2 == NULL){
        cout << "Vertex 2 does not exist" << endl;
        return;
    }

    adjVertex adj1 = {vp2, num};
    adjVertex adj2 = {vp1, num};
    vp1->adj.push_back(adj1);
    vp2->adj.push_back(adj2);
}

void Graph::insertVertex(string n){
    vertex* newVertex = new vertex;
    newVertex->name = n;
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
        cout<<endl;
    }
}

void Graph::traverseWithDijkstra(string start){
    for (int i = 0; i < vertices.size(); i++){
        vertices[i]->distance = INT_MAX;
    }
    
    vertex *vStart = findVertex(start, vertices);
    vStart->visited = true;
    vStart->distance = 0;

    queue<vertex*> q;

    q.push(vStart);

    vertex *v;
    while(!q.empty()){
        v = q.front();
        q.pop();
        for(int i = 0; i < v->adj.size(); i++){
            vertex* adjacent = v->adj[i].v;
            if(v->distance+v->adj[i].weight < adjacent->distance){
                adjacent->distance = v->distance + v->adj[i].weight;
                q.push(adjacent);
            }
        }
    }
}

void depthFirstTraversalHelper(vertex* sourceVertex, vector<vertex *> vertices){
    if (sourceVertex == NULL){
        return;
    }
    sourceVertex->visited = true;
    cout << sourceVertex->name << " -> ";
    for (int i = 0; i < sourceVertex->adj.size(); i++){
        if (!sourceVertex->adj[i].v->visited){
            depthFirstTraversalHelper(sourceVertex->adj[i].v, vertices);
        }
        
    }
}

void Graph::depthFirstTraversal(string sourceVertex){
    vertex* v = findVertex(sourceVertex, vertices);
    depthFirstTraversalHelper(v, vertices);
    cout << "DONE" << endl;
}

void Graph::minDistPath(string source, string destination) {
    traverseWithDijkstra(source);
    vertex* v = findVertex(source, vertices);
    vertex* dest = findVertex(destination, vertices);
    vertex* crawler = dest;
    vector<vertex*> path;
    path.push_back(dest);
    while(crawler != v){
        for (int i = 0; i < crawler->adj.size(); i++){
            if (crawler->distance-crawler->adj[i].weight == crawler->adj[i].v->distance){
                crawler = crawler->adj[i].v;
                path.push_back(crawler);
            }
        }
    }
    for (int i = path.size() - 1; i >= 0; i--){
        cout << path[i]->name << " -> ";
    }
    cout << "DONE [" << dest->distance << "]" << endl; 
}
