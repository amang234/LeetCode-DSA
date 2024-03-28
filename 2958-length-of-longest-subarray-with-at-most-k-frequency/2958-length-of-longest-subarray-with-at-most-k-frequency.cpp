class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map <int,int> mpp;
        int n = size(nums);
        int l = 0;
        for(int i = 0;i<n;i++){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>k){
                while(nums[l]!=nums[i])
                    mpp[nums[l]]--;
                    l++;
                mpp[nums[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};