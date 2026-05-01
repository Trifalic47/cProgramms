#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#define DEFAULT_PORT 9000

int main(int argc, char *argv[]) {
    /* Making socket which uses -> IPv4,TCP */
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock < 0) {
        perror("Unable to create the socket\n");
        return 1;
    }

    /* Making an connection to the server */
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(DEFAULT_PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0){
        perror("Invalid address/Address not supported\n");
        return 1;
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sock);
        return 1;
    }
    printf("Connected to the server\n");
    send(sock,argv[1],strlen(argv[1]),0);
    close(sock);
    return 0;
}
