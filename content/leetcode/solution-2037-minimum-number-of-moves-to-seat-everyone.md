
+++
authors = ["grid47"]
title = "Leetcode 2037: Minimum Number of Moves to Seat Everyone"
date = "2024-04-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2037: Minimum Number of Moves to Seat Everyone in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Counting Sort"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "wS7Ag33hf8E"
youtube_upload_date="2024-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/wS7Ag33hf8E/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int res = 0;
        for (int i = 0; i < seats.size(); i++) res += abs(seats[i] - students[i]);
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2037.md" >}}
---
{{< youtube wS7Ag33hf8E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2038: Remove Colored Pieces if Both Neighbors are the Same Color](https://grid47.xyz/leetcode/solution-2038-remove-colored-pieces-if-both-neighbors-are-the-same-color/) |
| --- |
