#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	char helper(char c1, char c2, bool& carry)
	{
		char res;
		bool new_carry = false;
		if (c1 == '0' && c2 == '0')
			res = '0';
		else if (c1 == '1' && c2 == '1')
		{
			res = '0';
			new_carry = true;
		}
		else
			res = '1';

		if (carry)
		{
			if (res == '0')
				res = '1';
			else
			{
				res = '0';
				new_carry = true;
			}

		}
		carry = new_carry;
		return res;
	}
	string addBinary(string a, string b) {
		if (b.size() > a.size())
			swap(a, b);
		//a.size() >= b.size()
		string res(a.size() + 1, '0');
		int a_i = a.size() - 1;
		int b_i = b.size() - 1;
		int res_i = res.size() - 1;
		bool carry = false;
		while (b_i >= 0)
		{
			res[res_i] = helper(a[a_i], b[b_i], carry);
			--b_i;
			--a_i;
			--res_i;
		}
		if (carry)
		{
			res[res_i] = '1';
			carry = false;
		}

		while (a_i >= 0)
		{
			res[res_i] = helper(res[res_i], a[a_i], carry);
			--a_i;
			--res_i;
		}
		if (carry)
		{
			res[res_i] = '1';
			carry = false;
		}
		if (res[0] == '0')
			res = res.substr(1, res.size() - 1);
		return res;
	}
};

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size());
        int carry = 0;
        for (size_t i = 0; i < n; ++i)
        {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry%2)? '1' : '0');
            carry /= 2;
        }
        if (carry) 
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};