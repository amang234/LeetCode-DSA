class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mpp;
        int ans = 0;
        for(auto it : s) mpp[it]++;
        for(auto it : t) mpp[it]--;
        for(auto it : mpp) ans += abs(it.second);

        return ans/2;  
    }
};