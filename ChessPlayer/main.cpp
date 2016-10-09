//
//  main.cpp
//  ChessPlayer
//
//  Created by 洪锐 李 on 2016/10/4.
//  Copyright © 2016年 洪锐 李. All rights reserved.
//

#include <iostream>
#include "Header.h"
#include "String2Int.cpp"
#include "CS561.cpp"
#include <fstream>
using namespace std;

int main(int argc, const char * argv[]) {
    char buffer[5];
    vector<int> cellvalue;
    vector<int> cellstate;
    vector<vector<int>> Overallvalue;
    vector<vector<int>> Boardstate;
    vector<vector<int>> avaliable;
    string youplay;
    string value;
    string mode, d;
    int N, depth, V;
   
    int i = 0;
    ifstream iinfo;
    
    string2int toint = *new string2int();
    Player play = *new Player();
    iinfo.open("/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/input.txt");
    if (! iinfo.is_open())
    { cout << "Error opening file"; exit (1); }
    
    iinfo.getline(buffer,3);
    N = toint.Toint(buffer);
    
    //////////////////////////////////////////////////////////
    //           Read all the requirements  <Head>          //
    //////////////////////////////////////////////////////////
    
    while (!iinfo.eof()) {
        char a = iinfo.get();
        if (a == '\n') {
            break;
        }
        else{
            mode.push_back(a);
        }
    }
    while (!iinfo.eof()) {
        char a = iinfo.get();
        if (a == '\n') {
            break;
        }
        else{
            youplay.push_back(a);
        }
    }
    while (!iinfo.eof()) {
        char a = iinfo.get();
        if (a == '\n') {
            break;
        }
        else{
            
            d.push_back(a);
        }
        
    }
    depth = toint.Toint(d);
    
    //////////////////////////////////////////////////////////
    //            Read all the requirements         <End>   //
    //////////////////////////////////////////////////////////
    
    
    //////////////////////////////////////////////////////////
    //              Read the cell value  <Head>             //
    //////////////////////////////////////////////////////////
    while (!iinfo.eof() && i != N)
    {
        
        char a = iinfo.get();
        if(a != ' ' && a != '\n'){
            value.push_back(a);
        }
        
        else if (a == '\n') {
            if (value.size() ) {
                V = toint.Toint(value);
                cellvalue.push_back(V);
                value.clear();
                Overallvalue.push_back(cellvalue);
                cellvalue.clear();
            }
                i++;
        }
        else if (a == ' '){
            if (value.size() ) {
                V = toint.Toint(value);
                cellvalue.push_back(V);
                value.clear();
            }
            else{
                { cout << "Error input data"; exit (1); }
            }
            
        }
        
    }
    
    //////////////////////////////////////////////////////////
    //               Read the cell value        <End>       //
    //////////////////////////////////////////////////////////
    int x = 0,y = 0;
    i = 0;
    //////////////////////////////////////////////////////////
    //              Read the borad state <Head>             //
    //////////////////////////////////////////////////////////
    while (!iinfo.eof() && i != N)
    {
        
        char a = iinfo.get();
        if(a != '\n'){
            if(a == 'X'){
                cellstate.push_back(-1);
            }
            else if (a == 'O'){
                cellstate.push_back(1);
            }
            else{
                cellstate.push_back(0);
                cellvalue.push_back(x);
                cellvalue.push_back(y);
                avaliable.push_back(cellvalue);
                cellvalue.clear();
            }
            x++;

        }
        
        else if (a == '\n') {
            Boardstate.push_back(cellstate);
            cellstate.clear();
            x = 0;
            y++;
            i++;
        }
    }
    
    //////////////////////////////////////////////////////////
    //               Read the borad state       <End>       //
    //////////////////////////////////////////////////////////
    iinfo.close();
    if (mode[0] == 'M') {
        cout << "result for Minimax:" << endl;
        cout << "Play as " << youplay << endl;
        int k = play.Minimax(N, youplay, youplay, depth, depth, Overallvalue, Boardstate, avaliable);
        cout << k;
    }
    else if(mode[0] == 'A'){
        cout << "result for Alpha-Beta:" << endl;
        cout << "Play as " << youplay << endl;

    }
    else if (mode[0] == 'C'){
        cout << "result for Competition:" << endl;
        cout << "Play as " << youplay << endl;
    }
   
    return 0;
}
