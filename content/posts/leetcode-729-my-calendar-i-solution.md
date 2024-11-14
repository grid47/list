
+++
authors = ["grid47"]
title = "Leetcode 729: My Calendar I"
date = "2024-08-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 729: My Calendar I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Design","Segment Tree","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/my-calendar-i/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/729.webp" 
    alt="A calendar where events are added, with each event softly glowing as it is scheduled."
    caption="Solution to LeetCode 729: My Calendar I Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class MyCalendar {
    map<int, int> mp;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        auto nxt = mp.upper_bound(start);
        if (nxt != mp.end() && (*nxt).second < end) {
            return false;
        }
        mp[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/729.md" >}}
---
{{< youtube fIxck3tlId4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #731: My Calendar II](https://grid47.xyz/posts/leetcode-731-my-calendar-ii-solution/) |
| --- |
