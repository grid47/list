
+++
authors = ["grid47"]
title = "Leetcode 2221: Find Triangular Sum of an Array"
date = "2024-03-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2221: Find Triangular Sum of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation","Combinatorics"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "K-IoQp07D8c"
youtube_upload_date="2022-04-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/K-IoQp07D8c/maxresdefault.webp"
comments = true
+++



---
You are given a 0-indexed integer array `nums`, where each element is a digit between 0 and 9. The triangular sum of `nums` is computed by repeatedly reducing the array by replacing each element with the sum of two consecutive elements, modulo 10. This process continues until only one element remains, which is the triangular sum. Your task is to return the triangular sum of the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums`, where each element is a digit between 0 and 9.
- **Example:** `nums = [3, 7, 4, 9, 1]`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 0 <= nums[i] <= 9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the triangular sum of the array `nums`.
- **Example:** `Output: 5`
- **Constraints:**
	- The array will always have at least one element.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to compute the triangular sum of the array `nums` by applying the given process until one element remains.

- Start with the input array `nums`.
- While the array has more than one element, create a new array by replacing each element with the sum of two consecutive elements, modulo 10.
- Repeat the process until only one element remains, which will be the triangular sum.
{{< dots >}}
### Problem Assumptions ✅
- The array will always contain at least one element.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 7, 4, 9, 1]`  \
  **Explanation:** The triangular sum is computed as follows: First, compute the sums of consecutive elements modulo 10: [3+7, 7+4, 4+9, 9+1] = [0, 1, 3, 0]. Then compute the sums of consecutive elements in this new array: [0+1, 1+3, 3+0] = [1, 4, 3]. Finally, compute the sum of the remaining elements: [1+4] = [5]. Hence, the triangular sum is 5.

- **Input:** `Input: nums = [5]`  \
  **Explanation:** Since there is only one element in the array, the triangular sum is the value of that element itself, which is 5.

{{< dots >}}
## Approach 🚀
The approach involves repeatedly reducing the array `nums` by applying the modulo 10 sum of consecutive elements until only one element remains, which is the triangular sum.

### Initial Thoughts 💭
- Each reduction step generates a new array that is shorter by one element.
- Modulo 10 operation ensures that the values remain within the range of a single digit.
- This is a straightforward problem that can be solved with a loop that continuously reduces the array until only one element is left.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one element in the input array, so there are no empty arrays to consider.
- The solution should efficiently handle arrays with up to 1000 elements.
- If the array has only one element, the triangular sum is the element itself.
- The problem must handle arrays with elements ranging from 0 to 9.
{{< dots >}}
## Code 💻
```cpp
int triangularSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> arr(n, 0);        
    for(int i = n; i > 1; i--) {
        int k = i - 1;
        for(int j = k - 1; j >= 0; j--)
            arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
        
        nums = arr;
    }
    
    return nums[0];
}
```

The function `triangularSum` calculates a triangular sum of a list of integers. In each iteration, it reduces the array by calculating the sum of adjacent elements modulo 10, and then repeats this process until only one element remains.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int triangularSum(vector<int>& nums) {
	```
	This is the function declaration for `triangularSum`, which takes a vector of integers `nums` and returns an integer representing the final triangular sum.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	The size of the input vector `nums` is stored in the variable `n`, which represents the number of elements in the array.

3. **Array Initialization**
	```cpp
	    vector<int> arr(n, 0);
	```
	A new vector `arr` of size `n` is created and initialized with zeros. This vector will hold intermediate results during the iteration.

4. **Outer Loop**
	```cpp
	    for(int i = n; i > 1; i--) {
	```
	An outer loop is used to iterate through the array, reducing the size of the array in each step. The loop runs as long as the size of the array is greater than 1.

5. **Index Calculation**
	```cpp
	        int k = i - 1;
	```
	The variable `k` is used to store the current index for the inner loop, which will process elements up to the `i-1` position.

6. **Inner Loop**
	```cpp
	        for(int j = k - 1; j >= 0; j--)
	```
	An inner loop is used to iterate through the array and calculate the new values for `arr[j]` by summing adjacent elements from the original `nums` array.

7. **Element Calculation**
	```cpp
	            arr[j] = (nums[j] % 10 + nums[j + 1] % 10) % 10;
	```
	In this step, the adjacent elements `nums[j]` and `nums[j + 1]` are summed modulo 10 and stored in `arr[j]` to create the new triangular sum.

8. **Empty Line**
	```cpp
	        
	```
	An empty line used for separation of code logic.

9. **Update Vector**
	```cpp
	        nums = arr;
	```
	The updated vector `arr` is assigned to `nums` so that it will be used in the next iteration of the outer loop.

10. **Return Final Result**
	```cpp
	    return nums[0];
	```
	The function returns the final value from the `nums` array, which represents the triangular sum after all iterations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the input array, as each reduction step involves iterating through the array.
- **Average Case:** O(n), as each reduction step takes linear time.
- **Worst Case:** O(n^2), as the number of iterations grows with the length of the array.

The time complexity is linear in the number of elements in the array, but the process repeats for multiple iterations.

### Space Complexity 💾
- **Best Case:** O(n), as we always need to store the array at each step.
- **Worst Case:** O(n), as a new array is created in each iteration, requiring O(n) space.

The space complexity is O(n), where n is the length of the input array, as we need to store intermediate arrays.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-triangular-sum-of-an-array/description/)

---
{{< youtube K-IoQp07D8c >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
