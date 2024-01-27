import csv

from cs50 import SQL

db = SQL("sqlite:///favorites.db")

title = input("Title: ").strip()

row = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title)

row = row[0]

print(row["counter"])

#INDEX