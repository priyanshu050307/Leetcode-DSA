class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 5>> dp(n + 1);
        vector<array<vector<int>, 5>> path(n + 1);
        vector<pair<vector<int>, int>> v;
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] < b[0];
        });
        vector<int> ends(n);
        for (int i = 0; i < n; i++)
            ends[i] = intervals[i][1];
        auto better = [](long long w1, vector<int>& a,
                         long long w2, vector<int>& b) {
            if (w1 != w2)
                return w1 > w2;
            return a < b;
        };
        for (int i = 1; i <= n; i++) {
            int start = intervals[i - 1][0];
            long long weight = intervals[i - 1][2];
            int idx = intervals[i - 1][3];
            int p = lower_bound(ends.begin(), ends.end(), start) - ends.begin();
            for (int j = 1; j <= 4; j++) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];
                long long newWeight = dp[p][j - 1] + weight;
                vector<int> newPath = path[p][j - 1];
                newPath.push_back(idx);
                sort(newPath.begin(), newPath.end());
                if (better(newWeight, newPath, dp[i][j], path[i][j])) {
                    dp[i][j] = newWeight;
                    path[i][j] = newPath;
                }
            }
        }
        vector<int> ans;
        for (int j = 1; j <= 4; j++) {
            if (better(dp[n][j], path[n][j],
                       dp[n][0], ans)) {
                ans = path[n][j];
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};