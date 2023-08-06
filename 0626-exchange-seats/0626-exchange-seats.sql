# Write your MySQL query statement below


# id is a continuous increment.


# using CASE as used in SWITCH in C++


select 

CASE

when id % 2=1 and id=(select COUNT(id) from Seat) then id

when id % 2=0 then id-1 else id+1


end

as id, student

from Seat

order by id;



