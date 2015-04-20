#include <QCoreApplication>
#include <QDir>
#include <QDebug>
#include <QString>
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

class newfilename   //to store the seperated filename and path that read from file
{
private:
    string ID;
    string performer;
    string songtitle;
    string duration;
    string path;
public:
    void setID(string x){ID=x;}
    void setperformer(string y){performer=y;}
    void setsongtitle(string z){songtitle=z;}
    void setduration(string w){duration=w;}
    void setpath(string s){path=s;}
    string getID(){return ID;}
    string getperformer(){return performer;}
    string getsongtitle(){return songtitle;}
    string getduration(){return duration;}
    string getpath(){return path;}
};

void method();
void sort_id(vector<newfilename> &seperate);
void sort_performer(vector<newfilename> &seperate);
void sort_songtitle(vector<newfilename> &seperate);
void sort_duration(vector<newfilename> &seperate);
void deal_filename(vector<string> &FileNamelist,vector<newfilename> &seperate,vector<string> &FullPathlist);


int main(int argc, char *argv[])
{   char choose1,choose2;
    //Every Qt console program has to create a QCoreApplication object.
    QCoreApplication a(argc, argv);

    //To read all files from the following directory
    //To setup a Windows directory you need to use \\ as the folder seperator: C:\\Users\\jjliou\\My Music
    QString path ="C:\\Qt\\Qt5.3.1\\Tools\\QtCreator\\bin\\ee2310\\hw9\\c++song";
    QDir dir(path);

    vector<string> FullPathlist;
    vector<string> FileNamelist;
    vector<newfilename> seperate; //to store the seperated filename in the vector
    //For every item in the directory
    foreach(QFileInfo item, dir.entryInfoList() )
    {
        //If it is a file
        if(item.isFile()) {
            //qDebug() << "Full path: " << item.absoluteFilePath() << " File name: " << item.fileName()<<endl;
            //Push the full path string into a vector; toStdString() is used to convert QString to String
            FullPathlist.push_back(item.absoluteFilePath().toStdString()); \
            //Push the file name string into a vector
            FileNamelist.push_back(item.fileName().toStdString());
        }
    }
    cout << "All regular files:" << endl<<endl;
    for(int i=0; i<FileNamelist.size(); i++){
        cout << FileNamelist[i] << endl;
    }
    deal_filename(FileNamelist,seperate,FullPathlist);  //seperate the filename
    method();  //show the methods to user to choose
    cin>>choose1>>choose2;
    switch(choose2)
    {
    case 'a': sort_id(seperate); break;
    case 'b': sort_performer(seperate); break;
    case 'c': sort_songtitle(seperate); break;
    case 'd': sort_duration(seperate); break;
    }
    switch(choose1)
    {
    case 'a': sort_id(seperate); break;
    case 'b': sort_performer(seperate); break;
    case 'c': sort_songtitle(seperate); break;
    case 'd': sort_duration(seperate); break;
    }

    ofstream output_file;
    output_file.open("playlist.html");

    //Output the html header
    output_file << "<!DOCTYPE html>\n<html>\n<body>\n\n<table>";

    for(int i=0;i<seperate.size();i++)
    {
        //Output the audio control tag for the first file
        output_file << "<tr><td><audio controls>\n<source src=\"";
        output_file << seperate[i].getpath();
        output_file << "\" type=\"audio/mpeg\">\n";

        output_file << "</audio></td>\n";

        //Output the file name
        output_file << "<td>" <<seperate[i].getID() << "</td><td>"<<seperate[i].getperformer() << "</td><td>"<<seperate[i].getsongtitle() << "</td><td>"<<seperate[i].getduration()<<"</td>";
        output_file << "</tr>";
        output_file << endl;
    }
    //Output the html end
    output_file << "</table></body>\n</html>\n";

    return 0;
}
void method()
{   cout<<endl<<"choose the method you want to sort"<<endl;
    cout<<"a.based on Track ID "<<endl;
    cout<<"b.based on performer"<<endl;
    cout<<"c.based on song title"<<endl;
    cout<<"d.based on duration "<<endl;
}
void deal_filename(vector<string> &FileNamelist,vector<newfilename> &seperate,vector<string> &FullPathlist)
{   size_t lastpos,pos;
    string ID,performer,songtitle,duration,file;
    newfilename buffer;
    for(int i=0;i<FileNamelist.size();i++)
    {
        lastpos=FileNamelist[i].find_first_not_of("-",0);   //seperate the ID in the filename by storing it in a string variable
        pos=FileNamelist[i].find_first_of("-",lastpos);
        ID=FileNamelist[i].substr(lastpos,pos-lastpos);
        buffer.setID(ID);

        lastpos=FileNamelist[i].find_first_not_of("-",pos);  //seperate the performer in the filename by storing it in a string variable
        pos=FileNamelist[i].find_first_of("-",lastpos);
        performer=FileNamelist[i].substr(lastpos,pos-lastpos);
        buffer.setperformer(performer);

        lastpos=FileNamelist[i].find_first_not_of("-",pos);  //seperate the songtitle in the filename by storing it in a string variable
        pos=FileNamelist[i].find_first_of("-",lastpos);
        songtitle=FileNamelist[i].substr(lastpos,pos-lastpos);
        buffer.setsongtitle(songtitle);

        lastpos=FileNamelist[i].find_first_not_of("-",pos);  //seperate the duration in the filename by storing it in a string variable
        pos=FileNamelist[i].find_first_of(".",lastpos);
        duration=FileNamelist[i].substr(lastpos,pos-lastpos);
        buffer.setduration(duration);

        lastpos=FileNamelist[i].find_first_not_of(".",pos);  //check if there are other types of file is in the same directory
        pos=FileNamelist[i].find_first_of("-",lastpos);
        file=FileNamelist[i].substr(lastpos,pos-lastpos);
        if(file!="mp3") //if the file is not mp3,then execute the next for loop
        {
            continue;
        }
        buffer.setpath(FullPathlist[i]);
        seperate.push_back(buffer);
    }
}

void sort_id(vector<newfilename> &seperate)      //use selection sort to sort the ID
{
    unsigned int startScan, minIndex;
    newfilename minValue;
    for (startScan=0; startScan<seperate.size()-1; startScan++) {
        minIndex = startScan;
        minValue = seperate[startScan];
        for (unsigned int index=startScan+1; index<seperate.size(); index++) {
            if (seperate[index].getID() < minValue.getID()) {
                minValue = seperate[index];
                minIndex = index;
            }
        }
        seperate[minIndex]  = seperate[startScan];
        seperate[startScan] = minValue;
    }
}
void sort_performer(vector<newfilename> &seperate) //use selection sort to sort the performer
{
    unsigned int startScan, minIndex;
    newfilename minValue;
    for (startScan=0; startScan<seperate.size()-1; startScan++) {
        minIndex = startScan;
        minValue = seperate[startScan];
        for (unsigned int index=startScan+1; index<seperate.size(); index++) {
            if (seperate[index].getperformer() < minValue.getperformer()) {
                minValue = seperate[index];
                minIndex = index;
            }
        }
        seperate[minIndex]  = seperate[startScan];
        seperate[startScan] = minValue;
    }
}
void sort_songtitle(vector<newfilename> &seperate) //use selection sort to sort the songtitle
{
    unsigned int startScan, minIndex;
    newfilename minValue;
    for (startScan=0; startScan<seperate.size()-1; startScan++) {
        minIndex = startScan;
        minValue = seperate[startScan];
        for (unsigned int index=startScan+1; index<seperate.size(); index++) {
            if (seperate[index].getsongtitle() < minValue.getsongtitle()) {
                minValue = seperate[index];
                minIndex = index;
            }
        }
        seperate[minIndex]  = seperate[startScan];
        seperate[startScan] = minValue;
    }
}
void sort_duration(vector<newfilename> &seperate) //use selection sort to sort the duration
{
    unsigned int startScan, minIndex;
    newfilename minValue;
    for (startScan=0; startScan<seperate.size()-1; startScan++) {
        minIndex = startScan;
        minValue = seperate[startScan];
        for (unsigned int index=startScan+1; index<seperate.size(); index++) {
            if (seperate[index].getduration() < minValue.getduration()) {
                minValue = seperate[index];
                minIndex = index;
            }
        }
        seperate[minIndex]  = seperate[startScan];
        seperate[startScan] = minValue;
    }
}
