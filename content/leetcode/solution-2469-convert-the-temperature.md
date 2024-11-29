
+++
authors = ["grid47"]
title = "Leetcode 2469: Convert the Temperature"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2469: Convert the Temperature in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "pJo95i-uamg"
youtube_upload_date="2022-11-13"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pJo95i-uamg/maxresdefault.webp"
comments = true
+++



---
You are given a non-negative floating point number `celsius` (rounded to two decimal places) representing a temperature in Celsius. Convert it to Kelvin and Fahrenheit and return the results in a list. The formulas are: Kelvin = Celsius + 273.15 and Fahrenheit = Celsius * 1.80 + 32.00. Return the results rounded to five decimal places.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a non-negative floating point number `celsius` representing the temperature in Celsius.
- **Example:** `celsius = 25.30`
- **Constraints:**
	- 0 <= celsius <= 1000

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list containing the temperature in Kelvin and Fahrenheit, rounded to five decimal places.
- **Example:** `[298.45000, 77.54000]`
- **Constraints:**
	- Answers within 10^-5 of the actual result will be accepted.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to correctly apply the formulas for conversion from Celsius to Kelvin and Fahrenheit.

- First, calculate the Kelvin value by adding 273.15 to the Celsius value.
- Next, calculate the Fahrenheit value using the formula Fahrenheit = Celsius * 1.80 + 32.00.
- Return the results as a list, rounding each to five decimal places.
{{< dots >}}
### Problem Assumptions ✅
- The input temperature `celsius` is always a valid non-negative floating point number.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: celsius = 25.30`  \
  **Explanation:** The Kelvin value is calculated by adding 273.15 to the Celsius value, giving 298.45. The Fahrenheit value is calculated by multiplying 25.30 by 1.80 and adding 32, which gives 77.54.

{{< dots >}}
## Approach 🚀
This problem is a straightforward application of the conversion formulas. First, we convert Celsius to Kelvin and then to Fahrenheit.

### Initial Thoughts 💭
- The formulas for Kelvin and Fahrenheit are linear and simple to compute.
- This problem requires basic arithmetic and handling floating point numbers.
{{< dots >}}
### Edge Cases 🌐
- The input `celsius` will never be empty as per the problem's constraints.
- For very large values of `celsius`, the formulas will still work within the provided constraints.
- If `celsius` is 0, the results should correctly return 273.15 Kelvin and 32.00 Fahrenheit.
- The solution needs to handle floating-point arithmetic carefully, especially with rounding to five decimal places.
{{< dots >}}
## Code 💻
```cpp
vector<double> convertTemperature(double celsius) {
    return { celsius + 273.15, celsius*1.80 + 32.00 };
}
```

This function converts a given temperature in Celsius to both Kelvin and Fahrenheit. It returns a vector containing two values: the temperature in Kelvin and the temperature in Fahrenheit.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<double> convertTemperature(double celsius) {
	```
	The function `convertTemperature` is declared, taking one parameter `celsius` which represents the temperature in Celsius.

2. **Return Statement**
	```cpp
	    return { celsius + 273.15, celsius*1.80 + 32.00 };
	```
	The function returns a vector containing two converted temperatures: the first value is the temperature in Kelvin (Celsius + 273.15), and the second value is the temperature in Fahrenheit (Celsius * 1.80 + 32).

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(1)
- **Worst Case:** O(1)

The time complexity is constant since the solution involves a fixed number of arithmetic operations.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is constant as we only need to store two results (Kelvin and Fahrenheit).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-the-temperature/description/)

---
{{< youtube pJo95i-uamg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
