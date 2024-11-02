
+++
authors = ["Crafted by Me"]
title = "Leetcode 2515: Shortest Distance to Target String in a Circular Array"
date = "2016-12-13"
description = "Solution to Leetcode 2515"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
        int n = words.size(), ans = INT_MAX;
        
        for(int i = 0; i < n; i++) 
            if(words[i] == target) 
                ans = min(ans, min(abs(s - i), abs(n - abs(s - i)))); 
        
        return ans == INT_MAX ? -1 : ans;
    }
};
{{< /highlight >}}


---
{{< youtube yTpRd3yvyz0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

