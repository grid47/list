# Write your MySQL query statement below
SELECT s.name, SUM(t.amount) balance
FROM Users s
LEFT JOIN Transactions t
ON s.account = t.account
GROUP BY s.account
HAVING balance > 10000;