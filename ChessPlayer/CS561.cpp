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

//struct node{
//    int depth;
//    string nowplay;
//    vector<vector<int>> broadstate;
//    vector<vector<int>> avaliable;
//    node *next;
//    node *silibing;
//    
//    node(): nowplay(""), broadstate(NULL), avaliable(NULL){}
//    node(int d, string n, vector<vector<int>> b, vector<vector<int>> a): depth(d), nowplay(n), broadstate(b), avaliable(a){}
//};

class Player{
private:
    int raid = 0;
    int self = 0;
    string youplay;
    vector<int> move;
    vector<vector<int>> broadstate;
    vector<vector<int>> cellvalue;
    
public:
    void output(int N, string youplay, int x, int y, vector<vector<int>> tmp){
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
    
//    void preprocess(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int>> cellvalue, vector<vector<int>> broadstate,vector<vector<int>> avaliable){
//        this -> cellvalue = cellvalue;
//        this -> broadstate = broadstate;
//        this -> youplay = youplay;
//        node *root = new node(depth, nowplay, broadstate, avaliable);
//        AlphaBeta(N, root, depth, -99999, 99999);
//        
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
    
    int Minimax(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int>> cellvalue, vector<vector<int>> broadstate,vector<vector<int>> avaliable){
        raid = 0;
        this->broadstate = broadstate;
        vector<vector<int>> tmp, ava;
        int a;
        if (depth == 0 || avaliable.size() == 0) {
            int Ovalue = Ocalculate(N, cellvalue, broadstate);
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
                int result = Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
                if (a < result) {
                    a = result;
                    move.clear();
                    move.push_back(x);
                    move.push_back(y);
                    if(depth == oridepth){
                        output(N, nowplay, x, y, tmp);

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
                int result = Minimax(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
                if (a > result) {
                    a = result;
                }
            }
        }
        return a;
    }
    int Alphabeta(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int>> cellvalue, vector<vector<int>> broadstate,vector<vector<int>> avaliable, int alpha, int beta){
        raid = 0;
        int bv;
        this->broadstate = broadstate;
        vector<vector<int>> tmp, ava;
        if (depth == 0 || avaliable.size() == 0) {
            int Ovalue = Ocalculate(N, cellvalue, broadstate);
            return (youplay == "O" ?  Ovalue : -Ovalue);
        }
        if(nowplay == youplay){
            alpha = -99999;
            string otherplay = youplay == "O" ? "X" : "O";
            for (int i = 0; i < avaliable.size(); i++) {
                tmp = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(youplay, x, y, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result = Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava,alpha,beta);
                if (alpha < result) {
                    alpha = result;
                    bv = alpha;
                    move.clear();
                    move.push_back(x);
                    move.push_back(y);
                    if(depth == oridepth){
                        output(N, nowplay, x, y, tmp);
                        
                    }
                }
                if(beta <= alpha){
                    break;
                }
            }
            
            return alpha;
        }
        else if(nowplay != youplay){
            beta = 99999;
            for (int i = 0; i < avaliable.size(); i++) {
                tmp = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(nowplay, x, y, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result = Alphabeta(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava,alpha,beta);
                if (beta > result) {
                    beta = result;
                    bv = beta;
                }
                
                if(beta <= alpha){
                    break;
                }
            }
        }
        return bv;
    }

//    int AlphaBeta(int N, node *n, int depth, int alpha, int beta){
//        raid = 0;
//        vector<vector<int>> tmp, ava;
//
//        if (depth == 0 || n -> avaliable.size() == 0) {
//            int Ovalue = Ocalculate(N, cellvalue, broadstate);
//            return (n -> nowplay == "O" ?  Ovalue : -Ovalue);
//        }
//        if(n -> nowplay == youplay){
//            alpha = -99999;
//            string otherplay = youplay == "O" ? "X" : "O";
//            node *next = new node();
//            for (int i = 0; i < n -> avaliable.size(); i++) {
//                
//                tmp = broadstate;
//                ava = n -> avaliable;
//                int x = n -> avaliable[i][0];
//                int y = n -> avaliable[i][1];
//                tmp = checkraid(youplay, x, y, broadstate);
//                tmp[y][x] = n -> nowplay == "O" ? 1 : -1;
//                ava.erase(ava.begin() + i);
//                node *child = new node(n -> depth - 1, otherplay, tmp, ava);
//                child ->silibing = next;
//                next = child;
//                if(i == 0){
//                    n -> next = child;
//                }
//                int result = AlphaBeta(N, child, depth, alpha, beta);
//                if (alpha < result) {
//                    alpha = result;
//                    move.clear();
//                    move.push_back(x);
//                    move.push_back(y);
//                    if(n -> depth == depth){
//                        output(N, n -> nowplay, x, y, tmp);
//                    }
//                }
//                
//                if(beta <= alpha){
//                    break;
//                }
//                
//            }
//            return alpha;
//        }
//        else{
//            beta = 99999;
//            node *next = new node();
//            for (int i = 0; i < n -> avaliable.size(); i++) {
//                tmp = broadstate;
//                ava = n -> avaliable;
//                int x = n -> avaliable[i][0];
//                int y = n -> avaliable[i][1];
//                tmp = checkraid(n -> nowplay, x, y, broadstate);
//                tmp[y][x] = n -> nowplay == "O" ? 1 : -1;
//                ava.erase(ava.begin() + i);
//                node *child = new node(n -> depth - 1, youplay, tmp, ava);
//                child ->silibing = next;
//                next = child;
//                int result = AlphaBeta(N, child, depth, alpha, beta);
//                if (beta > result) {
//                    beta = result;
//                }
//                if(beta <= alpha){
//                    break;
//                }
//            }
//            return beta;
//        }
//        //return a;
//    }
};