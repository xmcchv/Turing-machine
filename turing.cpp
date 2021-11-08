
#include <iostream>
#include <QByteArray>
#include <QList>
#include <QDebug>

using namespace std;
class Turing
{
public:
 char new_symbol;
 char current_symbol;
 bool direction;
 int state;
 int pos;
 QByteArray tape;
//    QList<QByteArray> addarray;
//    QList<QByteArray> timesarray;
//     2*3^2+3*4
void q0(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='a';pos++;q1();break;
    case '0': tape[pos]='0';pos++;q7();break;
    }
}
void q1(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q1();break;
    case '0': tape[pos]='0';pos++;q2();break;
    }
}
void q2(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='b';pos++;q3();break;
    case '0': tape[pos]='0';pos--;
        q5();
        break;
    }
}
void q3(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q3();break;
    case '0': tape[pos]='0';pos++;q4();break;
    }
}
void q4(){
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;
        q4();
        break;
    case '0': tape[pos]='0';pos++;
        q4();
        break;
    case 'E': tape[pos]='1';pos--;
        q6();
        break;
    case 'X': tape[pos]='X';pos++;
        q4();
        break;
    case '@': tape[pos]='@';pos++;
        q4();
        break;
    }
}
void q5(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q5();break;
    case '0': tape[pos]='0';pos--;q5();break;
    case 'b': tape[pos]='1';pos--;q5();break;
    case 'a': tape[pos]='a';pos++;q0();break;
    }
}
void q6(){
//     qDebug()<<"q6";
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;
        q6();
        break;
    case '0': tape[pos]='0';pos--;
        q6();
        break;
    case 'b': tape[pos]='b';pos++;
        q2();
        break;
    case 'X': tape[pos]='X';pos--;
        q6();
        break;
    case '@': tape[pos]='@';pos--;
        q6();
        break;
    }
}
void q7(){
//     qDebug()<<"q7";
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q7();break;
    case '0': tape[pos]='0';pos++;q7();break;
    case 'b': tape[pos]='b';pos++;q7();break;
    case 'X': tape[pos]='a';pos++;q8();break;
    }
}
void q8(){
//    qDebug()<<"q8";
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q8();break;
    case '0': tape[pos]='0';pos++;q8();break;
    case 'E': tape[pos]='@';pos--;q9();break;
    case 'X': tape[pos]='X';pos++;q8();break;
    case '@': tape[pos]='@';pos++;q8();break;
    }
}
void q9(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q9();break;
    case '0': tape[pos]='0';pos--;q9();break;
    case '@': tape[pos]='@';pos++;q10();break;
    }
}
void q10(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='b';pos++;q11();break;
//    case '0': tape[pos]='0';pos++;q7();break;
    case '@': tape[pos]='@';pos--;q13();break;
    }
}
void q11(){
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q11();break;
    case 'E': tape[pos]='1';pos--;q12();break;
    case '@': tape[pos]='@';pos++;q11();break;
    }
}
void q12(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q12();break;
    case 'b': tape[pos]='b';pos++;q10();break;
    case '@': tape[pos]='@';pos--;q12();break;
    }
}
void q13(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q13();break;
    case '0': tape[pos]='0';pos--;q13();break;
    case 'b': tape[pos]='1';pos--;q13();break;
    case 'a': tape[pos]='a';pos++;q14();break;
    case 'X': tape[pos]='X';pos--;q13();break;
    case '@': tape[pos]='@';pos--;q13();break;
    }

}
//2*3^2+3*4
void q14(){
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q14();break;
    case '0': tape[pos]='0';pos++;q14();break;
    case 'E': tape[pos]='@';pos--;q18();break;
    case 'X': tape[pos]='a';pos++;q15();break;
    case '@': tape[pos]='@';pos++;q14();break;
    }
}
void q15(){
//    qDebug()<<"q15";
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q15();break;
    case '0': tape[pos]='0';pos++;q15();break;
    case 'E': tape[pos]='E';pos--;q16();break;
    case 'X': tape[pos]='X';pos++;q15();break;
    case '@': tape[pos]='@';pos++;q15();break;
    }
}
void q16(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q16();break;
    case '@': tape[pos]='@';pos--;q17();break;
    }
}
void q17(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q17();break;
    case '@': tape[pos]='@';pos++;q10();break;
    }
}
void q18(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q18();break;
    case '0': tape[pos]='0';pos--;q18();break;
    case 'a': tape[pos]='a';pos++;q18_5();break;
    case '@': tape[pos]='@';pos--;q18();break;
    }
}
void q18_5(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '@': tape[pos]='@';pos++;q19();break;
    }
}
//2*3^2+3*4
void q19(){
//    qDebug()<<"q19";
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='a';pos++;q20();break;
    case '0': tape[pos]='0';pos++;q25();break;

    }
}
void q20(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q20();break;
    case '0': tape[pos]='0';pos++;q21();break;

    }
}
void q21(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='b';pos++;q22();break;

    case '@': tape[pos]='@';pos--;q24();break;
    }
}
void q22(){
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q22();break;
    case '0': tape[pos]='0';pos++;q22();break;
    case 'E': tape[pos]='1';pos--;q23();break;
    case '@': tape[pos]='@';pos++;q22();break;
    }
}
//2*3^2+3*4
void q23(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q23();break;
    case '0': tape[pos]='0';pos--;q23();break;
    case 'b': tape[pos]='b';pos++;q21();break;
    case '@': tape[pos]='@';pos--;q23();break;
    }
}
void q24(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q24();break;
    case '0': tape[pos]='0';pos--;q24();break;
    case 'b': tape[pos]='1';pos--;q24();break;
    case 'a': tape[pos]='a';pos++;q19();break;
    }
}
void q25(){
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q25();break;
    case '0': tape[pos]='0';pos++;q25();break;
    case 'E': tape[pos]='E';pos--;q26();break;
    case '@': tape[pos]='@';pos++;q25();break;
    }
}
void q26(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q26();break;

    case '@': tape[pos]='1';pos++;q27();break;
    }
}
void q27(){
    qDebug()<<"q27";
    if(pos==tape.length()){
        tape.append('E');
    }
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos++;q27();break;

    case 'E': tape[pos]='E';pos--;q28();break;
    }
}
void q28(){
    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='E';pos--;q29();break;
    }
}
void q29(){

    current_symbol = tape.at(pos);
    switch (current_symbol) {
    case '1': tape[pos]='1';pos--;q29();break;
    case '@': tape[pos]='@';pos++;qf();break;
    }
}
void qf(){
    print();

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
//    current_symbol = tape.at(pos);
    q0();
//    print();
}


void print(){
    qDebug()<<tape;
}


};

