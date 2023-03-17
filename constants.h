#ifndef CONSTANTS_H
#define CONSTANTS_H

#define IP_LENGTH 16
#define PORT 10100
#define DEMO_PORT 10200
#define TESTING_INTERVAL 5
#define NUM_NODES 5

#define TEST_MSG 1
#define REQUEST_MSG 2

#define ENTROPHY_THRESHOLD 2

#define NON_FAULTY_VAL "WE_ARE_GOOD"

typedef struct {
  char ip_addr[IP_LENGTH];
  int node_num;
} connection;

typedef struct {
  char filename[100];
  double entrophy;
} file_entr;

#endif
