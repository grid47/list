
+++
authors = ["grid47"]
title = "Leetcode 2190: Most Frequent Number Following Key In an Array"
date = "2024-04-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2190: Most Frequent Number Following Key In an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "0KHTVvSX7CE"
youtube_upload_date="2022-03-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/0KHTVvSX7CE/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
  int mostFrequent(vector<int>& nums, int key) {
    int cnt[1001] = {}, res = 0;
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
            res = nums[i];
    return res;
  }
};
{{< /highlight >}}
---

### Problem Statement
Given an integer array `nums` and a key integer `key`, the task is to find the most frequent integer in `nums` that appears immediately after an occurrence of `key`. The solution must return the integer that has the highest frequency of occurrence following `key` in the array.

### Approach
The problem is solved efficiently using a counting technique. The solution involves iterating through the array, checking if the previous number is equal to `key`, and then counting the occurrences of numbers that follow `key`. The number with the highest count is the answer.

### Code Breakdown (Step by Step)
1. **Initialization of Counting Array:**
   ```cpp
   int cnt[1001] = {}, res = 0;
   ```
   - The array `cnt` of size 1001 is used to count the frequency of each number that follows `key` in the array. The size of 1001 ensures that all possible numbers (from 0 to 1000) can be accounted for. 
   - `res` is initialized to 0 and will store the most frequent number after `key`.

2. **Iterating Through the Array:**
   ```cpp
   for (int i = 1; i < nums.size(); ++i)
   ```
   - A `for` loop is used to traverse the array `nums` starting from the second element (index 1), as we need to compare each element with its previous one.

3. **Checking for the Key and Counting Frequencies:**
   ```cpp
   if (nums[i - 1] == key && ++cnt[nums[i]] > cnt[res])
       res = nums[i];
   ```
   - The condition `nums[i - 1] == key` checks if the previous element is equal to `key`. If this condition is true, the current element `nums[i]` is the candidate for counting.
   - The expression `++cnt[nums[i]]` increments the count of `nums[i]` in the `cnt` array.
   - The comparison `cnt[nums[i]] > cnt[res]` checks if the current number has a higher frequency than the previously stored result. If so, `res` is updated to store the current number.

4. **Return Result:**
   ```cpp
   return res;
   ```
   - After the loop completes, `res` holds the most frequent number that appears after `key` in the array. This is returned as the result.

### Complexity
- **Time Complexity**: 
  - The time complexity of this solution is O(n), where `n` is the size of the input array `nums`. This is because the solution iterates through the array once and performs constant-time operations inside the loop.
- **Space Complexity**: 
  - The space complexity is O(1), or constant space, since the only additional space used is the fixed-size array `cnt` of 1001 elements.

### Conclusion
The code provides an efficient solution to the problem of finding the most frequent integer that appears after a specified key in an array. By using a frequency count array, the algorithm ensures that each number is processed in constant time, making the solution optimal for large arrays. The linear time complexity ensures that the solution can scale well even for large input sizes, and the space complexity remains minimal, using only a fixed amount of additional space for counting occurrences. This approach strikes an ideal balance between simplicity and performance, making it suitable for real-world applications where finding frequent patterns in arrays is a common task.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/description/)

---
{{< youtube 0KHTVvSX7CE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
