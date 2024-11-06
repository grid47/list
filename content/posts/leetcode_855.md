
+++
authors = ["Crafted by Me"]
title = "Leetcode 855: Exam Room"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 855: Exam Room in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Design","Heap (Priority Queue)","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/exam-room/description/)

---

**Code:**

{{< highlight cpp >}}
class ExamRoom {
    int N;
    vector<int> L;
public:
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if(L.size() == 0) {
            L.push_back(0);
            return 0;
        }
 
        
        int d = max(L[0], N - 1 - L[L.size() - 1]);
        for(int i = 0; i < L.size() - 1; i++) d = max(d, (L[i + 1] - L[i]) /2);
        
        if(L[0] == d) {
            
            L.insert(L.begin(), 0);
            
            return L[0];
        }
        
        for(int i = 0; i < L.size() - 1; i++) {
            if((L[i + 1] - L[i])/2 == d) {
                L.insert(L.begin() + i + 1, (L[i] + L[i +1])/2);
                return L[i + 1];
            }
         }
        
            L.push_back(N - 1);
            return N - 1;
        
    }
    
    void leave(int p) {
        for(int i = 0; i < L.size(); i++) if(L[i] == p) L.erase(L.begin() + i);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/855.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #856: Score of Parentheses](https://grid47.xyz/posts/leetcode_856) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
