
+++
authors = ["grid47"]
title = "Leetcode 2164: Sort Even and Odd Indices Independently"
date = "2024-04-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2164: Sort Even and Odd Indices Independently in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "h7GOQPBZNv4"
youtube_upload_date="2022-02-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/h7GOQPBZNv4/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int minIndex;
// Here in this nested loop , we are sorting the elements at even indices in non-decreasing order.
        for(int i=0;i<nums.size();i+=2)
        {
            minIndex=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]<nums[minIndex])
                    minIndex=j;
            }
            swap(nums[i],nums[minIndex]);
        }
// Here , we are trying to sort the elements at odd indices in non-increasing order. 
        for(int i=1;i<nums.size();i+=2)
        {
            minIndex=i;
            for(int j=i+2;j<nums.size();j+=2)
            {
                if(nums[j]>nums[minIndex])
                    minIndex=j;
            }
            swap(nums[i],nums[minIndex]);
        }
        
        return nums;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2164.md" >}}
---
{{< youtube h7GOQPBZNv4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2165: Smallest Value of the Rearranged Number](https://grid47.xyz/leetcode/solution-2165-smallest-value-of-the-rearranged-number/) |
| --- |