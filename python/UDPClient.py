from socket import *

serverName = "localhost"
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input("input lowercase sentence:")
clientSocket.sendto(message.encode(), (serverName, serverPort))
modifiedMesssage, serverAddress = clientSocket.recvfrom(2048)
print(modifiedMesssage.decode())
clientSocket.close()