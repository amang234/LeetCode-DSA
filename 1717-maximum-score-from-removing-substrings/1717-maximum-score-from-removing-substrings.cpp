class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a = 0;
        int b = 0;
        int l = min(x,y);
        int res = 0;

        for(char c:s){
            if(c>'b'){
                res += min(a,b) * l;
                a = 0; 
                b = 0; 
            } else if(c=='a'){
                if(x<y && b >0){
                    b--;
                    res += y;
                } else a++;
            } else {
                if(x>y && a>0){
                    a--;
                    res += x;
                } else b++;
            }
        }
        res += min(a,b) * l;
        return res;
    }
};