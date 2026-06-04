TimeHMS operator-(const TimeHMS& t) {
    int total1 = hour*3600 + min*60 + sec;
    int total2 = t.hour*3600 + t.min*60 + t.sec;

    int diff = total1 - total2;

    return TimeHMS(diff/3600,
                   (diff%3600)/60,
                   diff%60);
}