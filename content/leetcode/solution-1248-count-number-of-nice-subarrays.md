
+++
authors = ["grid47"]
title = "Leetcode 1248: Count Number of Nice Subarrays"
date = "2024-07-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1248: Count Number of Nice Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "4zNK0rhFfcA"
youtube_upload_date="2024-06-22"
youtube_thumbnail="https://i.ytimg.com/vi_webp/4zNK0rhFfcA/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
    
    int atmost(vector<int> &nums, int k) {
        int cnt[2] = {};
        int res = 0, j = 0;
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]%2]++;
            while(cnt[1] > k) {
                cnt[nums[j]%2]--;
                j++;
            }
            res += (i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
The task is to find the number of contiguous subarrays in a given integer array `nums` that contain exactly `k` odd numbers. A subarray is defined as a contiguous section of the array. The challenge is to do this efficiently without generating all possible subarrays explicitly.

### Approach
To solve this problem, we can utilize a technique called the **two-pointer approach** or **sliding window**, combined with the concept of counting subarrays with at most `k` odd numbers. The overall strategy can be broken down into the following steps:

1. **Subarrays with At Most k Odd Numbers**: First, we define a helper function, `atmost`, that calculates the number of contiguous subarrays containing at most `k` odd numbers. This function will be used to derive the number of subarrays with exactly `k` odd numbers.
  
2. **Calculate the Result**: To find the number of subarrays containing exactly `k` odd numbers, we can calculate:
   - The total number of subarrays with at most `k` odd numbers.
   - The total number of subarrays with at most `k - 1` odd numbers.
   The result will be the difference between these two counts.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
```
- **Lines 1-3**: The class `Solution` is defined, containing the public method `numberOfSubarrays`. This method takes an integer vector `nums` and an integer `k` as input parameters. It calls the helper function `atmost` twice:
  - First with `k` to count subarrays with at most `k` odd numbers.
  - Second with `k - 1` to count subarrays with at most `k - 1` odd numbers.
- The method returns the difference of the two results, which gives the number of subarrays containing exactly `k` odd numbers.

```cpp
    int atmost(vector<int> &nums, int k) {
        int cnt[2] = {};
        int res = 0, j = 0;
```
- **Lines 5-8**: We define the `atmost` function, which takes a reference to a vector of integers `nums` and an integer `k`. Here:
  - `cnt[2]` is an array that will count the number of odd and even numbers encountered in the current window. `cnt[0]` will track even counts, and `cnt[1]` will track odd counts.
  - `res` is initialized to zero and will accumulate the number of valid subarrays.
  - `j` is the starting index of the sliding window.

```cpp
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i] % 2]++;
```
- **Line 9**: We loop through the `nums` array with index `i`. For each number, we determine if it is odd or even using the modulus operator `%`. We increment the appropriate count in `cnt`.

```cpp
            while(cnt[1] > k) {
                cnt[nums[j] % 2]--;
                j++;
            }
```
- **Lines 10-13**: This while loop checks if the count of odd numbers exceeds `k`. If it does, we move the start of the window (`j`) to the right:
  - We decrement the count for the number at index `j` (which is moving out of the window).
  - We then increment `j` to consider the next number as the new start of the window.

```cpp
            res += (i - j + 1);
        }
        return res;
    }
};
```
- **Lines 14-16**: After adjusting the window, we calculate the number of valid subarrays ending at index `i` by adding `(i - j + 1)` to `res`. This expression accounts for all subarrays that can be formed with the current ending index `i` and starting index `j`.
- Finally, the function returns the total count of valid subarrays.

### Complexity
1. **Time Complexity**: The time complexity for the solution is \( O(n) \), where \( n \) is the length of the `nums` array. Each number is processed at most twice (once when expanding the window and once when contracting it).

2. **Space Complexity**: The space complexity is \( O(1) \) because we are using a fixed-size array (`cnt`) and a few integer variables, regardless of the size of the input.

### Conclusion
The `numberOfSubarrays` function efficiently computes the number of contiguous subarrays containing exactly `k` odd numbers by leveraging the sliding window technique. By separating the counting of subarrays with at most `k` and `k - 1` odd numbers, we avoid the need for nested loops or generating all possible subarrays explicitly. This method is optimal, achieving a linear time complexity and constant space usage, making it suitable for large input sizes. The solution exemplifies a powerful strategy for tackling problems involving subarray counting and conditions based on element properties.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-number-of-nice-subarrays/description/)

---
{{< youtube 4zNK0rhFfcA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
