operator double() 
{
    return hour + min/60.0 + sec/3600.0;
}