# serverUDP.py
import socket
serverport=1200
serversocket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

# Binding the ipaddress and port number to the server's socket
serversocket.bind(('',serverport))

print("The Server is Ready!")
message,clientaddress=serversocket.recvfrom(2048)
message = message.decode()
modifiedmessage=message.upper()

#encodes message back into bytes-like string
serversocket.sendto(modifiedmessage.encode(),clientaddress)
