-- The names of all people who starred in a movie released in 2004, ordered by birth year.
SELECT people.name
FROM movies
         JOIN stars ON movies.id = stars.movie_id
         JOIN people ON stars.person_id = people.id
WHERE movies.year = 2004
ORDER BY people.birth;
