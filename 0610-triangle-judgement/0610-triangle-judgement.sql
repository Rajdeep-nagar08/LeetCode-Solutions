# Write your MySQL query statement below

select x, y, z, 

case 

when x+y <= z or y+z <= x or z+x <= y then 'No' else 'Yes' end

as triangle

from Triangle;
