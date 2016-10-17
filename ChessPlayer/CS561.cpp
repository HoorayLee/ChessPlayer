////
////  CS561.cpp
////  ChessPlayer
////
////  Created by 洪锐 李 on 2016/10/4.
////  Copyright © 2016年 洪锐 李. All rights reserved.
////
//
//#include <stdio.h>
//#include <fstream>
//
//#include "Header.h"
//using namespace std;
//
//
//class Player{
//private:
//    int raid = 0;
//  	int prevr = 0;
//    int self = 0;
//    string youplay;
//    vector<int> move;
//    vector<vector<int> > broadstate;
//    vector<vector<int> > cellvalue;
//    
//public:
//    void output(int N, string youplay, int x, int y, vector<vector<int> > tmp){
//        ofstream ofile;
//        string filepath = "/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/output.txt";
//        ofile.open(filepath,ios::trunc);
////        checkraid(youplay, x, y, tmp);
//        char move1 = char(move[0] + 65);
//        if(raid == 1){
//            ofile << move1 << move[1] + 1 <<" ";
//            ofile << "Raid" <<endl;
//            raid = 0;
//        }
//        else{
//            ofile << move1 << move[1] + 1 <<" ";
//            ofile << "Stake" <<endl;
//        }
//        for (int i = 0; i < N; i++) {
//            for (int k = 0; k < N; k++) {
//                if (tmp[i][k] == 1) {
//                    ofile << "O";
//                }
//                else if(tmp[i][k] == -1){
//                    ofile << "X";
//                }
//                else if (tmp[i][k] == 0){
//                    ofile << ".";
//                }
//            }
//            ofile<<endl;
//        }
//        ofile.close();
//    }
//
//    int Ocalculate(int N, vector<vector<int> > cellvalue, vector<vector<int> > broadstate){
//        int value = 0;
//        int i = 0, k = 0;
//        for (i = 0; i < N; i++) {
//            for (k = 0; k < N; k++) {
//                if (broadstate[i][k] == 1) {
//                    value += cellvalue[i][k];
//                }
//                else if(broadstate[i][k] == -1){
//                    value -= cellvalue[i][k];
//                }
//            }
//        }
//        return value;
//    }
//    vector<vector<int> > checkraid(string uplay, int x, int y, vector<vector<int> > b){
//        raid = 0;
//        int l = -2,
//        r = -2,
//        u = -2,
//        d = -2;
//        if(x > 0){
//            l = b[x - 1][y];
//        }
//        if(x < b.size() - 1){
//            r = b[x + 1][y];
//        }
//        if(y < b.size() - 1){
//            u = b[x][y + 1];
//        }
//        if(y > 0){
//            d = b[x][y - 1];
//        }
//        int flag = 0;
//        if(uplay == "O"){
//            if(l == 1 || r == 1 || u == 1 || d == 1){
//                flag = 1;
//            }
//            if (flag == 1) {
//                if (l == -1) {
//                    b[x - 1][y] = 1;
//                    raid = 1;
//                }
//                if (r == -1){
//                    b[x + 1][y] = 1;
//                    raid = 1;
//                }
//                if (u == -1){
//                    b[x][y + 1] = 1;
//                    raid = 1;
//                }
//                if (d == -1){
//                    b[x][y - 1] = 1;
//                    raid = 1;
//                }
//            }
//        }
//        else if(uplay == "X"){
//            if(l == -1 || r == -1 || u == -1 || d == -1){
//                flag = 1;
//            }
//            if (flag == 1) {
//                if (l == 1) {
//                    b[x - 1][y] = -1;
//                    raid = 1;
//                }
//                if (r == 1){
//                    b[x + 1][y] = -1;
//                    raid = 1;
//                }
//                if (u == 1){
//                    b[x][y + 1] = -1;
//                    raid = 1;
//                }
//                if (d == 1){
//                    b[x][y - 1] = -1;
//                    raid = 1;
//                }
//            }
//        }
//        return b;
//    }
//    int checkraid(string uplay, int x, int y, vector<vector<int> > b, int what){
//        raid = 0;
//        int l = -2,
//        r = -2,
//        u = -2,
//        d = -2;
//        if(x > 0){
//            l = b[x - 1][y];
//        }
//        if(x < b.size() - 1){
//            r = b[x + 1][y];
//        }
//        if(y < b.size() - 1){
//            u = b[x][y + 1];
//        }
//        if(y > 0){
//            d = b[x][y - 1];
//        }
//        int flag = 0;
//        if(uplay == "O"){
//            if(l == 1 || r == 1 || u == 1 || d == 1){
//                flag = 1;
//            }
//            if (flag == 1) {
//                if (l == -1) {
//                    b[x - 1][y] = 1;
//                    raid = 1;
//                }
//                if (r == -1){
//                    b[x + 1][y] = 1;
//                    raid = 1;
//                }
//                if (u == -1){
//                    b[x][y + 1] = 1;
//                    raid = 1;
//                }
//                if (d == -1){
//                    b[x][y - 1] = 1;
//                    raid = 1;
//                }
//            }
//        }
//        else if(uplay == "X"){
//            if(l == -1 || r == -1 || u == -1 || d == -1){
//                flag = 1;
//            }
//            if (flag == 1) {
//                if (l == 1) {
//                    b[x - 1][y] = -1;
//                    raid = 1;
//                }
//                if (r == 1){
//                    b[x + 1][y] = -1;
//                    raid = 1;
//                }
//                if (u == 1){
//                    b[x][y + 1] = -1;
//                    raid = 1;
//                }
//                if (d == 1){
//                    b[x][y - 1] = -1;
//                    raid = 1;
//                }
//            }
//        }
//        return raid;
//    }
//
//
//    vector<vector<int> > checkraid(string uplay, int x, int y, vector<vector<int> > b, vector<vector<int> > c, int *O){
//        raid = 0;
//        int l = -2,
//            r = -2,
//            u = -2,
//            d = -2;
//        if(x > 0){
//            l = b[x - 1][y];
//        }
//        if(x < b.size() - 1){
//            r = b[x + 1][y];
//        }
//        if(y < b.size() - 1){
//            u = b[x][y + 1];
//        }
//        if(y > 0){
//            d = b[x][y - 1];
//        }
//        int flag = 0;
//        if(uplay == "O"){
//            if(l == 1 || r == 1 || u == 1 || d == 1){
//                flag = 1;
//            }
//            if (flag == 1) {
//                if (l == -1) {
//                    b[x - 1][y] = 1;
//                    *O += 2 * c[x - 1][y];
//                    raid = 1;
//                }
//                if (r == -1){
//                    b[x + 1][y] = 1;
//                    *O += 2 * c[x + 1][y];
//                    raid = 1;
//                }
//                if (u == -1){
//                    b[x][y + 1] = 1;
//                    *O += 2 * c[x][y + 1];
//                    raid = 1;
//                }
//                if (d == -1){
//                    b[x][y - 1] = 1;
//                    *O += 2 * c[x][y - 1];
//                    raid = 1;
//                }
//            }
//        }
//        else if(uplay == "X"){
//            if(l == -1 || r == -1 || u == -1 || d == -1){
//                flag = 1;
//            }
//            if (flag == 1) {
//                if (l == 1) {
//                    b[x - 1][y] = -1;
//                    *O -= 2 * c[x - 1][y];
//                    raid = 1;
//                }
//                if (r == 1){
//                    b[x + 1][y] = -1;
//                    *O -= 2 * c[x + 1][y];
//                    raid = 1;
//                }
//                if (u == 1){
//                    b[x][y + 1] = -1;
//                    *O -= 2 * c[x][y + 1];
//                    raid = 1;
//                }
//                if (d == 1){
//                    b[x][y - 1] = -1;
//                    *O -= 2 * c[x][y - 1];
//                    raid = 1;
//                }
//            }
//        }
//        return b;
//    }
//    
//    int Minimax(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int> > cellvalue, vector<vector<int> > broadstate,vector<vector<int> > avaliable){
//        raid = 0;
//        this->broadstate = broadstate;
//        vector<vector<int> > tmp, tmp1, ava;
//        int a;
//        if (depth == 0 || avaliable.size() == 0) {
//            int Ovalue = Ocalculate(N, cellvalue, broadstate);
//            return (youplay == "O" ?  Ovalue : -Ovalue);
//        }
//        if(nowplay == youplay){
//            a = -99999;
//            string otherplay = youplay == "O" ? "X" : "O";
//            for (int i = 0; i < avaliable.size(); i++) {
//                int result = 0;
//                tmp = broadstate;
//                tmp1 = broadstate;
//                ava = avaliable;
//                int x = avaliable[i][0];
//                int y = avaliable[i][1];
//                tmp = checkraid(youplay, y, x, broadstate);
//                tmp[y][x] = nowplay == "O" ? 1 : -1;
//                tmp1[y][x] = nowplay == "O" ? 1 : -1;
//                ava.erase(ava.begin() + i);
//                if(tmp1 != tmp){
//                     result = max(Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava), Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp1, ava));
//                }
//                else{
//                     result = Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
//                }
//                
//                if (a < result) {
//                    a = result;
//                    move.clear();
//                    move.push_back(x);
//                    move.push_back(y);
//                    if(depth == oridepth){
//                        tmp = checkraid(youplay, y, x, broadstate);
//                        raid = checkraid(youplay, y, x, broadstate, 1);
//                        tmp[y][x] = nowplay == "O" ? 1 : -1;
//                      	prevr = raid;
//                        output(N, nowplay, x, y, tmp);
//
//                    }
//                }
//              else if(a == result){
//                	move.clear();
//                    move.push_back(x);
//                    move.push_back(y);
//                    if(raid == 0 && prevr == 1 && depth == oridepth){
//                        output(N, nowplay, x, y, tmp);
//						prevr = 0;
//                    }
//            	}
//            }
//            
//        }
//        else if(nowplay != youplay){
//            a = 99999;
//            for (int i = 0; i < avaliable.size(); i++) {
//                int result = 0;
//                tmp1 = broadstate;
//                tmp = broadstate;
//                ava = avaliable;
//                int x = avaliable[i][0];
//                int y = avaliable[i][1];
//                tmp = checkraid(nowplay, y, x, broadstate);
//                tmp[y][x] = nowplay == "O" ? 1 : -1;
//                tmp1[y][x] = nowplay == "O" ? 1 : -1;
//                ava.erase(ava.begin() + i);
//                if(tmp1 != tmp){
//                    result = min(Minimax(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava), Minimax(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp1, ava));
//                }
//                else{
//                    result = Minimax(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
//                }
//                if (a > result) {
//                    a = result;
//                }
//            }
//        }
//        return a;
//    }
//    int Alphabeta(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int> > cellvalue, vector<vector<int> > broadstate,vector<vector<int> > avaliable, int Ooccupied, int alpha, int beta){
//        raid = 0;
//        int bv, O;
//        vector<int> step;
//        this->broadstate = broadstate;
//        vector<vector<int> > tmp, tmp1, ava;
//        if (depth == 0 || avaliable.size() == 0) {
//            return (youplay == "O" ?  Ooccupied : -Ooccupied);
//        }
//        if(nowplay == youplay){
//            alpha = -99999;
//            string otherplay = youplay == "O" ? "X" : "O";
//            for (int i = 0; i < avaliable.size(); i++) {
//                int result = 0;
//                O = Ooccupied;
//                int O1 = Ooccupied;
//                tmp = broadstate;
//                tmp1 = broadstate;
//                ava = avaliable;
//                int x = avaliable[i][0];
//                int y = avaliable[i][1];
//                tmp = checkraid(youplay, y, x, broadstate, cellvalue, &O);
//                tmp[y][x] = nowplay == "O" ? 1 : -1;
//                tmp1[y][x] = nowplay == "O" ? 1 : -1;
//                if(nowplay == "O"){
//                    O += cellvalue[y][x];
//                    O1 += cellvalue[y][x];
//                }
//                else{
//                    O -= cellvalue[y][x];
//                    O1 -= cellvalue[y][x];
//                }
//                ava.erase(ava.begin() + i);
//                if(tmp1 != tmp){
//                    result = max(Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava, O, alpha, beta), Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp1, ava, O1, alpha, beta));
//                }
//                else{
//                    result = Alphabeta(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava, O1, alpha, beta);
//                }
//
//                if (alpha < result) {
//                    alpha = result;
//                    bv = alpha;
//                    move.clear();
//                    move.push_back(x);
//                    move.push_back(y);
//                    if(depth == oridepth){
//                        tmp = checkraid(youplay, y, x, broadstate);
//                        raid = checkraid(youplay, y, x, broadstate, 1);
//                        tmp[y][x] = nowplay == "O" ? 1 : -1;
//                      	prevr = raid;
//                        output(N, nowplay, x, y, tmp);
//                        //cout << "You: " << result <<endl;
//                    }
//                }
//                else if(alpha == result){
//                    move.clear();
//                    move.push_back(x);
//                    move.push_back(y);
//                    raid = checkraid(youplay, y, x, broadstate, 1);
//                        if(raid == 0 && prevr == 1 && depth == oridepth){
//                            output(N, nowplay, x, y, tmp);
//                            prevr = 0;
//                        }
//                }
//
//                if(beta <= alpha){
//                    break;
//                }
//            }
//
//        }
//        else if(nowplay != youplay){
//            beta = 99999;
//            for (int i = 0; i < avaliable.size(); i++) {
//                O = Ooccupied;
//                int O1 = Ooccupied;
//                int result = 0;
//                tmp = broadstate;
//                tmp1 = broadstate;
//                ava = avaliable;
//                int x = avaliable[i][0];
//                int y = avaliable[i][1];
//                tmp = checkraid(nowplay, y, x, broadstate);
//                tmp[y][x] = nowplay == "O" ? 1 : -1;
//                tmp1[y][x] = nowplay == "O" ? 1 : -1;
//                
//                if(nowplay == "O"){
//                    O += cellvalue[y][x];
//                    O1 += cellvalue[y][x];
//                }
//                else{
//                    O -= cellvalue[y][x];
//                    O1 -= cellvalue[y][x];
//                }
//                ava.erase(ava.begin() + i);
//
//                if(tmp1 != tmp){
//                    result = min(Alphabeta(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava, O, alpha, beta), Alphabeta(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp1, ava, O1, alpha, beta));
//                }
//                else{
//                    result = Alphabeta(N, youplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava, O1, alpha, beta);
//                }
//
//                if (beta > result) {
//                    beta = result;
//                    bv = beta;
//                }
//                
//                if(beta <= alpha){
//                    break;
//                }
//            }
//        }
//        return bv;
//    }
//
//};
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
private:
    int raid = 0;
    int prevr = 0;
    int self = 0;
    string youplay;
    vector<int> move;
    vector<vector<int> > broadstate;
    vector<vector<int> > cellvalue;
    
public:
    void output(int N, string youplay, int x, int y, vector<vector<int> > tmp){
        ofstream ofile;
        string filepath = "/Users/kouruiri/Documents/ChessPlayer/ChessPlayer/output.txt";
        ofile.open(filepath,ios::trunc);
        //        checkraid(youplay, x, y, tmp);
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
    
    int Ocalculate(int N, vector<vector<int> > cellvalue, vector<vector<int> > broadstate){
        int value = 0;
        int i = 0, k = 0;
        for (i = 0; i < N; i++) {
            for (k = 0; k < N + 1; k+=2) {
//                if (broadstate[i][k] == 1) {
//                    value += cellvalue[i][k];
//                }
//                else if(broadstate[i][k] == -1){
//                    value -= cellvalue[i][k];
//                }
                if(k < N){
                    value = broadstate[i][k] == 1 ? value + cellvalue[i][k] : value + cellvalue[i][k] * broadstate[i][k];
                    
                }
                
                if(k + 1 < N){
                    value = broadstate[i][k + 1] == 1 ? value + cellvalue[i][k + 1] : value + cellvalue[i][k + 1] * broadstate[i][k + 1];
                }
            }
        }
        return value;
    }
    
    
    vector<vector<int> > checkraid(string uplay, int x, int y, vector<vector<int> > b){
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
    int checkraid(string uplay, int x, int y, vector<vector<int> > b, int what){
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
        return raid;
    }

    
    int Minimax(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int> > cellvalue, vector<vector<int> > broadstate,vector<vector<int> > avaliable){
        raid = 0;
        this->broadstate = broadstate;
        vector<vector<int> > tmp, ava;
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
                tmp = checkraid(youplay, y, x, broadstate);
                tmp[y][x] = nowplay == "O" ? 1 : -1;
                ava.erase(ava.begin() + i);
                int result = Minimax(N, otherplay, youplay, depth - 1,oridepth, cellvalue, tmp, ava);
                if (a < result) {
                    a = result;
                    move.clear();
                    move.push_back(x);
                    move.push_back(y);
                    if(depth == oridepth){
                        tmp = checkraid(youplay, y, x, broadstate);
                        tmp[y][x] = nowplay == "O" ? 1 : -1;
                        raid = checkraid(youplay, y, x, broadstate, 1);
                        prevr = raid;
                        output(N, nowplay, x, y, tmp);
                        
                    }
                }
                else if(a == result){
                    move.clear();
                    move.push_back(x);
                    move.push_back(y);
                    if(raid == 0 && prevr == 1 && depth == oridepth){
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
    int Alphabeta(int N, string nowplay, string youplay, int depth, int oridepth, vector<vector<int> > cellvalue, vector<vector<int> > broadstate,vector<vector<int> > avaliable, int alpha, int beta){
        raid = 0;
        int bv;
        this->broadstate = broadstate;
        vector<vector<int> > tmp, ava;
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
                tmp = checkraid(youplay, y, x, broadstate);
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
                        tmp = checkraid(youplay, y, x, broadstate);
                        tmp[y][x] = nowplay == "O" ? 1 : -1;
                        raid = checkraid(youplay, y, x, broadstate, 1);
                        prevr = raid;
                        output(N, nowplay, x, y, tmp);
                    }
                }
                else if(alpha == result){
                    move.clear();
                    move.push_back(x);
                    move.push_back(y);
                    if(raid == 0 && prevr == 1 && depth == oridepth){
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