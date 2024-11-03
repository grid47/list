
+++
authors = ["Crafted by Me"]
title = "Leetcode 735: Asteroid Collision"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 735: Asteroid Collision in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/asteroid-collision/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {

        int dir = 0, n = ast.size();
        vector<int> stk;

        for(int a : ast) {

            bool eq = false;
                while(!stk.empty()                  && 
                      (((double)stk.back()/a) < 0 && a < 0)  && 
                      (abs(stk.back()) < abs(a))) {
                    
           
                    stk.pop_back();
                    
                }
            
 
            
            if(!stk.empty() && (stk.back() == -a && a < 0)) { 

           // cout << stk.back();                
                
                stk.pop_back();                
                
                continue; 
            }

            if (stk.empty() || ((double)stk.back()/a > 0) || ((double)stk.back()/a < 0 && a > 0))
                stk.push_back(a);
            
        }
        return stk;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/735.md" >}}
---
{{< youtube LN7KjRszjk4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #736: Parse Lisp Expression](https://grid47.xyz/posts/leetcode_736) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

