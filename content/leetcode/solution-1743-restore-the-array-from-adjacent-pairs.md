
+++
authors = ["grid47"]
title = "Leetcode 1743: Restore the Array From Adjacent Pairs"
date = "2024-05-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1743: Restore the Array From Adjacent Pairs in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Depth-First Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "SGfdp6CFDrA"
youtube_upload_date="2021-01-31"
youtube_thumbnail="https://i.ytimg.com/vi/SGfdp6CFDrA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& ap) {
        int n = ap.size() + 1;
        map<int, vector<int>> mp;
        for(auto e : ap) {
            int u = e[0], v = e[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        vector<int> ans;
        for(auto it: mp) {
            if(it.second.size() == 1) {
                ans.push_back(it.first);
                ans.push_back(it.second[0]);
                break;
            }
        }

        while(ans.size() < n) {
            auto tail = ans.back(), prv = ans[ans.size() - 2];
            auto &next = mp[tail];
            if(next[0] != prv)
                ans.push_back(next[0]);
            else
                ans.push_back(next[1]);
        }

        return ans;
    }

};
{{< /highlight >}}
---

### Problem Statement

Given an array of adjacent pairs, where each element represents a connection between two integers, the task is to restore the original array from which the adjacent pairs were derived. Each pair in the input represents two neighboring elements in the original array, and the array has no duplicates. The goal is to reconstruct and return the original array in the correct order.

### Approach

The problem can be approached using a hash map and by identifying the endpoints of the array based on the adjacency properties of the elements. Here’s the plan:

1. **Map Construction**: Build a hash map to store each integer’s adjacent elements based on the given pairs.
  
2. **Endpoint Identification**: Find the array’s starting point by identifying an integer that appears only once in the adjacency map (endpoints only have one neighbor).
  
3. **Array Restoration**: Starting from one endpoint, construct the array by traversing through neighbors in sequence, ensuring each element appears in the correct order.

### Code Breakdown (Step by Step)

Let’s dive into the code line by line to understand the solution.

1. **Initialize Variables and Build the Adjacency Map**:
   - Use `map<int, vector<int>> mp` to store each integer and its neighbors. 
   - For each pair in `ap`, add each element to the other’s adjacency list.
   
   ```cpp
   int n = ap.size() + 1;
   map<int, vector<int>> mp;
   for(auto e : ap) {
       int u = e[0], v = e[1];
       mp[u].push_back(v);
       mp[v].push_back(u);
   }
   ```

   Here, `n` is the expected length of the restored array, and `mp` is used to record neighboring relationships from the input pairs.

2. **Find the Starting Endpoint**:
   - Identify an element with only one neighbor (an endpoint of the array).
   - Add this element and its single neighbor to `ans`, marking the start of the array.

   ```cpp
   vector<int> ans;
   for(auto it: mp) {
       if(it.second.size() == 1) {
           ans.push_back(it.first);
           ans.push_back(it.second[0]);
           break;
       }
   }
   ```

   In this loop, the `it.first` with only one neighbor `it.second[0]` is the starting point for the traversal.

3. **Traverse and Reconstruct the Array**:
   - Use a `while` loop to continue expanding the array until it reaches length `n`.
   - At each step, find the next element connected to the current last element that has not been visited (tracked by the previous element).

   ```cpp
   while(ans.size() < n) {
       auto tail = ans.back(), prv = ans[ans.size() - 2];
       auto &next = mp[tail];
       if(next[0] != prv)
           ans.push_back(next[0]);
       else
           ans.push_back(next[1]);
   }
   ```

   The loop continues appending elements until the array is fully constructed. It ensures each next element is a new connection not yet added to `ans`.

4. **Return the Result**:
   - After the loop, `ans` contains the original array in the correct order, which is then returned.

   ```cpp
   return ans;
   ```

### Complexity

- **Time Complexity**: \(O(n)\), where \(n\) is the number of pairs in `ap`. Building the map and traversing the array both take linear time.
  
- **Space Complexity**: \(O(n)\) due to the adjacency map and the result vector `ans`.

### Conclusion

This solution efficiently reconstructs the array from the given adjacent pairs by leveraging adjacency information and endpoint detection. Using a map to store neighbors allows efficient access to connections, and by identifying an endpoint, the array can be restored in linear order. This approach ensures accuracy and optimal performance, making it suitable for large input sizes within given constraints.

[`Link to LeetCode Lab`](https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/description/)

---
{{< youtube SGfdp6CFDrA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
