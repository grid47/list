
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 66: Plus One"
date = "2024-08-26"
description = "Solution to Leetcode 66"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/plus-one/description/)

---
{{< youtube tDjI08W1I7g >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int sum = 1;
        list<int> lst;
        for(int i = d.size() - 1; i >= 0; i--) {
            sum += d[i];
            lst.push_front(sum % 10);
            sum = sum /10;
        }
        if(sum > 0) lst.push_front(sum);
        vector<int> res(lst.begin(), lst.end());
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/66.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

