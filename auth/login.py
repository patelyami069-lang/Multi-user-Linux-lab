import os

def register():
    username = input("Enter username: ")
    password = input("Enter password: ")

    # Check if user already exists
    with open("data/users.txt", "r") as f:
        for line in f:
            u, p = line.strip().split(",")

            if u == username:
                print("Username already exists!")
                return

    # If not found, save new user
    with open("data/users.txt", "a") as f:
        f.write(username + "," + password + "\n")

    print("Registration successful")


def login():

    username = input("Username: ")
    password = input("Password: ")

    with open("data/users.txt","r") as f:
        for line in f:
            u,p = line.strip().split(",")

            if username == u and password == p:
                print("Login successful")
                return username

    print("Invalid credentials")
    return None