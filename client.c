#include "library.h"


// void sendPacket(int questionId, char ...parameters);
int showMenu();


/*
- Client has to establish a connection between him and the server
    {
        - Create a socket; (socket())
        - Connect to the server; (connect())
        - Receive data; (recv())
    }
*/


int showMenu(){

    int option = 0;

    printf("--------MENU--------\n");
    printf("0. Disconnect");
    printf("1. Enter details\n");
    printf("2. Update details\n");
    printf("3. Delete details\n");
    printf("4. Enter courses\n");
    printf("5. Update courses\n");
    printf("6. Delete Courses\n");
    printf("7. Enter score\n");
    printf("8. Update score\n");
    printf("9. Delete score\n");
    printf("10. Search grades\n");
    printf("11. Grade per course\n");
    scanf("%d", &option);

    if(option < 0 || option > 11 || !isdigit(option)){
        return -1;
    }
    return option;
}

int main(){
    showMenu();
    int clientFd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8000);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    int checkForConnection = connect(clientFd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));

    if(checkForConnection == -1){
        printf("Client: Error: The connection failed\n");
    } else {
        char stringData[255];

        recv(clientFd, stringData, sizeof(stringData), 0);
        printf("Message: %s\n", stringData);
    }


    return 0;
}