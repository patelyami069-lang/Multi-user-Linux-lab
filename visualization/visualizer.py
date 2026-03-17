import time
import os
import sys

QUEUE_FILE = "data/printer_queue.txt"

previous_queue = []


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


def draw(queue, printing=None):

    os.system("cls" if os.name == "nt" else "clear")

    print("\n=========== PRINTER SYSTEM ===========\n")

    if printing:
        print("Printer Status:")
        print(f"[ PRINTING ]  →  [{printing}]")
        print()

    if queue:
        visual = " → ".join([f"[{job}]" for job in queue])
        print("Waiting Queue:")
        print(visual)
    else:
        print("Waiting Queue: Empty")

    print("\n======================================\n")


while True:

    current_queue = read_queue()

    # detect job printed
    if len(previous_queue) > len(current_queue):

        finished_job = previous_queue[0]

        draw(current_queue, finished_job)

        time.sleep(1.5)

    draw(current_queue)

    previous_queue = current_queue

    time.sleep(1)

    print("\nVisualization complete. Closing in 5 seconds...")
    time.sleep(5)
    sys.exit()