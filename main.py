import os
from auth.login import login, register
from modules.printer_queue import printer_menu
from modules.shared_files import file_menu
from modules.deadlock import deadlock_demo
from modules.dashboard import show_dashboard

def clear():
    os.system('cls' if os.name == "nt" else "clear")

def main_menu(user):
    while True:

        clear()
        print("\n===== Linux Lab Management System =====")
        print("1. System Dashboard")
        print("2. Print File")
        print("3. Manage Shared Files")
        print("4. Share New File")
        print("5. View Activity Log")
        print("6. Deadlock Simulation")
        print("7. Logout")

        choice = input("Enter choice: ")

        if choice == "1":
            show_dashboard(user)
            input("\nPress Enter to continue...")

        elif choice == "2":
            printer_menu(user)

        elif choice == "3":
            file_menu(user)

        elif choice == "4":
            new_file = input("Enter file name to share: ")

            if new_file.strip() != "":
                with open("data/shared_files.txt", "a") as f:
                    f.write(new_file + "\n")

                print("File shared successfully!")
            else:
                print("Invalid file name!")

            input("\nPress Enter to continue...")

        elif choice == "5":

            print("\n===== Your Activity Log =====\n")

            found = False

            with open("data/activity_log.txt", "r") as f:
                for line in f:
                    if user in line:
                        print(line.strip())
                        found = True

            if not found:
                print("No activity yet.")

            input("\nPress Enter to continue...")

        elif choice == "6":
            deadlock_demo()
            input("\nPress Enter to continue...")

        elif choice == "7":
            print("Logging out...")
            break

        else:
            print("Invalid choice")

while True:

    clear()

    print("\n===== LAB SYSTEM =====")
    print("1. Register")
    print("2. Login")
    print("3. Exit")

    ch = input("Choice: ")

    if ch == "1":
        register()

    elif ch == "2":
        user = login()
        if user:
            main_menu(user)

    elif ch == "3":
        break