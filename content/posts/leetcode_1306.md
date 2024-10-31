
+++
authors = ["Crafted by Me"]
title = "Leetcode 1306: Jump Game III"
date = "2021-04-05"
description = "Solution to Leetcode 1306"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0)
                return true;
            int l = i - arr[i];
            int r = i + arr[i];
            arr[i] = -arr[i];
            if (l > -1 && arr[l] > -1) q.push(l);
            if (r < n  && arr[r] > -1) q.push(r);
        }
        
        return false;
    }
};
{{< /highlight >}}


---
{{< youtube 9oUhzPLmLZQ >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

