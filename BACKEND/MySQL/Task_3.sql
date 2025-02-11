-- Problem 1: Select all city names where countrycode = 'JPN'
SELECT name AS "Name"
FROM CITY
WHERE COUNTRYCODE = 'JPN';

--------------------------------------

-- Problem 2: Get the sum of LAT_N and LONG_W, rounded to 2 decimal places
SELECT 
    ROUND(SUM(LAT_N), 2) AS lat, 
    ROUND(SUM(LONG_W), 2) AS lon
FROM STATION;

--------------------------------------

-- Problem 3: Select distinct cities that do not start with a vowel
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTR(CITY, 1, 1) NOT IN ('A', 'E', 'I', 'O', 'U', 
                                 'a', 'e', 'i', 'o', 'u');

--------------------------------------

-- Problem 4: Select distinct cities that do not end with a vowel
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTR(CITY, LENGTH(CITY), 1) NOT IN ('A', 'E', 'I', 'O', 'U', 
                                            'a', 'e', 'i', 'o', 'u');

--------------------------------------

-- Problem 5: Select distinct cities that neither start nor end with a vowel
SELECT DISTINCT CITY
FROM STATION
WHERE SUBSTR(CITY, LENGTH(CITY), 1) NOT IN ('A', 'E', 'I', 'O', 'U', 
                                            'a', 'e', 'i', 'o', 'u') 
AND SUBSTR(CITY, 1, 1) NOT IN ('A', 'E', 'I', 'O', 'U', 
                               'a', 'e', 'i', 'o', 'u');

--------------------------------------

-- Problem 6: Get the average population rounded down to the nearest integer
SELECT FLOOR(AVG(population)) AS "AVG"
FROM CITY;

--------------------------------------

-- Problem 7: Get the top 2 users who sent the most messages in August 2022
SELECT sender_id, COUNT(sender_id) AS "message_count"
FROM messages
WHERE DATE_PART('month', sent_date) = 8 
AND DATE_PART('year', sent_date) = 2022
GROUP BY sender_id
ORDER BY message_count DESC
LIMIT 2;

--------------------------------------

-- Problem 8: Calculate click-through rate (CTR) for the app in 2022
SELECT 
    app_id,
    ROUND(
        SUM(CASE WHEN event_type = 'click' THEN 1 ELSE 0 END) * 100.0 /
        NULLIF(SUM(CASE WHEN event_type = 'impression' THEN 1 ELSE 0 END), 0), 
        2
    )::FLOAT AS ctr 
FROM events
WHERE DATE_PART('year', timestamp) = 2022
GROUP BY app_id;
