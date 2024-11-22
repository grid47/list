
+++
authors = ["grid47"]
title = "Leetcode 1296: Divide Array in Sets of K Consecutive Numbers"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1296: Divide Array in Sets of K Consecutive Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting"]
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
    bool isPossibleDivide(vector<int>& nums, int k) {

        map<int, int> cnt;
        int n = nums.size();
        for(int num : nums)
            cnt[num]++;
        
        for(auto it : cnt) {
            int frq = it.second;
            if(frq > 0)
            for(int i = 0; i < k; i++) {

                  if(cnt[it.first + i] < frq) return false;
                else cnt[it.first + i] -= frq;

            }
        }
        
        return true;
    }
};
{{< /highlight >}}
---



### Problem Statement
The problem requires us to determine whether an array of integers can be divided into `n` groups of `k` consecutive integers each, where `n` is the total number of groups formed. Each group must contain consecutive numbers, meaning that if the smallest number in a group is `x`, then the group must include `x`, `x+1`, ..., `x+k-1`.

For example, given an input array like `[1, 2, 3, 3, 4, 4, 5, 6]` and `k = 4`, it should return `true` because we can form the following groups:
- Group 1: `[1, 2, 3, 4]`
- Group 2: `[3, 4, 5, 6]`

Conversely, an input like `[1, 2, 3, 4, 5]` with `k = 4` would return `false`, as it's impossible to form two groups of four consecutive integers from this array.

### Approach
To solve this problem, we can follow these steps:

1. **Count Frequencies**: Use a map (or unordered_map) to count the frequency of each integer in the array. This helps us track how many times each number appears.

2. **Iterate Through Unique Numbers**: Iterate through the sorted unique numbers in the map. For each number, check if we can form a group starting with that number.

3. **Form Groups**: For each number that still has a positive frequency, attempt to form a complete group of `k` consecutive integers. If any of the required integers in the group is not available in sufficient frequency, return `false`.

4. **Adjust Frequencies**: If a group is formed successfully, reduce the frequency counts of all integers in that group.

5. **Return Result**: If we can form all required groups, return `true`; otherwise, return `false`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
```
- **Line 1-2**: The `Solution` class is defined, and the `isPossibleDivide` function begins, taking a vector `nums` and an integer `k` as parameters.

```cpp
        map<int, int> cnt;
        int n = nums.size();
        for(int num : nums)
            cnt[num]++;
```
- **Lines 3-6**: We create a map `cnt` to count the frequency of each number in `nums`. The variable `n` stores the size of the input array. The loop iterates through `nums`, incrementing the count for each integer.

```cpp
        for(auto it : cnt) {
            int frq = it.second;
            if(frq > 0)
```
- **Lines 7-9**: We iterate through each unique number in the frequency map. The variable `frq` stores the current number's frequency. We check if `frq` is greater than zero, meaning there are still numbers available to form groups.

```cpp
            for(int i = 0; i < k; i++) {
                if(cnt[it.first + i] < frq) return false;
```
- **Lines 10-12**: We enter a loop that runs `k` times to check for all consecutive integers starting from `it.first`. If the count of any required consecutive integer (i.e., `it.first + i`) is less than the frequency of the starting integer, we return `false`, as we can't form a complete group.

```cpp
                else cnt[it.first + i] -= frq;
            }
        }
        
        return true;
    }
};
```
- **Lines 13-16**: If the check passes, we reduce the count for each integer in the group by `frq`, indicating that we've used these integers to form a group. Finally, after checking all unique numbers, if no conditions for failure were triggered, we return `true`, indicating it's possible to divide the array into groups of consecutive integers.

### Complexity Analysis
1. **Time Complexity**:
   - The time complexity is \(O(n + m)\), where \(n\) is the number of elements in the `nums` array and \(m\) is the number of unique integers in `nums`. The loop for counting frequencies runs in \(O(n)\), and the loop for forming groups runs in \(O(m \cdot k)\).

2. **Space Complexity**:
   - The space complexity is \(O(m)\) due to the storage required for the frequency map, where \(m\) is the number of unique integers in the input array.

### Conclusion
The `isPossibleDivide` function effectively checks if an array can be divided into groups of consecutive integers using a frequency counting approach. By leveraging a map to track the number of occurrences of each integer, the function ensures that all necessary conditions for forming the groups are met.

This solution is efficient, clear, and well-suited for competitive programming scenarios and coding interviews where similar problems are commonly encountered. Understanding this approach enhances one's problem-solving skills, especially in dealing with collections of numbers and constraints regarding their arrangement or grouping.

In summary, this detailed breakdown not only explains how the code works but also provides insight into the underlying algorithmic principles, making it a valuable resource for anyone looking to deepen their knowledge of algorithms and data structures.

[`Link to LeetCode Lab`](https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
