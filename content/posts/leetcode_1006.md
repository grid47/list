
+++
authors = ["Crafted by Me"]
title = "Leetcode 1006: Clumsy Factorial"
date = "2022-01-31"
description = "In-depth solution and explanation for Leetcode 1006: Clumsy Factorial in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/clumsy-factorial/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int clumsy(int n) {
        
        int ans = n;
        int j = n - 1;
        vector<int> stk;
        
        for(int i = 1; i < n; i++) {
            
                 if(i % 4 == 1) ans *= j--;
            else if(i % 4 == 2) ans /= j--;
            else {
                
                stk.push_back(ans);
                
                if(i % 4 == 3) ans = j--;
                        else   ans = (-1 * j--);
                
            }
            
        }
        
        int sum = 0;
        for(int i = 0; i < stk.size(); i++)
            sum += stk[i];
        
        return sum + ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1006.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

