#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h> 

using namespace std;

int main(int argc,char *argv[])
{
    char *readStream = new char[1];
    int bytes_read=0;
    
    bool inProgram = true;
    
    while(inProgram){
        
        int readFD[3];

        readFD[0] =  open("./Files/X.txt",O_RDONLY);
        readFD[1] =  open("./Files/Y.txt",O_RDONLY);
        readFD[2] =  open("./Files/Z.txt",O_RDONLY);

            // 3 File Des -> Rd Permissions
            // Code Size Can be reduced with a loop
        cout<<"The Values in Files X Y and Z are respectively: "<<endl;
        for(int i=0;i<3;i++)
        {
           if(readFD[i]>-1)
           {
               bytes_read = read(readFD[i],readStream,sizeof(char));
               if(bytes_read)
                  cout<<readStream<< " ";
           }
           else
            cout<<"_ ";
        }
        cout << endl << "-----------------------------------------------"<<endl;

        close(readFD[0]);
        close(readFD[1]);
        close(readFD[2]);

        //  Special User with admin Rights..!

        int writeFD[3];
        char *writeStream=new char[1];


        writeFD[0] =  open("./Files/X.txt",O_WRONLY);
        writeFD[1] =  open("./Files/Y.txt",O_WRONLY);
        writeFD[2] =  open("./Files/Z.txt",O_WRONLY);

        bool access= (writeFD[0]>-1 || writeFD[1]>-1 || writeFD[2]>-1);

        // 3 File Des -> Rd Permissions
        // 3 File Des -> Write Mode-> 

        if(access)
        {
            for(int i=0;i<3;i++)
            {
                if(writeFD[i]>-1)
                    cout<< "Enter "<<i+1<< " to Change Value of file "<<i+1<<endl;
            }
            cout<<"Enter 4 to Exit The Program"<<endl;
            cout << endl;
            // Show Options For editing  
            int option;
            cin>> option; 
            cin.ignore();  
            if(option==1 || option==2 || option==3)
            {
                cout<<"Enter Value To Replace in the file: ";
                cin>>writeStream;  
                cout<<writeStream<<endl;
                lseek(writeFD[option-1],0,SEEK_SET);
                write(writeFD[option-1],writeStream,sizeof(char));
            }
            else if(option==4)
            {
                inProgram = false;
            }
            else
            {
                cout<<"Please Enter A Valid Option"<<endl;
            }
            cout<<endl;
        }
        else{
            close(writeFD[0]);
            close(writeFD[1]);
            close(writeFD[2]);
            break;
        }
        close(writeFD[0]);
        close(writeFD[1]);
        close(writeFD[2]);
        
        cout << endl << "-----------------------------------------------"<<endl;
        
    }
}
