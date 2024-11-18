
+++
authors = ["grid47"]
title = "Leetcode 2799: Count Complete Subarrays in an Array"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2799: Count Complete Subarrays in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1wXkWZtSD28"
youtube_upload_date="2023-07-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1wXkWZtSD28/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int cnt = 0;
        set<int> dist;
        map<int, int> mp;
        for(int x: nums)
            dist.insert(x);
        int cur = 0, req = dist.size();
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp.size() < req) continue;
            while(mp.size() >= req) {
                cnt+= (n - i);
                mp[nums[j]]--;
                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);
                j++;
            }
        }
        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2799.md" >}}
---
{{< youtube 1wXkWZtSD28 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2800: Shortest String That Contains Three Strings](https://grid47.xyz/leetcode/solution-2800-shortest-string-that-contains-three-strings/) |
| --- |
