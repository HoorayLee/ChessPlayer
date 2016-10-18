
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

struct node{
    int depth, raid, value;
    string nowplay;
    vector<vector<int> > broadstate;
    vector<vector<int> > avaliable;
    
    node(): value(0), nowplay(""), broadstate(), avaliable(){}
    node(int d, string n, vector<vector<int> > b, vector<vector<int> > a): depth(d), nowplay(n), broadstate(b), avaliable(a){}
};

class Player{
private:
    int raid = 0;
    int prevr = 0;
    string youplay;

    
    
public:
    vector<vector<int> > cellvalue;
    void output(int N, string youplay, int x, int y, vector<vector<int> > tmp){
        ofstream ofile;
        string filepath = "/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/output.txt";
        ofile.open(filepath,ios::trunc);
        char move1 = char(x + 65);
        if(raid == 1){
            ofile << move1 << y + 1 <<" ";
            ofile << "Raid" <<endl;
            raid = 0;
        }
        else{
            ofile << move1 << y + 1 <<" ";
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
    
    int Ocalculate(int N, vector<vector<int> > cellvalue, vector<vector<int> > broadstate){
        int value = 0;
        int i = 0, k = 0;
        for (i = 0; i < N; i++) {
            for (k = 0; k < N ; k++) {
                if (broadstate[i][k] == 1) {
                    value += cellvalue[i][k];
                }
                else if(broadstate[i][k] == -1){
                    value -= cellvalue[i][k];
                }
//                if(k < N){
//                    value = broadstate[i][k] == 1 ? value + cellvalue[i][k] : value + cellvalue[i][k] * broadstate[i][k];
//                    
//                }
//                
//                if(k + 1 < N){
//                    value = broadstate[i][k + 1] == 1 ? value + cellvalue[i][k + 1] : value + cellvalue[i][k + 1] * broadstate[i][k + 1];
//                }
            }
        }
        return value;
    }
    
    
    vector<vector<int> > checkraid(string uplay, int x, int y, vector<vector<int> > ori){
        raid = 0;
        vector<vector<int> >  b = ori;
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
    void checkraid(string uplay, int x, int y, node *n){
        raid = 0;
        vector<vector<int> > b = n -> broadstate;
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
                    n -> value += cellvalue[x - 1][y];
                    n -> raid = 1;
                }
                if (r == -1){
                    b[x + 1][y] = 1;
                    n -> value += cellvalue[x + 1][y];
                    n -> raid = 1;
                }
                if (u == -1){
                    b[x][y + 1] = 1;
                    n -> value += cellvalue[x][y + 1];
                    n -> raid = 1;
                }
                if (d == -1){
                    b[x][y - 1] = 1;
                    n -> value += cellvalue[x][y - 1];
                    n -> raid = 1;
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
                    n -> value -= cellvalue[x - 1][y];
                    n -> raid = 1;
                }
                if (r == 1){
                    b[x + 1][y] = -1;
                    n -> value -= cellvalue[x + 1][y];
                    n -> raid = 1;
                }
                if (u == 1){
                    b[x][y + 1] = -1;
                    n -> value -= cellvalue[x][y + 1];
                    n -> raid = 1;
                }
                if (d == 1){
                    b[x][y - 1] = -1;
                    n -> value -= cellvalue[x][y - 1];
                    n -> raid = 1;
                }
            }
        }
    }

    
    int Minimax(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int> > cellvalue, vector<vector<int> > broadstate,vector<vector<int> > avaliable){
        raid = 0;
        vector<vector<int> > tmp, tmp1, ava;
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
                tmp1 = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(youplay, y, x, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                tmp1[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result, result1;
                if(tmp != tmp1){
                    result = Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
                    result1 = Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp1, ava);
                    if(result == result1){
                        tmp = tmp1;
                    }
                }
                else{
                    result = Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
                }
   
                if (a < result) {
                    a = result;

                    if(depth == oridepth){
                        if(tmp == tmp1){
                            output(N, nowplay, x, y, tmp);
                        }
                        else{
                            tmp = checkraid(youplay, y, x, broadstate);
                            tmp[y][x] = nowplay == "O" ? 1 : -1;
                            prevr++;
                            output(N, nowplay, x, y, tmp);
                        }
                        
                        
                    }
                }
                else if(a == result){
   
                    if(raid == 0 && prevr > 0 && depth == oridepth){
                        output(N, nowplay, x, y, tmp);
                        prevr = 0;
                        
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
                tmp = checkraid(nowplay, y, x, broadstate);
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
//    int Alphabeta(node *root, string youplay, int oridepth, int alpha, int beta){
//        raid = 0;
//        int bv;
//        vector<vector<int> > tmp, tmp1, ava;
//        if (root -> depth == 0 || root -> avaliable.size() == 0) {
//            return (youplay == "O" ?  root -> value : -root -> value);
//        }
//        //node *n = new node();
//        if(root -> nowplay == youplay){
//            alpha = -99999;
//            string otherplay = youplay == "O" ? "X" : "O";
//            for (int i = 0; i < root -> avaliable.size(); i++) {
//                
//                tmp = root -> broadstate;
//                tmp1 = root -> broadstate;
//                ava = root -> avaliable;
//                int x = root -> avaliable[i][0];
//                int y = root -> avaliable[i][1];
//                tmp = checkraid(youplay, y, x, tmp);
//                tmp[y][x] = root -> nowplay == "O" ? 1 : -1;
//                tmp1[y][x] = root -> nowplay == "O" ? 1 : -1;
//                ava.erase(ava.begin() + i);
//                node *n = new node();
//                n -> value = root -> value;
//                n -> depth = root -> depth - 1;
//                n -> nowplay = youplay;
//                n -> broadstate = root -> broadstate;
//                n -> avaliable = ava;
//                checkraid(youplay, y, x, n);
//                n -> broadstate = tmp;
//                n -> value = youplay == "O" ? n->value + cellvalue[y][x] : n->value - cellvalue[y][x];
//                n -> nowplay = otherplay;
//                int result, result1;
//                result = Alphabeta(n, youplay, oridepth, alpha, beta);
//
//                if (alpha < result) {
//                    alpha = result;
//                    bv = alpha;
//         
//                    if(root -> depth == oridepth){
//
//                            tmp = checkraid(youplay, y, x, root -> broadstate);
//                            tmp[y][x] = root -> nowplay == "O" ? 1 : -1;
//                            prevr ++;
//                            output(root -> broadstate.size(), root -> nowplay, x, y, tmp);
//
//                    }
//                }
//                else if(alpha == result){
//      
//                    if(n->raid == 0 && prevr > 0 && root -> depth == oridepth){
//                        output(root -> broadstate.size(), root -> nowplay, x, y, tmp);
//                        prevr = 0;
//                    }
//                }
//
//                if(beta <= alpha){
//
//                    break;
//                }
//            }
//            
//        }
//        else if(root -> nowplay != youplay){
//            beta = 99999;
//            
//            for (int i = 0; i < root -> avaliable.size(); i++) {
//                
//                tmp = root -> broadstate;
//                ava = root -> avaliable;
//                int x = root -> avaliable[i][0];
//                int y = root -> avaliable[i][1];
//                tmp = checkraid(root -> nowplay, y, x, root -> broadstate);
//                tmp[y][x] = root -> nowplay == "O" ? 1 : -1;
//                ava.erase(ava.begin() + i);
//                
//                node *n = new node();
//                n -> value = root -> value;
//                n -> nowplay = root -> nowplay;
//                n -> depth = root -> depth - 1;
//                n -> broadstate = root -> broadstate;
//                n -> avaliable = ava;
//                checkraid(root -> nowplay, y, x, n);
//                n -> broadstate = tmp;
//                n -> value = n->nowplay == "O" ? n->value + cellvalue[y][x] : n->value - cellvalue[y][x];
//                n -> nowplay = youplay;
//                int result = Alphabeta(n,youplay,oridepth ,alpha,beta);
//                if (beta > result) {
//                    beta = result;
//                    bv = beta;
//                }
//                
//                if(beta <= alpha){
//                    //delete root;
//                    break;
//                }
//            }
//        }
//        return bv;
//    }
    int Alphabeta(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int> > cellvalue, vector<vector<int> > broadstate,vector<vector<int> > avaliable, int alpha, int beta){
        raid = 0;
        int bv;

        vector<vector<int> > tmp, tmp1, ava;
        if (depth == 0 || avaliable.size() == 0) {
            int Ovalue = Ocalculate(N, cellvalue, broadstate);
            return (youplay == "O" ?  Ovalue : -Ovalue);
        }
        if(nowplay == youplay){
            alpha = -99999;
            string otherplay = youplay == "O" ? "X" : "O";
            for (int i = 0; i < avaliable.size(); i++) {
                tmp = broadstate;
                tmp1 = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(youplay, y, x, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                tmp1[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result, result1;
                if(tmp != tmp1){
                    result = Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava,alpha,beta);
                    result1 = Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp1, ava,alpha,beta);
                    if(result == result1){
                        tmp = tmp1;
                    }
                }
                else{
                    result = Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava,alpha,beta);

                }
                if (alpha < result) {
                    alpha = result;
                    bv = alpha;

                    if(depth == oridepth){
                        if(tmp == tmp1){
                            output(N, nowplay, x, y, tmp);
                        }
                        else{
                            tmp = checkraid(youplay, y, x, broadstate);
                            tmp[y][x] = nowplay == "O" ? 1 : -1;
                            prevr++;
                            output(N, nowplay, x, y, tmp);
                        }
                    }
                }
                else if(alpha == result){

                    if(raid == 0 && prevr > 0 && depth == oridepth){
                        output(N, nowplay, x, y, tmp);
                        prevr = 0;
                    }
                }
                
                if(beta <= alpha){
                    break;
                }
            }
            
        }
        else if(nowplay != youplay){
            beta = 99999;
            for (int i = 0; i < avaliable.size(); i++) {
                tmp = broadstate;
                ava = avaliable;
                int x = avaliable[i][0];
                int y = avaliable[i][1];
                tmp = checkraid(nowplay, y, x, broadstate);
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
    
};