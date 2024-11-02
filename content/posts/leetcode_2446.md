
+++
authors = ["Crafted by Me"]
title = "Leetcode 2446: Determine if Two Events Have Conflict"
date = "2017-02-20"
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

{{< highlight cpp >}}
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
        return false;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

