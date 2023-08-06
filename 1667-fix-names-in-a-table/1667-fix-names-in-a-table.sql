# Write your MySQL query statement below


select user_id, 

CONCAT(UPPER(substr(name,1,1)),LOWER(substr(name,2)))
                       
as name 
                      
                       
from Users order by user_id;