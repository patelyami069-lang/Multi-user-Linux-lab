def deadlock_demo():

    print("\n===== Deadlock Detection Simulation =====")

    print("\nEnter resource information")

    user1_hold = input("User1 holds resource: ")
    user1_wait = input("User1 waiting for resource: ")

    user2_hold = input("User2 holds resource: ")
    user2_wait = input("User2 waiting for resource: ")

    print("\nAnalyzing system state...\n")

    # Circular wait check
    if user1_wait == user2_hold and user2_wait == user1_hold:
        print("⚠ Deadlock Detected!")
        print("Circular wait between User1 and User2")

    else:
        print("No Deadlock Detected")