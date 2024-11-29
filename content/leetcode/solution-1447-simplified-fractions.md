
+++
authors = ["grid47"]
title = "Leetcode 1447: Simplified Fractions"
date = "2024-06-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1447: Simplified Fractions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "xAPYdvSkcF8"
youtube_upload_date="2020-05-17"
youtube_thumbnail="https://i.ytimg.com/vi/xAPYdvSkcF8/hqdefault.jpg?sqp=-oaymwEmCOADEOgC8quKqQMa8AEB-AHUBoAC4AOKAgwIABABGGUgZSgVMA8=&rs=AOn4CLA8kfJhe38vkPWigQhNMfXCO873lw"
comments = true
+++



---
Given an integer `n`, return a list of all unique simplified fractions between 0 and 1 (exclusive) where the denominator is less than or equal to `n`. A fraction is simplified if the greatest common divisor (GCD) of the numerator and denominator is 1. The result can be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** An integer `n` representing the maximum allowed value for the denominator.
- **Example:** `Input: n = 4`
- **Constraints:**
	- 1 <= n <= 100

{{< dots >}}
### Output Specifications 📤
- **Output:** A list of strings representing all unique simplified fractions between 0 and 1 with denominators up to `n`.
- **Example:** `Output: ["1/2", "1/3", "1/4", "2/3", "3/4"]`
- **Constraints:**
	- The list can be in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** Generate all unique simplified fractions with denominators up to `n`.

- Iterate through all possible denominators from 2 to `n`.
- For each denominator, iterate through numerators from 1 to denominator-1.
- Check if the GCD of the numerator and denominator is 1. If true, add the fraction to the result list.
{{< dots >}}
### Problem Assumptions ✅
- The denominator of the fraction is always greater than the numerator.
- Fractions must be strictly between 0 and 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: n = 5`  \
  **Explanation:** Output: ["1/2", "1/3", "1/4", "1/5", "2/3", "2/5", "3/4", "3/5", "4/5"]. These are all the simplified fractions between 0 and 1 with denominators less than or equal to 5.

- **Input:** `Input: n = 2`  \
  **Explanation:** Output: ["1/2"]. Only one unique fraction exists with denominator less than or equal to 2.

- **Input:** `Input: n = 3`  \
  **Explanation:** Output: ["1/2", "1/3", "2/3"]. The fraction "2/3" is included as it is simplified and lies between 0 and 1.

{{< dots >}}
## Approach 🚀
Use nested loops to generate fractions and filter out non-simplified ones using the GCD.

### Initial Thoughts 💭
- Each denominator can produce multiple numerators, but only some result in simplified fractions.
- The GCD function is useful for checking if a fraction is simplified.
- Iterating over all possible combinations and filtering based on the GCD is an efficient approach for the given constraints.
{{< dots >}}
### Edge Cases 🌐
- Input: n = 1 -> Output: []. No valid fractions exist for n = 1.
- Input: n = 100 -> Should return all valid simplified fractions between 0 and 1 with denominators up to 100 efficiently.
- Input: n = 2 -> Output: ["1/2"]. Only one valid fraction.
- Input: n = 10 -> Output: Should include fractions such as "1/10" and "9/10".
- Ensure proper handling of GCD calculations for large values.
{{< dots >}}
## Code 💻
```cpp
vector<string> simplifiedFractions(int n) {
    if(n == 1) return {};
    vector<string> res;
    queue<tuple<int, int, int, int>> q;
    q.emplace(0, 1, 1, 1);
    while(!q.empty()) {
        auto [num1, den1, num2, den2] = q.front();
        q.pop();
        int num = num1 + num2;
        int den = den1 + den2;
        res.push_back(to_string(num) + "/" + to_string(den));
        if(den + den1 <= n) q.emplace(num1, den1, num, den);
        if(den + den2 <= n) q.emplace(num, den, num2, den2);
    }
    return res;
}
```

This function calculates all simplified fractions for a given integer n, returning them as strings in the form of 'num/den'. It uses a breadth-first search to explore fractions formed by adding pairs of fractions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<string> simplifiedFractions(int n) {
	```
	This is the function header where the return type is a vector of strings and the parameter is an integer n, representing the maximum denominator for the fractions.

2. **Conditional Check**
	```cpp
	    if(n == 1) return {};
	```
	If n equals 1, return an empty vector since no simplified fractions exist for this case.

3. **Variable Declaration**
	```cpp
	    vector<string> res;
	```
	Declare a vector of strings to store the resulting simplified fractions.

4. **Queue Initialization**
	```cpp
	    queue<tuple<int, int, int, int>> q;
	```
	Initialize a queue to store tuples of integers representing the numerators and denominators of two fractions being added.

5. **Queue Operation**
	```cpp
	    q.emplace(0, 1, 1, 1);
	```
	Add the initial fraction (0/1) and (1/1) to the queue for further processing.

6. **While Loop**
	```cpp
	    while(!q.empty()) {
	```
	Begin a while loop that continues as long as there are items in the queue.

7. **Queue Pop**
	```cpp
	        auto [num1, den1, num2, den2] = q.front();
	```
	Extract the front element of the queue, which contains the numerators and denominators of two fractions.

8. **Queue Operation**
	```cpp
	        q.pop();
	```
	Remove the front element from the queue after it has been processed.

9. **Mathematical Operation**
	```cpp
	        int num = num1 + num2;
	```
	Calculate the numerator of the new fraction by adding the numerators of the two fractions.

10. **Mathematical Operation**
	```cpp
	        int den = den1 + den2;
	```
	Calculate the denominator of the new fraction by adding the denominators of the two fractions.

11. **Vector Operation**
	```cpp
	        res.push_back(to_string(num) + "/" + to_string(den));
	```
	Convert the new fraction to a string and add it to the result vector.

12. **Conditional Check**
	```cpp
	        if(den + den1 <= n) q.emplace(num1, den1, num, den);
	```
	If the sum of the denominator of the new fraction and the first fraction's denominator is less than or equal to n, add this new fraction to the queue for further processing.

13. **Conditional Check**
	```cpp
	        if(den + den2 <= n) q.emplace(num, den, num2, den2);
	```
	If the sum of the denominator of the new fraction and the second fraction's denominator is less than or equal to n, add this new fraction to the queue for further processing.

14. **Return Statement**
	```cpp
	    return res;
	```
	Return the vector containing all the simplified fractions.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^2)
- **Average Case:** O(n^2)
- **Worst Case:** O(n^2)

Iterating over all possible numerator and denominator pairs up to `n`.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n^2)

Storing the result list requires space proportional to the number of valid fractions.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/simplified-fractions/description/)

---
{{< youtube xAPYdvSkcF8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
