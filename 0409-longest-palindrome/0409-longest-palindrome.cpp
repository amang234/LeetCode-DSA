class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> cs;
        int l = 0;
        for(char c:s){
            if(cs.find(c) != cs.end()) {
                cs.erase(c);
                l += 2;
            } else cs.insert(c);
        }
        if(!cs.empty()) l+=1;
        return l;
    }
};