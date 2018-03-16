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
	scanf("%s",fir);
	used.add(fir);
	printf("\nplease print the second word:");
    scanf("%s",sec);
    printf("\n");
    stack<string> ori;
    queue<stack> q;
    ori.push(fir);
    q.enqueue(ori);
    do{
    	stack<string> word;
    	word=q.dequeue();
    	string pre_word=word.peek();
		int len=strlen(pre_word);
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
						stack w=word;
						w.push(next_word);
						q.enqueue(w);
					}
					if(string(next_word)==string(sec)){
						printf("%s ",sec);
						while(word.isEmpty()!=true){
							string ss=word.pop();
							printf("%s ",ss);
						}
						return 0;
					}
				}
			}
		} 
	}while(q.isEmpty()!=true);
	return 0;
} 
