
+++
authors = ["grid47"]
title = "Leetcode 2090: K Radius Subarray Averages"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2090: K Radius Subarray Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rdKE6yZ_D3A"
youtube_upload_date="2021-11-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rdKE6yZ_D3A/maxresdefault.webp"
comments = true
+++



---
Given an array of integers, you need to compute the k-radius average for each element in the array. The k-radius average for an element at index i is the average of the elements from index i - k to i + k (inclusive). If there are fewer than k elements before or after the index i, the result for that index will be -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums and an integer k.
- **Example:** `nums = [7,4,3,9,1,8,5,2,6], k = 3`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= k <= 10^5
	- -10^9 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array of integers where each element is the k-radius average for the corresponding index in the input array.
- **Example:** `Output: [-1,-1,-1,5,4,4,-1,-1,-1]`
- **Constraints:**
	- The length of the output array is the same as the input array.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the k-radius average for each index in the array.

- Initialize an array to store prefix sums of the input array.
- For each index, check if there are enough elements to the left and right to calculate the k-radius average.
- If there are enough elements, compute the sum of the subarray and calculate the integer division of the sum by the total number of elements.
- If there are not enough elements, set the result for that index to -1.
{{< dots >}}
### Problem Assumptions ✅
- The array may contain both large positive and negative integers.
- The function should be optimized for large inputs.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1,2,3,4,5], k = 2`  \
  **Explanation:** The k-radius average for index 2 is calculated using elements from index 0 to index 4. The sum is 15, so the average is 15 // 5 = 3.

{{< dots >}}
## Approach 🚀
We calculate the prefix sum of the array to efficiently compute the sum of elements in any subarray. We use this to determine the k-radius average for each index.

### Initial Thoughts 💭
- We need to calculate the sum of elements in a subarray for each index.
- Using a prefix sum array will allow us to compute the sum of any subarray in constant time.
{{< dots >}}
### Edge Cases 🌐
- Handle the case where nums is empty.
- Ensure that the solution handles large arrays efficiently.
- When k is 0, the k-radius average for each index is just the element itself.
- Handle large values of k and nums size efficiently.
{{< dots >}}
## Code 💻
```cpp
vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long> psum(n, 0);
    vector<int> avg(n, 0);
    psum[0] = nums[0];
    for(int i = 1; i < n; i++)
        psum[i] = psum[i - 1] + nums[i];
    
    for(int i = 0; i < n; i++) {
        if(i - k < 0 || i + k >= n) {
            avg[i] = -1;
        } else {
            avg[i] = (psum[i + k] - ((i - k) == 0? 0: psum[i - k - 1])) / (2 * k + 1);
        }
    }
    return avg;
}
```

This function `getAverages` computes the moving averages of elements in the `nums` array within a window of size `2k+1`. If the window is out of bounds for an element, it returns `-1` for that position.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> getAverages(vector<int>& nums, int k) {
	```
	This defines the `getAverages` function that takes a reference to a vector `nums` and an integer `k` as input parameters, and returns a vector of integers.

2. **Variable Declaration**
	```cpp
	    int n = nums.size();
	```
	This declares an integer `n` that stores the size of the `nums` vector.

3. **Variable Initialization**
	```cpp
	    vector<long> psum(n, 0);
	```
	This initializes a vector `psum` of size `n` to store the prefix sums of the `nums` array, initialized to 0.

4. **Variable Initialization**
	```cpp
	    vector<int> avg(n, 0);
	```
	This initializes a vector `avg` of size `n` to store the averages of the moving window, initialized to 0.

5. **Prefix Sum Calculation**
	```cpp
	    psum[0] = nums[0];
	```
	This sets the first element of the `psum` vector to be equal to the first element of the `nums` vector.

6. **Prefix Sum Calculation**
	```cpp
	    for(int i = 1; i < n; i++)
	```
	This starts a loop from the second element to the last element of the `nums` vector to calculate the prefix sum.

7. **Prefix Sum Calculation**
	```cpp
	        psum[i] = psum[i - 1] + nums[i];
	```
	This calculates the prefix sum for the `i`-th element by adding the `i`-th element of `nums` to the previous prefix sum.

8. **Window Calculation**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	This starts a loop to calculate the moving average for each element in the `nums` vector.

9. **Boundary Check**
	```cpp
	        if(i - k < 0 || i + k >= n) {
	```
	This checks if the current index `i` is within the valid window range, i.e., the window `[i-k, i+k]` must be within bounds.

10. **Assignment**
	```cpp
	            avg[i] = -1;
	```
	If the window is out of bounds for the current index `i`, it assigns `-1` to the corresponding position in the `avg` vector.

11. **Window Calculation**
	```cpp
	        } else {
	```
	This handles the case where the current index `i` is within the valid window range.

12. **Averaging**
	```cpp
	            avg[i] = (psum[i + k] - ((i - k) == 0? 0: psum[i - k - 1])) / (2 * k + 1);
	```
	This calculates the average for the window centered at `i`. It subtracts the appropriate prefix sums to get the sum of elements in the window and divides by the window size `2k + 1`.

13. **Return Statement**
	```cpp
	    return avg;
	```
	This returns the vector `avg`, which contains the moving averages (or `-1` for out-of-bounds windows).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the array.
- **Average Case:** O(n), since we only iterate over the array once for prefix sums and once for calculating the averages.
- **Worst Case:** O(n), the time complexity remains linear.

The time complexity is linear because we iterate over the array twice: once to calculate the prefix sum, and once to compute the averages.

### Space Complexity 💾
- **Best Case:** O(n), since both the prefix sum and result arrays are of size n.
- **Worst Case:** O(n) space for the prefix sum array and the result array.

The space complexity is linear due to the storage of the prefix sum and the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/k-radius-subarray-averages/description/)

---
{{< youtube rdKE6yZ_D3A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
