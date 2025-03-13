SELECT "first_name" AS "name", "last_name" AS "surname" FROM "players"
WHERE "final_game" BETWEEN '2022-01-01' AND '2022-12-31'
ORDER BY "first_name" ASC, "last_name" ASC;
