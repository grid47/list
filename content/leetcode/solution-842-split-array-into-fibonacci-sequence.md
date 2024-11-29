
+++
authors = ["grid47"]
title = "Leetcode 842: Split Array into Fibonacci Sequence"
date = "2024-08-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 842: Split Array into Fibonacci Sequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a string of digits, and you need to split it into a sequence of integers that follow the Fibonacci-like property. In other words, the sum of the first two numbers should equal the third, the sum of the second and third should equal the fourth, and so on. Your goal is to find any valid Fibonacci-like sequence from the digits, or return an empty list if it's not possible.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a string of digits 'num'. You need to split this string into multiple non-negative integers such that the resulting sequence forms a Fibonacci-like sequence.
- **Example:** `Input: num = '123456'`
- **Constraints:**
	- 1 <= num.length <= 200
	- num contains only digits.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return any Fibonacci-like sequence that can be split from the given string of digits, or return an empty list if it's not possible to form such a sequence.
- **Example:** `Output: [123, 456, 579]`
- **Constraints:**
	- The resulting sequence must satisfy the Fibonacci property: f[i] + f[i + 1] = f[i + 2] for all 0 <= i < f.length - 2.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to split the string into possible Fibonacci-like subsequences and check if they satisfy the property where each number is the sum of the previous two.

- Step 1: Try splitting the string into different lengths and check if the sum of the first two numbers equals the third number.
- Step 2: Ensure that the numbers formed do not have leading zeros unless the number is zero itself.
- Step 3: Recursively check if we can split the string further while maintaining the Fibonacci property.
{{< dots >}}
### Problem Assumptions ✅
- Each piece of the split string should be a valid non-negative integer.
- The sequence must follow the Fibonacci-like rule where each number is the sum of the previous two numbers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: '123456'`  \
  **Explanation:** Starting with '1' and '2', the next number is '3', which satisfies the Fibonacci-like condition. Then '5' and '8' form a valid sequence. The final sequence is [123, 456, 579].

- **Input:** `Input: '11111'`  \
  **Explanation:** The sequence can be split as [1, 1, 2, 3, 5], which follows the Fibonacci-like condition.

- **Input:** `Input: '0123'`  \
  **Explanation:** The input contains leading zeroes, which is not valid unless the number is '0'. Therefore, it is not possible to form a Fibonacci-like sequence.

{{< dots >}}
## Approach 🚀
We can approach this problem by attempting to split the input string into all possible subsequences of two numbers and checking if the sum of the first two equals the third. This requires trying different split points and ensuring that each number in the sequence fits the Fibonacci-like property.

### Initial Thoughts 💭
- The problem involves checking all possible splits of the string into numbers.
- We need to check if each possible sequence forms a valid Fibonacci-like sequence.
- Since we need to check different subsequences, a recursive approach with backtracking seems appropriate.
{{< dots >}}
### Edge Cases 🌐
- An empty string cannot form a valid sequence.
- For large inputs, ensure that the splitting and checking process is efficient.
- Leading zeroes in numbers that are not '0' should be handled as invalid.
- The constraints are based on the string length and valid integer splitting.
{{< dots >}}
## Code 💻
```cpp
vector<int> splitIntoFibonacci(string num) {
    vector<int> res;
    split(0, res, num);
    return res;
}

bool split(int idx, vector<int> &res, string num) {
    if(idx == num.size() && res.size() >= 3) return true;
    for(int i = idx; i < num.size(); i++) {
        if(num[idx] == '0' && i > idx) break;
        int sz = i - idx+1;
        long n = stol("0" + num.substr(idx, sz));
        if(n > INT_MAX) break;
                 
        if(res.size() <= 1 || (n == (long)res.back() + res[res.size() -2])) {
            res.push_back(n);
            if(split(i + 1, res, num))
                return true;
            res.pop_back();
        }

    }
    return false;
}
```

This is a function to split a string of digits into a Fibonacci-like sequence, where each number in the sequence is the sum of the previous two numbers. It recursively attempts to find such a split, returning the sequence if possible.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function**
	```cpp
	vector<int> splitIntoFibonacci(string num) {
	```
	This is the main function that initiates the splitting process by calling the helper function 'split' starting from index 0.

2. **Variable Declaration**
	```cpp
	    vector<int> res;
	```
	A vector to store the resulting Fibonacci-like sequence.

3. **Function Call**
	```cpp
	    split(0, res, num);
	```
	Calls the helper function 'split' to attempt splitting the string into a Fibonacci sequence starting at index 0.

4. **Return**
	```cpp
	    return res;
	```
	Returns the resulting Fibonacci sequence found by the 'split' function.

5. **Helper Function**
	```cpp
	bool split(int idx, vector<int> &res, string num) {
	```
	A helper function that tries to split the string 'num' into a Fibonacci-like sequence recursively, starting at the given index.

6. **Base Case Check**
	```cpp
	    if(idx == num.size() && res.size() >= 3) return true;
	```
	Checks if the entire string has been processed and at least 3 numbers have been added to the sequence, in which case it returns true.

7. **Loop**
	```cpp
	    for(int i = idx; i < num.size(); i++) {
	```
	Iterates through the string starting from the current index to try splitting the string into Fibonacci numbers.

8. **Edge Case Check**
	```cpp
	        if(num[idx] == '0' && i > idx) break;
	```
	Breaks the loop if the current number starts with a '0' and is not a single-digit number, as it would not be a valid Fibonacci number.

9. **SubString Calculation**
	```cpp
	        int sz = i - idx + 1;
	```
	Calculates the length of the current substring being considered as a potential Fibonacci number.

10. **String to Number**
	```cpp
	        long n = stol("0" + num.substr(idx, sz));
	```
	Converts the current substring to a long integer to avoid overflow.

11. **Overflow Check**
	```cpp
	        if(n > INT_MAX) break;
	```
	Checks if the number exceeds the maximum value for an integer, in which case it breaks out of the loop.

12. **Fibonacci Sequence Validation**
	```cpp
	        if(res.size() <= 1 || (n == (long)res.back() + res[res.size() - 2])) {
	```
	Checks if the current number is the sum of the last two numbers in the sequence. If it is, the number is valid and can be added to the sequence.

13. **Add to Result**
	```cpp
	            res.push_back(n);
	```
	Adds the valid number to the Fibonacci sequence.

14. **Recursive Call**
	```cpp
	            if(split(i + 1, res, num))
	```
	Recursively attempts to continue splitting the string from the next index.

15. **Successful Split**
	```cpp
	                return true;
	```
	If the recursive call succeeds in splitting the rest of the string, it returns true.

16. **Backtrack**
	```cpp
	            res.pop_back();
	```
	Backtracks by removing the last number added to the sequence if the split was unsuccessful.

17. **Return False**
	```cpp
	    return false;
	```
	If no valid split is found, returns false to indicate failure.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^3)

The time complexity depends on the number of valid splits and the checks needed for each split, which could involve iterating through each character of the string.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity depends on the space required to store the subsequences and recursion stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
