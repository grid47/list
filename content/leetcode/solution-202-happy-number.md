
+++
authors = ["grid47"]
title = "Leetcode 202: Happy Number"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 202: Happy Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","Math","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/202.webp"
youtube = "4IroNy8fmNA"
youtube_upload_date="2022-06-25"
youtube_thumbnail="https://i.ytimg.com/vi/4IroNy8fmNA/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/happy-number/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/202.webp" 
    alt="A glowing number slowly transforming into a smiley face, symbolizing happiness and positivity."
    caption="Solution to LeetCode 202: Happy Number Problem"
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
    int sqr(int n) {
        int res = 0;
        while(n) {
            int tmp = n % 10;
            res += tmp * tmp;
            n = n / 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = sqr(slow);
            fast = sqr(sqr(fast));
        } while(slow != fast);
        return slow == 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/202.md" >}}
---
{{< youtube 4IroNy8fmNA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #205: Isomorphic Strings](https://grid47.xyz/leetcode/solution-205-isomorphic-strings/) |
| --- |