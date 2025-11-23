#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

    struct ifaddrs *address; //var declaration addresses (storing all the dresses)
    // getifaddrs function allocates memory and fills in a linked list of addresses
    

    if (getifaddrs(&address) == -1) {
        printf("getifaddrs call failed \n");
        return -1;
    }

    struct ifaddrs *addresses = addresses;
    while(address) {
        int family = address->ifa_addr->sa_family;
        if (family == AF_INET || family == AF_INET6) {

            printf("%s\t", address->ifa_name);
            printf("%s\t", family == AF_INET ? "IPv4" : "IPv6");

            char ap[100];
            const int family_size = family == AF_INET ?
            sizeof(struct sockaddr_in) : sizeof(struct sockaddr_in6);
            getnameinfo(address->ifa_addr, 
                family_size, ap, sizeof(ap), 0,0, NI_NUMERICHOST); //NI_NUMERICHOST not identified but works
            printf("\t%s\n", ap);
        }
        address = address->ifa_next;
    }

    freeifaddrs(addresses);
    return 0;

}