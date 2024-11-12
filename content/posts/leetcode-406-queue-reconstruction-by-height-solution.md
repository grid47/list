
+++
authors = ["grid47"]
title = "Leetcode 406: Queue Reconstruction by Height"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 406: Queue Reconstruction by Height in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Indexed Tree","Segment Tree","Sorting"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #409: Longest Palindrome](https://grid47.xyz/posts/leetcode-409-longest-palindrome-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
