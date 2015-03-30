#include "threads.h"

threads::threads()
{
    count = 0;
    NUM_SECONDS=1;
    stopped = false;
}

threads::~threads(){}

void threads::run()
{
    stopped = false;
    int time_counter = 0;
    clock_t this_time = clock();
    clock_t last_time = this_time;

    while(!stopped){
        this_time = clock();
        time_counter += (double)(this_time-last_time);
        last_time=this_time;

        if(time_counter > (double)(NUM_SECONDS*CLOCKS_PER_SEC)){
            count++;
            emit send_count_data(count);
            time_counter -= (double)(NUM_SECONDS*CLOCKS_PER_SEC);
        }

    }
}

void threads::stop()
{
    stopped = true;
}

