class Solution {
public:
    string minWindow(string s, string t) {
    unordered_map<char, int> target, window;
    int required = t.size();  // Count of characters required to be in the window
    int left = 0, right = 0;  // Window pointers
    int minLen = INT_MAX, minStart = 0;

    // Populate target map with character frequencies in t
    for (char ch : t) {
        target[ch]++;
    }

    while (right < s.size()) {
        char currentChar = s[right];

        // Check if the current character is required
        if (target.count(currentChar)) {
            window[currentChar]++;

            // If the count in the window is equal to the count in the target, decrement required
            if (window[currentChar] <= target[currentChar]) {
                required--;
            }
        }

        // Try to minimize the window by moving the left pointer
        while (required == 0) {
            // Update the minimum window substring
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            char leftChar = s[left];

            // Move the left pointer to the right and update window and required count
            if (target.count(leftChar)) {
                window[leftChar]--;
                if (window[leftChar] < target[leftChar]) {
                    required++;
                }
            }

            left++;
        }

        // Move the right pointer to the right
        right++;
    }

    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}
};