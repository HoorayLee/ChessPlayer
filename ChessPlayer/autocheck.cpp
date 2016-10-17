//
//  main.cpp
//  Autocheck
//
//  Created by 洪锐 李 on 10/16/16.
//  Copyright © 2016 洪锐 李. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    string path = "/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/total_output.txt";
    string path1 = "/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/total_output1.txt";
    
    fstream instream1, instream2;
    instream1.open(path);
    instream2.open(path1);
    int flag = 0;
    int i = 0;
    while(!instream1.eof()){
        char a = instream1.get();
        char b = instream2.get();
        if(a != b){
            flag = 1;
            while (a != '-' || b != '-') {
                if(a != '-'){
                    a = instream1.get();
                }
                
                if(b != '-'){
                    b = instream2.get();

                }
            }
        }
        
        if(a == '-' && flag != 0){
            flag = 0;
            
            cout << i << endl;
            i++;
        }
        else if(a== '-'){
            i++;
        }
    }
    getchar();
    return 0;
}
