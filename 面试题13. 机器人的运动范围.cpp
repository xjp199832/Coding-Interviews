/*地上有一个m行n列的方格，从坐标[0, 0] 到坐标[m - 1, n - 1] 。一个机器人从坐标[0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格[35, 37] ，因为3 + 5 + 3 + 7 = 18。但它不能进入方格[35, 38]，因为3 + 5 + 3 + 8 = 19。请问该机器人能够到达多少个格子？*/
#include <vector>
using namespace std;

class Solution {
    vector<vector<bool>> visited;
    int m, n;
public:
    int movingCount(int m, int n, int k) {
        this->m = m;
        this->n = n;
        visited = vector<vector<bool>>(m);
        for (int i = 0; i < m; i++)
            visited[i].resize(n, false);
        
        return dfs(0, 0, k);
    }

    int dfs(int i, int j, int k)
    {
        
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || check(i,j,k))
            return 0;
        visited[i][j] = true;
        return 1 + dfs(i + 1, j, k) + dfs(i, j + 1, k);
    }

    bool check(int i, int j, int k)
    {
        int num = i % 10 + i / 10 + j % 10 + j / 10;
        return num <= k;
    }
};