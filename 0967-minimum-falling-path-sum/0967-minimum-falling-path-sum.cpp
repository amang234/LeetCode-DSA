class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n  = matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; ++j){
                if(i==0)
                    dp[i][j]=matrix[i][j];
                
                else{
                    dp[i][j] = dp[i-1][j];
                    if(j!=0) dp[i][j] = min(dp[i][j] ,dp[i-1][j-1]);
                    if(j!=n-1)dp[i][j] = min(dp[i][j],dp[i-1][j+1]);
                    dp[i][j] +=matrix[i][j];
                }
            }
        }

        return *min_element(dp[n-1].begin(),dp[n-1].end());

    }
};