
+++
authors = ["grid47"]
title = "Leetcode 822: Card Flipping Game"
date = "2024-08-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 822: Card Flipping Game in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/822.webp"
youtube = "K-g8sOWW4F0"
youtube_upload_date="2024-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/K-g8sOWW4F0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/card-flipping-game/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/822.webp" 
    alt="A set of cards being flipped, with the correct card glowing softly as it's flipped over."
    caption="Solution to LeetCode 822: Card Flipping Game Problem"
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
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> same;
        for(int i = 0; i < fronts.size(); i++) if(fronts[i] == backs[i]) same.insert(fronts[i]);
        int res = 3000;
        for(auto &num: fronts) if(!same.count(num)) res = min(res, num);
        for(auto &num: backs)  if(!same.count(num)) res = min(res, num);        
        return res % 3000;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/822.md" >}}
---
{{< youtube K-g8sOWW4F0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #823: Binary Trees With Factors](https://grid47.xyz/leetcode/solution-823-binary-trees-with-factors/) |
| --- |