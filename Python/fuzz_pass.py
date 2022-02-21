# Code by Varun Belani
# This code checks to see if password fuzzing is successful on login page
# Using the default admin user
import urllib2
import urllib
import fuzzy_engine
import subprocess
from subprocess import Popen, PIPE
from multiprocessing import Process, Queue
import requests
params = "command=login&username=admin&password=%s&encoded=true" 
url = "http://10.0.0.142:8080/WebInterface/login.html"
fuzzed_input = fuzzy_engine.rand_gen()

print "Output from the fuzz engine:"
print fuzzed_input

# All this code is me stumbling around
# cmd = "curl -d 'command=login&username=admin&password=%s&encoded=true' http://10.0.0.142:8080/WebInterface/login.html" % fuzzed_input
#def engine():
#    return subprocess.Popen(["curl", "-d", params, "-c", "-", url, "%", pass_command])
#    return subprocess.Popen("curl -d", params, "-c -", url, "%",pass_command)
    
# print subprocess.call(['curl','-d','command=login&username=admin&password=%s&encoded=true','http://10.0.0.142:8080/WebInterface/login.html' ]shell=True)
def engine():
    data = {
      'command': 'login',
      'username': 'admin',
      'password': fuzzed_input,
      'encoded': 'true'
    }
    # This website is awesome!!!
    # https://curl.trillworks.com/#python
    response = requests.post(url, data=data)

    print response
    print response.encoding
    print response.cookies
