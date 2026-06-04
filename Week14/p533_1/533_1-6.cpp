int& operator[](int index)
{
    if(index==0) return hour;
    if(index==1) return min;
    return sec;
}