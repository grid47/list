
+++
authors = ["grid47"]
title = "Leetcode 553: Optimal Division"
date = "2024-09-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 553: Optimal Division in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/553.webp"
youtube = "SFNvfrvWxVQ"
youtube_upload_date="2019-11-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/SFNvfrvWxVQ/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/553.webp" 
    alt="A sequence of numbers being divided optimally, with each division step softly glowing as the optimal result is reached."
    caption="Solution to LeetCode 553: Optimal Division Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s = "";
        if(nums.size() == 1) return to_string(nums[0]);
        if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);

        for(int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]) + "/";
            if(i == 0)
                s += "(";
        }
        s[s.size() -1] = ')';
        return s;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the optimal division for a given list of integers, such that the result of the division is maximized. The optimal way to divide a list of numbers involves placing parentheses in such a way that maximizes the value of the division. You need to return the division expression as a string, which could include the necessary parentheses.

**Example:**

Input: `[1000, 100, 10, 2]`

Output: `"1000/(100/10/2)"`

The goal is to divide the first number by the result of dividing the rest of the numbers, ensuring that the parentheses are positioned to maximize the result.

### Approach

To maximize the result of the division, consider the properties of division:
1. **Maximization Rule**: When dividing multiple numbers, the division result is largest when the first number is divided by the smallest possible value. This can be achieved by placing the division of the remaining numbers inside parentheses. 
2. **Basic Strategy**: If we have more than two numbers, the optimal strategy is to divide the first number by the result of dividing the rest of the numbers (from the second element onward). For two numbers, just perform the division directly without parentheses.

For example:
- For a list with just one number, return that number as it is.
- For two numbers, return the result of a simple division.
- For more than two numbers, divide the first number by the result of the division of the rest of the numbers inside parentheses.

### Code Breakdown (Step by Step)

#### 1. **Class and Function Definition**
```cpp
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string s = "";
```
- The class `Solution` contains the function `optimalDivision`, which takes a vector `nums` of integers.
- The string `s` is initialized to an empty string, which will store the final result.

#### 2. **Handling a Single Element in the List**
```cpp
        if(nums.size() == 1) return to_string(nums[0]);
```
- If the input list `nums` contains only one element, the result is simply that element as a string. 
- We convert the integer to a string using `to_string(nums[0])`.

#### 3. **Handling Two Elements**
```cpp
        if(nums.size() == 2) return to_string(nums[0]) + '/' + to_string(nums[1]);
```
- If the list contains exactly two numbers, the division expression is simply the first number divided by the second number, formatted as a string with the '/' operator.
- The result is returned in the format `"num1/num2"`.

#### 4. **Handling More Than Two Elements**
```cpp
        for(int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]) + "/";
            if(i == 0)
                s += "(";
        }
```
- For more than two elements, the function iterates through the list of numbers.
- For each number, it appends that number to the string `s`, followed by a "/" (to represent the division).
- If the current number is the first one (`i == 0`), it adds an opening parenthesis `(` to the string, indicating that the rest of the numbers will be divided inside the parentheses.

#### 5. **Closing Parenthesis**
```cpp
        s[s.size() -1] = ')';
        return s;
    }
};
```
- After the loop finishes, the string `s` will have an extra '/' at the end. This is replaced with a closing parenthesis `)`, ensuring that the entire expression is wrapped inside parentheses (except for the first number).
- The final division expression is then returned.

### Complexity

#### Time Complexity:
- The function processes each number in the `nums` list exactly once, and for each number, it performs constant time operations (string concatenation).
- Therefore, the time complexity is **O(n)**, where `n` is the size of the `nums` list.

#### Space Complexity:
- The space complexity is dominated by the string `s`, which stores the division expression. Since the length of the string is proportional to the number of elements in the `nums` list, the space complexity is also **O(n)**.

### Conclusion

This solution efficiently constructs the optimal division expression for a given list of integers. By following the simple rules of division and leveraging parentheses to maximize the result, the function ensures the largest possible value for the division expression. The solution is optimized for both time and space, and its performance is linear with respect to the size of the input list.

The function `optimalDivision` works for:
- One element by returning it directly.
- Two elements by performing a simple division.
- More than two elements by formatting the result to maximize the division.

This approach provides an elegant and efficient solution to the problem by using basic string manipulation and mathematical insights into division. It's a perfect example of how to optimize expressions in mathematical problems through careful structuring of operations, ensuring that the code runs efficiently and produces the correct result.

[`Link to LeetCode Lab`](https://leetcode.com/problems/optimal-division/description/)

---
{{< youtube SFNvfrvWxVQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
