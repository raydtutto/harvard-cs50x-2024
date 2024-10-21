from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

rows =  db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)

# Get the first row from the result
row = rows[0]

print(row["n"])
