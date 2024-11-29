
+++
authors = ["grid47"]
title = "Leetcode 2605: Form Smallest Number From Two Digit Arrays"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2605: Form Smallest Number From Two Digit Arrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "ZlVNO8BFBCY"
youtube_upload_date="2023-04-01"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ZlVNO8BFBCY/maxresdefault.webp"
comments = true
+++



---
You are given two arrays nums1 and nums2, both containing unique digits. Your task is to find the smallest possible number that contains at least one digit from both arrays. If there are common digits between the two arrays, the smallest common digit will be the answer. If no common digit exists, return the smallest number formed by taking the smallest digit from each array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given two arrays nums1 and nums2. Both arrays consist of unique digits between 1 and 9.
- **Example:** `nums1 = [8, 2, 5], nums2 = [6, 1]`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 9
	- 1 <= nums1[i], nums2[i] <= 9
	- All digits in each array are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the smallest number that contains at least one digit from each array. If there is a common digit between the two arrays, return it. If not, return the smallest number formed by combining the smallest digit from each array.
- **Example:** `Output: 15`
- **Constraints:**
	- Output should be a single integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find the smallest number containing at least one digit from each array.

- Check if there is any common digit between nums1 and nums2.
- If there is a common digit, return that digit as the result.
- If no common digit exists, return the smallest number formed by combining the smallest digits from both arrays.
{{< dots >}}
### Problem Assumptions ✅
- The arrays nums1 and nums2 will always contain unique digits.
{{< dots >}}
## Examples 🧩
- **Input:** `nums1 = [8, 2, 5], nums2 = [6, 1]`  \
  **Explanation:** There are no common digits between the arrays. The smallest number formed by combining the smallest digits from nums1 and nums2 is 15, which is the correct answer.

- **Input:** `nums1 = [1, 2, 3], nums2 = [3, 4, 5]`  \
  **Explanation:** The common digit between the two arrays is 3. Therefore, the smallest number that contains a digit from both arrays is 3.

{{< dots >}}
## Approach 🚀
To solve the problem, we first check for common digits between the two arrays. If there is one, we return that digit. Otherwise, we return the smallest number formed by combining the smallest digits from both arrays.

### Initial Thoughts 💭
- The problem involves checking for common digits and then determining the smallest possible number.
- We can efficiently check for common digits by using sets or direct comparison between the two arrays.
{{< dots >}}
### Edge Cases 🌐
- There will be no empty inputs as both nums1 and nums2 contain at least one digit.
- Both arrays can have at most 9 digits, so the input size is small.
- Consider cases where the arrays share one or more common digits.
- Ensure that the solution works for all cases with unique digits between 1 and 9.
{{< dots >}}
## Code 💻
```cpp
int minNumber(vector<int>& nums1, vector<int>& nums2) {
    int num1 = nums1[0];
    set<int> cnt;
    int mn = 10;

    for(int i = 0; i < nums1.size(); i++) {
        cnt.insert(nums1[i]);
        num1 = min(nums1[i], num1);
    }
    
    int num2 = nums2[0];
    for(int i = 0; i < nums2.size(); i++) {
        if(cnt.count(nums2[i])) {
            mn = min(mn, nums2[i]);
        };
        num2 = min(nums2[i], num2);
    }
    if(mn < 10) return mn;
    if(num1 < num2) {
        return num1 * 10 + num2;
    } else {
        return num2 * 10 + num1;            
    }
}
```

This function finds the smallest possible number formed by digits from two input arrays, nums1 and nums2. The function works by first calculating the minimum values and common elements between the two arrays, and then returning the smallest combination of numbers from them.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int minNumber(vector<int>& nums1, vector<int>& nums2) {
	```
	The function starts by taking two input arrays, nums1 and nums2, which represent two lists of integers.

2. **Variable Initialization**
	```cpp
	    int num1 = nums1[0];
	```
	The first element of nums1 is assigned to num1, which will hold the minimum value in the first array.

3. **Set Initialization**
	```cpp
	    set<int> cnt;
	```
	A set 'cnt' is created to store unique values from nums1, helping with finding common elements between the two arrays.

4. **Variable Initialization**
	```cpp
	    int mn = 10;
	```
	A variable 'mn' is initialized to 10, which is used to track the minimum value found from the common elements of nums1 and nums2.

5. **Looping Through Array 1**
	```cpp
	    for(int i = 0; i < nums1.size(); i++) {
	```
	This loop iterates through all elements of nums1 to populate the set 'cnt' and update the minimum value of num1.

6. **Set Insertion**
	```cpp
	        cnt.insert(nums1[i]);
	```
	Each element of nums1 is inserted into the set 'cnt' to ensure all elements are unique.

7. **Updating Minimum Value**
	```cpp
	        num1 = min(nums1[i], num1);
	```
	The minimum value of nums1 is updated during each iteration of the loop.

8. **Variable Initialization**
	```cpp
	    int num2 = nums2[0];
	```
	The first element of nums2 is assigned to num2, which will hold the minimum value in the second array.

9. **Looping Through Array 2**
	```cpp
	    for(int i = 0; i < nums2.size(); i++) {
	```
	This loop iterates through all elements of nums2 and checks for common elements between nums1 and nums2.

10. **Checking for Common Elements**
	```cpp
	        if(cnt.count(nums2[i])) {
	```
	This checks if the current element of nums2 exists in the set 'cnt' (i.e., it is a common element).

11. **Updating Minimum Value**
	```cpp
	            mn = min(mn, nums2[i]);
	```
	If a common element is found, the minimum value 'mn' is updated with the smaller of the two values.

12. **Updating Minimum Value**
	```cpp
	        num2 = min(nums2[i], num2);
	```
	The minimum value of nums2 is updated during each iteration of the loop.

13. **Returning the Result**
	```cpp
	    if(mn < 10) return mn;
	```
	If a common element was found (mn < 10), return the smallest common element.

14. **Condition Check**
	```cpp
	    if(num1 < num2) {
	```
	This checks if num1 is smaller than num2.

15. **Returning the Result**
	```cpp
	        return num1 * 10 + num2;
	```
	If num1 is smaller, return the number formed by concatenating num1 and num2.

16. **Condition Check**
	```cpp
	    } else {
	```
	Else condition if num1 is not smaller than num2.

17. **Returning the Result**
	```cpp
	        return num2 * 10 + num1;            
	```
	If num1 is not smaller than num2, return the number formed by concatenating num2 and num1.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(n)
- **Worst Case:** O(n)

In the worst case, we check all elements of both arrays, which requires O(n) time where n is the size of the arrays (at most 9).

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n)

We store sets for quick lookup, requiring O(n) space in the worst case, where n is the size of the arrays (at most 9).

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays/description/)

---
{{< youtube ZlVNO8BFBCY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
