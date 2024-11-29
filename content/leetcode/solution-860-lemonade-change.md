
+++
authors = ["grid47"]
title = "Leetcode 860: Lemonade Change"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 860: Lemonade Change in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "mSVAw0AUZgA"
youtube_upload_date="2024-08-15"
youtube_thumbnail="https://i.ytimg.com/vi/mSVAw0AUZgA/maxresdefault.jpg"
comments = true
+++



---
You are managing a lemonade stand where each lemonade costs $5. Customers are standing in line to buy one lemonade each, paying with either a $5, $10, or $20 bill. Your task is to determine if you can provide the correct change to every customer as they arrive in line. At the start, you have no change, and you must provide each customer with the appropriate change for their bill.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array, bills, where each element represents the bill a customer uses to pay for their lemonade. The bills array contains values of either 5, 10, or 20, corresponding to the bill used by each customer.
- **Example:** `Input: bills = [5, 5, 10, 5, 20]`
- **Constraints:**
	- 1 <= bills.length <= 10^5
	- bills[i] is either 5, 10, or 20.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return true if it is possible to provide the correct change for every customer in line. Otherwise, return false.
- **Example:** `Output: true`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to check if the change can be provided to each customer in the order they arrive.

- Step 1: Iterate through the array of bills and for each customer, check the bill they provide.
- Step 2: If the customer pays with a $5 bill, increment the count of $5 bills.
- Step 3: If the customer pays with a $10 bill, ensure that you have at least one $5 bill to give change. If so, give the change and update the count of $5 and $10 bills.
- Step 4: If the customer pays with a $20 bill, check if you have one $10 bill and one $5 bill to give $15 in change. If not, check if you have at least three $5 bills to provide $15 in change.
- Step 5: If you cannot provide the correct change at any point, return false.
{{< dots >}}
### Problem Assumptions ✅
- There will always be at least one customer in the queue.
- The customers will always pay with one of the allowed bills: $5, $10, or $20.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: bills = [5, 5, 10, 5, 20]`  \
  **Explanation:** In this case, the first two customers pay with $5 bills. The third customer pays with a $10 bill, and we can give $5 change. The fourth customer pays with a $5 bill, and the fifth customer pays with a $20 bill. We give them $10 change using one $10 bill and one $5 bill, and the correct change is provided for all customers.

- **Input:** `Input: bills = [5, 5, 10, 10, 20]`  \
  **Explanation:** Here, the first two customers pay with $5 bills. The next two customers pay with $10 bills, but we can't provide the correct change for the fourth customer because we only have one $5 bill, not enough to give $5 change. Therefore, the answer is false.

{{< dots >}}
## Approach 🚀
To solve this problem, we need to simulate the process of serving each customer while keeping track of the number of $5 and $10 bills we have. At each step, we must ensure that we can give the correct change to each customer in the order they arrive.

### Initial Thoughts 💭
- We need to carefully manage the number of $5 and $10 bills because these are required to provide change to customers paying with $10 and $20 bills.
- If there are more $10 bills than $5 bills, it becomes impossible to give the correct change.
- A greedy approach works well here: as we process each bill, we attempt to give the required change, and if we can't, we return false.
{{< dots >}}
### Edge Cases 🌐
- N/A: There will always be at least one customer in the queue.
- The solution must handle arrays with up to 100,000 bills efficiently.
- If the customer always pays with $5 bills, there is no issue with providing change.
- The number of customers and the values of the bills must adhere to the given constraints.
{{< dots >}}
## Code 💻
```cpp
bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int x : bills) {
             if (x == 5) five++;
        else if (x == 10) {
                 if (five > 0) five--, ten++;
            else return false;
        } else {
                 if (five > 0 && ten > 0) five--, ten--;
            else if (five > 2) five -= 3;
            else return false;
        }
    }
    return true;
}
```

This function simulates the change-making process for lemonade transactions, checking if it's possible to provide the correct change for each customer based on their bill.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	bool lemonadeChange(vector<int>& bills) {
	```
	The function begins by accepting a vector of bills that represent the bills customers pay.

2. **Variable Initialization**
	```cpp
	    int five = 0, ten = 0;
	```
	Two integer variables are initialized to track the count of 5-dollar and 10-dollar bills received.

3. **For Loop**
	```cpp
	    for (int x : bills) {
	```
	The for loop iterates over the bills array to process each bill one by one.

4. **Check for 5-dollar bill**
	```cpp
	             if (x == 5) five++;
	```
	If the current bill is 5 dollars, increment the count of 5-dollar bills.

5. **Check for 10-dollar bill**
	```cpp
	        else if (x == 10) {
	```
	If the current bill is 10 dollars, check if we can give the correct change.

6. **Provide Change for 10-dollar Bill**
	```cpp
	                 if (five > 0) five--, ten++;
	```
	If we have at least one 5-dollar bill, give one 5-dollar bill as change and accept the 10-dollar bill.

7. **Return False for Inability to Provide Change**
	```cpp
	            else return false;
	```
	If we don't have any 5-dollar bills to provide change, return false indicating we can't provide change.

8. **Check for 20-dollar bill**
	```cpp
	        } else {
	```
	If the bill is not 5 or 10 dollars, it must be a 20-dollar bill.

9. **Provide Change for 20-dollar Bill with 10-dollar Bill**
	```cpp
	                 if (five > 0 && ten > 0) five--, ten--;
	```
	If we have both 5-dollar and 10-dollar bills, give one of each as change.

10. **Provide Change for 20-dollar Bill with Three 5-dollar Bills**
	```cpp
	            else if (five > 2) five -= 3;
	```
	If we don't have a 10-dollar bill, check if we have at least three 5-dollar bills to provide change.

11. **Return False for Inability to Provide Change**
	```cpp
	            else return false;
	```
	If we don't have sufficient 5-dollar bills to provide change, return false indicating it's not possible.

12. **Return True**
	```cpp
	    return true;
	```
	If we have processed all bills successfully and returned the correct change for each, return true.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n), where n is the length of the bills array. This occurs when every customer pays with a $5 bill.
- **Average Case:** O(n), as each customer is processed in constant time.
- **Worst Case:** O(n), where n is the length of the bills array.



### Space Complexity 💾
- **Best Case:** O(1), as no extra space is required apart from the counters.
- **Worst Case:** O(1), since we are only using a fixed amount of extra space for the counters.



**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/lemonade-change/description/)

---
{{< youtube mSVAw0AUZgA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
