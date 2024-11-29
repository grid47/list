
+++
authors = ["grid47"]
title = "Leetcode 43: Multiply Strings"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 43: Multiply Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/43.webp"
youtube = "6k2PdSDX-1w"
youtube_upload_date="2024-01-12"
youtube_thumbnail="https://i.ytimg.com/vi/6k2PdSDX-1w/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/43.webp" 
    alt="Two glowing strings intertwining and gently multiplying into a brighter sequence."
    caption="Solution to LeetCode 43: Multiply Strings Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two non-negative integers represented as strings, return their product as a string. You must not use any built-in BigInteger library or convert the inputs to integers directly.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two non-negative integers 'num1' and 'num2' represented as strings.
- **Example:** `Input: num1 = "3", num2 = "4"`
- **Constraints:**
	- 1 <= num1.length, num2.length <= 200
	- num1 and num2 consist of digits only.
	- Both num1 and num2 do not contain any leading zero, except the number 0 itself.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the product of num1 and num2 as a string.
- **Example:** `Output: "12"`
- **Constraints:**
	- The output should be a valid representation of the product as a string.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to simulate the multiplication of two numbers represented as strings and return the result as a string.

- Initialize an array to hold the product of the two numbers.
- Multiply each digit of num1 with each digit of num2, and store the result in the appropriate position of the array.
- Handle the carry-over values from multiplication and adjust the positions accordingly.
- Convert the array back to a string, ensuring there are no leading zeroes.
{{< dots >}}
### Problem Assumptions ✅
- Both num1 and num2 are valid non-negative integer strings.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num1 = "3", num2 = "4"`  \
  **Explanation:** In this case, the multiplication of 3 and 4 results in 12.

- **Input:** `Input: num1 = "45", num2 = "23"`  \
  **Explanation:** The result of multiplying 45 and 23 is 1035.

- **Input:** `Input: num1 = "99", num2 = "99"`  \
  **Explanation:** Multiplying 99 by 99 results in 9801.

{{< dots >}}
## Approach 🚀
We simulate the multiplication of the two numbers by multiplying each digit of num1 with each digit of num2, and handle the carries appropriately.

### Initial Thoughts 💭
- We cannot directly convert the strings to integers, so we need to simulate the multiplication process manually.
- This problem can be solved by iterating over the digits of the two strings and performing traditional multiplication, while storing the intermediate results in an array.
{{< dots >}}
### Edge Cases 🌐
- If either num1 or num2 is '0', return '0' as the result.
- For large inputs, ensure that the solution efficiently handles up to 200 digits without exceeding time limits.
- Handle the case where either num1 or num2 is a single digit, or where one of them is zero.
- Ensure the output string represents the correct result without leading zeros, except when the result is zero.
{{< dots >}}
## Code 💻
```cpp
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    
    vector<int> res(num1.size()+num2.size(), 0);
    
    for (int i = num1.size()-1; i >= 0; i--) {
        for (int j = num2.size()-1; j >= 0; j--) {
            res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }
    
    int i = 0;
    string ans = "";
    while (res[i] == 0) i++;
    while (i < res.size()) ans += to_string(res[i++]);
    
    return ans;
}
```

This code multiplies two large numbers represented as strings and returns the product as a string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	string multiply(string num1, string num2) {
	```
	This line declares a function named `multiply` that takes two strings `num1` and `num2` representing large numbers as input and returns a string representing their product.

2. **Base Case**
	```cpp
	    if (num1 == "0" || num2 == "0") return "0";
	```
	This line handles the base case where either `num1` or `num2` is "0". In this case, the product is "0", so the function returns "0".

3. **Vector Initialization**
	```cpp
	    vector<int> res(num1.size()+num2.size(), 0);
	```
	This line initializes a vector `res` of size `num1.size() + num2.size()` to store the intermediate results of the multiplication. It is initialized with zeros.

4. **Nested Loops for Multiplication**
	```cpp
	    for (int i = num1.size()-1; i >= 0; i--) {
	        for (int j = num2.size()-1; j >= 0; j--) {
	            res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
	            res[i + j] += res[i + j + 1] / 10;
	            res[i + j + 1] %= 10;
	        }
	    }
	```
	This nested loop performs the multiplication digit by digit. 1. **Digit-wise Multiplication:** The product of the digits at positions `i` and `j` in `num1` and `num2`, respectively, is added to the corresponding position in the `res` vector. 2. **Carry Handling:** If the sum at a position exceeds 9, the carry-over digit is added to the next higher position in the `res` vector. 3. **Modulo Operation:** The current position in the `res` vector is updated to store only the single-digit remainder after the carry-over.

5. **Result String Construction**
	```cpp
	    int i = 0;
	    string ans = "";
	    while (res[i] == 0) i++;
	    while (i < res.size()) ans += to_string(res[i++]);
	```
	This part constructs the final result string `ans` from the `res` vector. 1. **Skip Leading Zeros:** The loop skips leading zeros in the `res` vector. 2. **Convert Digits to String:** The remaining digits in `res` are converted to strings and appended to the `ans` string.

6. **Return Result**
	```cpp
	    return ans;
	```
	This line returns the final result string `ans`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N * M)
- **Average Case:** O(N * M)
- **Worst Case:** O(N * M)

The time complexity is proportional to the product of the lengths of num1 and num2, since we multiply each digit of num1 with each digit of num2.

### Space Complexity 💾
- **Best Case:** O(N + M)
- **Worst Case:** O(N + M)

The space complexity depends on the size of the result array, which can be at most the sum of the lengths of num1 and num2.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/multiply-strings/description/)

---
{{< youtube 6k2PdSDX-1w >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
