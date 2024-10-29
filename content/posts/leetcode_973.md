
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 973: K Closest Points to Origin"
date = "2022-03-02"
description = "Solution to Leetcode 973"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-closest-points-to-origin/description/)

---

**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] * a[0] + a[1] * a[1] > b[0]* b[0] + b[1] * b[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto it : pts) {
            pq.push(it);
        }
        
        vector<vector<int>> ans;
        while(k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

