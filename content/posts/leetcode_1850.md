
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1850: Minimum Adjacent Swaps to Reach the Kth Smallest Number"
date = "2019-10-06"
description = "Solution to Leetcode 1850"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string og = num;
        while(k--) {
            next_permutation(num.begin(), num.end());
        }
        return steps(og, num);
    }

    int steps(string s1, string s2) {
        int sz = s1.size();
        int i = 0, j = 0;
        int res = 0;

        while(i < sz) {
            j = i;
            while(s1[i] != s2[j]) j++;
            while(i < j) {
                swap(s2[j], s2[j - 1]);
                j--;
                res++;
            }
            i++;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

