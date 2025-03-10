#include "webserver.h"

void handle_request(int client_socket, const char *file_name)
{
	char		response[MAX_REQUEST_SIZE];	// HTTP 응답 메시지
	FILE		*file;						// 요청된 파일의 내용을 읽기 위한 파일 포인터
	char		*page_file_name;
	const char	*extension;
	size_t		read_size;
	char		buffer[MAX_REQUEST_SIZE];

	// HTTP 응답 헤더 작성
	ft_strlcpy(response, "HTTP/1.1 200 OK\r\n", MAX_REQUEST_SIZE);

	// 파일 확장자에 따른 Content-Type 설정
	extension = ft_strrchr(file_name, '.');	// 파일명에서 마지막 . 문자 이후를 확장자로 간주
	page_file_name = NULL;
	if (extension != NULL)
	{
		if (ft_strncmp(extension, ".html", 6) == 0)
			ft_strlcat(response, "Content-Type: text/html\r\n", MAX_REQUEST_SIZE);
		else if (ft_strncmp(extension, ".jpeg", 6) == 0 || ft_strncmp(extension, ".jpg", 5) == 0)
			ft_strlcat(response, "Content-Type: image/jpeg\r\n", MAX_REQUEST_SIZE);
		else if (ft_strncmp(extension, ".png", 5) == 0)
			ft_strlcat(response, "Content-Type: image/png\r\n", MAX_REQUEST_SIZE);
	}

	if (ft_strncmp(file_name, "img/", 4) == 0)
		page_file_name = ft_strdup(file_name);
	else if (extension != NULL && ft_strncmp(extension, ".html", 6) == 0)
		page_file_name = ft_strjoin("page/", file_name);
	else
		page_file_name = ft_strdup(file_name);

	printf("Requested file: %s\n", page_file_name);

	// 파일 열기 (바이너리 모드)
	file = fopen(page_file_name, "rb"); // "rb": "read binary => 이미지 파일을 읽을 때는 이 모드로 열어야 함

	// 파일을 찾을 수 없는 경우 404 오류 응답
	if (file == NULL)
	{
		ft_strlcpy(response, "HTTP/1.1 404 Not Found\r\n", MAX_REQUEST_SIZE);
		ft_strlcat(response, "Content-Type: text/html\r\n", MAX_REQUEST_SIZE);
		file = fopen("page/404.html", "rb");
	}
	// Content-Length 헤더 추가
	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	char content_length_header[100];
	snprintf(content_length_header, sizeof(content_length_header), "Content-Length: %ld\r\n", file_size);
	ft_strlcat(response, content_length_header, MAX_REQUEST_SIZE);

	// 응답 헤더 마무리
	ft_strlcat(response, "\r\n", MAX_REQUEST_SIZE);

	// 응답 헤더 전송
	write(client_socket, response, strlen(response));

	// 파일 내용을 읽어 응답으로 보냄
	while ((read_size = fread(buffer, 1, sizeof(buffer), file)) > 0)
		write(client_socket, buffer, read_size);
	fclose(file);

	free(page_file_name);
	// 클라이언트 소켓 닫기
	close(client_socket);
}
