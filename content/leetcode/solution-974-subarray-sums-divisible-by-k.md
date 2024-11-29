
+++
authors = ["grid47"]
title = "Leetcode 974: Subarray Sums Divisible by K"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 974: Subarray Sums Divisible by K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "bcXy-T4Sc3E"
youtube_upload_date="2024-06-09"
youtube_thumbnail="https://i.ytimg.com/vi/bcXy-T4Sc3E/maxresdefault.jpg"
comments = true
+++



---
Given an integer array nums and an integer k, return the number of non-empty subarrays where the sum of elements is divisible by k. A subarray is defined as a contiguous sequence of elements in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer array nums and an integer k.
- **Example:** `nums = [3, 1, -4, 6, 5], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 3 * 10^4
	- -10^4 <= nums[i] <= 10^4
	- 2 <= k <= 10^4

{{< dots >}}
### Output Specifications 📤
- **Output:** An integer representing the count of subarrays where the sum is divisible by k.
- **Example:** `6`
- **Constraints:**
	- The result must fit within a 32-bit signed integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of subarrays with a sum divisible by k.

- Maintain a running sum of elements as you traverse the array.
- Use the modulo operator to compute the remainder of the running sum when divided by k.
- Adjust negative remainders to ensure they fall within the range [0, k-1].
- Store the frequency of each remainder in a hashmap and use it to count subarrays with matching remainders.
{{< dots >}}
### Problem Assumptions ✅
- The array nums is valid and non-empty.
- The integer k is greater than or equal to 2.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 1, -4, 6, 5], k = 3`  \
  **Explanation:** The total subarrays with sums divisible by k = 3 are 6, including single-element subarrays like [3] and multi-element subarrays like [3, 1, -4, 6, 5].

- **Input:** `nums = [7, -3, 2, 8], k = 4`  \
  **Explanation:** The subarrays [-3, 2, 8], [2, 8], [8], and [7, -3, 2] have sums divisible by k = 4, resulting in a count of 4.

{{< dots >}}
## Approach 🚀
Use a hashmap to count the frequency of remainders when the running sum is divided by k, leveraging the remainder property to count subarrays.

### Initial Thoughts 💭
- A naive approach of computing the sum for all subarrays would be inefficient for large arrays.
- The problem can be optimized using the property of remainders to identify subarrays with sums divisible by k.
- Using a hashmap to track remainder frequencies allows for efficient subarray counting by leveraging previous results.
{{< dots >}}
### Edge Cases 🌐
- An array with one element and k > 1, ensuring no subarray is divisible.
- An array of maximum length with varying large values, ensuring efficient handling.
- All elements in the array are 0.
- Ensure that negative remainders are handled correctly.
{{< dots >}}
## Code 💻
```cpp
int subarraysDivByK(vector<int>& nums, int k) {
    int res = 0, n = nums.size(), sum = 0;        
    vector<int> frq(k, 0);
    frq[0] = 1;
    for(int j = 0; j < n; j++) {
        sum += nums[j];
        int rm = sum % k;
        if(rm < 0) rm += k;            
        res += frq[rm];
        frq[rm]++;
    }
    return res;
}
```

This function counts the number of subarrays whose sum is divisible by a given integer 'k'. It uses a frequency array to track the modulo of the sum of elements as it iterates through the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int subarraysDivByK(vector<int>& nums, int k) {
	```
	Defines the function `subarraysDivByK`, which takes an integer vector `nums` and an integer `k`, and returns the number of subarrays whose sum is divisible by `k`.

2. **Variable Initialization**
	```cpp
	    int res = 0, n = nums.size(), sum = 0;        
	```
	Initializes variables: `res` to store the result (number of valid subarrays), `n` to store the size of `nums`, and `sum` to accumulate the sum of elements as we iterate.

3. **Frequency Array Declaration**
	```cpp
	    vector<int> frq(k, 0);
	```
	Declares a frequency array `frq` of size `k`, initialized with 0, to keep track of the modulo results of subarray sums.

4. **Initial Frequency Setup**
	```cpp
	    frq[0] = 1;
	```
	Sets `frq[0]` to 1, since a sum of 0 is always divisible by `k`, which allows us to count subarrays starting from the first element.

5. **Loop Over Array**
	```cpp
	    for(int j = 0; j < n; j++) {
	```
	Starts a loop to iterate through each element in the `nums` array.

6. **Update Sum**
	```cpp
	        sum += nums[j];
	```
	Adds the current element `nums[j]` to the running sum `sum`.

7. **Modulo Calculation**
	```cpp
	        int rm = sum % k;
	```
	Calculates the remainder `rm` when the accumulated sum is divided by `k`.

8. **Handle Negative Remainders**
	```cpp
	        if(rm < 0) rm += k;            
	```
	Adjusts the remainder if it's negative by adding `k` to ensure that `rm` is always positive.

9. **Update Result**
	```cpp
	        res += frq[rm];
	```
	Increments the result `res` by the value stored in `frq[rm]`, which represents the count of subarrays whose sum modulo `k` equals `rm`.

10. **Update Frequency Array**
	```cpp
	        frq[rm]++;
	```
	Increments the frequency count of the remainder `rm` in the frequency array `frq`.

11. **Return Statement**
	```cpp
	    return res;
	```
	Returns the result `res`, which contains the total number of subarrays whose sum is divisible by `k`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The array is traversed once, and hashmap operations are O(1) on average.

### Space Complexity 💾
- **Best Case:** O(k)
- **Worst Case:** O(k)

The hashmap stores at most k entries for the remainders.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subarray-sums-divisible-by-k/description/)

---
{{< youtube bcXy-T4Sc3E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
