--Problem 1 :
SELECT 
    CASE
        WHEN A + B <= C OR A + C <= B OR B + C <= A THEN 'Not A Triangle'
        WHEN A = B AND B = C THEN 'Equilateral'
        WHEN A = B OR A = C OR B = C THEN 'Isosceles'
        ELSE 'Scalene'
    END AS "Type"
FROM TRIANGLES;

------------------------------
-- Problem 2 : 

SELECT CONCAT(NAME,'(',SUBSTR(OCCUPATION,1,1),')')
FROM OCCUPATIONS
ORDER BY Name;
SELECT CONCAT('There are a total of ',COUNT(OCCUPATION),' ',LOWER(OCCUPATION),'s.')
FROM OCCUPATIONS
GROUP BY OCCUPATION
ORDER BY COUNT(OCCUPATION), OCCUPATION;

-----------------------------
-- I solve it with subquery more comfortable more than join

--Problem : 3
SELECT 
    company_code AS "com_code", 
    founder AS "Name_founder", 

    (SELECT COUNT(DISTINCT lead_manager_code) 
     FROM employee e 
     WHERE e.company_code = c.company_code) AS "num_of_lead_managers",

    (SELECT COUNT(DISTINCT senior_manager_code) 
     FROM employee e 
     WHERE e.company_code = c.company_code) AS "num_of_senior_managers",

    (SELECT COUNT(DISTINCT manager_code) 
     FROM employee e 
     WHERE e.company_code = c.company_code) AS "num_of_managers",

    (SELECT COUNT(DISTINCT employee_code) 
     FROM employee e 
     WHERE e.company_code = c.company_code) AS "num_of_employees"

FROM Company c 
ORDER BY c.company_code;

----------------------------------------

--problem 5:
select floor(avg(population))
from city;

----------------------------------------


--problem : 6
select w.id , p.age , w.coins_needed ,  w.power as "MAX_power"
from Wands w join Wands_Property p on w.code = p.code
where p.is_evil = 0 and w.COINS_NEEDED = 
(SELECT MIN(COINS_NEEDED)                                           
 FROM WANDS AS X                                         
JOIN WANDS_PROPERTY AS Y 
ON (X.CODE = Y.CODE)                                                         
WHERE X.POWER = W.POWER AND Y.AGE = P.AGE) 
order by MAX_power desc , p.age desc;

------------------------------------------

--problem : 7
select s.name , g.grade , s.marks 
from Students s join Grades g
on g.grade >= 8 and s.marks between g.Min_Mark and g.Max_Mark
order by g.grade desc , s.name;
select null , g.grade , s.marks 
from Students s join Grades g
on g.grade < 8 and s.marks between g.Min_Mark and g.Max_Mark
order by g.grade desc , s.marks;

---------------------------------------------------
--problem 8:
SELECT ROUND(LONG_W, 4) 
FROM STATION 
WHERE LAT_N = (SELECT MAX(LAT_N) FROM STATION WHERE LAT_N < 137.2345);


--problem : 9

SELECT s1.Name 
FROM Students s1
JOIN Friends f ON s1.ID = f.ID
JOIN Packages p1 ON s1.ID = p1.ID
JOIN Packages p2 ON f.Friend_ID = p2.ID
WHERE p2.Salary > p1.Salary
ORDER BY p2.Salary;
