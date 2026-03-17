from modules.logs import log_activity

def file_menu(user):

    while True:

        print("\n===== Shared Files =====")
        print("1. View Files")
        print("2. Access File")
        print("3. Share New File")
        print("4. Remove File")
        print("5. Back")

        choice = input("Enter choice: ")

        # READ FILE LIST
        with open("data/shared_files.txt","r") as f:
            files = f.readlines()

        # VIEW FILES
        if choice == "1":
            print("\nShared Files:")
            for i,f in enumerate(files):
                print(i+1, f.strip())

            input("\nPress Enter to continue...")


        # ACCESS FILE
        elif choice == "2":

            print("\nShared Files:")
            for i,f in enumerate(files):
                print(i+1, f.strip())

            num = int(input("Select file: "))
            selected = files[num-1].strip()

            print(user,"is accessing",selected)

            log_activity(user + " accessed " + selected)

            input("\nPress Enter to continue...")


        # SHARE FILE
        elif choice == "3":

            new_file = input("Enter file name to share: ")

            if new_file.strip() != "":
                with open("data/shared_files.txt","a") as f:
                    f.write(new_file + "\n")

                print("File shared successfully!")
                log_activity(user + " shared " + new_file)

            else:
                print("Invalid file name!")

            input("\nPress Enter to continue...")


        # REMOVE FILE
        elif choice == "4":

            print("\nShared Files:")
            for i,f in enumerate(files):
                print(i+1, f.strip())

            num = int(input("Select file to remove: "))

            removed = files.pop(num-1).strip()

            with open("data/shared_files.txt","w") as f:
                for file in files:
                    f.write(file)

            print("File removed:", removed)

            log_activity(user + " removed " + removed)

            input("\nPress Enter to continue...")


        elif choice == "5":
            break

        else:
            print("Invalid choice")