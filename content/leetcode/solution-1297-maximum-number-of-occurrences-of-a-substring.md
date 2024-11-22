
+++
authors = ["grid47"]
title = "Leetcode 1297: Maximum Number of Occurrences of a Substring"
date = "2024-06-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1297: Maximum Number of Occurrences of a Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Sliding Window"]
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
The problem at hand is to determine if an array of integers can be divided into `n` groups of size `k`, where each group contains consecutive integers. This means that if we start with the smallest integer in a group, the group must contain that integer and the next `k-1` integers. For example, given an input array like `[1, 2, 3, 3, 4, 4, 5, 6]` and `k = 4`, the function should return `true` because it is possible to form groups such as `[1, 2, 3, 4]` and `[3, 4, 5, 6]`. Conversely, for an input like `[1, 2, 3, 4, 5]` with `k = 4`, the function would return `false`, as it is not possible to create two groups of four consecutive integers.

### Approach
To determine if the division into groups is possible, we can follow these steps:

1. **Count Frequencies**: Use a `map` to count the frequency of each integer in the array. This allows us to track how many times each number appears.

2. **Iterate Through Unique Numbers**: Loop through the sorted unique numbers in the map and attempt to form groups starting with each number that has a positive frequency.

3. **Form Groups**: For each unique number, check if we can form a complete group of `k` consecutive integers. If any of the required integers is not available in the necessary frequency, return `false`.

4. **Adjust Frequencies**: If a group is successfully formed, decrease the frequency counts of all integers in that group.

5. **Return Result**: If all groups are formed without issues, return `true`; otherwise, return `false`.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
```
- **Line 1-2**: The `Solution` class is declared, and the `isPossibleDivide` function starts, accepting a vector of integers `nums` and an integer `k`.

```cpp
        map<int, int> cnt;
        int n = nums.size();
        for(int num : nums)
            cnt[num]++;
```
- **Lines 3-6**: We create a `map` named `cnt` to store the frequency of each integer in `nums`. The variable `n` captures the size of the input array. The loop iterates through each number in `nums`, incrementing its corresponding count in the map.

```cpp
        for(auto it : cnt) {
            int frq = it.second;
            if(frq > 0)
```
- **Lines 7-9**: The next loop iterates through the entries in the frequency map. For each unique number, we assign its frequency to the variable `frq`. We check if `frq` is greater than zero, which indicates that we still have available integers to form groups.

```cpp
            for(int i = 0; i < k; i++) {
                if(cnt[it.first + i] < frq) return false;
```
- **Lines 10-12**: A nested loop runs `k` times to check for all integers starting from `it.first`. If the count of any required consecutive integer (i.e., `it.first + i`) is less than `frq`, we return `false`, as it means we cannot form a complete group.

```cpp
                else cnt[it.first + i] -= frq;
            }
        }
        
        return true;
    }
};
```
- **Lines 13-16**: If the check passes, we decrease the count for each integer in the group by `frq`, indicating that we've used these integers to create a group. If all checks are successful and all required groups can be formed, we return `true`.

### Complexity Analysis
1. **Time Complexity**:
   - The overall time complexity of this function is \(O(n + m \cdot k)\), where \(n\) is the number of elements in the `nums` array and \(m\) is the number of unique integers in `nums`. The initial loop for counting frequencies operates in \(O(n)\), while the subsequent loops for checking group formation run in \(O(m \cdot k)\).

2. **Space Complexity**:
   - The space complexity is \(O(m)\) because we store the frequency counts in a `map`, where \(m\) represents the number of unique integers in the input array.

### Conclusion
The `isPossibleDivide` function efficiently determines whether an array can be divided into groups of consecutive integers of a specified size. It utilizes a counting approach that ensures all necessary conditions for forming groups are met. By leveraging a map to keep track of the occurrences of each integer, the function provides a clear and straightforward solution.

This implementation is particularly valuable in competitive programming and coding interviews, where such problems involving number grouping and frequency counting are common. Understanding this method enhances problem-solving skills, especially when working with collections of integers under specific constraints.

In summary, this explanation offers a detailed look at how the `isPossibleDivide` function operates, providing insights into its algorithmic design while ensuring it is accessible for those looking to improve their understanding of similar programming challenges.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
