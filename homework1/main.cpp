#include <iostream>
#include <string>
using namespace std;


int main()
{   string name,date,date1,date2,date3;

    double base,local,inter,tax,total;

    cin >> date;
    getline(cin,date);
    cin >> name;
    cin >> date1 >> date2;


    cin >> base >> local >> inter;
    cin >> date3;

    tax=(base+local+inter)*0.09;

           total=(base+local+inter+tax);
           cout<<date<<endl;
           cout<<"Dear  "<< name <<"  costumer"<<endl;
           cout<<"The following is this month's billing deatils"<<endl;
           cout<<"Bill cycle:from  "<<date1<<"  to "<<date2<<endl;
           cout<<"Base plan......................:"<<base<<endl;
           cout<<"Local calls....................:"<<local<<endl;
           cout<<"International calls:............"<<inter<<endl;
           cout<<"Tax:............................"<<tax<<endl;
           cout<<"Total:.........................."<<total<<endl;
           cout<<"Please pay the above total by:"<<date3<<endl;
           cout <<"Billing department";






                 return 0;
             }

