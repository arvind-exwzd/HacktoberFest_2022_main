class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numFactoredBinaryTrees(vector<int>& A) {
        int n = A.size(), mx, ans = 0;
        sort(A.begin(), A.end());
        
        unordered_map<int, int> dp;
        
        for (int i = 0; i < n; i++){
            dp[A[i]] = 1;
            mx = sqrt(A[i]);
            for (int j = 0; j < i && A[j] <= mx; j++){
                if (A[i] % A[j] == 0){
                    dp[A[i]] = (0LL + dp[A[i]] + 1LL * dp[A[j]] * dp[A[i]/A[j]]) % MOD;
                    if (A[j] != A[i]/A[j]) dp[A[i]] = (0LL + dp[A[i]] + 1LL * dp[A[j]] * dp[A[i]/A[j]]) % MOD;
                }
            }
            ans = (0LL + ans + dp[A[i]]) % MOD;
        }
        return ans;
    }
};
