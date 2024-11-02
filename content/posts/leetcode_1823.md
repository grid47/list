
+++
authors = ["Crafted by Me"]
title = "Leetcode 1823: Find the Winner of the Circular Game"
date = "2018-11-05"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

