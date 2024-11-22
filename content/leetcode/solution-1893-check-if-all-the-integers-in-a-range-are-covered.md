
+++
authors = ["grid47"]
title = "Leetcode 1893: Check if All the Integers in a Range Are Covered"
date = "2024-05-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1893: Check if All the Integers in a Range Are Covered in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "hZ7QlMbyaKw"
youtube_upload_date="2021-06-12"
youtube_thumbnail="https://i.ytimg.com/vi_webp/hZ7QlMbyaKw/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52] = {};
        for (auto &r : ranges) {
            line[r[0]] += 1;
            line[r[1] + 1] -= 1;
        }
        for (int i = 1, overlaps = 0; i <= right; ++i) {
            overlaps += line[i];
            if (i >= left && overlaps == 0)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem involves checking whether a given range `[left, right]` is completely covered by a series of ranges defined in a 2D array called `ranges`. Each element in `ranges` consists of two integers representing the start and end of a range. The goal is to determine if every integer between `left` and `right` (inclusive) is contained within at least one of the ranges provided in the `ranges` array.

### Approach

To solve this problem, we will use a technique known as the "sweep line" algorithm. This involves creating an array (or a line) that keeps track of how many ranges are active at each point. We can do this by iterating through the provided ranges and marking the start and end points of each range. By incrementing at the start and decrementing just after the end of each range, we can determine how many ranges cover each point as we iterate through.

### Code Breakdown (Step by Step)

1. **Class Definition**: We define a class named `Solution` to encapsulate our method for solving the problem.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Declaration**: The `isCovered` function is defined, which takes two parameters: a vector of vectors `ranges` and two integers `left` and `right`.

   ```cpp
       bool isCovered(vector<vector<int>>& ranges, int left, int right) {
   ```

3. **Array Initialization**: We declare an array `line` of size 52 (to cover the range from 1 to 51). This will help track how many ranges cover each point.

   ```cpp
           int line[52] = {};
   ```

4. **Marking the Ranges**: We loop through each range in `ranges` and mark the start and end points. For each range `[start, end]`, we increment the position `start` and decrement the position `end + 1` to indicate that the range ends after `end`.

   ```cpp
           for (auto &r : ranges) {
               line[r[0]] += 1;        // Start of a range
               line[r[1] + 1] -= 1;    // End of a range (exclusive)
           }
   ```

5. **Checking Coverage**: We then iterate through the positions from 1 to `right` to check if all integers in the range `[left, right]` are covered. We maintain a counter `overlaps` to track how many ranges are active at each point.

   ```cpp
           for (int i = 1, overlaps = 0; i <= right; ++i) {
               overlaps += line[i]; // Update active ranges
   ```

6. **Validation of Coverage**: For each integer in the range `[left, right]`, we check if it falls within the active coverage. If an integer in the specified range has zero overlaps, it means it is not covered by any range, and we return `false`.

   ```cpp
               if (i >= left && overlaps == 0)
                   return false; // Not covered
           }
   ```

7. **Returning the Result**: If all integers in the specified range are covered by the ranges, we return `true`.

   ```cpp
           return true; // All covered
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \( O(n + m) \), where \( n \) is the number of ranges in the `ranges` array and \( m \) is the maximum value of `right`. This is because we iterate through the `ranges` to mark the line array and then iterate through the line array to check for coverage.

- **Space Complexity**: The space complexity is \( O(1) \) in terms of auxiliary space since the `line` array has a fixed size of 52 regardless of the input size.

### Conclusion

The `isCovered` function provides an efficient and effective way to determine whether a specified range `[left, right]` is completely covered by a set of ranges. By employing the sweep line technique, we can track the coverage efficiently without needing to iterate over each integer in the range repeatedly.

This approach is particularly useful for problems involving intervals and ranges, as it allows for quick and easy calculations regarding coverage and overlap. The design is also efficient, requiring only a linear pass through the data and minimal additional storage.

This solution is not only efficient but also straightforward, making it an excellent choice for tackling similar problems in competitive programming and algorithm design. Understanding how to implement the sweep line technique opens doors to solving a variety of range-related challenges, enhancing one's problem-solving toolkit in the realm of algorithms.

[`Link to LeetCode Lab`](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/)

---
{{< youtube hZ7QlMbyaKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
