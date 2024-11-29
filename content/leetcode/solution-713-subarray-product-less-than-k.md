
+++
authors = ["grid47"]
title = "Leetcode 713: Subarray Product Less Than K"
date = "2024-08-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 713: Subarray Product Less Than K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sliding Window","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/713.webp"
youtube = "Cg6_nF7YIks"
youtube_upload_date="2024-03-27"
youtube_thumbnail="https://i.ytimg.com/vi/Cg6_nF7YIks/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/713.webp" 
    alt="An array of numbers where subarrays with products less than K are highlighted and softly glowing."
    caption="Solution to LeetCode 713: Subarray Product Less Than K Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of integers `nums` and an integer `k`, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than `k`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of integers and an integer `k`.
- **Example:** `nums = [3, 4, 1, 2], k = 20`
- **Constraints:**
	- 1 <= nums.length <= 3 * 10^4
	- 1 <= nums[i] <= 1000
	- 0 <= k <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the count of contiguous subarrays whose product of elements is strictly less than `k`.
- **Example:** `6`
- **Constraints:**
	- The result should be a non-negative integer representing the count of subarrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently calculate the number of contiguous subarrays with product less than `k`.

- Use a sliding window technique to iterate through the array.
- Maintain a product variable to store the product of the current subarray.
- If the product exceeds `k`, move the left boundary of the window to reduce the product.
- For each valid window, the number of subarrays ending at the current position is added to the result.
{{< dots >}}
### Problem Assumptions ✅
- The array contains positive integers and `k` is a non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [3, 4, 1, 2], k = 20`  \
  **Explanation:** The subarrays [3], [4], [1], [2], [3, 4], and [4, 1] have products less than 20, totaling 6 valid subarrays.

- **Input:** `nums = [1, 1, 1], k = 5`  \
  **Explanation:** All possible subarrays in this case have products less than 5, so the output is 6.

{{< dots >}}
## Approach 🚀
The problem can be solved efficiently using a sliding window technique to track the product of elements in subarrays.

### Initial Thoughts 💭
- Using a brute force approach by checking all possible subarrays would be too slow for large arrays.
- A sliding window approach can help reduce the time complexity.
- We will use a window where the product of the elements is maintained dynamically, updating it as the window slides over the array.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return 0.
- Ensure the solution works efficiently for large arrays, up to the size constraint of 30,000.
- If `k` is 0, the result should be 0 as no subarray can have a product less than 0.
- Handle cases where `k` is very large or very small relative to the elements in the array.
{{< dots >}}
## Code 💻
```cpp
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k == 0) return 0;
    long long prod = 1;
    int res = 0, j = 0;
    for(int i = 0; i < nums.size(); i++) {
        prod *= nums[i];
        
        while(prod >= k && j <= i) {
            prod /= nums[j++];
        }
        
        res += (i - j + 1);
    }
    return res;
}
```

The function calculates the number of contiguous subarrays whose product of elements is less than a given value 'k' using the sliding window technique.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	```
	Define the function 'numSubarrayProductLessThanK' which takes a vector of integers 'nums' and an integer 'k'.

2. **Edge Case Handling**
	```cpp
	    if(k == 0) return 0;
	```
	Handle the edge case where 'k' is 0, in which case no subarray product can be less than 0, thus return 0.

3. **Variable Initialization**
	```cpp
	    long long prod = 1;
	```
	Initialize the product variable 'prod' to 1. This will hold the product of elements in the current subarray.

4. **Variable Initialization**
	```cpp
	    int res = 0, j = 0;
	```
	Initialize 'res' to store the result (number of valid subarrays) and 'j' as the starting index of the sliding window.

5. **Loop**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	Loop through each element in the 'nums' array using the variable 'i' as the end index of the sliding window.

6. **Product Calculation**
	```cpp
	        prod *= nums[i];
	```
	Multiply the current element 'nums[i]' with the running product 'prod'.

7. **Sliding Window Adjustment**
	```cpp
	        
	```
	Check and adjust the sliding window if the product exceeds 'k'.

8. **While Loop**
	```cpp
	        while(prod >= k && j <= i) {
	```
	While the product exceeds or equals 'k', move the starting index 'j' to the right to reduce the product.

9. **Window Shrinking**
	```cpp
	            prod /= nums[j++];
	```
	Divide the product by 'nums[j]' (the element at the starting index), and increment 'j' to shrink the window.

10. **Counting Valid Subarrays**
	```cpp
	        res += (i - j + 1);
	```
	For each valid subarray (where the product is less than 'k'), add the number of valid subarrays in the current window to 'res'.

11. **Return Statement**
	```cpp
	    return res;
	```
	Return the total count of valid subarrays whose product is less than 'k'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we process each element once while adjusting the window, making the time complexity linear.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The solution uses constant space, only requiring a few variables to maintain the window and the count.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/subarray-product-less-than-k/description/)

---
{{< youtube Cg6_nF7YIks >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
