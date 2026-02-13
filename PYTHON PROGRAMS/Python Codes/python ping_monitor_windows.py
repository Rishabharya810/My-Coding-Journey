import subprocess
import re
import smtplib
from email.message import EmailMessage

def check_ping(hostname):
    ping = subprocess.Popen(
        ["ping", "-c", "4", hostname],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    out, _ = ping.communicate()
    out = out.decode("utf-8")
    
    times = re.findall(r"time=([\d.]+) ms", out)
    avg_time = sum(float(t) for t in times) / len(times) if times else 0
    
    return avg_time

def send_email(subject, body, sender_email, receiver_email, password, smtp_server):
    message = EmailMessage()
    message["From"] = sender_email
    message["To"] = receiver_email
    message["Subject"] = subject
    message.set_content(body)

    with smtplib.SMTP_SSL(smtp_server, 465) as server:
        server.login(sender_email, password)
        server.send_message(message)

def main():
    hostname = input("Enter the hostname or IP address to monitor: ")
    threshold = float(input("Enter the threshold in milliseconds: "))
    sender_email = input("Enter your email address: ")
    receiver_email = input("Enter the recipient's email address: ")
    password = input("Enter your email password: ")  # Use app password if required
    smtp_server = input("Enter SMTP server (e.g., smtp.example.com): ")

    while True:
        ping_time = check_ping(hostname)
        print(f"Ping time for {hostname}: {ping_time} ms")

        if ping_time > threshold:
            subject = "High Ping Rate Alert"
            body = f"Ping time ({ping_time} ms) exceeded threshold ({threshold} ms) for {hostname}"
            send_email(subject, body, sender_email, receiver_email, password, smtp_server)
            print(f"Sent email notification for high ping rate to {receiver_email}")

        # Adjust the time interval as needed (e.g., every 5 minutes)
        # You may need to handle exceptions and add error checking for stability
        import time
        time.sleep(0)  # Sleep for 5 minutes

if __name__ == "__main__":
    main()
