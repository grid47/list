
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 84: Largest Rectangle in Histogram"
date = "2024-08-07"
description = "Solution to Leetcode 84"
tags = [
    
]
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}
