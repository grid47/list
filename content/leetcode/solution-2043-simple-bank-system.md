
+++
authors = ["grid47"]
title = "Leetcode 2043: Simple Bank System"
date = "2024-04-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2043: Simple Bank System in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Design","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "ouflA0KmCnI"
youtube_upload_date="2021-10-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/ouflA0KmCnI/maxresdefault.webp"
comments = true
+++



---
You are required to build a system for a bank that automates various account transactions, including deposits, withdrawals, and transfers. The bank has multiple accounts, and each transaction must adhere to specific rules to be considered valid. Implement a class that handles these operations efficiently while ensuring transactional integrity.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The system receives an initial array of balances and multiple commands for transactions. Each command specifies the type of transaction, the involved account(s), and the amount.
- **Example:** `Input:
['Bank', 'withdraw', 'transfer', 'deposit', 'transfer', 'withdraw']
[[[50, 200, 75]], [2, 20], [3, 1, 50], [2, 30], [3, 1, 100], [4, 40]]`
- **Constraints:**
	- The number of accounts, n, is between 1 and 10^5.
	- Account indices are between 1 and n.
	- Transaction amounts and balances are non-negative and can go up to 10^12.
	- A maximum of 10^4 operations are supported.

{{< dots >}}
### Output Specifications 📤
- **Output:** The system outputs the success or failure of each transaction as a boolean result.
- **Example:** `Output:
[null, true, true, true, false, false]`
- **Constraints:**
	- The output matches the order of operations, indicating success or failure for each transaction type.

{{< dots >}}
### Core Logic 🔍
**Goal:** Process transactions while maintaining the validity of account balances and ensuring the integrity of operations.

- Initialize the bank with an array representing account balances.
- For 'withdraw', check if the account exists and has sufficient balance. Deduct the amount if valid.
- For 'deposit', validate the account number and add the specified amount to the account balance.
- For 'transfer', validate both account numbers and check if the source account has sufficient balance. Transfer the funds if valid.
- Return true for successful operations and false for invalid transactions.
{{< dots >}}
### Problem Assumptions ✅
- The initial balances are non-negative.
- All accounts are valid at initialization.
{{< dots >}}
## Examples 🧩
- **Input:** `Input:
['Bank', 'deposit', 'withdraw', 'transfer']
[[[100, 50]], [1, 50], [2, 60], [1, 2, 30]]`  \
  **Explanation:** The initial balances are [100, 50].
- 'deposit': Account 1 receives $50, new balance is $150. Return true.
- 'withdraw': Account 2 tries to withdraw $60 but has insufficient funds. Return false.
- 'transfer': Account 1 transfers $30 to Account 2. Updated balances are [120, 80]. Return true.

{{< dots >}}
## Approach 🚀
The solution uses a direct mapping of account numbers to indices in the balance array for efficient lookups and updates. All operations are performed in constant time by validating inputs and applying changes directly to the array.

### Initial Thoughts 💭
- The key challenge is validating account numbers and ensuring sufficient balance for transactions.
- Since accounts are indexed and contiguous, they can be efficiently mapped to array indices.
- Use a straightforward array representation for account balances.
- Perform validation checks before applying any transaction to ensure data consistency.
{{< dots >}}
### Edge Cases 🌐
- Input with no accounts should return false for all operations.
- Processes a maximum-sized balance array with 10^5 accounts and 10^4 transactions without exceeding limits.
- Handle cases where transaction amounts are zero or equal to account balances.
- Ensure invalid account numbers return false.
- Check operations with edge case values like maximum balance and transaction amounts.
{{< dots >}}
## Code 💻
```cpp
int n;
vector<long long> bal;
Bank(vector<long long>& balance) {
    bal = balance;
    n = bal.size();
}

bool transfer(int acc1, int acc2, long long money) {
    int ac1 = acc1 - 1 , ac2 = acc2 - 1;
    if(ac1 < 0 || ac1 >= n || ac2 < 0 || ac2 >= n || bal[ac1] < money)
        return false;
    
    bal[ac1] -= money;
    bal[ac2] += money;
    return true;
}

bool deposit(int acc, long long money) {
    
    if(acc < 1 || acc > n) return false;
    
    bal[acc - 1] += money;
    return true;
}

bool withdraw(int acc, long long money) {
    if(acc < 1 || acc > n || bal[acc - 1] < money) return false;        
    bal[acc - 1] -= money;
    return true;
}
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
```

This code defines a Bank class that handles operations like transfer, deposit, and withdraw, managing user account balances.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Declaration**
	```cpp
	int n;
	```
	Declares the integer variable `n`, which will store the number of accounts.

2. **Vector Initialization**
	```cpp
	vector<long long> bal;
	```
	Declares a vector `bal` of type `long long` to hold the balances of the accounts.

3. **Constructor Definition**
	```cpp
	Bank(vector<long long>& balance) {
	```
	Constructor to initialize the bank with an account balance vector.

4. **Assign Balance to Bank**
	```cpp
	    bal = balance;
	```
	Assigns the passed `balance` vector to the `bal` member variable.

5. **Account Size Assignment**
	```cpp
	    n = bal.size();
	```
	Sets the number of accounts `n` by determining the size of the balance vector.

6. **Function Declaration**
	```cpp
	bool transfer(int acc1, int acc2, long long money) {
	```
	Declares the `transfer` function that allows transferring money between two accounts.

7. **Account Index Adjustments**
	```cpp
	    int ac1 = acc1 - 1 , ac2 = acc2 - 1;
	```
	Adjusts the account numbers (1-based to 0-based index) for `ac1` and `ac2`.

8. **Transfer Validation**
	```cpp
	    if(ac1 < 0 || ac1 >= n || ac2 < 0 || ac2 >= n || bal[ac1] < money)
	```
	Checks if the account numbers are valid and if the balance in `ac1` is sufficient to cover the transfer.

9. **Return False on Invalid Transfer**
	```cpp
	        return false;
	```
	Returns `false` if the transfer is invalid due to insufficient funds or invalid account numbers.

10. **Transfer Logic**
	```cpp
	    bal[ac1] -= money;
	```
	Deducts the specified amount from account `ac1`.

11. **Transfer Logic**
	```cpp
	    bal[ac2] += money;
	```
	Adds the specified amount to account `ac2`.

12. **Return True on Successful Transfer**
	```cpp
	    return true;
	```
	Returns `true` if the transfer is successful.

13. **Function Declaration**
	```cpp
	bool deposit(int acc, long long money) {
	```
	Declares the `deposit` function that allows depositing money into an account.

14. **Deposit Validation**
	```cpp
	    if(acc < 1 || acc > n) return false;
	```
	Checks if the account number `acc` is valid.

15. **Deposit Logic**
	```cpp
	    bal[acc - 1] += money;
	```
	Adds the specified amount to the balance of the given account.

16. **Return True on Successful Deposit**
	```cpp
	    return true;
	```
	Returns `true` if the deposit is successful.

17. **Function Declaration**
	```cpp
	bool withdraw(int acc, long long money) {
	```
	Declares the `withdraw` function that allows withdrawing money from an account.

18. **Withdraw Validation**
	```cpp
	    if(acc < 1 || acc > n || bal[acc - 1] < money) return false;
	```
	Checks if the account number is valid and if the account has enough balance for the withdrawal.

19. **Withdraw Logic**
	```cpp
	    bal[acc - 1] -= money;
	```
	Deducts the specified amount from the account balance.

20. **Return True on Successful Withdrawal**
	```cpp
	    return true;
	```
	Returns `true` if the withdrawal is successful.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(1) per transaction.
- **Average Case:** O(1) per transaction.
- **Worst Case:** O(1) per transaction.

Each operation involves constant-time array access and validation.

### Space Complexity 💾
- **Best Case:** O(n) for storing balances.
- **Worst Case:** O(n) for storing balances.

The balance array is the only significant space usage.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/simple-bank-system/description/)

---
{{< youtube ouflA0KmCnI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
