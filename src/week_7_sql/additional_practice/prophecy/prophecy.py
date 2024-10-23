from cs50 import SQL
import csv

db = SQL("sqlite:///roster.db")

# Cleanup tables
db.execute("DELETE FROM house_assignments")
db.execute("DELETE FROM students")
db.execute("DELETE FROM houses")

# Create students and houses tables
with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        student_name = row["student_name"]
        house_name = row["house"]
        head_name = row["head"]

        # Fill houses
        house_exists = db.execute("SELECT * FROM houses WHERE house = ?", house_name)

        if not house_exists:
            db.execute("INSERT INTO houses (house, head) VALUES (?, ?)", house_name, head_name)

        # Fill students
        db.execute("INSERT INTO students (student_name) VALUES (?)", student_name)


# Create a join table
with open("students.csv", "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        student_name = row["student_name"]
        house_name = row["house"]

        # Get id
        student_id = db.execute("SELECT id FROM students WHERE student_name = ?", student_name)
        house_id = db.execute("SELECT id FROM houses WHERE house = ?", house_name)

        # print(f"house {house_name}: {house_id}, student {student_name}: {student_id}")  # DEBUG

        # Fill join table
        db.execute("INSERT INTO house_assignments (house_id, student_id) VALUES (?, ?)",
                   int(house_id[0]['id']), int(student_id[0]['id']))
