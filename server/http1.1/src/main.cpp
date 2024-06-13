#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include "RequestMessage.hpp"

const int BUFFER_SIZE = 4096;

void handle_client(int client_socket)
{
    RequestMessage req_msg;
    char buffer[BUFFER_SIZE];
    std::memset(buffer, 0, BUFFER_SIZE);

    // 클라이언트로부터 요청 읽기
    int bytes_received = read(client_socket, buffer, BUFFER_SIZE - 1);
    if (bytes_received < 0)
    {
        std::cerr << "Error reading from socket" << std::endl;
        close(client_socket);
        return;
    }

    // 요청 메시지 출력
    std::cout << "HTTP Request:\n" << buffer << std::endl;

    std::string html_response = "<html>"
                                "<body>"
                                "<h1>Hello World</h1>"
                                "</body>"
                                "</html>";

    // 간단한 HTTP 응답 작성
    std::string http_response = "HTTP/1.1 200 OK\r\n"
                                "Content-Type: text/html\r\n"
                                "Content-Length: " +
                                std::to_string(html_response.size()) +
                                "\r\n"
                                "\r\n" +
                                html_response;

    // 클라이언트로 응답 보내기
    int bytes_sent =
        write(client_socket, http_response.c_str(), http_response.size());
    if (bytes_sent < 0)
    {
        std::cerr << "Error writing to socket" << std::endl;
    }

    // 소켓 닫기
    close(client_socket);
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Error: ./server <port>" << std::endl;
        return 1;
    }
    int port;
    std::istringstream iss(argv[1]);
    iss >> port;
    // 소켓 생성
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        std::cerr << "Error opening socket" << std::endl;
        return 1;
    }

    // 소켓 옵션 설정
    int optval = 1;
    setsockopt(
        server_socket, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // 서버 주소 구조체 설정
    struct sockaddr_in server_addr;
    std::memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    // 소켓에 주소 바인딩
    if (bind(server_socket,
             (struct sockaddr *)&server_addr,
             sizeof(server_addr)) < 0)
    {
        std::cerr << "Error on binding" << std::endl;
        close(server_socket);
        return 1;
    }

    // 클라이언트 연결 대기
    listen(server_socket, 5);
    std::cout << "Server is listening on port " << port << std::endl;

    // 클라이언트 연결 수락 및 처리
    while (true)
    {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket =
            accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0)
        {
            std::cerr << "Error on accept" << std::endl;
            continue;
        }

        handle_client(client_socket);
    }

    // 서버 소켓 닫기
    close(server_socket);
    return 0;
}
