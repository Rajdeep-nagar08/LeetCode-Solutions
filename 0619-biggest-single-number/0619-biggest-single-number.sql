# Write your MySQL query statement below




select 

(case when(count(num))=1 then num else null end) as num

from myNumbers

group by num

order by num desc limit 1;


# select num from MyNumbers

# group by num

# having count(num)=1

# order by num desc

# limit 1;