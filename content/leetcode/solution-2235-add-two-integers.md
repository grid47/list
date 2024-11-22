
+++
authors = ["grid47"]
title = "Leetcode 2235: Add Two Integers"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2235: Add Two Integers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Qubhoqoks6I"
youtube_upload_date="2023-01-07"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Qubhoqoks6I/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to create a simple function that takes two integers as input and returns their sum. This is a basic operation commonly encountered in programming and serves as an introduction to working with functions and arithmetic operations in any programming language.

### Approach

The approach to solving this problem is straightforward:
1. We need a function that will accept two integers as input.
2. The function will compute the sum of these two integers.
3. The result will be returned to the calling code.

This problem requires understanding how functions are declared, how parameters are passed, and how the return value is handled in C++. 

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
    int sum(int num1, int num2) {
        return num1 + num2;
    }
};
```

#### 1. **Class Declaration**:
```cpp
class Solution {
```
- We begin by declaring a class named `Solution`. In C++, a class is used to group together related functions (also called methods) and data. In this case, we are creating a class to encapsulate our solution.

- The `public` keyword specifies that the function `sum` is accessible from outside the class, meaning other parts of the code can call this function.

#### 2. **Function Declaration**:
```cpp
int sum(int num1, int num2) {
```
- We define a member function `sum` inside the class `Solution`.
- The function takes two integer parameters, `num1` and `num2`, which represent the two numbers whose sum we want to compute.
- The function's return type is `int`, indicating that it will return an integer value.

#### 3. **Sum Operation**:
```cpp
return num1 + num2;
```
- This line performs the arithmetic operation of adding `num1` and `num2` together.
- The result is then returned to the calling code.
- Since `num1` and `num2` are both integers, their sum will also be an integer.

#### 4. **Class Closing**:
```cpp
};
```
- This closes the class `Solution`, indicating that the definition of the class is complete.
- The class contains a single function, `sum`, which performs the operation of adding two numbers.

### Complexity

#### Time Complexity:
- The time complexity of the `sum` function is **O(1)**. This is because the addition operation and returning the result are performed in constant time, regardless of the size of the input numbers.

#### Space Complexity:
- The space complexity of the `sum` function is **O(1)**. The function only requires space for the two input parameters and the return value, which are all of constant size. The space used by the function does not depend on the size of the input numbers or any other variables, making it a constant-space solution.

### Conclusion

This code provides a basic implementation of a function that adds two integers. The `sum` function is simple yet demonstrates key programming concepts such as function definition, input/output handling, and basic arithmetic operations. It has constant time and space complexity, making it highly efficient for this specific problem.

In real-world applications, you might use similar functions when performing a variety of basic operations like addition, subtraction, multiplication, etc. The simplicity of this function makes it an excellent starting point for beginners to understand how to define and use functions in C++.

The solution is extremely efficient and straightforward, ensuring that any operation involving adding two integers can be done quickly and without any unnecessary overhead.

[`Link to LeetCode Lab`](https://leetcode.com/problems/add-two-integers/description/)

---
{{< youtube Qubhoqoks6I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
