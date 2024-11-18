
+++
authors = ["grid47"]
title = "Leetcode 2155: All Divisions With the Highest Score of a Binary Array"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2155: All Divisions With the Highest Score of a Binary Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jAn_1AC2VMo"
youtube_upload_date="2022-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jAn_1AC2VMo/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; i++)
        if (nums[i] == 1) ones++;
        
        int mx = ones;
        vector<int> mxx;
        mxx.push_back(0);

        int zeros = 0;
        
        int prv, cur = mx;
        for(int i = 1; i < n + 1; i++) {
            zeros += ((nums[i - 1] == 0)? 1 : 0);
            ones  -= ((nums[i - 1] == 1)? 1 : 0);

            prv = mx;
            cur = zeros + ones;
            mx  = max(mx, cur);

                 if (mx == cur && cur == prv) mxx.push_back(i);
            else if (mx >  prv) {
                mxx.clear();
                mxx.push_back(i);
            }
        }
        
        return mxx;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2155.md" >}}
---
{{< youtube jAn_1AC2VMo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2160: Minimum Sum of Four Digit Number After Splitting Digits](https://grid47.xyz/leetcode/solution-2160-minimum-sum-of-four-digit-number-after-splitting-digits/) |
| --- |
