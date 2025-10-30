# Write your MySQL query statement below

-- Select the email column and rename it as 'Email' in the output
SELECT email AS Email
FROM Person

-- Group rows that have the same email value together
GROUP BY email

-- Only keep those groups (emails) that appear more than once
-- i.e., emails that are duplicated in the 'Person' table
HAVING COUNT(*) > 1;
