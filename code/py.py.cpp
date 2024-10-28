import os

# Create files named from 1.txt to 3329.txt
for i in range(1, 3330):
    filename = os.path.join(os.getcwd(), f"{i}")
    with open(filename, 'w') as file:
        file.write(f"")
        

