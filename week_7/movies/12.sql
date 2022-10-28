-- write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred. INTERSECT: https://stackoverflow.com/questions/4047484/selecting-with-multiple-where-conditions-on-same-column


SELECT DISTINCT title FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON people.id = stars.person_id WHERE name= "Johnny Depp" INTERSECT SELECT title FROM movies JOIN stars ON stars.movie_id = movies.id JOIN people ON people.id = stars.person_id WHERE name= "Helena Bonham Carter";