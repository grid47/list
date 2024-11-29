
+++
authors = ["grid47"]
title = "Leetcode 2231: Largest Number After Digit Swaps by Parity"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2231: Largest Number After Digit Swaps by Parity in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "UNbggCsJ6LE"
youtube_upload_date="2022-04-10"
youtube_thumbnail="https://i.ytimg.com/vi_webp/UNbggCsJ6LE/maxresdefault.webp"
comments = true
+++



---
You are given a positive integer `num`. You are allowed to swap any two digits of `num` that have the same parity (i.e., both digits are either odd or both even). The goal is to return the largest possible value of `num` after any number of swaps.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a positive integer `num`.
- **Example:** `num = 8235`
- **Constraints:**
	- 1 <= num <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the largest possible value of `num` after performing any number of valid swaps.
- **Example:** `Output: 8532`
- **Constraints:**
	- The result will be a positive integer.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to maximize the number by swapping digits of the same parity. To achieve this, we will use priority queues to store the odd and even digits in descending order and then place the largest possible digits at their respective positions.

- 1. Convert the number into a string to easily access each digit.
- 2. Separate the odd and even digits into two different priority queues, ensuring the digits are stored in descending order.
- 3. For each digit in the original number, replace it with the largest available odd or even digit from the respective priority queue, depending on its parity.
{{< dots >}}
### Problem Assumptions ✅
- The input is always a valid positive integer.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: num = 8235`  \
  **Explanation:** In this case, we have two even digits (8, 2) and two odd digits (3, 5). After sorting both even and odd digits in descending order, we get 8, 2 for evens and 5, 3 for odds. Swapping the digits gives the largest possible number: 8532.

- **Input:** `Input: num = 4321`  \
  **Explanation:** Here, we have two even digits (4, 2) and two odd digits (3, 1). After sorting, we get 4, 2 for evens and 3, 1 for odds. Swapping the digits to maximize the value results in 4321, which is already the largest possible number.

{{< dots >}}
## Approach 🚀
The approach involves using priority queues (heaps) to rearrange the digits in such a way that maximizes the number. We separate the even and odd digits, store them in descending order, and then reconstruct the number by assigning the largest available digits to each place.

### Initial Thoughts 💭
- Sorting the digits by parity allows us to focus on the largest possible number for each set of digits.
- The problem can be solved by treating it as a sorting problem for two distinct groups of digits: even and odd.
{{< dots >}}
### Edge Cases 🌐
- There are no empty inputs as the problem guarantees that `num` is always a positive integer.
- The input will not exceed 9 digits, so the solution should efficiently handle the maximum size.
- If `num` consists of only even or only odd digits, the number is already the largest possible number.
- The solution must handle cases where all digits have the same parity.
{{< dots >}}
## Code 💻
```cpp
int largestInteger(int num) {
    priority_queue<int> p; // priority queue to store odd digits in descending order
    priority_queue<int> q; // priority queue to store even digits in descending order
    string nums=to_string(num); // converting num to a string for easy access of the digits
    int n=nums.size(); // n stores the number of digits in num
    
    for(int i=0;i<n;i++){
        int digit=nums[i]-'0'; 
        if((digit)%2) // if digit is odd, push it into priority queue p
            p.push(digit);
        else
            q.push(digit); // if digit is even, push it into priority queue q
    }
    
    int answer=0;
    for(int i=0; i<n; i++){
        answer=answer*10;
        if((nums[i]-'0')%2) // if the digit is odd, add the largest odd digit of p into the answer
            {answer+=p.top();p.pop();}
        else
            {answer+=q.top();q.pop();} // if the digit is even, add the largest even digit of q into the answer
    }
    return answer;
}
```

This code aims to rearrange the digits of a number such that the largest odd digits are placed in odd positions, and the largest even digits are placed in even positions.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	int largestInteger(int num) {
	```
	The function `largestInteger` is declared, taking an integer `num` as input and returning an integer as the output.

2. **Priority Queue Declaration**
	```cpp
	    priority_queue<int> p; // priority queue to store odd digits in descending order
	```
	A priority queue `p` is declared to store the odd digits from `num` in descending order.

3. **Priority Queue Declaration**
	```cpp
	    priority_queue<int> q; // priority queue to store even digits in descending order
	```
	Another priority queue `q` is declared to store the even digits from `num` in descending order.

4. **String Conversion**
	```cpp
	    string nums=to_string(num); // converting num to a string for easy access of the digits
	```
	The integer `num` is converted into a string `nums` for easier access to its individual digits.

5. **Variable Initialization**
	```cpp
	    int n=nums.size(); // n stores the number of digits in num
	```
	The variable `n` is initialized to the size of the string `nums`, representing the number of digits in the input number.

6. **For Loop**
	```cpp
	    for(int i=0;i<n;i++){
	```
	A `for` loop is initiated to iterate through each character (digit) of the string `nums`.

7. **Digit Extraction**
	```cpp
	        int digit=nums[i]-'0'; 
	```
	Each character in the string `nums` is converted back to an integer `digit`.

8. **Condition Check**
	```cpp
	        if((digit)%2) // if digit is odd, push it into priority queue p
	```
	A condition checks if the current digit is odd by checking if the digit modulo 2 is non-zero.

9. **Priority Queue Insert**
	```cpp
	            p.push(digit);
	```
	If the digit is odd, it is pushed into the priority queue `p`.

10. **Else Statement**
	```cpp
	        else
	```
	If the digit is not odd (i.e., it is even), the following code block will execute.

11. **Priority Queue Insert**
	```cpp
	            q.push(digit); // if digit is even, push it into priority queue q
	```
	If the digit is even, it is pushed into the priority queue `q`.

12. **Variable Initialization**
	```cpp
	    int answer=0;
	```
	A variable `answer` is initialized to 0, which will store the final rearranged number.

13. **For Loop**
	```cpp
	    for(int i=0; i<n; i++){
	```
	A second `for` loop is initiated to reconstruct the number based on the priority queues.

14. **Answer Calculation**
	```cpp
	        answer=answer*10;
	```
	The variable `answer` is updated by multiplying the current value by 10, making space for the next digit.

15. **Condition Check**
	```cpp
	        if((nums[i]-'0')%2) // if the digit is odd, add the largest odd digit of p into the answer
	```
	A condition checks if the current digit in `nums` is odd. If it is, the largest odd digit from `p` will be added to `answer`.

16. **Priority Queue Pop**
	```cpp
	            {answer+=p.top();p.pop();}
	```
	If the digit is odd, the top element from priority queue `p` (largest odd digit) is added to `answer` and popped from the queue.

17. **Else Statement**
	```cpp
	        else
	```
	If the digit is even, the following code block will execute.

18. **Priority Queue Pop**
	```cpp
	            {answer+=q.top();q.pop();} // if the digit is even, add the largest even digit of q into the answer
	```
	If the digit is even, the top element from priority queue `q` (largest even digit) is added to `answer` and popped from the queue.

19. **Return Statement**
	```cpp
	    return answer;
	```
	The function returns the final rearranged number `answer`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The sorting of digits in the priority queues dominates the time complexity, where `n` is the number of digits in `num`.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

We use space for storing the even and odd digits, which requires O(n) space where `n` is the number of digits in `num`.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/)

---
{{< youtube UNbggCsJ6LE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
