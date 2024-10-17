class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        int secondaryNum = num;
        while(num > 0){
            int temp = num % 10;
            digits.push_back(temp);
            num = num/10;
        }

        int n = digits.size();
        int i = 0, j = n-1;
        while(i <= j){
            swap(digits[i++], digits[j--]);
        }

        i = 0;
        bool isSwap = false;
        while(i < n-1){
            int temp = digits[i];
            int maxi = INT_MIN, ind = -1;
            for(j = i+1; j<n; j++){
                if(digits[j] > temp){
                    if(digits[j] >= maxi){
                        maxi = digits[j];
                        ind = j;
                    }
                }
            }
            if(maxi != INT_MIN){
                swap(digits[i], digits[ind]);
                isSwap = true;
                break;
            }
            else{
                i++;
            }
        }

        if(isSwap == false){
            return secondaryNum;
        }

        int ans = 0;
        for(int k=0; k<n; k++){
            ans = (ans * 10) + digits[k];
        }

        return ans;
    }
};