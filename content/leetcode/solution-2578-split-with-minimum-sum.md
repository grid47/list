
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
comments = true
+++



---
Given a positive integer num, split it into two non-negative integers num1 and num2 such that the concatenation of num1 and num2 is a permutation of the digits of num. The goal is to minimize the sum of num1 and num2.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a positive integer num.
- **Example:** `For example, num = 8657.`
- **Constraints:**
	- 10 <= num <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** The output is an integer, the minimum possible sum of num1 and num2 after splitting the digits of num.
- **Example:** `For num = 592, the output is 56.`
- **Constraints:**
	- The output is an integer representing the minimal possible sum.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find the minimum sum after splitting the digits of num into two valid numbers.

- 1. Extract the digits of num.
- 2. Sort the digits in ascending order to minimize the sum.
- 3. Distribute the digits alternatively between num1 and num2 to form two valid numbers.
- 4. Compute and return the sum of num1 and num2.
{{< dots >}}
### Problem Assumptions ✅
- The number num will always have at least two digits.
{{< dots >}}
## Examples 🧩
- **Input:** `For num = 592, the output is 56.`  \
  **Explanation:** We split 592 into num1 = 5 and num2 = 9. The sum of 5 and 9 is 56, which is the minimum possible sum.

{{< dots >}}
## Approach 🚀
We approach this problem by first extracting and sorting the digits of num. Then, we distribute the digits between num1 and num2 in an alternating manner to ensure the minimal sum.

### Initial Thoughts 💭
- The digits need to be rearranged optimally to form the smallest possible sum.
- Sorting the digits in ascending order and then distributing them alternately between num1 and num2 should give the minimal sum.
{{< dots >}}
### Edge Cases 🌐
- The input will always be a valid integer with at least two digits.
- For large inputs (up to 10^9), ensure the algorithm handles large integers efficiently.
- If all digits in num are the same, num1 and num2 should be split equally to minimize the sum.
- Ensure that the final sum is the minimal possible value.
{{< dots >}}
## Code 💻
```cpp
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
```

This function takes an integer 'num', splits its digits, sorts them, and then processes them in a specific manner to return a modified sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Block**
	```cpp
	int splitNum(int num) {
	```
	Function declaration: Starts the splitNum function with an integer input.

2. **Variable Initialization**
	```cpp
	    int num1 = 0, num2 = 0, x = 1;
	```
	Initializes variables num1, num2 for storing results, and x for scaling the digits during the second loop.

3. **Variable Initialization**
	```cpp
	    vector<int> v;
	```
	Creates a vector 'v' to store individual digits of the number.

4. **Loop**
	```cpp
	    while(num){
	```
	Begins a loop that continues as long as there are digits in the number.

5. **Action**
	```cpp
	        v.push_back(num%10);
	```
	Extracts the last digit of 'num' and adds it to the vector 'v'.

6. **Action**
	```cpp
	        num /= 10;
	```
	Divides 'num' by 10 to remove the last digit.

7. **Action**
	```cpp
	    sort(v.begin(),v.end());
	```
	Sorts the vector 'v' containing digits in ascending order.

8. **Variable Initialization**
	```cpp
	    num = 0;
	```
	Resets 'num' to 0 before processing the sorted digits.

9. **Loop**
	```cpp
	    for(auto &i: v){
	```
	Starts a loop to process each digit in the sorted vector.

10. **Action**
	```cpp
	        num *= 10;
	```
	Multiplies 'num' by 10 to shift left by one digit.

11. **Action**
	```cpp
	        num += i;
	```
	Adds the current digit 'i' from the sorted vector to 'num'.

12. **Loop**
	```cpp
	    while(num){
	```
	Starts a loop to process the number with sorted digits.

13. **Action**
	```cpp
	        num1 += x*(num%10);
	```
	Extracts the last digit of 'num' and adds it to 'num1' scaled by 'x'.

14. **Action**
	```cpp
	        num /= 10;
	```
	Divides 'num' by 10 to remove the last digit.

15. **Action**
	```cpp
	        num2 += x*(num%10);
	```
	Extracts the last digit of 'num' again and adds it to 'num2' scaled by 'x'.

16. **Action**
	```cpp
	        num /= 10;
	```
	Divides 'num' by 10 again to remove the last digit.

17. **Action**
	```cpp
	        x *= 10;
	```
	Multiplies 'x' by 10 to scale the next digit in the next iteration.

18. **Return**
	```cpp
	    return num1+num2;
	```
	Returns the sum of 'num1' and 'num2' as the result of the function.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(d log d)
- **Average Case:** O(d log d)
- **Worst Case:** O(d log d)

The time complexity is dominated by the sorting step, where d is the number of digits in num.

### Space Complexity 💾
- **Best Case:** O(d)
- **Worst Case:** O(d)

The space complexity is O(d) due to the storage of the digits of num.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/split-with-minimum-sum/description/)

---
{{< youtube rRksdLnCAqI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
