
+++
authors = ["grid47"]
title = "Leetcode 384: Shuffle an Array"
date = "2024-09-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 384: Shuffle an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shuffle-an-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/384.webp" 
    alt="A glowing array where elements shuffle into new positions, gently highlighting the change."
    caption="Solution to LeetCode 384: Shuffle an Array Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    vector<int> arr;
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }
    
    vector<int> reset() {
        return arr;
    }
    
    vector<int> shuffle() {
        vector<int> stk(arr);
        int n = stk.size();
        for(int i = 0; i < n; i++) {
            int j = rand() % (n - i);
            swap(stk[i + j], stk[i]);
        }
        return stk;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/384.md" >}}
---
{{< youtube LSNxktnyoh8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #385: Mini Parser](https://grid47.xyz/leetcode/solution-385-mini-parser/) |
| --- |
