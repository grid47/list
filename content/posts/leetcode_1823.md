
+++
authors = ["Yasir"]
title = "Leetcode 1823: Find the Winner of the Circular Game"
date = "2019-11-02"
description = "Solution to Leetcode 1823"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++)
            q.push(i);
        
        while(q.size() != 1) {
            int x= k;
            while(x > 1) {
                int r = q.front();
                q.pop();
                q.push(r);
                x--;
            }
            q.pop();
        }
        
        return q.front();
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

