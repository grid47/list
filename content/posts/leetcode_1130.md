
+++
authors = ["Crafted by Me"]
title = "Leetcode 1130: Minimum Cost Tree From Leaf Values"
date = "2021-09-28"
description = "Solution to Leetcode 1130"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        
        int res = 0;
        
        vector<int> stk = { INT_MAX };
        for(int a : arr) {
            while(stk.back() <= a) {
                int mid = stk.back();
                stk.pop_back();
                res += mid * min(stk.back(), a);
            }
            stk.push_back(a);
        }
        
        for(int i = 2; i < stk.size(); i++) {
            res += stk[i] * stk[i - 1];
        }
        
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

