#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    int a,i = 0;
    string text, old, password1, password2, pass, name, passwaord0, age, user, word, word1;
    string creds[2], cp[2];

    cout <<"     Security System  "<< endl;

    cout <<"______________________________________"<<endl<<endl;
    cout <<"|            1. Register               |"<<endl;
    cout <<"|            2. Login                  |"<<endl;
    cout <<"|            3. Change Password        |"<<endl;
    cout <<"|__________  4. End Program __________ |"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter your choice: ";
        cin>>a;
        switch(a)
        {
            case 1:{
                cout<<"________________________________________"<<endl<<endl;
                cout<<"|-----------------Register -------------|"<<endl;
                cout<<"|_______________________________________|"<<endl<<endl;
                cout<<"Enter user name:-";
                cin>>name;
                cout<<"Enter password:-";
                cin>>passwaord0;
                cout<<"Enter your age:-";
                cin>>age;

                ofstream of1;
                of1.open("file.text");
                if(of1.is_open()){
                    of1<<name<<"\n";
                    of1<<password0;
                    cout<<"registration successful"<<endl;
                }


            break;
            }
            case 2:{
                i=0;

                cout<<"___________________________________"<<endl<<endl;
                cout<<"|----------------Login-------------|"<<endl;
                cout<<"|__________________________________|"<endl<<endl;

                ifstream of2;
                of2.open("file.text";)
                cout<<"Enter user name:-"
                cin>>user;
                cout<<"enter password";
                cin>>pass;

                if(of2.is_open()){
                    while(!of2.eof()){
                            while(getline(of2,text)){//using this get line file will be read line by line
                            istringstream iss(text);
                            iss>>word;
                            creds[i]=word;
                            i++;
                        }

                        if(user==creds[0] && pass==creds[1]){
                            cout<<"----Log in successful-----";
                            cout<<endl<<endl;

                            cout<<" Details: "<<endl;

                            cout<<"User name: "+ name<<endl;
                            cout<<"Password: "+ pass<<endl;
                            cout<<"Age: "+ age<<endl;
                        }
                        else{
                            cout<<endl<<endl;
                            cout<<"incorrect Credentials"<<endl;
                            cout<<"|     1. Press 2 to login           |"<<endl;
                            cout<<"|     2. Press 3 to change paaword  |"<<endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 3:{
            i=0;

            cout<<"------------Change password----------"<<endl;

            ifstream of0;
            of0.open("file.text");
            cout<<"enter old password:-";
            cin>>old;
            if(of0.is_open()){
                while(of0.eof()){
                    while(getline(of0, text)){
                        istringstream iss(text);
                        iss>>word1;// here we store data in word 1
                        cp[1]=wordl;
                        i++;
                    }
                    if(old==cp[1]){
                        of0.close();
                        ofstream of1;
                        if(of1.is_open()){
                            cout<<"enter new password:-";
                            cin>>password1;
                            cout<<"enter your password again:-";
                            cin>>password2;

                            if(password1==password2){
                                of1<<cp[0]<<"\n";
                                of1<<password1;
                                cout<<"Password changed successfully"<<endl;
                            }
                            else{
                                of1<<cp[0]<<"\n";
                                of1<<old;
                                cout<<"Password do not match"<<endl;
                            }
                        }
                    }
                    else{
                        cout<<"enter a valid password"<<endl;
                        break;
                    }
                }
            }
            break;
        }
        case 4:{
            cout<<"___________ Thank You!__________";
            break;
        }
        default:
            cout<<"Enter a valid choice";
    }
}
while(a!=4);
return 0;
}
