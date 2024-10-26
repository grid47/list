
+++
authors = ["Yasir"]
title = "Leetcode 738: Monotone Increasing Digits"
date = "2022-10-20"
description = "Solution to Leetcode 738"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/monotone-increasing-digits/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string n_str = to_string(n);

        int marker = n_str.size();

        for(int i = n_str.size() - 1; i > 0; i--) {
            if(n_str[i] < n_str[i - 1]) {
                marker = i;
                n_str[i-1] = n_str[i - 1] - 1;
            }
        }

        for(int i = marker; i < n_str.size(); i++)
            n_str[i]= '9';

        return stoi(n_str);
    }
};
{{< /highlight >}}

