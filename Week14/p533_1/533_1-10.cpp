
// 입력

friend istream& operator>>(istream& in,
                           TimeHMS& t)
                           {
    in >> t.hour >> t.min >> t.sec;
    return in;
}

// 출력

friend ostream& operator<<(ostream& out,
                           const TimeHMS& t)
{
    out << t.hour << "h "
        << t.min << "m "
        << t.sec << "s";

    return out;
}