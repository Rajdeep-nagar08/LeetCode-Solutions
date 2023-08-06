# Write your MySQL query statement below


# id is a continuous increment.


# using CASE as used in SWITCH in C++


# select 

# CASE

# when id % 2=1 and id=(select COUNT(id) from Seat) then id

# when id % 2=0 then id=id-1 else id=id+1


# end

# as id, student

# from Seat

# order by id;




SELECT

CASE

WHEN id % 2= 1 AND id = (SELECT COUNT(id) FROM seat) THEN id

WHEN id % 2 = 0 THEN id - 1 ELSE id + 1

END 

as id, student

FROM seat

ORDER BY id
;


