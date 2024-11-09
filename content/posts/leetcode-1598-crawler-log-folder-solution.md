
+++
authors = ["grid47"]
title = "Leetcode 1598: Crawler Log Folder"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1598: Crawler Log Folder in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Stack"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/crawler-log-folder/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static int minOperations(vector<string>& logs) {
        int level=0;
        for(auto& dir: logs){
            if (dir=="../") 
                level-=(level>0);
            else if (dir!="./")
                level++;
        //    cout<<level<<endl;
        }
        return level;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1598.md" >}}
---
{{< youtube Ur3saIXP7ro >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1599: Maximum Profit of Operating a Centennial Wheel](https://grid47.xyz/posts/leetcode-1598-crawler-log-folder-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
