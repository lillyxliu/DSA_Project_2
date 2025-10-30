#ifndef GRAPH_H
#define GRAPH_H
#pragma once
#include <utility>
#include <vector>
#include <map>
#include <string>
#include "person.h"
#include <cmath>
#include <cfloat>
#include "crow.h"

using namespace std;

// https://developer.mozilla.org/en-US/docs/Web/HTTP/Guides/CORS
// https://www.npmjs.com/package/react-force-graph
// https://www.geeksforgeeks.org/cpp/implementation-of-graph-in-cpp/
// Slides: page 55 adjency list, page 58 one graph api
class Graph{
public: 
    struct Node{
        string id;
        vector<pair<string,int>> neighbors; // string: id int: weight
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

    void add_node(string id){
        if(find_node_index(id) == -1){  
            nodes.push_back(Node(id));
        }
        // else: do nothing since node already exists
    }

    void add_edge(string from, string to , int weight){
        // if a node for an id not exist, add node
        // if it already exists, this does nothing
        add_node(from);
        add_node(to);

        // find the index of the new nodes from the id
        int from_index = find_node_index(from);
        int to_index = find_node_index(to);

        // add edge to adjacency list
        nodes[from_index].neighbors.push_back({to,weight});
        nodes[to_index].neighbors.push_back({from,weight}); 
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
        int from_index = find_node_index(nodes[from].id);
        int to_index = find_node_index(nodes[to].id);

        for(int i = 0; i<nodes[from_index].neighbors.size();i++){
            // checks if the id of node's neighbor's at i index matches node's at 2nd index's actual id
            if(nodes[from_index].neighbors[i].first == nodes[to_index].id){
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
    // adjacency list
    map<string, vector<pair<string, int>>> neighbors;
   
    int find_node_index(string id){
        for(int i = 0; i< nodes.size();i++){
            if(nodes[i].id == id){
                return i;
            }
        }
        return -1; 
    } 
    
    crow::json::wvalue to_json() {
        crow::json::wvalue result;
        vector<crow::json::wvalue> nodes_json;
        vector<crow::json::wvalue> edges_json;

        for (auto &node : nodes) {
            nodes_json.push_back(crow::json::wvalue{{"id", node.id}});
            for (auto &neighbor : node.neighbors) {
                edges_json.push_back(crow::json::wvalue{
                    {"source", node.id},
                    {"target", neighbor.first},
                    {"weight", neighbor.second}
                });
            }
        }

        result["nodes"] = std::move(nodes_json);
        result["edges"] = std::move(edges_json);
        return result;
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