from cs50 import get_int

# Create an empty list
scores = []

for i in range(3):
    score = get_int("Score:  ")
    # Add new value onto the end
    scores.append(score)

average = sum(scores) / len(scores)
print(f"Average: {average:.1f}")
