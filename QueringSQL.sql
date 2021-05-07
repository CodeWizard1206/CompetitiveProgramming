-- Consider the schema below:
-- COMPANY(cid,name,location)
-- STUDENT(sid,name,degree)
-- INTERVIEW(cid,sid,date)
-- OFFER(cid,sid,salary)
-- Write queries to:

-- • List companies whose name contains “Private” or “Ltd” in them.
SELECT *
FROM COMPANY
WHERE name LIKE "%Private%" OR name LIKE "%Ltd%";

-- • For every offer, list corresponding student and company name.
SELECT S.name, S.degree, C.name, O.salary
FROM COMPANY AS C, STUDENT AS S, OFFER AS O
WHERE O.cid = C.cid AND O.sid = S.sid;

-- • For each company based in Pune, list number of interviews taken, number of offers
-- handed and acceptance ratio (#offers / #interviews).
SELECT C.name,
@x := (SELECT COUNT(I.cid)
    FROM INTERVIEW AS I
    WHERE I.cid = C.cid
    GROUP BY I.cid) AS number_of_interviews,
@y := (SELECT COUNT(O.cid)
    FROM OFFER AS O
    WHERE O.cid = C.cid
    GROUP BY O.cid) AS number_of_offers,
@y/@x AS acceptance_ratio
FROM COMPANY AS C
WHERE C.location = "Pune";

-- • List all student names pursuing BTech and have more than 5 offers.
SELECT S.name
FROM STUDENT AS S, OFFER AS O
WHERE S.degree = "BTech" AND S.sid = O.sid
HAVING COUNT(O.cid) > 5;