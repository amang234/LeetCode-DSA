class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> charcount;
        for(char c:order) charcount[c] = 0;
        for(char c:s) {
            if(charcount.find(c) != charcount.end()) charcount[c]++;
        }
        string sortedS;
        for(char c: order) sortedS.append(charcount[c],c);
        for(char c:s) {
            if(charcount.find(c) == charcount.end())  sortedS.push_back(c);
        }
        return sortedS;
    }
};