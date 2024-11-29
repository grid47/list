
+++
authors = ["grid47"]
title = "Leetcode 2537: Count the Number of Good Subarrays"
date = "2024-02-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2537: Count the Number of Good Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "X4wzXCe1wvs"
youtube_upload_date="2023-01-15"
youtube_thumbnail="https://i.ytimg.com/vi_webp/X4wzXCe1wvs/maxresdefault.webp"
comments = true
+++



---
Given an integer array `nums` and an integer `k`, return the number of "good" subarrays. A subarray is good if it contains at least `k` pairs of indices `(i, j)` such that `i < j` and `nums[i] == nums[j]`. A subarray is a contiguous non-empty sequence of elements within the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` and an integer `k`. The task is to count how many subarrays satisfy the good subarray condition.
- **Example:** `nums = [5, 2, 7, 5, 3, 3, 7], k = 2`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 1 <= nums[i], k <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the number of good subarrays that meet the condition of containing at least `k` pairs of equal elements.
- **Example:** `4`
- **Constraints:**
	- The result should be an integer indicating the number of good subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** Efficiently count the number of good subarrays by checking the number of valid pairs for each subarray.

- Iterate through the array and for each subarray, count how many pairs of equal elements exist.
- Use a map to track the frequency of each element, then calculate how many pairs can be formed from these frequencies.
- Count the number of subarrays that have at least `k` pairs.
{{< dots >}}
### Problem Assumptions ✅
- The input array `nums` is always valid and non-empty.
- The value of `k` is always a positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `[5, 2, 7, 5, 3, 3, 7], k = 2`  \
  **Explanation:** In this example, there are 4 different subarrays that contain at least 2 pairs of equal elements.

- **Input:** `[2, 2, 2, 2, 2], k = 10`  \
  **Explanation:** In this example, the only good subarray is the entire array itself, which has exactly 10 pairs.

{{< dots >}}
## Approach 🚀
The approach involves calculating the number of pairs of equal elements in each subarray and checking if it meets the threshold `k`.

### Initial Thoughts 💭
- The number of good subarrays depends on the number of pairs formed by equal elements.
- By tracking the frequency of each element as we iterate through the array, we can count the pairs efficiently.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least one element.
- Ensure the algorithm can handle arrays with up to 10^5 elements efficiently.
- Handle cases where `k` is large relative to the number of elements in the array.
- The solution should avoid brute force techniques, as they would be inefficient for large arrays.
{{< dots >}}
## Code 💻
```cpp
long long countGood(vector<int>& nums, int k) {
    long long res = 0, tmp = 0;
    
    int n = nums.size();
    
    map<int, int> mp, cnt;
    
    int j = 0;
    for(int i = 0; i < n; i++) {
        tmp += (cnt[nums[i]]);
        cnt[nums[i]]++;            
        while(j <= i && tmp >= k) {
            res+= (n - i);
            cnt[nums[j]]--;
            tmp -= cnt[nums[j]];
            j++;
        }
    }
    return res;
}
```

The function 'countGood' counts the number of subarrays with a certain property based on the input array and an integer k. It uses a sliding window approach to count good subarrays where the frequency condition is satisfied.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long countGood(vector<int>& nums, int k) {
	```
	The function 'countGood' is defined, which takes a vector of integers 'nums' and an integer 'k' as input and returns a long long result.

2. **Variable Initialization**
	```cpp
	    long long res = 0, tmp = 0;
	```
	Two variables 'res' and 'tmp' are initialized to 0. 'res' will store the count of good subarrays, and 'tmp' tracks the frequency condition within the sliding window.

3. **Array Size**
	```cpp
	    int n = nums.size();
	```
	The variable 'n' is set to the size of the input array 'nums'.

4. **Map Initialization**
	```cpp
	    map<int, int> mp, cnt;
	```
	Two maps, 'mp' and 'cnt', are initialized. 'mp' will be used for storing elements of the array (though it's not used in this code), and 'cnt' will track the frequency of elements within the sliding window.

5. **Pointer Initialization**
	```cpp
	    int j = 0;
	```
	The pointer 'j' is initialized to 0. It represents the left boundary of the sliding window.

6. **Outer Loop**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	An outer loop starts from 'i = 0' to 'i < n', iterating over each element of the 'nums' array.

7. **Frequency Update**
	```cpp
	        tmp += (cnt[nums[i]]);
	```
	The variable 'tmp' is updated by adding the current frequency of 'nums[i]' from the 'cnt' map. This tracks the frequency condition within the window.

8. **Count Update**
	```cpp
	        cnt[nums[i]]++;            
	```
	The frequency count of the current element 'nums[i]' is incremented in the 'cnt' map.

9. **Inner Loop Condition**
	```cpp
	        while(j <= i && tmp >= k) {
	```
	A while loop is initiated as long as the frequency condition 'tmp >= k' holds, and the left pointer 'j' is less than or equal to the right pointer 'i'.

10. **Result Update**
	```cpp
	            res += (n - i);
	```
	The result variable 'res' is updated by adding the count of valid subarrays from 'i' to the end of the array. This is part of the sliding window approach.

11. **Count Decrease**
	```cpp
	            cnt[nums[j]]--;
	```
	The frequency of the element 'nums[j]' at the left boundary of the sliding window is decreased in the 'cnt' map.

12. **Frequency Decrease**
	```cpp
	            tmp -= cnt[nums[j]];
	```
	The variable 'tmp' is updated by subtracting the updated frequency of 'nums[j]', reflecting the change in the window's frequency condition.

13. **Pointer Increment**
	```cpp
	            j++;
	```
	The left boundary pointer 'j' is incremented to shrink the window.

14. **Return Result**
	```cpp
	    return res;
	```
	The function returns the final result 'res', which is the count of all valid subarrays that meet the frequency condition.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to a single pass through the array and efficient use of a map to track frequencies.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the frequencies of elements in a map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-good-subarrays/description/)

---
{{< youtube X4wzXCe1wvs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
