
+++
authors = ["grid47"]
title = "Leetcode 1054: Distant Barcodes"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1054: Distant Barcodes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MlgCCJ7MfKQ"
youtube_upload_date="2024-09-03"
youtube_thumbnail="https://i.ytimg.com/vi/MlgCCJ7MfKQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
        unordered_map<int, int> mp;
        set<pair<int, int>> st;
        for(int num: b) mp[num]++;
        for(auto it: mp) st.insert({ it.second, it.first });
        for(auto it = st.rbegin(); it != st.rend(); it++) {
            for(auto cnt = 0; cnt < it->first; cnt++, pos += 2) {
                if(pos >= b.size()) pos  = 1;
                b[pos] = it->second;
            }
        }
        return b;
    }
};
{{< /highlight >}}
---


### Problem Statement
The objective is to rearrange an array of integers (barcodes) in such a way that no two adjacent elements are the same. If it is not possible to achieve such an arrangement, the function should return any valid arrangement.

### Approach
To solve this problem, the approach involves:
1. Counting the frequency of each barcode using a hash map.
2. Storing the barcodes in a priority queue or set based on their frequencies, allowing us to access the most frequent barcodes first.
3. Placing the barcodes in the result array in a manner that respects the adjacency constraint by starting from even indices and then filling in the odd indices if necessary.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   The function `rearrangeBarcodes` is declared to take a vector of integers `b` and an optional parameter `pos`, which defaults to 0. This `pos` variable will help in managing the position where the next barcode will be placed.

   ```cpp
   vector<int> rearrangeBarcodes(vector<int>& b, int pos = 0) {
   ```

2. **Frequency Count**:
   An unordered map `mp` is declared to count the frequency of each barcode in the input vector `b`. The `set` named `st` will store pairs of frequency and barcode values, allowing for easy retrieval of the most frequent barcodes.

   ```cpp
   unordered_map<int, int> mp;
   set<pair<int, int>> st;
   for(int num: b) mp[num]++;
   ```

3. **Store Frequencies**:
   After counting the frequencies, each barcode and its count are inserted into the set `st`, where the count is the first element of the pair. This ensures that barcodes are sorted in descending order based on their frequencies.

   ```cpp
   for(auto it: mp) st.insert({ it.second, it.first });
   ```

4. **Placing Barcodes**:
   Using a reverse iterator to traverse the set from the highest frequency to the lowest, the code places each barcode into the result vector `b` at the designated positions. Initially, barcodes are placed at even indices (0, 2, 4, ...) until they run out of space. If there are remaining barcodes, they start filling odd indices (1, 3, 5, ...).

   ```cpp
   for(auto it = st.rbegin(); it != st.rend(); it++) {
       for(auto cnt = 0; cnt < it->first; cnt++, pos += 2) {
           if(pos >= b.size()) pos  = 1;
           b[pos] = it->second;
       }
   }
   ```

5. **Returning the Result**:
   After all the barcodes have been placed, the modified array `b` is returned.

   ```cpp
   return b;
   }
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity is \(O(n \log k)\), where \(n\) is the size of the input array and \(k\) is the number of unique barcodes. This complexity arises from inserting elements into the set (which keeps elements sorted) and iterating through them.
  
- **Space Complexity**: The space complexity is \(O(k)\), where \(k\) is the number of unique barcodes. This accounts for the space used to store the frequency count in the map and the sorted pairs in the set.

### Conclusion
The `rearrangeBarcodes` function efficiently rearranges the barcodes such that no two adjacent barcodes are the same, utilizing a frequency count and a sorted data structure to ensure optimal placement of the most frequent elements. 

This algorithm is particularly useful in scenarios involving data arrangement, scheduling, or any application where spacing out similar items is crucial to meet certain constraints. The solution leverages the properties of hash maps and sets to achieve a balance between simplicity and efficiency, making it a robust choice for this problem.

By ensuring that the most frequent elements are placed first in a strategic manner, the function maximizes the chances of achieving the required arrangement while minimizing the potential for adjacent duplicates.

Overall, this implementation highlights the importance of understanding data structures and their applications in solving algorithmic challenges effectively, reinforcing the skill of optimizing arrangements based on frequency.


[`Link to LeetCode Lab`](https://leetcode.com/problems/distant-barcodes/description/)

---
{{< youtube MlgCCJ7MfKQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
