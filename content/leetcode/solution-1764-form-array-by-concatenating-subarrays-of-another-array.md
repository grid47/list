
+++
authors = ["grid47"]
title = "Leetcode 1764: Form Array by Concatenating Subarrays of Another Array"
date = "2024-05-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1764: Form Array by Concatenating Subarrays of Another Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","String Matching"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "GGdu6E9o7D4"
youtube_upload_date="2021-02-23"
youtube_thumbnail="https://i.ytimg.com/vi/GGdu6E9o7D4/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
        
        int numsIdx = 0, grpIdx = 0;
        
        while(numsIdx < nums.size() && grpIdx < group.size()) {
            

            int matchCnt = 0;
            
            while(numsIdx + matchCnt < nums.size() &&
                 matchCnt < group[grpIdx].size() &&
                 nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
                    matchCnt++;
            
            if(matchCnt == group[grpIdx].size()) {
                grpIdx++;
                numsIdx += matchCnt;
            } else numsIdx++;

        }
                
        return grpIdx == group.size();
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand requires us to determine whether we can sequentially choose groups of integers from a given list (`nums`) based on specified subarrays (groups). Each group must appear in the same order as they are defined in the `group` list, and all elements of a group must be contiguous within `nums`. The challenge is to implement an efficient solution that traverses both the `nums` and `group` arrays and verifies this condition.

### Approach

The algorithm employs a two-pointer technique to iterate through both the `nums` array and the `group` array. The main idea is to use one pointer (`numsIdx`) to traverse the `nums` array and another pointer (`grpIdx`) to traverse the `group` array. Here's how the algorithm is structured:

1. **Initialization**: Start with both pointers at the beginning of their respective arrays.

2. **Outer Loop**: The outer loop continues until all groups are checked or all elements in `nums` have been processed.

3. **Matching Elements**: For each group, an inner loop checks if the elements in `group[grpIdx]` match the current segment of `nums`, starting from `numsIdx`. Count the number of consecutive matching elements.

4. **Advancing Pointers**: 
   - If all elements in the current group are found in sequence in `nums`, advance both pointers to process the next group and the next part of `nums`.
   - If a match is not found, increment `numsIdx` to check the next potential starting point in `nums`.

5. **Final Check**: After processing, check if all groups were successfully matched. If so, return `true`; otherwise, return `false`.

### Code Breakdown (Step by Step)

The code is implemented in the `Solution` class and consists of a single public method, `canChoose`, which takes two parameters: `group` (a vector of integer vectors) and `nums` (a vector of integers).

1. **Class Definition**: The solution is encapsulated within the `Solution` class.

   ```cpp
   class Solution {
   ```

2. **Method Signature**: The `canChoose` method takes two parameters: a reference to a vector of vectors (`group`) and a reference to a vector of integers (`nums`).

   ```cpp
   public:
       bool canChoose(vector<vector<int>>& group, vector<int>& nums) {
   ```

3. **Pointer Initialization**: Two integer variables are initialized to track the current index in `nums` (`numsIdx`) and the current index in `group` (`grpIdx`).

   ```cpp
   int numsIdx = 0, grpIdx = 0;
   ```

4. **Outer While Loop**: This loop continues as long as there are remaining elements in `nums` and groups in `group`.

   ```cpp
   while(numsIdx < nums.size() && grpIdx < group.size()) {
   ```

5. **Matching Count**: A variable `matchCnt` is initialized to zero. This will count how many elements from the current group match the corresponding elements in `nums`.

   ```cpp
   int matchCnt = 0;
   ```

6. **Inner While Loop**: This nested loop checks for consecutive matches between `group[grpIdx]` and the corresponding elements in `nums`, starting from `numsIdx`.

   ```cpp
   while(numsIdx + matchCnt < nums.size() &&
         matchCnt < group[grpIdx].size() &&
         nums[numsIdx + matchCnt] == group[grpIdx][matchCnt])
       matchCnt++;
   ```

7. **Check for Full Match**: After the inner loop, the algorithm checks if the entire current group was matched.

   ```cpp
   if(matchCnt == group[grpIdx].size()) {
   ```

   - If matched, both pointers are advanced: `grpIdx` is incremented to check the next group, and `numsIdx` is updated to skip the matched elements in `nums`.

   ```cpp
       grpIdx++;
       numsIdx += matchCnt;
   ```

   - If not matched, simply increment `numsIdx` to try the next potential starting point in `nums`.

   ```cpp
   } else numsIdx++;
   ```

8. **Final Result**: After completing the traversal, the function checks if all groups were matched and returns the result.

   ```cpp
   return grpIdx == group.size();
   ```

### Complexity

- **Time Complexity**: The time complexity of the algorithm is \(O(n + m)\), where \(n\) is the length of `nums` and \(m\) is the total number of elements across all groups in `group`. This is efficient as we only make a single pass through both arrays.

- **Space Complexity**: The space complexity is \(O(1)\) since no additional data structures are used that grow with the input size; only a few integer variables are utilized.

### Conclusion

The `canChoose` method is an effective solution to determine if a series of groups can be sequentially chosen from an integer array while preserving order and contiguity. Utilizing a two-pointer technique allows the algorithm to efficiently traverse the input data without requiring nested loops, leading to an optimal solution.

This method demonstrates the power of iteration and matching algorithms in competitive programming. By structuring the algorithm to check for contiguous sequences, it achieves both clarity and performance. 

In practical applications, this approach could be adapted for tasks such as substring matching, pattern recognition, or validating sequences in larger datasets, making it a versatile tool in the software developer's toolkit. 

Overall, the `canChoose` function showcases essential algorithmic principles that can be applied to a wide array of programming challenges, encouraging best practices in code efficiency and readability.

[`Link to LeetCode Lab`](https://leetcode.com/problems/form-array-by-concatenating-subarrays-of-another-array/description/)

---
{{< youtube GGdu6E9o7D4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
