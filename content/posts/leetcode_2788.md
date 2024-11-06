
+++
authors = ["Crafted by Me"]
title = "Leetcode 2788: Split Strings by Separator"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2788: Split Strings by Separator in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-strings-by-separator/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char sep) {
        
        vector<string> ans;
        
        for(int i = 0; i < words.size(); i++) {
            string cur = "";
            
            for(int j = 0; j < words[i].size(); j++) {
                if(words[i][j] == sep) {
                    if(cur != "")
                    ans.push_back(cur);
                    cur = "";
                } else if(j == words[i].size() - 1) {
                    cur += words[i][j];                    
                    ans.push_back(cur);
                    cur = "";
                } else 
                cur += words[i][j];
            }
            
        }
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube DdjLhSeodGs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2789: Largest Element in an Array after Merge Operations](https://grid47.xyz/posts/leetcode_2789) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
