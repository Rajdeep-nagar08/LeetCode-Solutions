# Write your MySQL query statement below




select distinct contest_id, 

ROUND((count(distinct user_id)*100)/(select count(*) from Users),2) as percentage

from Register

group by contest_id

order by percentage desc, contest_id;
