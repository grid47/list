
+++
authors = ["grid47"]
title = "Leetcode 673: Number of Longest Increasing Subsequence"
date = "2024-08-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 673: Number of Longest Increasing Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Binary Indexed Tree","Segment Tree"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/673.webp"
youtube = "Tuc-rjJbsXU"
youtube_upload_date="2021-11-24"
youtube_thumbnail="https://i.ytimg.com/vi/Tuc-rjJbsXU/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/673.webp" 
    alt="A sequence of numbers where the longest increasing subsequence is highlighted and softly glowing."
    caption="Solution to LeetCode 673: Number of Longest Increasing Subsequence Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int res = 0, n = nums.size(), max_len = 0;
        vector<int> len(n, 0), cnt(n, 0);
        
        for(int i = 0; i < n; i++) {
            cnt[i] = 1;
            len[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
                    if(len[j] + 1 >  len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }   
            }
            if(max_len == len[i]) res += cnt[i];
            if(max_len < len[i]) {
                res = cnt[i];
                max_len = len[i];
            }
            
        }
        
        return res;
        
    }
};
{{< /highlight >}}
---

### Problem Statement:

Given an unsorted array of integers `nums`, the goal is to find the number of longest increasing subsequences (LIS). A subsequence is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements. The longest increasing subsequence is the subsequence that has the maximum length, and we need to return how many such subsequences exist.

### Approach:

The problem is about finding the number of distinct longest increasing subsequences (LIS) in an array. The key observations are:
1. **LIS Length**: A subsequence is considered increasing if each element is greater than the previous one.
2. **Multiple LIS**: The same LIS may appear in multiple distinct ways. For example, the array `[1, 2, 3]` has one LIS, but the array `[1, 2, 3, 2]` has two LIS: `[1, 2, 3]` and `[1, 2, 3]` again.

We can solve this problem using dynamic programming to find the length of the LIS and also track the count of different LIS of that length at each index.

### Code Breakdown (Step by Step):

The algorithm uses dynamic programming (DP) with two arrays:
1. **len[i]**: This array stores the length of the longest increasing subsequence that ends at index `i`.
2. **cnt[i]**: This array stores the number of distinct longest increasing subsequences that end at index `i`.

We then calculate these values iteratively, ensuring that we properly track the longest subsequence and its frequency.

#### Step 1: Initialize the variables
```cpp
int res = 0, n = nums.size(), max_len = 0;
vector<int> len(n, 0), cnt(n, 0);
```
- `res`: Stores the total count of LIS.
- `n`: The length of the input array `nums`.
- `max_len`: Tracks the maximum length of the increasing subsequences.
- `len`: A vector initialized to `0`, representing the LIS length at each index.
- `cnt`: A vector initialized to `0`, representing the count of LIS of the length `len[i]` at each index.

#### Step 2: Iterating through the array
```cpp
for(int i = 0; i < n; i++) {
    cnt[i] = 1;
    len[i] = 1;
```
For each element `i` in the array, we initialize `len[i] = 1` (the minimum length of LIS ending at `i` is 1, the element itself) and `cnt[i] = 1` (initially, there's only one subsequence of length 1, the element itself).

#### Step 3: Finding subsequences ending at index `i`
```cpp
for(int j = 0; j < i; j++) {
    if(nums[j] < nums[i]) {
```
For each `i`, we check all previous elements `j` (from `0` to `i-1`). If `nums[j] < nums[i]`, it means `nums[i]` can extend an increasing subsequence that ends at `j`.

#### Step 4: Updating `len[i]` and `cnt[i]`
```cpp
    if(len[j] + 1 == len[i]) cnt[i] += cnt[j];
    if(len[j] + 1 >  len[i]) {
        len[i] = len[j] + 1;
        cnt[i] = cnt[j];
    }
}
```
- If `len[j] + 1 == len[i]`, it means `nums[i]` is part of a subsequence of the same length as `len[i]`, so we add the number of subsequences ending at `j` to `cnt[i]`.
- If `len[j] + 1 > len[i]`, it means we've found a longer subsequence ending at `i`, so we update `len[i]` to `len[j] + 1` and reset `cnt[i]` to `cnt[j]`, meaning that the count of LIS ending at `i` is now equal to the count of LIS ending at `j`.

#### Step 5: Tracking the maximum length and the total count
```cpp
if(max_len == len[i]) res += cnt[i];
if(max_len < len[i]) {
    res = cnt[i];
    max_len = len[i];
}
```
- If `len[i] == max_len`, it means we've found another subsequence of the maximum length, so we add the count of such subsequences (`cnt[i]`) to the result `res`.
- If `len[i] > max_len`, we update `max_len` to `len[i]` and set `res` to `cnt[i]` because we've found a new longest subsequence, and the count of these subsequences is `cnt[i]`.

#### Step 6: Return the final result
```cpp
return res;
```
The function finally returns `res`, which contains the total count of longest increasing subsequences.

### Complexity:

#### Time Complexity:
- **O(n^2)**: The algorithm iterates through each element `i` and compares it with every previous element `j` to find the LIS and count the subsequences. This results in a nested loop, making the time complexity `O(n^2)`, where `n` is the length of the array `nums`.

#### Space Complexity:
- **O(n)**: The space complexity is dominated by the two arrays `len` and `cnt`, which each require `O(n)` space. Thus, the overall space complexity is `O(n)`.

### Conclusion:

This approach uses dynamic programming to efficiently compute the number of distinct longest increasing subsequences (LIS). By maintaining two arrays, `len` and `cnt`, we can track the length of the LIS and the number of ways to form such subsequences ending at each index. The algorithm performs well for arrays of moderate size with a time complexity of `O(n^2)`.

Key observations include:
- Each element is processed in relation to every previous element to build the longest subsequence ending at that element.
- The algorithm efficiently counts how many distinct LIS can end at each position in the array and tracks the global maximum length.

This solution works effectively for finding the number of LIS in an array and can handle typical input sizes in competitive programming and real-world applications.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/)

---
{{< youtube Tuc-rjJbsXU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
