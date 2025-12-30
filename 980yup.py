
with open("new_file.txt", "w") as fileWrite:
    fileWrite.write("Hello bich")

with open("test_file.txt", "r") as fileRead:
    print(fileRead.read())
