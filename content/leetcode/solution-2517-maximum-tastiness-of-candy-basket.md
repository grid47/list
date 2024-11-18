
+++
authors = ["grid47"]
title = "Leetcode 2517: Maximum Tastiness of Candy Basket"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2517: Maximum Tastiness of Candy Basket in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "mEZRRvBqSB0"
youtube_upload_date="2022-12-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/mEZRRvBqSB0/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool can(vector<int> nums, int mid, int k) {
        int cnt = 1, n = nums.size();
        int i = 1;
        int prv = nums[0];
        while(i < n) {
            if(nums[i] - prv >= mid) {
                cnt++;
                prv = nums[i];
            }
            if(cnt >= k) return true;
            i++;
        }
        return false;
    }
    
    int maximumTastiness(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int l = 0, r = nums[n - 1] - nums[0];
        int ans = r;
        
        while(l <= r) {
            
            int mid = l + (r - l + 1) / 2;
            // cout << mid << " " << can(nums, mid, k) << "\n";
            if(can(nums, mid, k)) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
            
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2517.md" >}}
---
{{< youtube mEZRRvBqSB0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2520: Count the Digits That Divide a Number](https://grid47.xyz/leetcode/solution-2520-count-the-digits-that-divide-a-number/) |
| --- |
