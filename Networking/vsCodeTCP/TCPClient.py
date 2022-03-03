# TCPClient.py
import socket
#Assigning servername and port number
servername="10.11.6.117"
serverport=1200
clientSocket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
#Establishing connection with server
clientSocket.connect((servername,serverport))
print("Connected to ",(servername,serverport))

message=input("Input lowercase sentence ")
clientSocket.send(message.encode())

#The send message is modified into Capital letters and send back again, so we are receiving it using recv()
modifiedsentence=clientSocket.recv(1024)
print(modifiedsentence.decode())

clientSocket.close()
