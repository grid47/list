
+++
authors = ["grid47"]
title = "Leetcode 525: Contiguous Array"
date = "2024-09-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 525: Contiguous Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/525.webp"
youtube = "3dRoRxipjhY"
youtube_upload_date="2020-04-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/3dRoRxipjhY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/contiguous-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/525.webp" 
    alt="A sequence where the contiguous subarrays that sum to zero are softly highlighted, glowing as they are identified."
    caption="Solution to LeetCode 525: Contiguous Array Problem"
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
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        int score = 0, res = 0;
        map<int, int> mp;

        for(int i = 0; i < n; i++) {
            score += nums[i]? 1: -1;

            if(score == 0) res = i + 1;
            else {

                if(mp.count(score))
                res = max(res, i - mp[score]);

                if(!mp.count(score)) mp[score] = i;
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/525.md" >}}
---
{{< youtube 3dRoRxipjhY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #528: Random Pick with Weight](https://grid47.xyz/leetcode/solution-528-random-pick-with-weight/) |
| --- |
