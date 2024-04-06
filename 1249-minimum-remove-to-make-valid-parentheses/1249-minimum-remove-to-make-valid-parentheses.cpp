class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int opc = 0;
        vector<char> arr(s.begin(), s.end());

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == '(')
                opc++;
            else if (arr[i] == ')') {
                if (opc == 0)
                    arr[i] = '*';
                else
                    opc--;
            }
        }

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (opc > 0 && arr[i] == '(') {
                arr[i] = '*'; 
                opc--;
            }
        }
        
        string result = "";
        for (char c : arr) {
            if (c != '*')
                result += c;
        }

        return result;
    }
};