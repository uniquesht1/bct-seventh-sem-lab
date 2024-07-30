#include <stdio.h>
#include <conio.h>
#include <direct.h>
#include <time.h>

void main()
{
    int cs = 0, pro = 0;
    double run = 5;
    char key = 'a';
    time_t t1, t2;
    printf("Press a key(except q) to enter a process into critical section.\n");
    printf("Press q at any time to exit.\n");
    t1 = time(NULL) - 5;
    while (key != 'q')
    {
        while (!kbhit())
            if (cs != 0)
            {
                t2 = time(NULL);
                if (t2 - t1 > run)
                {
                    printf("\nProcess %d exits critical section.", pro - 1);
                    cs = 0;
                }
            }
        key = getch();
        if (key != 'q')
        {
            if (cs != 0)
            {
                printf("\n\nError: Another process is currently executing critical section Please wait till its execution is over\n");
            }
            else
            {
                printf("\nProcess %d enters critical section.", pro);
                pro++;
                cs = 1;
                t1 = time(NULL);
            }
        }
    }
}