
+++
authors = ["grid47"]
title = "Leetcode 2572: Count the Number of Square-Free Subsets"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2572: Count the Number of Square-Free Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rT4w58kX818"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rT4w58kX818/maxresdefault.webp"
comments = true
+++



---
You are given a positive integer array nums. A subset of the array nums is square-free if the product of its elements is a square-free integer. A square-free integer is an integer that is not divisible by any perfect square other than 1. Return the number of square-free non-empty subsets of the array nums. Since the answer may be too large, return it modulo 10^9 + 7.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array nums where 1 <= nums.length <= 1000 and 1 <= nums[i] <= 30.
- **Example:** `For example, nums = [6, 7, 8].`
- **Constraints:**
	- 1 <= nums.length <= 1000
	- 1 <= nums[i] <= 30

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the number of square-free non-empty subsets of the array nums. The result must be returned modulo 10^9 + 7.
- **Example:** `For nums = [6, 7, 8], the output is 4.`
- **Constraints:**
	- The result should be an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to count the number of non-empty subsets of nums where the product of the elements is square-free.

- 1. First, determine which numbers in nums have prime factorization with no square factors.
- 2. Use dynamic programming to explore all possible subsets, ensuring that the product of the elements is square-free at each step.
- 3. Track the valid square-free subsets and their counts.
{{< dots >}}
### Problem Assumptions ✅
- The input array nums will always contain positive integers.
- Subsets should not be empty, and the result should be computed modulo 10^9 + 7.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums = [6, 7, 8], the output is 4.`  \
  **Explanation:** We identify the square-free subsets, [6], [7], [6, 7], and [8]. The total count of square-free subsets is 4.

{{< dots >}}
## Approach 🚀
This approach uses dynamic programming to count the valid square-free subsets by iterating through all subsets and checking if their product is square-free.

### Initial Thoughts 💭
- The key observation is that any number divisible by a square is not square-free, so we need to exclude such subsets.
- We can represent each subset by its prime factorization mask and dynamically compute the result.
- Dynamic programming allows us to efficiently keep track of subsets and their corresponding masks to check square-freeness.
{{< dots >}}
### Edge Cases 🌐
- nums will always contain at least one element, as per the problem constraints.
- Ensure that the solution efficiently handles arrays with 1000 elements.
- When nums contains repeated elements, make sure subsets are counted correctly without duplication.
- Consider the modulus operation to handle large outputs.
{{< dots >}}
## Code 💻
```cpp
int mod = (int) 1e9 + 7, n;
vector<int> nums, prime;
int memo[1001][1 << 11];

int getMask(int num) {
    int mask = 0;
    for(int i= 0; i < prime.size(); i++) {
        int cnt = 0;
        while(num % prime[i] == 0) {
            cnt++;
            num /= prime[i];
        }
        if(cnt > 1) return -1;
        if(cnt == 1) {
            mask |= (1 << (i + 1));                
        }
    }
    return mask;
}    

int dp(int idx, int mask) {
    if(idx == n) return 1;

    if(memo[idx][mask] != -1) return memo[idx][mask];        
    int ans = dp(idx + 1, mask);

    int nmask = getMask(nums[idx]);
    if((nmask != -1) && ((nmask & mask) == 0)) {
        ans = (ans + dp(idx + 1, nmask | mask)) % mod;
    }
    return memo[idx][mask] = ans;
}

int squareFreeSubsets(vector<int>& nums) {
    n = nums.size();
    this->nums = nums;
    prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    memset(memo, -1, sizeof memo);
    return (dp(0, 0) - 1 + mod) % mod;
}
```

This is the complete code for the problem. It defines a dynamic programming solution for finding square-free subsets of a given set of numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	int mod = (int) 1e9 + 7, n;
	```
	Initialize the modulo constant to 10^9 + 7 and declare the integer variable 'n' for the size of the input array.

2. **Variable Initialization**
	```cpp
	vector<int> nums, prime;
	```
	Declare vectors 'nums' to store the input numbers and 'prime' to store a list of prime numbers used in the algorithm.

3. **Dynamic Programming**
	```cpp
	int memo[1001][1 << 11];
	```
	Declare a memoization table 'memo' to store intermediate results of subproblems. The table has dimensions based on the number of elements and bitmask size.

4. **Function Definition**
	```cpp
	int getMask(int num) {
	```
	Define the function 'getMask' that generates a bitmask representing the prime factorization of a number.

5. **Function Implementation**
	```cpp
	    int mask = 0;
	```
	Initialize a variable 'mask' to store the bitmask result.

6. **Loop**
	```cpp
	    for(int i= 0; i < prime.size(); i++) {
	```
	Loop through the list of prime numbers to calculate the bitmask.

7. **Counter**
	```cpp
	        int cnt = 0;
	```
	Initialize a counter 'cnt' to track the number of times a prime divides the number.

8. **Loop**
	```cpp
	        while(num % prime[i] == 0) {
	```
	While the number is divisible by the current prime, increment the counter and divide the number.

9. **Counter Update**
	```cpp
	            cnt++;
	```
	Increment the counter 'cnt' for each division by the current prime.

10. **Number Modification**
	```cpp
	            num /= prime[i];
	```
	Divide the number by the current prime to remove the prime factor.

11. **Condition Check**
	```cpp
	        if(cnt > 1) return -1;
	```
	If the prime factor appears more than once, return -1 indicating it's not a square-free factor.

12. **Bitmask Update**
	```cpp
	        if(cnt == 1) {
	```
	If the prime appears exactly once, update the bitmask.

13. **Bitmask Update**
	```cpp
	            mask |= (1 << (i + 1));                
	```
	Set the corresponding bit in the mask for the current prime.

14. **Return Statement**
	```cpp
	    return mask;
	```
	Return the generated bitmask representing the prime factorization of the number.

15. **Function Definition**
	```cpp
	int dp(int idx, int mask) {
	```
	Define the dynamic programming function 'dp' to calculate the number of square-free subsets.

16. **Base Case**
	```cpp
	    if(idx == n) return 1;
	```
	Base case: If the index is equal to the number of elements, return 1 as a valid subset.

17. **Memoization Check**
	```cpp
	    if(memo[idx][mask] != -1) return memo[idx][mask];        
	```
	Check if the result is already computed in the memoization table. If yes, return the stored value.

18. **Recursive Call**
	```cpp
	    int ans = dp(idx + 1, mask);
	```
	Recursively call the function for the next index without including the current element.

19. **Mask Calculation**
	```cpp
	    int nmask = getMask(nums[idx]);
	```
	Calculate the bitmask for the current number.

20. **Condition Check**
	```cpp
	    if((nmask != -1) && ((nmask & mask) == 0)) {
	```
	Check if the number can be included in the subset (no overlap of prime factors).

21. **Recursive Call**
	```cpp
	        ans = (ans + dp(idx + 1, nmask | mask)) % mod;
	```
	Include the current number and recursively call the function for the next index, updating the mask.

22. **Memoization Update**
	```cpp
	    return memo[idx][mask] = ans;
	```
	Store the computed result in the memoization table.

23. **Function Definition**
	```cpp
	int squareFreeSubsets(vector<int>& nums) {
	```
	Define the main function 'squareFreeSubsets' to solve the problem using dynamic programming.

24. **Variable Initialization**
	```cpp
	    n = nums.size();
	```
	Set 'n' to the size of the input vector 'nums'.

25. **Variable Initialization**
	```cpp
	    this->nums = nums;
	```
	Assign the input vector to the class variable 'nums'.

26. **Prime List Setup**
	```cpp
	    prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	```
	Initialize the list of primes used in the bitmask calculation.

27. **Memoization Initialization**
	```cpp
	    memset(memo, -1, sizeof memo);
	```
	Initialize the memoization table with -1 values to indicate uncomputed states.

28. **Return Statement**
	```cpp
	    return (dp(0, 0) - 1 + mod) % mod;
	```
	Return the result of the dynamic programming function, subtracting 1 to exclude the empty subset.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n * 2^k), where n is the number of elements and k is the number of primes up to 30.
- **Average Case:** O(n * 2^k), assuming prime factorization of each element.
- **Worst Case:** O(n * 2^k), where n is the size of nums and k is the number of prime numbers up to 30.

The time complexity is dependent on the number of subsets and the prime factorization checks.

### Space Complexity 💾
- **Best Case:** O(n * 2^k), for the space required by dynamic programming.
- **Worst Case:** O(n * 2^k), where n is the size of nums and k is the number of prime numbers.

The space complexity is proportional to the number of subsets and the size of the prime factorization representation.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/)

---
{{< youtube rT4w58kX818 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
