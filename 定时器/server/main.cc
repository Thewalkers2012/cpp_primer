#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv)
{
  if (argc <= 2)
  {
    printf("usage:%s ip_address port_number\n", argv[0]);
    return 1;
  }

  const char *ip = argv[1];
  int port = atoi(argv[2]);

  int ret = 0;
  struct sockaddr_in address;
  bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);

  int sockfd = socket(PF_INET, SOCK_STREAM, 0);
  assert(sockfd >= 0);

  ret = bind(sockfd, (struct sockaddr*)&address, sizeof(address));
  assert(ret != -1);

  ret = listen(sockfd, 5);
  assert(ret != -1);

  sleep(10);

  while (1)
  {
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);

    int connfd = accept(sockfd, (struct sockaddr*)&client, &client_addrlength);
    if (connfd < 0)
    {
      printf("errno is: %d\n", errno);
    }
    else
    {
      // 接受链接成功则打印出客户端的 ip 地址和端口号
      char remote[INET_ADDRSTRLEN];
      printf("connected with ip:%s and port:%d\n", inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN), ntohs(client.sin_port));
      close(connfd);
    }
  }

  close(sockfd);

  return 0;
}
