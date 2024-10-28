
+++
authors = ["Yasir"]
title = "Leetcode 1006: Clumsy Factorial"
date = "2022-01-27"
description = "Solution to Leetcode 1006"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

