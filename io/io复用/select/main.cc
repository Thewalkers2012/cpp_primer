#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc <= 2)
    {
        printf("usage: %s ip_address port_number\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &address.sin_addr);
    address.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    assert(sockfd >= 0);

    int ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
    assert(ret != -1);

    ret = listen(sockfd, 5);
    assert(ret != -1);

    struct sockaddr_in client_address;
    socklen_t client_addrlength = sizeof(client_address);
    int connfd = accept(sockfd, (struct sockaddr*)&client_address, &client_addrlength);
    if (connfd < 0)
    {
        printf("errno is: %s\n", errno);
        close(sockfd);
    }

    char buffer[1024];
    fd_set read_fds;
    fd_set exception_fds;
    FD_ZERO(&read_fds);
    FD_ZERO(&exception_fds);

    while (1)
    {
        memset(buffer, '\0', sizeof(buffer));
        // 每次调用 select 前都要重新在 read_fds 和 exception_fds 中设置
        // 文件描述符 connfd，因为事件发生后，文件描述符将被内核修改
        FD_ZERO(&read_fds);
        FD_ZERO(&exception_fds);

        ret = select(connfd + 1, &read_fds, NULL, &exception_fds, NULL);
        if (ret < 0)
        {
            printf("selection failure\n");
            break ;
        }

        // 对于可读事件，采用普通 recv 函数读取数据
        if (FD_ISSET(connfd, &read_fds))
        {
            ret = recv(connfd, buf, sizeof(buf) - 1, 0);
            if (ret <= 0)
            {
                break ;
            }
            printf("get %d bytes of normal data: %s\n", ret, buf);
        } 
        else if (FD_ISSET(connfd, &exception_fds)) 
        {
            ret = recv(connfd, buf, sizeof(buf) - 1, MSG_OOB);
            if (ret <= 0)
            {
                break ;
            }
        }
    }

    close(connfd);
    close(sockfd);

    return 0;
}