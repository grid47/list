
+++
authors = ["Yasir"]
title = "Leetcode 1720: Decode XORed Array"
date = "2020-02-13"
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

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

