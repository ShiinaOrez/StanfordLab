/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include <string>
#include <ctime>
#include <random>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "lexicon.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

Map <string,int> print;
int count=0;
const double C=sqrt(3.0)/2.0;

int gcd(int a, int b) {
    if(!b){
        cout << "gcd(" <<a<<",0)="<<a<<"\n" ;
        return a;
    }
    else{
        cout << "gcd(" <<a<<","<<b<<")=gcd("<<b<<","<<a%b<<")\n" ;
        return gcd(b,a%b);
    }
}

void ser(GWindow &w, int leftX, int leftY, int size, int order){
    int rightX,rightY,underX,underY;
    rightX=leftX+size;
    rightY=leftY;
    underX=(leftX+rightX)/2;
    underY=int(double(leftY)+double(size)*C);
    int upY=int(double(leftY)-double(size)*C);
    if(!order) return ;
    else{
        w.drawLine(leftX,leftY,rightX,rightY);
        w.drawLine(leftX,leftY,underX,upY);
        w.drawLine(rightX,rightY,underX,upY);
        ser(w,leftX-size/4,leftY-int((size/2)*C),size/2,order-1);
        ser(w,leftX+size/4,leftY+int((size/2)*C),size/2,order-1);
        ser(w,(underX+rightX)/2,(upY+rightY)/2,size/2,order-1);
    }
    return ;
}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    int rightX,rightY,underX,underY;
    rightX=leftX+size;
    rightY=leftY;
    underX=(leftX+rightX)/2;
    underY=int(double(leftY)+double(size)*C);
    int upY=int(double(leftY)-double(size)*C);
    w.drawLine(leftX,leftY,rightX,rightY);
    w.drawLine(leftX,leftY,underX,underY);
    w.drawLine(rightX,rightY,underX,underY);
    ser(w,(underX+leftX)/2,(underY+leftY)/2,size/2,order-1);
    return ;
}

void fill(GBufferedImage& image,int x,int y,int newColor,int color){
    if(!image.inBounds(x,y)) return ;
    if(image.getRGB(x,y)!=color) return ;
    image.setRGB(x,y,newColor);
    count++;
    fill(image,x+1,y,newColor,color);
    fill(image,x,y+1,newColor,color);
    fill(image,x-1,y,newColor,color);
    fill(image,x,y-1,newColor,color);
    return ;
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    count=0;
    int width=image.getWidth();
    int height=image.getHeight();
    int color=image.getRGB(x,y);
    if(!image.inBounds(x,y)){
        cout << count << endl;
        return 0;
    }
    if(newColor==color) return 0;
    image.setRGB(x,y,newColor);
    fill(image,x+1,y,newColor,color);
    fill(image,x,y+1,newColor,color);
    fill(image,x-1,y,newColor,color);
    fill(image,x,y-1,newColor,color);
    cout << count << endl;
//    cout << "[recursion flood fill called]" << endl;
    return 0;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    if(!prereqMap.containsKey(goal)){
        return ;
    }
    else{
        Vector <string> ss;
        ss=prereqMap.get(goal);
        for(int i=0;i<ss.size();i++){
            if(print.containsKey(ss[i])) continue;
            else{
                personalCurriculum(prereqMap,ss[i]);
                if(!print.containsKey(ss[i])){
//                    cout << print.containsKey(ss[i]);
                    print.put(ss[i],1);
                    cout << ss[i] << endl;
                }
            }
        }
    }
    return ;
//    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    srand(time(0));
    string str;
    Vector <string> array;
    if(!grammar.containsKey(symbol)){
        str=' '+symbol;
        return str;
    }
    else{
        string token;
        array=grammar.get(symbol);
        token=array[rand()%array.size()];
        TokenScanner s(token);
        while(s.hasMoreTokens()){
            string t=s.nextToken();
            str=str+' '+generate(grammar, t);
        }
    }
//    cout << "[recursion generate called]" << endl;
    return str;
}
