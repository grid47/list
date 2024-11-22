
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return { celsius + 273.15, celsius*1.80 + 32.00 };
    }
};
{{< /highlight >}}
---

### Problem Statement:
The problem asks to convert a given temperature in Celsius to its equivalent in two different units: Kelvin and Fahrenheit. Given a temperature in Celsius, we are tasked with returning a vector containing the temperature in Kelvin and Fahrenheit.

- **Kelvin** is a unit of temperature that starts at absolute zero (0 K). The formula for converting Celsius to Kelvin is:  
  \[
  K = C + 273.15
  \]
  where \( C \) is the temperature in Celsius.
  
- **Fahrenheit** is another unit of temperature, commonly used in the United States. The formula for converting Celsius to Fahrenheit is:  
  \[
  F = C \times 1.80 + 32.00
  \]
  where \( C \) is the temperature in Celsius.

The function needs to return a vector containing these two values.

### Approach:
To solve this problem, we need to convert a given temperature from Celsius to both Kelvin and Fahrenheit. The approach is straightforward:

1. **Conversion to Kelvin**: We add 273.15 to the Celsius temperature.
2. **Conversion to Fahrenheit**: We multiply the Celsius temperature by 1.80 and then add 32.00.

Once both values are calculated, we need to return them in a vector of type `double`, where the first element is the temperature in Kelvin and the second element is the temperature in Fahrenheit.

The approach works in constant time, as the conversion formulas do not depend on the size of the input or any iterations over data structures. The time complexity for the conversion is \( O(1) \), meaning the function will always execute in constant time, regardless of the input.

### Code Breakdown (Step by Step):
Let's walk through the provided C++ code and break it down into individual components to understand how the function works.

1. **Function Declaration**:
   ```cpp
   vector<double> convertTemperature(double celsius)
   ```
   The function `convertTemperature` takes a single argument:
   - `celsius`: a `double` representing the temperature in Celsius that needs to be converted.
   
   It returns a vector of `double` values containing the converted temperatures in Kelvin and Fahrenheit.

2. **Return Statement**:
   ```cpp
   return { celsius + 273.15, celsius*1.80 + 32.00 };
   ```
   The return statement directly computes and returns a vector with two elements:
   
   - The first element is the Celsius temperature converted to Kelvin, calculated as `celsius + 273.15`.
   - The second element is the Celsius temperature converted to Fahrenheit, calculated as `celsius * 1.80 + 32.00`.
   
   The result is returned as a vector of `double` values, with the first element being the Kelvin temperature and the second being the Fahrenheit temperature.

### Code Explanation:
1. **Input Parameter**: 
   - The function takes in one input parameter: a `double` value representing the temperature in Celsius.

2. **Vector Return Type**:
   - The function returns a `vector<double>`, which is a container from the C++ Standard Library that stores a collection of double-precision floating-point numbers.
   
   - The vector returned will contain exactly two values: the temperature converted to Kelvin and the temperature converted to Fahrenheit.

3. **Temperature Conversion**:
   - To convert Celsius to Kelvin, we add 273.15 to the given Celsius temperature. This is based on the definition of the Kelvin scale, which is offset by 273.15 from the Celsius scale.
   
   - To convert Celsius to Fahrenheit, we multiply the Celsius temperature by 1.80 (which is equivalent to \( \frac{9}{5} \)) and then add 32.00. This follows the formula for converting between Celsius and Fahrenheit.
   
4. **Returning the Result**:
   - After performing the two conversions, the result is returned as a vector. The syntax `{ ... }` is used to create a temporary `vector<double>` that contains the two results.

### Complexity:
Let’s analyze the time and space complexity of the function:

- **Time Complexity**:
  - The function performs only two arithmetic operations: adding 273.15 and multiplying by 1.80 (then adding 32.00). These are constant time operations.
  - There are no loops or recursive calls. The conversion process for each Celsius value is done in constant time.
  
  Therefore, the time complexity of the function is \( O(1) \), meaning that the function will always execute in constant time, regardless of the input value.

- **Space Complexity**:
  - The function returns a `vector<double>`, which stores exactly two double values. The space used by the vector is constant because it holds only two values, irrespective of the size of the input.
  
  Therefore, the space complexity is also \( O(1) \), as the space usage does not depend on the input size and remains constant.

### Conclusion:
The function `convertTemperature` efficiently converts a temperature given in Celsius to both Kelvin and Fahrenheit. It uses simple arithmetic formulas to perform the conversions and returns the results in a `vector<double>`. The approach is optimal in terms of both time and space, as the function runs in constant time and uses constant space.

This function is ideal for applications that require quick temperature conversions without needing complex data structures or algorithms. Its simplicity and efficiency make it highly suitable for scenarios where multiple temperature conversions are needed in a fast and scalable manner.

Moreover, the use of a `vector<double>` allows the result to be easily accessed and manipulated if needed. Since the conversion formulas themselves are well-established and straightforward, this solution is both easy to understand and implement.

In conclusion, this function provides a simple yet effective solution to the problem of converting temperatures between different units, with a time and space complexity that is optimal for most real-world scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/convert-the-temperature/description/)

---
{{< youtube pJo95i-uamg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
