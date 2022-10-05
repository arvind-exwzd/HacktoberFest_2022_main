class Solution {
public:
    int dp[101][101];
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle) {
        int m = obstacle.size();
        int n = obstacle[0].size();
        
        for (int i = 0; i < m; i++) {
            if ( obstacle[i][0] ) break;
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            if ( obstacle[0][i] ) break;
            dp[0][i] = 1;
        }
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (obstacle[i][j] == 0) 
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
};
