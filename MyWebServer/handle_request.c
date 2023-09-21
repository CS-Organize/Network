#include "webserver.h"

void handle_request(int client_socket, const char *file_name)
{
	char	response[MAX_REQUEST_SIZE];	// HTTP 응답 메시지
	FILE	*file;						// 요청된 파일의 내용을 읽기 위한 파일 포인터
	char	page_file_name[256];

	// HTTP 응답 헤더 작성
	ft_strlcpy(response, "HTTP/1.1 200 OK\r\n", 19);

	// 파일 확장자에 따른 Content-Type 설정
	const char *extension = ft_strrchr(file_name, '.');	// 파일명에서 마지막 . 문자 이후를 확장자로 간주

	if (extension != NULL)
	{
		if (ft_strncmp(extension, ".html", 6) == 0)
			ft_strlcat(response, "Content-Type: text/html\r\n", MAX_REQUEST_SIZE);
		else if (ft_strncmp(extension, ".jpeg", 6) == 0 || ft_strncmp(extension, ".jpg", 5) == 0)
			ft_strlcat(response, "Content-Type: image/jpeg\r\n", MAX_REQUEST_SIZE);
		else if (ft_strncmp(extension, ".png", 5) == 0)
			ft_strlcat(response, "Content-Type: image/png\r\n", MAX_REQUEST_SIZE);
	}

	// 파일 경로 수정: "page" 폴더 기준으로 설정
	if (ft_strncmp(file_name, "img/", 4) == 0) {
	    // "img/"로 시작하는 경우, "img/"로 변경
	    snprintf(page_file_name, sizeof(page_file_name), "img/%s", file_name + 4);
	} else {
	    // 그 외의 경우 "page/"로 설정
	    snprintf(page_file_name, sizeof(page_file_name), "page/%s", file_name);
	}
	printf("Requested file: %s\n", page_file_name);

	// 파일 열기 (바이너리 모드)
	file = fopen(page_file_name, "rb");

	if (file == NULL) {
		// 파일을 찾을 수 없는 경우 404 오류 응답
		strcat(response, "HTTP/1.1 404 Not Found\r\n\r\n");
		write(client_socket, response, strlen(response));
	} else {
		// Content-Length 헤더 추가
		fseek(file, 0, SEEK_END);
		long file_size = ftell(file);
		fseek(file, 0, SEEK_SET);
		char content_length_header[100];
		snprintf(content_length_header, sizeof(content_length_header), "Content-Length: %ld\r\n", file_size);
		strcat(response, content_length_header);

		// 응답 헤더 마무리
		strcat(response, "\r\n");

		// 응답 헤더 전송
		write(client_socket, response, strlen(response));

		// 파일 내용을 읽어 응답으로 보냄
		char buffer[MAX_REQUEST_SIZE];
		size_t read_size;
		while ((read_size = fread(buffer, 1, sizeof(buffer), file)) > 0)
			write(client_socket, buffer, read_size);
		fclose(file);
	}
	// 클라이언트 소켓 닫기
	close(client_socket);
}
