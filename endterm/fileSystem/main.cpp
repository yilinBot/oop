#include <iostream>

#include "System.h"
#include "Directory.h"
#include "File.h"


using namespace std;

void createSampleSystem(System *sys);
void menu(System *sys);

int main()
{
    System *sys = new System("MySystem","FAT32");
    createSampleSystem(sys);
    menu(sys); //itt nem mûködik...

    return 0;
}

void createSampleSystem(System *sys)
{
    File *f1 = new File("f1.txt",1);
    File *f2 = new File("f2.txt",2);
    File *f3 = new File("f3.txt",3);
    File *f4 = new File("f4.txt",4);
    File *f5 = new File("f5.txt",5);
    File *f6 = new File("f6.txt",6);

    Directory *d1 = new Directory("dir1");
    Directory *d2 = new Directory("dir2");
    Directory *d3 = new Directory("dir3");

    d1->addEntry(f1);
    d1->addEntry(f2);

    d2->addEntry(f3);
    d2->addEntry(f4);

    d3->addEntry(d1);
    d3->addEntry(f5);

    sys->addEntry(d2);
    sys->addEntry(d3);
    sys->addEntry(f6);

    /**std::cout << "Size of the system: " << sys.getSize() << endl;
    cout << "\nPress any key to continue.\n";
    getch(); */

    //menu(sys); ///itt mûködik
}
void menu(System *sys)
{
    std::string entryName;
    do
    {
        cout << "--- Get the size of an entry ---\n";
        cout << "\nType exit to exit.\n";
        cout << "Give the name of the entry: ";
        cin >> entryName;
        if (entryName == "exit") break;
        std::cout<<"\nSearch begins...\n"<<std::endl;
        Entry* entry = sys->searchFor(entryName);
        std::cout<<"\nDone.\n"<<std::endl;
        if (entry != nullptr)
        {
            cout << entry->getName() << " contains" << entry->getVec() << endl;

            cout << "\nThe size of " << entryName << " is: " << entry->getSize() << endl;
        }
        else cout << "\nEntry not found.\n";
        cout << "\nPress any key to continue.\n";
        cin.ignore();
        cin.get();
    } while (true);
}
