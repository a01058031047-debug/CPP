bool operator==(const TimeHMS& t) 
{
    return hour==t.hour &&
           min==t.min &&
           sec==t.sec;
}

bool operator!=(const TimeHMS& t) 
{
    return !(*this == t);
}