#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// structure for each item

struct Item{
	string Name;
	int quantity;
	double price;
	double total;
};
 int main() {
 	Item cart[100];
 	int itemCount = 0;
 	double grandTotal = 0.0;
 	int Choice;
 	
 	cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: \n";
 	cout<<"----------------THIS IS A MINI POS SYSTEM-------------------- \n";
 	cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: \n";
 	
 	while(true){
 		//Menu options
 		cout<<"\n 1. Add Item \n";
 		cout<<"\n 2. View Reciepts \n";
 		cout<<"\n 3. Exit  \n";
 		cout<<"Select An Option :";
 		cin>> Choice;
 		
 		if(cin.fail()){
 			cin.clear();
 			cin.ignore(numeric_limits<streamsize>::max(),'\n');
 			cout<<"Invalid Input! \n";
 			continue;
		 }
		 
		 //ADDING THE OPTION MENU
		 //OPTION 1 ADD ITEMS:
		 
		 if (Choice==1){
		 	if(itemCount >=100){
		 		cout<<"Cart is full \n";
		 		continue;
			 }
			 cin.ignore(); //clear buffer
			 cout<<"Enter item name :";
			 getline(cin,cart[itemCount].Name);
			 
			 //QUANTITY VALIDATION
			 while(true){
			 	cout<<"Enter Quantity:";
			 	cin>>cart[itemCount].quantity;
			 	
			 	if(cin.fail() || cart[itemCount].quantity <=0 ){
			 		cout<<"Invalid Quantity! \n";
			 		cin.clear();
			 		cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 } else break;	
			 }
			 
			 //price validation
			 while(true){
			 	cout<<"Enter price :";
			 	cin>>cart[itemCount].price;
			 	
			 	if (cin.fail() || cart[itemCount].price <= 0) {
			 		cout<<"Invalid price! \n";
			 		cin.clear();
			 		cin.ignore(numeric_limits<streamsize>::max(),'\n');
				 } else break;
			  }
			 
			 //calculating the total
            cart[itemCount].total = cart[itemCount].quantity * cart[itemCount].price;
            grandTotal += cart[itemCount].total;
			 
			 cout<<"Item added successfully! \n";
			 itemCount++;	 
		 }
		 
		//-------------------------------
		//OPTION 2 SECTION: VIEW RECEIPT
		//-------------------------------
		else if (Choice==2) {
			if(itemCount==0){
				cout<<"No items in cart! \n";
				continue;
			} 
			cout<<fixed<<setprecision(2);
			
			cout<<"\n::::::::::::::::::::::::::::::::::::::::::\n";
			cout<<"                  RECEIPT                   \n";
			cout<<"::::::::::::::::::::::::::::::::::::::::::::\n";
			 
			 for (int i = 0; i<itemCount; i++) {
			 	cout<<"Item:"<<cart[i].Name <<"\n";
			 	cout<<"Qty:"<<cart[i].quantity <<"\n";
			 	cout<<"Price:$"<<cart[i].price<<"\n";
			 	cout<<"Total:$"<<cart[i].total<<"\n";
			 	cout<<"--------------------------\n";	
			 }
			 
			 cout<<"GRAND TOTAL:$"<<grandTotal<<"\n";
			 cout<<"=============================\n";		
		}
		
		//==========================================================
		//OPTION 3: EXIT MENU 
		//==========================================================
		else if(Choice==3){
			cout<<"THANK YOU FOR USING THE POS SYSTEM! \n";
			break;
		}
		
		else{
			cout<<"Invalid Option.Try again. \n";
		}				 		 
	 }
 	 	
 return 0;	
 }