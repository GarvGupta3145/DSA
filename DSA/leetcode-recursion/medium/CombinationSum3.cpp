#include<bits/stdc++.h>
class Solution {
public:
    void solve(int curr, int n, int k, vector<int>& ans, vector<vector<int>>& res) {
        if (n < 0) return;
        if (ans.size() == k) {
            if (n == 0)
                res.push_back(ans);
            return;
        }
         if (curr > 9) return;
        // if (ans.size() + (9 - curr + 1) < k) return;
        ans.push_back(curr);
        solve(curr + 1, n - curr, k, ans, res);
        ans.pop_back();
        solve(curr + 1, n, k, ans, res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<vector<int>> res;
        solve(1, n, k, ans, res);
        return res;
    }
};
