#include "Graph.hpp"
#include <list>

vertex* findVertex(string name, vector<vertex*> vertices){
    for (int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            return vertices[i];
        }
    }
    return NULL;
}

void Graph::addVertex(string name){
    vertex* newVertex = new vertex;
    newVertex->name = name;
    vertices.push_back(newVertex);
}

void Graph::addEdge(string v1, string v2){
    if (v1 == v2){
        cout << "Cannot create connection to the same vertex." << endl;
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

    adjVertex adj1 = {vp2};
    adjVertex adj2 = {vp1};
    vp1->adj.push_back(adj1);
    vp2->adj.push_back(adj2);
}

void Graph::displayEdges(){
    for (int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << " -->";
        for (int j = 0; j < vertices[i]->adj.size(); j++){
            cout << " " << vertices[i]->adj[j].v->name;
        }
        cout << endl;
    }
}

void clearVisited(vector<vertex*>* vertices){
    for (int i = 0; i < vertices->size(); i++){
        vertices->at(i)->visited = false;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex){
    clearVisited(&vertices);
    vertex* source = findVertex(sourceVertex, vertices);
    if (source == NULL){
        cout << "Source does not exist." << endl;
        return;
    }
    
    list<vertex*> queue;
    queue.push_back(source);
    source->visited = true;

    cout << "Starting vertex (root): " << source->name << "-> ";

    vertex* node;
    while(!queue.empty()){
        node = queue.front();
        queue.pop_front();

        for(int i = 0; i < node->adj.size(); i++){
            vertex* adjacent = node->adj[i].v;
            if(!adjacent->visited){
                adjacent->visited = true;
                adjacent->distance = node->distance + 1;
                queue.push_back(adjacent);
                cout << adjacent->name << "(" << adjacent->distance << ")" << " ";
            }
        }
    }
}

void depthFirstTraverse(vertex* source){
    list<vertex*> stack;
    stack.push_back(source);
    source->visited = true;
    vertex* node;
    while(!stack.empty()){
        node = stack.back();
        stack.pop_back();
        for (int i = 0; i < node->adj.size(); i++){
            vertex* adjacent =  node->adj[i].v;
            if (!adjacent->visited){
                adjacent->visited = true;
                stack.push_back(adjacent);
            }
        }
    }
}

int Graph::getConnectedBuildings(){
    clearVisited(&vertices);
    bool allVisited = false;
    int counter = 0;
    int node = 0;
    while (!allVisited){
        allVisited = true;
        counter++;
        depthFirstTraverse(vertices[node]);
        for (int i = 0; i < vertices.size(); i++){
            if(!vertices[i]->visited){
                allVisited = false;
                node = i;
            }
        }
    }
    return counter;
}