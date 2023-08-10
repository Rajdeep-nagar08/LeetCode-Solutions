# Write your MySQL query statement below




select 

(case when (select count(*) from myNumbers t2 where t1.num=t2.num)=1 then t1.num

else null end) as num

from myNumbers t1

order by num desc limit 1;