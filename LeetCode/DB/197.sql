select distinct w2.id
from weather w1, weather w2
where to_days(w1.recorddate) + 1 = to_days(w2.recorddate) and w1.temperature < w2.temperature