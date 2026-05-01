#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_PORT 9000

int main() {

    /*
     * What this line of code do.. ->
     * - Makes an new socket.
     * - Uses IPv4 -> AF_INET
     * - Uses TCP -> SOCK_STREAM
     * - Last one is 0 which is protocol.. Which would selected recommended connections method
     * It also checks for the socket creation error by doing if (sock < 0);
    */
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if (sock < 0) {
        perror("Socket creation failed!\n");
        return 1;
    }

    /* Now doing the binding work */
    struct sockaddr_in server_addr;
    memset(&server_addr,0,sizeof(server_addr));
    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_port = htons(DEFAULT_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY; // Accepts requests from all ip address
    if (bind(sock,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("Error on binding!");
        return 1;
    };
    printf("Socket binded on the port %d\n",DEFAULT_PORT);

    /* Listening on the socket -> sock and allowing maximum 5 connections */
    if (listen(sock, 5) < 0) {
        perror("Failed to listen!\n");
        return 1;
    };
    printf("Listening. Waiting for connection..\n");

    /* Accpeting and interpreting requests */
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);

        int client_fd = accept(sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_fd < 0 ) {
            perror("Error in accept!\n");
            continue;
        }

        printf("Client connected: %s:%d\n",inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));

        char buffer[1024];
        ssize_t bytes_received;

        // Use a loop because TCP may split one message into multiple chunks
        while ((bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
            buffer[bytes_received] = '\0'; // Null-terminate if it's a string
            printf("Received: %s\n", buffer);
    }

    if (bytes_received == 0) {
        printf("Connection closed by peer.\n"); // Orderly shutdown
    } else if (bytes_received == -1) {
        perror("recv failed"); // Handle errors
        }
    }

    close(sock);

    return 0;
}
