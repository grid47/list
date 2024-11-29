
+++
authors = ["grid47"]
title = "Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation"
date = "2024-05-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1806: Minimum Number of Operations to Reinitialize a Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "MT7Qo0LmoFo"
youtube_upload_date="2021-03-28"
youtube_thumbnail="https://i.ytimg.com/vi_webp/MT7Qo0LmoFo/maxresdefault.webp"
comments = true
+++



---
You are given an even integer `n` and a permutation `perm` of size `n` where initially `perm[i] = i` (0-indexed). In each operation, you create a new array `arr` based on certain rules and update `perm` to `arr`. The goal is to determine the minimum number of operations required to restore `perm` to its initial state.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an even integer `n` and a permutation `perm` of size `n` where initially `perm[i] = i` (0-indexed).
- **Example:** `n = 4`
- **Constraints:**
	- 2 <= n <= 1000
	- n is even.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of operations required to restore the permutation to its initial state.
- **Example:** `Output: 2`
- **Constraints:**
	- The solution should handle all even integers n within the given range.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum number of operations required to restore the permutation `perm` to its original state.

- Initialize the permutation `perm` as [0, 1, 2, ..., n-1].
- Perform operations to generate a new array `arr` based on the rules described.
- Check if `arr` matches the initial permutation. If not, update `perm` to `arr` and repeat until the match is found.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be an even integer n.
- The permutation `perm` is initially [0, 1, 2, ..., n-1].
{{< dots >}}
## Examples 🧩
- **Input:** `n = 4`  \
  **Explanation:** The initial permutation is `[0, 1, 2, 3]`. After the first operation, the permutation becomes `[0, 2, 1, 3]`. After the second operation, the permutation returns to `[0, 1, 2, 3]`, so it takes 2 operations.

{{< dots >}}
## Approach 🚀
We will simulate the process of performing the operations and count how many operations it takes to return to the original permutation.

### Initial Thoughts 💭
- We need to find a way to efficiently check when the permutation returns to the original state.
- Simulating the operation and checking for equality after each step is a straightforward approach to solve the problem.
{{< dots >}}
### Edge Cases 🌐
- There will always be an input value for `n` which is even.
- For large inputs, the solution should handle the operations efficiently, especially since n can go up to 1000.
- Consider the smallest value of n (n = 2) and ensure the solution works for that edge case.
- The solution should operate efficiently with time complexity proportional to n.
{{< dots >}}
## Code 💻
```cpp
int reinitializePermutation(int n) {
    
    vector<int> prem(n, 0), arr(n, 0);
    
    for(int i = 0; i < n; i++) {
        prem[i] = i;
    }
    int cnt = 1;
    while(1) {
    
        for(int i = 0; i < n; i++) {
            arr[i] = (i % 2) ? prem[n/2 + (i - 1)/2] : prem[i/2];
        }
        
        bool x = false;
        for(int i= 0; i < n; i++)
            if(arr[i] != i) x = true;
        
        if(!x) break;
        
        prem = arr;
        cnt++;
    }
    return cnt;
}
```

The function `reinitializePermutation` performs a series of reinitializations on the input array `prem` based on a specific rule, and returns the number of operations required to revert `prem` to its original state.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int reinitializePermutation(int n) {
	```
	Define the function `reinitializePermutation` which takes an integer `n` representing the size of the array and returns an integer representing the number of reinitializations required.

2. **Variable Initialization**
	```cpp
	    vector<int> prem(n, 0), arr(n, 0);
	```
	Initialize two vectors `prem` and `arr` of size `n` to store the current and new permutation values respectively.

3. **Loop and Recursion**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Start a loop to iterate through all indices of the vector.

4. **Variable Initialization**
	```cpp
	        prem[i] = i;
	```
	Initialize the `prem` array such that each index `i` holds the value `i`.

5. **Variable Initialization**
	```cpp
	    int cnt = 1;
	```
	Initialize the counter variable `cnt` to 1, representing the number of reinitializations performed.

6. **Loop and Recursion**
	```cpp
	    while(1) {
	```
	Start an infinite loop to continuously apply the reinitialization process until the condition is met.

7. **Loop and Recursion**
	```cpp
	        for(int i = 0; i < n; i++) {
	```
	Start a loop to apply the reinitialization rule to each index of the array `arr`.

8. **Mathematical Operations**
	```cpp
	            arr[i] = (i % 2) ? prem[n/2 + (i - 1)/2] : prem[i/2];
	```
	Reinitialize each index of the array `arr` according to a specific rule: if `i` is odd, use the second half of `prem`, otherwise use the first half.

9. **Conditionals**
	```cpp
	        bool x = false;
	```
	Initialize a boolean variable `x` to track whether the array `arr` is different from the original `prem`.

10. **Loop and Recursion**
	```cpp
	        for(int i= 0; i < n; i++)
	```
	Start a loop to compare each index of `arr` to its original value in `prem`.

11. **Conditionals**
	```cpp
	            if(arr[i] != i) x = true;
	```
	If any index in `arr` is not equal to its corresponding index `i`, set `x` to true, indicating that reinitialization is still incomplete.

12. **Flow Control**
	```cpp
	        if(!x) break;
	```
	If `x` remains false (indicating the array is in its final state), break out of the infinite loop.

13. **Variable Initialization**
	```cpp
	        prem = arr;
	```
	Update the `prem` array to match the newly reinitialized `arr` for the next iteration.

14. **Mathematical Operations**
	```cpp
	        cnt++;
	```
	Increment the counter `cnt` to reflect the number of reinitialization steps taken.

15. **Return**
	```cpp
	    return cnt;
	```
	Return the counter `cnt`, which represents the total number of reinitialization steps required.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

Each operation requires O(n) time for generating the new array and checking for equality. The worst-case scenario is when the solution requires multiple operations to restore the original permutation.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the permutation and the intermediate array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/description/)

---
{{< youtube MT7Qo0LmoFo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
