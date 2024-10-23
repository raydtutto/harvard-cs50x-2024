-- Students table
CREATE TABLE students (
                          id INTEGER,
                          student_name TEXT,
                          PRIMARY KEY(id)
);

-- Houses table
CREATE TABLE houses (
                        id INTEGER,
                        house TEXT,
                        head TEXT,
                        PRIMARY KEY(id)
);

-- House assignments table
CREATE TABLE house_assignments (
                                   house_id INTEGER,
                                   student_id INTEGER,
                                   PRIMARY KEY(house_id, student_id),
                                   FOREIGN KEY(house_id) REFERENCES houses(id),
                                   FOREIGN KEY(student_id) REFERENCES students(id)
);
