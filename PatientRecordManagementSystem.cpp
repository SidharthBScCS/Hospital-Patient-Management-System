#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

struct Patient{
    int patientID;
    string patientName;
    string admissionDate;
    string treatmentDetails;
    Patient *next;
};

struct EmergencyPatient{
    int priority;
    string name;
    bool operator<(const EmergencyPatient &other) const {
        return priority < other.priority;
    }
};

class PatientRecordManagementSystem{
    private:
        Patient *head;
        stack<Patient> undoStack;
        priority_queue<EmergencyPatient> emergencyQueue;

    public:
        PatientRecordManagementSystem(){
            head = nullptr;
        }

        void insertPatient(int id,string name,string date,string details){
            Patient *newPatient = new Patient{id, name, date, details, head};
            head = newPatient;
            cout << "Data inserted successfully" << endl;
        }

        void deletePatient(int id){
            Patient *temp = head;
            Patient *prev = nullptr;
            while(temp!=nullptr && temp->patientID!=id){
                prev = temp;
                temp = temp->next;
            }
            if(temp==nullptr){
                cout << "Patient not found" << endl;
                return;
            }
            if(prev==nullptr){
                head = temp->next;
            }
            else{
                prev->next = temp->next;
                delete temp;
                cout << "Patient record deleted successfully" << endl;
            }
        }

        void retrievePatient(int id){
            Patient *temp = head;
            while(temp!=nullptr){
                if(temp->patientID==id){
                    cout<< "Patient ID: " << temp->patientID << endl;
                    cout<< "Patient Name: " << temp->patientName << endl;
                    cout<< "Admission Date: " << temp->admissionDate << endl;
                    cout<< "Treatment Details: " << temp->treatmentDetails << endl;
                    return;
                }
                temp = temp->next;
            }
            cout << "Patient not found" << endl;
        }

        void addPatientRecord(int id,string name,string date,string details){
            insertPatient(id, name, date, details);
            undoStack.push({id, name, date, details, nullptr});
        }

        void undoAdmission(){
            if(!undoStack.empty()){
                Patient last = undoStack.top();
                undoStack.pop();
                deletePatient(last.patientID);
                cout << "Undo successfully" << endl;
            }
            else{
                cout << "Nothing to undo" << endl;
            }
        }

        void manageEmergencyQueue(){
            emergencyQueue.push({1, "Sidharth"});
            emergencyQueue.push({3, "Krishna"});
            emergencyQueue.push({2, "BSc CS"});

            cout << "Emeregency Queue" << endl;
            while(!emergencyQueue.empty()){
                EmergencyPatient ep=emergencyQueue.top();
                emergencyQueue.pop();
                cout << "Name: " << ep.name << endl;
                cout<<"Priority: " << ep.priority << endl;
            }
        }

        float calculateBilling(int days,float rate,float service){
            float total = (days * rate) + service;
            cout << "Total amount to be paid: " << total << endl;
            return total;
        }

        int evaluateInventory(string expr){
            stack<int> s;
            stringstream ss(expr);
            string token;
            while(ss>>token){
                if(isdigit(token[0])){
                    s.push(stoi(token));
                }
                else{
                    int b = s.top();
                    s.pop();

                    int a = s.top();
                    s.pop();

                    if(token=="+"){
                        s.push(a + b);
                    }
                    else if(token=="-"){
                        s.push(a - b);
                    }
                    else if(token=="*"){
                        s.push(a * b);
                    }
                    else if(token=="/"){
                        s.push(a / b);
                    }
                }
            }
            int result = s.top();
            s.pop();
            cout << "Inventory result: " << result << endl;
            return result;
        }
};

int main(){
    PatientRecordManagementSystem hospital;
    int choice;
    
    do{
        cout << "1.Add Patient" << endl;
        cout << "2.Delete patient" << endl;
        cout << "3.View patient" << endl;
        cout << "4.Undo last patient" << endl;
        cout << "5.Manage emergency queue" << endl;
        cout << "6.Calculate billing" << endl;
        cout << "7.Evaluate inventory expression" << endl;
        cout << "8.Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice==1){
            int id;
            cout << "Enter Patient ID: ";
            cin >> id;

            string name;
            cout << "Enter Patient Name: ";
            cin >> name;

            string date;
            cout << "Enter admission date: ";
            cin >> date;

            string details;
            cout << "Enter patient details: ";
            cin >> details;

            hospital.addPatientRecord(id, name, date, details);
        }

        else if(choice==2){
            int id;
            cout << "Enter Patient ID: ";
            cin >> id;
            hospital.deletePatient(id);
        }

        else if(choice==3){
            int id;
            cout << "Enter Patient ID to view: ";
            cin >> id;
            hospital.retrievePatient(id);
        }

        else if(choice==4){
            hospital.undoAdmission();
        }

        else if(choice==5){
            hospital.manageEmergencyQueue();
        }

        else if(choice==6){
            int days;
            cout << "Enter no:of days admitted: ";
            cin >> days;

            float rate;
            cout<<"Enter daily rate: ";
            cin >> rate;

            float service;
            cout << "Enter service charges: ";
            cin >> service;

            hospital.calculateBilling(days, rate, service);
        }

        else if(choice==7){
            string expr;
            cin.ignore();
            cout << "Enter postfix expression: ";
            getline(cin,expr);
            hospital.evaluateInventory(expr);
        }

        else if(choice==8){
            cout << "Exiting..." << endl;
        }

        else{
            cout << "Invalid choice" << endl;
        }
    } while (choice != 8);
}