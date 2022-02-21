import subprocess
from subprocess import Popen
import fuzzy_engine, fuzz_pass
import time
def main():
    print "Type 1 to run, 0 to stop"
    print ">>>",
    command = input()
    while True:
        if command == 0:
            print "Exiting..."
            exit()
        else:
            print fuzz_pass.engine()
            time.sleep(3)
            print "Press 0 to stop or 1 to continue..."
            print ">>>",
            command = input()

main()
