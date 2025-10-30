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

float id_to_value_type(string& id, Person& p_source,  map<string,Person>& a_map,int type){
    if(type == 0){
        return id_to_value_personality(id, p_source, a_map);
    } else {
        return id_to_value_physical(id, p_source, a_map);
    }
}
