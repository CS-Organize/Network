#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

const int MAX_REQUEST_SIZE = 1024;
char request[MAX_REQUEST_SIZE];

class TCPSocket
{
private:
    int mSocket;
    struct sockaddr_in mAddress;
public:
    TCPSocket(int rhsSocket = -1) : mSocket(rhsSocket)
    {
        if (mSocket == -1) // 기본 생성자를 통해 소켓 생성
        {
            // 소켓 생성
            mSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            if (mSocket < 0)
            {
                std::cerr << "Can not create socket" << std::endl;
                exit(1);
            }

            // 소켓 주소 구조체 초기화
            bzero((char *) &mAddress, sizeof(mAddress));
            mAddress.sin_family = AF_INET;
            mAddress.sin_addr.s_addr = htonl(INADDR_ANY);
            mAddress.sin_port = htons(80);
        }
    }

    ~TCPSocket()
    {
        close(mSocket);
    }

    void Bind()
    {
        if (bind(mSocket, (struct sockaddr *) &mAddress, sizeof(mAddress)) < 0)
        {
            std::cerr << "Can not bind socket" << std::endl;
            exit(1);
        }
    }

    void Listen()
    {
        if (listen(mSocket, 5) < 0)
        {
            std::cerr << "Can not listen" << std::endl;
            exit(1);
        }
    }

    TCPSocket Accept()
    {
        socklen_t addressLength = sizeof(mAddress);
        int clientSocket = accept(mSocket, (struct sockaddr *) &mAddress, &addressLength);
        if (clientSocket < 0)
        {
            std::cerr << "Accept failed" << std::endl;
            exit(1);
        }
        return TCPSocket(clientSocket);
    }

    void Read()
    {
        bzero(request, MAX_REQUEST_SIZE);
        read(mSocket, request, MAX_REQUEST_SIZE);
    }
};

int main()
{
    TCPSocket server;
    server.Bind();
    server.Listen();

    while (true)
    {
        TCPSocket client = server.Accept(); // 새 연결을 위한 소켓을 반환
        client.Read();
        std::cout << "Received request: " << request << std::endl;
    }
    return 0;
}
