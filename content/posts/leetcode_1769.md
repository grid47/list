
+++
authors = ["Crafted by Me"]
title = "Leetcode 1769: Minimum Number of Operations to Move All Balls to Each Box"
date = "2019-12-29"
description = "Solution to Leetcode 1769"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> res(boxes.length()); 
        for (int i = 0, ops = 0, cnt = 0; i < boxes.length(); ++i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        for (int i = boxes.length() - 1, ops = 0, cnt = 0; i >= 0; --i) {
            res[i] += ops;
            cnt += boxes[i] == '1' ? 1 : 0;
            ops += cnt;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

