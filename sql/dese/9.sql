SELECT "name" FROM "districts"
WHERE "id" = (
    SELECT "district_id" FROM "expenditures"
    GROUP BY "district_id"
    ORDER BY "pupils" ASC
    LIMIT 1
);
