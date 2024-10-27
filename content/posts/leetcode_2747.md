
+++
authors = ["Yasir"]
title = "Leetcode 2747: Count Zero Request Servers"
date = "2017-04-21"
description = "Solution to Leetcode 2747"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-zero-request-servers/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<pair<int,int>> qs;
        for(int i=0;i<queries.size();i++){      // sorting and also storing the index to create an anwer at the end
            qs.push_back({queries[i],i});   // at their appropiate place
        }
        sort(qs.begin(),qs.end());
        vector<int> result(queries.size());

        set<pair<int,int>> s;       // for storing {time,id}
        map<int,int> count;         // for storing the number of ids in the current window
        
        sort(logs.begin(),logs.end(),[&](auto const &a,auto const &b){  // sorting the logs based on their time
            return a[1]<b[1];
        });         

        int i = 0;
        for(auto &[q,index]:qs){
            while(i<logs.size() && logs[i][1]<=q){          // adding all the servers that have time <= q
                s.insert({logs[i][1],logs[i][0]});          
                count[logs[i][0]]++;
                i++;
            }
            while(!s.empty() && s.begin()->first<q-x){      // removing all the elements that are out of the current 
                count[s.begin()->second]--;                 // window i.e. < q-x
                if(count[s.begin()->second]==0) count.erase(s.begin()->second);
                s.erase(s.begin());
            }
            result[index] = n - count.size();
        }
        return result;
    }
};
{{< /highlight >}}

