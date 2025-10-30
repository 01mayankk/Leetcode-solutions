# Write your MySQL query statement below

-- Select the employee's name
SELECT e1.name AS Employee
FROM Employee e1

-- Self join: match each employee with their manager
JOIN Employee e2 
ON e1.managerId = e2.id

-- Filter condition: employee earns more than their manager
WHERE e1.salary > e2.salary;
