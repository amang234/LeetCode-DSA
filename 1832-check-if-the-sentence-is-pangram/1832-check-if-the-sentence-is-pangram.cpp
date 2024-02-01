class Solution {
public:
    bool checkIfPangram(string sentence) {
         unordered_set<char> alphabetSet;
        
        for (char i = 'a'; i <= 'z'; i++) {
            alphabetSet.insert(i);
        }

        for (int i = 0; i < sentence.length(); i++) {
            alphabetSet.erase(sentence[i]);
            if (alphabetSet.empty()) {
                return true;
            }
        }

        return false;
    }
};