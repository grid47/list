
+++
authors = ["grid47"]
title = "Leetcode 1352: Product of the Last K Numbers"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1352: Product of the Last K Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Design","Queue","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "fH1WYQCcMd8"
youtube_upload_date="2021-02-26"
youtube_thumbnail="https://i.ytimg.com/vi/fH1WYQCcMd8/maxresdefault.jpg"
comments = true
+++



---
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers in the stream.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence of operations: initialize the object, add numbers to the stream, and get the product of the last k numbers.
- **Example:** `For example, ['ProductOfNumbers', 'add', 'add', 'add', 'getProduct'] with input [[], [3], [0], [2], 2].`
- **Constraints:**
	- 0 <= num <= 100
	- 1 <= k <= 4 * 10^4
	- At most 4 * 10^4 calls to add and getProduct.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should be a list of integers where each element is the result of the respective 'getProduct' operation.
- **Example:** `For example, ['getProduct(2)', 'getProduct(3)'] could return 20 and 40, respectively.`
- **Constraints:**
	- The result will always fit in a 32-bit integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** Design an efficient system to keep track of the last k numbers and compute their product.

- 1. Use a list to keep track of the products of the numbers in the stream.
- 2. If a zero is encountered, reset the product history.
- 3. For each getProduct query, compute the product of the last k numbers.
{{< dots >}}
### Problem Assumptions ✅
- The input list has at least k numbers when calling 'getProduct'.
- Any sequence of numbers in the list fits within the range of a 32-bit integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: ['ProductOfNumbers', 'add', 'add', 'add', 'add', 'add', 'getProduct(2)', 'getProduct(3)', 'getProduct(4)', 'add', 'getProduct(2)']`  \
  **Explanation:** The operations add numbers to the stream, and getProduct computes the product of the last k numbers.

- **Input:** `Example 2: ['ProductOfNumbers', 'add', 'add', 'add', 'getProduct(3)']`  \
  **Explanation:** After adding numbers [1, 2, 3], the product of the last 3 numbers is 6.

{{< dots >}}
## Approach 🚀
The solution should efficiently store the running product and handle reset conditions when a zero is encountered.

### Initial Thoughts 💭
- A running product can be stored in a list where each index represents the product of numbers up to that point.
- A zero encountered resets the running product.
- We can track the product of the numbers in the stream in a way that allows us to compute the product of any k consecutive numbers.
{{< dots >}}
### Edge Cases 🌐
- No numbers added yet: Ensure no product is returned until numbers are added.
- Handling up to 4 * 10^4 operations efficiently without performance degradation.
- Zero in the stream: Reset the product list.
- Ensure that the product of the stream at any point in time fits within a 32-bit integer.
{{< dots >}}
## Code 💻
```cpp
public:
ProductOfNumbers() {
    p = {1};
}

void add(int num) {
    if(num > 0) {
        p.push_back(p.back() * num);
    } else {
        p = {1};            
    }

}

int getProduct(int k) {
    int n = p.size();
    return k < n ? p[n - 1] / p[n - k - 1]: 0;
}
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
```

This class implements a product manager for numbers. The `add` method appends a number while maintaining a cumulative product list, and `getProduct` computes the product of the last k numbers efficiently using division.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Access Modifier**
	```cpp
	public:
	```
	Declares the public access modifier for the class members.

2. **Constructor**
	```cpp
	ProductOfNumbers() {
	```
	Defines the constructor for the `ProductOfNumbers` class, initializing the cumulative product list.

3. **Initialization**
	```cpp
	    p = {1};
	```
	Initializes the product list with 1 to handle cumulative product calculations.

4. **Method Declaration**
	```cpp
	void add(int num) {
	```
	Begins the declaration of the `add` method to handle new number additions.

5. **Condition Check**
	```cpp
	    if(num > 0) {
	```
	Checks if the added number is positive to update the cumulative product list.

6. **Update Product**
	```cpp
	        p.push_back(p.back() * num);
	```
	Appends the product of the last cumulative product and the new number to the list.

7. **Reset List**
	```cpp
	    } else {
	```
	Handles the case where the added number is zero or negative by resetting the list.

8. **Reset Product**
	```cpp
	        p = {1};
	```
	Resets the cumulative product list to its initial state.

9. **Method Declaration**
	```cpp
	int getProduct(int k) {
	```
	Begins the declaration of the `getProduct` method to compute the product of the last k numbers.

10. **Size Calculation**
	```cpp
	    int n = p.size();
	```
	Calculates the size of the cumulative product list.

11. **Return Value**
	```cpp
	    return k < n ? p[n - 1] / p[n - k - 1]: 0;
	```
	Returns the product of the last k numbers if valid; otherwise, returns 0.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) when adding a number.
- **Average Case:** O(1) for each operation.
- **Worst Case:** O(k) when computing the product of the last k numbers.

The time complexity is dominated by the 'getProduct' operation, which is O(k) in the worst case.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(n) where n is the number of elements in the stream.

The space complexity is O(n) as we need to store the product for each element in the stream.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/product-of-the-last-k-numbers/description/)

---
{{< youtube fH1WYQCcMd8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
