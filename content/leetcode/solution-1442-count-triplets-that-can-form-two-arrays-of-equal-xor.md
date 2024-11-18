
+++
authors = ["grid47"]
title = "Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1442: Count Triplets That Can Form Two Arrays of Equal XOR in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Bit Manipulation","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "e4Yx9KjqzQ8"
youtube_upload_date="2024-05-30"
youtube_thumbnail="https://i.ytimg.com/vi/e4Yx9KjqzQ8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTriplets(vector<int>& nums) {

        int res = 0, n = nums.size();
        vector<int> arr(n+1,0);
        for(int i = 1; i < n + 1; i++)
            arr[i] = arr[i -1] ^ nums[i-1];
        for(int i = 0; i < n+1; i++) {
            for(int j = i + 1; j < n+1; j++)
                if(arr[i] == arr[j])
                res += j - i- 1;
            }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1442.md" >}}
---
{{< youtube e4Yx9KjqzQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1443: Minimum Time to Collect All Apples in a Tree](https://grid47.xyz/leetcode/solution-1443-minimum-time-to-collect-all-apples-in-a-tree/) |
| --- |
