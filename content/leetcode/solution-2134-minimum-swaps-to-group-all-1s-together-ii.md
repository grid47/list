
+++
authors = ["grid47"]
title = "Leetcode 2134: Minimum Swaps to Group All 1's Together II"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2134: Minimum Swaps to Group All 1's Together II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BueoreUIkcE"
youtube_upload_date="2024-08-02"
youtube_thumbnail="https://i.ytimg.com/vi/BueoreUIkcE/maxresdefault.jpg"
comments = true
+++



---
You are given a binary circular array, where each element is either 0 or 1. The goal is to group all the 1's together in the array using the minimum number of swaps. A swap consists of exchanging the values at two distinct positions in the array. The array is circular, meaning the first and last elements are adjacent. Your task is to find the minimum number of swaps required to group all the 1's together.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input is a binary array, which is circular in nature, represented as a list of integers where each element is either 0 or 1.
- **Example:** `nums = [1, 0, 1, 1, 0, 1, 0]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- nums[i] is either 0 or 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an integer representing the minimum number of swaps required to group all the 1's together in the array.
- **Example:** `Input: nums = [1, 0, 1, 1, 0, 1, 0] Output: 1`
- **Constraints:**
	- The solution must be optimal and efficient for large arrays.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to minimize the number of swaps required to group all the 1's together in a circular array.

- 1. Count the total number of 1's in the array.
- 2. Create a doubled array to account for the circular nature of the array.
- 3. Use a sliding window of size equal to the number of 1's to count how many 1's are within each window.
- 4. Find the window with the maximum number of 1's and calculate the number of swaps needed to move the remaining 1's into that window.
{{< dots >}}
### Problem Assumptions ✅
- The input array will always contain at least one element.
- We assume that the input array can be quite large (up to 10^5 elements).
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [1, 0, 1, 1, 0, 1, 0]`  \
  **Explanation:** In this case, the number of 1's is 4. The window of size 4 can be placed in several positions. The window containing the last 4 elements, [1, 1, 0, 1], has 3 ones. We can move one more 1 into this window with just 1 swap, thus the minimum number of swaps is 1.

- **Input:** `Input: nums = [0, 1, 1, 1, 0, 0, 1, 1, 0]`  \
  **Explanation:** Here, there are 5 ones in the array. By applying the sliding window technique, we can find that the minimum swaps required to group all 1's together is 2.

- **Input:** `Input: nums = [1, 1, 0, 0, 1]`  \
  **Explanation:** All the 1's are already grouped together due to the circular property of the array. Thus, no swaps are needed.

{{< dots >}}
## Approach 🚀
The approach involves using a sliding window to efficiently group the 1's together while accounting for the circular nature of the array.

### Initial Thoughts 💭
- A direct approach would involve trying all possible combinations of 1's, but that would be inefficient for large arrays.
- A sliding window is a more optimal way to find the smallest number of swaps needed.
- The key idea is to find the largest window containing the most 1's, then count how many swaps are needed to bring the remaining 1's into this window.
{{< dots >}}
### Edge Cases 🌐
- An empty array is not a valid input as per the problem constraints.
- The solution must handle input arrays of size up to 100,000 efficiently.
- Arrays with all 1's or all 0's should be handled as special cases, as no swaps are needed in these cases.
- The solution should be optimized to run in linear time, O(n), given the constraint that n can be as large as 100,000.
{{< dots >}}
## Code 💻
```cpp
int minSwaps(vector<int>& nums) {
    int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
    ones = count(nums.begin(), nums.end(), 1);
    vector<int> nums2(2 *n);
    for(int i = 0; i < 2 * n; i++)
    nums2[i] = nums[i%n];
    for(int i = 0; i < 2 *n ; i++) {
        if(i >= ones && nums2[i - ones] == 1) x--;
        if(nums2[i] == 1) x++;
        onesInWindows = max(x, onesInWindows);
    }
    return ones - onesInWindows;
}
```

This function calculates the minimum number of swaps required to group all the 1's together in a circular binary array. It uses a sliding window technique to find the maximum number of 1's that can fit into a window of size equal to the total number of 1's in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minSwaps(vector<int>& nums) {
	```
	The function `minSwaps` takes a reference to a vector of integers `nums`, representing a binary array, and returns the minimum number of swaps needed to group all the 1's together.

2. **Variable Declaration**
	```cpp
	    int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
	```
	This line declares and initializes the variables: `ones` to count the number of 1's, `x` for the current count of 1's in the window, `onesInWindows` for the maximum number of 1's in the window, `i` as the loop counter, and `n` to store the size of the input array `nums`.

3. **Operation**
	```cpp
	    ones = count(nums.begin(), nums.end(), 1);
	```
	This line counts the total number of 1's in the array `nums` using the `count` function and stores it in `ones`.

4. **Vector Initialization**
	```cpp
	    vector<int> nums2(2 *n);
	```
	A new vector `nums2` of size `2*n` is created to simulate a circular array by repeating the original array `nums`.

5. **Loop**
	```cpp
	    for(int i = 0; i < 2 * n; i++)
	```
	A loop to populate the `nums2` vector with the elements of `nums` repeated twice. This helps to simulate the circular nature of the array.

6. **Operation**
	```cpp
	    nums2[i] = nums[i%n];
	```
	Each element of `nums2` is assigned the corresponding element from `nums`, using the modulus operation to ensure it wraps around when `i` exceeds the length of `nums`.

7. **Loop**
	```cpp
	    for(int i = 0; i < 2 *n ; i++) {
	```
	This loop iterates through the `nums2` array to calculate the number of 1's in the sliding window of size `ones`.

8. **Condition**
	```cpp
	        if(i >= ones && nums2[i - ones] == 1) x--;
	```
	If the current index `i` is greater than or equal to the window size `ones`, and the element at position `i - ones` is a 1, we decrement `x` as it falls out of the window.

9. **Condition**
	```cpp
	        if(nums2[i] == 1) x++;
	```
	If the current element `nums2[i]` is 1, we increment `x`, as it is part of the current window.

10. **Operation**
	```cpp
	        onesInWindows = max(x, onesInWindows);
	```
	This updates `onesInWindows` to the maximum value between `x` (the current count of 1's in the window) and the previous value of `onesInWindows`.

11. **Return**
	```cpp
	    return ones - onesInWindows;
	```
	The function returns the difference between `ones` (total number of 1's) and `onesInWindows` (the maximum number of 1's found in the sliding window), which is the minimum number of swaps needed.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) due to the sliding window approach and the linear traversal of the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the need for a doubled array to handle the circular nature of the input.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/)

---
{{< youtube BueoreUIkcE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
