#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void	error_handling(char *message);

int	main(void)
{
	char	buf[] = "Let's go!\n";
	int		fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC); // O_CREAT: 파일이 없으면 생성, O_WRONLY: 쓰기 전용, O_TRUNC: 기존 내용 삭제

	if (fd == -1)
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	if (write(fd, buf, sizeof(buf)) == -1) // fd에 buf의 내용을 쓰기
		error_handling("write() error!");
	close(fd);

	return (0);
}

void	error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
