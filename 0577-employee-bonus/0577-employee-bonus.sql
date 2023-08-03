# Write your MySQL query statement below


select name, bonus from Employee t1 left join Bonus t2 on t1.empID=t2.empID where bonus < 1000 or bonus is NULL;