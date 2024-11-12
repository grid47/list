
+++
authors = ["grid47"]
title = "Leetcode 1742: Maximum Number of Balls in a Box"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1742: Maximum Number of Balls in a Box in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-balls-in-a-box/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        
        vector<int> box (46,0);
        for(int i = lowLimit;i<=highLimit;i++)
        {
            int sum = 0;
            int temp = i;
            while(temp)
            {
                sum = sum + temp%10;
                temp = temp/10;
            }
            box[sum]++;
        }
        
        return *max_element(box.begin(),box.end());
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1742.md" >}}
---
{{< youtube bRjEkQZ1R7Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1743: Restore the Array From Adjacent Pairs](https://grid47.xyz/posts/leetcode-1743-restore-the-array-from-adjacent-pairs-solution/) |
| --- |
