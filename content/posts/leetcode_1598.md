
+++
authors = ["Crafted by Me"]
title = "Leetcode 1598: Crawler Log Folder"
date = "2019-06-18"
description = "Solution to Leetcode 1598"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

