
+++
authors = ["Crafted by Me"]
title = "Leetcode 77: Combinations"
date = "2024-08-16"
description = "Solution to Leetcode 77"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/combinations/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        vector<vector<int>> ans;
        vector<int> tmp;
        
            bt(ans, 1, k, tmp);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, int i, int k, vector<int> &tmp) {
        if(tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }
        if(i == n + 1) return;
        
        for(int j = i; j <= n; j++) {
            tmp.push_back(j);
            bt(ans, j + 1, k, tmp);
            tmp.pop_back();
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/77.md" >}}

---

{{< youtube q0s6m7AiM7o >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

