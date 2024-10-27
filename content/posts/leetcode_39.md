
+++
authors = ["Yasir"]
title = "Leetcode 39: Combination Sum"
date = "2024-09-19"
description = "Solution to Leetcode 39"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combination-sum/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, 0, target, cand);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx, int sum, vector<int> &cand) {
        if(idx == cand.size() || sum == 0) {
            if(sum == 0) ans.push_back(tmp);
            return;
        }
        if(sum < 0) return;
        tmp.push_back(cand[idx]);
        bt(ans, tmp, idx, sum - cand[idx], cand);
        tmp.pop_back();
        
        bt(ans, tmp, idx + 1, sum, cand);
    }
};
{{< /highlight >}}

