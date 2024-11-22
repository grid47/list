
+++
authors = ["grid47"]
title = "Leetcode 2815: Max Pair Sum in an Array"
date = "2024-01-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2815: Max Pair Sum in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "DUrmIZhrj4o"
youtube_upload_date="2023-08-13"
youtube_thumbnail="https://i.ytimg.com/vi/DUrmIZhrj4o/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        vector<vector<int>> ids(10);
        
        for(int x: nums) {
            int val = x;
            int f = x % 10;
            while(x > 0) {
                f = max(f, x % 10);
                x /= 10;
            }
            ids[f].push_back(val);            
        }
        int ans = -1;
        for(int i = 0; i < ids.size(); i++) {
            sort(ids[i].begin(), ids[i].end());
            int n = ids[i].size();
            if(ids[i].size() >= 2) {
                // cout << ids[i][n - 1] << " " << ids[i][n - 2] << " "<< ids[i][n - 1] + ids[i][n - 2] << "\n";
                ans = max(ans, ids[i][n - 1] + ids[i][n - 2]);
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given an array of integers `nums`, and you are tasked with finding the maximum sum of any two numbers from the array where both numbers share the same **maximum digit**. A "maximum digit" is the largest digit present in a number. For example, in the number `483`, the maximum digit is `8`. You need to return the maximum sum of two such numbers with the same maximum digit, or `-1` if no such pair exists.

### Approach

To solve this problem efficiently, we can follow a series of steps:

1. **Extract Maximum Digits**: For each number in the list, we first determine its maximum digit.
   
2. **Grouping by Maximum Digit**: We then group the numbers by their maximum digit. For example, all numbers whose maximum digit is `9` are grouped together, and so on for other digits.

3. **Finding Maximum Pair**: For each group (corresponding to a particular maximum digit), we check if the group contains at least two numbers. If so, we calculate the sum of the two largest numbers in that group and keep track of the maximum such sum across all groups.

4. **Return the Result**: If we find at least one valid pair, we return the maximum sum. If no such pair exists, we return `-1`.

### Code Breakdown (Step by Step)

1. **Initializing the Grouping Data Structure**:
   ```cpp
   vector<vector<int>> ids(10);
   ```
   - We use a vector of vectors `ids` to store numbers grouped by their maximum digit. There are 10 groups (one for each digit from 0 to 9), as the maximum digit of any number can only be in the range 0-9.

2. **Processing Each Number**:
   ```cpp
   for(int x: nums) {
       int val = x;
       int f = x % 10;
       while(x > 0) {
           f = max(f, x % 10);
           x /= 10;
       }
       ids[f].push_back(val);
   }
   ```
   - We loop through each number `x` in the input array `nums`.
   - We start by assuming the last digit of `x` is the maximum digit (`f = x % 10`).
   - We then iterate over the digits of the number by repeatedly dividing it by 10, updating `f` to hold the largest digit encountered.
   - Once we find the maximum digit `f` for the number, we add it to the corresponding group in `ids[f]`.

3. **Finding the Two Largest Numbers for Each Group**:
   ```cpp
   int ans = -1;
   for(int i = 0; i < ids.size(); i++) {
       sort(ids[i].begin(), ids[i].end());
       int n = ids[i].size();
       if(ids[i].size() >= 2) {
           ans = max(ans, ids[i][n - 1] + ids[i][n - 2]);
       }
   }
   ```
   - After grouping the numbers, we initialize `ans` to `-1`, which will be used to store the maximum sum of two numbers that share the same maximum digit.
   - For each group `ids[i]`, we first sort the numbers in ascending order to easily find the two largest numbers.
   - If the group contains at least two numbers, we compute the sum of the two largest numbers (`ids[i][n - 1]` and `ids[i][n - 2]`), and update `ans` to be the maximum of the current `ans` and this new sum.

4. **Return the Result**:
   ```cpp
   return ans;
   ```
   - Finally, after processing all groups, we return `ans`, which contains the maximum sum of two numbers with the same maximum digit. If no such pair exists, `ans` will remain `-1`, which is the correct output.

### Complexity

1. **Time Complexity**:
   - The main operations in the code are:
     - Looping through each number in `nums` to determine its maximum digit, which takes `O(d)` time for each number, where `d` is the number of digits in the number. Since `d` is typically small (up to 10 for large numbers), this is approximately **O(n)** where `n` is the number of elements in `nums`.
     - Sorting the numbers within each group. The worst-case scenario occurs when all numbers have the same maximum digit, in which case we sort the entire list. Sorting each group takes **O(m log m)**, where `m` is the number of elements in the group. In the worst case, the total time complexity for sorting across all groups is **O(n log n)**, where `n` is the total number of elements in the array.
   
   Therefore, the total time complexity of the solution is **O(n log n)**, where `n` is the number of elements in `nums`.

2. **Space Complexity**:
   - We use a vector `ids` of size 10 to store the numbers grouped by their maximum digit, which takes **O(n)** space.
   - The sorting operations within each group do not require additional space beyond the input data.
   - Thus, the space complexity is **O(n)**, where `n` is the number of elements in `nums`.

### Conclusion

The algorithm efficiently solves the problem by utilizing a grouping strategy based on the maximum digit of each number. It first calculates the maximum digit for each number, groups the numbers by their maximum digit, and then sorts each group to find the two largest numbers to maximize their sum.

With a time complexity of **O(n log n)**, the solution is efficient enough for typical input sizes. The space complexity of **O(n)** is also optimal for this problem, as it only requires space to store the grouped numbers.

This solution provides a straightforward and clear approach to solving the problem of finding the maximum sum of two numbers sharing the same maximum digit, ensuring both correctness and efficiency.

[`Link to LeetCode Lab`](https://leetcode.com/problems/max-pair-sum-in-an-array/description/)

---
{{< youtube DUrmIZhrj4o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
