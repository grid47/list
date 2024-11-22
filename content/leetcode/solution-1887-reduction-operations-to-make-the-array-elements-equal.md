
+++
authors = ["grid47"]
title = "Leetcode 1887: Reduction Operations to Make the Array Elements Equal"
date = "2024-05-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1887: Reduction Operations to Make the Array Elements Equal in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "1etc9Ip8Xm8"
youtube_upload_date="2021-06-06"
youtube_thumbnail="https://i.ytimg.com/vi_webp/1etc9Ip8Xm8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        int ops = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = n - 2; i >= 0; i--) {
            
            if(nums[i] == nums[i + 1]) continue;
            ops += (n - 1 - i);
            
        }
        
        return ops;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the minimum number of operations required to reduce all elements of an array to the same value. An operation consists of selecting an element and reducing it by one. The goal is to find the total number of such operations needed.

### Approach

The approach to solving this problem involves the following steps:

1. **Sorting the Array**: Start by sorting the input array. This allows us to easily determine how many elements are greater than a certain value.
2. **Counting Operations**: Iterate through the sorted array, counting how many operations are required to reduce elements to the next unique value.
3. **Using a Running Total**: For each unique value encountered, calculate how many elements need to be reduced to reach that value from the previous unique value.

### Code Breakdown (Step by Step)

1. **Class Definition**: The `Solution` class encapsulates the method to solve the problem.

   ```cpp
   class Solution {
   public:
   ```

2. **Main Function**: The `reductionOperations` function is defined to take a vector of integers as input.

   ```cpp
       int reductionOperations(vector<int>& nums) {
   ```

3. **Variable Initialization**: Initialize variables to keep track of the total number of operations (`ops`) and the size of the array (`n`).

   ```cpp
           int ops = 0, n = nums.size();
   ```

4. **Sorting the Array**: The input array is sorted in ascending order. This enables easy access to the elements and facilitates counting the operations required.

   ```cpp
           sort(nums.begin(), nums.end());
   ```

5. **Counting Operations Loop**: Iterate through the sorted array from the second-to-last element down to the first. This allows checking each element against the next one to determine how many operations are needed.

   ```cpp
           for(int i = n - 2; i >= 0; i--) {
   ```

6. **Skip Duplicates**: If the current element is equal to the next one, continue to the next iteration. This is crucial because we only need to count operations when we encounter a unique value.

   ```cpp
               if(nums[i] == nums[i + 1]) continue;
   ```

7. **Calculate Operations**: For each unique element, add to the `ops` counter the number of elements that are greater than this element. This is done by subtracting the index `i` from `n - 1` to get the count of elements that need to be reduced.

   ```cpp
               ops += (n - 1 - i);
           }
   ```

8. **Return Result**: Finally, return the total number of operations needed to make all elements equal.

   ```cpp
           return ops;
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n \log n) \) due to the sorting step, where \( n \) is the number of elements in the input array. The subsequent loop runs in \( O(n) \), which is dominated by the sorting step.

- **Space Complexity**: The space complexity is \( O(1) \) if we ignore the input size since we are using a constant amount of additional space for variables, and the sorting is done in place.

### Conclusion

The provided solution efficiently calculates the minimum number of operations required to make all elements in the array equal. By leveraging sorting and careful counting, it ensures optimal performance and correctness.

This method is particularly effective in scenarios where minimizing operations is crucial, such as in resource allocation problems or optimization tasks in computational mathematics. The clear structure and logical flow of the code make it easy to understand and maintain, adhering to best practices in programming.

Overall, this solution highlights fundamental programming techniques such as sorting, iteration, and condition handling, offering a solid framework for tackling similar problems in the future. By applying these techniques, developers can solve a wide range of challenges involving numerical arrays and optimization requirements.

[`Link to LeetCode Lab`](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/description/)

---
{{< youtube 1etc9Ip8Xm8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
