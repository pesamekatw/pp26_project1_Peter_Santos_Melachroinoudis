#include "library.h"
/*

Server Side of Socket
    {
        - Create a socket; (socket())
        - Bind the socket; (bind())
        - Listen for connections; (listen())
        - Accept a client connection; (accept())
    }

*/
int main(){

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    char serverMessage[255] = "Message from the server";

    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    listen(serverSocket, 1);

    int clientSocket = accept(serverSocket, NULL, NULL);

    send(clientSocket, serverMessage, sizeof(serverMessage), 0);


    return 0;
}