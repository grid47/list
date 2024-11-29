
+++
authors = ["grid47"]
title = "Leetcode 2541: Minimum Operations to Make Array Equal II"
date = "2024-02-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2541: Minimum Operations to Make Array Equal II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "k9jEPl5tC0s"
youtube_upload_date="2023-01-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/k9jEPl5tC0s/maxresdefault.webp"
comments = true
+++



---
You are given two integer arrays `nums1` and `nums2` of equal length `n` and an integer `k`. You can perform the following operation on `nums1`: Choose two indexes `i` and `j` and increment `nums1[i]` by `k` and decrement `nums1[j]` by `k`. The goal is to determine the minimum number of operations required to make `nums1` equal to `nums2`. If it is impossible, return `-1`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two integer arrays `nums1` and `nums2` of equal length `n` and an integer `k`.
- **Example:** `nums1 = [3, 7, 4], nums2 = [1, 7, 8], k = 2`
- **Constraints:**
	- n == nums1.length == nums2.length
	- 2 <= n <= 10^5
	- 0 <= nums1[i], nums2[i] <= 10^9
	- 0 <= k <= 10^5

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be the minimum number of operations required to make `nums1` equal to `nums2`. If it is impossible, return `-1`.
- **Example:** `2`
- **Constraints:**
	- The result should be an integer or -1 if it is impossible.

{{< dots >}}
### Core Logic 🔍
**Goal:** To transform `nums1` into `nums2` using the fewest number of operations.

- For each index `i`, compute the difference `nums1[i] - nums2[i]`.
- If the difference is not divisible by `k`, return `-1` because it is impossible to reach the target.
- For all valid differences, keep track of the sum of positive differences and negative differences.
- If the sum of differences is not zero, return `-1`.
- Otherwise, return the total number of operations, which is the sum of all positive differences divided by `k`.
{{< dots >}}
### Problem Assumptions ✅
- Both arrays `nums1` and `nums2` are valid and have the same length.
- The array elements are integers within the range of `0` to `10^9`.
{{< dots >}}
## Examples 🧩
- **Input:** `[3, 7, 4], [1, 7, 8], k = 2`  \
  **Explanation:** We can increment `nums1[0]` by 2 and decrement `nums1[2]` by 2 in the first operation. Then, we increment `nums1[2]` by 2 and decrement `nums1[0]` by 2 in the second operation to match `nums2`.

- **Input:** `[3, 6, 2], [2, 5, 1], k = 1`  \
  **Explanation:** It is impossible to make the arrays equal because the differences between corresponding elements are not divisible by `k = 1`.

{{< dots >}}
## Approach 🚀
The approach involves checking whether the differences between corresponding elements of `nums1` and `nums2` are divisible by `k` and whether the sum of differences is zero.

### Initial Thoughts 💭
- If the differences between corresponding elements are not divisible by `k`, the operation cannot be performed.
- The goal is to transform `nums1` into `nums2` with the minimum number of operations by adjusting the elements in pairs.
{{< dots >}}
### Edge Cases 🌐
- The arrays should not be empty, as the minimum length is 2.
- Ensure that the solution works efficiently for arrays with lengths up to 10^5.
- Consider edge cases where `k = 0` and the arrays are already equal.
- The solution must handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
    if(k == 0) {
    for(int i = 0; i < nums1.size(); i++) {
        if(nums1[i] != nums2[i]) return -1;
    }
        return 0;
    }
    for(int i = 0; i < nums1.size(); i++) {
        nums1[i] -= nums2[i];
        if(nums1[i] % k != 0) return -1;
    }
    cout << "hi";
    long long res = 0, sum = 0;
    for(int i = 0; i < nums1.size(); i++) {
        cout << nums1[i] << " ";
        if(nums1[i] > 0) res += nums1[i] / k;
        sum += nums1[i];
    }
    if(sum != 0) return -1;
    return res;
}
```

The function 'minOperations' calculates the minimum number of operations required to convert two integer arrays 'nums1' and 'nums2' into equal arrays using a specified integer 'k'. It checks several conditions and applies operations only if the conditions are met.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
	```
	The function 'minOperations' is defined, which takes two integer vectors, 'nums1' and 'nums2', and an integer 'k'. It returns a long long integer representing the minimum number of operations needed.

2. **Check if k is Zero**
	```cpp
	    if(k == 0) {
	```
	This conditional checks if the value of 'k' is zero. If it is, the algorithm performs a special case check between 'nums1' and 'nums2'.

3. **Loop Through First Array**
	```cpp
	    for(int i = 0; i < nums1.size(); i++) {
	```
	This for loop iterates through each element of 'nums1' to compare with the corresponding element in 'nums2'.

4. **Element Comparison**
	```cpp
	        if(nums1[i] != nums2[i]) return -1;
	```
	If any element at the same index in 'nums1' and 'nums2' are not equal, the function immediately returns -1, indicating that it's not possible to transform the arrays into equal arrays when k = 0.

5. **Return Zero for k = 0**
	```cpp
	        return 0;
	```
	If all elements in 'nums1' and 'nums2' are equal and 'k' is zero, the function returns 0, indicating no operations are needed.

6. **Adjusting nums1**
	```cpp
	    for(int i = 0; i < nums1.size(); i++) {
	```
	This for loop iterates through each element in 'nums1' to adjust the values based on the corresponding values in 'nums2'.

7. **Subtract Elements**
	```cpp
	        nums1[i] -= nums2[i];
	```
	Each element of 'nums2' is subtracted from the corresponding element in 'nums1'. This step prepares the array for further operations.

8. **Check Divisibility by k**
	```cpp
	        if(nums1[i] % k != 0) return -1;
	```
	This conditional checks if the difference between the corresponding elements of 'nums1' and 'nums2' is divisible by 'k'. If it's not, the function returns -1, indicating it's impossible to achieve equality.

9. **Initialize Result Variables**
	```cpp
	    long long res = 0, sum = 0;
	```
	Two long long variables 'res' and 'sum' are initialized to track the result and the sum of elements in 'nums1'.

10. **Loop Through Adjusted nums1**
	```cpp
	    for(int i = 0; i < nums1.size(); i++) {
	```
	A loop is initiated to iterate through the adjusted 'nums1' to calculate the minimum number of operations required.

11. **Debug Output for nums1**
	```cpp
	        cout << nums1[i] << " ";
	```
	This line prints each element of the adjusted 'nums1' to the console for debugging purposes.

12. **Calculate Operations**
	```cpp
	        if(nums1[i] > 0) res += nums1[i] / k;
	```
	If the value in 'nums1' is positive, it is divided by 'k' and added to 'res'. This represents the number of operations required to balance this element.

13. **Update Sum**
	```cpp
	        sum += nums1[i];
	```
	The value of each element in 'nums1' is added to 'sum' to track the total sum of the adjusted 'nums1'.

14. **Check Sum**
	```cpp
	    if(sum != 0) return -1;
	```
	This condition checks if the sum of 'nums1' is not zero. If it's not zero, it means the transformation is not possible, and the function returns -1.

15. **Return Result**
	```cpp
	    return res;
	```
	The function returns the result, 'res', which represents the minimum number of operations required to make the arrays equal.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is linear because we traverse both arrays once.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant because only a few variables are used.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii/description/)

---
{{< youtube k9jEPl5tC0s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
