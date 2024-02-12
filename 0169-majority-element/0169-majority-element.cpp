class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> mpp;
        int n=nums.size()/2;
        for(auto a:nums) mpp[a]++;
        int ans=0;
        for(auto a:mpp) {
            if(a.second>n) ans = a.first;
        }
        return ans;
    }
};