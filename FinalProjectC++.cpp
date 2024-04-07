#define SIZE 20
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <set>
using namespace std;

struct game
{
    int id;
    char name[50];
    char company[50];
    char genre[70];
    char year[30];
    float rating;
    char processor[100];
    char os[50];
    char ram[50];
    char disk[100];
    char directX[100];
    char price[50];
    char description[200];
    char link[200];

};

void Show(const game& gam)
{
    cout << "Name: " << gam.name << endl;
    cout << "Company: " << gam.company << endl;
    cout << "Genre: " << gam.genre << endl;
    cout << "Year: " << gam.year << endl;
    cout << "Rating: " << gam.rating << endl;
    cout << "Processor: " << gam.processor << endl;
    cout << "Operation system: " << gam.os << endl;
    cout << "RAM: " << gam.ram << endl;
    cout << "Disk: " << gam.disk << endl;
    cout << "DirectX: " << gam.directX << endl;
    cout << "Price: " << gam.price << endl;
    cout << "Description: " << gam.description << endl;
    cout << "Link: " << gam.link << endl;
}

void SearchByName(const game play[], int size, const char* name)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(play[i].name, name) == 0)
        {
            Show(play[i]);
            found = true;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "Game not found" << endl;
    }
}

void SearchByCompany(const game play[], int size, const char* name)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(play[i].company, name) == 0)
        {
            Show(play[i]);
            found = true;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "Game not found" << endl;
    }
}

void SearchByGenre(const game play[], int size, const char* name)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(play[i].genre, name) == 0)
        {
            Show(play[i]);
            found = true;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "Game not found" << endl;
    }
}

void SearchByYear(const game play[], int size, const char* name)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(play[i].year, name) == 0)
        {
            Show(play[i]);
            found = true;
            cout << endl;
        }
    }
    if (!found)
    {
        cout << "Game not found" << endl;
    }
}

void ShowAll(const game play[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "ID: " << play[i].id << endl;
        cout << "Name: " << play[i].name << endl;
        cout << "Company: " << play[i].company << endl;
        cout << "Genre: " << play[i].genre << endl;
        cout << "Year: " << play[i].year << endl;
        cout << "Rating: " << play[i].rating << endl;
        cout << "Processor: " << play[i].processor << endl;
        cout << "OS: " << play[i].os << endl;
        cout << "RAM: " << play[i].ram << endl;
        cout << "Disk: " << play[i].disk << endl;
        cout << "DirectX: " << play[i].directX << endl;
        cout << "Price: " << play[i].price << endl;
        cout << "Description: " << play[i].description << endl;
        cout << "Link: " << play[i].link << endl;
        cout << endl;
    }
}

void TheMostPopular(const game play[], int size)
{
    double maxRating = 0;

    for (int i = 0; i < size; i++)
    {
        if (play[i].rating > maxRating)
        {
            maxRating = play[i].rating;
        }
    }

    bool found = false;

    for (int i = 0; i < size; i++)
    {
        if (play[i].rating == maxRating)
        {
            Show(play[i]);
            found = true;
            cout << endl;
        }
    }

    if (!found)
    {
        cout << "No game with the best rating" << endl;
    }
}

void ChangeData(game play[], int size, int id)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (play[i].id == id)
        {
            Show(play[i]);
            cout << "Enter name: ";
            cin >> play[i].name;
            cout << "Enter company: ";
            cin >> play[i].company;
            cout << "Enter genre: ";
            cin >> play[i].genre;
            cout << "Enter year: ";
            cin >> play[i].year;
            cout << "Enter rating: ";
            cin >> play[i].rating;
            cout << "Enter processor: ";
            cin >> play[i].processor;
            cout << "Enter operation system: ";
            cin >> play[i].os;
            cout << "Enter RAM: ";
            cin >> play[i].ram;
            cout << "Enter disk: ";
            cin >> play[i].disk;
            cout << "Enter directX: ";
            cin >> play[i].directX;
            cout << "Enter price: ";
            cin >> play[i].price;
            cout << "Enter description: ";
            cin >> play[i].description;
            cout << "Enter link: ";
            cin >> play[i].link;
            cin.ignore();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Film to change data not found" << endl;
    }
}

void SaveToFile(const game play[], int size, const char* filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            file << play[i].id << endl;
            file << play[i].name << endl;
            file << play[i].company << endl;
            file << play[i].genre << endl;
            file << play[i].year << endl;
            file << play[i].rating << endl;
            file << play[i].processor << endl;
            file << play[i].os << endl;
            file << play[i].ram << endl;
            file << play[i].disk << endl;
            file << play[i].directX << endl;
            file << play[i].description << endl;
            file << play[i].link << endl;
        }
    }
    else
    {
        cerr << "Error opening file" << endl;
        return;
    }
    file.close();
}

void LoadFromFile(game play[], int& size, const char* filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file" << endl;
        return;
    }
    else
    {
        size = 0;
        while (size < SIZE && file >> play[size].id)
        {
            file.ignore();
            file.getline(play[size].name, 50);
            file.getline(play[size].company, 50);
            file.getline(play[size].genre, 70);
            file.getline(play[size].year, 30);
            file >> play[size].rating;
            file.ignore();
            file.getline(play[size].processor, 100);
            file.getline(play[size].os, 50);
            file.getline(play[size].ram, 50);
            file.getline(play[size].disk, 100);
            file.getline(play[size].directX, 100);
            file.getline(play[size].price, 50);
            file.getline(play[size].description, 200);

            size++;
        }
    }
    file.close();
}

void Exit()
{
    exit(0);
}

void recommendRandomGames(const game games[], int size) {
    srand(time(0)); 
    int randomIndex = rand() % size; 
    cout << "Recommended game: " << games[randomIndex].name << endl; 
}

int main()
{
    int choice;
    game games[SIZE] = {
        {1, "Counter Strike 2", "Valve", "First person shooter", "2023", 7.9, "Intel Core i5-750 and more", "Windows 10 and more", "8 GB and more", "85 GB", "11 and more", "Free", "Counter Strike 2 - sequel to the iconic multiplayer FPS, featuring intense team - based combat, diverse maps, and strategic gameplay, developed by Valve Corporation.", "https://store.steampowered.com/app/730/CounterStrike_2/"},
        {2, "Metro Exodus", "4A Games", "First person shooter", "2019", 9.4, "Intel Core i5-4440 and more", "Windows 7 and more", "8 GB and more", "59 GB", "11 and more", "20.58$ or 799 UAH", "Metro Exodus - an epic post-apocalyptic game by 4A Games. Players survive in a Soviet world, exploring mysterious territories and battling mutants and humans alike.", "https://store.steampowered.com/app/412020/Metro_Exodus/"},
        {3, "S.T.A.L.K.E.R.", "GSC Game World", "Survival horror", "2007", 9.0, "Intel Pentium 4 2.0 GHz and more", "Windows XP and more", "512 MB and more", "6 GB", "9 and more", "7.19$ or 279 UAH", "S.T.A.L.K.E.R.: Shadow of Chernobyl - an immersive FPS set in the Chernobyl Exclusion Zone, blending survival horror elements with intense gunplay and atmospheric exploration.", "https://store.steampowered.com/app/4500/STALKER_Shadow_of_Chernobyl/"},
        {4, "Grand Theft Auto V", "Rockstar North", "Action-adventure", "2013", 9.5, "Intel Core 2 Quad CPU Q6600 @ 2.40GHz (4 CPUs) and more", "Windows 10 and more", "4 GB and more", "110 GB", "10 and more", "8.06$ or 312 UAH", "Grand Theft Auto V - an action-packed open-world adventure set in the fictional state of San Andreas, featuring a gripping storyline, diverse characters, and endless opportunities for mayhem.", "https://store.steampowered.com/app/271590/Grand_Theft_Auto_V/"},
        {5, "Crysis", "Crytek", "First person shooter", "2008", 9.3, "Intel Core i5-3450 and more", "Windows 10 and more", "8 GB and more", "20 GB", "9 and more", "9.76$ or 379 UAH", "Crysis - a groundbreaking FPS renowned for its stunning visuals and open-ended gameplay, where players wield an advanced nanosuit to confront an alien invasion in a lush tropical setting.", "https://store.steampowered.com/app/17330/Crysis_Warhead/"},
        {6, "Call of Duty: Ghosts", "Infinity Ward", "First person shooter", "2013", 9.2, "Intel Core 2 Duo E8200 2.66 GHZ and more", "Windows 7 and more", "6 GB and more", "40 GB", "11 and more", "52.42$ or 2035 UAH", "Call of Duty - a classic first-person shooter set in various historical periods, featuring intense combat and immersive storytelling.", "https://store.steampowered.com/app/209160/Call_of_Duty_Ghosts/"},
        {7, "God of War", "Santa Monica Studio", "Action-adventure", "2022", 9.6, "Intel Core i5-2500K and more", "Windows 10 and more", "8 GB and more", "70 GB", "11 and more", "30.99$ or 1199 UAH", "God of War - an epic action-adventure game based on Greek mythology, following the journey of Kratos as he seeks revenge against the gods.", "https://store.steampowered.com/app/1593500/God_of_War/"},
        {8, "PUBG", "PUBG Corporation", "Battle royale", "2017", 8.8, "Intel Core i5-4430 and more", "Windows 10 and more", "8 GB and more", "40 GB", "11 and more", "Free", "PlayerUnknown's Battlegrounds (PUBG) - a popular battle royale game where players fight to be the last one standing on a remote island.", "https://store.steampowered.com/app/578080/PUBG_BATTLEGROUNDS/"},
        {9, "Cyberpunk 2077", "CD Projekt Red", "Action role-playing", "2020", 9.1, "Intel Core i7-6700 and more", "Windows 10 and more", "12 GB and more", "70 GB", "12", "14.14$ or 549 UAH", "Cyberpunk 2077 - a futuristic open-world RPG set in the dystopian Night City, offering deep storytelling and immersive gameplay.", "https://store.steampowered.com/app/1091500/Cyberpunk_2077/"},
        {10, "The Sims 4", "Maxis", "Life simulation", "2014", 8.2, "Intel Core i3-3220 and more", "Windows 10 and more", "4 GB and more", "26 GB", "11 and more", "Free", "The Sims 4 - a popular life simulation game where players create and control virtual people, building homes, and guiding their lives.", "https://store.steampowered.com/app/1222670/The_Sims_4/"},
        {11, "Mortal Combat X", "NetherRealm Studios", "Fighting", "2015", 9.1, "Intel Core i5-750 and more", "Windows 7 and more", "3 GB and more", "36 GB", "11 and more", "14.99$ or 549 UAH", "Mortal Kombat - a legendary fighting game franchise known for its intense combat, brutal fatalities, and diverse roster of characters.", "https://store.steampowered.com/app/307780/Mortal_Kombat_X/"},
        {12, "Spider-Man 2", "Insomniac Games", "Action-adventure", "2023", 9.4, "Intel Core i5-4670 and more", "Windows 10 abd more", "8 GB and more", "75 GB", "12", "36.04$ or 1399 UAH", "Spider-Man 2 - a thrilling action-adventure game based on the popular Marvel superhero, featuring web-slinging traversal, dynamic combat, and an open-world New York City to explore.", "https://store.steampowered.com/app/1817190/Marvels_SpiderMan_Miles_Morales/"},
        {13, "Witcher 3", "CD Projekt Red", "Action role-playing", "2015", 8.9, "Intel Core i5-2500K and more", "Windows 7 and more", "6 GB and more", "50 GB", "11 and more", "4.69$ or 182 UAH", "The Witcher 3 - an epic action RPG set in a rich fantasy world, following the adventures of Geralt of Rivia as he hunts monsters, explores vast landscapes, and makes morally ambiguous choices.", "https://store.steampowered.com/app/292030/_3/"},
        {14, "Assassin's Creed Odyssey", "Ubisoft", "Action-adventure", "2018", 9.6, "Intel Core i5 2400 and more", "Windows 10 and more", "8 GB and more", "46 GB", "11 and more", "4.87$ or 189 UAH", "Assassin's Creed - a historical action-adventure series set in various time periods, featuring stealth-based gameplay, parkour traversal, and engaging narratives.", "https://store.steampowered.com/app/812140/Assassins_Creed_Odyssey/"},
        {15, "Forza Horizon 5", "Playground Games", "Race", "2021", 8.8, "Intel Core i5-4460 and more", "Windows 10 and more", "8 GB and more", "110 GB", "12", "30.89$ or 1199 UAN", "Forza Horizon 5 is an arcade racing simulator video game. Playground Games is the developer, and Xbox Game Studios is the publisher.", "https://store.steampowered.com/app/1551360/Forza_Horizon_5/"}
    };
    do
    {
        cout << "----- Menu -----" << endl;
        cout << "[1] - Search by name " << endl;
        cout << "[2] - Search by company " << endl;
        cout << "[3] - Search by genre " << endl;
        cout << "[4] - Search by year " << endl;
        cout << "[5] - The most popular " << endl;
        cout << "[6] - Show all " << endl;
        cout << "[7] - Change data " << endl;
        cout << "[8] - Write to file " << endl;
        cout << "[9] - Load from file " << endl;
        cout << "[0] - Exit " << endl;
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
        {
            const char* playNames[15] = { "Counter Strike 2", "Metro Exodus", "S.T.A.L.K.E.R.", "Grand Theft Auto V", "Crysis", "Call of Duty: Ghosts", "God of War", "PUBG", "Cyberpunk 2077", "The Sims 4", "Mortal Combat X", "Spider-Man 2", "Witcher 3", "Assassin's Creed Odyssey", "Forza Horizon 5" };

            recommendRandomGames(games, 15);

            char name[50];
            cout << "Enter name of game: ";
            cin.getline(name, 50);

            bool found = false;
            for (int i = 0; i < 15; ++i) {
                if (strcmp(playNames[i], name) == 0) {
                    SearchByName(games, SIZE, name);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Game not found" << endl;
            }

            break;
        }
            case 2:
            {
                char company[50];
                cout << "Enter name of company: " << endl;
                cin.getline(company, 50);
                SearchByCompany(games, SIZE, company);
                break;
            }
            case 3:
            {
                char genre[50];
                cout << "Enter name of genre: " << endl;
                cin.getline(genre, 50);
                SearchByGenre(games, SIZE, genre);
                break;
            }
            case 4:
            {
                char year[50];
                cout << "Enter name of year: " << endl;
                cin.getline(year, 30);
                SearchByYear(games, SIZE, year);
                break;
            }
            case 5:
            {
                TheMostPopular(games, SIZE);
                break;
            }
            case 6:
            {
                ShowAll(games, SIZE);
                break;
            }
            case 7:
            {
                int id;
                cout << "Enter id: " << endl;
                cin >> id;
                ChangeData(games, SIZE, id);
                break;
            }
            default:
            {
                cout << "Invalid choice, try one more time" << endl;
                break;
            }
            case 8:
            {
                char filename[50];
                cout << "Enter name for you file: ";
                cin.getline(filename, 50);
                SaveToFile(games, SIZE, filename);
                break;
            }
            case 9:
            {
                int size;
                char filename[50];
                cout << "Enter name of you file: ";
                cin.getline(filename, 50);
                LoadFromFile(games, size, filename);
                break;
            }
            case 0:
            {
                Exit();
                break;
            }
        }
    } while (true);
}
