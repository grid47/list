
+++
authors = ["grid47"]
title = "Leetcode 398: Random Pick Index"
date = "2024-09-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 398: Random Pick Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Reservoir Sampling","Randomized"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/398.webp"
youtube = "1rDRyxPcmvY"
youtube_upload_date="2020-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1rDRyxPcmvY/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/random-pick-index/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/398.webp" 
    alt="A series of indices being selected randomly, with each chosen index softly glowing."
    caption="Solution to LeetCode 398: Random Pick Index Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
    unordered_map<int, vector<int>> mp;
public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        mp[nums[i]].push_back(i);
    }
    
    int pick(int target) { 
        int sz = mp[target].size();
        int res = mp[target][rand()%sz];
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/398.md" >}}
---
{{< youtube 1rDRyxPcmvY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #399: Evaluate Division](https://grid47.xyz/leetcode/solution-399-evaluate-division/) |
| --- |