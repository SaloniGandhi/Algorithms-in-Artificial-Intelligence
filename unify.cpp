#include<cstring>
#include<cstdio>
#include<iostream>
#include<iomanip>
#include<cstdlib>
/* 
1.Sentence must start with a Uppercase character (e.g. Noun/ I/ We/ He etc.)
2. Then lowercase character follows.
3. There must be spaces between words.
4. Then the sentence must end with a full stop(.) after a word.
5. Two continuous spaces are not allowed.
6. Two continuous upper case characters are not allowed.
7. However the sentence can end after an upper case character.
*/

using namespace std;
using std::string;

bool check_Sentence(char *str);
string*refine_sentence(string arr[]);

struct node{
		string sub_noun;
		string verb;
		string object;
		int word_count;
		
		};
		



  
int main(){
	
	string str1,str2;
	cout<<"enter the first sentence"<<endl;
	getline(cin,str1);
	cout<<"enter the second sentence"<<endl;
	getline(cin,str2);

	
	
	
//now put your input strings into a character array to check whether your sentence is in the correct form.
	char *str1dup = new char[str1.length() + 1];
	strcpy(str1dup, str1.c_str());
	char*str2dup=new char[str2.length()+1];
	strcpy(str2dup,str2.c_str());

/*now to check whether the given sentences are in an acceptable
	form so that we can tokenize them*/
	int str1dup_size = sizeof(str1dup) / sizeof(str1dup[0]);
	int ans1=check_Sentence(str1dup) ;
	cout<<ans1<<endl;                           
	int str2dup_size=sizeof(str2dup)/sizeof(str2dup[0]);
	int ans2=check_Sentence(str2dup);
	cout<<ans2<<endl;
	
	
	
	
	int j=0;
	string arr1[500];
	string arr2[500];
	char *dup1 = strdup(str1.c_str());
	char *dup2=strdup(str2.c_str());
	char*p;
	
	p=strtok(dup2," ,.-");
	while(p!=NULL){
		//cout<<dup2;
		arr2[j]=p;
		p=strtok(NULL," ,.-");
		j++;
		}
		
	char*token1;
	//char*token2;
	int i=0;
 	token1 = strtok (dup1," ,.-");
 	//token2 = strtok (dup2," ,.-");
  	while (token1 != NULL)
  		{
    			
    			arr1[i]=token1;
    			
    			token1 = strtok (NULL, " ,.-");
    			
    			i++;
  		}
  	int s3=arr1->size();
  	/*cout<<"The contents of the sentence1 are as follows b4 refining"<<endl;
  	for(int x=0;x<20;x++){
 	cout<<arr1[x]<<endl;
 		}	
 	//cout<<endl;
  	cout<<"The contents of the sentence2 are as follows b4 refining"<<endl;
  	int s4= arr2->size();	
  	cout<<"size:"<<s4;
  	for(int y=0;y<20;y++){
  		cout<<arr2[y]<<endl;	}
	*/
	
	free(dup1);
	free(dup2);
	string*catchstr1=new string[500];
	string*catchstr2=new string[500];
		
	//the refined array is now stored in catchstr.
	catchstr1=refine_sentence(arr1);
	catchstr2=refine_sentence(arr2);
	int s1=catchstr1->size();
	cout<<endl;
	
	cout<<"contents after refining for sentence1"<<endl;
	for(i=0;i<s1;i++){
  		cout<<catchstr1[i]<<endl;	}
	
	cout<<endl;
	
	
	cout<<"contents after refining for sentence2"<<endl;
	for(i=0;i<7;i++){
  		cout<<catchstr2[i]<<endl;	}
  	/*
  	cout<<catchstr2[0]<<catchstr2[1]<<catchstr2[2];
  	cout<<"size"<<s1;
  	cout<<s2;*/
	int s2=catchstr2->length();  
  	node*sentence1=new node;
  	sentence1->sub_noun=catchstr1[0];
  	sentence1->verb=catchstr1[1];
  	sentence1->object=catchstr1[2]; 
  	sentence1->word_count=s1;
  	
  	node*sentence2=new node;
  	sentence2->sub_noun=catchstr2[0];
  	sentence2->verb=catchstr2[1];
  	sentence2->object=catchstr2[2]; 
  	sentence2->word_count=s2;
  	
  	if(sentence1==NULL||sentence2==NULL)
  		cout<<"The Input is invalid";
  	
  	//compare the two nodes if their verbs match we can proceed to unify
  	//if(sentence1->word_count==sentence2->word_count){
  		if (sentence1->verb==sentence2->verb){
  			
  			if(sentence1->sub_noun==sentence2->sub_noun){
  				cout<<"The noun of sentence 1 :-" << sentence1->sub_noun<<setw(2)<<"maps to ";
  				cout<<"the noun of sentence 2:-"<<sentence2->sub_noun;
				cout<<endl;
				cout<<"Thus object of sentence1 maps to object of sentence 2:"<<endl;
				cout<<sentence1->object<<"|"<<sentence2->object<<endl;
				cout<<endl;
				}
  			else if (sentence1->object==sentence2->object){
  				cout<<"The object of sentence 1 :" << sentence1->object<<"maps to ";
  				cout<<"The object of sentence 2:"<<sentence2->object;
				cout<<endl;
				cout<<"Thus noun of sentence1 maps to noun of sentence 2:"<<endl;
				cout<<sentence1->sub_noun<<"|"<<sentence2->sub_noun<<endl;
				}
  		}
  	//}
  		
  
	
	
	return 0;//end of main
	}
	
	
	
	
string*refine_sentence(string array[]){
	string*refine=new string[50];
	for(int i=0;i<50;i++){
		if(array[i]=="the"){
			refine[i]=array[i+1];	
			break;}
		if(array[i]=="to"){
			refine[i]=array[i+1];
			break;}
		if((array[i]=="a")||(array[i]=="an")||(array[i]=="it")||(array[i]=="they")){
			refine[i]=array[i+1];
			break;}//causes next iteration of the loop.
		else {
			refine[i]=array[i];
			continue;}
	}
return refine;
}







bool check_Sentence(char *str){
	int len =strlen(str);
	if(str[0]<'A' ||str[0]>'Z')
		return false;
	//if last character is not a full stop then invalid
	if(str[len-1]!='.')
		return false;
	int prev=0,current=0;
	int index=1;
	//loop the sentence
	while(str[index]){	
		 if(str[index]>='A' && str[index]<='Z')
			current=0;
		else if(str[index]==' ')
			current=1;
		else if(str[index]>='a' && str[index]<='z')
			current=2;
		else if(str[index]=='.')
			current=3;
		if(prev==current && current!=2)
			return false;
		if(prev==2 && current== 0)
			return false;
		if(current==3 && prev!=1)
			return (str[index+1]=='\0');
		index++;
		//set prev as current b4 moving to next character
		prev=current;
	}
return false;

}
	
			
			
			
			
			
