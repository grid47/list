
+++
authors = ["grid47"]
title = "Leetcode 2048: Next Greater Numerically Balanced Number"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2048: Next Greater Numerically Balanced Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Backtracking","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "VLLBGEWCHqs"
youtube_upload_date="2021-10-24"
youtube_thumbnail="https://i.ytimg.com/vi/VLLBGEWCHqs/maxresdefault.jpg"
comments = true
+++



---
An integer x is numerically balanced if, for every digit d in x, the digit d occurs exactly d times in the number. For example, 22 is numerically balanced because the digit 2 appears exactly 2 times, while 3133 is numerically balanced because the digit 3 appears exactly 3 times, and the digit 1 appears exactly 1 time.

Given an integer n, find the smallest numerically balanced integer that is strictly greater than n.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** A single integer n.
- **Example:** `Input: n = 5`
- **Constraints:**
	- 0 <= n <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** A single integer representing the smallest numerically balanced number strictly greater than n.
- **Example:** `Output: 22`
- **Constraints:**
	- The output must always be a numerically balanced number.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify the smallest numerically balanced number greater than the input number n.

- Generate a pre-defined list of known numerically balanced numbers.
- Iterate through the list to find the smallest number that is greater than n.
- Use permutations to explore numbers of the same digit length, ensuring they are numerically balanced.
{{< dots >}}
### Problem Assumptions ✅
- The input n is a valid integer within the given range.
- The numerically balanced property applies only to positive integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 7`  \
  **Explanation:** The smallest numerically balanced number greater than 7 is 22. The digit 2 occurs exactly 2 times. Output: 22.

- **Input:** `Input: n = 2000`  \
  **Explanation:** The smallest numerically balanced number greater than 2000 is 3133. The digit 3 occurs exactly 3 times, and the digit 1 occurs exactly 1 time. Output: 3133.

- **Input:** `Input: n = 50000`  \
  **Explanation:** The smallest numerically balanced number greater than 50000 is 122333. The digit 1 occurs exactly 1 time, digit 2 occurs 2 times, and digit 3 occurs 3 times. Output: 122333.

{{< dots >}}
## Approach 🚀
Use a precomputed list of numerically balanced numbers combined with permutation-based exploration for numbers of appropriate size.

### Initial Thoughts 💭
- Numerically balanced numbers are rare, making a precomputed list an efficient starting point.
- The problem involves a combination of string manipulation and numerical properties.
- Precomputing smaller numerically balanced numbers can drastically reduce runtime for queries involving smaller values of n.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as the problem guarantees a valid input.
- Handle cases where n is close to 10^6 by ensuring efficient traversal of balanced numbers.
- Values like n = 0 or n = 1, where the smallest balanced number is from the start of the list.
- Values just below a balanced number like n = 21 or n = 132.
- Ensure no numerically balanced numbers are skipped due to incorrect comparison.
{{< dots >}}
## Code 💻
```cpp
vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
int nextBeautifulNumber(int n) {
    int res = 1224444;
    
    string s = to_string(n);
    for(auto it: base) {
        string ss = to_string(it);
        if(ss.size() < s.size()) continue;
        if(ss.size() > s.size()) res = min(res, it);
        else {
            do {
                if(ss > s) {
                    res = min(res, stoi(ss));
                }
            } while(next_permutation(ss.begin(), ss.end()));
        }
    }
    return res;
}
```

This code defines a solution to find the next 'beautiful' number greater than a given number. A beautiful number is one that consists of repeated digits, such as 111, 222, 3333. The code iterates through a predefined set of base numbers, compares them with the given number, and returns the smallest valid 'beautiful' number that is larger than the given number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Base Numbers Initialization**
	```cpp
	vector<int> base = {1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666 };
	```
	Defines a vector `base` that contains a set of base 'beautiful' numbers, which will be used to find the next 'beautiful' number larger than the given input `n`.

2. **Function Declaration**
	```cpp
	int nextBeautifulNumber(int n) {
	```
	Declares the function `nextBeautifulNumber` that takes an integer `n` as input and returns the next beautiful number greater than `n`.

3. **Result Initialization**
	```cpp
	    int res = 1224444;
	```
	Initializes the result `res` to the smallest base beautiful number that is larger than any possible input.

4. **String Conversion**
	```cpp
	    string s = to_string(n);
	```
	Converts the input integer `n` into a string `s` to facilitate comparison with other string-based beautiful numbers.

5. **Loop Through Base Numbers**
	```cpp
	    for(auto it: base) {
	```
	Iterates through each number in the `base` vector to check if it can be the next beautiful number larger than `n`.

6. **Convert Base Number to String**
	```cpp
	        string ss = to_string(it);
	```
	Converts the current base number `it` into a string `ss` for comparison with the input string `s`.

7. **Size Comparison (Smaller)**
	```cpp
	        if(ss.size() < s.size()) continue;
	```
	If the size of the current base number `ss` is smaller than `s`, skips it, as we are looking for a number with at least the same number of digits as `n`.

8. **Size Comparison (Larger)**
	```cpp
	        if(ss.size() > s.size()) res = min(res, it);
	```
	If the size of the current base number `ss` is larger than `s`, it automatically becomes a candidate for the result `res` as the smallest larger 'beautiful' number.

9. **Exact Size Comparison**
	```cpp
	        else {
	```
	If the base number `ss` has the same number of digits as `n`, the code enters this block to compare the numbers in more detail.

10. **Permutation Loop**
	```cpp
	            do {
	```
	Starts a `do-while` loop that generates all permutations of the string `ss` to find the smallest valid 'beautiful' number greater than `s`.

11. **Permutation Comparison**
	```cpp
	                if(ss > s) {
	```
	Compares the current permutation `ss` with the input string `s`. If `ss` is greater than `s`, it could be the next valid 'beautiful' number.

12. **Update Result**
	```cpp
	                    res = min(res, stoi(ss));
	```
	Updates the result `res` with the minimum of the current result and the integer value of the valid permutation `ss`.

13. **Next Permutation**
	```cpp
	            } while(next_permutation(ss.begin(), ss.end()));
	```
	Generates the next permutation of the string `ss` and continues the loop until all permutations have been checked.

14. **Return Result**
	```cpp
	    return res;
	```
	Returns the smallest 'beautiful' number greater than the input `n`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) for direct lookup in the precomputed list.
- **Average Case:** O(k * m!) for permutations, where k is the number of digits and m is the average digit count.
- **Worst Case:** O(k * m!) when n is close to the largest precomputed number and requires exploration.

Precomputing balanced numbers saves time, but larger inputs require exploring permutations for validation.

### Space Complexity 💾
- **Best Case:** O(1) if only precomputed results are used.
- **Worst Case:** O(k) for storing temporary permutations.

Space usage depends on the need for generating and validating permutations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/next-greater-numerically-balanced-number/description/)

---
{{< youtube VLLBGEWCHqs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
