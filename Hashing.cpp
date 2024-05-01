#include<iostream>
using namespace std;
class Hashtable
{
	public:
		int key;
		long int mob_no;		
	
};
class Hashing 
{
	Hashtable t[10];

	public:
		int i;
		Hashing()
		{
			for(i=0;i<10;i++)
			{
				t[i].key=i;
				t[i].mob_no=-1;
				
			}
		}
		void display();
		void insert(int prob_choice);
		int linear_prob(int colision_pos);
		int quad_prob(int colision_pos);
		int search(int x);	
}; 

int Hashing ::search(int x)
{

	for(i=0;i<10;i++)
	{
		if (t[i].mob_no==x)
			return i;
	}
	return -1;

}

int Hashing::linear_prob(int colision_pos)
{
	for(i=colision_pos;i<10;i++)
 	{

	 	if (t[i].mob_no==-1)
		{
			return i;
		}
		if (i==9)
		{
			i=-1;
		}
		
	}
	
}

int Hashing::quad_prob(int colision_pos)
{
	for(i=0;i<10;i++)
 	{
		int quad_tmp=((colision_pos+(i*i))%10);
		if (t[quad_tmp].mob_no ==-1)
		{
			return quad_tmp;
		}

	}

}	

void Hashing::display()
{
			cout<<"\n Hash Table :-"<<endl;
			cout<<"\n\tKey\tValue"<<endl;
			for(i=0;i<10;i++)
			{

				cout<<"\n\t"<<t[i].key<<"\t"<<t[i].mob_no<<endl;
			}
}
void Hashing::insert(int prob_choice)
{
	long int num;
	int position,col_pos;
	cout<<"\n\t Enter the mobile number :-";
	cin>>num;
	position=num%10;
	for (i=0;i<10;i++)
	{
		if(t[i].key==position)
		{
			if (prob_choice==1)
			{
				col_pos=position; 	
		 		int temp_pos=linear_prob(col_pos);
				t[temp_pos].mob_no=num;
				cout<<"\n \t Mobile number store at key "<< temp_pos <<endl;
		 		break;

			}
			else if (prob_choice==2)
			{
				col_pos=position; 	
		 		int temp_pos=quad_prob(col_pos);
				t[temp_pos].mob_no=num;
				cout<<"\n \t Mobile number store at key "<< temp_pos <<endl;
		 		break;

			}	
			else 
				cout << "\n \t Enter choice is invalid ! "<<endl;
		}
	}
}



int main()
{
	Hashing h;
	int ch,prob_choice;
	do{
		cout<<"\n \t Main Menu "<<endl;
		cout<<"\n \t 1: Insert Data "<<endl;
		cout<<"\n \t 2: Display Data "<<endl;
		cout<<"\n \t 3: Search Data "<<endl;
		cout<<"\n \t 4:Exit "<<endl;
		cout<<"\n \t Enter the choice :- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				
				cout<<"\n \t 1:Linear Probing "<<endl;
				cout<<"\n \t 2:Quadratic Probing "<<endl;
				cout<<"\n \t Enter the choice :- ";
				cin>>prob_choice;
				h.insert(prob_choice);
		
			break;
			
			case 2:
				h.display();
			break;
			
			case 3:
				int val,pos;
				cout<<"\n \t Enter the number :- ";
				cin>>val;
				pos=h.search(val);
				if (pos!=-1)
				{
					cout<<"\n \t Data successfully found at "<<pos<<" position"<<endl;
				}
				else
					cout<<"\n \t Data not found "<<endl;

			break;	
			
			case 4:
				cout<<"\n \t  End of programm...!";
			break;
			
			default :
				cout<<"\n \t Invalid Choice !"<<endl;	
		}		
	}while(ch!=4);
	
	return 0;
}


