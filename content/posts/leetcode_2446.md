
+++
authors = ["Yasir"]
title = "Leetcode 2446: Determine if Two Events Have Conflict"
date = "2018-02-16"
description = "Solution to Leetcode 2446"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-two-events-have-conflict/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
        return false;
    }
};
{{< /highlight >}}

