
+++
authors = ["Yasir"]
title = "Leetcode 855: Exam Room"
date = "2022-06-25"
description = "Solution to Leetcode 855"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/exam-room/description/)

---

**Code:**

{{< highlight html >}}
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

