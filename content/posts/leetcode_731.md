
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 731: My Calendar II"
date = "2022-10-31"
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
{{< youtube nan >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

