//
//  CS561.cpp
//  ChessPlayer
//
//  Created by 洪锐 李 on 2016/10/4.
//  Copyright © 2016年 洪锐 李. All rights reserved.
//

#include <stdio.h>
#include <fstream>
#include "Header.h"
using namespace std;
class Player{
public:
    int raid = 0;
    int self = 0;
    vector<int> move;
    //int nextx, nexty;
    int Ocalculate(int N, vector<vector<int>> cellvalue, vector<vector<int>> broadstate){
        int value = 0;
        int i = 0, k = 0;
        for (i = 0; i < N; i++) {
            for (k = 0; k < N; k++) {
                if (broadstate[i][k] == 1) {
                    value += cellvalue[i][k];
                }
                else if(broadstate[i][k] == -1){
                    value -= cellvalue[i][k];
                }
            }
        }
        return value;
    }
//    int Xcalculate(int N, vector<vector<int>> cellvalue, vector<vector<int>> broadstate){
//        int value = 0;
//        int i = 0, k = 0;
//        for (i = 0; i < N; i++) {
//            for (k = 0; k < N; k++) {
//                if (broadstate[i][k] == 1) {
//                    value -= cellvalue[i][k];
//                }
//                else if(broadstate[i][k] == -1){
//                    value += cellvalue[i][k];
//                }
//            }
//        }
//        return value;
//    }
    vector<vector<int>> checkraid(string uplay, int x, int y, vector<vector<int>> b){
        raid = 0;
        int l = -2,
            r = -2,
            u = -2,
            d = -2;
        if(x > 0){
            l = b[x - 1][y];
        }
        if(x < b.size() - 1){
            r = b[x + 1][y];
        }
        if(y < b.size() - 1){
            u = b[x][y + 1];
        }
        if(y > 0){
            d = b[x][y - 1];
        }
        int flag = 0;
        if(uplay == "O"){
            if(l == 1 || r == 1 || u == 1 || d == 1){
                flag = 1;
            }
            if (flag == 1) {
                if (l == -1) {
                    b[x - 1][y] = 1;
                    raid = 1;
                }
                if (r == -1){
                    b[x + 1][y] = 1;
                    raid = 1;
                }
                if (u == -1){
                    b[x][y + 1] = 1;
                    raid = 1;
                }
                if (d == -1){
                    b[x][y - 1] = 1;
                    raid = 1;
                }
            }
        }
        else if(uplay == "X"){
            if(l == -1 || r == -1 || u == -1 || d == -1){
                flag = 1;
            }
            if (flag == 1) {
                if (l == 1) {
                    b[x - 1][y] = -1;
                    raid = 1;
                }
                if (r == 1){
                    b[x + 1][y] = -1;
                    raid = 1;
                }
                if (u == 1){
                    b[x][y + 1] = -1;
                    raid = 1;
                }
                if (d == 1){
                    b[x][y - 1] = -1;
                    raid = 1;
                }
            }
        }
        return b;
    }
    
    int Minimax(int N, string nowplay, string youplay, int depth, vector<vector<int>> cellvalue, vector<vector<int>> broadstate,vector<vector<int>> avaliable){
        raid = 0;
        vector<vector<int>> tmp, ava;
        int a;
        if (depth == 0 || avaliable.size() == 0) {
            int Ovalue = Ocalculate(N, cellvalue, broadstate);
            //int Xvalue = Xcalculate(N, cellvalue, broadstate);
            return (youplay == "O" ?  Ovalue : -Ovalue);
        }
        if(nowplay == youplay){
            a = -99999;
            string otherplay = youplay == "O" ? "X" : "O";
            for (int i = 0; i < avaliable.size(); i++) {
                tmp = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(youplay, x, y, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result = Minimax(N, otherplay, youplay, depth - 1, cellvalue, tmp, ava);
                if (a < result) {
                    a = result;
                    move.clear();
                    move.push_back(x);
                    move.push_back(y);
                    if(depth == 4){
                        ofstream ofile;
                        string filepath = "/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/output.txt";
                        ofile.open(filepath,ios::trunc);
                        checkraid(youplay, x, y, broadstate);
                        char move1 = char(move[0] + 65);
                        if(raid == 1){
                            ofile << move1 << move[1] + 1 <<" ";
                            ofile << "Raid" <<endl;
                            raid = 0;
                        }
                        else{
                            ofile << move1 << move[1] + 1 <<" ";
                            ofile << "Stake" <<endl;
                        }
                        ofile << "depth:"<<depth <<endl;
                        
                        // ofile<< move[0] << move[1] <<endl;
                        for (int i = 0; i < N; i++) {
                            for (int k = 0; k < N; k++) {
                                if (tmp[i][k] == 1) {
                                    ofile << "O";
                                }
                                else if(tmp[i][k] == -1){
                                    ofile << "X";
                                }
                                else if (tmp[i][k] == 0){
                                    ofile << ".";
                                }
                            }
                            ofile<<endl;
                        }
                        ofile.close();

                    }
                }
            }
            
            
        }
        else if(nowplay != youplay){
            a = 99999;
            for (int i = 0; i < avaliable.size(); i++) {
                tmp = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(nowplay, x, y, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result = Minimax(N, youplay, youplay, depth - 1, cellvalue, tmp, ava);
                if (a > result) {
                    a = result;
                }
            }
        }
        return a;
    }
    
    void AlphaBeta(){
        
    }
};