
+++
authors = ["grid47"]
title = "Leetcode 1968: Array With Elements Not Equal to Average of Neighbors"
date = "2024-04-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1968: Array With Elements Not Equal to Average of Neighbors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Wmb3YdVYfqM"
youtube_upload_date="2021-08-15"
youtube_thumbnail="https://i.ytimg.com/vi/Wmb3YdVYfqM/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        
        #define A(i) nums[(1 + 2 * i) % (n|1)]
        
        int i = 0, j = 0, k = n - 1;
        
        while(j <= k) {
            if(A(j) < mid)
                swap(A(j), A(k--));
            else if(A(j) > mid)
                swap(A(i++), A(j++));
            else j++;
        }
        return nums;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1968.md" >}}
---
{{< youtube Wmb3YdVYfqM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1969: Minimum Non-Zero Product of the Array Elements](https://grid47.xyz/leetcode/solution-1969-minimum-non-zero-product-of-the-array-elements/) |
| --- |
