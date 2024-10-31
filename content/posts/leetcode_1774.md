
+++
authors = ["Crafted by Me"]
title = "Leetcode 1774: Closest Dessert Cost"
date = "2019-12-24"
description = "Solution to Leetcode 1774"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/closest-dessert-cost/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int target;
    vector<int> top;
    
    int closestCost(vector<int>& base, vector<int>& top, int target) {
        this->target = target;
        this->top = top;
        int ans = 0;
        for(int i = 0; i < base.size(); i++)
            ans = close(ans, dfs(0, base[i]));
        return ans;
    }
    
    
    int dfs(int idx, int sum) {
        if(idx >= top.size()) return sum;
        
        int a = dfs(idx + 1, sum + top[idx]);
        int b = dfs(idx + 1, sum + 2 * top[idx]);
        int c = dfs(idx + 1, sum);
        
        return close(a, close(b, c));
    }
    
    int close(int a, int b) {
        if(a == 0) return b;
        if(b == 0) return a;
        
        if(abs(target - a) == abs(target - b))
            return a < b? a: b;
        
        return abs(target - a) < abs(target - b) ? a: b;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

