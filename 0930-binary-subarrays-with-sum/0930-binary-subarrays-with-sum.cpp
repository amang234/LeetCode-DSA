class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int cur_sum = 0;
        int total_subarr = 0;

        for(int num : nums) {
            cur_sum += num;
            if(mpp.find(cur_sum - goal) != mpp.end()) {
                total_subarr += mpp[cur_sum - goal];
            }
            mpp[cur_sum]++;
        }
        return total_subarr;
    }
};