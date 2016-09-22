//
//  main.cpp
//  file_read_write
//
//  Created by KevinLiu on 16/9/21.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //ifstream fin("mydata.txt");
    //if(fin.fail())
   // {
     //   cout <<"error in open file."<< endl;
     //   exit(1);
    //}
    
    ifstream fin("mydata.txt");
    ofstream fout("checkdata.txt");
    
    //check for possible error
    if(fin.fail())
    {cerr << "could not open input file mydata.txt." << endl;
        exit(1);
    }

    if(fout.fail())
    {
        cerr << "could not open output file checkdata.txt." << endl;
        exit(1);
    }

    //all files are open
    double t, motion;
    int count(0);
    fin >> t >> motion;
    while(!fin.eof())
    {
        ++count;
        
        if(t >= 0 && motion >=0)
        {
            fout << t << " " << motion <<endl;
        }
        else
        {
            cerr << "Bad data pair on line" << count <<endl << t << " " << motion << endl;
        }
        fin >> t >> motion;
    }
    
    fin.close();
    fout.close();
    return 0;
}
