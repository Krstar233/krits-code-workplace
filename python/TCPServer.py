from socket import *
serverPort = 12000
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(("",serverPort))
serverSocket.listen()
print("The server is ready to receive")
while True:
    connectSocket, addr = serverSocket.accept()
    sentence = connectSocket.recv(1024).decode()
    capitalizedSentence = sentence.upper()
    connectSocket.send(capitalizedSentence.encode())
    connectSocket.close()