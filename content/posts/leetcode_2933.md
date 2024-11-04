
+++
authors = ["Crafted by Me"]
title = "Leetcode 2933: High-Access Employees"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2933: High-Access Employees in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/high-access-employees/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int string_to_int(string s){
        int val=0;
        for(int i=0;i<s.length();i++) val = val*10 + (s[i]-'0');
        
        return val;
    }
    
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
		map<string, vector<int>> times;
        for(vector<string> v : access_times){
            string s=v[1];
            
            int minutes = string_to_int(s.substr(0,2))*60 + string_to_int(s.substr(2));
            times[v[0]].push_back(minutes);
        }
        
        vector<string> ans;
        for(auto it=times.begin();it!=times.end();it++){
            string ch = it->first;
            vector<int> time = it->second;
            
            vector<int> sweep(1441,0);
            for(int t : time){
				// contribution of each access for next 59 minutes
                sweep[t]++;
                if(t+60 < 1441) sweep[t+60]--;
            }
            
			// check for at least 3 overlapping access times
            int c=0;
            for(int i=0;i<1441;i++){
                c += sweep[i];
                
                if(c>=3){
                    ans.push_back(ch);
                    break;
                }
            }
        }
        
        return ans;
    }
};
{{< /highlight >}}


---
{{< youtube r4DlEjNCYE0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2934: Minimum Operations to Maximize Last Elements in Arrays](https://grid47.xyz/posts/leetcode_2934) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}

