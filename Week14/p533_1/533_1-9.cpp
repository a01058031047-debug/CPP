friend TimeHMS operator*(int n, const TimeHMS& t)
{
    int total =
        n * (t.hour*3600 + t.min*60 + t.sec);

    return TimeHMS(total/3600,
                   (total%3600)/60,
                   total%60);
}