
+++
authors = ["grid47"]
title = "Leetcode 1652: Defuse the Bomb"
date = "2024-05-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1652: Defuse the Bomb in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "r81OUfKmGtM"
youtube_upload_date="2020-11-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/r81OUfKmGtM/maxresdefault.webp"
comments = true
+++



---
You are given a circular array 'code' and an integer 'k'. To decrypt the code, you must replace every element in the array based on the value of k. If k > 0, replace the i-th element with the sum of the next k elements. If k < 0, replace the i-th element with the sum of the previous k elements. If k == 0, replace the i-th element with 0. The array is circular, meaning the next element of the last one is the first, and the previous element of the first one is the last.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An array of integers representing the encrypted code and an integer representing the decryption key k.
- **Example:** `code = [4, 6, 3, 7], k = 2`
- **Constraints:**
	- 1 <= n <= 100
	- 1 <= code[i] <= 100
	- -(n - 1) <= k <= n - 1

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array where each element is replaced according to the decryption rules based on k.
- **Example:** `Output: [13, 11, 13, 13]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To efficiently replace each element in the array based on the value of k, considering the circular nature of the array.

- Check if k is zero, if so return an array of zeros.
- If k > 0, for each element in the array, sum the next k elements (consider the circular nature).
- If k < 0, for each element in the array, sum the previous k elements (consider the circular nature).
- Return the resulting array after all replacements.
{{< dots >}}
### Problem Assumptions ✅
- The input will always contain valid values for code and k.
{{< dots >}}
## Examples 🧩
- **Input:** `code = [4, 6, 3, 7], k = 2`  \
  **Explanation:** We sum the next k elements for each element in the array, taking care of the circular behavior where elements wrap around.

{{< dots >}}
## Approach 🚀
The approach involves iterating through the array and applying the sum rule based on k for each element, handling the circular nature of the array with modular arithmetic.

### Initial Thoughts 💭
- We need to consider both positive and negative values of k, and ensure that the array is treated as circular.
- The modulo operator can help in wrapping the indices around when summing elements beyond the boundaries of the array.
{{< dots >}}
### Edge Cases 🌐
- Ensure the solution handles arrays with one element.
- Ensure the solution works within the constraints when n is at its maximum value.
- Handle the case where k == 0 by returning an array of zeros.
- The array must always have a size between 1 and 100.
{{< dots >}}
## Code 💻
```cpp
vector<int> decrypt(vector<int>& code, int k) {
    
    int n = code.size();
    vector<int> ans(n, 0);
    
    if(k == 0) return ans;
    
    int sum = 0;
    if(k > 0) {
        for(int i = 1; i < k + 1; i++)
            sum += code[i];
        ans[0] = sum;
        for(int i = 1; i < n; i++) {
            sum += code[(i + k) % n];
            sum -= code[i];
            ans[i] = sum;
        }
        return ans;
    }

    for(int i = 0; i < abs(k); i++)
        sum += code[n - 1 - i];
    ans[0] = sum;
    for(int i = 1; i < n; i++) {
        sum += code[i - 1];
        sum -= code[(i - 1 - abs(k) + n) % n];
        ans[i] = sum;
    }
    return ans;        
    
}
```

This function calculates a new array based on the input array and the given integer k. The logic is based on summing elements in either direction depending on k's sign.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> decrypt(vector<int>& code, int k) {
	```
	Declares the decrypt function that takes an array and an integer k.

2. **Variable Initialization**
	```cpp
	    int n = code.size();
	```
	Calculates the size of the input array.

3. **Variable Initialization**
	```cpp
	    vector<int> ans(n, 0);
	```
	Initializes the answer array with zeros.

4. **Conditional Statement**
	```cpp
	    if(k == 0) return ans;
	```
	Handles the special case where k is zero, returning a zero-filled array.

5. **Variable Initialization**
	```cpp
	    int sum = 0;
	```
	Initializes a variable to store the sum of elements.

6. **Conditional Statement**
	```cpp
	    if(k > 0) {
	```
	Begins processing for positive values of k.

7. **Loop**
	```cpp
	        for(int i = 1; i < k + 1; i++)
	```
	Iterates over the first k elements after the current element.

8. **Sum Calculation**
	```cpp
	            sum += code[i];
	```
	Adds the value of the current element to the sum.

9. **Array Assignment**
	```cpp
	        ans[0] = sum;
	```
	Stores the initial sum in the answer array.

10. **Loop**
	```cpp
	        for(int i = 1; i < n; i++) {
	```
	Iterates through the array to compute sums for each position.

11. **Sum Adjustment**
	```cpp
	            sum += code[(i + k) % n];
	```
	Adds the next element in the k range to the sum.

12. **Sum Adjustment**
	```cpp
	            sum -= code[i];
	```
	Removes the element that goes out of the k range from the sum.

13. **Array Assignment**
	```cpp
	            ans[i] = sum;
	```
	Stores the computed sum for the current position in the answer array.

14. **Return Statement**
	```cpp
	        return ans;
	```
	Returns the computed answer array.

15. **Loop**
	```cpp
	    for(int i = 0; i < abs(k); i++)
	```
	Iterates over the last k elements for negative k.

16. **Sum Calculation**
	```cpp
	        sum += code[n - 1 - i];
	```
	Adds the value of the current element to the sum for negative k.

17. **Array Assignment**
	```cpp
	    ans[0] = sum;
	```
	Stores the initial sum for negative k in the answer array.

18. **Loop**
	```cpp
	    for(int i = 1; i < n; i++) {
	```
	Iterates through the array for sums with negative k.

19. **Sum Adjustment**
	```cpp
	        sum += code[i - 1];
	```
	Adds the next element to the sum for negative k.

20. **Sum Adjustment**
	```cpp
	        sum -= code[(i - 1 - abs(k) + n) % n];
	```
	Removes the element going out of the range for negative k.

21. **Array Assignment**
	```cpp
	        ans[i] = sum;
	```
	Stores the computed sum for the current position in the answer array.

22. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the computed answer array for negative k.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we iterate over the array once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the array we create to store the result.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/defuse-the-bomb/description/)

---
{{< youtube r81OUfKmGtM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
