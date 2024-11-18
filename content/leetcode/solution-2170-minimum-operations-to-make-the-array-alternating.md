
+++
authors = ["grid47"]
title = "Leetcode 2170: Minimum Operations to Make the Array Alternating"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2170: Minimum Operations to Make the Array Alternating in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "LkSQby_5YMg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    array<int, 3> top2Freq(vector<int>& nums, int start) {
        int first = 0, second = 0, cnt[100001] = {};
        for(int i = start; i < nums.size(); i += 2) {
            if(++cnt[nums[i]] >= cnt[first]) {
                if(nums[i] != first)
                    second = first;
                first = nums[i];
            } else if(cnt[nums[i]] > cnt[second]) second = nums[i];
        }
        return {first, cnt[first], cnt[second] };
    }

    int minimumOperations(vector<int>& nums) {
        auto ev = top2Freq(nums, 0), od = top2Freq(nums, 1);
        return nums.size() - (ev[0] != od[0]? ev[1] + od[1] : max(ev[1]+ od[2], ev[2] + od[1]));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2170.md" >}}
---
{{< youtube LkSQby_5YMg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2171: Removing Minimum Number of Magic Beans](https://grid47.xyz/leetcode/solution-2171-removing-minimum-number-of-magic-beans/) |
| --- |
