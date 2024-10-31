
+++
authors = ["Crafted by Me"]
title = "Leetcode 735: Asteroid Collision"
date = "2022-10-28"
description = "Solution to Leetcode 735"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

