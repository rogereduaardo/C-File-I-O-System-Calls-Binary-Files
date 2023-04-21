  #include <stdio.h>

#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



int main(void) {
  printf("C File I/O - System Calls - Binary Files\n");

  // int open (const char *pathname, int flags);
  const char *pathname = "data.bin";
  int flags = O_RDWR;
  int fd = open(pathname, flags);
  if (-1 == fd)
  {
    perror("open");
    return 1;
  }

  printf("Input file contents:\n");
  char buf[100];
  int num_read = read(fd, buf, sizeof(buf));
  for (int i = 0; i < num_read; i++)
    {
      printf("buf[%d]: 0x%02x - %d (%c)\n", i, buf[i], buf[i], buf[i]);
    }
  close(fd);

  fd = open(pathname, flags);
  char bin_data[] = {0x01, 0x02, 0x03};
  int num_written = write(fd, bin_data, sizeof(bin_data));
  if (-1 == num_written)
  {
    perror("write");
    return 2;
  }

  printf("num_written: %d\n", num_written);
  
  close(fd);
  
  return 0;
}