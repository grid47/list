
+++
authors = ["grid47"]
title = "Leetcode 517: Super Washing Machines"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 517: Super Washing Machines in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
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
---
{{< youtube 7xvqjefQkt0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #518: Coin Change II](https://grid47.xyz/posts/leetcode_518) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
