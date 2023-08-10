# Write your MySQL query statement below




select ROUND(count(t2.player_id)/count(t1.player_id),2) as fraction from 

(select player_id, min(event_date) as first_login from Activity group by player_id) 

t1 left join Activity t2 on 

t1.player_id=t2.player_id and DATEDIFF(t2.event_date,t1.first_login)=1;