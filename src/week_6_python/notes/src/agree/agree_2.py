s = input("Do you agree? ")

if s in ["y", "Y", "yes", "Yes", "YES", "YEs", "yES", "yEs", "YeS"]:
    print("Agreed")
elif s in ["n", "N", "no", "No", "NO", "nO"]:
    print("Not agreed")