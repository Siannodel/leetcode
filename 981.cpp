#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class TimeMap {
public:
    /** Initialize your data structure here. */
    map<string, map<int, string> > list;
    map<int, string>::iterator it;

    TimeMap() {
        list.clear();
    }
    
    void set(string key, string value, int timestamp) {
        list[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if (!list.count(key)) return "";
        it = list[key].lower_bound(timestamp);
        if (it == list[key].end()) return (--it)->second;
        else if(it->first==timestamp) return it->second;
        else if (it!=list[key].begin()) return (--it)->second;
        else return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";

    map<int, string>::iterator it;
    it = m.lower_bound(3.5);
    cout<<it->second<<endl;
    it = m.upper_bound(3.5);
    cout<<it->second<<endl;

    system("pause");
    return 0;
}