
+++
authors = ["grid47"]
title = "Leetcode 66: Plus One"
date = "2024-10-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 66: Plus One in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/66.webp"
youtube = "tDjI08W1I7g"
youtube_upload_date="2022-03-07"
youtube_thumbnail="https://i.ytimg.com/vi/tDjI08W1I7g/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/plus-one/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/66.webp" 
    alt="A glowing number gently increasing by one, signifying growth and positivity."
    caption="Solution to LeetCode 66: Plus One Problem"
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
    vector<int> plusOne(vector<int>& d) {
        int sum = 1;
        list<int> lst;
        for(int i = d.size() - 1; i >= 0; i--) {
            sum += d[i];
            lst.push_front(sum % 10);
            sum = sum /10;
        }
        if(sum > 0) lst.push_front(sum);
        vector<int> res(lst.begin(), lst.end());
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/66.md" >}}
---
{{< youtube tDjI08W1I7g >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #67: Add Binary](https://grid47.xyz/leetcode/solution-67-add-binary/) |
| --- |
