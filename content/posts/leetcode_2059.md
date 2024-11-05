
+++
authors = ["Crafted by Me"]
title = "Leetcode 2059: Minimum Operations to Convert Number"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2059: Minimum Operations to Convert Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-convert-number/description/)

---

**Code:**

{{< highlight cpp >}}
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


---
{{< youtube jrWEsrkfBjg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2060: Check if an Original String Exists Given Two Encoded Strings](https://grid47.xyz/posts/leetcode_2060) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}

