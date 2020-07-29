#include<iostream>
#include<vector>
#include<utility>
using namespace std;
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt){ 
    adj[u].push_back(make_pair(v, wt));  
} 
void cdfa(int a,int b){
	int V=5,i,u,v,w;
	vector<pair<int,int> > adj[V];
	addEdge(adj,0,1,a);
	addEdge(adj,0,3,b);
	addEdge(adj,1,2,b);
	addEdge(adj,2,1,a);
	addEdge(adj,3,4,a);
	addEdge(adj,4,3,b);
	cout<<"DFA transition table is"<<endl;
	cout<<"\nState\t"<<a<<"\t"<<b<<endl;
	cout<<"-----\t-----\t-----"<<endl;
	for(i=0;i<V;i++){
		cout<<"q["<<i<<"]\t";
		w=adj[i].size();
		if(w==0){
			cout<<"NULL\t"<<"NULL"<<endl;
		}
		else{
			vector<pair<int,int> > :: iterator itr;
			for(itr=adj[i].begin();itr!=adj[i].end();itr++){
				u=itr->first;
				v=itr->second;
				if(v==a){
					cout<<"q("<<u<<")\t";
					if(w==1)
						cout<<"NULL"<<endl;
				}
				else if(v==b){
					if(w==1)
						cout<<"NULL\t";
					cout<<"q("<<u<<")\t"<<endl;
				}
			}
       	}
	}
	cout<<"\n";
}

void mdfa(int a,int b){
	int V=3,i,u,v,w;
	vector<pair<int,int> > adj[V];
	addEdge(adj,0,1,a);
	addEdge(adj,0,2,b);
	addEdge(adj,1,2,b);
	addEdge(adj,2,1,a);
	cout<<"Minimized DFA transition table is"<<endl;
	cout<<"\nState\t"<<a<<"\t"<<b<<endl;
	cout<<"-----\t-----\t-----"<<endl;
	for(i=0;i<V;i++){
		w=adj[i].size();
		cout<<"q["<<i<<"]\t";
		if(w==0){
			cout<<"NULL\t"<<"NULL"<<endl;
		}
		else{
			vector<pair<int,int> > :: iterator itr;
			for( itr=adj[i].begin();itr!=adj[i].end();itr++){
				u=itr->first;
				v=itr->second;
				if(v==a){
					cout<<"q("<<u<<")\t";
					if(w==1)
						cout<<"NULL"<<endl;
				}
				else if(v==b){
					if(w==1)
						cout<<"NULL\t";
					cout<<"q("<<u<<")\t"<<endl;
				}
			}
    	}
	}
	cout<<"\n";
}

int main(){
	int n,i,a,b;
	char ch;
	cout<<"DFA for alternate sequence of a and b\n";
	cout<<"RE=(ab)*/(ba)*/a(ba)*/b(ab)*"<<endl;
	cout<<"Enter the value of a and b : ";
	cin>>a>>b;
	do{
		cout<<"1. Construct the dfa and display it"<<endl;
		cout<<"2. Display the total no of states in dfa"<<endl;
		cout<<"3. Construct a minimized dfa"<<endl;
		cout<<"4. Display the minimized no of states"<<endl;
		cout<<"Enter your choice : ";
		cin>>n;
		switch(n){
			case 1: 
				cdfa(a,b); 
			    break;
			case 2: 
				cout<<"Total no of states in original dfa = 5"<<endl;
		        break;
			case 3:  
				mdfa(a,b);
			    break;
			case 4: 
				cout<<"The minimized no of states = 3"<<endl;
		        break;
			default: 
				cout<<"Invalid choice"<<endl;  			         
		}
		cout<<"Press y to continue or n to end : ";
		cin>>ch;
	}while(ch=='y');
	return 0;
}
