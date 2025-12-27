#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

using namespace std;



int main() {
    int status;
    struct addrinfo hints;
    struct addrinfo *res;  // will point to the results

    memset(&hints, 0, sizeof hints); // make sure the struct is empty
    hints.ai_family = AF_UNSPEC;     // don't care IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM; // TCP stream sockets


    // get ready to connect
    status = getaddrinfo("www.example.net", "3490", &hints, &res);

    int s = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

    cout << s << endl;







    




}