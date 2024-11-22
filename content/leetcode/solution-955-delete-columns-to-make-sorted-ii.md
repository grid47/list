
+++
authors = ["grid47"]
title = "Leetcode 955: Delete Columns to Make Sorted II"
date = "2024-08-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 955: Delete Columns to Make Sorted II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, m = strs.size(), n = strs[0].size();
        int i , j;
        vector<bool> sorted(m - 1, false);
        for(j = 0; j < n; j++) {
            for(i = 0; i < m - 1; i++) {
                if(!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    res++;
                    break;
                }
            }
            if(i < m - 1) continue;
            for(i = 0; i < m - 1; i++) {
                sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
            }
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine the minimum number of columns to delete from a list of strings such that each string is lexicographically sorted when read column-wise. A lexicographically sorted order means that for any two consecutive strings in the list, the characters in each column must either be in non-decreasing order (from top to bottom). The goal is to return the minimum number of columns that must be deleted to ensure that the remaining columns maintain this lexicographical order across all strings.

### Approach

The solution involves scanning through each column of the strings to determine if any characters violate the lexicographical order. If a column does violate the order, it needs to be deleted. The algorithm proceeds as follows:

1. **Iterate Over Each Column**: Start by checking each column in the given set of strings.
2. **Identify Violations**: For each column, check if any string at position `i` is lexicographically greater than the string at position `i + 1`. If this happens, mark the column for deletion.
3. **Track Sorted Columns**: If a column does not need deletion, keep track of columns that maintain their order (sorted columns).
4. **Count Deletions**: Finally, count and return the number of columns that need to be deleted to ensure lexicographical order across the strings.

The solution uses a greedy approach that minimizes the number of deletions while ensuring that the remaining columns are in the required order. The algorithm efficiently determines which columns violate the condition and immediately counts them as deletions.

### Code Breakdown (Step by Step)

1. **Initial Setup**:
   ```cpp
   int res = 0, m = strs.size(), n = strs[0].size();
   int i , j;
   vector<bool> sorted(m - 1, false);
   ```
   - `res`: This variable will store the number of columns that need to be deleted.
   - `m`: The number of strings (rows) in the input `strs`.
   - `n`: The length of each string (number of columns).
   - `sorted`: A vector that tracks whether the strings are sorted in the current column. It's initialized to `false` for all pairs of strings.

2. **Iterating Over Columns**:
   ```cpp
   for(j = 0; j < n; j++) {
   ```
   - The outer loop iterates over each column, denoted by `j`.

3. **Checking for Violations**:
   ```cpp
   for(i = 0; i < m - 1; i++) {
       if(!sorted[i] && strs[i][j] > strs[i + 1][j]) {
           res++;
           break;
       }
   }
   ```
   - The inner loop checks each pair of adjacent strings (`strs[i]` and `strs[i+1]`) in the current column `j`.
   - If the strings are not yet sorted (`!sorted[i]`) and the character in the current column `strs[i][j]` is greater than `strs[i+1][j]`, it means the column violates the lexicographical order. Therefore, the column is marked for deletion (`res++`), and the loop breaks early.

4. **Skip Columns That Need Deletion**:
   ```cpp
   if(i < m - 1) continue;
   ```
   - If a column needs deletion, the `continue` statement skips the remaining steps for that column and moves to the next one.

5. **Mark Columns as Sorted**:
   ```cpp
   for(i = 0; i < m - 1; i++) {
       sorted[i] = sorted[i] || strs[i][j] < strs[i + 1][j];
   }
   ```
   - After checking for violations, if no deletions are made for the current column, we update the `sorted` vector. If any string `strs[i]` is lexicographically smaller than `strs[i+1]` in the current column, we mark that pair as sorted.

6. **Return the Result**:
   ```cpp
   return res;
   ```
   - The function finally returns the value of `res`, which represents the minimum number of columns that need to be deleted.

### Complexity

1. **Time Complexity**:
   - The solution involves two nested loops: the outer loop iterates over each column (`n` columns), and the inner loop compares adjacent strings in each column (`m - 1` comparisons).
   - Therefore, the time complexity of the solution is O(m * n), where `m` is the number of strings and `n` is the length of each string.

2. **Space Complexity**:
   - The space complexity is O(m), as the `sorted` vector stores a boolean value for each adjacent pair of strings, and the space required for this vector is proportional to the number of strings (`m`).
   - The overall space complexity is O(m) in addition to the space needed to store the input strings.

### Conclusion

The problem is efficiently solved using a greedy approach that checks each column in the input strings. The algorithm iterates over each column and determines if it is lexicographically sorted across all strings. If not, the column is marked for deletion, and the number of deletions is counted. This solution runs in linear time with respect to the size of the input, making it efficient for larger inputs.

In summary, the solution efficiently finds the minimum number of columns to delete by checking each column for lexicographical violations and counts how many columns violate the required order. By doing so, it minimizes the deletions needed while ensuring that the remaining columns maintain the lexicographical order.

[`Link to LeetCode Lab`](https://leetcode.com/problems/delete-columns-to-make-sorted-ii/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
