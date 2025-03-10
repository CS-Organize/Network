#ifndef WEBSERVER_H
# define WEBSERVER_H

# include "./libft/libft.h"
# include <arpa/inet.h>
# include <stdio.h>
# include <string.h>

# define MAX_REQUEST_SIZE 2048

// handle_request.c
void handle_request(int client_socket, const char *file_name);

#endif
