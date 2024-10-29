
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 384: Shuffle an Array"
date = "2023-10-12"
description = "Solution to Leetcode 384"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shuffle-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> arr;
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> stk(arr);
        int n = stk.size();
        for(int i = 0; i < n; i++) {
            int j = rand() % (n - i);
            swap(stk[i + j], stk[i]);
        }
        return stk;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/384.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

