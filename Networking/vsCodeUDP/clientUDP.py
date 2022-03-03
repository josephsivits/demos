# clientUDP.py
import socket
servername = "10.11.6.117"
serverport=1200
clientsocket=socket.socket(socket.AF_INET,socket.SOCK_DGRAM)

message=input("Input lowercase sentence ")
print("sending message to ",(servername,serverport))

clientsocket.sendto((message).encode(),(servername,serverport))
modifiedmessage, serveraddress=clientsocket.recvfrom(2048)
clientsocket.close()
print(modifiedmessage.decode())