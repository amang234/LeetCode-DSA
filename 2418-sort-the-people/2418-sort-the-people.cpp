class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> mpp;
        for(int i=0; i < names.size(); i++) mpp[heights[i]] = names[i];
        sort(heights.begin(), heights.end());
        vector<string> res(heights.size());
        int index = 0;
        for(int i = heights.size() - 1;i>=0;i--) {
            res[index] = mpp[heights[i]];
            index++;
        }
        return res;
    }
};