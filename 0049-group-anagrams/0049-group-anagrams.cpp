class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        vector<vector<string>> s;
        for(auto it: strs){
            string temp = it;
            sort(it.begin(),it.end());
            mpp[it].push_back(temp);
        }
        for(auto it : mpp){
            vector<string>temp;
            temp = it.second;
            s.push_back(temp);
        }

        return s;

    }
};