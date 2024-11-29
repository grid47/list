
+++
authors = ["grid47"]
title = "Leetcode 2269: Find the K-Beauty of a Number"
date = "2024-03-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2269: Find the K-Beauty of a Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Sliding Window"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "23-y60kKUdY"
youtube_upload_date="2022-05-14"
youtube_thumbnail="https://i.ytimg.com/vi_webp/23-y60kKUdY/maxresdefault.webp"
comments = true
+++



---
The k-beauty of a number is defined as the number of contiguous substrings of length `k` that are divisors of the original number when it is read as a string. Your task is to determine the k-beauty of a given number `num`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer `num` and an integer `k`, where `num` is a number and `k` is the length of substrings to consider.
- **Example:** `num = 150, k = 2`
- **Constraints:**
	- 1 <= num <= 10^9
	- 1 <= k <= num.length (considering num as a string)

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the k-beauty of the number `num`, which is the number of valid divisors formed by its substrings of length `k`.
- **Example:** `Output: 2`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** To compute the number of divisors that can be formed by substrings of length `k` from the number `num`. These substrings should divide `num` without a remainder.

- Convert `num` to a string and extract all substrings of length `k`.
- Check each substring to see if it is a valid divisor of `num`.
- Count how many substrings are divisors and return that count.
{{< dots >}}
### Problem Assumptions ✅
- The input number `num` will always be positive, and the substring length `k` will not exceed the length of `num`.
{{< dots >}}
## Examples 🧩
- **Input:** `num = 150, k = 2`  \
  **Explanation:** The possible substrings of length 2 are '15', '50', '00'. Among them, '15' and '50' are divisors of 150. Therefore, the k-beauty is 2.

- **Input:** `num = 430043, k = 3`  \
  **Explanation:** The possible substrings of length 3 are '430', '300', '000', '043', '430', '043'. Only '430' is a divisor of 430043. Therefore, the k-beauty is 1.

{{< dots >}}
## Approach 🚀
To solve this problem, we can iterate through the string representation of `num`, extract substrings of length `k`, convert them to integers, and check if they are divisors of `num`.

### Initial Thoughts 💭
- We need to extract all possible substrings of length `k` from the string representation of `num`.
- Each extracted substring must be checked to see if it divides the original number `num`.
- This can be done efficiently by iterating through the string and checking divisibility. The complexity is directly related to the number of substrings we need to check.
{{< dots >}}
### Edge Cases 🌐
- There will always be at least one digit in the input `num`.
- The solution should handle large numbers efficiently, up to the constraint limits of 10^9.
- Ensure that substrings representing '0' do not result in division errors since 0 is not a valid divisor.
- The solution should work within the time limits and handle large numbers efficiently.
{{< dots >}}
## Code 💻
```cpp
int divisorSubstrings(int num, int k) {
    int res = 0, cur = 0, pow = 1;
    for (int n = num; n > 0; n /= 10) {
        cur += (n % 10) * pow;
        if (--k > 0)
            pow *= 10;
        else {
            res += cur && !(num % cur);
            cur /= 10;
        }
    }
    return res;        
}
```

This function calculates the number of k-length substrings of a given number `num` that divide `num` evenly. It processes the number by extracting digits and checking divisibility for substrings of length `k`.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int divisorSubstrings(int num, int k) {
	```
	This is the function header that defines `divisorSubstrings`, which takes two parameters: an integer `num` and an integer `k`, and returns the count of valid divisors.

2. **Variable Initialization**
	```cpp
	    int res = 0, cur = 0, pow = 1;
	```
	Initializes the variables: `res` to store the result, `cur` to store the current substring, and `pow` to calculate the place value of digits.

3. **Loop Start**
	```cpp
	    for (int n = num; n > 0; n /= 10) {
	```
	Starts a loop that processes each digit of `num` from right to left, using integer division to extract digits.

4. **Update Current Substring**
	```cpp
	        cur += (n % 10) * pow;
	```
	Extracts the last digit of `n` and adds it to `cur`, multiplied by `pow` to account for the place value of the digit.

5. **Condition to Continue Substring Building**
	```cpp
	        if (--k > 0)
	```
	Decreases `k` and checks if there are still digits to be added to the current substring (i.e., if the substring length is less than `k`).

6. **Place Value Update**
	```cpp
	            pow *= 10;
	```
	If the substring is not yet of length `k`, updates the place value (`pow`) to multiply the next digit by the correct power of 10.

7. **Condition Block for Divisibility Check**
	```cpp
	        else {
	```
	If `k` is 0 (i.e., the substring has reached length `k`), the code block checks if the current substring divides `num`.

8. **Divisibility Check**
	```cpp
	            res += cur && !(num % cur);
	```
	Checks if the current substring `cur` is a divisor of `num`. If so, increments the result `res`. The `cur && !(num % cur)` condition ensures `cur` is non-zero and divides `num` evenly.

9. **Update Current Substring**
	```cpp
	            cur /= 10;
	```
	Removes the last digit from `cur` after the divisibility check to prepare for the next iteration.

10. **Return Statement**
	```cpp
	    return res;        
	```
	Returns the final result `res`, which is the count of valid divisors found for `num`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where `n` is the length of the string representation of `num`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(1)

The space complexity is O(1) since we are only storing the result and iterating through the string.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/)

---
{{< youtube 23-y60kKUdY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
