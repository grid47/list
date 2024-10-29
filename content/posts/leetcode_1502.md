
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1502: Can Make Arithmetic Progression From Sequence"
date = "2020-09-19"
description = "Solution to Leetcode 1502"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) return true;
        int min = INT_MAX, max = INT_MIN;
        for (int num : arr) {
            min = std::min(min, num);
            max = std::max(max, num);
        }
        if ((max - min) % (arr.size() - 1) != 0) return false;
        int d = (max - min) / (arr.size() - 1);

        int i = 0;
        while (i < arr.size()) {
            if (arr[i] == min + i * d) i++;
            else if ((arr[i] - min) % d != 0) return false;
            else {
                int pos = (arr[i] - min) / d;
                if (pos < i || arr[pos] == arr[i]) return false;
                std::swap(arr[i], arr[pos]);
            }
        }
        return true;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

