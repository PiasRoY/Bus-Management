
struct NAME {
    char fname[20];
    char lname[20];
};

struct ADDRESS {
    char Praddress[50];
    char Peaddress[50];
};

struct Contacts {
    unsigned long long number;
    unsigned long long Alnumber;
    char Email[100];
};

struct RouteCode {
    int RC;
};

struct Seat {
    int NumeberOfSeats;
    char SeatPlans[80];
};

struct CostNTime {
    int Cost[40] = {400, 550, 480, 1000, 400, 550, 480, 1000, 400, 550, 480, 1000, 400, 550, 480, 1000,
                    400, 550, 480, 1000, 400, 550, 480, 1000, 400, 550, 480, 1000, 400, 550, 480, 1000};
    typedef struct str {
        char time[10];
    } string;
    string Time[40] = {{"8:00AM"}, {"8:30AM"}, {"9:00AM"}, {"9:30AM"}, {"10:00AM"}, {"10:30AM"}, {"11:00AM"}, {"11:30AM"}
                       ,{"8:00PM"}, {"8:30PM"}, {"9:00PM"}, {"9:30PM"}, {"10:00PM"}, {"10:30PM"}, {"11:00PM"}, {"11:30PM"},
                       {"8:00AM"}, {"8:30AM"}, {"9:00AM"}, {"9:30AM"}, {"10:00AM"}, {"10:30AM"}, {"11:00AM"}, {"11:30AM"}
                       ,{"8:00PM"}, {"8:30PM"}, {"9:00PM"}, {"9:30PM"}, {"10:00PM"}, {"10:30PM"}, {"11:00PM"}, {"11:30PM"}};
};

struct info {
    struct NAME name;
    struct ADDRESS address;
    struct Contacts contacts;
    struct RouteCode routecode;
    struct Seat seat;
    struct CostNTime costntime;
};

