#include<bits/stdc++.h>
using namespace std;

void printStars(int n) {
  for(int i = 0; i < n; i++)
    cout << "*****";
  cout << endl;
}


string upperToLower(string S) {
  for(auto i = S.begin(); i != S.end(); i++) {
    if(*i >= 65 && *i <= 90)
      *i += 32;
  }
  return S;
}

class Contact {
  string fname, lname, email, address, bday;
  vector<string> phone_numbers;

public:

  // Constructor 
  Contact(string fname, string lname, string pno, string email, string address, string bday) {
    this->fname = fname;
    this->lname = lname;
    this->phone_numbers.push_back(pno);
    this->email = email;
    this->address = address;
    this->bday = bday;
  }

  string getfName() {
    return fname;
  }

  string getlName() {
    return lname;
  }

  vector<string> getPNo() {
    return phone_numbers;
  }

  //  Updates Phone No.
  void updatePNo(string old_pno, string new_pno) {
    auto it = find(phone_numbers.begin(), phone_numbers.end(), old_pno);
    *it = new_pno;
  }
  
  // Add another Phone No.
  void addPhone(string pno){
    phone_numbers.push_back(pno);
  }

  // Prints All Details
  void printDetails(){
    cout << endl << "Name : " << fname << " " << lname << endl;
    cout << "Phone Number : ";
    for(auto pno : phone_numbers)
      cout << pno << ", ";
    cout << endl;
    cout << "E-Mail : " << email << endl;
    cout << "Address : " << address << endl;
    cout << "Birthday : " << bday << endl;
    cout << endl; 
  }
};



class Node{

public:
  char data;
  map<char, Node*> children;
  Contact* person;  // acts as bool terminal

  Node(char d){
    data = d;
    person = NULL;
  }
};

class Trie{
  Node* root;
  int count;

public:
  Trie() { 
    root = new Node('\0');
    count = 0;
  }

// insert new contact in trie 1
  Contact* insert(string fname, string lname, string pno, string email, string address, string bday) {
    string w = fname + lname;
    w = upperToLower(w);
    Node* temp = root;
    for(auto ch : w) {
      if(temp->children.count(ch)){
        temp = temp->children[ch];
      }
      else{
        Node* n = new Node(ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->person = new Contact(fname, lname, pno, email, address, bday);
    return temp->person;
  }

  // print all contacts below current root
  void printAllBelow(Node* root){
    if(root == NULL) root = this->root; 

    if(root->person) root->person->printDetails();

    for(auto pair : root->children){
      if(pair.second) printAllBelow(pair.second);
    }
  }

  // find users with given string as prefix
  void find(string w){
    Node* temp = root;
    w = upperToLower(w);
    for(auto ch : w){
      if(temp->children.count(ch) == 0) {
        cout << endl << "# Contact Not Found #" << endl;
        return;
      }
      else 
        temp = temp->children[ch];
    }
    printAllBelow(temp);
    // if(temp->person != NULL) temp->person->printDetails();
  }

  // Update Phone Number Function
  Contact* update(string w1, string w2, string old_pno, string new_pno) {
    string w = w1 + w2;
    w = upperToLower(w);
    Node* temp = root;
    for(auto ch : w){
      if(temp->children.count(ch) == 0) {
        cout << endl << "# Contact Does not Exist!! #" << endl;
        return NULL;
      }
      else temp = temp->children[ch];        
    }
    if(temp->person) temp->person->updatePNo(old_pno, new_pno);

    return temp->person;
  }

  // add new phone number
  Contact* addPhoneNumber(string w1, string w2, string new_pno) {
    string w = w1 + w2;
    w = upperToLower(w);
    Node* temp = root;
    for(auto ch : w) {
      if(temp->children.count(ch) == 0){
        cout << endl << "# Contact Does not Exist!! #" << endl;
        return NULL;
      }
      else temp = temp->children[ch];        
    }
    if(temp->person) temp->person->addPhone(new_pno);

    return temp->person;
  }

// delete contact function
  void deleteContact(string w){
    Node* temp = root;
    w = upperToLower(w);
    for(auto ch : w){
      if(temp->children.count(ch) == 0) {
        cout << endl << "# Contact Not Found!! #" << endl;
        return;
      }
      else 
        temp = temp->children[ch];
    }
    if(temp->person != NULL){
      Contact *t = temp->person;
      temp->person = NULL;
      delete t;
    }
  }  
};



class Trie2 {
  Node* root;
  int count;

public:

  Trie2() {
    root = new Node('x');
    count = 0;
  } 

  // insert contact in trie 2
  void insert(string pno, Contact* s) {
    string w = pno;
    Node* temp = root;
    for(auto ch : w) {
      if(temp->children.count(ch))
        temp = temp->children[ch];
      else {
        Node* n = new Node(ch);
        temp->children[ch] = n;
        temp = n;
      }
    }
    temp->person = s;
  }


  // print all contacts below current root
  void printAllBelow(Node *root){
    if(root->person)
      root->person->printDetails();

    for(auto pair : root->children){
      if(pair.second)
        printAllBelow(pair.second);
    }
    // cout << "# No More Contacts exists!! #" << endl;
  }

  void print(Node *root){
    if(root->person)
      root->person->printDetails();
  }

  // find contact with current phone number as prefix
  void find(string w) {
    Node* temp = root;
    for(auto ch : w) {
      if(temp->children.count(ch) == 0) {
        cout << endl << "# Contact Does Not Exits!! #" << endl;
        return;
      }
      else{
        temp = temp->children[ch];
      }
    }
    printAllBelow(temp);
    // if(temp->person != NULL){
    //   temp->person->printDetails();
    // }
  }

  bool isEmpty(Node* root) 
  { 
    for (int i = 0; i < 10; i++) 
      if (root->children[i]) 
        return false; 
    return true; 
  } 

  // remove old phone number while updating
  void breakLink(string w){
    Node *temp = root;
    for(auto ch : w){
      if(temp->children.count(ch) == 0){
        cout<<"# Contact Not Found!! #"<<endl;
        return;
      }
      else{
        temp = temp->children[ch];
      }
    }
    temp->person = NULL;
  }

  void update(string oldNo, string newNo, Contact *s){
      // first break the link of contact from leaf of old phone number
      breakLink(oldNo);
      // insert new phone number
      insert(newNo, s);
   }

   // delete contact function
  string deleteContact(string pno){
    Node* temp = root;
    string w;
    for(auto ch : pno) {
      if(temp->children.count(ch) == 0) {
        cout << endl << "Contact Not Found" << endl;
        return "none";
      }
      else {
        temp = temp->children[ch];
      }
    }
    if(temp->person != NULL) {
      w = temp->person->getfName() + temp->person->getlName();
      temp->person = NULL;
      return w;
    }
    else {
      return "none";
    }
      
   }      
};


// integration of trie 1 and trie 2 together
class ContactBook {
  Trie T;
  Trie2 T2;

public:

  void insert(string fname, string lname, string pno, string email, string address, string bday) {
    Contact *x = T.insert(fname, lname, pno, email, address, bday);
    T2.insert(pno, x);
  }

  void update(string fname, string lname, string oldpno, string newpno) {
    Contact *x = T.update(fname, lname,oldpno, newpno);
    T2.update(oldpno, newpno, x);
  }

  void findByName(string w) {
    T.find(w);
  }

  void findByPhoneNumber(string w) {
    T2.find(w);
  }

  void addPhoneNumber(string fname, string lname, string pno) {
    Contact *x = T.addPhoneNumber(fname, lname, pno);
    if(x != NULL){
      T2.insert(pno, x);
    }
  }

  void printAllContacts(){
    T.printAllBelow(NULL);
  }

  void deleteContact(string pno){
    string w = T2.deleteContact(pno);
    if(w != "none"){
      T.deleteContact(w);
    }
    
  }
};

// users class for login functionality
class Users{
	map<string, string> users;
	bool loggedIn;

	

public:

  Users() {
		loggedIn = false;
	}

	bool isLoggedIn(){
		return loggedIn;
	}

	void login(){
		string uname, pwd;
    cout<<endl;
		cout<<"Username: ";
		cin>>uname;
		cout<<"Password: ";
		cin>>pwd;
    cout<<endl;
		if(users.find(uname)!=users.end() and users[uname]==pwd){ 
			cout<<"User Logged In Successfully"<<endl;
			loggedIn = true;
		}
		else{
			cout<<"Invalid Credentials";
		}
	}

	void signup(){
		string uname, pwd;
		cout<<"Username: ";
		cin>>uname;
		cout<<"Password: ";
		cin>>pwd;
		if(users.find(uname)!=users.end()){
			cout<<"User exists"<<endl;
		} else{
      users[uname] = pwd;
			cout<<"User Registered Successfully"<<endl;
		}
	}

	void logout(){
		loggedIn = false;
	}
};


// Driver Code
int main() {

  ContactBook contactBook;
  Users users;


  // default contacts
  contactBook.insert("Paras", "Aghija", "9999988888", "aghija.paras@gmail.com", "Delhi", "19 August");
  contactBook.insert("Knupriya", "Marwaha", "7777788888", "kp@gmail.com", "Faridabad", "23 June"); 
  contactBook.insert("shubham", "Garg", "7777766666", "shubhamg@gmail.com", "Noida", "9 August");
  contactBook.insert("Abhinandan", "Jain", "5555566666", "abhinandanjain@gmail.com", "Delhi", "9 August");
  printStars(5);
  cout << " \t\tPHONEBOOK " << endl;
  printStars(5);

  // menu driven program
  while(1){
  	if(users.isLoggedIn()){
  		int opt;
	    cout << endl << "=> Features:\n 1 - Add Contact \n 2 - Add another Phone Number for a Contact \n 3 - Delete Contact \n 4 - Search Contact \n 5 - Update Contact \n 6 - All Contacts \n 7 - Logout" << endl;
	    cout << "Enter your Choice: ";
	    cin >> opt;

	    switch(opt) {
	      case 1: { // Contact Addition
	        string cont[6];
	        cout << endl << "\tEnter First Name: ";
	        cin >> cont[0];
	        cout << "\tEnter Last Name: ";
	        cin >> cont[1];
	        cout << "\tEnter Phone Number: ";
	        cin >> cont[2];
          while(cont[2].length()!=10){
            cout<<endl<<"Phone Number should be of 10 digits"<<endl;
            cout << "\tEnter Phone Number: ";
	          cin >> cont[2];
          }
	        cout << "\tEnter E-Mail: ";
	        cin >> cont[3];
	        cout << "\tEnter Address: ";
	        cin >> cont[4];
	        cout << "\tEnter Birthday: ";
	        cin.ignore();
	        getline(cin, cont[5]);
	        contactBook.insert(cont[0], cont[1], cont[2], cont[3], cont[4], cont[5]);
	        cout << endl << "Contact Created Successfully!!" << endl;
	        break; 
	      }

	      case 2: {
	        string findCont_fname,findCont_lname, newPno;
	        cout << endl << "\tEnter First Name of Contact: ";
	        cin >> findCont_fname;
	        cout << "\tEnter Last Name of Contact: ";
	        cin >> findCont_lname;

	        cout << "\tEnter another Phone Number: ";
	        cin >> newPno;

          while(newPno.length()!=10){
            cout<<endl<<"Phone Number should be of 10 digits"<<endl;
            cout << "\tEnter another Phone Number: ";
	          cin >> newPno;
          }

	        contactBook.addPhoneNumber(findCont_fname, findCont_lname, newPno);
	        cout << endl << "Phone Number added to Contact Successfully!" << endl;
	        break;
	      }

	      case 3: { // Contact Deletion
	        string Pno;
	        cout << endl << "\tEnter the Phone Number of Contact: ";
	        cin >> Pno;

          while(Pno.length()!=10){
            cout<<endl<<"Phone Number should be of 10 digits"<<endl;
            cout << "\tEnter Phone Number: ";
	          cin >> Pno;
          }
	        
	        contactBook.deleteContact(Pno);
	        cout << endl << "Contact deleted Successfully!" << endl;
	        // contactBook.printAllContacts();
	        break;
	      }

	      case 4: { // Search Contact
	        int ch;
	        cout << endl << "\t1 - Search by Name\n\t2 - Search by Phone Number\n\tEnter your choice: ";
	        cin >> ch;
	        if(ch == 1) {
	          string findCont_name;
	          cout << endl << "\tEnter Name of Contact: ";
	          cin >> findCont_name;
	          cout << endl;
	          contactBook.findByName(findCont_name);
	        }
	        else if(ch == 2) {
	          string findCont_pno;
	          cout << endl << "\tEnter Phone Number of Contact: ";
	          cin >> findCont_pno;
	          contactBook.findByPhoneNumber(findCont_pno);
	        }
	        break;
	      }

	      case 5: { // Contact Updation
	        string findCont_fname,findCont_lname, oldPno, newPno;
	        cout << endl << "\tEnter First Name of Contact: ";
	        cin >> findCont_fname;
	        cout << "\tEnter Last Name of Contact: ";
	        cin >> findCont_lname;

	        cout << "\tEnter Old Phone Number: ";
	        cin >> oldPno;
          while(oldPno.length()!=10){
            cout<<endl<<"Phone Number should be of 10 digits"<<endl;
            cout << "\tEnter Old Phone Number: ";
	          cin >> oldPno;
          }
	        cout << "\tEnter New Phone Number: ";
	        cin >> newPno;
          while(newPno.length()!=10){
            cout<<endl<<"Phone Number should be of 10 digits"<<endl;
            cout << "\tEnter New Phone Number: ";
	          cin >> newPno;
          }
	        contactBook.update(findCont_fname, findCont_lname, oldPno, newPno);       
	        cout << endl << "Contact Updated Successfully!" << endl; 
	        // contactBook.findByName(findCont_fname);
	        break;
	      }

	      case 6: { // Display All Contacts
	        contactBook.printAllContacts();
	        break;
	      }

	      case 7: { // Logout Function
	        cout << endl << "Logging Out!!" << endl;
	        users.logout();        
	        break;
	      }

	      default: {
	        cout << "Enter a Valid Option";
	        break;
	      }
	    }
  	} else{
  		int c=-1;
  		cout<<endl<<"1. Login";
  		cout<<endl<<"2. Signup";
  		cout<<endl<<"3. Exit";
  		cout<<endl;
  		cout<<"Enter choice: ";
      cin>>c;

  		switch(c){
  			case 1: {
  				users.login();
  				break;
  			}
  			case 2: {
  				users.signup();
  				break;
  			}
  			case 3: {
  				cout << endl << "Thank You!!" << endl;
        		exit(0);
        		break;
  			}
  			default: {
  				cout << "Enter a Valid Option";
        		break;
  			}
  		}
  	}
  }


  return 0;
}
