
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
+++



---
**Code:**

{{< highlight cpp >}}
class StockSpanner {
    stack<pair<int, int>> cp;
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
 */
{{< /highlight >}}
---

### Problem Statement

The problem asks us to design a **StockSpanner** class that supports the following method:
- `next(price)` — this method will receive an integer `price` representing the current day's stock price. It should return an integer that represents the **span** of the stock's price, defined as the number of consecutive days (including today) where the stock price was less than or equal to `price`.

The **span** of a stock is the number of consecutive days up to the current day where the stock price was greater than or equal to today's price. For example, if the stock prices for the last 5 days are `[100, 80, 60, 70, 60]`, and today's price is 75, then the stock span for the day with price 75 would be 2, since the price was greater than or equal to 75 on the two previous days.

We are to implement the class `StockSpanner` that efficiently calculates the span for each price on each call to `next(price)`.

### Approach

To solve this problem efficiently, we can use a **monotonic stack** to track the indices of the stock prices in a way that allows us to efficiently calculate the span for each price.

#### **Explanation of Approach**

1. **Monotonic Stack**:
   - We use a stack to store pairs of stock prices and their corresponding spans. Each pair contains:
     - The stock price on a particular day.
     - The span of that stock price, which is how many consecutive days (including the current day) the stock price has been greater than or equal to the price on that day.
   
2. **Pop from Stack**:
   - For each new price, we compare it with the price at the top of the stack. If the price at the top of the stack is less than or equal to the new price, we pop that price from the stack and add its span to the span of the new price.
   - This is because the span of the current price will include the span of the prices that are less than or equal to it (as we can include all consecutive days where the price was less than or equal to the current price).

3. **Update Span**:
   - If we pop items from the stack, we continue adding their spans to the current span until we find a price greater than the current price or the stack becomes empty. 
   - Once the stack is empty or we find a price greater than the current price, the span for the current price is calculated and pushed onto the stack.

4. **Efficiency**:
   - Each price is pushed and popped from the stack at most once, making the time complexity of each `next(price)` call **O(1)**, leading to an overall **O(n)** time complexity for a sequence of `n` price inputs.

### Code Breakdown (Step by Step)

#### **Class Definition**
```cpp
class StockSpanner {
    stack<pair<int, int>> cp;
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
```

1. **StockSpanner Class**:
   - We define the class `StockSpanner` with a private member `cp`, which is a stack of pairs.
     - The stack stores pairs of `(price, span)`, where `price` is the stock price on a given day, and `span` is the stock span for that price.

2. **Constructor**:
   - The constructor initializes the stack `cp` to be empty. It does not need to take any parameters since we initialize the stack when a new `StockSpanner` object is created.

3. **`next(price)` Method**:
   - **Initialize Span**: We initialize `res` to 1 because the span of the current day's price is at least 1 (the price itself).
     ```cpp
     int res = 1;
     ```
   
   - **Pop Prices from the Stack**:
     - We enter a loop where we check if the stack is non-empty and the price at the top of the stack is less than or equal to the current price (`cp.top().first <= price`).
     - If this condition is true, we add the span of the top element (`cp.top().second`) to the result (`res`) and pop the top element off the stack.
     ```cpp
     while(!cp.empty() && cp.top().first <= price) {
         res += cp.top().second;
         cp.pop();
     }
     ```
   
   - **Push Current Price and Span onto the Stack**:
     - After processing any prices from the stack, we push the current price and its span onto the stack.
     ```cpp
     cp.push(make_pair(price, res));
     ```
   
   - **Return the Span**:
     - Finally, we return the span for the current price, which is stored in `res`.
     ```cpp
     return res;
     ```

4. **Example Usage**:
   - An instance of the `StockSpanner` class is created, and we repeatedly call `next(price)` to get the span for each stock price.
   ```cpp
   StockSpanner* obj = new StockSpanner();
   int param_1 = obj->next(price);
   ```

### Complexity

#### **Time Complexity**

- Each price is pushed onto the stack and popped from the stack at most once. As a result, the time complexity for each `next(price)` call is **O(1)**, and for a sequence of `n` price inputs, the overall time complexity is **O(n)**.

#### **Space Complexity**

- The space complexity of the solution is **O(n)**, where `n` is the number of stock prices in the sequence. This is because, in the worst case, all prices could be stored in the stack, each having a corresponding span.

### Conclusion

The `StockSpanner` class provides an efficient solution for calculating the span of stock prices using a **monotonic stack**. By leveraging the stack to store pairs of stock prices and their corresponding spans, we can efficiently compute the span for each price with each `next(price)` call in constant time, resulting in an overall time complexity of **O(n)** for `n` price inputs.

The solution is both space-efficient and time-efficient, handling even large sequences of stock prices efficiently. The stack-based approach ensures that we only need to process each stock price once, making it an optimal solution for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/online-stock-span/description/)

---
{{< youtube slYh0ZNEqSw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
