
+++
authors = ["Crafted by Me"]
title = "Leetcode 406: Queue Reconstruction by Height"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 406: Queue Reconstruction by Height in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/queue-reconstruction-by-height/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort( people.begin(), people.end(), [] (vector<int> a, vector<int> b) {
            
            return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
            
        });
        
        vector<vector<int>> ans;
        for(auto p: people) 
            ans.insert(ans.begin() + p[1], p);
        
        return ans;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/406.md" >}}
---
{{< youtube 6plztg2nnjY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #407: Trapping Rain Water II](https://grid47.xyz/posts/leetcode_407) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

