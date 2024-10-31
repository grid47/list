
+++
authors = ["Crafted by Me"]
title = "Leetcode 486: Predict the Winner"
date = "2023-07-04"
description = "Solution to Leetcode 486"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/predict-the-winner/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<int> nums;
    vector<vector<map<int, int>>> memo;
    
    int dp(int l, int r, int net) {
        
        if(l == r) return nums[l];
        
        if(memo[l][r].count(net)) return memo[l][r][net];
        
        int ans = net - dp(l + 1, r, net - nums[l]);
        ans = max(ans, net - dp(l, r - 1, net - nums[r]));
        
        return memo[l][r][net] = ans;
    }
    
    bool predictTheWinner(vector<int>& nums) {

        this->nums = nums;
        int n = nums.size();
        memo.resize(n + 1, vector<map<int,int>>(n + 1));
        
        int net = accumulate(nums.begin(), nums.end(), 0);
        
        int ret = dp(0, n - 1, net);

        return ret >= net - ret;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/486.md" >}}
---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

