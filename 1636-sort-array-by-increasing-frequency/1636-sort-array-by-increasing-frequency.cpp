class Solution {
public:
    // counting sort for unique x in the decreasing order 
    static void counting_sort(auto& arr) {// this simplifed version is sufficient for use
        if (arr.empty()) return;
        auto [xMin, xMax] = minmax_element(arr.begin(), arr.end());
        int m = *xMin, v = *xMax - m + 1;
        vector<bool> cnt(v, 0);
        for (int x : arr)
            cnt[x - m]=1;
        for (int y = v-1, i=0; y >= 0; y--) { //sort in decreasing order
            if (cnt[y]==0) continue;
            arr[i]=y+m;
            i++;
        }
    }

    static vector<int> frequencySort(vector<int>& nums) {
        const int n = nums.size();
        vector<int> freq(201, 0);
        int maxF = 0, maxX = -1;
        for (int x : nums) {
            x += 100; // x-min_x where min_x=-100
            int f = ++freq[x];
            maxX = max(x, maxX);
            maxF = max(f, maxF);
        }
        vector<vector<int>> freqx(maxF + 1);
        for (int x = 0; x <= maxX; x++) {
            if (freq[x] > 0)
                freqx[freq[x]].push_back(x-100); // Adjust value back
        }

        int i = 0;
        for (int f = 1; f <= maxF; f++) {
            auto& arr = freqx[f];
            counting_sort(arr);
            for (int x : arr) {// each x occurs f times
                fill(nums.begin()+i, nums.begin()+i+f, x);
                i+=f;
            }
        }
        return nums;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();