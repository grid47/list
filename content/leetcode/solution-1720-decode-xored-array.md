
+++
authors = ["grid47"]
title = "Leetcode 1720: Decode XORed Array"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1720: Decode XORed Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "sthGfBi890o"
img_src = ""
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1720.md" >}}
---
{{< youtube sthGfBi890o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1721: Swapping Nodes in a Linked List](https://grid47.xyz/leetcode/solution-1721-swapping-nodes-in-a-linked-list/) |
| --- |
