
+++
authors = ["Crafted by Me"]
title = "Leetcode 2147: Number of Ways to Divide a Long Corridor"
date = "2018-12-17"
description = "In-depth solution and explanation for Leetcode 2147: Number of Ways to Divide a Long Corridor in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-divide-a-long-corridor/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    
    
    int numberOfWays(string corridor) {
        int n = corridor.size();
        vector<int> itr;
        for(int i = 0; i < n; i++)
            if(corridor[i] == 'S') 
                itr.push_back(i);
        
        if((itr.size() % 2) || (itr.size() == 0)) return 0;
        
        long long res = 1;
        
        int prv = itr[1];
        
        for(int i = 2; i < itr.size(); i += 2) {
            
            int len = itr[i] - prv;
            
            res = (res * len) % mod;
            
            prv = itr[i + 1];
        }
        return res;
    }
};
{{< /highlight >}}


---
{{< youtube YOTjCd4Eyhc >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2148: Count Elements With Strictly Smaller and Greater Elements ](https://grid47.xyz/posts/leetcode_2148) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

