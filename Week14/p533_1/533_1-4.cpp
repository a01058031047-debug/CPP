TimeHMS& operator++() 
{
    hour++;
    return *this;
}

TimeHMS& operator--() 
{
    hour--;
    return *this;
}