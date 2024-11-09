#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

void display_mainpage();
void ven_credential();
void Goback_CheckVender();
void Goback_CheckCustomer();
void vendorMain_menu();
void title_style(){
    cout << "------------------------------------------------------------------------------\n";
    cout << "------------------------------------------------------------------------------\n";
    cout << "|                                                                            |\n";
    cout << "|                                WELCOME                                     |\n";
    cout << "|                                                                            |\n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "|                       VENDING MACHINE SIMULATOR                            |\n";
    cout << "-----------------------------------------------------------------------------\n";
    }
    
     void venderTitle_style(){
        system("cls");

    cout << "------------------------------------------------------------------------------\n";
    cout << "|                                                                            |\n";
    cout << "|                                WELCOME                                     |\n";
    cout << "|                                                                            |\n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "|                                  Vendor                                    |\n";
    cout << "-----------------------------------------------------------------------------\n";
     }
     void for_adding(){
    cout << "|                           Add Products Details                             |\n";
    cout << "-----------------------------------------------------------------------------\n\n";
     }
       void for_updating(){
    cout << "|                         Update Products Details                            |\n";
     cout << "-----------------------------------------------------------------------------\n";
     }
       void for_deleting(){
      cout << "|                          Delete product  Details                           |\n";
    cout << "-----------------------------------------------------------------------------\n";
     }
     void customerTitle_style(){
    cout << "------------------------------------------------------------------------------\n";
    cout << "|                                                                            |\n";
    cout << "|                                WELCOME                                     |\n";
    cout << "|                                                                            |\n";
     cout << "-----------------------------------------------------------------------------\n";
    cout << "|                                 Customer                                   |\n";
    cout << "-----------------------------------------------------------------------------\n";
    cout << "|                                Main Menu                                   |\n";
    cout << "-----------------------------------------------------------------------------\n";

     }
  void for_salty(){
     cout << "|                            Salty Snacks counter                            |\n";
     cout << "-----------------------------------------------------------------------------\n\n";
     }
      void for_sweets(){
     cout << "|                            Sweet Snacks counter                            |\n";
     cout << "-----------------------------------------------------------------------------\n\n";
     }
      void for_beverages(){
     cout << "|                             Cold drinks counter                            |\n";
     cout << "-----------------------------------------------------------------------------\n\n";
     }

class login_vend{
    string ent_id,ent_pswd="";
    public:
    void cred(string* id,int id_length, string* password,int pas_len){
        string chec_pswrd;
        chec_pswrd=*password;
        string chec_id;
        chec_id=*id;
cout<<"Enter your id: ";
ent_id.clear();
int i=0;
char id_c;
while(i<id_length){
 id_c=_getch();
if(id_c=='\r'){
    break;
    return;
}else if(id_c>='0' &&  id_c<='9'){
      cout<<id_c;
    ent_id.push_back(id_c);
    i++;
}else if(id_c=='\b'){
    if(!ent_id.empty()){
        cout<<"\b \b";
        ent_id.pop_back();
        i--;
    }
}}

if(ent_id==chec_id){
//if id is correct then ask password 
bool checker=true;
int attempts=0;
do{
cout << "\nEnter password: ";
ent_pswd.clear();
int i=0;
char ch;
while(i<pas_len){
ch=_getch();
if(ch=='\r'){
    break;
    exit(0);
}else if(ch=='\b'){
    if(!ent_pswd.empty()){
        cout<<"\b \b";
        ent_pswd.pop_back();  
        i--; 
    }
}else{
    ent_pswd.push_back(ch);
     cout<<"*";
    i++;
}
}
if(ent_pswd==chec_pswrd){
    cout<<"\nWelcome...";
    checker = true;
     //for main menu 
            vendorMain_menu();
}else{
    cout<<"\nWrong password...\n";
    cout<<"Your attempts left: "<<2-attempts<<"\n";
    checker=false;
    attempts++;
}
}while(attempts<3 && checker==false);
}else{
    cout<<"\nWrong credentials...\n";
    retryorExit();
}
    }
void retryorExit(){
cout<<"\nDo you want to try again (Y) OR exit the program?\n";
    string choice;
    getline(cin,choice);
    if(choice=="Y" || choice=="y"){

        venderTitle_style();
        ven_credential();
    }else{
        cout<<"Thank you for your precious time and energy....\n";
     exit(0);
    }
}
};

void ven_credential(){
string saved_id="123";
int len=saved_id.length();
string saved_password="abc";
int pas_len=saved_password.length();
login_vend login;
login.cred(&saved_id, len, &saved_password ,pas_len);
}
class Product {
protected:
    int price = 0;
    int code = 0;
    string name="";
    int quantity = 0;

public:
    void correctNamePro() {
        name.clear();
        int k = 0;
        char Namm;
        while (k < 9) {
            Namm = _getch();
            if (Namm == '\r') {
                break;
            } else if (Namm == '\b') {
                if (!name.empty()) {
                    cout << "\b \b"; // Erase the last character from the console
                    name.pop_back();
                    k--;
                }
            } else if ((Namm >= 'a' && Namm <= 'z') || (Namm >= 'A' && Namm <= 'Z')) {
                name.push_back(Namm);
                cout << Namm;
                k++;
            }
        }
        if (name.empty()) {
            name = "default"; // Assign a default name if no input is provided
        }
    }

     void correctCodePro() {
        string codes = "";
        int j = 0;
        char Codee;
        while (j < 4) {
            Codee = _getch();
            if (Codee == '\r') {
                break;
            } else if (Codee == '\b') {
                if (!codes.empty()) {
                    cout << "\b \b"; // Erase the last character from the console
                    codes.pop_back();
                    j--;
                }
            } else if (Codee >= '0' && Codee <= '9') {
                codes.push_back(Codee);
                cout << Codee;
                j++;
            }
        }
        if (!codes.empty()) {
             code = stoi(codes);
        } else {
          
             code = 1; // Assign a default code if no input is provided
        }
    }

    void correctQuantityPro() {
        string qya = "";
        int j = 0;
        char Quant;
        while (j < 2) {
            Quant = _getch();
            if (Quant == '\r') {
                break;
            } else if (Quant == '\b') {
                if (!qya.empty()) {
                    cout << "\b \b"; // Erase the last character from the console
                    qya.pop_back();
                    j--;
                }
            } else if (Quant >= '0' && Quant <= '9') {
                qya.push_back(Quant);
                cout << Quant;
                j++;
            }
        }
        if (!qya.empty()) {
          quantity = stoi(qya);
        } else {
            quantity=0;
        }
    }

    void correctPricePro() {
        string pri = "";
        int j = 0;
        char Pri_cE;
        while (j < 3) {
            Pri_cE = _getch();
            if (Pri_cE == '\r') {
                break;
            } else if (Pri_cE == '\b') {
                if (!pri.empty()) {
                    cout << "\b \b"; // Erase the last character from the console
                    pri.pop_back();
                    j--;
                }
            } else if (Pri_cE >= '0' && Pri_cE <= '9') {
                pri.push_back(Pri_cE);
                cout << Pri_cE;
                j++;
            }
        }
       if(!pri.empty()) {
            price = stoi(pri);
        }else{
            price=0;
        }
    }

    void inputDetails() {
        cout << "Enter name of your item: ";
        correctNamePro();
        cout << "\nEnter code of your item: ";
        correctCodePro();
        cout << "\nEnter your item limit: ";
        correctQuantityPro();
        cout << "\nEnter price of your item: ";
        correctPricePro();
    }

    string showNamePro() {
        return name;
    }

    int showCodePro() {
        return code;
    }

    int showQuantityPro() {
        return quantity;
    }

    int showPricePro() {
        return price;
    }

    void updateQuantity(int purchasedQuantity) {
        quantity -= purchasedQuantity;
    }
};

class split :private Product {
    int* pric_es;
    int* cod_es;
    string* nam_es;
    int* quan_tity;
    int size;
    int capacity;

public:
    split() {
        capacity = 100; // Initial capacity
        size = 0;
        pric_es = new int[capacity];
        cod_es = new int[capacity];
        nam_es = new string[capacity];
        quan_tity = new int[capacity];
    }

    ~split() {
        delete[] pric_es;
        delete[] cod_es;
        delete[] nam_es;
        delete[] quan_tity;
    }

    void reallocate() {
        capacity *= 2; // Double the capacity
        int* new_pric_es = new int[capacity];
        int* new_cod_es = new int[capacity];
        string* new_nam_es = new string[capacity];
        int* new_quan_tity = new int[capacity];

        for (int i = 0; i < size; i++) {
            new_pric_es[i] = pric_es[i];
            new_cod_es[i] = cod_es[i];
            new_nam_es[i] = nam_es[i];
            new_quan_tity[i] = quan_tity[i];

        }

        delete[] pric_es;
        delete[] cod_es;
        delete[] nam_es;
        delete[] quan_tity;

        pric_es = new_pric_es;
        cod_es = new_cod_es;
        nam_es = new_nam_es;
        quan_tity = new_quan_tity;
    }

    void spliter(const string& sentence) {
        if (size >= capacity) {
            reallocate();
        }

        int pos = 0;
        int start = 0;
        string token;

        // Extract Product name
        pos = sentence.find('|');
        nam_es[size] = sentence.substr(start, pos - start);
        start = pos + 1;

        // Extract Code
        pos = sentence.find('|', start);
        token = sentence.substr(start, pos - start);
        cod_es[size] = stoi(token);
        start = pos + 1;

        // Extract Items
        pos = sentence.find('|', start);
        token = sentence.substr(start, pos - start);
        quan_tity[size] = stoi(token);
        start = pos + 1;

        // Extract Price
        token = sentence.substr(start);
        pric_es[size] = stoi(token);

        size++;
    }

    void display_vender(){
            cout << "-----------------------------------------------------\n";
            cout<< left<< setw(16) << "Product name"
                 << setw(12) << " Code"
                 << setw(12) << " Items"
                 << setw(12) << " Price";
            cout << "\n----------------------------------------------------\n";
           
        for (int i = 0; i < size; ++i) {
           cout<<left<<setw(15)<<nam_es[i] 
             <<" | " <<setw(9)<< cod_es[i]
            << " | " <<  setw(9) <<quan_tity[i] 
            << " | " << setw(10) << pric_es[i] << endl;
        }
    }
    void display_customer() {
for (int i = 0; i < size; i += 3) {
        for (int j = 0; j < 3; ++j) {
            if (i + j < size) {
                cout << "--------------------" << setw(9) << " ";
            }
        }
        cout << endl;

        for (int j = 0; j < 3; ++j) {
            if (i + j < size) {
                cout << "PN: " << setw(15) << left << nam_es[i + j] << setw(10) << " ";
            }
        }
        cout << endl;

        for (int j = 0; j < 3; ++j) {
            if (i + j < size) {
                cout << "CD: " << setw(15) << left << cod_es[i + j] << setw(10) << " ";
            }
        }
        cout << endl;

        for (int j = 0; j < 3; ++j) {
            if (i + j < size) {
                cout << "Qty: " << setw(14) << left << quan_tity[i + j] << setw(10) << " ";
            }
        }
        cout << endl;

        for (int j = 0; j < 3; ++j) {
            if (i + j < size) {
                cout << "PR: " << setw(15) << left << pric_es[i + j] << setw(10) << " ";
            }
        }
        cout << endl;

        for (int j = 0; j < 3; ++j) {
            if (i + j < size) {
                cout << "--------------------" << setw(9) << " ";
            }
        }
        cout << endl;
        cout << endl;
    }

    
}

};

class ProductAddFile : protected Product {
    string no_producToadd;
public:
    int num;
    Product* products;
    string line;
    ProductAddFile() {
        num = 0;
        products = nullptr;
    }
    ~ProductAddFile() {
        delete[] products; 
    }
    int getvaluetoadd() {
        cout << "How many products you want to enter? (Max limit: 5): ";
        while (true) {
            char value = _getch();
            if (value >= '1' && value <= '5') {
                cout << value;
                return value - '0'; 
            }
        }
    }

    void adder_details() {
        num = getvaluetoadd();
        cout << "\nEnter details now:\n";
        products = new Product[num];
        for (int i = 0; i < num; i++) {
            cout << "\n\nProduct detail of item " << i + 1 << ":\n";
            products[i].inputDetails();
        }
    }
    void writeTofile(const string& filename) {
        ofstream File(filename, ios::app);
        if (File.is_open()) {
            File.seekp(0, ios::end);
            bool isEmpty = (File.tellp() == 0);
            if (isEmpty) {
                File << "------------------------------------------\n";
                File << left
                     << setw(15) << "Product name"
                     << setw(10) << " Code"
                     << setw(10) << " Items"
                     << setw(10) << " Price";
                File << "\n------------------------------------------";
            }

            for (int i = 0; i < num; i++) {
                File << endl << left
                     << setw(15) << products[i].showNamePro()
                     << "|" << setw(9) << products[i].showCodePro()
                     << "|" << setw(9) << products[i].showQuantityPro()
                     << "|" << setw(10) << products[i].showPricePro();
            }
            File.close(); 
        } else {
            cout << "Error unable to open file \"" << filename << "\"\n";
        }
    }

    void writeFromFile(const string& nameFile, bool selection) {
        ifstream Myfile(nameFile);
        string line;
        split obj;
        if (Myfile.is_open()) {
            while (getline(Myfile, line)) {
                if (line.find("Product name") != string::npos || line.find("------------------------------------------") != string::npos) {
                    continue;
                }
                obj.spliter(line);
            }
            Myfile.close();
            if (selection == true) {
                obj.display_customer();
             
            } else {
                obj.display_vender();
         
            }
        } else {
            cout << "Error unable to open file \"" << nameFile << "\"\n";
        }
    }

   void updateProductDetails(const string& filename, int code) {
    ifstream Myfile(filename);
    ofstream Tempfile("temp.txt");
    string line;
    bool updated = false;

    if (Myfile.is_open() && Tempfile.is_open()) {
        while (getline(Myfile, line)) {
            if (line.find("Product name") != string::npos || line.find("------------------------------------------") != string::npos) {
                Tempfile << line << endl; 
            } else {
                size_t firstPos = line.find('|');
                if (firstPos != string::npos) {
                    string AfterFirstPos = line.substr(firstPos + 1);
                    size_t secondPos = AfterFirstPos.find('|');
                    if (secondPos != string::npos) {
                        string codeStr = AfterFirstPos.substr(0, secondPos);
                        int lineCode = stoi(codeStr);
                        if (lineCode == code) {
                            cout << "\nEnter new details for product with code " << code << ":\n";
                            Product updatedProduct;
                            updatedProduct.inputDetails(); 
                            Tempfile << left << setw(15) << updatedProduct.showNamePro()
                                     << "|" << setw(9) << updatedProduct.showCodePro()
                                     << "|" << setw(9) << updatedProduct.showQuantityPro()
                                     << "|" << setw(10) << updatedProduct.showPricePro() << endl;
                            updated = true;
                        } else {
                            Tempfile << line << endl;
                        }
                    }
                }
            }
        }
        Myfile.close();
        Tempfile.close();

        if (updated) {
            remove(filename.c_str());
            rename("temp.txt", filename.c_str());
            cout << "\nProduct updated successfully!\n";
        } else {
            cout << "\nProduct with code " << code << " not found.\n";
            remove("temp.txt"); 
        }
    } else {
        cout << "Error opening file(s).\n";
    }
}

   void deleteProduct(const string& filename, int code) {
    ifstream Myfile(filename);
    ofstream Tempfile("temp.txt");
    string line;
    bool deleted = false;

    if (Myfile.is_open() && Tempfile.is_open()) {
        while (getline(Myfile, line)) {
            if (line.find("Product name") != string::npos || line.find("------------------------------------------") != string::npos) {
                Tempfile << line << endl; 
            } else {
                size_t firstPos = line.find('|');
                if (firstPos != string::npos) {
                    string AfterFirstPos = line.substr(firstPos + 1);
                    size_t secondPos = AfterFirstPos.find('|');
                    if (secondPos != string::npos) {
                        string codeStr = AfterFirstPos.substr(0, secondPos);
                        int lineCode = stoi(codeStr);
                        if (lineCode == code) {
                            deleted = true;
                        } else {
                            Tempfile << line << endl;  
                        }
                    }
                }
            }
        }
        Myfile.close();
        Tempfile.close();

        if (deleted) {
            remove(filename.c_str());
            rename("temp.txt", filename.c_str());
            cout << "\nProduct with code " << code << " deleted successfully!\n";
        } else {
            cout << "\nProduct with code " << code << " not found.\n";
            remove("temp.txt");
        }
    } else {
        cout << "Error opening file(s).\n";
    }
}

void customer_purchase(const string& filename, int pur_code) {
    ifstream Myfile(filename);
    ofstream Tempfile("temp.txt");
    string line;
    bool found = false;

    if (Myfile.is_open() && Tempfile.is_open()) {
        while (getline(Myfile, line)) {
            if (line.find("Product name") != string::npos || line.find("------------------------------------------") != string::npos) {
                Tempfile << line << endl;
            } else {
                size_t firstPos = line.find('|');
                if (firstPos != string::npos) {
                    string AfterFirstPos = line.substr(firstPos + 1);
                    size_t secondPos = AfterFirstPos.find('|');
                    if (secondPos != string::npos) {
                        string codeStr = AfterFirstPos.substr(0, secondPos);
                        int lineCode = stoi(codeStr); 
                        if (lineCode == pur_code) {
                            size_t thirdDelimPos = AfterFirstPos.find('|', secondPos + 1);
                            string quantityStr = AfterFirstPos.substr(secondPos + 1, thirdDelimPos - (secondPos + 1));
                            string priceStr = AfterFirstPos.substr(thirdDelimPos + 1);

                            int availableQuantity = stoi(quantityStr);
                            int price = stoi(priceStr);

                            if (availableQuantity == 0) {
                                cout << "\nTransaction cannot be completed! Product out of stock....\n";
                                Goback_CheckCustomer();
                                Tempfile << line << endl; 
                                found = true;
                            } else {
                                found = true;
                                int purchaseQuantity = 0;
                                while (true) {
                                    cout << "\nEnter the quantity you want to purchase (available: " << availableQuantity << "): ";
                                    cin >> purchaseQuantity;
                                    if (purchaseQuantity > 0 && purchaseQuantity <= availableQuantity) {
                                        break;
                                    } else {
                                        cout << "Invalid quantity.\n Please enter a valid quantity.\n";
                                    }
                                }

                                int totalCost = purchaseQuantity * price;
                                int enteredAmount = 0;
                                while (true) {
                                    cout << "The total cost is " << totalCost << ".\nEnter the amount: ";
                                    cin >> enteredAmount;
                                    if (enteredAmount < totalCost) {
                                        cout << "Invalid amount......\n Please enter at least " << totalCost << ".\n";
                                    } else {
                                        break;
                                    }
                                }

                                int change = enteredAmount - totalCost;
                               if (change > 0) {
        cout << "\033[32m\nTransaction completed!\033[0m\n"; // Green
        cout << "\033[34mYour change is: " << change << "\033[0m" << endl; // Blue
        cout << "\033[31mThank you for buying...\033[0m\n\n"; // Red
                               cout << "\033[33m--------------------------COME AGAIN-----------------------\033[0m\n"; // Yellow

    } else {
        cout << "\033[32m\nTransaction completed!\033[0m" << endl; // Green
       cout << "\033[31mThank you for buying...\033[0m\n\n"; // Red
                cout << "\033[33m--------------------------COME AGAIN-----------------------\033[0m\n"; // Yellow
    }

                                int remainingQuantity = availableQuantity - purchaseQuantity;
                                Tempfile << left << setw(15) << line.substr(0, firstPos)
                                    << "|" << setw(9) << lineCode
                                    << "|" << setw(9) << remainingQuantity
                                    << "|" << setw(10) << price << endl;
                            }
                        } else {
                            Tempfile << line << endl; 
                        }
                    }
                }
            }
        }
        Myfile.close();
        Tempfile.close();

        if (found) {
            remove(filename.c_str());
            rename("temp.txt", filename.c_str());
        } else {
            cout << "\nProduct with code " << pur_code << " not found.\n";
            Goback_CheckCustomer();
            remove("temp.txt"); // Remove temporary file if no update was made

        }
    } else {
        cout << "Error opening file(s).\n";
    }
}
};

class AddproAsk{
public:
string chosen;
void menuForAdding(){
          bool Controller=false;
      system("cls");
       do{
            venderTitle_style();
            cout<<"1.Add products in Salty Snacks counter\n";
            cout<<"2.Add products in Sweet Snacks counter\n";
            cout<<"3.Add products in Beverages counter\n";
            cout<<"4.Go back\n";
            cout<<"Enter your choice: ";
getline(cin,chosen);
if(chosen=="1"){
      venderTitle_style();
    for_adding();
     for_salty();
cout<<endl<<endl;
ProductAddFile add1;
add1.adder_details();
add1.writeTofile("salty.txt");
    Controller=false;
}else if(chosen=="2"){
     venderTitle_style();
     for_adding();
       for_sweets();
   cout<<endl<<endl;
ProductAddFile add2;
add2.adder_details();
add2.writeTofile("sweets.txt");
    Controller=false;
}else if(chosen=="3"){
 
     venderTitle_style();
     for_adding();
       for_beverages();
  cout<<endl<<endl;
ProductAddFile add3;
add3.adder_details();
add3.writeTofile("beverages.txt");
    Controller=false;

}else if(chosen=="4"){
    system("cls");
   vendorMain_menu();
    Controller=false;
}else{
    cout<<"Wrong choice...\n";
     cout << "Please enter 1 or 2 or ( 3 for exiting )\n";
             Controller=true;}

}while(Controller);
}

};

class ProductUpdating{
int code;
public:
string co_choice;
 void correctcodePro() {
      cout<<"\n\nEnter your product code for update: ";
        string codes;
        int j = 0;
        codes.clear();
        char Codee;
        while (j < 4) {
            Codee = _getch();
            if (Codee == '\r') {
                break;
            } else if (Codee == '\b') {
                if (!codes.empty()) {
                    cout << "\b \b";  // Erase the last character from the console
                    codes.pop_back();
                    j--;
                }
            } else if (Codee >= '0' && Codee <= '9') {
                codes.push_back(Codee);
                cout << Codee;
                j++;
            }
        }
        if (!codes.empty()) {
            code = stoi(codes);
        }
    }
 
  int showCodepro() {
        return code;
    }



void menuForUpdating(){
          bool ControlMenu=false;
      system("cls");
       do{
            venderTitle_style();
            cout<<"1.Update products in Salty Snacks counter\n";
            cout<<"2.Update products in Sweet Snacks counter\n";
            cout<<"3.Update products in Beverages counter\n";
            cout<<"4.Go back\n";
            cout<<"Enter your choice: ";
getline(cin,co_choice);
if(co_choice=="1"){

      venderTitle_style();
    for_updating();
     for_salty();
     //show record
        ProductAddFile show;
   show.writeFromFile("salty.txt",false);
   correctcodePro();
   show.updateProductDetails("salty.txt",code);
    cout<<endl<<endl;
    ControlMenu=false;
}else if(co_choice=="2"){

     venderTitle_style();
    for_updating();
       for_sweets();
       //show record
         ProductAddFile show1;
   show1.writeFromFile("sweets.txt",false);
    correctcodePro();
   show1.updateProductDetails("sweets.txt",code);
    cout<<endl<<endl;
    ControlMenu=false;
}else if(co_choice=="3"){

     venderTitle_style();
    for_updating();
       for_beverages();
      //show record
        ProductAddFile show2;
   show2.writeFromFile("beverages.txt",false);
    correctcodePro();
   show2.updateProductDetails("beverages.txt",code);
    cout<<endl<<endl;
    ControlMenu=false;

}else if(co_choice=="4"){
    system("cls");
   vendorMain_menu();
    ControlMenu=false;
}else{
    cout<<"Wrong choice...\n";
     cout << "Please enter 1 or 2 or ( 3 for exiting )\n";
     getch();
             ControlMenu=true;}

}while(ControlMenu);
}
};
class ProductDeleting{
    int code;
public:
string de_choice;
 void correctcodePro() {
      cout<<"\n\nEnter your product code for delete: ";
        string codes;
        int j = 0;
        codes.clear();
        char Codee;
        while (j < 4) {
            Codee = _getch();
            if (Codee == '\r') {
                break;
            } else if (Codee == '\b') {
                if (!codes.empty()) {
                    cout << "\b \b";  // Erase the last character from the console
                    codes.pop_back();
                    j--;
                }
            } else if (Codee >= '0' && Codee <= '9') {
                codes.push_back(Codee);
                cout << Codee;
                j++;
            }
        }
        if (!codes.empty()) {
            code = stoi(codes);
        }
    }
 
int showCodepro() {
        return code;
    }

void menuForDeleting(){
          bool Controler=false;
      system("cls");
       do{
            venderTitle_style();
            cout<<"1.Delete product in Salty Snacks counter\n";
            cout<<"2.Delete product in Sweet Snacks counter\n";
            cout<<"3.Delete product in Beverages counter\n";
            cout<<"4.Go back\n";
            cout<<"Enter your choice: ";
getline(cin,de_choice);
if(de_choice=="1"){

      venderTitle_style();
    for_deleting();
     for_salty();
     //to show record 
      cout<<endl;
             ProductAddFile show_for;
   show_for.writeFromFile("salty.txt",false);
      correctcodePro();
   show_for.deleteProduct("salty.txt",code);
          cout<<endl;

    Controler=false;
}else if(de_choice=="2"){

     venderTitle_style();
    for_deleting();
       for_sweets();
        cout<<endl;
                    ProductAddFile show_for1;
   show_for1.writeFromFile("sweets.txt",false);
   correctcodePro();
   show_for1.deleteProduct("sweets.txt",code);

          cout<<endl;
   
    Controler=false;
}else if(de_choice=="3"){

     venderTitle_style();
   for_deleting();
       for_beverages();

                    ProductAddFile show_for2;
   show_for2.writeFromFile("beverages.txt",false);
   correctcodePro();
      show_for2.deleteProduct("beverages.txt",code);
          cout<<endl;

    Controler=false;

}else if(de_choice=="4"){
    system("cls");
   vendorMain_menu();
    Controler=false;
}else{
    cout<<"Wrong choice...\n";
     cout << "Please enter 1 or 2 or ( 3 for exiting )\n";
             Controler=true;}

}while(Controler);
}

};

void vendorMain_menu(){
    bool tester=false;
      system("cls");
       do{
            venderTitle_style();
    cout<<"\n1. Add \n";
    cout<<"2. Update\n";
    cout<<"3. Delete\n";
    cout<<"4. View All products\n";
    cout<<"5. Go back\n";
cout<<"Enter your choice: ";
string cho_ice;
getline(cin,cho_ice);
if(cho_ice=="1"){

      venderTitle_style();
   for_adding();
   AddproAsk obj1;
   obj1.menuForAdding();
  Goback_CheckVender();
    tester=false;
}else if(cho_ice=="2"){

     venderTitle_style();
    for_updating();
    cout<<endl<<endl;
    ProductUpdating upd;
    upd.menuForUpdating();
    Goback_CheckVender();
    tester=false;
}else if(cho_ice=="3"){

     venderTitle_style();
  for_deleting();
  cout<<endl<<endl; 
  ProductDeleting  del;
  del.menuForDeleting();
 Goback_CheckVender();
    tester=false;
}
else if(cho_ice=="4"){
       ProductAddFile view;
   venderTitle_style();
   cout<<"\n\n----------------------------------Snacks------------------------------------- \n\n";
   view.writeFromFile("salty.txt",false);
    cout<<"\n\n---------------------------------Sweets------------------------------------- \n\n";
   view.writeFromFile("sweets.txt",false);
    cout<<"\n\n--------------------------------Beverages----------------------------------- \n\n";
   view.writeFromFile("beverages.txt",false);

Goback_CheckVender();
    tester=false;
}else if(cho_ice=="5"){
    system("cls");
    display_mainpage();
    tester=false;
}else{
    cout<<"Wrong choice...\n";
     cout << "Please enter 1 or 2 or ( 3 for exiting )\n";
             tester=true;}

}while(tester);
}


//for checking
  void Goback_CheckVender(){
cout<<"\n\nDo you want to try again (Y) OR exit the program?\n";
    string che_choise;
    getline(cin,che_choise);
    if(che_choise=="Y" || che_choise=="y"){

        venderTitle_style();
       vendorMain_menu();
    }else{
        cout<<"Thank you for your precious time and energy....\n";
     exit(0);
    }
}

class Customer: private Product{
    int code;
    public:
    string cho_ice;
    void correctcodePro() {
      cout<<"\n\nEnter your product code for purchase: ";
        string codes;
        int j = 0;
        codes.clear();
        char Codee;
        while (j < 4) {
            Codee = _getch();
            if (Codee == '\r') {
                break;
            } else if (Codee == '\b') {
                if (!codes.empty()) {
                    cout << "\b \b";  // Erase the last character from the console
                    codes.pop_back();
                    j--;
                }
            } else if (Codee >= '0' && Codee <= '9') {
                codes.push_back(Codee);
                cout << Codee;
                j++;
            }
        }
        if (!codes.empty()) {
            code = stoi(codes);
        }
    }
void customerMain_menu(){
          bool Controller=false;
      system("cls");
       do{
            customerTitle_style();
            cout<<"1.Salty Snacks\n";
            cout<<"2.Sweet Snacks\n";
            cout<<"3.Beverages\n";
            cout<<"4.Go back\n";
            cout<<"Enter your choice: ";

getline(cin,cho_ice);
if(cho_ice=="1"){
      system("cls");
      customerTitle_style();
   for_salty();
ProductAddFile obj;
obj.writeFromFile("salty.txt",true);
correctcodePro();
obj.customer_purchase("salty.txt",code);
    Controller=false;
}else if(cho_ice=="2"){
       system("cls");
     customerTitle_style();
    for_sweets();
    ProductAddFile obj1;
obj1.writeFromFile("sweets.txt",true);
correctcodePro();
obj1.customer_purchase("sweets.txt",code);
    Controller=false;
}else if(cho_ice=="3"){
        system("cls");
     customerTitle_style();
  for_beverages();
  ProductAddFile obj2;
obj2.writeFromFile("beverages.txt",true);
correctcodePro();
obj2.customer_purchase("beverages.txt",code);
    Controller=false;
}else if(cho_ice=="4"){
    system("cls");
    display_mainpage();
    Controller=false;
}else{
    cout<<"Wrong choice...\n";
     cout << "Please enter 1 or 2 or ( 3 for exiting )\n";
             Controller=true;}

}while(Controller==true);
}
};

void Goback_CheckCustomer(){
    cout<<"\n\nDo you want to try again (Y) OR exit the program?\n";
    string che_choise;
    getline(cin,che_choise);
    if(che_choise=="Y" || che_choise=="y"){
customerTitle_style();
Customer obj;
     obj.customerMain_menu();
    }else{
        cout<<"Thank you for your precious time and energy....\n";
     exit(0);
    }
}

//display first page
void display_mainpage(){
    bool flag=false;
    do{
    title_style();
    cout << "1. Vendor\n";
        cout << "2. Customer\n";
        cout<<  "3. Exit\n";
        string select_choice;
          cout << "Enter your choice: ";
        getline(cin,select_choice);
        if(select_choice=="1"){
            venderTitle_style();
            ven_credential();
            flag=false;
        }
    else if(select_choice=="2"){
        system("cls");
          customerTitle_style();
       Customer obj;
       obj.customerMain_menu();
        flag=false;
    }else if(select_choice=="3"){
       cout<<"Thank you for your precious time.....";
            exit(0);
    }else{
        cout << "Invalid choice.\n Please enter 1 or 2 or ( 3 for exiting )\n";
        getch();
        flag=true;
    }}while(flag==true);
}

int main(){
    display_mainpage();
    return 0;
}