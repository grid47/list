
+++
authors = ["grid47"]
title = "Leetcode 45: Jump Game II"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 45: Jump Game II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "CsDI-yQuGeM"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/45.webp"
+++



[`Problem Link`](https://leetcode.com/problems/jump-game-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/45.webp" 
    alt="A glowing path with multiple jumping stones, forming an easy, calming journey."
    caption="Solution to LeetCode 45: Jump Game II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int cur = 0;
        int far = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            far = max(far, i + nums[i]);
            if(i == cur) {
                cur = far;
                jumps++;
            }
        }
        return jumps;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/45.md" >}}
---
{{< youtube CsDI-yQuGeM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #46: Permutations](https://grid47.xyz/leetcode/solution-46-permutations/) |
| --- |
