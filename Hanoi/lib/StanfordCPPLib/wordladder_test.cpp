#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include "lexicon.h"
#include "stack.h"
#include "queue.h"

using namespace std;

string fir,sec;

int main(){
	Lexicon words("EnglishWords.dat");
	Lexicon used;
	printf("please print the first word:");
	cin >> fir;
	used.add(fir);
	printf("\nplease print the second word:");
	cin >> sec ;
	printf("\n");
	Stack<string> ori;
	Queue<Stack<string> > q;
	ori.push(fir);
	q.enqueue(ori);
	do{
	    Stack<string> word;
    	    word=q.dequeue();
    	    string pre_word=word.peek();
		int len=pre_word.length();
		for(int i=0;i<len;i++){
			string next_word;
			for(int j='a';j<='z';j++){
				if(pre_word[i]==j) continue;
				else{
					next_word=pre_word;
					next_word[i]=j;
					if(used.contains(next_word))
					    continue;
					else if(words.contains(next_word)){
						Stack<string> w=word;
						w.push(next_word);
						q.enqueue(w);
					}
					if(string(next_word)==string(sec)){
						cout << sec ;
						while(word.isEmpty()!=true){
							string ss=word.pop();
							cout << ss;
						}
						return 0;
					}
				}
			}
		} 
	}while(q.isEmpty()!=true);
	return 0;
} 
