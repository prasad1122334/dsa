#include<iostream>
using namespace std;
class Set
{
	
	int set[20],n;
	public:
		
		Set() {n=0;}
		void add();
		void display();
		void remove(int x);
		int search(int x);
		void set_union(Set &s1,Set &s2);
        void set_intersection(Set &s1,Set &s2);
        void set_difference(Set &s1,Set &s2);
        void set_subset(Set &s1,Set &s2);

};
void Set::set_subset(Set &s1,Set &s2)
{
    n=0;
    int cnt=0,cnt1=0;
    for (int i = 0; i < s1.n ; i++) 
    {
        for(int j = 0; j < s2.n; j++)
        {
            if (s1.set[i] == s2.set[j])
            {
                set[n++] = s1.set[i];
                break;
            }
        }
    }
    if (n == s1.n)
    {
        cout<<"\n A is subset of B :-";
        display();
    }
    else if (n == s2.n)
    {
        cout<<"\n B is subset of A :-";
        display();
    }
    else 
    {
        cout<<"\n There is subset not found. ";
    }
    
}
void Set::set_difference(Set &s1,Set &s2)
{
    n=0;
    for (int i = 0; i < s1.n ; i++) 
    {
        int flag= 0;
        for(int j = 0; j < s2.n; j++)
        {
            if (s1.set[i] == s2.set[j])
            {
                flag=1;
                break;
            }
        }
        if (flag == 0)									
        {
            set[n++] = s1.set[i];
        }
    }
    cout << "\nDifference of two sets: ";
    display();
}
void Set::set_intersection(Set &s1,Set &s2)
{
    n=0;
    for (int i = 0; i < s1.n ; i++) 
    {
        for(int j = 0; j < s2.n; j++)
        {
            if (s1.set[i] == s2.set[j])
            {
                set[n++] = s1.set[i];
                break;
            }
        }
    }
    cout << "\nIntersection of two sets: ";
    display();
}
void Set::set_union(Set &s1,Set &s2) 
{
    n=0;
    for (int i = 0; i < s1.n; i++)
    {
        set[i] = s1.set[i];
        n++;
    }
    for (int i = 0; i < s2.n; i++) 
    {
        if (search(s2.set[i]) == -1) 
        {
            set[n++] = s2.set[i];
        }
    }
    cout << "\nUnion of two sets: ";
    display();
}
void Set::remove(int x)
{
	int ele = search(x);
	if (ele != -1) 
	{
		for (int j = ele; j < n - 1; j++)
		{
			set[j] = set[j + 1];
		}
		n--;
		cout << "\nElement " << x << " removed successfully.";
	}
	else 
	{
	cout << "\nElement not found in the set.";
	}
}
void Set::add()
{
	cout<<"\n Enter the "<<n<<" element:-";
	cin>>set[n];
	n++;
}
void Set::display()
{
	if (n!=0)
	{
		for (int i=0;i<n;i++)
		{
			cout<<"\t"<<set[i];
		}

		cout<<"\n";
	}
	else
	cout<<"\n Set is empty";

}
int Set::search(int x)
{
	for (int i =0;i<n;i++)
	{
		if (x==set[i])
			return i;
	}
	return -1;
}
int main()
{
	Set s1,s2,s3;
	int ch,element;
	do
	{
		cout << "\n1: Enter an element";
		cout << "\n2: Display elements";
		cout << "\n3: Remove an element";
		cout << "\n4: Search for an element";
		cout<<  "\n5: Union of set ";
        cout<<  "\n6: Intersection of set ";
        cout<<  "\n7: Difference of set ";
        cout<<  "\n8: Subset of set ";
		cout << "\n9: Exit";
		cout << "\nEnter your choice:- ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				int ch1;
				cout<<"\n 1:Add element in set A";
				cout<<"\n 2:Add element in set B";
				cout << "\nEnter your choice:- ";
				cin>>ch1;
				switch(ch1)
				{
					case 1:
						s1.add();
						break;
					case 2:
						s2.add();
						break;
                    default:
                        cout<<"\nInvalid choice";	
				}
				
			break;
			case 2:
				int ch2;
				cout<<"\n 1:Display element in set A";
				cout<<"\n 2:Display element in set B";
				cout << "\nEnter your choice:- ";
				cin>>ch2;
				switch(ch2)
				{
					case 1:
						s1.display();
						break;
					case 2:
						s2.display();
						break;
                    default:
                        cout<<"\nInvalid choice";	
				}
				
			break;

			case 3:
				int ch3;
				cout<<"\n 1:Remove element in set A";
				cout<<"\n 2:Remove element in set B";
				cout << "\nEnter your choice:- ";
				cin>>ch3;
				switch(ch3)
				{
					case 1:
						cout << "\nEnter the element to remove: ";
						cin >> element;
						s1.remove(element);
						break;
					case 2:
						cout << "\nEnter the element to remove: ";
						cin >> element;
						s2.remove(element);
						break;
                    default:
                        cout<<"\nInvalid choice";
				}
				
			break;

			case 4:
				int ch4,pos;
				cout<<"\n 1:Search element in set A";
				cout<<"\n 2:Search element in set B";
				cout << "\nEnter your choice:- ";
				cin>>ch4;
				
				switch(ch4)
				{
					case 1:
						cout << "\nEnter the element to search: ";
						cin >> element;
						pos= s1.search(element) ;
						if ( pos != -1) 
						{
						cout << "\nElement " << element << " found in the set at "<< pos;
						} 
						else
						{
						cout << "\nElement " << element << " not found in the set ";
						}
						break;
					case 2:
						cout << "\nEnter the element to search: ";
						cin >> element;
						pos= s2.search(element) ;
						if ( pos != -1) 
						{
						cout << "\nElement " << element << " found in the set at "<< pos;
						} 
						else
						{
						cout << "\nElement " << element << " not found in the set ";
						}
						break;
                    default:
                        cout<<"\nInvalid choice";
				}
			break;
			case 5:
					s3.set_union(s1,s2);
                    
			break;
            case 6:
					s3.set_intersection(s1,s2);
                   
			break;
            case 7:
				int ch5;
				cout<<"\n 1:Difference between set A & B";
				cout<<"\n 2:Difference between set B & A ";
				cout << "\nEnter your choice:- ";
				cin>>ch5;
				switch(ch5)
				{
					case 1:
						s3.set_difference(s1,s2);
                        
						break;
					case 2:
						s3.set_difference(s2,s1);
                       
						break;
                    default:
                        cout<<"\nInvalid choice";
				}
                    
			break;
            case 8:
					s3.set_subset(s1,s2);
                    
			break;
			case 9:

			break;		
            default:
                cout<<"\nInvalid choice";		
		}	
	}while(ch!=9);
	return 0;
}

