
+++
authors = ["Yasir"]
title = "Leetcode 2059: Minimum Operations to Convert Number"
date = "2019-03-11"
description = "Solution to Leetcode 2059"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-convert-number/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        queue<int> q;
        set<int> seen;
        q.push(start);
        seen.insert(start);
        int op = 0;
        while(!q.empty()) {
            int sz = q.size();
            op++;
            while(sz--) {
                int x = q.front();
                q.pop();
                for(auto it: nums) {
                    if((x + it) == goal || (x - it) == goal || (x ^ it) == goal)
                        return op;
                    
                    if(!seen.count(x + it) && x + it <= 1000 && x + it >= 0) {
                        seen.insert(x + it);                        
                        q.push(x + it);
                    }
                    
                    if(!seen.count(x - it) && x - it <= 1000 && x - it >= 0) {
                        seen.insert(x - it);
                        q.push(x - it);
                    }             
                    
                    if(!seen.count(x ^ it) && (x ^ it) <= 1000 && (x ^ it) >= 0) {
                        seen.insert(x ^ it);
                        q.push(x ^ it);
                    }                    
                }
            }
        }
        
        return -1;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

