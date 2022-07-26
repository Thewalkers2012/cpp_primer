#include "timer/lst_timer.h"

#include <fcntl.h>

#define FD_LIMIT 65535
#define MAX_EVENT_NUMBER 1024
#define TIMESLOT 5

static int pipefd[2];

// 利用代码清淡中的生序链表来管理定时器
static sort_timer_lst timer_lst;
static int epollfd = 0;

int setnonblocking(int fd)
{
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}

void addfd(int epollfd, int fd)
{
}