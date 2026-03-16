def register():
    username = input("Enter new username: ")
    password = input("Enter password: ")

    with open("data/users.txt", "r") as file:
        users = file.readlines()

    for user in users:
        u, p = user.strip().split()

        if username == u:
            print("Username already exists!")
            return

    with open("data/users.txt", "a") as file:
        file.write(username + " " + password + "\n")

    print("Registration successful!")


def login():
    username = input("Username: ")
    password = input("Password: ")

    with open("data/users.txt", "r") as file:
        users = file.readlines()

    for user in users:
        u, p = user.strip().split()

        if username == u and password == p:
            print("Login successful!")
            return username

    print("Invalid username or password.")
    return None