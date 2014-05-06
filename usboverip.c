#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int mode;
    char *bus_id = malloc(20);
    char usb_ip_msg[100] = "sudo usbip bind -b ";
    printf("%s\n", usb_ip_msg);

    printf("Welcome...... Are you hosting(1) or recieving(2)? ");
    scanf("%d", &mode);
    printf("%d\n", mode);
    if (mode == 1) {
        printf("You will be the host of a device\n");
        int forkReturn = fork();
        if (forkReturn < 0) {
            printf("fork error\n");
        } else if (forkReturn == 0) {
            system("sudo usbipd");
        } else {
            int getOut = 0;
            while (mode != 0) {
                printf("What would you like to do? \n");
                printf("(1)Check attached usb devices\n");
                printf("(2)Host usb device\n");
                printf("(0)Exit program ");
                scanf("%d", &mode);
                if (mode == 1) {
                    printf("Here are your attached devices\n");
                    system("sudo usbip list -l");
                } else if (mode == 2) {
                    printf("Which device do you want to bind?\n");
                    scanf("%s", bus_id);
                    strcat(&usb_ip_msg, bus_id);
                    printf("%s\n", usb_ip_msg);
                    system(usb_ip_msg);
                } else if (mode == 0) {
                } else {
                    printf("Please enter a valid option\n");
                }
            }
        }
    } else if (mode == 2) {
        char *ipAddress = malloc(20);
        char usb_ip_client[100] = "sudo usbip list -r ";
        char usb_ip_connect[100] = "sudo usbip attach -h ";
        char theBus[20] = " -b ";
        char *busID = malloc(20);
        printf("You will be connecting to a remote device host\n");
        while (mode != 0) {
            printf("What would you like to do? \n");
            printf("(1)Print devices on a remote host\n");
            printf("(2)Bind a remote host's device\n");
            //printf("(3)Unbind a remote host's device\n");
            printf("(0)Exit program ");
            scanf("%d", &mode);
            if (mode == 1) {
                printf("What is the host's IPv4 address? ");
                scanf("%s", ipAddress);
                strcat(&usb_ip_client, ipAddress);
                printf("%s\n", usb_ip_client);
                system(usb_ip_client);
            } else if (mode == 2) {
                printf("What is the host's IPv4 address? ");
                scanf("%s", ipAddress);
                strcat(&usb_ip_connect, ipAddress);
                printf("Which device to you want to bind to? ");
                scanf("%s", busID);
                strcat(&theBus, busID);
                strcat(&usb_ip_connect, &theBus);
                system(usb_ip_connect);
            //} else if (mode == 3) {

            } else if (mode == 0) {

            } else {
                printf("Please enter a valid option\n");
            }
        }






    }



}

