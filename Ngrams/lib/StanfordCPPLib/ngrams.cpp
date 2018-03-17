// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <ctime>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "map.h"
#include "vector.h" 
#include "queue.h"
#include "console.h"

using namespace std;

int N;
Map<Vector<string>,Vector<string> > gram;
Vector<string> arti; 
Queue<string> output;

voide get_info(){
	string text_name;
	printf("we want to get the N:");
	cin>> N;
	printf("\nwe also want to get the length:");
	cin>> length;
	printf("\nand the text_file name?:");
	ifstream stream;{//make a new stream
		while(1){
			cin>> text_name;//file_name
			stream.open(text_name.c_str());
			if(stream.fail()){
				printf("\nwhat mo**er_f**k ?type it again!:");//if we can't open the file
				continue;
			}
			else break;//we open the file
		}
		while(1){//deal with xxx.txt
			string word;
			stream>> word;//input the word from stream
			if(stream.fail()) break;//input all of the word
			else arti.add(word);
		}
	} 
	stream.close();//close the stream we open
	return ;//return the main function
} 

void maketh_map(){//make the map
	int p,size=arti.size();
	for(int i=0;i<size;i++){//get the key
		Vector<string> key;
		p=i+N;
		if(p<=size){
			for(int j=i;j<p;j++){
				key.add(arti[j]); 
			}
		}
		else {//break apart
			p%=size;
			for(int j=i;j<size;j++) 
				key.add(arti[j]);
			for(int j=0;j<p;j++)
				key.add(arti[j]);
		}
		last_word=arti[p];
		Vector<string> value;
		if(map.containsKey(key)){//the key has existed
			value=map.get(key);
			value.add(last_word);
			map.put(key,value);
		}
		else {
			value.add(last_word);
			map.put(key,value);
		}
	}
	return ;
}

void print(){
	while(output.isEmpty()!=0){
		string p=output.dequeue();
		cout<< p << ' ';
	} 
	return ;
}

int main() {
	
    get_info();//before we deal with data,we must to get_info
	maketh_map();//maketh map
	
	Vector<string> first_key;//first random key
	Queue<string> t;//2nd,3rd,4th....Nth key
	first_key=map.keys()[randomInteger(1,map.keys.size()-1)];//random
	for(int i=0;i<N-1;i++){
		output.enqueue(first_key[i]);//enqueue
		t.enqueue(first_key[i]);//order to find the value
	} 
	length-=(N-1);//length decrease
	
	while(length>0){
		Vector<string> tt;//data_type queue can't to get the value
		for(int i=0;i<N-1;i++)//queue into vector
			tt[i]=t[i]; 
		Vector<string> words=map.get(tt);//get the value
		string word=words[randomInteger(0,words.size()-1)]//random the next word
		t.enqueue(word);//key enqueue
		output.enqueue(word);//enqueue
		t.dequeue();//key dequeue
		length--;
	}
	
	print();
	
    cout << "Exiting." << endl;
    return 0;
}
