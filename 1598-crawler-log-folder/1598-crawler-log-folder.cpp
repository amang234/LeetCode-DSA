class Solution {
public:
    int minOperations(vector<string>& logs) {
        vector<string> path;
        for(const string& log:logs) {
            if(log=="../") {
                if(!path.empty()) path.pop_back();
            } else if(log !="./") path.push_back(log);
        }
        return path.size();
    }
};