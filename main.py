import os
import subprocess
from concepts.concepts import show_concepts
from quiz.quiz import start_quiz
from auth.login import register, login


def main_menu():
    while True:
        print("\n===== OS Learning Tool =====")
        print("1. Learn OS Concepts")
        print("2. CPU Scheduling Simulation")
        print("3. Take Quiz")
        print("4. Logout")

        choice = input("Enter your choice: ")

        if choice == "1":
            show_concepts()

        elif choice == "2":
            print("\n===== CPU Scheduling Simulation =====")
            print("1. FCFS")
            print("2. SJF")
            print("3. Back")

            algo = input("Choose scheduling algorithm: ")

            if algo == "1":
                os.system("compiled\\fcfs.exe")  # run FCFS simulation

            elif algo == "2":
                os.system("compiled\\sjf.exe")   # run SJF simulation

            elif algo == "3":
                break

            else:
                print("Invalid choice!")

        elif choice == "3":
            start_quiz()

        elif choice == "4":
            print("Logging out...")
            break

        else:
            print("Invalid choice!")


while True:
    print("\n===== OS Learning Tool =====")
    print("1. Register")
    print("2. Login")
    print("3. Exit")

    choice = input("Enter choice: ")

    if choice == "1":
        register()

    elif choice == "2":
        user = login()

        if user:
            print("Welcome", user)
            main_menu()   # go to main system after login

    elif choice == "3":
        print("Exiting program...")
        break

    else:
        print("Invalid choice")