#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main()
{

	int sock = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = inet_addr("127.0.01");

	bind(sock, (struct sockaddr *)&addr, sizeof(addr));

	if (listen(sock, 5) == -1)
	{
		perror("Error listening on socket.\n");
		exit(-1);
	}

	struct sockaddr_in clientaddr;
	socklen_t client_len = sizeof(clientaddr);

	int client_sock = accept(sock, (struct sockaddr *)&clientaddr, &client_len);

	if (client_sock == -1)
	{
		perror("Error accepting client.\n");
		exit(-1);
	}

	char buffer[1024];

	recv(client_sock, &buffer, sizeof(buffer), 0);
	printf("got: %s\n", buffer);

	send(client_sock, "Hello Client!\n", 15, 0);

	close(client_sock);
	close(sock);

	return 0;
}
