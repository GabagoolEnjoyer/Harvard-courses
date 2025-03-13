CREATE TABLE "users" (
    "id" INTEGER,
    "first_name" TEXT NOT NULL,
    "last_name" TEXT NOT NULL,
    "username" TEXT NOT NULL,
    "password" TEXT NOT NULL,
    PRIMARY KEY("id")
);

CREATE TABLE "school" (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "type" TEXT NOT NULL,
    "location" TEXT NOT NULL,
    "date_founded" NUMERIC NOT NULL,
    PRIMARY KEY("id")
);

CREATE TABLE "companies" (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "industry" TEXT NOT NULL,
    "location" TEXT NOT NULL,
    PRIMARY KEY("id")
);

CREATE TABLE "connections_people" (
    "id" INTEGER,
    "user_1_id" INTEGER,
    "user_2_id" INTEGER,
    PRIMARY KEY("id"),
    FOREIGN KEY("user_1_id") REFERENCES "users"("id"),
    FOREIGN KEY("user_2_id") REFERENCES "users"("id")
);

CREATE TABLE "connections_schools" (
    "id" INTEGER,
    "user_id" INTEGER,
    "school_id" INTEGER,
    "date_started" NUMERIC NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "date_finished" NUMERIC DEFAULT CURRENT_TIMESTAMP,
    "degree" TEXT NOT NULL,
    PRIMARY KEY("id"),
    FOREIGN KEY("user_id") REFERENCES "users"("id"),
    FOREIGN KEY("school_id") REFERENCES "schools"("id")
);

CREATE TABLE "connections_companies" (
    "id" INTEGER,
    "user_id" INTEGER,
    "company_id" INTEGER,
    "date_started" NUMERIC NOT NULL DEFAULT CURRENT_TIMESTAMP,
    "date_finished" NUMERIC DEFAULT CURRENT_TIMESTAMP,
    "position" TEXT NOT NULL,
    PRIMARY KEY("id"),
    FOREIGN KEY("user_id") REFERENCES "users"("id"),
    FOREIGN KEY("company_id") REFERENCES "companies"("id")
);
