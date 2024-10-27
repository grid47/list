
+++
authors = ["Yasir"]
title = "Leetcode 729: My Calendar I"
date = "2022-10-30"
description = "Solution to Leetcode 729"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/my-calendar-i/description/)

---

**Code:**

{{< highlight html >}}
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

