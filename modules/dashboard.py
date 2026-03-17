import os
from modules.printer_queue import queue

def show_dashboard(user):

    print("\n========= LAB STATUS =========\n")

    print("User           :", user)
    print("Printer Status : Ready")

    try:
        with open("data/printer_queue.txt","r") as f:
            queue = f.readlines()
        print("Queue Length   :", len(queue))
    except:
        print("Queue Length   : 0")

    print("\n==============================")

    resource_table(user)

def resource_table(user):

    print("\n========= RESOURCE ALLOCATION =========\n")

    print("User\t\tResource\t\tStatus")
    print("-------------------------------------------")

    try:
        with open("data/printer_queue.txt","r") as f:
            jobs = f.readlines()

        if jobs:
            for job in jobs:
                u, file = job.strip().split(",")
                print(f"{u}\t\tPrinter({file})\t\tWaiting")

    except:
        pass

    try:
        with open("data/file_access_log.txt","r") as f:
            logs = f.readlines()

        if logs:
            last = logs[-1].strip().split(" ")
            print(f"{last[0]}\t\t{last[-1]}\t\tOpen")

    except:
        pass

    print("\n=======================================\n")