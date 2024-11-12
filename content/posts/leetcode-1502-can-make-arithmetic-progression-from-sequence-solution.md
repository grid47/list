
+++
authors = ["grid47"]
title = "Leetcode 1502: Can Make Arithmetic Progression From Sequence"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1502: Can Make Arithmetic Progression From Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1502.md" >}}
---
{{< youtube crVb-Fubs0w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1503: Last Moment Before All Ants Fall Out of a Plank](https://grid47.xyz/posts/leetcode-1503-last-moment-before-all-ants-fall-out-of-a-plank-solution/) |
| --- |
