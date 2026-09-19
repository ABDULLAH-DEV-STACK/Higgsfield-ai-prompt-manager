#include <iostream> 
#include <string>
#include "sqlite3.h"
using namespace std;

// class 1: Handle SQL DataBase Presistence using SQLite
class DataBaseManager {
    private:
    sqlite3* db;
    public:
    DataBaseManager() {
        // Open or create database file ai_prompts.db
        if (sqlite3_open("ai_prompts.db", &db) == SQLITE_OK) {
            string sql = "CREATE TABLE IF NOT EXISTS VideoJobs ("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
            "Prompt TEXT NOT  NULL, "
            "STATUS TEXT NOT  NULL);";
            sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr);
        } else {
            cerr << "Error intializing database." << endl;
        }     
    }
    
    
    void savePrompt(const string& prompt) {
        string sql = "INSERT INTO VideoJobs (Prompt, STATUS) VALUES ('" + prompt + "', 'QUEUED');";
        if (sqlite3_exec(db, sql.c_str(), nullptr, nullptr, nullptr) != SQLITE_OK) {
            cerr << "Error saving prompt to database." << endl;
        } else {
            cout << "[Database Manager] Prompt saved to database successfully." << endl;
        }
    }
    
    void readAllPrompts() {
        string sql = "SELECT ID, Prompt, Status FROM VideoJobs;";
        sqlite3_stmt* stmt;

        // 1. Prepare the SELECT query
        if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
            cout << "\n=============================================" << endl;
            cout << "      SAVED PROMPTS FROM SQLITE DATABASE     " << endl;
            cout << "=============================================" << endl;

            bool foundData = false;

            // 2. Loop through every row returned by the database
            while (sqlite3_step(stmt) == SQLITE_ROW) {
                foundData = true;

                // Extract column values (0 = ID, 1 = Prompt, 2 = Status)
                int id = sqlite3_column_int(stmt, 0);
                
                // Convert raw database text to standard C++ string safely
                const unsigned char* rawPrompt = sqlite3_column_text(stmt, 1);
                string promptText = rawPrompt ? reinterpret_cast<const char*>(rawPrompt) : "";

                const unsigned char* rawStatus = sqlite3_column_text(stmt, 2);
                string statusText = rawStatus ? reinterpret_cast<const char*>(rawStatus) : "";

                // Display the structured database record
                cout << "  [Job #" << id << "] Status: [" << statusText << "]" << endl;
                cout << "  Prompt: " << promptText << endl;
                cout << "---------------------------------------------" << endl;
            }

            if (!foundData) {
                cout << "  No saved prompts found in the database." << endl;
                cout << "---------------------------------------------" << endl;
            }
        } else {
            cerr << "[Database Error] Failed to fetch data." << endl;
        }

        // 3. Clear statement memory allocation
        sqlite3_finalize(stmt);
    }

    ~DataBaseManager() {
        if (db) {
            sqlite3_close(db);
        }
    }
};

// Class 2: Encapsulates Higgsfield AI Intergration Parameters 
class HiggsFieldClient {
    private:
    string apikey;
    string modelversion;

    public:
    HiggsFieldClient(string key, string model="hiddsfield-v1") {
     apikey = key;
     modelversion = model;
    }
    
    void dispatchPrompt(const string& prompt) {
        cout << "[Higgsfield Client] Target Model: " << modelversion << endl;
        cout << "[Higgsfiels Client] Structuring JSON Payload..."<< endl;
        cout << "PayLoad: {\"model\": \"" << modelversion << "\", \"prompt\": \""<< prompt  << "\"}" << endl;
        cout << "[Higgsfiled Client] Simulation: Request sent to https://api.higgsfield.ai/v1/generate" << endl;
        cout << "[Higgsfield Client] Status 200 OK - Generation queued!" << endl;        
    }
};

int main() {
    cout << "================================================" << endl;
    cout << " C++ HIGGSFEILD AI PROMPT & DATABASE MANAGER" << endl;
    cout << "================================================" << endl;

    // Intantiate OOP Objects 
    DataBaseManager dbManager;
    HiggsFieldClient apiManager("YOUR_API_KEY_HERE");

    string userPrompt;
    // Replace your original "Enter a video generation prompt:" section with this menu loop
    cout << "Select an Option:" << endl;
    cout << "1. Create & Save a New Video Prompt" << endl;
    cout << "2. View All Stored Database Prompts" << endl;
    cout << "Enter Choice (1-2): ";
    
    string choice;
    getline(cin, choice);

    if (choice == "2") {
        // Run your newly typed read-back function
        dbManager.readAllPrompts();
    } 
    else if (choice == "1") {
        string userPrompt;
        cout << "\nEnter a video generation prompt: ";
        getline(cin, userPrompt);

        if (userPrompt.empty()) {
            cout << "Prompt cannot be empty. Exiting program." << endl;
            return 1;
        }

        cout << endl << "--- Processing Pipeline ---" << endl;
        dbManager.savePrompt(userPrompt);
        apiManager.dispatchPrompt(userPrompt);
        cout << endl << "Task completed successfully." << endl;
    } 
    else {
        cout << "Invalid choice selection. Exiting program." << endl;
    }
}