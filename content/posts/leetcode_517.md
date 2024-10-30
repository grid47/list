
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 517: Super Washing Machines"
date = "2023-06-02"
description = "Solution to Leetcode 517"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/super-washing-machines/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int findMinMoves(vector<int>& nums) {
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        if(sum % n != 0) return -1;
        if(sum == 0) return 0;
        int res = -1;
        int hit = sum / n;
        
        vector<int> left(n, 0), right(n, 0);
        
        for(int i = 1; i < n; i++)
            left[i] = left[i - 1] + nums[i - 1];
        
        for(int i = n - 2; i >= 0; i--)
            right[i] = right[i + 1] + nums[i + 1];
        
        for(int i = 0; i < n; i++) {
            int expLeft = i * hit;
            int expRight = (n - 1 - i) * hit;
            int lefts = 0;
            int rights = 0;
            if(expLeft > left[i]) {
                lefts = expLeft - left[i];
            }
            if(expRight > right[i]) {
                rights = expRight - right[i];
            }
            res = max(res, lefts + rights);
        }
        return res;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/517.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

