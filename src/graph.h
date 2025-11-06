#ifndef GRAPH_H
#define GRAPH_H
#pragma once

#include <iostream>
#include <ostream>
#include <utility>
#include <vector>
#include <map>
#include <string>
#include "person.h"
//#include "functions.h"
using namespace std;

// https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/CORS
// https://www.npmjs.com/package/react-force-graph
// https://www.geeksforgeeks.org/cpp/implementation-of-graph-in-cpp/
// Slides: page 55 adjency list, page 58 one graph api
class Graph{

private:
public: 
    map<string, int> id_to_index; // id is string, int is index in nodes vector

    struct Node{
        string id;
        vector<pair<string,float>> neighbors; // string: id int: weight
        Node(string id_){
            id = id_;
        }
    };

    vector<Node> nodes;

    Graph(){} // defualt constructor
    Graph(int v){ // constructor: initalize v nodes
        for(int i =0; i< v;i++){
            nodes.push_back(Node("")); // empty id
        }
    }
    Graph(const Graph& other){ // copy constructor
        nodes = other.nodes;
        id_to_index = other.id_to_index;
    }
    ~Graph(){ // destructor
        // delete nothing since no dynamic memory
    }

    void add_node(string id){
        // search map for id, if not found add new node
        if(id_to_index.find(id) == id_to_index.end()){ 
            id_to_index[id] = nodes.size(); 
            nodes.push_back(Node(id));
        }
        // else: do nothing since node already exists
    }

    void add_edge(string from, string to , float weight){
        if(to == from){
            return; // don't create edges for identical nodes
        }
        // if a node for an id not exist, add node
        // if it already exists, this does nothing
        add_node(from);
        add_node(to);

        // find the index of the new nodes from the id
        int from_index = find_node_index(from);
        int to_index = find_node_index(to);

        // no duplicate edges:
        for(auto neighbor: nodes[from_index].neighbors){
            if(neighbor.first == to){
                return; // edge already exists
            }
        }

        // add edge to adjacency list
        nodes[from_index].neighbors.push_back({to,weight});
     //   nodes[to_index].neighbors.push_back({from,weight}); 
    }

    int vertex_count(){
        // reutn num of vertices
        return nodes.size();
    }
    int edge_count(){
        // return num of edges
        int count = 0;
        for(int i = 0; i< nodes.size();i++){
            count += nodes[i].neighbors.size();
        }
        return count/2; // undirected graph so each edge is counted twice
    }
    

    bool isEdge(int from, int to){
        // get index of from node's id
        if(from< 0 || to <0 ){
            return false;
        }
        if(from >= nodes.size() || to >= nodes.size()){
            return false;
        }


        int from_index = find_node_index(nodes[from].id);
        int to_index = find_node_index(nodes[to].id);

        if(from_index == -1 || to_index == -1){
            return false; // one of the nodes does not exist
        }

        //for(int i = 0; i<nodes[from_index].neighbors.size();i++){
        for(auto neighbor: nodes[from_index].neighbors){ // checking from neighor to neighbors  
        // checks if the id of node's neighbor's at i index matches node's at 2nd index's actual id
            if(neighbor.first == nodes[to_index].id){
                return true;
            }
        }
        return false;

    }

    int getWeight(int from, int to){
         int from_index = find_node_index(nodes[from].id);
        int to_index = find_node_index(nodes[to].id);

        for(int i = 0; i<nodes[from_index].neighbors.size();i++){
            // checks if the id of node's neighbor's at i index matches node's at 2nd index's actual id
            if(nodes[from_index].neighbors[i].first== nodes[to_index].id){
                return nodes[from_index].neighbors[i].second;
            }
        }
        return -1; // edge not found

    }
    vector<int> getAdjacent(string id){
        int node_index = find_node_index(id);
        vector<int> adjacent_indices;

        if(node_index == -1){
            return adjacent_indices; // empty vector
        }
        for(auto neighbor: nodes[node_index].neighbors){
            // every loop acceses an index in the vector of pairs of the node
            // the first element of the pair is the id of the neighbor node
            /// pushes back the node index of the neighbor found id
            adjacent_indices.push_back(find_node_index(neighbor.first));
        }
        return adjacent_indices;
    }
    void printGraph(){
        for(auto node: nodes){
            for(auto neighbor: node.neighbors){
                cout << node.id << ": " << neighbor.first << "; weight: " << neighbor.second << ";" << endl;
            }
        }
    }

    void printGraph(map<string,Person>& a_map){
        for(auto node: nodes){
            cout << endl << "[" << a_map[node.id].getFirstName() << "]: " ;
            for(auto neighbor: node.neighbors){
                cout << a_map[neighbor.first].getFirstName() << "(" << neighbor.second << ")";
                if( neighbor.first != node.neighbors.back().first){
                    cout << ", ";
                }
            }
            cout << endl;
        }
    }
     
    // adjacency list
    map<string, vector<pair<string, int>>> neighbors;
   
    int find_node_index(string id){
        auto iter = id_to_index.find(id);
        // if the is found in the map return the index
        if(iter != id_to_index.end()){
            return iter->second;
        }
        return -1; // if nothing is found in the map, return -1

    // old vector implmentation  
        // for(int i = 0; i< nodes.size();i++){
        //     if(nodes[i].id == id){
        //         return i;
        //     }
        // }
        // return -1; 
    } 

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
