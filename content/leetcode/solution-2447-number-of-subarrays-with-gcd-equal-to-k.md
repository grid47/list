
+++
authors = ["grid47"]
title = "Leetcode 2447: Number of Subarrays With GCD Equal to K"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2447: Number of Subarrays With GCD Equal to K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "QEvLvINq730"
youtube_upload_date="2022-10-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QEvLvINq730/maxresdefault.webp"
comments = true
+++



---
Given an integer array `nums` and an integer `k`, return the number of subarrays in which the greatest common divisor (GCD) of all the elements is exactly `k`. A subarray is a contiguous non-empty sequence of elements within the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` and an integer `k`.
- **Example:** `nums = [6, 3, 9, 12], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i], k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of subarrays where the greatest common divisor of all elements is equal to `k`.
- **Example:** `Output: 3`
- **Constraints:**
	- All elements in the array are non-negative integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find subarrays whose GCD equals `k`.

- Iterate through the array to find subarrays.
- For each subarray, calculate the GCD of the elements.
- Count the subarrays where the GCD is equal to `k`.
{{< dots >}}
### Problem Assumptions ✅
- The GCD operation can handle large values efficiently.
- The subarrays are contiguous.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [9, 3, 1, 6], k = 3`  \
  **Explanation:** The subarrays where the GCD of elements is 3 are [9, 3], [3], [3, 1, 6], and [9, 3, 1, 6]. Hence, the answer is 4.

- **Input:** `nums = [10, 20, 30, 40], k = 5`  \
  **Explanation:** The subarrays where the GCD of elements is 5 are [10, 20, 30, 40], [10, 20], [20, 30], and [30, 40]. So, the answer is 4.

{{< dots >}}
## Approach 🚀
The problem can be solved by iterating through all possible subarrays, calculating the GCD of each subarray, and counting the subarrays that have a GCD equal to `k`.

### Initial Thoughts 💭
- We need an efficient way to compute GCDs for subarrays.
- Naively checking all subarrays might lead to high computational overhead for larger arrays.
- We can use a nested loop to generate all subarrays, compute their GCD, and check if it matches `k`.
{{< dots >}}
### Edge Cases 🌐
- Input will never be empty as per the problem constraints.
- When the array is large (close to 1000 elements), the time complexity should be kept in mind.
- When `k` is larger than all elements in the array, there will be no subarrays with GCD equal to `k`.
- We assume the time complexity is efficient enough to handle the constraints provided.
{{< dots >}}
## Code 💻
```cpp

int subarrayGCD(vector<int>& nums, int k) {        
    int cnt = 0, n = nums.size();
    
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n && nums[j] % k == 0; j++) {
            nums[i] = __gcd(nums[i], nums[j]);
            cnt += (nums[i] == k);
        }
    }
    return cnt;
}
```

The function `subarrayGCD` computes the number of contiguous subarrays of `nums` where the greatest common divisor (GCD) of the elements in the subarray equals `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int subarrayGCD(vector<int>& nums, int k) {
	```
	This line defines the function `subarrayGCD`, which takes a vector of integers `nums` and an integer `k`, and returns the count of subarrays whose GCD equals `k`.

2. **Variable Initialization**
	```cpp
	    int cnt = 0, n = nums.size();
	```
	This line initializes the counter `cnt` to 0, which will track the number of valid subarrays, and `n`, which stores the size of the input array `nums`.

3. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	The outer loop starts at index `i` and iterates through each element of the array `nums`.

4. **Inner Loop Condition**
	```cpp
	        for(int j = i; j < n && nums[j] % k == 0; j++) {
	```
	The inner loop starts at index `i` and continues as long as the current element `nums[j]` is divisible by `k`. This ensures that we only consider elements that can potentially form a valid subarray.

5. **GCD Calculation**
	```cpp
	            nums[i] = __gcd(nums[i], nums[j]);
	```
	This line computes the greatest common divisor (GCD) of `nums[i]` and `nums[j]` and stores it back in `nums[i]`. This process updates the GCD as we extend the subarray.

6. **Count Increment**
	```cpp
	            cnt += (nums[i] == k);
	```
	If the GCD of the current subarray equals `k`, we increment the counter `cnt`.

7. **Return Statement**
	```cpp
	    return cnt;
	```
	This line returns the count `cnt` of valid subarrays whose GCD equals `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2 * log(max(nums)))
- **Worst Case:** O(n^2 * log(max(nums)))

In the worst case, we have to check all subarrays, and computing GCD for each subarray takes logarithmic time relative to the values involved.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

We are only using a counter variable, so the space complexity is constant.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/description/)

---
{{< youtube QEvLvINq730 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
