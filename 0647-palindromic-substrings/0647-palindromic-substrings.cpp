class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int count = 0;
        for(int d=0;d<s.size();d++){
            for(int i=0,j=d;j<s.size();i++,j++){
                if(d==0) dp[i][j]=true;
                else if(d==1){
                    if(s[i]==s[j]) dp[i][j]=true;
                    else dp[i][j]=false;
                } else {
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                    else dp[i][j]=false;
                }
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};