# Write your MySQL query statement below

SELECT id, num 
FROM (
    SELECT id, COUNT(id) AS num 
    FROM (
        SELECT requester_id AS id FROM RequestAccepted 
        UNION ALL 
        SELECT accepter_id AS id FROM RequestAccepted
    ) t1 
    GROUP BY id
) t2 
WHERE num = (
    SELECT MAX(num) 
    FROM (
        SELECT id, COUNT(id) AS num 
        FROM (
            SELECT requester_id AS id FROM RequestAccepted 
            UNION ALL 
            SELECT accepter_id AS id FROM RequestAccepted
        ) t1 
        GROUP BY id
    ) t2
);