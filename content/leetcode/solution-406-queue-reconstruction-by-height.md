
+++
authors = ["grid47"]
title = "Leetcode 406: Queue Reconstruction by Height"
date = "2024-09-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 406: Queue Reconstruction by Height in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Indexed Tree","Segment Tree","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/406.webp"
youtube = "6plztg2nnjY"
youtube_upload_date="2020-06-06"
youtube_thumbnail="https://i.ytimg.com/vi/6plztg2nnjY/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/406.webp" 
    alt="A series of people with heights, arranging themselves in a queue with each step glowing as they are positioned."
    caption="Solution to LeetCode 406: Queue Reconstruction by Height Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort( people.begin(), people.end(), [] (vector<int> a, vector<int> b) {
            
            return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
            
        });
        
        vector<vector<int>> ans;
        for(auto p: people) 
            ans.insert(ans.begin() + p[1], p);
        
        return ans;
        
    }
};
{{< /highlight >}}
---

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort( people.begin(), people.end(), [] (vector<int> a, vector<int> b) {
            
            return a[0] > b[0] || ((a[0] == b[0]) && a[1] < b[1]);
            
        });
        
        vector<vector<int>> ans;
        for(auto p: people) 
            ans.insert(ans.begin() + p[1], p);
        
        return ans;
        
    }
};



### Problem Statement
### Approach
### Code Breakdown (Step by Step)
### Complexity
### Conclusion

generate a 350 line SEO friendly explanation of this code.


[`Link to LeetCode Lab`](https://leetcode.com/problems/queue-reconstruction-by-height/description/)

---
{{< youtube 6plztg2nnjY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
