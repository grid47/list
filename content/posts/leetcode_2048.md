
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2048: Next Greater Numerically Balanced Number"
date = "2019-03-22"
description = "Solution to Leetcode 2048"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
    int nextBeautifulNumber(int n) {
        int res = 1224444;
        
        string s = to_string(n);
        for(auto it: base) {
            string ss = to_string(it);
            if(ss.size() < s.size()) continue;
            if(ss.size() > s.size()) res = min(res, it);
            else {
                do {
                    if(ss > s) {
                        res = min(res, stoi(ss));
                    }
                } while(next_permutation(ss.begin(), ss.end()));
            }
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

