#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

using namespace std;



int main() {
    int status;
    struct addrinfo hints;
    struct addrinfo *res;  // will point to the results

    struct sockaddr_storage userMes;

    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets


    // set up a server for people to send too
    status = getaddrinfo(NULL, "8080", &hints, &res);

    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    int bindStat = ::bind(s, res->ai_addr, res->ai_addrlen);
    
    cout << "Bind: " << bindStat << endl;

    listen(s, 5); // listening for people

    socklen_t addrSize = sizeof userMes;
    int accepted = accept(s, (struct sockaddr *)&userMes, &addrSize);




    // sending message

    char *msg = "Stupid ass fucker";
    int len; 
    size_t bytes_sent;

    len = strlen(msg);
    bytes_sent = send(accepted, msg, len, 0);

    cout << bytes_sent << endl;

    

   

    



    



    

    


















    
    


    







    




}