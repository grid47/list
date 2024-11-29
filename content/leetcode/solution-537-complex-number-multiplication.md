
+++
authors = ["grid47"]
title = "Leetcode 537: Complex Number Multiplication"
date = "2024-09-14"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 537: Complex Number Multiplication in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/537.webp"
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/537.webp" 
    alt="Two complex numbers multiplying, with each step of the calculation softly glowing as the result is formed."
    caption="Solution to LeetCode 537: Complex Number Multiplication Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given two complex numbers represented as strings, multiply them and return the result as a string in the format 'real+imaginaryi'.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** Each input consists of two strings representing complex numbers. Each complex number is represented in the form 'real+imaginaryi', where both real and imaginary are integers within the range [-100, 100].
- **Example:** `Input: num1 = "2+3i", num2 = "4+5i"`
- **Constraints:**
	- num1 and num2 are valid complex numbers, with real and imaginary parts being integers in the range [-100, 100].

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a string representing the product of the two complex numbers in the format 'real+imaginaryi'.
- **Example:** `Output: "-7+22i"`
- **Constraints:**
	- The output should follow the exact format 'real+imaginaryi', where real and imaginary are integers.

{{< dots >}}
### Core Logic 🔍
**Goal:** To multiply two complex numbers and return the result in the appropriate format.

- Parse the real and imaginary parts of both complex numbers from the input strings.
- Apply the formula for multiplying complex numbers: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i.
- Construct the result string by formatting the real and imaginary parts into the 'real+imaginaryi' format.
{{< dots >}}
### Problem Assumptions ✅
- The input complex numbers are valid and conform to the given format.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num1 = "2+3i", num2 = "4+5i"`  \
  **Explanation:** Multiplying (2 + 3i) by (4 + 5i) using the formula (a + bi) * (c + di) = (ac - bd) + (ad + bc)i results in -7 + 22i.

{{< dots >}}
## Approach 🚀
To solve the problem, we need to parse the input strings, apply the complex number multiplication formula, and then return the result in the correct format.

### Initial Thoughts 💭
- We need to parse the complex numbers into their real and imaginary components and then perform the multiplication.
- The formula for multiplying complex numbers is straightforward, and we need to format the result properly.
{{< dots >}}
### Edge Cases 🌐
- The problem guarantees valid input, so no need to handle empty input cases.
- The solution needs to handle all valid inputs as specified within the constraints.
- Ensure that negative values in the real or imaginary parts are correctly handled in the result.
- The solution must handle all inputs within the range [-100, 100] for both real and imaginary parts.
{{< dots >}}
## Code 💻
```cpp
string complexNumberMultiply(string num1, string num2) {
    string r1, img1, r2, img2;
    int i = 0;
    while(num1[i] != '+') {
        r1 += num1[i];
        i++;
    }
    img1 = num1.substr(i + 1, num1.size() -1);
    i = 0;
    while(num2[i] != '+') {
        r2 += num2[i];
        i++;
    }
    img2 = num2.substr(i + 1, num2.size() -1);
    int re1 = stoi(r1);
    int re2 = stoi(r2);
    int ig1 = stoi(img1);
    int ig2 = stoi(img2);

    i = re1 * re2 - ig1 * ig2;
    int g = re1 * ig2 + re2 * ig1;

    return to_string(i) + "+" + to_string(g) + "i";
}
```

This function multiplies two complex numbers represented as strings. It splits the real and imaginary parts of the numbers, performs the multiplication, and returns the result as a string.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	string complexNumberMultiply(string num1, string num2) {
	```
	Defines the `complexNumberMultiply` function that accepts two complex numbers as strings and returns their product as a string.

2. **Variable Initialization**
	```cpp
	    string r1, img1, r2, img2;
	```
	Initializes strings to store the real and imaginary parts of the two complex numbers.

3. **Variable Initialization**
	```cpp
	    int i = 0;
	```
	Initializes an integer variable `i` to be used as an index for parsing the input strings.

4. **First While Loop**
	```cpp
	    while(num1[i] != '+') {
	```
	Starts a loop to extract the real part of the first complex number by iterating until the '+' sign.

5. **String Manipulation**
	```cpp
	        r1 += num1[i];
	```
	Appends each character of the real part of `num1` to the string `r1`.

6. **Increment Index**
	```cpp
	        i++;
	```
	Increments the index `i` to move through the string.

7. **Extract Imaginary Part**
	```cpp
	    img1 = num1.substr(i + 1, num1.size() -1);
	```
	Extracts the imaginary part of `num1` by getting the substring after the '+' sign.

8. **Variable Initialization**
	```cpp
	    i = 0;
	```
	Resets the index `i` to 0 to parse the second complex number `num2`.

9. **Second While Loop**
	```cpp
	    while(num2[i] != '+') {
	```
	Starts a loop to extract the real part of the second complex number `num2`.

10. **String Manipulation**
	```cpp
	        r2 += num2[i];
	```
	Appends each character of the real part of `num2` to the string `r2`.

11. **Increment Index**
	```cpp
	        i++;
	```
	Increments the index `i` to move through the string.

12. **Extract Imaginary Part**
	```cpp
	    img2 = num2.substr(i + 1, num2.size() -1);
	```
	Extracts the imaginary part of `num2` by getting the substring after the '+' sign.

13. **Integer Conversion**
	```cpp
	    int re1 = stoi(r1);
	```
	Converts the real part of `num1` from string to integer.

14. **Integer Conversion**
	```cpp
	    int re2 = stoi(r2);
	```
	Converts the real part of `num2` from string to integer.

15. **Integer Conversion**
	```cpp
	    int ig1 = stoi(img1);
	```
	Converts the imaginary part of `num1` from string to integer.

16. **Integer Conversion**
	```cpp
	    int ig2 = stoi(img2);
	```
	Converts the imaginary part of `num2` from string to integer.

17. **Complex Number Multiplication**
	```cpp
	    i = re1 * re2 - ig1 * ig2;
	```
	Calculates the real part of the product of the two complex numbers using the formula: (a * c - b * d).

18. **Complex Number Multiplication**
	```cpp
	    int g = re1 * ig2 + re2 * ig1;
	```
	Calculates the imaginary part of the product of the two complex numbers using the formula: (a * d + b * c).

19. **Return Result**
	```cpp
	    return to_string(i) + "+" + to_string(g) + "i";
	```
	Returns the result as a string, combining the real and imaginary parts with a '+' sign.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

Both parsing the complex numbers and performing the multiplication take constant time, O(1).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) as only a few integer variables are used to store the real and imaginary parts.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/complex-number-multiplication/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
