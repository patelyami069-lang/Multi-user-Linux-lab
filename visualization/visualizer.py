import os
import time

QUEUE_FILE = "data/printer_queue.txt"
PRINTING_FILE = "data/printing_status.txt"


def read_queue():
    jobs = []

    if not os.path.exists(QUEUE_FILE):
        return jobs

    with open(QUEUE_FILE, "r") as f:
        for line in f:
            parts = line.strip().split()
            if len(parts) >= 2:
                jobs.append(f"{parts[0]}:{parts[1]}")

    return jobs


def read_printing():
    if not os.path.exists(PRINTING_FILE):
        return None

    with open(PRINTING_FILE, "r") as f:
        line = f.readline().strip()

    if not line:
        return None

    parts = line.split()
    if len(parts) >= 2:
        return f"{parts[0]}:{parts[1]}"

    return None


def draw_system(printing, queue):
    os.system("clear")

    print("\n=========== PRINTER SYSTEM ===========\n")

    if printing:
        print(f"Printing: {printing}")
        print()

        print("Printing", end="", flush=True)
        for _ in range(5):
            time.sleep(0.5)
            print(".", end="", flush=True)
        print("\n")
    else:
        print("Printing: None\n")

    print("Waiting Queue:")

    if queue:
        for job in queue:
            print(f"- {job}")
    else:
        print("Empty")

    print("\n======================================\n")


printing = read_printing()
queue = read_queue()

draw_system(printing, queue)

time.sleep(3)