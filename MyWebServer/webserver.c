#include "webserver.h"

// 1. 소켓 생성					-> socket
// 2. IP주소와 PORT번호 할당	-> bind
// 3. 연결요청 가능상태로 변경	-> listen
// 4. 연결요청에 대한 수락		-> accept

int main(int ac, char *av[])
{
	int					port;
	int					server_socket;
	int					client_socket;
	struct sockaddr_in	server_addr;
	struct sockaddr_in	client_addr;
	socklen_t			client_addr_len;
	char				request[MAX_REQUEST_SIZE];
	char				*file_name;

	if (ac != 2)
	{
		printf("Usage: %s <port>\n", av[0]);
		return 1;
	}

	port = ft_atoi(av[1]);
	client_addr_len = sizeof(client_addr);

	// 서버 소켓 생성
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	// 서버 주소 설정
	ft_bzero(&server_addr, sizeof(server_addr));		// 0으로 초기화

	server_addr.sin_family = AF_INET; 					// IPv4 주소 체계 사용
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);	// 32비트 IPv4 주소
	server_addr.sin_port = htons(port);					// 서버가 사용할 포트 번호

	// htons: host to network short (Endianness)

	// 서버 소켓에 주소 바인딩
	bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

	// 서버 소켓으로 클라이언트의 연결 요청을 기다림 (최대 5개)
	listen(server_socket, 5);

	printf("웹 서버가 시작되었습니다. 포트 %d에서 대기 중...\n", port);

	while (1) {
		// 클라이언트 연결 대기
		client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
		// 요청 처리 (요청된 파일명을 URL에서 추출)
		read(client_socket, request, sizeof(request));

		printf("#request\n%s\n", request);
		file_name = strtok(request, " ");	// 첫 번째 문자열을 가져옴
		file_name = strtok(NULL, " ");		// 두 번째 문자열을 가져옴
		printf("#file_name\n%s\n", file_name);

		if (file_name != NULL)
		{
			// 파일명이 존재하면 "/" 문자열을 제거하여 파일명으로 사용
			if (ft_strncmp(file_name, "/", 2) == 0)
				file_name = "index.html";
			else
				file_name++;
		}
		else
			file_name = "index.html";

		handle_request(client_socket, file_name);	// HTTP 요청을 처리하는 함수
	}
	// 서버 소켓 닫기 (실행되지 않음)
	close(server_socket);
	return 0;
}
