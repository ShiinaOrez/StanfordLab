/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

const double C=sqrt(3.0)/2.0;

int gcd(int a, int b) {
    if(!b){
        printf("gcd(%d,0)=%d\n",a,a);
        return a;
    }
    else{
        printf("gcd(%d,%d)=gcd(%d,%d)\n",a,b,b,a%b);
        return gcd(b,a%b);
    }
}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order ,int n) {
    int rightX,rightY,underX,underY;
    rightX=leftX+size;
    rightY=leftY;
    underX=(leftX+rightX)/2;
    underY=int(double(leftY)+double(size)*C);
    upY=int(double(leftY)-double(size)*C);
    if (order==n){
        w.drawLine(leftX,leftY,rightX,rightY);
        w.drawLine(leftX,leftY,underX,underY);
        w.drawLine(rightX,rightY,underX,underY);
        serpinskii(w,(leftX+underX)/2,(leftY+underY)/2,size/2,order-1,n);
    }
    else{
        w.drawLine(leftX,leftY,rightX,rightY);
        w.drawLine(leftX,leftY,underX,upY);
        w.drawLine(rightX,rightY,underX,upY);
        if(order==1) return ;
        else{
            serpinskii(w,leftX-size/4,leftY-int((size/2)*C),size/2,order-1,n);
            serpinskii(w,leftX+size/4,leftY+int((size/2)*C),size/2,order-1,n);
            serpinskii(w,(upX+rightX)/2,(upY+rightY)/2,size/2,order-1,n);
        }
    }
    return ;
//    cout << "[recursion serpinskii called]" << endl;
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    // your code here
    cout << "[recursion flood fill called]" << endl;
    return 0;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
