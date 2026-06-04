TimeHMS operator++(int) 
{
    TimeHMS temp = *this;

    sec++;

    if(sec >= 60){
        sec = 0;
        min++;
    }

    if(min >= 60){
        min = 0;
        hour++;
    }

    return temp;
}

TimeHMS operator--(int) 
{
    TimeHMS temp = *this;

    sec--;

    if(sec < 0){
        sec = 59;
        min--;
    }

    if(min < 0){
        min = 59;
        hour--;
    }

    return temp;
}