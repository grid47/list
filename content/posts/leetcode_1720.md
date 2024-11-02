
+++
authors = ["Crafted by Me"]
title = "Leetcode 1720: Decode XORed Array"
date = "2019-02-16"
description = "Solution to Leetcode 1720"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-xored-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
vector<int> decode(vector<int>& encoded, int first) {
        vector<int> res;
        res.push_back(first);
        for(int i = 0; i < encoded.size(); i++)
            res.push_back(res[i] ^ encoded[i]);
        return res;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

