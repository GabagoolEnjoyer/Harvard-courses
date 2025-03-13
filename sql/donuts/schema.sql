CREATE TABLE "ingredients" (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "unit" TEXT NOT NULL,
    "price" NUMERIC NOT NULL,
    PRIMARY KEY("id")
);

CREATE TABLE "donuts" (
    "id" INTEGER,
    "name" TEXT NOT NULL,
    "is_gluten-free" TEXT NOT NULL CHECK("is_gluten-free" IN ('yes', 'no')),
    "price" NUMERIC NOT NULL,
    "ingredients_id" INTEGER [],
    PRIMARY KEY("id"),
    FOREIGN KEY ("ingredients_id") REFERENCES "ingredients"("id")
);

CREATE TABLE "orders" (
    "id" INTEGER,
    "donuts_id" INTEGER [],
    "customer_id" INTEGER,
    PRIMARY KEY("id"),
    FOREIGN KEY("donuts_id") REFERENCES "donuts"("id"),
    FOREIGN KEY("customer_id") REFERENCES "customers"("id")
);

CREATE TABLE "customers" (
    "id" INTEGER,
    "first_name" TEXT NOT NULL,
    "last_name" TEXT NOT NULL,
    "order_history" INTEGER [],
    PRIMARY KEY("id"),
    FOREIGN KEY("order_history") REFERENCES "orders"("id")
);
