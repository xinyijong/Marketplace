#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

/******************************
TMT2673 GO1 (MC) - Group 13
Hendriyan Bin Yusof(84001)
Jong Xin Yi (84169)
Mohd Aiman Bin Baharin (84588)
Muhammad Ghassani Bin Ibrahim (84688)
Aleessya Almaz Binti Razali (86269)
****************************/

/******************************
Class User
Implemented by Jong Xin Yi (84169)
****************************/
//Superclass
class User{
private:
	//Encapsulation
    string email;
    string password;
    string role;
    string name;
    string contactDetails;
    string bio;
    int index;

public:
	//Getter
    string getEmail(){
        return email;
    }

    string getPwd(){
        return password;
    }

    string getUserRole(){
        return role;
    }

    string getName(){
        return name;
    }

    string getContact(){
        return contactDetails;
    }

    string getBio(){
        return bio;
    }

    int getIndex(){
        return index;
    }
	
	//Setter
    void setEmail(string Email){
        email=Email;
    }

    void setPwd(string Pwd){
        password=Pwd;
    }

    void setUserRole(string userRole){
        role=userRole;
    }

    void setName(string Name){
        name=Name;
    }

    void setContact(string Contact){
        contactDetails=Contact;
    }

    void setBio(string Bio){
        bio=Bio;
    }

    void setIndex(int Index){
        index=Index;
    }

    void createUser(string email, string password, string role, string name, string contact, string bio, int index){
        setEmail(email);
        setPwd(password);
        setUserRole(role);
        setName(name);
        setContact(contact);
        setBio(bio);
        setIndex(index);
    }

    void displayDetail(){
    	cout << "--------------------------------\n";
        cout << "Name: " << getName() << endl;
        cout << "Contact number: " << getContact() << endl;
        cout << "Bio: " << getBio() << endl;
        cout << "Role: " << getUserRole() << endl;
        cout << "--------------------------------\n\n";
    }
	
    void manageProfile(){
        string name, contact, bio;
        int manage;
        cout << "\n"<<getName()<<"'s Profile\n";
        displayDetail();
		
		cout<<"Do you want to update your profile? (1: Yes, 2: No): ";
		cin>>manage;
		cin.ignore();
		while(manage!=1){
			if(manage==2){
				cout<<"You choose to not update your profile.\n\n";
				return;
			}
			if(manage<1 || manage>2){
				cout<<"Invalid choice. Please try again.\n\n";
				cout<<"Do you want to update your profile? (1: Yes, 2: No): ";
				cin>>manage;
				cin.ignore();
				cout<<endl;
			}
		}
        cout << "\n=== Update Profile ===\n";

        cout << "Update your name: ";
        getline(cin, name);
        while(name.empty()){
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Update your name: ";
            getline(cin, name);
        }
        setName(name);

        cout << "Update your contact number: ";
        getline(cin, contact);
        while(contact.empty() || contact.length()!=10 && contact.length()!=11){
            if (contact.empty()){
                cout << "Required field, please do not leave blank.\n\n";
                cout << "Update your contact number: ";
                getline(cin, contact);
            }

            if (contact.length()!=10 && contact.length()!=11){
                cout << "Contact number must have 10 digits or 11 digits.\n\n";
                cout << "Update your contact number: ";
                getline(cin, contact);
            }
        }
        setContact(contact);

        cout << "Update your bio: ";
        getline(cin, bio);
        while(bio.empty()){
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Update your bio: ";
            getline(cin, bio);
        }
        setBio(bio);

        cout << "\nProfile updated successfully.\n\n";
    }
};

/******************************
Class HomemadeListing
Implemented by Muhammad Ghassani Bin Ibrahim (84688)
****************************/
class HomemadeListing{
private:
    string title;
    string description;
    float price;
    int artisanIndex;

public:
	//Constructor
    HomemadeListing(string Title, string desc, float Price, int Index){
        title=Title;
        description=desc;
        price=Price;
        artisanIndex=Index;
    }
    
	int getArtisanIndex(){
        return artisanIndex;
    }
	
    string getTitle(){
        return title;
    }

    string getDesc(){
        return description;
    }

    float getPrice(){
        return price;
    }

    void setTitle(string newTitle){
        title=newTitle;
    }

    void setDescription(string newDesc){
        description=newDesc;
    }

    void setPrice(float newPrice){
        price=newPrice;
    }

};

/******************************
Class JobAdvertisement
Implemented by Jong Xin Yi (84169)
****************************/
class JobAdvertisement{
private:
	//Encapsulation
    string title;
    string description;
    string location;
    float payment;
    string contactDetail;
    int providerIndex;

public:
	//Constructor
    JobAdvertisement(string Title, string desc, string Location, float Payment, string contact, int Index){
        title=Title;
        description=desc;
        location=Location;
        payment=Payment;
        contactDetail=contact;
        providerIndex=Index;
    }
	
	//Getter
    string getTitle(){
        return title;
    }

    string getDesc(){
    	return description;
    }

    string getLocation(){
        return location;
    }

    float getPayment(){
        return payment;
    }

    string getContact(){
        return contactDetail;
    }
    
    int getProviderIndex(){
        return providerIndex;
    }
	
	//Setter
    void setTitle(string newTitle){
        title=newTitle;
    }

    void setDescription(string newDesc){
        description=newDesc;
    }

    void setLocation(string newLocation){
        location=newLocation;
    }

    void setPayment(float newPayment){
        payment=newPayment;
    }
    
    void setContact(string newContact){
        contactDetail=newContact;
    }
};

int totalP=0;
int totalS=0;
int totalA=0;
int totalC=0;

int indexP=0;
int indexS=0;
int indexA=0;
int indexC=0;

vector<HomemadeListing> homemade; //hold instances of the HomemadeListing class
vector<JobAdvertisement> jobPostings;

/******************************
Class Artisan
Implemented by Mohd Aiman Bin Baharin (84588)
****************************/
//Inheritance
class Artisan:public User{
private:
	 int numOfProduct;
	 
public:
	//Constructor with default value
	//overriding
	Artisan(){
		createUser("charlie@outlook.com", "charlie55", "Artisan", "Charlie", "0176625419", "Skilled in woodworking", 0);
	}
	
	int getNumOfProduct(){
    	return numOfProduct;
    }
	
	void setNumOfProduct(int num){
        numOfProduct=num;
    }
	
	//association
    void listHomemadeListing(string title, string description, float price, int index){
        HomemadeListing product(title, description, price, index); //create new HomemadeListing object
        homemade.push_back(product); //add into vector
    }

    void postProduct(){
        string title, description;
        float price;
		
		cout<<"\n=== List Homemade Product ===";
		
        cout << "\nEnter product title: ";
        getline(cin, title);
        while(title.empty()){
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Enter product title: ";
            getline(cin, title);
        }
        cout << "Enter product description: ";
        getline(cin, description);
        while (description.empty()){
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Enter product description: ";
            getline(cin, description);
        }
        cout << "Enter product price: ";
        cin >> price;
        cin.ignore();
        while (price<=0){
            cout << "Invalid price, please input the valid price.\n\n";
            cout << "Enter product price: ";
            cin >> price;
            cin.ignore();
    	}
     	int artisanIndex=getIndex();
        listHomemadeListing(title, description, price, artisanIndex); 
        
		cout << "\nHomemade product listed successfully. \n";
		displayHomemadeListing();
    }

	bool displayHomemadeListing(){
	    int count=0;
	    int check=homemade.size();
		bool found=false;
	    if (check==0) {
	        cout << "\nNo homemade product listed.\n\n";
	        return false;
	    }else{
	    	cout << "\nYour listed homemade product: \n";
	        cout << left << setw(10) << "\nID" << setw(20) << "Product Title" << setw(30) << "Product Description" << setw(15) << "Product Price" << endl;
	        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
			for(auto& product : homemade){
	            // Check if the homemade product listing is associated with the current artisan
				if(getIndex() == product.getArtisanIndex()){
	                count++;
	                cout << left << setw(10) << count
	                     		 << setw(20) << product.getTitle()
	                     		 << setw(30) << product.getDesc()
	                     		 << setw(3) << fixed << setprecision(2) << "RM" << product.getPrice()
	                     << endl;
	                found=true;
	            }
	        }
	        setNumOfProduct(count);
	        cout<<"\n";
	    }
	
	    if (!found){
	        cout << "\nNo homemade product listed.\n\n";
	    }
	    return found;
	}
    
    void updateHomemadeListing(){
    	int count=0, i;
    	int check=homemade.size();
    	for (auto& product : homemade){
    		if(getIndex() == product.getArtisanIndex()){
        		count = getNumOfProduct();
        		break;  
    		}
		}
        int productNum;
        string title, desc;
        float price;
        if (check==0){
            cout << "\nNo homemade product listed.\n\n";
        }else{
            if(displayHomemadeListing()==true){
            	cout << "Enter product ID you want to update: ";
            	cin >> productNum;
            	cin.ignore();
            	if (productNum >= 1 && productNum <= count) {
                	auto it = homemade.begin(); //Declares an iterator it and initializes it to the beginning of the homemade vector
                	i=1;
					while(i<productNum) 
					{
						++it;
						++i;
					}
        			auto &product = *it; //Creates a reference product to the product in the vector pointed to by the iterator

                	cout << "\n=== Update Homemade Product Details ===\n";

                	string title, desc;
                	float price;

                	cout << "Update product title: ";
               	 	getline(cin, title);
                	while (title.empty()) {
                    	cout << "Required field, please do not leave blank.\n\n";
                    	cout << "Update product title: ";
                    	getline(cin, title);
                	}
                	product.setTitle(title);

	                cout << "Update product description: ";
	                getline(cin, desc);
	                while (desc.empty()) {
	                    cout << "Required field, please do not leave blank.\n\n";
	                    cout << "Update product description: ";
	                    getline(cin, desc);
	                }
	                product.setDescription(desc);

	                cout << "Update product price: ";
	                cin >> price;
	                cin.ignore();
	                while (price<= 0) {
	                    cout << "Invalid price, please input the valid price.\n\n";
	                    cout << "Update product price: ";
	                    cin >> price;
	                    cin.ignore();
	                }
	                product.setPrice(price);

                	cout << "\nHomemade product details updated successfully.\n\n";
            	} else {
                	cout << "Invalid homemade product ID.\n\n";
            	}
			}
            
        }
    }
    
    void removeHomemadeListing(){
    	int count=0, i, confirm;
    	int check=homemade.size();
    	for (auto& product : homemade){
    		if (getIndex() == product.getArtisanIndex()) {
        		count = getNumOfProduct();
        		break;  
    		}
		}
        int productNum;
        string title, desc;
        float price;
        if (check == 0) {
            cout << "\nNo homemade product listed.\n\n";
        } else {
            if(displayHomemadeListing()==true){
            	cout << "Enter product ID you want to remove: ";
            	cin >> productNum;
            	cin.ignore();
            	if (productNum >= 1 && productNum <= count) {
                	auto it = homemade.begin();
                	i=1;
					while(i<productNum)
					{
						++it;
						++i;
					}
        			int vectorIndex = distance(homemade.begin(), it);//get the index of the selected product in the vector
        			cout<<"\nDo you confirm to remove the homemade product? (1: Yes, 2: No): ";
					cin>>confirm;
					cin.ignore();
					while(confirm!=1){
						if(confirm==2){
							cout<<"You choose to not remove the homemade product.\n\n";
							return;
						}
						if(confirm<1 || confirm>2){
							cout<<"Invalid option. Please try again.\n\n";
							cout<<"Do you confirm to remove the homemade product? (1: Yes, 2: No): ";
							cin>>confirm;
							cin.ignore();
							cout<<endl;
						}
					}
                	homemade.erase(it); //delete the selected product in vector
                	count--;
				
					cout<<"Homemade product is removed successfully.\n\n";
            	} else {
                	cout << "Invalid homemade product ID.\n\n";
            	}
			}
        }
    }
};

/******************************
Class JobProvider
Implemented by Aleessya Almaz Binti Razali (86269)
****************************/
class JobProvider : public User {
private:
	int numOfJob;
	
public:
	int getNumOfJob(){
    	return numOfJob;
    }
	
	void setNumOfJob(int num){
        numOfJob=num;
    }
	
	JobProvider(){
		createUser("sariel@outlook.com", "sariel77", "Job Provider", "Sariel", "0128874621", "Experienced in IT", 0);
	}
	
	//association
    void postJobAdvertisement(string title, string description, string location, float payment, string contact, int index) {
        JobAdvertisement job(title, description, location, payment, contact, index);
        jobPostings.push_back(job);
    }
    
    void postJobPosting() {
        string title, description, location, contact, index;
        float payment;
		cout << "\n=== Post New Job ===";
        cout << "\nEnter job title: ";
        getline(cin, title);
        while (title.empty()) {
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Enter job title: ";
            getline(cin, title);
        }
        cout << "Enter job description: ";
        getline(cin, description);
        while (description.empty()) {
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Enter job description: ";
            getline(cin, description);
        }
        cout << "Enter job location: ";
        getline(cin, location);
        while (location.empty()) {
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Enter job location: ";
            getline(cin, location);
        }
        cout << "Enter contact number: ";
        getline(cin, contact);
        while (contact.empty() || contact.length() != 10 && contact.length() != 11) {
            if (contact.empty()) {
                cout << "Required field, please do not leave blank.\n\n";
                cout << "Enter contact number: ";
                getline(cin, contact);
            }

            if (contact.length() != 10 && contact.length() != 11) {
                cout << "Contact number must have 10 digits or 11 digits.\n\n";
                cout << "Enter contact number: ";
                getline(cin, contact);
            }
        }
        cout << "Enter job payment: ";
        cin >> payment;
        cin.ignore();
        while (payment <= 0) {
            cout << "Invalid payment, please input the valid payment.\n\n";
            cout << "Enter job payment: ";
            cin >> payment;
            cin.ignore();
        }
		
		int providerIndex=getIndex();
        postJobAdvertisement(title, description, location, payment, contact, providerIndex);
        cout << "\nJob posted successfully."
             << endl;
        displayJobPostings();
	}
    
	bool displayJobPostings() {
	    int count = 0;
	    int check = jobPostings.size();
		bool found=false;
	    if (check == 0) {
	        cout << "\nNo job is posted.\n\n";
	        return false;
	    }else{
	    	cout << "\nYour posted job: \n";
			cout << left << setw(10) << "\nID" << setw(20) << "Job Title" << setw(25) << "Job Description" << setw(20) << "Job Location" << setw(20) << "Job Contact" << setw(20) << "Job Payment"<< endl;
			cout << setfill('-') << setw(105) << "-" << setfill(' ') << endl;
	    	for (auto& job : jobPostings) {
	
		        // Check if the job posting is associated with the current job provider
			    if (getIndex() == job.getProviderIndex()) {
			        count++;
			           	cout << left << setw(10) << count
				            		 << setw(20) << job.getTitle()
				               		 << setw(25) << job.getDesc()
				             		 << setw(20) << job.getLocation()
				             		 << setw(20) << job.getContact()
				             		 << setw(3) << "RM" << fixed << setprecision(2) << job.getPayment()
				             << endl;
			
			                 found=true;
			        }
			}
			cout<<"\n";
			setNumOfJob(count);
	    }
	
	    	if (!found) {
	        	cout << "No job is posted.\n\n";
	    	}
	    	return found;
	}

    void updateJobPosting() {
    	int count=0, i;
        int check = jobPostings.size();
        for (auto& job : jobPostings) {
	    	if (getIndex() == job.getProviderIndex()) {
	        	count = getNumOfJob();
	        	break;  
    		}
		}
        int jobNum;
        string title, desc, location, contact;
        float payment;
        if (check == 0) {
            cout << "\nNo job is posted.\n\n";
        } else {
            if(displayJobPostings()==true){
            	cout << "Enter job ID you want to update: ";
            	cin >> jobNum;
            	cin.ignore();
            	if (jobNum >= 1 && jobNum <= count) {
                	auto it = jobPostings.begin();
                	i=1;
					while(i<jobNum)
					{
						++it;
						++i;
					}
        			JobAdvertisement &job = *it;
					cout << "\n=== Update Job Details ===\n";
                	string title, desc, location;
                	float payment;

                	cout << "Update job title: ";
                	getline(cin, title);
	                while (title.empty()) {
	                    cout << "Required field, please do not leave blank.\n\n";
	                    cout << "Update job title: ";
	                    getline(cin, title);
	                }
	                job.setTitle(title);

	                cout << "Update job description: ";
	                getline(cin, desc);
	                while (desc.empty()) {
	                    cout << "Required field, please do not leave blank.\n\n";
	                    cout << "Update job description: ";
	                    getline(cin, desc);
	                }
	                job.setDescription(desc);

	                cout << "Update job location: ";
	                getline(cin, location);
	                while (location.empty()) {
	                    cout << "Required field, please do not leave blank.\n\n";
	                    cout << "Update job location: ";
	                    getline(cin, location);
	                }
	                job.setLocation(location);
                
                	cout << "Update job contact: ";
                	getline(cin, contact);
        			while (contact.empty() || contact.length() != 10 && contact.length() != 11) {
	            		if (contact.empty()) {
	                	cout << "Required field, please do not leave blank.\n\n";
	                	cout << "Enter contact number: ";
	                	getline(cin, contact);
	            		}
	
	            		if (contact.length() != 10 && contact.length() != 11) {
	                	cout << "Contact number must have 10 digits or 11 digits.\n\n";
	                	cout << "Enter contact number: ";
	                	getline(cin, contact);
	            		}
        			}					
                	job.setContact(contact);

	                cout << "Update job payment: ";
	                cin >> payment;
	                cin.ignore();
	                while (payment <= 0) {
	                    cout << "Invalid payment, please input the valid payment.\n\n";
	                    cout << "Update job payment: ";
	                    cin >> payment;
	                    cin.ignore();
	                }
                	job.setPayment(payment);

                	cout << "\nJob details updated successfully.\n\n";
				}else{
					cout << "Invalid job ID.\n\n";
				}

            } 
        }
	}
			    
    void removeJobPosting(){
    	int count=0, i;
    	int check = jobPostings.size();
    	for (auto& job : jobPostings) { //iterates the vector
    		if (getIndex() == job.getProviderIndex()) { //find the associated job provider
        		count = getNumOfJob();
        		break;  
    		}
		}
        int jobNum;
        int confirm;
        string title, desc, location;
        float payment;
        if (check == 0) {
            cout << "\nNo job is posted.\n\n";
        } else {
        	if(displayJobPostings()==true){
            	cout << "Enter job ID you want to remove: ";
            	cin >> jobNum;
            	cin.ignore();

            	if (jobNum >= 1 && jobNum <= count) {
                		auto it = jobPostings.begin();
						i=1;
						while(i<jobNum)
						{
							++it;
							++i;
						}
					int vectorIndex = distance(jobPostings.begin(), it);
					cout<<"\nDo you confirm to remove the job? (1: Yes, 2: No): ";
					cin>>confirm;
					cin.ignore();
					while(confirm!=1){
						if(confirm==2){
							cout<<"You choose to not remove the job.\n\n";
							return;
						}
						if(confirm<1 || confirm>2){
							cout<<"Invalid option. Please try again.\n\n";
							cout<<"Do you confirm to remove the job? (1: Yes, 2: No): ";
							cin>>confirm;
							cin.ignore();
							cout<<endl;
						}
					}
        			jobPostings.erase(it);
                	count--;
					
					cout<<"Job is removed successfully.\n\n";
            	} else {
                	cout << "Invalid job ID.\n\n";
            	}
        	}
		}       
    }
};

/******************************
Class Customer
Implemented by Mohd Aiman Bin Baharin (84588)
****************************/
class Customer : public User {
public:
	Customer(){
		createUser("osborn@gmail.com", "osborn11", "Customer", "Osborn", "0103254198", "Frequent shopper",0);
	}
	
	void browseHomemadeListing() {
        int count = 0;
        int check = homemade.size();
        if(check==0){
        	cout<<"\nNo homemade product is listed.\n\n";
		}else{
			cout << left << setw(10) << "\nID" << setw(20) << "Product Title" << setw(30) << "Product Description" << setw(15) << "Product Price" << endl;
	        cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
			for(auto& product : homemade){ //iterates over each element in the homemade vector
	                count++;
	                cout << left << setw(10) << count
	                     		 << setw(20) << product.getTitle()
	                     		 << setw(30) << product.getDesc()
	                     		 << setw(3) << fixed << setprecision(2) << "RM" << product.getPrice()
	                     << endl;
	    	}
			cout<<"\n";
		}

    }
	
	void searchByProduct(string title) {
	    int found = -1;
	    int count = 0;
		cout << left << setw(10) << "\nID" << setw(20) << "Product Title" << setw(30) << "Product Description" << setw(15) << "Product Price" << endl;
		cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
	    for (auto& product : homemade) {
	        string name = product.getTitle();
	        transform(name.begin(), name.end(), name.begin(), ::tolower);
	        transform(title.begin(), title.end(), title.begin(), ::tolower);
	
	        if (title == name) {
	            count += 1;
	            cout << left << setw(10) << count
		                     << setw(20) << product.getTitle()
		                     << setw(30) << product.getDesc()
		                     << setw(3) << fixed << setprecision(2) << "RM" << product.getPrice()
		                     << endl;
	            found = 1;
	        }
	    }
	    cout<<"\n";
	
	    if (found != 1) {
	        cout << "No results found.\n\n";
	    }
	}

	void searchByPrice(float minPrice, float maxPrice) {
	    int found = -1;
	    int count = 0;
		cout << left << setw(10) << "\nID" << setw(20) << "Product Title" << setw(30) << "Product Description" << setw(15) << "Product Price" << endl;
		cout << setfill('-') << setw(75) << "-" << setfill(' ') << endl;
	    for (auto& product : homemade) {
	        if (minPrice<=product.getPrice()&&maxPrice>=product.getPrice()) {
	            count += 1;
	            cout << left << setw(10) << count
		                     << setw(20) << product.getTitle()
		                     << setw(30) << product.getDesc()
		                     << setw(3) << fixed << setprecision(2) << "RM" << product.getPrice()
		                     << endl;
	            found = 1;
	        }
	    }
		cout<<"\n";
	    if (found != 1) {
	        cout << "No results found.\n\n";
	    }
	}
};

/******************************
Class JobSeeker
Implemented by Aleessya Almaz Binti Razali (86269)
****************************/
class JobSeeker : public User {
public:
	JobSeeker(){
		createUser("evan@gmail.com", "evan66", "Job Seeker", "Evan", "01162487741", "Looking for a job in marketing",0);
	}

	void browseJobPostings() {
        int count = 0;
        int check = jobPostings.size();
        if(check==0){
        	cout<<"\nNo job is listed.\n\n";
		}else{
			cout << left << setw(10) << "\nID" << setw(20) << "Job Title" << setw(25) << "Job Description" << setw(20) << "Job Location" << setw(20) << "Job Contact" << setw(20) << "Job Payment"<< endl;
			cout << setfill('-') << setw(105) << "-" << setfill(' ') << endl;
			for (auto& job : jobPostings) {
	            count++;
	            cout << left << setw(10) << count
		             		 << setw(20) << job.getTitle()
		             		 << setw(25) << job.getDesc()
		             		 << setw(20) << job.getLocation()
		             		 << setw(20) << job.getContact()
		             		 << setw(3) << "RM" << fixed << setprecision(2) << job.getPayment()
		             << endl;
	    	}
	    	cout<<"\n";
		}
    }
	
	
	void searchByLocation(string location) {
	    int found = -1;
	    int count = 0;
		cout << left << setw(10) << "\nID" << setw(20) << "Job Title" << setw(25) << "Job Description" << setw(20) << "Job Location" << setw(20) << "Job Contact" << setw(20) << "Job Payment"<< endl;
		cout << setfill('-') << setw(105) << "-" << setfill(' ') << endl;
	    for (auto& job : jobPostings) {
	        	string jobLocation = job.getLocation();
	        	transform(jobLocation.begin(), jobLocation.end(), jobLocation.begin(), ::tolower); //convert all characters in the jobLocation string to lowercase
	        	transform(location.begin(), location.end(), location.begin(), ::tolower);
	
	        	if (location == jobLocation) {
	            	count += 1;
	            	cout << left << setw(10) << count
			                 	 << setw(20) << job.getTitle()
			                 	 << setw(25) << job.getDesc()
			                 	 << setw(20) << job.getLocation()
			                 	 << setw(20) << job.getContact()
			                 	 << setw(3) << "RM" << fixed << setprecision(2) << job.getPayment()
			             << endl;
	            	found = 1;
	        	}
	    }
	    cout<<"\n";
	
	    if (found != 1) {
	        cout << "No results found.\n\n";
	    }
	}
	
	void searchByTitle(string title) {
	    int found = -1;
	    int count = 0;
		cout << left << setw(10) << "\nID" << setw(20) << "Job Title" << setw(25) << "Job Description" << setw(20) << "Job Location" << setw(20) << "Job Contact" << setw(20) << "Job Payment"<< endl;
		cout << setfill('-') << setw(105) << "-" << setfill(' ') << endl;
	    for (auto& job : jobPostings) {
	        string jobTitle = job.getTitle();
	        transform(jobTitle.begin(), jobTitle.end(), jobTitle.begin(), ::tolower);
	        transform(title.begin(), title.end(), title.begin(), ::tolower);
	
	        if (title == jobTitle) {
	            count += 1;
	            cout << left << setw(10) << count
			                 << setw(20) << job.getTitle()
			                 << setw(25) << job.getDesc()
			                 << setw(20) << job.getLocation()
			                 << setw(20) << job.getContact()
			                 << setw(3) << "RM" << fixed << setprecision(2) << job.getPayment()
			                 << endl;
	            found = 1;
	        }
	    }
		cout<<"\n";
	    if (found != 1) {
	        cout << "No results found.\n\n";
	    }
	}
	
	void searchByPayment(float minPayment, float maxPayment) {
	    int found = -1;
	    int count = 0;
		cout << left << setw(10) << "\nID" << setw(20) << "Job Title" << setw(25) << "Job Description" << setw(20) << "Job Location" << setw(20) << "Job Contact" << setw(20) << "Job Payment"<< endl;
		cout << setfill('-') << setw(105) << "-" << setfill(' ') << endl;
	    for (auto& job : jobPostings) {
	        if (minPayment<=job.getPayment()&&maxPayment>=job.getPayment()) {
	            count += 1;
	            cout << left << setw(10) << count
			                 << setw(20) << job.getTitle()
			                 << setw(25) << job.getDesc()
			                 << setw(20) << job.getLocation()
			                 << setw(20) << job.getContact()
			                 << setw(3) << "RM" << fixed << setprecision(2) << job.getPayment()
			                 << endl;
	            found = 1;
	        }
	    }
		cout<<"\n";
	    if (found != 1) {
	        cout << "No results found.\n\n";
	    }
	}
};

Artisan artisan; //Declares an instance of the Artisan class named artisan
vector<Artisan> artisans; //Declares a vector of Artisan objects named artisans
Customer customer;
vector<Customer> customers;
JobProvider jobProvider;
vector<JobProvider> jobProviders;
JobSeeker jobSeeker;
vector<JobSeeker> jobSeekers;

bool isEmailDuplicate(string email) {
    for (auto& provider : jobProviders) {
        	if (provider.getEmail() == email) {
            // Email is already in use
            return true;
        }
    }
    for (auto& seeker : jobSeekers) {
        	if (seeker.getEmail() == email) {
            return true;
        }
    }
    for (auto& artisan : artisans) {
        	if (artisan.getEmail() == email) {

            return true;
        }
    }
     for (auto& customer : customers) {
        	if (customer.getEmail() == email) {
            return true;
        }
    }
    return false;
}

/******************************
Class marketPlace
Implemented by Hendriyan Bin Yusof (84001)
****************************/
class marketPlace {
public:
    void createUser() {
        string email, password, role, name, contact, bio;
        int roleIndex;

        cout << "Enter email: ";
        getline(cin, email);
        while (email.empty() || isEmailDuplicate(email)){
        	if(email.empty()){
        		cout << "Required field, please do not leave blank.\n\n";
            	cout << "Enter email: ";
            	getline(cin, email);
			}
			if(isEmailDuplicate(email)){
				cout << "Sorry, email has been registered.\n\n";
            	cout << "Enter email: ";
            	getline(cin, email);
			}
        }
        cout << "Enter password: ";
        getline(cin, password);
        while (password.empty()) {
            cout << "Required field, please do not leave blank.\n\n";
            cout << "Enter password: ";
            getline(cin, password);
        }
        cout << "Enter role (1: Job Provider, 2: Job Seeker, 3: Artisan, 4: Customer): ";
        cin >> roleIndex;
        cin.ignore();
		while (roleIndex<0 && roleIndex>4) {
            cout << "Invalid role, please enter the correct role.\n\n";
            cout << "Enter role (1: Job Provider, 2: Job Seeker, 3: Artisan, 4: Customer): ";
            cin >> roleIndex;
        	cin.ignore();
        }
        // Set the role based on user input
        switch (roleIndex) {
        	case 1:
	            role = "Job Provider";
	
	            cout << "Enter name: ";
	            getline(cin, name);
	            while (name.empty()) {
	            cout << "Required field, please do not leave blank.\n\n";
	            cout << "Enter name: ";
	            getline(cin, name);
	        	}
	
	            cout << "Enter contact number: ";
	            getline(cin, contact);
	            while (contact.empty() || contact.length() != 10 && contact.length() != 11) {
		            if (contact.empty()) {
		                cout << "Required field, please do not leave blank.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
		
		            if (contact.length() != 10 && contact.length() != 11) {
		                cout << "Contact number must have 10 digits or 11 digits.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
	        	}
	
	            cout << "Enter a brief bio: ";
	            getline(cin, bio);
	            while (bio.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, bio);
	        	}
				
				indexP++;
	        	jobProviders.push_back(JobProvider());
	        	jobProviders.back().createUser(email, password, role, name, contact, bio, indexP);
	        	totalP++;
	            cout << "\nUser created successfully.\n";
				cout << "Please log in with your email and password.\n\n";
	            break;
        	case 2:
	            role = "Job Seeker";
	
	            cout << "Enter name: ";
	            getline(cin, name);
	            while (name.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, name);
	        	}
	
	            cout << "Enter contact number: ";
	            getline(cin, contact);
	            while (contact.empty() || contact.length() != 10 && contact.length() != 11) {
		            if (contact.empty()) {
		                cout << "Required field, please do not leave blank.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
	
		            if (contact.length() != 10 && contact.length() != 11) {
		                cout << "Contact number must have 10 digits or 11 digits.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
	        	}
	
	            cout << "Enter a brief bio: ";
	            getline(cin, bio);
	            while (bio.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, bio);
	        	}
				
				indexS++;
	        	jobSeekers.push_back(JobSeeker());
	        	jobSeekers.back().createUser(email, password, role, name, contact, bio, indexS);
	        	totalS++;
	            cout << "\nUser created successfully.\n";
				cout << "Please log in with your email and password.\n\n";
	            break;
	        case 3:
	        	role = "Artisan";
	
	            cout << "Enter name: ";
	            getline(cin, name);
	            while (name.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, name);
	        	}
	
	            cout << "Enter contact number: ";
	            getline(cin, contact);
	            while (contact.empty() || contact.length() != 10 && contact.length() != 11) {
		            if (contact.empty()) {
		                cout << "Required field, please do not leave blank.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
		
		            if (contact.length() != 10 && contact.length() != 11) {
		                cout << "Contact number must have 10 digits or 11 digits.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
	        	}
	
	            cout << "Enter a brief bio: ";
	            getline(cin, bio);
	            while (bio.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, bio);
	        	}
				
				indexA++;
	        	artisans.push_back(Artisan());
	        	artisans.back().createUser(email, password, role, name, contact, bio, indexA);
	        	totalA++;
	            cout << "\nUser created successfully.\n";
	            cout << "Please log in with your email and password.\n\n";
	            break;
	        case 4:
	        	role = "Customer";
	
	            cout << "Enter name: ";
	            getline(cin, name);
	            while (name.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, name);
	        	}
	
	            cout << "Enter contact number: ";
	            getline(cin, contact);
	            while (contact.empty() || contact.length() != 10 && contact.length() != 11) {
		            if (contact.empty()) {
		                cout << "Required field, please do not leave blank.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
		
		            if (contact.length() != 10 && contact.length() != 11) {
		                cout << "Contact number must have 10 digits or 11 digits.\n\n";
		                cout << "Enter contact number: ";
		                getline(cin, contact);
		            }
	        	}
	
	            cout << "Enter a brief bio: ";
	            getline(cin, bio);
	            while (bio.empty()) {
		            cout << "Required field, please do not leave blank.\n\n";
		            cout << "Enter name: ";
		            getline(cin, bio);
	        	}
	        	
				indexC++;
	        	customers.push_back(Customer()); //creates a new instance of the Customer class
	        	customers.back().createUser(email, password, role, name, contact, bio, indexC); //adds the newly created Customer object to the end of the customers vector
	        	totalC++;
	            cout << "\nUser created successfully.\n";
				cout << "Please log in with your email and password.\n\n";
	            break;
	        default:
	            cout << "Invalid role. Please try again.\n\n";
	            return;
        }
    }
};

int main(){
    int choose, choose2, choose3, choose4, choose5, i, provider=0, seeker=0, found=-1, artisan=0, customer=0;
    string role, email, password, location, productName, title;
    float minPayment, maxPayment, minPrice, maxPrice;
    marketPlace MarketPlace;

    jobProviders.push_back(JobProvider()); //creates a new instance of the Job provider class (preset data)
    totalP++;
	jobSeekers.push_back(JobSeeker());
	totalS++;
	artisans.push_back(Artisan());
	totalA++;
	customers.push_back(Customer());
	totalC++;
	
    do {
    	cout << "=== Part-Time Job and Homemade Product Marketplace ==="<<endl;
        cout << "1. Register Account\n";
        cout << "2. Log In\n";
        cout << "3. Exit\n";
        cout << "Please select the option (1 to 3): ";
        cin >> choose;
        cin.ignore();

        switch (choose) {
            case 1:
            	system("cls");
                cout << "=== Register Account ===\n";
                MarketPlace.createUser();
                break;

            case 2: {
            	found=-1;
            	system("cls");
                do {
                    cout << "=== Log In === \n";
                    cout << "Enter email: ";
                    getline(cin, email);
                    cout << "Enter password: ";
                    getline(cin, password);

                    i=0;
					while(i<totalP)
					{
						if (jobProviders[i].getEmail() == email && jobProviders[i].getPwd() == password) {
                            cout << "Login successfully.\n" << endl;
                            provider = jobProviders[i].getIndex();
                            role = jobProviders[i].getUserRole();
                            found = 1;
                        }
  						i++;
					}
					
					i=0;
					while(i<totalS)
					{
						if (jobSeekers[i].getEmail() == email && jobSeekers[i].getPwd() == password) {
                            cout << "Login successfully.\n" << endl;
                            seeker = jobSeekers[i].getIndex();
                            role = jobSeekers[i].getUserRole();
                            found = 1;
                        }
  						i++;
					}
					
					i=0;
					while(i<totalA)
					{
						if (artisans[i].getEmail() == email && artisans[i].getPwd() == password) {
                            cout << "Login successfully.\n" << endl;
                            artisan = artisans[i].getIndex();
                            role = artisans[i].getUserRole();
                            found = 1; 
                        }
  						i++;
					}
					
					i=0;
					while(i<totalC)
					{
						if (customers[i].getEmail() == email && customers[i].getPwd() == password) {
                            cout << "Login successfully.\n" << endl;
                            customer = customers[i].getIndex();
                            role = customers[i].getUserRole();
                            found = 1;
                        }
  						i++;
					}

                    if (found == -1) {
                        cout << "Login failed. Incorrect email or password.\n\n";
                        break; 
                    }
                }while(found==-1);
				
                if (found == 1 && role == "Job Provider") {
                	system("cls");
                    do {
                    	cout << "=== Job Provider Main Page ===\n";
                        cout << "1. Manage Profile\n";
                        cout << "2. Post New Job\n";
                        cout << "3. Available Job Posting\n";
                        cout << "4. Update Job Details\n";
                        cout << "5. Remove Job\n";
                        cout << "6. Log Out\n";
                        cout << "Please select the option (1 to 6): ";
                        cin >> choose2;
                        cin.ignore();

                        switch (choose2) {
                            case 1:
                                jobProviders[provider].manageProfile(); //overrides
                                break;
                            case 2:
                                jobProviders[provider].postJobPosting();
                                break;
                            case 3:
                                jobProviders[provider].displayJobPostings();
                                break;
                            case 4:
                                jobProviders[provider].updateJobPosting();
                                break;
                            case 5:
                                jobProviders[provider].removeJobPosting();
                                break;
                            case 6:
                                cout << "\nYou choose to log out. Thank you for using the system.\n\n";
                                system("cls");
                                break;
                            default:
                                cout << "\nInvalid option. Please try again.\n\n";
                        }
                    } while (choose2 != 6);
                }
                
				if (found == 1 && role == "Job Seeker") {
					system("cls");
                    do {
                    	cout << "=== Job Seeker Main Page ===\n";
                        cout << "1. Manage Profile\n";
                        cout << "2. Browse Job Posting\n";
                        cout << "3. Search Job By Title\n";
                        cout << "4. Search Job By Location\n";
                        cout << "5. Search Job By Payment Range\n";
                        cout << "6. Log Out\n";
                        cout << "Please select the option (1 to 6): ";
                        cin >> choose3;
                        cin.ignore();

                        switch (choose3) {
                            case 1:
                                jobSeekers[seeker].manageProfile();
                                break;
                            case 2:
                            	jobSeekers[seeker].browseJobPostings();
                            	break;
                            case 3:
                            	cout<<"\nEnter job title to search: ";
                            	getline(cin, title);
                            	while (title.empty()) {
                    				cout << "Required field, please do not leave blank.\n\n";
                    				cout << "Enter job title to search: ";
                    				getline(cin, title);
                				}
                                jobSeekers[seeker].searchByTitle(title);
                                break;
                            case 4:
                            	cout<<"\nEnter job location to search: ";
                            	getline(cin, location);
                            	while (location.empty()) {
                    				cout << "Required field, please do not leave blank.\n\n";
                    				cout << "Enter job location to search: ";
                    				getline(cin, location);
                				}
                                jobSeekers[seeker].searchByLocation(location);
                                break;
                            case 5:
                                cout<<"\nEnter minimum payment: ";
                            	cin>>minPayment;
                            	cin.ignore();
                            	while (minPayment <= 0) {
            						cout << "Invalid payment, please input the valid payment.\n\n";
            						cout << "Enter minimum payment: ";
            						cin >> minPayment;
            						cin.ignore();
        						}
                            	cout<<"Enter maximum payment: ";
                            	cin>>maxPayment;
                            	cin.ignore();
                            	while (maxPayment <= minPayment) {
	            					cout << "Maximum payment cannot less than or equal to minimum payment.\n\n";
	            					cout << "Enter maximum payment: ";
	            					cin >> maxPayment;
	            					cin.ignore();
	        					}
                                jobSeekers[seeker].searchByPayment(minPayment, maxPayment);
                                break;
                            case 6:
                                cout << "\nYou choose to log out. Thank you for using the system.\n";
                                system("cls");
                                break;
                            default:
                                cout << "\nInvalid option. Please try again.\n";
                        }
                    } while (choose3 != 6);
                }
                
                	if (found == 1 && role == "Artisan") {
                		system("cls");
	                    do {
	                    	cout << "=== Artisan Main Page ===\n";
	                        cout << "1. Manage Profile\n";
	                        cout << "2. List New Homemade Product\n";
	                        cout << "3. Available Homemade Product Listing\n";
	                        cout << "4. Update Homemade Product Details\n";
	                        cout << "5. Remove Homemade Product\n";
	                        cout << "6. Log Out\n";
	                        cout << "Please select the option (1 to 6): ";
	                        cin >> choose4;
	                        cin.ignore();
	
	                        switch (choose4) {
	                            case 1:
	                                artisans[artisan].manageProfile();
	                                break;
	                            case 2:
	                            	artisans[artisan].postProduct();
	                                break;
	                            case 3:
	                                artisans[artisan].displayHomemadeListing();
	                                break;
	                            case 4:
	                                artisans[artisan].updateHomemadeListing();
	                                break;
	                            case 5:
	                                artisans[artisan].removeHomemadeListing();
	                                break;
	                            case 6:
	                                cout << "\nYou choose to log out. Thank you for using the system.\n";
	                                system("cls");
	                                break;
	                            default:
	                                cout << "\nInvalid option. Please try again.\n\n";
	                        }
	                    } while (choose4 != 6);
                	}
                
                	if (found == 1 && role == "Customer") {
                		system("cls");
	                    do {
	                    	cout << "=== Customer Main Page ===\n";
	                        cout << "1. Manage Profile\n";
	                        cout << "2. Browse Homemade Product Listing\n";
	                        cout << "3. Search Homemade Product By Title\n";
	                        cout << "4. Search Homemade Product By Price Range\n";
	                        cout << "5. Log Out\n";
	                        cout << "Please select the option (1 to 5): ";
	                        cin >> choose5;
	                        cin.ignore();
	
	                        switch (choose5) {
	                            case 1:
	                                customers[customer].manageProfile();
	                                break;
	                            case 2:
	                        		customers[customer].browseHomemadeListing();
	                                break;
	                            case 3:
	                                cout<<"Enter product title to search: ";
	                            	getline(cin, productName);
	                            	while (productName.empty()) {
	                    				cout << "Required field, please do not leave blank.\n\n";
	                    				cout << "Enter product title to search: ";
	                    				getline(cin, productName);
	                				}
	                            	customers[customer].searchByProduct(productName);
	                                break;
	                            case 4:
	                                cout<<"Enter minimum price: ";
	                            	cin>>minPrice;
	                            	cin.ignore();
	                            	while (minPrice <= 0) {
	            						cout << "Invalid price, please input the valid price.\n\n";
	            						cout << "Enter minimum price: ";
	            						cin >> minPrice;
	            						cin.ignore();
	        						}
	                            	cout<<"Enter maximum price: ";
	                            	cin>>maxPrice;
	                            	cin.ignore();
	                            	while (maxPrice <= minPrice) {
	            						cout << "Maximum price cannot less than or equal to minimum price.\n\n";
	            						cout << "Enter maximum price: ";
	            						cin >> maxPrice;
	            						cin.ignore();
	        						}
	                                customers[customer].searchByPrice(minPrice, maxPrice);
	                                break;
	                            case 5:
	                                cout << "\nYou choose to log out. Thank you for using the system.\n";
	                                system("cls");
	                                break;
	                            default:
	                                cout << "\nInvalid option. Please try again.\n";
	                        }
	                    } while (choose5 != 5);
                	}

                break;
            }

            case 3:
                cout << "\nThank you for using the system.\n";
                return 0; 

            default:
                cout << "\nInvalid option. Please try again.\n\n";
        }
    }while(true);
    return 0;
}
