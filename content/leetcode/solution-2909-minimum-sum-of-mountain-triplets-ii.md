
+++
authors = ["grid47"]
title = "Leetcode 2909: Minimum Sum of Mountain Triplets II"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2909: Minimum Sum of Mountain Triplets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PU5YZP1-uVA"
youtube_upload_date="2023-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/PU5YZP1-uVA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> smallestRight(nums.size(), nums.back());
        for(int i = nums.size()-2; i >= 0; i--){
            smallestRight[i] = min(smallestRight[i+1], nums[i]);
        }
        int smallestLeft = nums[0], ans = -1;
        for(int i = 1; i < nums.size(); i++){
            if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
                if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
                else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
            }
            smallestLeft = min(smallestLeft, nums[i]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2909.md" >}}
---
{{< youtube PU5YZP1-uVA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2910: Minimum Number of Groups to Create a Valid Assignment](https://grid47.xyz/leetcode/solution-2910-minimum-number-of-groups-to-create-a-valid-assignment/) |
| --- |
