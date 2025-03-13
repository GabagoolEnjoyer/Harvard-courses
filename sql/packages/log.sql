
-- *** The Lost Letter **
SELECT "id", "contents" FROM "packages"
WHERE "from_address_id" = (
     SELECT "id" FROM "addresses" WHERE "address" = '900 Somerville Avenue'
);

-- 384 is needed id of a package

SELECT "address", "type" FROM "addresses"
WHERE "id" = (
    SELECT "address_id" FROM "scans"
    WHERE "package_id" = 384 AND "action" = 'Drop'
);

-- *** The Devious Delivery ***
SELECT "type" FROM "addresses"
WHERE "id" = (
    SELECT "address_id" FROM "scans"
    WHERE "package_id" = (
        SELECT "id" FROM "packages" WHERE "from_address_id" IS NULL
    ) AND "action" = 'Drop');

-- *** The Forgotten Gift ***
SELECT "id", "contents" FROM "packages"
WHERE "from_address_id" = (
    SELECT "id" FROM "addresses"
    WHERE "address" = '109 Tileston Street'
);
-- id 9523
SELECT "address", "type" FROM "addresses"
WHERE "id" = (
    SELECT "address_id" FROM "scans"
    WHERE "package_id" = 9523 AND "action" = 'Drop'
);
