#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    //Declarations

    //Strings
    string genIO;

    //Numbers
    int genNum;

    //Open file fstream and create text file for IA (Instant Answer - Cheat Sheet) to be stored in
    ofstream fileout;
    fileout.open ("CheatSheet.json");

    //Vectors
    vector<string> sections;

    //Print welcome message
    cout << "Welcome, I am Ludwig Von Drake, the wise duck that will help you create an cheat sheet instant answer for DuckDuckGo!" << endl;

    //Clear screen upon user clicking a key
    system("pause");
    system("cls");

    //Prompt user to create an IA page
    cout << "First if you haven't done so already, go ahead and make an instant answer page here:" << endl;
    cout << "https://duck.co/ia/new_ia" << endl;

    //Clear screen upon user clicking a key
    system("pause");
    system("cls");

    //Start constructing IA
    fileout << "{\n";

    //Ask for id
    cout << "Great! Now enter your cheat sheet's id. You can find that in the IA page you just created." << endl;
    cout << "Enter id: ";
    cin >> genIO;
    cin.ignore();

    //Write id to CheatSheet
    fileout << "\t\"id\": \"" << genIO << "\",\n";

    //Ask for name
    cout << "Now enter your cheat sheet's name. That can also be found in the IA Page you created." << endl;
    cout << "Enter name: ";
    getline(cin, genIO);

    //Write id to CheatSheet
    fileout << "\t\"name\": \"" << genIO << "\",\n";

    //Ask for description
    cout << "Now enter your cheat sheet's description. That was also in the IA Page you created." << endl;
    cout << "Enter description: ";
    getline(cin, genIO);

    //Write id to CheatSheet
    fileout << "\t\"description\": \"" << genIO << "\",\n";

    //Ask for metadata & sources
    cout << "Excellent! Now, a cheat sheet should always contain reference to its source of information. So give us your source (the name of the page you got your information)." << endl;
    cout << "Enter source page name: ";
    getline(cin, genIO);

    //Write source name to CheatSheet
    fileout << "\t\"metadata\": {\n";
    fileout << "\t\t\"sourceName\": \"" << genIO << "\",\n";

    //Ask for source name URL and write to file
    cout << "Enter source page URL: ";
    getline(cin, genIO);
    fileout << "\t\t\"sourceUrl\": \"" << genIO << "\"\n";
    fileout << "\t},\n";

    //Ask for aliases
    fileout << "\t\"aliases\": [\n";
    cout << "Now enter your cheat sheet's aliases. These are words that when combined with words such as: cheats, codes etc trigger the IA. For example for World of Warcraft an alias would be WoW. A cheat sheet can have from none to many aliases." << endl;
    cout << "Do you want to enter an alias? (Y/n)" << endl;
    getline(cin, genIO);

    while(genIO == "Y"){
        cout << "Enter alias: ";
        getline(cin, genIO);
        fileout << "\t\t\"" << genIO << "\"";
        cout << "Do you want to enter another alias? (Y/n)" << endl;
        getline(cin, genIO);
        if(genIO == "Y"){
            fileout << ",\n";
        }else{
            fileout << "\n";
        }
    }

    fileout << "\t],\n";

    //Ask for template type
    cout << "Now lets decide how your cheat sheet looks and behaves. This depends on the template (e.g: terminal, keys etc)." << endl;
    cout << "To learn more about available templates see: https://docs.duckduckhack.com/frontend-reference/templates-overview.html" << endl;
    cout << "Enter a template name (e.g: terminal): ";
    getline(cin, genIO);

    //Write template type to CheatSheet
    fileout << "\t\"template_type\": \"" << genIO << "\",\n";

    //Ask for sections_order
    fileout << "\t\"section_order\": [\n";
    cout << "Now enter your cheat sheet's sections in the order you wish them to appear. Like good books are divided in chapters, cheat sheets are divided in sections (from one to many)." << endl;
    genIO = "Y";

    while(genIO == "Y"){
        cout << "Enter section: ";
        getline(cin, genIO);
        sections.push_back(genIO);
        fileout << "\t\t\"" << genIO << "\"";
        cout << "Do you want to enter another section? (Y/n)" << endl;
        getline(cin, genIO);
        if(genIO == "Y"){
            fileout << ",\n";
        }else{
            fileout << "\n";
        }
    }

    fileout << "\t],\n";

    //Fill in sections
    fileout << "\t\"sections\": {\n";
    genNum = 0;

    //While there are sections remaining to fill in, run this loop
    while(genNum < sections.size()){
        //Write start of new section
        fileout << "\t\t\"" << sections[genNum] << "\": [\n";
        //Set genIO to Y so it enters the first time and if the loop bellow is exited with an n, it means that we have to turn it into a Y again for it to run.
        genIO = "Y";
        while(genIO == "Y"){

            //Entering entries part
            fileout << "\t\t\t{\n";
            cout << "Now lets create an entry, first you will be asked to enter a val and then a key." << endl;
            cout << "(Example of a val and key: Move forward - W )." << endl;
            cout << "Enter val: ";
            getline(cin, genIO);
            fileout << "\t\t\t\t\"val\": \"" << genIO << "\",\n";
            cout << "Enter key: ";
            getline(cin, genIO);
            fileout << "\t\t\t\t\"key\": \"" << genIO << "\"\n";
            fileout << "\t\t\t}";

            //Ask whether to enter more entries or stop and go to next section
            cout << "Enter more entries under this section? (Y/n) If you say no, we will continue on to the next section." << endl;
            cout << "Enter selection : ";
            getline(cin, genIO);
            //If the answer is yes, put a coma after } in the last entry
            if(genIO == "Y"){
                fileout << ",\n";
            }else{
                fileout << "\n";
            }
            //If the answer is no, put the ending ], to the section
            if(genIO != "Y"){
                //Increase genNum since we are moving to a new section
                genNum++;
                //If genNum = number of sections then we have no more sections so there is no "," after the "]"
                if(genNum == sections.size()){
                    fileout << "\t\t]\n";
                }else{
                    fileout << "\t\t],\n";
                }
            }
        }

    }

    //Closing bracket for sections
    fileout << "\t}\n";

    //Final closing bracket for cheat sheet
    fileout << "}\n";

    //Close txt fstream
    fileout.close();

    //couts for validating json, renaming file and put link on submiting IA
    system("cls");
    cout << "Congratulations! Your Cheat Sheet Instant Answer has been created!" << endl;
    cout << "It is placed in the same directory as this program and is named CheatSheet.json." << endl;
    cout << "If you want to view or edit it just open it with your favorite notepad application." << endl;
    cout << "To validate it use DuckDuckGo's JSON validator (just duck \"json validator\")." << endl;
    cout << "To submit your IA to DuckDuckGo, fork https://github.com/duckduckgo/zeroclickinfo-goodies into your github." <<endl;
    cout << "Create a new branch, rename your JSON file and upload it to zeroclickinfo-goodies/share/goodie/cheat_sheets/json/ in your forked repository." << endl;
    cout << "If you want to test it, read these:" << endl;
    cout << "https://docs.duckduckhack.com/welcome/setup-dev-environment.html" << endl;
    cout << "https://docs.duckduckhack.com/walkthroughs/programming-syntax.html" << endl;
    cout << "Then see here how to submit a pull request: https://docs.duckduckhack.com/submitting/pull-request.html" << endl;
    system("pause");

    return 0;
}
