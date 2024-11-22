
+++
authors = ["grid47"]
title = "Leetcode 1899: Merge Triplets to Form Target Triplet"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1899: Merge Triplets to Form Target Triplet in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kShkQLQZ9K4"
youtube_upload_date="2021-06-13"
youtube_thumbnail="https://i.ytimg.com/vi/kShkQLQZ9K4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool mergeTriplets(vector<vector<int>>& tri, vector<int>& tgt) {
        vector<int> res(3, 0);
        int n = tri.size();

        for(auto s: tri) {
            if(s[0] <= tgt[0] && s[1] <= tgt[1] && s[2] <= tgt[2]) {
                res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
            }
        }
        
        return tgt == res;        
    }
    
    
};
{{< /highlight >}}
---

### Problem Statement

The task is to determine whether a target triplet can be formed by merging the maximum values from a given list of triplets. Each triplet contains three integers, and the goal is to check if we can form a triplet that matches the target by selecting values from the input triplets, provided that each selected triplet does not exceed the corresponding value in the target triplet.

### Approach

To solve this problem, we follow a straightforward approach:

1. **Initialization**: We start by initializing a result vector `res` with three zeroes. This vector will hold the maximum values that can be formed from the input triplets.

2. **Iterate Through Triplets**: For each triplet in the input list, we check if the triplet's values do not exceed the values in the target triplet.

3. **Updating Maximum Values**: If a triplet is valid (i.e., all its values are less than or equal to the corresponding values in the target triplet), we update the `res` vector with the maximum values from the valid triplet.

4. **Final Comparison**: After processing all triplets, we compare the `res` vector with the target triplet. If they match, it means the target can be formed from the input triplets; otherwise, it cannot.

### Code Breakdown (Step by Step)

Let’s break down the code into its key components to understand how it works:

1. **Class Definition**: We begin by defining a class called `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **mergeTriplets Function**: This function is the core of the solution. It takes a vector of triplets (`tri`) and a target triplet (`tgt`) as input.

   ```cpp
       bool mergeTriplets(vector<vector<int>>& tri, vector<int>& tgt) {
   ```

3. **Result Vector Initialization**: We initialize a result vector `res` to store the maximum values for each position of the triplet.

   ```cpp
           vector<int> res(3, 0);
           int n = tri.size();
   ```

4. **Iterate Through Each Triplet**: We loop through each triplet in the `tri` vector.

   ```cpp
           for(auto s: tri) {
   ```

   - **Check Validity**: For each triplet `s`, we check if all its elements are less than or equal to the corresponding elements in the target triplet.

   ```cpp
               if(s[0] <= tgt[0] && s[1] <= tgt[1] && s[2] <= tgt[2]) {
   ```

5. **Updating Maximum Values**: If the triplet is valid, we update the `res` vector with the maximum values:

   ```cpp
                   res = { max(res[0], s[0]), max(res[1], s[1]), max(res[2], s[2]) };
               }
           }
   ```

6. **Final Check**: After processing all triplets, we check if the target triplet matches the result vector.

   ```cpp
           return tgt == res;        
       }
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n) \), where \( n \) is the number of triplets in the `tri` vector. We loop through each triplet once, performing constant-time checks and updates.

- **Space Complexity**: The space complexity is \( O(1) \) because we use a constant amount of space for the `res` vector, regardless of the input size.

### Conclusion

The `mergeTriplets` function efficiently determines whether a given target triplet can be formed by merging the maximum values from a list of input triplets. By utilizing a simple iteration and conditional checks, the solution is both straightforward and effective.

This approach is useful in various contexts where merging or combining elements under specific constraints is required. It highlights the importance of understanding how to manipulate arrays and vectors to achieve desired outcomes based on given conditions.

### Use Cases

This problem can be applied in various domains, such as:

- **Game Development**: In games where players can merge resources or items to achieve specific goals, this logic can help determine the feasibility of achieving a target configuration.

- **Data Aggregation**: In data processing, merging values while adhering to certain constraints is a common task. This algorithm can be a building block for more complex data aggregation tasks.

- **Optimization Problems**: Many optimization problems involve selecting values under constraints. This approach can serve as a foundation for developing more complex algorithms in optimization scenarios.

By effectively using this method, developers can ensure their applications are both robust and efficient in handling various data manipulation tasks.

[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/)

---
{{< youtube kShkQLQZ9K4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
