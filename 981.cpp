#include <vector>
#include <iostream>
#include <string>
#include <map>
using namespace std;

class TimeMap {
public:
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
    cout<<"..."<<endl;
    system("pause");
    return 0;
}
