class Solution {
public:
    vector<vector<int>> offsets = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    bool func(vector<vector<char>>& board, vector<vector<int>>& visited, string &word, int i, int j, int n)
    {
        if (n >= word.size())
        {
            return true;
        }

        int h = board.size();
        int w = board[0].size();

        if (i < 0 || i >= h || j < 0 || j >= w)
        {
            return false;
        }
        if (visited[i][j] == 0 && board[i][j] == word[n])
        {
            visited[i][j] = 1;
            for (auto off : offsets)
            {
                int off_i = off[0];
                int off_j = off[1];
                bool flag = func(board, visited, word, i + off_i, j + off_j, n+1);
                if (flag)
                {
                    return true;
                }
            }
            visited[i][j] = 0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if (word == "") return true;
        int h = board.size();
        if (h == 0) return false;
        int w = board[0].size();

        vector<vector<int>> visited(h, vector<int>(w, 0));

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                bool flag = func(board, visited, word, i, j, 0);
                if (flag) return true;
            }
        }
        return false;
    }
};