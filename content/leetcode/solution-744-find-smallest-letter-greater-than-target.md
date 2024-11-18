
+++
authors = ["grid47"]
title = "Leetcode 744: Find Smallest Letter Greater Than Target"
date = "2024-08-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 744: Find Smallest Letter Greater Than Target in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/744.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



[`Problem Link`](https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/744.webp" 
    alt="A string where the smallest letter greater than the target is found and highlighted with a soft glow."
    caption="Solution to LeetCode 744: Find Smallest Letter Greater Than Target Problem"
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
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(int i = 0; i < letters.size(); i++) {
            if(letters[i] > target) {
                ans = letters[i];
                break;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/744.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #746: Min Cost Climbing Stairs](https://grid47.xyz/leetcode/solution-746-min-cost-climbing-stairs/) |
| --- |
