-- The names of all people who have directed a movie that received a rating of at least 9.0.
SELECT people.name
FROM ratings
         JOIN movies ON ratings.movie_id = movies.id
         JOIN directors ON directors.movie_id = movies.id
         JOIN people ON people.id = directors.person_id
WHERE ratings.rating >= 9.0;
