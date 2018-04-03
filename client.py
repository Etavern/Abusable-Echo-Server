import socket

target = '127.0.0.1'
port = 6660

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((target, port))

client.send('testing')
response = client.recv(4096)

print(response)
