
+++
authors = ["grid47"]
title = "Leetcode 1357: Apply Discount Every n Orders"
date = "2024-06-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1357: Apply Discount Every n Orders in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "A-PXwozdaCg"
youtube_upload_date="2024-06-25"
youtube_thumbnail="https://i.ytimg.com/vi/A-PXwozdaCg/maxresdefault.jpg"
comments = true
+++



---
A supermarket offers various products, each with an associated price. The customers make purchases where the subtotal is calculated based on the prices and quantities of the products they buy. Every nth customer gets a discount on their subtotal, and the final bill is calculated accordingly.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two parts: an initialization array to set up the cashier and a sequence of purchases made by customers.
- **Example:** `["Cashier", "getBill", "getBill", "getBill", "getBill", "getBill", "getBill"]
[[3, 50, [1, 2, 3, 4, 5], [100, 200, 300, 400, 500]], [[1, 2], [1, 2]], [[3, 5], [2, 2]], [[4], [5]], [[2, 3, 5], [3, 3, 3]], [[1, 5], [2, 5]], [[4, 3], [3, 4]]]`
- **Constraints:**
	- 1 <= n <= 104
	- 0 <= discount <= 100
	- 1 <= products.length <= 200
	- prices.length == products.length
	- 1 <= products[i] <= 200
	- 1 <= prices[i] <= 1000
	- 1 <= product.length <= products.length
	- amount.length == product.length
	- product[j] exists in products
	- 1 <= amount[j] <= 1000
	- At most 1000 calls will be made to getBill.

{{< dots >}}
### Output Specifications 📤
- **Output:** The output should return the final amount the customer needs to pay after applying the discount (if applicable).
- **Example:** `[null, 500.0, 1600.0, 400.0, 1900.0, 3000.0, 3200.0]`
- **Constraints:**
	- The answer should be within 10^-5 of the actual value.

{{< dots >}}
### Core Logic 🔍
**Goal:** Calculate the subtotal based on the products and quantities, apply the discount for every nth customer, and return the final amount.

- Initialize the Cashier class with n, discount, and product prices.
- For each customer, calculate the total price of the products purchased.
- If the customer is the nth customer, apply the discount to their subtotal.
- Return the final price after any discount.
{{< dots >}}
### Problem Assumptions ✅
- Each customer is processed sequentially, and the discount is applied based on the order of their purchase.
{{< dots >}}
## Examples 🧩
- **Input:** `["Cashier", "getBill", "getBill"]
[[3, 50, [1, 2, 3], [100, 200, 300]], [[1, 2], [1, 1]], [[3], [5]]]`  \
  **Explanation:** In this example, the first two customers do not receive a discount, while the third customer, being the 3rd customer, gets a 50% discount.

{{< dots >}}
## Approach 🚀
The solution can be implemented by tracking the customer count and applying the discount every nth customer while calculating the bill.

### Initial Thoughts 💭
- The product prices and quantities can be mapped together for fast lookup.
- We need to handle both the calculation of the subtotal and the condition for applying the discount efficiently.
- The problem is straightforward and can be solved using a simple counter for customer numbers.
{{< dots >}}
### Edge Cases 🌐
- Handle cases where the product list is empty or the amount array is empty.
- Ensure the solution can handle up to the maximum input size (10,000 customers).
- Check edge cases where the discount is 0% or 100%.
- Verify when only one product is purchased.
- Ensure the solution adheres to the provided constraints on time and space complexity.
{{< dots >}}
## Code 💻
```cpp
double pct;
unordered_map<int, int> tags;
public:
Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
    cnt = 0;
    mod = n;
    pct = (100 - discount)/ 100.0;
    for(int i = 0; i < products.size(); i++)
        tags[products[i]] = prices[i];
}

double getBill(vector<int> product, vector<int> amount) {
    cnt++;
    int ans = 0;
    for(int i = 0; i < product.size(); i++)
        ans += tags[product[i]] * amount[i];
    return cnt%mod? ans: ans * pct; 
}
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
```

This code defines a 'Cashier' class that calculates the total bill based on products and their amounts, applying a discount for every nth customer.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	double pct;
	```
	Declares a variable 'pct' of type double to store the discount percentage as a decimal.

2. **Data Structure Declaration**
	```cpp
	unordered_map<int, int> tags;
	```
	Declares an unordered map 'tags' to associate product IDs with their respective prices.

3. **Access Modifier**
	```cpp
	public:
	```
	Specifies that the following members of the class are public and can be accessed outside the class.

4. **Constructor Declaration**
	```cpp
	Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
	```
	The constructor initializes the Cashier object with the number of customers for a discount, a discount percentage, a vector of product IDs, and their corresponding prices.

5. **Variable Initialization**
	```cpp
	    cnt = 0;
	```
	Initializes the counter 'cnt' to track the number of customers served.

6. **Variable Initialization**
	```cpp
	    mod = n;
	```
	Sets 'mod' to the number of customers after which a discount will be applied.

7. **Discount Calculation**
	```cpp
	    pct = (100 - discount)/ 100.0;
	```
	Calculates the decimal value of the discount percentage and stores it in 'pct'.

8. **Loop - Product Price Initialization**
	```cpp
	    for(int i = 0; i < products.size(); i++)
	```
	Loops through each product ID in the 'products' vector.

9. **Map Insertion**
	```cpp
	        tags[products[i]] = prices[i];
	```
	Maps each product ID in 'products' to its corresponding price in 'prices' using the 'tags' unordered map.

10. **Function Declaration**
	```cpp
	double getBill(vector<int> product, vector<int> amount) {
	```
	Declares the 'getBill' function which calculates the total bill based on the products and their quantities.

11. **Counter Increment**
	```cpp
	    cnt++;
	```
	Increments the customer counter 'cnt' by one each time a bill is generated.

12. **Variable Initialization**
	```cpp
	    int ans = 0;
	```
	Initializes a variable 'ans' to store the total bill amount before applying any discount.

13. **Loop - Bill Calculation**
	```cpp
	    for(int i = 0; i < product.size(); i++)
	```
	Loops through each product ID in the 'product' vector.

14. **Bill Calculation**
	```cpp
	        ans += tags[product[i]] * amount[i];
	```
	For each product, the corresponding price from the 'tags' map is multiplied by the quantity in the 'amount' vector, and the result is added to 'ans'.

15. **Conditional Discount Application**
	```cpp
	    return cnt%mod? ans: ans * pct; 
	```
	If the customer count is divisible by 'mod' (every nth customer), a discount is applied to the total bill by multiplying 'ans' with 'pct'. Otherwise, the full amount is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1)
- **Average Case:** O(m)
- **Worst Case:** O(m)

The time complexity depends on the number of products in the bill, and each call to getBill processes m products.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(p)

The space complexity is O(p), where p is the number of products, to store the product-price mapping.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/apply-discount-every-n-orders/description/)

---
{{< youtube A-PXwozdaCg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
