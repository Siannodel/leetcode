class ExamRoom {
public:
    set<int> s;
    int n;
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        if (s.empty())
        {
            s.insert(0);
            return 0;
        }
        int max_d = 0;
        int pre_i = -1;
        int pos = 0;
        for (auto i : s)
        {
            int d;
           
            
            d = (i - pre_i) / 2;
            
            if (d > max_d)
            {
                pos = pre_i == -1 ? 0 : pre_i + d;
                max_d = d;
            }
            pre_i = i;
        }
        if (n - pre_i - 1 > max_d)
        {
            pos = n - 1;
        }
        s.insert(pos);
        return pos;
    }
    
    void leave(int p) {
        s.erase(p);
    }
};
