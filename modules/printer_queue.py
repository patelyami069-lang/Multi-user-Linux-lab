import time
import os
from modules.logs import log_activity

queue = []
printer_available = True

def clear():
    os.system('cls' if os.name == "nt" else "clear")

def printer_menu(user):

    while True:

        clear()
        print("\n===== Printer Menu =====")
        print("1. Add Print Job")
        print("2. Process Next Job")
        print("3. View Queue")
        print("4. Visualize Queue")
        print("5. Back to Main Menu")

        choice = input("Enter choice: ")

        if choice == "1":
            file = input("Enter file name to print: ")
            queue.append((user, file))
            print("Job added to queue")
            input("\nPress Enter to continue...")

        elif choice == "2":
            if len(queue) == 0:
                print("No print jobs in queue")
            else:
                job = queue.pop(0)
                print("Printing:", job[1], "for", job[0])
                print("Printing", end="")
                for i in range(5):
                    print(".", end="", flush=True)
                    time.sleep(0.5)
                
                print("\nPrint completed!\n")

            input("\nPress Enter to continue...")

        elif choice == "3":
            print("\nCurrent Queue:")
            if len(queue) == 0:
                print("Queue is empty")

            else:
                for i, job in enumerate(queue, start=1):
                    print(i, "-", job[0], ":", job[1])
            
            input("\nPress Enter to continue...")

        elif choice == "4":
            show_queue_visual()
            input("\nPress Enter to continue...")

        elif choice == "5":
            print("Returning to Main Menu...")
            break   

        else:
            print("Invalid choice")
            input("\nPress Enter to continue...")
    
def show_queue_visual():

    if len(queue) == 0:
        print("\nPrinter Queue Empty\n")
        return

    print("\nPrinter Queue\n")

    for job in queue:
        print(f"[ {job[1]} ]", end=" -> ")

    print("END\n")