
+++
authors = ["grid47"]
title = "Leetcode 2644: Find the Maximum Divisibility Score"
date = "2024-02-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2644: Find the Maximum Divisibility Score in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Aqhrp1nYMqo"
youtube_upload_date="2023-04-16"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Aqhrp1nYMqo/maxresdefault.webp"
comments = true
+++



---
You are given two integer arrays, 'nums' and 'divisors'. For each element in 'divisors', you need to calculate the divisibility score, which is the number of elements in 'nums' divisible by that divisor. Your goal is to return the divisor with the highest divisibility score. If multiple divisors have the same score, return the smallest one.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays: 'nums', an array of integers, and 'divisors', another array of integers representing the divisors.
- **Example:** `nums = [12, 18, 24, 36], divisors = [3, 4, 6]`
- **Constraints:**
	- 1 <= nums.length, divisors.length <= 1000
	- 1 <= nums[i], divisors[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the integer from 'divisors' with the highest divisibility score, or the smallest one if multiple divisors have the same score.
- **Example:** `Output: 6`
- **Constraints:**
	- The output must be the divisor with the highest divisibility score.

{{< dots >}}
### Core Logic 🔍
**Goal:** Find the divisor with the maximum divisibility score from the 'divisors' array.

- Step 1: Initialize a count array to track divisibility scores for each divisor.
- Step 2: Iterate through each number in 'nums' and check if it is divisible by each divisor in 'divisors'.
- Step 3: For each divisor, increment its count if the number is divisible by it.
- Step 4: After processing all numbers, find the divisor with the highest divisibility score, breaking ties by choosing the smallest divisor.
{{< dots >}}
### Problem Assumptions ✅
- Each number in 'nums' can be divisible by one or more divisors.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [12, 18, 24, 36], divisors = [3, 4, 6]`  \
  **Explanation:** The divisibility scores are: 3 -> 4 numbers divisible, 4 -> 3 numbers divisible, 6 -> 3 numbers divisible. The highest score is 4, and the smallest divisor with that score is 3.

{{< dots >}}
## Approach 🚀
The approach is to iterate through each number in 'nums' and for each divisor, count how many numbers in 'nums' are divisible by that divisor. Then, we return the divisor with the highest count.

### Initial Thoughts 💭
- We need to calculate the divisibility score for each divisor, so iterating over 'nums' and 'divisors' is a natural approach.
- Efficiency is key due to the constraints on the size of the arrays.
{{< dots >}}
### Edge Cases 🌐
- If either 'nums' or 'divisors' is empty, return a default value indicating no divisibility score.
- For large inputs, the solution must be optimized to handle large values in 'nums' and 'divisors'.
- If no numbers are divisible by any divisor, return the smallest divisor with score 0.
- Ensure the solution runs efficiently for arrays of up to 1000 elements.
{{< dots >}}
## Code 💻
```cpp
int maxDivScore(vector<int>& nums, vector<int>& div) {
    int n = div.size();
    int m = nums.size();
    vector<int> cnt(n, 0);
    int mx = 0, idx = *min_element(div.begin(), div.end());
    map<int, vector<int>> mp;
    for(int i = 0; i < m; i++) {
        if(mp.count(nums[i])) {
            for(int x: mp[nums[i]]) {
                cnt[x]++;
                if(cnt[x] > mx || (cnt[x] == mx && div[x] < div[idx])) {
                    mx = cnt[x];
                    idx = x;
                }
            }
        } else {
            for(int j = 0; j < n; j++) {
                if(nums[i] % div[j] == 0) {
                    mp[nums[i]].push_back(j);
                    cnt[j]++;
                    if(cnt[j] > mx || (cnt[j] == mx && div[j] < div[idx])) {
                        mx = cnt[j];
                        idx = j;
                    }                        
                }
            }
        }
    }
    return mx == 0? idx:div[idx];
}
```

This function calculates the maximum division score based on two input arrays: nums and div. It tracks the frequency of divisors and returns the optimal value that satisfies the given conditions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int maxDivScore(vector<int>& nums, vector<int>& div) {
	```
	Defines the function 'maxDivScore' that takes two vectors as input: nums (numbers to divide) and div (divisors). The goal is to find the division score.

2. **Variable Initialization**
	```cpp
	    int n = div.size();
	```
	Initializes 'n' to store the size of the 'div' vector, representing the number of divisors.

3. **Variable Initialization**
	```cpp
	    int m = nums.size();
	```
	Initializes 'm' to store the size of the 'nums' vector, representing the number of elements to check against divisors.

4. **Array Initialization**
	```cpp
	    vector<int> cnt(n, 0);
	```
	Initializes 'cnt', a vector of size 'n', to keep track of the count of each divisor's occurrence.

5. **Variable Initialization**
	```cpp
	    int mx = 0, idx = *min_element(div.begin(), div.end());
	```
	Initializes 'mx' to 0 and 'idx' to the minimum element in the 'div' vector, which will serve as an index for the divisor with the highest score.

6. **Data Structure Initialization**
	```cpp
	    map<int, vector<int>> mp;
	```
	Initializes a map 'mp' to associate each number in 'nums' with its respective divisors from 'div'.

7. **Loop**
	```cpp
	    for(int i = 0; i < m; i++) {
	```
	Starts a loop that iterates through each element of the 'nums' vector.

8. **Condition Check**
	```cpp
	        if(mp.count(nums[i])) {
	```
	Checks if the current number in 'nums' already has associated divisors in the map 'mp'.

9. **Nested Loop**
	```cpp
	            for(int x: mp[nums[i]]) {
	```
	Iterates through the divisors associated with the current number 'nums[i]' in the map 'mp'.

10. **Array Update**
	```cpp
	                cnt[x]++;
	```
	Increments the count of the current divisor 'x'.

11. **Condition Check**
	```cpp
	                if(cnt[x] > mx || (cnt[x] == mx && div[x] < div[idx])) {
	```
	Checks if the count of the current divisor exceeds 'mx' or if it ties with 'mx' but has a smaller value in 'div'.

12. **Variable Update**
	```cpp
	                    mx = cnt[x];
	```
	Updates 'mx' to the new maximum count of divisors.

13. **Variable Update**
	```cpp
	                    idx = x;
	```
	Updates 'idx' to the current divisor with the maximum count.

14. **Else Block**
	```cpp
	        } else {
	```
	If no divisors are found for the current number, the else block executes.

15. **Loop**
	```cpp
	            for(int j = 0; j < n; j++) {
	```
	Starts a loop iterating through each element in the 'div' vector.

16. **Condition Check**
	```cpp
	                if(nums[i] % div[j] == 0) {
	```
	Checks if the current number 'nums[i]' is divisible by 'div[j]'.

17. **Data Structure Update**
	```cpp
	                    mp[nums[i]].push_back(j);
	```
	Adds 'j' to the map 'mp' for the current number 'nums[i]' to associate it with its divisors.

18. **Array Update**
	```cpp
	                    cnt[j]++;
	```
	Increments the count of the divisor 'div[j]'.

19. **Condition Check**
	```cpp
	                    if(cnt[j] > mx || (cnt[j] == mx && div[j] < div[idx])) {
	```
	Checks if the current divisor 'div[j]' has a higher count than 'mx', or if it ties but has a smaller value in 'div'.

20. **Variable Update**
	```cpp
	                        mx = cnt[j];
	```
	Updates 'mx' to the count of the current divisor.

21. **Variable Update**
	```cpp
	                        idx = j;
	```
	Updates 'idx' to the current divisor's index.

22. **Return Statement**
	```cpp
	    return mx == 0? idx:div[idx];
	```
	Returns the divisor corresponding to the highest count. If no valid divisor is found, returns the minimum divisor.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m * n)
- **Average Case:** O(m * n)
- **Worst Case:** O(m * n)

The time complexity is O(m * n), where m is the number of elements in 'nums' and n is the number of divisors.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the storage required for the divisibility scores.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-maximum-divisibility-score/description/)

---
{{< youtube Aqhrp1nYMqo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
