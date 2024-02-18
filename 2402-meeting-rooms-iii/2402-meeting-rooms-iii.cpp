class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int m = meetings.size();
        vector<int> room_meeting_count(n, 0);
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,greater<pair<long long, int>>>busy;

        for (int i = 0; i < n; ++i) {
            available.push(i);
        }

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            while (busy.size() > 0 && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (available.size() > 0) {
                int top = available.top();
                room_meeting_count[top]++;
                available.pop();
                busy.push({end, top});
                continue;
            }
            auto top = busy.top();
            int available_time = top.first, index = top.second;
            busy.pop();
            room_meeting_count[index]++;
            busy.push({top.first + end - start, index});
        }

        return max_element(room_meeting_count.begin(),
                           room_meeting_count.end()) -
               room_meeting_count.begin();
    }
};