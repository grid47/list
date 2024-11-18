
+++
authors = ["grid47"]
title = "Leetcode 2578: Split With Minimum Sum"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2578: Split With Minimum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rRksdLnCAqI"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rRksdLnCAqI/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/split-with-minimum-sum/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int splitNum(int num) {
        int num1 = 0, num2 = 0, x = 1;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num /= 10;
        }
        sort(v.begin(),v.end());
        num = 0;
        for(auto &i: v){
            num *= 10;
            num += i;
        }
        while(num){
            num1 += x*(num%10);
            num /= 10;
            num2 += x*(num%10);
            num /= 10;
            x *= 10;
        }
        return num1+num2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2578.md" >}}
---
{{< youtube rRksdLnCAqI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2579: Count Total Number of Colored Cells](https://grid47.xyz/leetcode/solution-2579-count-total-number-of-colored-cells/) |
| --- |
