# Write your MySQL query statement below


select distinct t1.class from Courses t1 

where (select count(*) from Courses t2 where t1.class=t2.class) >=5;