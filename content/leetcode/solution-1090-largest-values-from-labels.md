
+++
authors = ["grid47"]
title = "Leetcode 1090: Largest Values From Labels"
date = "2024-07-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1090: Largest Values From Labels in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "E0OkE3G95vU"
youtube_upload_date="2020-12-06"
youtube_thumbnail="https://i.ytimg.com/vi/E0OkE3G95vU/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        multimap<int, int> s;
        unordered_map<int, int> m;
        for(int i = 0; i < values.size(); i++) 
            s.insert({values[i], labels[i]});
        int res = 0;
        for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
            if(++m[it->second] <= useLimit) {
                res += it->first;
                --numWanted;                
            }
        }
        return res;
    }
};
{{< /highlight >}}
---



### Problem Statement
The task is to maximize the sum of selected values from a list while respecting two constraints: you can select a limited number of values (`numWanted`) and each value has a corresponding label that can be used a maximum of `useLimit` times. Given two arrays, one for values and one for corresponding labels, the objective is to calculate the largest possible sum of values that can be selected according to the specified conditions.

### Approach
To tackle this problem effectively, we will follow these steps:

1. **Store Values with Labels**: Use a data structure to pair each value with its label.
2. **Sort Values**: Sort these pairs in descending order based on the value to prioritize the highest values first.
3. **Select Values**: Iterate through the sorted list and select values while ensuring that the number of times each label is used does not exceed the `useLimit`. Keep track of how many labels have been used and accumulate the total sum.
4. **Return the Result**: Once the maximum sum is calculated, return it.

### Code Breakdown (Step by Step)

1. **Class Definition**: The class `Solution` contains the method `largestValsFromLabels`, which implements the logic to solve the problem.

   ```cpp
   class Solution {
   public:
       int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
   ```

2. **Initialize Data Structures**: We declare a multimap `s` to store pairs of values and labels, allowing us to sort by value while maintaining label associations. An unordered map `m` will keep track of how many times each label has been used.

   ```cpp
           multimap<int, int> s;
           unordered_map<int, int> m;
   ```

3. **Populate the Multimap**: We iterate through the `values` and `labels` arrays, inserting each pair into the multimap. This creates an ordered collection of values associated with their respective labels.

   ```cpp
           for(int i = 0; i < values.size(); i++) 
               s.insert({values[i], labels[i]});
   ```

4. **Initialize Result Variable**: A variable `res` is initialized to zero to accumulate the maximum sum of values selected.

   ```cpp
           int res = 0;
   ```

5. **Iterate Through the Multimap**: We use a reverse iterator to go through the multimap starting from the highest value. We continue until we have either exhausted the multimap or reached the limit on selected values.

   ```cpp
           for(auto it = rbegin(s); it != rend(s) && numWanted > 0; it++) {
   ```

6. **Count Usage of Labels**: For each value-label pair, we increment the count of how many times the label has been used. If the count does not exceed the `useLimit`, we add the value to the result and decrement the number of values we still need to select (`numWanted`).

   ```cpp
               if(++m[it->second] <= useLimit) {
                   res += it->first;
                   --numWanted;                
               }
           }
   ```

7. **Return the Result**: Finally, we return the accumulated sum of the selected values.

   ```cpp
           return res;
       }
   };
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of this algorithm is \(O(N \log N)\), where \(N\) is the number of values. This is primarily due to the insertion of elements into the multimap, which requires sorting. The iteration through the sorted elements is \(O(N)\).
  
- **Space Complexity**: The space complexity is \(O(N)\) as we store up to \(N\) pairs in the multimap and also maintain the unordered map for counting label usages.

### Conclusion
The provided C++ code effectively solves the problem of maximizing the sum of selected values under specific constraints using a clear and efficient approach. By leveraging a multimap to sort the values in descending order and tracking the usage of labels, the algorithm ensures that we can select the highest possible values while adhering to the limits set on each label.

This method is especially useful in scenarios where prioritization of elements based on value is critical, such as resource allocation, budget optimization, or inventory management. Its \(O(N \log N)\) time complexity makes it suitable for reasonably sized datasets, providing a balance between efficiency and clarity.

In summary, the `largestValsFromLabels` method demonstrates a robust strategy for solving a combinatorial selection problem, showcasing the effectiveness of data structures like maps and multisets in achieving optimal results in competitive programming and algorithmic challenges.


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-values-from-labels/description/)

---
{{< youtube E0OkE3G95vU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
