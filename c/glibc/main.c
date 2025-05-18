#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <arpa/inet.h>

#define PORT 3000
#define BACKLOG 128

static const char RESPONSE[] =
    "HTTP/1.1 200 OK\r\n"
    "Content-Length: 13\r\n"
    "Content-Type: text/plain\r\n"
    "Connection: close\r\n"
    "\r\n"
    "Hello, World!";

void handle_client(int client_fd)
{
    size_t total = 0;
    size_t len = sizeof(RESPONSE) - 1;

    while (total < len)
    {
        ssize_t sent = write(client_fd, RESPONSE + total, len - total);
        if (sent <= 0)
        {
            perror("write");
            break;
        }
        total += sent;
    }

    close(client_fd);
}

int main(void)
{
    signal(SIGPIPE, SIG_IGN);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket");
        return 1;
    }

    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR)");
        close(server_fd);
        return 1;
    }

#ifdef SO_REUSEPORT
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt));
#endif

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = htonl(INADDR_ANY)};

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        close(server_fd);
        return 1;
    }

    if (listen(server_fd, BACKLOG) < 0)
    {
        perror("listen");
        close(server_fd);
        return 1;
    }

    for (;;)
    {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0)
        {
            perror("accept");
            continue;
        }
        handle_client(client_fd);
    }

    close(server_fd);
    return 1;
}
