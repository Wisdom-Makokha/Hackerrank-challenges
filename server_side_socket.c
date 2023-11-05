/**
 * @file server_side_socket.c
 * @author Wisdom Makokha
 * @brief 
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

//Server side c/c++ program to demonstrate socket programming
#include <stdio.h>
#ifdef __WIN32__ 
#include <winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#pragma comment(lib, "Ws2_32.lib")

int main(int argc, char const * argv[])
{
    int server_fd, new_socket;
    ssize_t valread;
    struct sockaddr_in address;
    int opt = 1;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    //Creating the socket file descriptor
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    //Forcefully attaching socket to port 8080
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    //Forcefully attaching socket to port 8080
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == INVALID_SOCKET)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if(listen(server_fd, 3) == INVALID_SOCKET)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) == INVALID_SOCKET)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    valread = read(new_socket, buffer, 1024 - 1); // subtract 1 for the null terminator at the end

    printf("%s\n", buffer);
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    //close the connected socket
    closesocket(new_socket);

    //close the listening socket
    closesocket(server_fd);
    return 0;
}