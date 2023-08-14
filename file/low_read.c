#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100

void	error_handling(char *message);

int	main(void)
{
	char	buf[BUF_SIZE];
	int		fd = open("data.txt", O_RDONLY); // 파일 data.txt를 읽기 전용으로 열기

	if (fd == -1)
		error_handling("open() error!");
	printf("file descriptor: %d \n", fd);

	if (read(fd, buf, sizeof(buf)) == -1) // data.txt의 내용을 buf에 저장
		error_handling("read() error!");
	printf("file data: %s", buf);
	close(fd);

	return (0);
}

void	error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
