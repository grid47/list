
+++
authors = ["Yasir"]
title = "Leetcode 1598: Crawler Log Folder"
date = "2020-06-13"
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

{{< highlight html >}}
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

