class Solution {
public:
    int appendCharacters(string s, string t) {
        int indexS = 0;
        int indexT = 0;
        int lengthS = s.length();
        int lengthT = t.length();

        while(indexS < lengthS && indexT < lengthT) {
            if(s[indexS] == t[indexT]) indexT++;
            indexS++;
        }
        return lengthT - indexT;
    }
};