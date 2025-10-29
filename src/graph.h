#ifndef GRAPH_H
#define GRAPH_H
#include <utility>
using namespace std;

// https://www.geeksforgeeks.org/cpp/implementation-of-graph-in-cpp/
// Slides: page 55 adjency list, page 58 one graph api
class Graph{
public: 
    struct Node{
        string id;
        vector<pair<string,int> neighbors; // 0+ neighbors
        Node(string id_){
            id = id_;
        }
    }
    vector<Node> nodes;

    Graph();
    Graph(int v){
    
        
    void addNode(string id){
        nodes.push_back(id,{});
    }

    void addEdge(int from, int to , int weight){
        nodes[from].neighbors.push_back({to,weight});
        nodes[to].neighbors.push_back({from,weight}); 
    }

    }
    int V(){
        // reutn num of vertices
        return nodes.size();
    }
    int E(){
        // return num of edges
        int count = 0;
        for(int i = 0; i< nodes.size();i++){
            count += nodes[i].neighbors[i].size();
        }
        return count;
    }
    

    bool isEdge(int from, int to){}
    int getWeight(int from, int to);
    vector<int> getAdjacent(int vertex){}
    void printGraph();

    // adjacency list
    map<string, vector<pair<string, int>>> neighbors;

};



// #include <iostream>
// #include<map>
// #include<vector>
// #include<iterator>
// using namespace std;
// int main()
// {
// int no_lines;
// string from, to, wt;
// map<string, vector<pair<string,int>>> graph;
// cin >> no_lines;
// for(int i = 0; i < no_lines; i++)
// {
// cin >> from >> to >> wt;
// graph[from].push_back(make_pair(to, stoi(wt)));
// if (graph.find(to)==graph.end())
// graph[to] = {};
// }
// }




#endif