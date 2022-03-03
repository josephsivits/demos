#  TCPserver.py
import socket
serverport = 1200
serversocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

# Binding the ipaddress and port number to the server's socket
serversocket.bind(('',serverport))

# maximum number of queued connections... 1
serversocket.listen(1)
print("The Server is Ready!")

while True:
    # connectionsocket is dedicated to particular client
    connectionSocket, addr=serversocket.accept()
    #receive the message from Client and decode it
    message=connectionSocket.recv(1024).decode()
    #convert the received message to Uppercase using upper() function
    modifiedmessage=message.upper()
    #send the modifiedmessage to the client
    connectionSocket.send(modifiedmessage.encode())
    connectionSocket.close()
