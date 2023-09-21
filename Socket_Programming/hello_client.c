#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

void	error_handling(char *message);

int	main(int ac, char *av[])
{
	int					sock;
	struct sockaddr_in	serv_addr;
	char				message[30];
	int					str_len;

	if (ac != 3)
	{
		printf("Usage : %s <IP> <port>\n", av[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket() error"); // 소켓을 생성하는 순간에 서버 소켓과 클라이언트 소켓으로 나뉘는 것이 아니라 bind, listen 함수의 호출로 서버 소켓, connect 함수의 호출로 클라이언트 소켓이 된다.

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(av[1]);
	serv_addr.sin_port = htons(atoi(av[2]));

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) // connect 함수의 호출을 통해 서버에 연결을 요청
		error_handling("connect() error");

	str_len = read(sock, message, sizeof(message) - 1);
	if (str_len == -1)
		error_handling("read() error");

	printf("Message from server : %s \n", message);
	close(sock);

	return (0);
}

void	error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
