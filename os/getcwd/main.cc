#include <stdio.h>
#include <unistd.h>

int main()
{
  char server_name[200];
  getcwd(server_name, 200);
  printf("%s\n", server_name);
  return 0;
}