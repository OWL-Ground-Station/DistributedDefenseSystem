#include "communication.h"

void send_array(int sock, int arr[], int arr_size) {
    printf("here we are\n");
    int buffer[arr_size];
    for (int i = 0; i < arr_size; ++i) {
        buffer[i] = htonl(arr[i]);
    }

    if (send(sock, buffer, arr_size * sizeof(int), 0) < 0) {
        perror("Error sending tested up\n");
    }
}

void send_fault_status(int sock, int faulty) {
    int status = htonl(faulty);

    if (send(sock, &status, sizeof(int), 0) < 0) {
        perror("Error sending tested up\n");
    }
}

int receive_msg(int sock) {
    int msg_type;
    recv(sock, &msg_type, sizeof(msg_type), 0);
    return msg_type;
}

int init_client_to_server(char ip_address[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &(serv_addr.sin_addr));
    serv_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    return sock;
}

int request_fault_status(int sock) {
    int test_msg = TEST_MSG;
    send(sock, &test_msg, sizeof(test_msg), 0);

    int status;
    recv(sock, &status, sizeof(status), 0);
    status = ntohl(status);
    return status;
}

void request_arr(int sock) {
    int req_msg = REQUEST_MSG;
    printf("here_1\n");
    send(sock, &req_msg, sizeof(req_msg), 0);

    int buffer[NUM_NODES] = {0};
    printf("here\n");
    recv(sock, &buffer, sizeof(buffer), 0);
    printf("Sent array values: \n");
    for (int i = 0; i < NUM_NODES; ++i) {
        int val = ntohl(buffer[i]);
        if (i < NUM_NODES - 1) printf("%d ", val);
        else printf("%d\n", val);
    }
}