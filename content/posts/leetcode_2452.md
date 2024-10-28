
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2452: Words Within Two Edits of Dictionary"
date = "2018-02-11"
description = "Solution to Leetcode 2452"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/words-within-two-edits-of-dictionary/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for(auto &q: queries)
        for(auto &d: dictionary)
        if(inner_product(begin(q), end(q), begin(d), 0, plus<int>(), not_equal_to<char>()) < 3) {
            res.push_back(q);
            break;
        }
        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

