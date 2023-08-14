#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 10000

void	error_handling(char *message);

int	main(int ac, char *av[])
{
	int					serv_sock;
	int					clnt_sock;
	struct sockaddr_in	serv_addr;
	struct sockaddr_in	clnt_addr;
	socklen_t			clnt_addr_size;

	char				message[BUF_SIZE];

	for (size_t i = 0; i < BUF_SIZE; i++)
		message[i] = '!';

	if (ac != 2)
	{
		printf("Usage : %s <port>\n", av[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0); // socket 함수 호출을 통해서 소켓을 생성
	if (serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family		= AF_INET;
	serv_addr.sin_addr.s_addr	= htonl(INADDR_ANY);
	serv_addr.sin_port			= htons(atoi(av[1]));

	if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) // bind 함수 호출을 통해서 IP주소와 PORT번호를 할당
		error_handling("bind() error");

	if (listen(serv_sock, 5) == -1) // listen 함수 호출을 통해서 연결 요청 대기상태로 진입
		error_handling("listen() error");

	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size); // accept 함수 호출을 통해서 연결요청에 대한 수락, 연결 요청이 있을 때까지 함수는 반환하지 않음
	if (clnt_sock == -1)
		error_handling("accept() error");

	write(clnt_sock, message, sizeof(message)); // accept를 지나고 실행되었다는 것은 연결요청이 있었다는 것이므로, write 함수를 통해서 클라이언트에게 메시지를 전송
	close(clnt_sock);
	close(serv_sock);

	return (0);
}

void	error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
