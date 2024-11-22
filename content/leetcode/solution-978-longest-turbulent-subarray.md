
+++
authors = ["grid47"]
title = "Leetcode 978: Longest Turbulent Subarray"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 978: Longest Turbulent Subarray in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "V_iHUhR8Dek"
youtube_upload_date="2023-02-25"
youtube_thumbnail="https://i.ytimg.com/vi_webp/V_iHUhR8Dek/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {

        vector<int> dp(2, 1);
        
        int res = 1, n = arr.size(), prv = 0;

        for(int i = 1; i < n; i++) {

            if ((prv == 0 || prv == -1) && arr[i - 1] < arr[i] ) {
                dp[0] = dp[1] + 1;
                res = max(res, dp[0]);
                prv = 1;
            } else if ((prv == 0 || prv == 1) && arr[i - 1] > arr[i] ) {
                dp[1] = dp[0] + 1;
                res = max(res, dp[1]);
                prv = -1;
            }
            else if (arr[i - 1] == arr[i] ) {
                dp[0] = 1;
                dp[1] = 1;
                prv = 0;
            } else {
                dp[0] = 2;
                dp[1] = 2;
                prv = (arr[i - 1] < arr[i]) ? 1 : -1;
            }
        }
        
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the length of the longest **turbulent subarray** in a given array `arr`. A **turbulent array** is an array where the elements alternate between increasing and decreasing. Specifically, an array is turbulent if:
- For all `i`, `arr[i] > arr[i + 1]` (when the previous element is greater than the current element) or 
- `arr[i] < arr[i + 1]` (when the previous element is smaller than the current element).

The task is to find the maximum length of a contiguous subarray where the sequence alternates between increasing and decreasing.

For example:
- **Input**: `arr = [9, 1, 7, 3, 5, 2]`
- **Output**: `4` (The longest turbulent subarray is `[1, 7, 3, 5]`).

### Approach

We need to identify the longest contiguous subarray where the sequence alternates between increasing and decreasing numbers. The solution leverages **dynamic programming** combined with a state-tracking mechanism for the **alternating** nature of the sequence.

#### Key Insights:
1. **Alternating Sequence**: For the subarray to be turbulent, each element in the subarray must alternate between being greater or smaller than the next element. Specifically, at each step, there should be either an **increase** (next element is larger) or a **decrease** (next element is smaller).
   
2. **Dynamic Programming Approach**: We can maintain two state variables:
   - `dp[0]`: the length of the longest turbulent subarray ending at the current index where the sequence is **increasing**.
   - `dp[1]`: the length of the longest turbulent subarray ending at the current index where the sequence is **decreasing**.
   
   These states help track the lengths of subarrays while alternating between increasing and decreasing patterns.

3. **State Transitions**:
   - If the current element is **greater** than the previous one, then we extend the **decreasing** subsequence to form an increasing sequence at the current position.
   - If the current element is **less** than the previous one, then we extend the **increasing** subsequence to form a decreasing sequence at the current position.
   - If the current element is **equal** to the previous one, both the increasing and decreasing subsequences are reset.
   - The length of the **turbulent subarray** ending at the current position will be updated by the maximum of the two states (`dp[0]` and `dp[1]`).

4. **Result Calculation**: We iterate through the array, updating the state values based on the comparisons between adjacent elements, and keep track of the maximum turbulent subarray length.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> dp(2, 1);  // Initialize dp array with both increasing and decreasing subarrays of length 1.
        int res = 1, n = arr.size(), prv = 0;  // res stores the maximum length of the turbulent subarray found so far.

        // Iterate over the array starting from the second element.
        for(int i = 1; i < n; i++) {
            // If the sequence is increasing:
            if ((prv == 0 || prv == -1) && arr[i - 1] < arr[i]) {
                dp[0] = dp[1] + 1;  // Extend the increasing subsequence.
                res = max(res, dp[0]);  // Update the maximum length of the turbulent subarray.
                prv = 1;  // Set the state to 'increasing'.
            }
            // If the sequence is decreasing:
            else if ((prv == 0 || prv == 1) && arr[i - 1] > arr[i]) {
                dp[1] = dp[0] + 1;  // Extend the decreasing subsequence.
                res = max(res, dp[1]);  // Update the maximum length of the turbulent subarray.
                prv = -1;  // Set the state to 'decreasing'.
            }
            // If the current element equals the previous element:
            else if (arr[i - 1] == arr[i]) {
                dp[0] = 1;  // Reset both subsequences to length 1.
                dp[1] = 1;
                prv = 0;  // Set the state to 'neutral'.
            }
            // If neither increasing nor decreasing (handles equal elements or boundaries):
            else {
                dp[0] = 2;  // Start both subsequences from length 2 (since we're dealing with two elements now).
                dp[1] = 2;
                prv = (arr[i - 1] < arr[i]) ? 1 : -1;  // Determine whether the sequence is increasing or decreasing.
            }
        }
        
        return res;  // Return the maximum length of the turbulent subarray found.
    }
};
```

1. **Initializations**:
   - `dp`: A vector of size 2 initialized to `[1, 1]` which keeps track of the lengths of the longest increasing and decreasing subsequences.
   - `res`: A variable to store the result (the maximum length of a turbulent subarray). Initially set to 1, as the minimum length of any turbulent subarray is 1.
   - `prv`: A variable to track the state of the previous comparison (whether it was increasing, decreasing, or neutral).

2. **Iterating through the array**:
   - The loop starts from index 1 and compares each element with the previous one. Depending on whether the current element is greater than, less than, or equal to the previous element, the dynamic programming states `dp[0]` (for increasing) and `dp[1]` (for decreasing) are updated accordingly.
   - The variable `prv` keeps track of the current state (whether the sequence is increasing, decreasing, or neutral).
   - For each valid transition (increasing or decreasing), the maximum length is updated.

3. **Edge Case Handling**:
   - If two adjacent elements are equal, the sequence is reset to length 1 for both increasing and decreasing subsequences.
   - If the array has only one element, it automatically returns a result of 1, as a single element is trivially a turbulent subarray.

### Time and Space Complexity

- **Time Complexity**:
  - The time complexity of the solution is **O(n)**, where `n` is the size of the input array `arr`. The array is traversed once, and each operation within the loop takes constant time.

- **Space Complexity**:
  - The space complexity is **O(1)**, as we only use a constant amount of extra space to store the dynamic programming states (`dp`) and the result (`res`).

### Conclusion

The algorithm effectively solves the problem of finding the length of the longest turbulent subarray in an optimal way. By using dynamic programming and a state-tracking mechanism for alternating increases and decreases, the solution achieves an **O(n)** time complexity and **O(1)** space complexity. This approach ensures efficiency even for larger input sizes, and it efficiently handles cases where adjacent elements are equal. The solution is both time and space optimal, making it suitable for large input arrays.

[`Link to LeetCode Lab`](https://leetcode.com/problems/longest-turbulent-subarray/description/)

---
{{< youtube V_iHUhR8Dek >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
