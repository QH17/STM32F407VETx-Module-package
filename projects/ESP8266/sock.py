
import socket

port = 8001
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("", port))                     # 从给定的端口，从任何发送者，接收UDP数据报
print("Waiting for the port", port)
 
while True:
    data, address = sock.recvfrom(1024)   # 接收一个最大报文为1024字节的数据报
    print("Received:", data, "from", address)
