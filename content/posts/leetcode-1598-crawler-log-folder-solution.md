
+++
authors = ["grid47"]
title = "Leetcode 1598: Crawler Log Folder"
date = "2024-05-31"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1599: Maximum Profit of Operating a Centennial Wheel](https://grid47.xyz/posts/leetcode-1599-maximum-profit-of-operating-a-centennial-wheel-solution/) |
| --- |
