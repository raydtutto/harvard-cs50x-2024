people = [
    {"name": "Carter", "number": "+1-617-495-1000"},
    {"name": "David", "number": "+1-617-495-1000"},
    {"name": "John", "number": "+1-949-468-2750"},
]

name = input("Name: ")

for person in people:
    if person["name"] == name:
        print(f"Found: {person['number']}")
        break
else:
    print("Not found")
