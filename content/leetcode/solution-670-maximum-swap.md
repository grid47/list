
+++
authors = ["grid47"]
title = "Leetcode 670: Maximum Swap"
date = "2024-09-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 670: Maximum Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/670.webp"
youtube = "arecn8VuQL0"
youtube_upload_date="2020-05-02"
youtube_thumbnail="https://i.ytimg.com/vi/arecn8VuQL0/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/670.webp" 
    alt="A number where the maximum swap is performed, with each swap softly glowing as it occurs."
    caption="Solution to LeetCode 670: Maximum Swap Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an integer `num`, and you can swap two digits at most once to get the largest possible number. Return the maximum number that can be obtained after performing the swap.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `num` which is the number whose digits need to be rearranged by swapping at most two digits to get the maximum value.
- **Example:** `num = 1234`
- **Constraints:**
	- 0 <= num <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest number that can be obtained by swapping two digits in the number at most once.
- **Example:** `4231`
- **Constraints:**
	- The number must be returned as an integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Maximize the number by swapping two digits at most once.

- 1. Convert the number into a string to easily access individual digits.
- 2. Track the index of the largest possible digit that can be swapped for each position.
- 3. For each digit, check if a swap is possible with any larger digit from a later position.
- 4. Perform the swap and return the resulting number.
{{< dots >}}
### Problem Assumptions ✅
- The number is a non-negative integer.
{{< dots >}}
## Examples 🧩
- **Input:** `num = 1234`  \
  **Explanation:** The maximum number can be obtained by swapping the digits 1 and 4, resulting in 4231.

- **Input:** `num = 9876`  \
  **Explanation:** Since the number is already in the maximum possible order, no swap is needed, and the result is 9876.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to find the largest number by performing at most one swap between two digits of the number.

### Initial Thoughts 💭
- The approach involves checking the possibility of swapping each digit with the largest available digit from the right side.
- If a swap can maximize the number, we perform the swap and return the result.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs in this problem, as the number is always provided.
- Ensure the solution handles numbers with up to 8 digits (max 10^8).
- If the number is already the largest possible form, no swap should be made.
- The number will be within the range 0 <= num <= 10^8.
{{< dots >}}
## Code 💻
```cpp
int maximumSwap(int num) {

    vector<int> idx(10, 0);

    string nm = to_string(num);
    for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;

    for(int i = 0; i < nm.size(); i++)
    for(int j = 9; j > nm[i] - '0'; j--) {
        if(idx[j] > i) {
            swap(nm[idx[j]], nm[i]);
            return stoi(nm);
        }
    }

    return num;
}
```

This function attempts to maximize the given number by performing at most one swap between any two digits. It swaps the digits in such a way that the resulting number is the largest possible number that can be obtained by one swap.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int maximumSwap(int num) {
	```
	This is the function definition for `maximumSwap`, which takes an integer `num` and returns the largest number that can be obtained by swapping two digits of `num` at most once.

2. **Initialization of Array**
	```cpp
	
	```
	An integer vector `idx` of size 10 is initialized to store the index positions of the last occurrence of each digit from 0 to 9 in the number.

3. **Index Array Initialization**
	```cpp
	    vector<int> idx(10, 0);
	```
	A vector `idx` is created and initialized to store the last index of each digit in the number `num`.

4. **Convert Number to String**
	```cpp
	
	```
	The number `num` is converted to a string so that we can easily iterate through its digits.

5. **String Conversion**
	```cpp
	    string nm = to_string(num);
	```
	Convert the number `num` into a string `nm` to facilitate manipulation of individual digits.

6. **Tracking Digit Indices**
	```cpp
	    for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;
	```
	Iterate through each digit of the string `nm` and store its index in the `idx` array. This ensures that we know the position of each digit's last occurrence.

7. **Main Loop**
	```cpp
	
	```
	The outer loop iterates through the digits of `nm` from left to right to determine which digits can be swapped for maximizing the number.

8. **Outer Loop**
	```cpp
	    for(int i = 0; i < nm.size(); i++)
	```
	This loop iterates through each digit of `nm` to determine if a larger digit can be swapped with it to form a larger number.

9. **Inner Loop**
	```cpp
	    for(int j = 9; j > nm[i] - '0'; j--) {
	```
	The inner loop looks for a larger digit, from 9 to the current digit, that appears later in the string to swap with the current digit.

10. **Check for Valid Swap**
	```cpp
	        if(idx[j] > i) {
	```
	If a digit larger than the current digit is found later in the string (`idx[j] > i`), this means we can swap these digits to form a larger number.

11. **Perform Swap**
	```cpp
	            swap(nm[idx[j]], nm[i]);
	```
	Swap the current digit `nm[i]` with the larger digit found later in the string `nm[idx[j]]`.

12. **Return Maximized Number**
	```cpp
	            return stoi(nm);
	```
	Convert the modified string back to an integer and return it as the result, representing the maximum number that can be obtained by one swap.

13. **Return Original Number**
	```cpp
	    return num;
	```
	Return the original number `num` if no valid swap was found that can maximize the number.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n), where n is the number of digits in the number. Since the number has at most 8 digits, this is efficient.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1), as we only use a constant amount of extra space.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-swap/description/)

---
{{< youtube arecn8VuQL0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
