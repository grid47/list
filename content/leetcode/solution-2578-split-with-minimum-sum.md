
+++
authors = ["grid47"]
title = "Leetcode 2578: Split With Minimum Sum"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2578: Split With Minimum Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "rRksdLnCAqI"
youtube_upload_date="2023-03-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rRksdLnCAqI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int splitNum(int num) {
        int num1 = 0, num2 = 0, x = 1;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num /= 10;
        }
        sort(v.begin(),v.end());
        num = 0;
        for(auto &i: v){
            num *= 10;
            num += i;
        }
        while(num){
            num1 += x*(num%10);
            num /= 10;
            num2 += x*(num%10);
            num /= 10;
            x *= 10;
        }
        return num1+num2;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires you to split the digits of a given integer `num` into two numbers such that the sum of these two numbers is minimized. The approach involves sorting the digits of the number and then distributing them in an alternating manner between the two numbers, where each number is constructed from the digits to ensure the sum is minimized.

### Approach

To solve this problem, the goal is to divide the digits of the input number into two integers in such a way that their sum is minimized. The strategy is to sort the digits in ascending order and then alternate the digits between the two numbers. This ensures that the smaller digits are placed in the higher place values, which minimizes the overall sum of the two numbers. Here's a breakdown of the approach:

1. **Extract digits**: Extract all digits from the given number.
2. **Sort digits**: Sort the digits in ascending order to ensure the smallest digits are used in the most significant positions for the final numbers.
3. **Distribute digits**: Distribute the digits alternatively between two numbers, ensuring that digits are added to the numbers in a way that minimizes the sum of these two numbers.
4. **Reconstruct numbers**: After distributing the digits, reconstruct the two numbers.
5. **Calculate the sum**: The final result will be the sum of these two reconstructed numbers.

### Code Breakdown (Step by Step)

Let's break down the code step by step to understand the logic:

#### 1. **Extracting Digits**:
```cpp
int num1 = 0, num2 = 0, x = 1;
vector<int> v;
while(num){
    v.push_back(num%10);
    num /= 10;
}
```
- The code begins by initializing two variables `num1` and `num2` to hold the two numbers we will form.
- The variable `x` is used to track the place value (1, 10, 100, etc.) for the digits in the final numbers.
- A vector `v` is used to store the digits of the given number `num`.
- The `while` loop extracts the digits of `num` one by one, using the modulus operator (`% 10`) to get the least significant digit and dividing `num` by 10 to remove the digit. This continues until `num` becomes 0.

#### 2. **Sorting Digits**:
```cpp
sort(v.begin(), v.end());
```
- After extracting the digits, they are stored in the vector `v`. We then sort the digits in ascending order using the `sort` function. This ensures that the smallest digits are positioned at the beginning of the vector, which is crucial for minimizing the final sum of the two numbers.

#### 3. **Reconstructing the Numbers**:
```cpp
num = 0;
for(auto &i: v){
    num *= 10;
    num += i;
}
```
- After sorting the digits, the code reconstructs the number by iterating through the sorted vector `v` and adding each digit to the variable `num`.
- The variable `num` is multiplied by 10 each time to shift the previously added digits to the left, and the current digit `i` is added to `num` to form the reconstructed number.

#### 4. **Distributing the Digits**:
```cpp
while(num){
    num1 += x*(num%10);
    num /= 10;
    num2 += x*(num%10);
    num /= 10;
    x *= 10;
}
```
- Now that we have the sorted number, the code proceeds to distribute the digits between `num1` and `num2`. This is done by alternating the digits between the two numbers.
- The `while(num)` loop iterates through the digits of `num`, and in each iteration:
  - The least significant digit (`num % 10`) is added to `num1` and multiplied by `x` to maintain the correct place value.
  - The number is divided by 10 to remove the digit just added.
  - The next digit is added to `num2` and similarly processed.
  - The `x` value is multiplied by 10 in each iteration to adjust the place value (1, 10, 100, etc.) for the digits.

#### 5. **Return the Final Result**:
```cpp
return num1 + num2;
```
- After distributing all the digits, the function returns the sum of `num1` and `num2`, which is the final result.

### Complexity Analysis

#### Time Complexity:
1. **Extracting digits**: Extracting the digits of `num` requires iterating through the number's digits, which takes `O(d)`, where `d` is the number of digits in the number. Since the number has at most `O(log(num))` digits, this step takes `O(log(num))` time.
2. **Sorting digits**: Sorting the digits in the vector `v` takes `O(d log d)`, where `d` is the number of digits. Again, since `d` is proportional to `log(num)`, the sorting step takes `O(log(num) * log(log(num)))` time.
3. **Distributing digits**: The distribution of digits between `num1` and `num2` requires iterating through all the digits, which takes `O(d)` time. This step takes `O(log(num))` time.

Thus, the total time complexity is dominated by the sorting step and is **O(log(num) * log(log(num)))**.

#### Space Complexity:
- The space complexity is mainly due to the vector `v` that stores the digits of `num`. The space required for `v` is proportional to the number of digits in `num`, which is `O(log(num))`.
- There are no other significant space requirements in the algorithm.

Thus, the space complexity is **O(log(num))**.

### Conclusion

This solution efficiently solves the problem by extracting the digits from the given number, sorting them, and distributing them between two numbers. The final result is the sum of these two numbers, which minimizes the sum due to the optimal distribution of digits. The time complexity of **O(log(num) * log(log(num)))** and space complexity of **O(log(num))** make this approach scalable and efficient for large input sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/split-with-minimum-sum/description/)

---
{{< youtube rRksdLnCAqI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
