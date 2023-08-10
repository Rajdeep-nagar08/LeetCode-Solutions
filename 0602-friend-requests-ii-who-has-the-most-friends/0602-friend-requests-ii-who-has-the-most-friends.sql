# Write your MySQL query statement below

select id,num1 as num

from

(

(select t1.requester_id as id,

(select count(*) from RequestAccepted t2 where t1.requester_id=t2.requester_id

or t1.requester_id=t2.accepter_id) as num1

from RequestAccepted t1

order by num1 desc limit 1)


union



(select t1.accepter_id as id,

(select count(*) from RequestAccepted t2 where t1.accepter_id=t2.accepter_id

or t1.accepter_id=t2.requester_id) as num1

from RequestAccepted t1

order by num1 desc limit 1)
    
) final

order by num desc limit 1;
