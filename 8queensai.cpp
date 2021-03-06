/*
NAME:ATMAKURU VENKATA SUBRAMANYA DHATRISH
ROLL_NO:1801037


1.State space:
       Here sate space is a 8x8 matrix where the position of a queen is represented by 1
2.State transition operator:
		adding a new queen which is denoted by 1 in the subsequent row.
3.intitial state:
		a 8 x 8 null matrix.
4.Goal state:
		When all the rows are filled with a single queen at non attacking positions,
5.Cost:
		 				
		       
*/
#include<iostream>
#include<queue>
using namespace std;
bool solution=false;
int cost=0;
struct board{
	int mat[8][8];
	int queens;
};
queue<board> q1;
board initialize(board &b1){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			b1.mat[i][j]=0;
		}
	}
	b1.queens=0;
	return b1;
}
void print(board &temp){
	cout<<"temp"<<endl;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cout<<temp.mat[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}
//function to check whther queens are in valid position.
bool isvalid(board &temp){
	int q=temp.queens,p=0,i,i2;
	for(i=0;i<8;i++){
		if(temp.mat[q-1][i]==1) break;
	}
	for(int j=q-2;j>=0;j--){
		if(temp.mat[j][i]==1){
			return false;
		}
	}
	i2=i-1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2<0) break;
		if(temp.mat[j][i2]==1) return false;
		i2--;
	}
	i2=i+1;
	for(int j=q-2;j>=0;j--){
		if(j<0||i2>7) break;
		if(temp.mat[j][i2]==1) return false;
		i2++;
	}
	return true;
}
/*utility function to genaerate all the possible next states for the given state of the board and if they are valid, they are added
to the queue.*/
void states(queue<board> &q1){
	board temp;
	bool oc=true;
	temp=q1.front();
	q1.pop();
	int q=temp.queens;
    if(temp.queens==8) {
    	print(temp);
    	cout<<"solution found\n"<<endl;
    	cout<<"cost is "<<cost<<endl;
    	solution=true;
    	return;
	}
	for(int i=0;i<8;i++){
		temp.mat[q][i]=1;
		temp.queens++;
		if(q==0||isvalid(temp)){
			print(temp);
			q1.push(temp);
			cost++;
		}
		temp.queens--;
		temp.mat[q][i]=0;
	}
}
//main function for intiation of the problem.
int main(){
	board b1;
	initialize(b1);
	q1.push(b1);
    while(!q1.empty()&&solution==false){
    	states(q1);
    	
	}
	return 0;
}
