import socket


TCP_IP = '0.0.0.0'
TCP_PORT = 37337
BUFFER_SIZE = 1024  # Normally 1024, but we want fast response

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, TCP_PORT))
# Can have 5 concurrent connections, hence the 0.0.0.0 address
s.listen(5)

conn, addr = s.accept()
print 'Connection address:', addr
while 1:
    data = conn.recv(BUFFER_SIZE)
    if not data: break
    print "sent data:", data
    conn.send(data)  # echo

conn.close()
