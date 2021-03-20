#include <vector>
#include <string>
using namespace std;

class UF
{
public:
    UF(int n)
    {
        count = n;
        parent = vector<int>(n, 0);
        size = vector<int>(n, 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    void connect(int p, int q)
    {
        int parent_p = find(p);
        int parent_q = find(q);
        if (size[parent_p] >= size[parent_q])
        {
            parent[parent_q] = parent_p;
            size[parent_p] += size[parent_q];
        }
        else
        {
            parent[parent_p] = parent_q;
            size[parent_q] += size[parent_p];
        }
        count--;
        return;
    }

    int get_count()
    {
        return count;
    }

    bool connected(int p, int q)
    {
        int parent_p = find(p);
        int parent_q = find(q);
        return parent_p == parent_q;
    }

private:

    int find(int x)
    {
        while(parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    vector<int> parent;
    vector<int> size;
    int count;
};

bool equations_possible(vector<string> equations)
{
    UF uf(26);

    for (auto eq : equations)
    {
        if (eq[1] == '=')
        {
            char a = eq[0];
            char b = eq[3];
            uf.connect(a - 'a', b - 'a');
        }
    }

    for (auto eq : equations)
    {
        if (eq[1] == '!')
        {
            char a = eq[0];
            char b = eq[3];
            if (uf.connected(a - 'a', b - 'a'))
            {
                return false;
            }
        }
    }
    return true;
}
