
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2515: Shortest Distance to Target String in a Circular Array"
date = "2017-12-11"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

