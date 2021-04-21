#include <stack>

using namespace std;

class CQueue {
public: 
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (s2.empty()) return -1;
        int value = s2.top();
        s2.pop();
        return value;
    }
private:
    stack<int> s1;
    stack<int> s2;
};