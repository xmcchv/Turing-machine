
#include <iostream>
#include <QByteArray>
#include <QList>
#include <QDebug>

using namespace std;
class Turing_1
{
public:
 char new_symbol;
 char current_symbol;
 bool direction;
 QString state;
 int result;
 int pos;
 QByteArray tape;
//    QList<QByteArray> addarray;
//    QList<QByteArray> timesarray;
//     2*3^2+3*4
 void process(){
     while(state!="qf"){
         if(state=="q0"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='a';pos++;state="q1";break;
             case '0': tape[pos]='0';pos++;state="q7";break;
             }
         }
         else if(state=="q1"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q1";break;
             case '0': tape[pos]='0';pos++;state="q2";break;
             }
         }
         else if(state=="q2"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='b';pos++;state="q3";break;
             case '0': tape[pos]='0';pos--;state="q5";break;
             }
         }
         else if(state=="q3"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q3";break;
             case '0': tape[pos]='0';pos++;state="q4";break;
             }
         }
         else if(state=="q4"){
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q4";break;
             case '0': tape[pos]='0';pos++;state="q4";break;
             case 'E': tape[pos]='1';pos--;state="q6";break;
             case 'X': tape[pos]='X';pos++;state="q4";break;
             case '@': tape[pos]='@';pos++;state="q4";break;
             }
         }
         else if(state=="q5"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q5";break;
             case '0': tape[pos]='0';pos--;state="q5";break;
             case 'b': tape[pos]='1';pos--;state="q5";break;
             case 'a': tape[pos]='a';pos++;state="q0";break;
             }
         }
         else if(state=="q6"){
         //     qDebug()<<"q6";
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q6";break;
             case '0': tape[pos]='0';pos--;state="q6";break;
             case 'b': tape[pos]='b';pos++;state="q2";break;
             case 'X': tape[pos]='X';pos--;state="q6";break;
             case '@': tape[pos]='@';pos--;state="q6";break;
             }
         }
         else if(state=="q7"){
         //     qDebug()<<"q7";
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q7";break;
             case '0': tape[pos]='0';pos++;state="q7";break;
             case 'b': tape[pos]='b';pos++;state="q7";break;
             case 'X': tape[pos]='a';pos++;state="q8";break;
             case '@': tape[pos]='@';pos++;state="q19";break;
             }
         }
         else if(state=="q8"){
         //    qDebug()<<"q8";
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q8";break;
             case '0': tape[pos]='0';pos++;state="q8";break;
             case 'E': tape[pos]='@';pos--;state="q9";break;
             case 'X': tape[pos]='X';pos++;state="q8";break;
             case '@': tape[pos]='@';pos++;state="q8";break;
             }
         }
         else if(state=="q9"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q9";break;
             case '0': tape[pos]='0';pos--;state="q9";break;
             case '@': tape[pos]='@';pos++;state="q10";break;
             }
         }
         else if(state=="q10"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='b';pos++;state="q11";break;
         //    case '0': tape[pos]='0';pos++;q7();break;
             case '@': tape[pos]='@';pos--;state="q13";break;
             }
         }
         else if(state=="q11"){
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q11";break;
             case 'E': tape[pos]='1';pos--;state="q12";break;
             case '@': tape[pos]='@';pos++;state="q11";break;
             }
         }
         else if(state=="q12"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q12";break;
             case 'b': tape[pos]='b';pos++;state="q10";break;
             case '@': tape[pos]='@';pos--;state="q12";break;
             }
         }
         else if(state=="q13"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q13";break;
             case '0': tape[pos]='0';pos--;state="q13";break;
             case 'b': tape[pos]='1';pos--;state="q13";break;
             case 'a': tape[pos]='a';pos++;state="q14";break;
             case 'X': tape[pos]='X';pos--;state="q13";break;
             case '@': tape[pos]='@';pos--;state="q13";break;
             }

         }
         //2*3^2+3*4
         else if(state=="q14"){
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q14";break;
             case '0': tape[pos]='0';pos++;state="q14";break;
             case 'E': tape[pos]='@';pos--;state="q18";break;
             case 'X': tape[pos]='a';pos++;state="q15";break;
             case '@': tape[pos]='@';pos++;state="q14";break;
             }
         }
         else if(state=="q15"){
         //    qDebug()<<"q15";
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q15";break;
             case '0': tape[pos]='0';pos++;state="q15";break;
             case 'E': tape[pos]='E';pos--;state="q16";break;
             case 'X': tape[pos]='X';pos++;state="q15";break;
             case '@': tape[pos]='@';pos++;state="q15";break;
             }
         }
         else if(state=="q16"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q16";break;
             case '@': tape[pos]='@';pos--;state="q17";break;
             }
         }
         else if(state=="q17"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q17";break;
             case '@': tape[pos]='@';pos++;state="q10";break;
             }
         }
         else if(state=="q18"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q18";break;
             case '0': tape[pos]='0';pos--;state="q18";break;
             case 'a': tape[pos]='a';pos++;state="q18_5";break;
             case '@': tape[pos]='@';pos--;state="q18";break;
             }
         }
         else if(state=="q18_5"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '@': tape[pos]='@';pos++;state="q19";break;
             }
         }
         //2*3^2+3*4
         else if(state=="q19"){
         //    qDebug()<<"q19";
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='a';pos++;state="q20";break;
             case '0': tape[pos]='0';pos++;state="q25";break;

             }
         }
         else if(state=="q20"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q20";break;
             case '0': tape[pos]='0';pos++;state="q21";break;

             }
         }
         else if(state=="q21"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='b';pos++;state="q22";break;

             case '@': tape[pos]='@';pos--;state="q24";break;
             }
         }
         else if(state=="q22"){
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q22";break;
             case '0': tape[pos]='0';pos++;state="q22";break;
             case 'E': tape[pos]='1';pos--;state="q23";break;
             case '@': tape[pos]='@';pos++;state="q22";break;
             }
         }
         //2*3^2+3*4
         else if(state=="q23"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q23";break;
             case '0': tape[pos]='0';pos--;state="q23";break;
             case 'b': tape[pos]='b';pos++;state="q21";break;
             case '@': tape[pos]='@';pos--;state="q23";break;
             }
         }
         else if(state=="q24"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q24";break;
             case '0': tape[pos]='0';pos--;state="q24";break;
             case 'b': tape[pos]='1';pos--;state="q24";break;
             case 'a': tape[pos]='a';pos++;state="q19";break;
             }
         }
         else if(state=="q25"){
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q25";break;
             case '0': tape[pos]='0';pos++;state="q25";break;
             case 'E': tape[pos]='E';pos--;state="q26";break;
             case '@': tape[pos]='@';pos++;state="q25";break;
             }
         }
         else if(state=="q26"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q26";break;

             case '@': tape[pos]='1';pos++;state="q27";break;
             }
         }
         else if(state=="q27"){
             if(pos==tape.length()){
                 tape.append('E');
             }
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos++;state="q27";break;
             case 'E': tape[pos]='E';pos--;state="q28";break;
             }
         }
         else if(state=="q28"){
             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='E';pos--;state="q29";break;
             }
         }
         else if(state=="q29"){

             current_symbol = tape.at(pos);
             switch (current_symbol) {
             case '1': tape[pos]='1';pos--;state="q29";break;
             case '@': tape[pos]='@';pos++;state="qf";break;
             }
         }
//         else if(state=="qf"){
//             print();
//         }
     }
     print();
     countresult();
 }

// 2*3^2+3*4
 void countresult(){
    QByteArrayList tmp=tape.split('@');
    QByteArray resulttape=tmp[tmp.length()-1].split('E')[0];
    qDebug()<<resulttape;
    qDebug()<<resulttape.length();
    result=resulttape.length();
 }


void initialize(QByteArrayList str){
//    tape.append(str);
    int a = str[0].toInt();
    int x = str[1].toInt();
    int b = str[2].toInt();
    int y = str[3].toInt();

    for(int i=0;i<a;i++){
        tape.append("1");
    }
    tape.append("0");
    for(int i=0;i<x;i++){
        tape.append("1");
    }
    tape.append("0");
    for(int i=0;i<x;i++){
        tape.append("X");
    }
    tape.append("@");
    for(int i=0;i<b;i++){
        tape.append("1");
    }
    tape.append("0");
    for(int i=0;i<y;i++){
        tape.append("1");
    }
    tape.append("@");


    pos = 0;
    state="q0";
    process();

}


void print(){
    qDebug()<<tape;
}


};

