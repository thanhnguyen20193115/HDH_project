/******************************************************************************
*  @brief      Userspace application to test the Device driver
*
*  @author     nhatlv p.linuxfromscratch@gmail.com
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio_ext.h>
#include<sys/ioctl.h>
#include <time.h>
#include <errno.h>
#include <assert.h>

#define LED_ON      _IOW('a','1',int32_t*)
#define LED_OFF     _IOR('a','0',int32_t*)

#define CDEV_PATH "/dev/m_device"

int fd, option;
int number, foo;
char write_buf[1024];
char read_buf[1024];

/*void printMenu()
{

    printf("**** Please Enter the Option *****\n");
    printf("        1.  LED on                \n");
    printf("        0.  LED off               \n");
    printf("        99. Exit                  \n");
    printf("**********************************\n");
    printf(">>> ");
}
*/
int main()
{   
    printf("*********************************\n");
    printf("******* Linux From Scratch *******\n\n");

    fd = open(CDEV_PATH, O_RDWR);
    if (fd < 0) {
        printf("Cannot open device file: %s...\n", CDEV_PATH);
        return -1;
    }
          	FILE* fp = fopen("data1.csv", "a");
            time_t start, end;
            time_t run_time;
            start = time(NULL);
            printf("the first clock value is %d\n",start); 
            ioctl(fd, LED_ON, NULL);
            delay(10000);
            ioctl(fd, LED_OFF, NULL);
            // sleep(1000);
             end = time(NULL);
             printf("the second clock value is %d\n",end);
             printf("Thoi gian LED sang la : %d\n",end - start);
             fprintf(fp,"%d\n",end - start);
            //getchar();
        close(fd);
        return 0;
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
/* my output
the first clock value is 0
the second clock value is 15
*/
   /*while(1) {
        printMenu();
        
        scanf("%d",&option); 
        switch (option) {
            case 1:
                printf("Turn LED on\n");
                ioctl(fd, LED_ON, NULL);
                printf("Done!\n\n\n");
                break;

            case 0:
                printf("Turn LED off\n");
                ioctl(fd, LED_OFF, NULL);
                printf("Done!\n\n\n");
                break;

            case 99:
                close(fd);
                exit(1);               
                break;
            default:
                printf("Enter invalid option: %c\n", option);
                break;
        }
    }
    */
