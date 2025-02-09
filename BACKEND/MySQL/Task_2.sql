/* first problem : select all columns in city table where population > 100000
and countrycode = USA*/

select *
from CITY
where POPULATION > 100000 and countrycode = 'USA'; 
---------------------------------

/* second problem : select all Names in city table where population > 120000
and countrycode = USA*/

select NAME
from CITY
where POPULATION >  120000 and countrycode = 'USA'; 
----------------------------------

--Third problem : select all columns in city table where countrycode = JPN

select *
from CITY
where countrycode = 'JPN';
----------------------------------

--fourth problem : select names with alphatical order 
select name
from employee
order by 1 asc;
---------------------------------
/*fifth : prints a list of employee names (i.e.: the name attribute) for employees in Employee having
 a salary greater than 2000$ per month who have been employees for less than 10 months.*/

select name
from employee
where salary > 2000 and months < 10;
------------------------------------

/*sixth : Print the Name of any student in STUDENTS who scored higher 75 than  Marks. 
Order your output by the last three characters of each name.
 If two or more students both have names ending in the same last three characters (i.e.: Bobby, Robby, etc.), secondary sort them by ascending ID.
*/

select name
from students
where marks > 75
order by right(name , 3) , ID; -- right=> return last characters (3)
---------------------------------------

--seventh problem : print parts and assembly_step where finish_date isn't exist
select part "part" , assembly_step "assembly_step"
from parts_assembly
where finish_date is null;
------------------------------------------