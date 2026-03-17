def log_activity(text):

    with open("data/activity_log.txt","a") as f:
        f.write(text + "\n")