# Write your MySQL query statement below
SELECT c.name AS Customers
FROM customers c
LEFT JOIN Orders o
    ON c.id=o.customerId
WHERE o.customerId is NULL;
