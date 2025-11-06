#include "functions.h"

//Look up object
Person lookup_id_get_obj(string id, map<string,Person>& a_map){  // change name
    return a_map[id];

} 

float id_to_value_physical(string& id, Person& p_source,  map<string,Person>& a_map){
    Person per = lookup_id_get_obj(id, a_map);
    float value = per.calcPhysicalDif(p_source);
    return value;
}

float id_to_value_personality(string& id, Person& p_source,  map<string,Person>& a_map){
    Person per = lookup_id_get_obj(id, a_map);
    float value = per.calcPersDif(p_source);
    return value;
}
//THIS IS A SUM, NOT AVERAGE
float sum_personality_and_physical(string& id, Person& p_source, map<string,Person>& a_map){
    float personality = id_to_value_personality(id, p_source, a_map);
    float physical = id_to_value_physical(id, p_source, a_map);
    return personality + physical;
}

float compare_to_zero(string& id, Person& p_source){
    return 0.0;
}

float id_to_value_type(string& id, Person& p_source,  map<string,Person>& a_map,int type){
    if(type == 0){
        return id_to_value_personality(id, p_source, a_map);
    }else if(type == 1){ 
        return id_to_value_physical(id, p_source, a_map);
    }else if(type == 2){
        return sum_personality_and_physical(id, p_source, a_map);
    }else if(type == 3){
        return 0.0; // placeholder
    }else{
        return 0.0; // placeholder
    } 
}


Graph build_graph(map<string,Person>& a_map, vector<string>& vector_id){
    int connections_max = 3;
    //Calc Graph Implementaion
    Graph calc_graph;
    // optimized version
    int count = 0;
    // vector that stores the vector of pre calcuated weights for one node, in which that weight is stored as a pair of id and weight
    vector<vector<pair<string, float>>> pre_calc_weights(vector_id.size(), vector<pair<string, float>>());
     for(int i =0; i< vector_id.size();i++){
        Person& person_one = a_map[vector_id[i]]; // create a copy of person one
       
        for(int j= i+1; j< vector_id.size(); j++){
            Person& person_two = a_map[vector_id[j]];    // create a copy of person two

            // float weight_personality_euclidean = person_one.calcPersDif_euclidean(person_two); // calculate personality weight
            // float weight_physical_euclidean = person_one.calcPhysicalDif_euclidean(person_two); // calculate physical weight
              
            float weight_personality = person_one.calcPersDif(person_two)/4.0f; // calculate personality weight
            float weight_physical = person_one.calcPhysicalDif(person_two)/4.0f; // calculate physical weight
          

            float total_weight = (weight_personality*0.8 + weight_physical*0.2); // average weight
            
            pre_calc_weights[i].push_back({vector_id[j], total_weight});
            pre_calc_weights[j].push_back({vector_id[i], total_weight}); // symmetric
        }
        heapSort_generic(pre_calc_weights[i], true); // sort by total weight, min heap
        
        // add top connections:
        // either adds max number of connections, or all possible connections, whichever is smaller
        for(int c = 0; c < min(connections_max, (int)pre_calc_weights[i].size()); c++){
           
            calc_graph.add_edge(vector_id[i], pre_calc_weights[i][c].first, pre_calc_weights[i][c].second);

            // adding the edge between two nodes. 
            // provided the person on eid, current person two id, and the vector of vector weights
            // inside the vector, aka the vector of weights for the node, provide the 2nd value,
            // which is the weight between the two nodes, storing the total weight
        }
  
        count++;
        cout << count << ", ";
    }
    return calc_graph;
}


