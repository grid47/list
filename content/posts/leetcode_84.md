
+++
authors = ["Crafted by Me"]
title = "Leetcode 84: Largest Rectangle in Histogram"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 84: Largest Rectangle in Histogram in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-rectangle-in-histogram/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> stk;
        int n = h.size();
        vector<int> left(n, 0), right(n, 0);
        for(int i = 0; i < h.size(); i++) {
            if(stk.empty()) {
                left[i] = -1;
                stk.push(i);
            } else {
                while(!stk.empty() && h[i] <= h[stk.top()])
                    stk.pop();
                if(stk.empty())
                    left[i] = -1;
                else left[i] = stk.top();
                stk.push(i);
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout << left[i] << " ";
        // cout << '\n';
        while(!stk.empty()) stk.pop();
        for(int i = h.size() -1; i >= 0; i--) {
            
            if(stk.empty()) {
                right[i] = n;
                stk.push(i);
            } else {
                while(!stk.empty() && h[i] <= h[stk.top()])
                    stk.pop();
                if(stk.empty())
                    right[i] = n;
                else right[i] = stk.top();
                stk.push(i);
            }
        }
        // for(int i = 0; i < n; i++)
        //     cout << right[i] << " ";
        // cout << '\n';        
        int res = 0;
        for(int i = 0; i < n; i++)
            res = max(res, h[i] * (right[i] - left[i] - 1));
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/84.md" >}}
---
{{< youtube zx5Sw9130L0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #86: Partition List](https://grid47.xyz/posts/leetcode_86) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
