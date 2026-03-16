def start_quiz():

    score = 0

    print("\n===== OS Quiz =====")

    print("\n1. Which scheduling algorithm may cause starvation?")
    print("1) FCFS")
    print("2) SJF")
    print("3) Round Robin")
    print("4) FIFO")

    ans = input("Enter answer: ")

    if ans == "2":
        print("Correct!")
        score += 1
    else:
        print("Wrong! Correct answer: SJF")

    print("\nYour Score:", score)
    input("Press Enter to return to menu...")