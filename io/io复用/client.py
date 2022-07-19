import socket

s = socket.socket()
s.connect(('10.248.185.252', 8000))
s.send("hello".encode())
s.close()
