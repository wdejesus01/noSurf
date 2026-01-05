#include <stdio.h>
#include <netdb.h>
#include <string.h>

int hostName_check(const char *hostname) {
    struct addrinfo hints, *res;
    // Set bytes of hints struct = 0
    memset(&hints, 0, sizeof(hints));

    // getaddrinfo returns 0 on success or error code in gai_strerror(3)
    int status = getaddrinfo(hostname, NULL, &hints, &res);
    if (status == 0){
      freeaddrinfo(res);
      return status;
    }
    // Print out error string corresponding to getaddrinfo error code
    printf("%s\n",gai_strerror(status));
    return status;
}

int main(int argc, char *argv[]) {
  return hostName_check(argv[1]);
}
