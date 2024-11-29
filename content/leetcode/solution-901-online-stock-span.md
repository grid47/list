
+++
authors = ["grid47"]
title = "Leetcode 901: Online Stock Span"
date = "2024-08-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 901: Online Stock Span in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Stack","Design","Monotonic Stack","Data Stream"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "slYh0ZNEqSw"
youtube_upload_date="2022-02-12"
youtube_thumbnail="https://i.ytimg.com/vi/slYh0ZNEqSw/maxresdefault.jpg"
comments = true
+++



---
Design a system that processes daily stock price quotes and computes the price span for the current day. The price span for a day is defined as the maximum number of consecutive days (including today) where the price of the stock was less than or equal to today's price.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a sequence of operations where a 'next' operation receives the stock price of the current day.
- **Example:** `Input: ["StockSpanner", "next", "next", "next", "next", "next", "next"]
[[], [120], [95], [100], [90], [130], [125]]`
- **Constraints:**
	- 1 <= price <= 100000
	- At most 10000 calls to the 'next' function.

{{< dots >}}
### Output Specifications 📤
- **Output:** For each 'next' operation, output the price span for the provided stock price.
- **Example:** `Output: [null, 1, 1, 2, 1, 5, 2]`
- **Constraints:**
	- Output is an integer for each 'next' operation, except the initialization which outputs null.

{{< dots >}}
### Core Logic 🔍
**Goal:** Compute the price span efficiently using a stack-based approach.

- 1. Maintain a stack of price-span pairs.
- 2. For each new price, pop elements from the stack if they are less than or equal to the current price.
- 3. Sum the spans of the popped elements and include today's span (1).
- 4. Push the current price and its computed span onto the stack.
- 5. Return the span for the current day.
{{< dots >}}
### Problem Assumptions ✅
- The input price is always a valid integer within the given range.
- The operations will always follow the sequence provided in the example.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: ["StockSpanner", "next", "next", "next", "next", "next", "next"]
[[], [90], [85], [95], [85], [110], [105]]`  \
  **Explanation:** Output: [null, 1, 1, 3, 1, 5, 2]
Explanation: The span for each price is computed as follows:
1. [90]: Span = 1
2. [85]: Span = 1
3. [95]: Span = 3 (90, 85, 95)
4. [85]: Span = 1
5. [110]: Span = 5 (90, 85, 95, 85, 110)
6. [105]: Span = 2 (110, 105)

{{< dots >}}
## Approach 🚀
Use a stack-based approach to efficiently compute the span for each day's stock price.

### Initial Thoughts 💭
- Brute force computation for each day's span would result in O(n^2) time complexity.
- We can optimize using a stack to track previous prices and spans.
- A stack allows us to efficiently manage and compute spans by keeping track of relevant previous days.
{{< dots >}}
### Edge Cases 🌐
- No empty inputs, as 'next' operations always receive a valid price.
- Handles maximum constraints with 10^4 operations and prices up to 10^5.
- Test cases with consecutive equal prices.
- Test cases with strictly increasing or decreasing prices.
- Input adheres to constraints and does not exceed operational limits.
{{< dots >}}
## Code 💻
```cpp
public:
StockSpanner() {
    
}

int next(int price) {
    
    int res = 1;
    
    while(!cp.empty() && cp.top().first <= price) {
        res += cp.top().second;
        cp.pop();
    }
    
    cp.push(make_pair(price, res));
    
    return res;
}
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
```

This is the implementation of the StockSpanner class. The next method computes the span of stock prices using a stack.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Access Specifier**
	```cpp
	public:
	```
	Defines the access specifier for the following class methods and variables, making them accessible outside the class.

2. **Constructor**
	```cpp
	StockSpanner() {
	```
	Constructor for the StockSpanner class. Initializes the stack and prepares the object.

3. **Constructor Body**
	```cpp
	    
	```
	Placeholder for constructor body if needed in the future.

4. **Function Definition**
	```cpp
	int next(int price) {
	```
	Defines the next method, which calculates the span of stock prices for the current price.

5. **Variable Initialization**
	```cpp
	    int res = 1;
	```
	Initializes the result variable to 1, which represents the span of the current stock price.

6. **Loop**
	```cpp
	    while(!cp.empty() && cp.top().first <= price) {
	```
	Starts a loop that pops elements from the stack as long as the stack is not empty and the stock price is greater than the top element of the stack.

7. **Update Result**
	```cpp
	        res += cp.top().second;
	```
	Updates the result by adding the span value of the top element of the stack.

8. **Pop Stack**
	```cpp
	        cp.pop();
	```
	Pops the top element from the stack, as its span has been added to the result.

9. **Push Stack**
	```cpp
	    cp.push(make_pair(price, res));
	```
	Pushes the current stock price and its corresponding span into the stack.

10. **Return Statement**
	```cpp
	    return res;
	```
	Returns the calculated span for the current stock price.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) per operation when most prices are decreasing.
- **Average Case:** O(1) amortized per operation due to stack operations.
- **Worst Case:** O(n) for n operations, where all elements are popped once.

Each element is pushed and popped from the stack at most once.

### Space Complexity 💾
- **Best Case:** O(1), when prices decrease consistently.
- **Worst Case:** O(n), where n is the number of operations.

Stack space depends on the number of elements stored.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/online-stock-span/description/)

---
{{< youtube slYh0ZNEqSw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
