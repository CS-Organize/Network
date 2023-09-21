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
	int					str_len = 0;
	int					idx = 0, read_len = 0;

	if (ac != 3)
	{
		printf("Usage : %s <IP> <port>\n", av[0]);
		exit(1);
	}

	sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // TCP 소켓 생성, 앞의 두 인자를 통한 프로토콜 정보에 해당하는 tcp 프로토콜 하나이기 때문에 세 번째 인자는 생략 가능
	if (sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(av[1]);
	serv_addr.sin_port = htons(atoi(av[2]));

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) // connect 함수의 호출을 통해 서버에 연결을 요청
		error_handling("connect() error");

	for (size_t i = 0; i < 30000; i++)
		printf("Wait time %d\n", i);

	while (read_len = read(sock, &message[idx++], 1)) // read 함수의 호출을 통해 서버로부터 전송된 데이터를 읽어들임, 전송되는 데이터의 경계(Boundary)가 존재하지 않는다.
	{
		if (read_len == -1)
			error_handling("read() error");
		str_len += read_len;
	}

	printf("Message from server : %s \n", message);
	printf("Function read call count : %d \n", str_len);
	close(sock);

	return (0);
}

void	error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
