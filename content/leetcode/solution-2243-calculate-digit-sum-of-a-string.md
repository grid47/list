
+++
authors = ["grid47"]
title = "Leetcode 2243: Calculate Digit Sum of a String"
date = "2024-03-27"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2243: Calculate Digit Sum of a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Lyesi93Z6_A"
youtube_upload_date="2022-04-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Lyesi93Z6_A/maxresdefault.webp"
comments = true
+++



---
You are given a string of digits, `s`, and an integer `k`. Your task is to repeatedly process the string until its length becomes less than or equal to `k`. In each step, divide the string into consecutive groups of size `k`. If the last group is smaller than `k`, process it as is. For each group, calculate the sum of its digits, convert the result back to a string, and merge all groups to form a new string. Repeat the process until the string length is `≤ k`, and return the final string.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a string `s` and an integer `k`.
- **Example:** `For example, `s = "987654"` and `k = 2`.`
- **Constraints:**
	- 1 <= s.length <= 100
	- 2 <= k <= 100
	- The string `s` consists of digits only.

{{< dots >}}
### Output Specifications 📤
- **Output:** The function returns the final processed string after applying the digit-sum transformation until the length of `s` becomes less than or equal to `k`.
- **Example:** `If `s = "987654"` and `k = 2`, the output will be `"3011"`.`
- **Constraints:**
	- The output string will have a length of at most `k`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Transform the string `s` iteratively by dividing it into groups of size `k`, summing the digits of each group, and merging the results until its length is less than or equal to `k`.

- While the length of `s` is greater than `k`, perform the following:
- 1. Divide `s` into groups of size `k`.
- 2. For each group, calculate the sum of its digits.
- 3. Replace the group with the sum as a string.
- 4. Merge all groups to form the new string `s`.
- Return `s` when its length is less than or equal to `k`.
{{< dots >}}
### Problem Assumptions ✅
- The input string `s` is non-empty.
- The value of `k` is always valid.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: `s = "987654321", k = 3``  \
  **Explanation:** 1. Divide `s` into groups: `"987"`, `"654"`, `"321"`. 
2. Sum digits in each group: `9+8+7=24`, `6+5+4=15`, `3+2+1=6`. 
3. Merge results: `"24156"`. Repeat for `"24156"`. 
4. Divide: `"241"`, `"56"`. Sum: `2+4+1=7`, `5+6=11`. Merge: `"711"`. Stop as length ≤ `k`.

- **Input:** `Input: `s = "1234", k = 2``  \
  **Explanation:** 1. Divide: `"12"`, `"34"`. Sum: `1+2=3`, `3+4=7`. Merge: `"37"`. Stop as length ≤ `k`.

{{< dots >}}
## Approach 🚀
Iteratively process the string until its length is less than or equal to `k` by dividing into groups, summing digits, and merging results.

### Initial Thoughts 💭
- Each group can be processed independently.
- The transformation involves simple arithmetic operations.
- Use a loop to handle iterations.
- Handle groups efficiently using slicing or indexing.
{{< dots >}}
### Edge Cases 🌐
- Not applicable as `s` is guaranteed to be non-empty.
- Ensure the implementation handles strings close to the maximum length of 100 efficiently.
- `k` equals the length of `s`: return `s` immediately.
- `s` contains only zeros: ensure the sum correctly results in zeros.
- Ensure all calculations respect numeric constraints for digits.
{{< dots >}}
## Code 💻
```cpp
string digitSum(string s, int k) {
while(s.size() > k) {
    string s1;
    for (int i = 0; i < s.size(); i += k)
        s1 += to_string(accumulate(begin(s) + i, begin(s) + min((int)s.size(), i + k), 0, 
            [](int n, char ch){ return n + ch - '0'; }));
    swap(s1, s);
}
return s;
}
```

This function calculates the repeated digit sum of a given string of digits, reducing it until the string size is less than or equal to a specified integer 'k'.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string digitSum(string s, int k) {
	```
	This line defines the function 'digitSum', which takes a string 's' and an integer 'k' as input.

2. **Loop Condition**
	```cpp
	while(s.size() > k) {
	```
	The while loop continues as long as the size of the string 's' is greater than 'k'.

3. **Variable Initialization**
	```cpp
	    string s1;
	```
	A temporary string 's1' is initialized to store the sum of digits in each segment.

4. **For Loop**
	```cpp
	    for (int i = 0; i < s.size(); i += k)
	```
	This for loop iterates over the string 's' in steps of 'k', processing 'k' digits at a time.

5. **Accumulation**
	```cpp
	        s1 += to_string(accumulate(begin(s) + i, begin(s) + min((int)s.size(), i + k), 0, 
	```
	This line accumulates the sum of the 'k' digits starting from index 'i'. The 'accumulate' function adds each digit's numeric value to the total.

6. **Lambda Function**
	```cpp
	            [](int n, char ch){ return n + ch - '0'; }));
	```
	The lambda function inside 'accumulate' converts each character 'ch' to its corresponding integer value by subtracting '0'.

7. **Swap Operation**
	```cpp
	    swap(s1, s);
	```
	After each iteration, the new string 's1' is swapped with 's', so the process continues on the updated string.

8. **Return Statement**
	```cpp
	return s;
	```
	Once the string size is less than or equal to 'k', the function returns the final string 's'.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

Each iteration processes the string in linear time, and the length of `s` reduces logarithmically over iterations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

In-place modifications reduce space requirements; however, slicing may require extra memory proportional to the input size.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/)

---
{{< youtube Lyesi93Z6_A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
