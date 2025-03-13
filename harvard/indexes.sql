CREATE INDEX "enrollments_course"
ON "enrollments"("course_id");

CREATE INDEX "enrollments_students"
ON "enrollments"("student_id");

CREATE INDEX "courses_department"
ON "courses"("department")
WHERE "semester" LIKE '%2023%' OR "semester" LIKE '%2024%';

CREATE INDEX "courses_number"
ON "courses"("number")
WHERE "semester" LIKE '%2023%' OR "semester" LIKE '%2024%';

CREATE INDEX "courses_semester"
ON "courses"("semester");

CREATE INDEX "courses_id"
ON "courses"("id");
