
+++
authors = ["grid47"]
title = "Leetcode 731: My Calendar II"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 731: My Calendar II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Design","Segment Tree","Prefix Sum","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/my-calendar-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/731.webp" 
    alt="A calendar with overlapping events, where conflicts are highlighted and softly glowing to indicate double-booking."
    caption="Solution to LeetCode 731: My Calendar II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class MyCalendarTwo {
    map<int, int> mp;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int bkd = 0;
    
        
        for(auto it =mp.begin(); it != mp.end(); it++) {
            
            bkd += it->second;
            
            if(bkd == 3) {
                
                mp[start]--;
                mp[end]++;
                
                return false;
            }
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/731.md" >}}
---
{{< youtube 7utL5cTDcnA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #733: Flood Fill](https://grid47.xyz/posts/leetcode-733-flood-fill-solution/) |
| --- |
