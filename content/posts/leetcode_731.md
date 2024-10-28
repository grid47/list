
+++
authors = ["Yasir"]
title = "Leetcode 731: My Calendar II"
date = "2022-10-29"
description = "Solution to Leetcode 731"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/my-calendar-ii/description/)

---

**Code:**

{{< highlight html >}}
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


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

