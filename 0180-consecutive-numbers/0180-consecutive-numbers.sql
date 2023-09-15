select distinct num as consecutiveNums 
from (select num,sum(c) over (order by id) as flag from 
(select id, num, case when LAG(Num) OVER (order by id)- Num = 0 then 0 else 1 end as c
from logs) a
) b
group by num,flag
having count(*) >=3 