
+++
authors = ["grid47"]
title = "Leetcode 1552: Magnetic Force Between Two Balls"
date = "2024-06-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1552: Magnetic Force Between Two Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uixgQ1tejRs"
youtube_upload_date="2020-08-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uixgQ1tejRs/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int l = 0;
        int r = pos[n - 1]-pos[0];
        while(l < r) {
            int mid = r - (r - l) / 2;
            if(isValid(pos, mid, m)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    bool isValid(vector<int> &nums, int mid, int cnt) {
        int res = 1, cur = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] - cur >= mid) {
                res++;
                cur = nums[i];
            }
        }
        return res >= cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1552.md" >}}
---
{{< youtube uixgQ1tejRs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1557: Minimum Number of Vertices to Reach All Nodes](https://grid47.xyz/leetcode/solution-1557-minimum-number-of-vertices-to-reach-all-nodes/) |
| --- |