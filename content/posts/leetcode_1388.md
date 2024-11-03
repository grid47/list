
+++
authors = ["Crafted by Me"]
title = "Leetcode 1388: Pizza With 3n Slices"
date = "2021-01-14"
description = "In-depth solution and explanation for Leetcode 1388: Pizza With 3n Slices in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/pizza-with-3n-slices/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<vector<vector<int>>> mem;
    vector<int> nums;
    
    int dp(int idx, int fst, int cnt) {

        if(cnt == 0) return 0;
        if(idx >= n) return INT_MIN;
        if(mem[idx][cnt][fst + 1] != -1) return mem[idx][cnt][fst + 1];
        
        int ans = dp(idx + 1, fst, cnt);
        if((idx + 1)% n != fst) {
            ans = max(ans, dp(idx + 2, fst, cnt - 1) + nums[idx]);
        }

        return mem[idx][cnt][fst + 1] = ans;
    }
    
    int maxSizeSlices(vector<int>& nums) {
        this->n = nums.size();
        mem.resize(n, vector<vector<int>>(n/3 + 1, vector<int>(n + 1, -1)));
        this->nums = nums;
        int res = 0;
        for(int i = 0; i < nums.size(); i++)
            res = max(res, dp(i + 2, i, n/3 - 1) + nums[i]);
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1388.md" >}}
---


"| 1389: Create Target Array in the Given Order |"

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

