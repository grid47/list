
+++
authors = ["grid47"]
title = "Leetcode 456: 132 Pattern"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 456: 132 Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Stack","Monotonic Stack","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/456.webp"
youtube = "TfgWauHLuRE"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/TfgWauHLuRE/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/132-pattern/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/456.webp" 
    alt="A sequence of numbers where the 132 pattern lights up, showing the correct order and placement of elements."
    caption="Solution to LeetCode 456: 132 Pattern Problem"
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
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        int prv = INT_MIN;
        stack<int> stk;
        
        for(int i = n - 1; i >= 0; i--) {

            if (nums[i] < prv) return true;

            while(!stk.empty() && nums[i] > stk.top()) {

                prv = stk.top();
                stk.pop();

            }

            stk.push(nums[i]);
        }

        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/456.md" >}}
---
{{< youtube TfgWauHLuRE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #457: Circular Array Loop](https://grid47.xyz/leetcode/solution-457-circular-array-loop/) |
| --- |