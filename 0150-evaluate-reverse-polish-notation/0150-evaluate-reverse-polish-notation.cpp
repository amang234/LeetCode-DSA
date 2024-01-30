class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> a;
        int res = 0;
            if(tokens.size() ==  1){
                return stoi(tokens[0]);
            }
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int y = a.top();
                a.pop();
                int x = a.top();
                a.pop();

                int val;
                if (tokens[i] == "+") val = x + y;
                else if (tokens[i] == "-") val = x - y;
                else if (tokens[i] == "*") val = x * y;
                else if (tokens[i] == "/") val = x / y;

                a.push(val);
                res = val;
            } else {
                a.push(stoi(tokens[i]));
            }
        }

        return res;
    }
};
