#include <iostream>
#include <string>
#include <vector> //vector library for vector data type
#include <fstream> //fstraem library for reading from files
#include <conio.h> //istream input and output library
using namespace std;

class Audio  //virtual parent class
{
public:
    virtual double getTotalPrice() = 0;  //functions to be defined in child classes
    virtual void displayInfo() = 0;
    virtual string getName() = 0;
};

class EntertainmentAudio : public Audio
{
protected:

    string Genre;
    string Description;
    int Year;
    double LowFreq;
    double Price1;
public:

    EntertainmentAudio() //constructors
    {

        Genre = "g";
        Description = "des";
        Year = 0;
        LowFreq = 0;
        Price1 = 0;
    }
    EntertainmentAudio(string g, string des, int y, double freq, double pr)
    {

        Genre = g;
        Description = des;
        Year = y;
        LowFreq = freq;
        Price1 = pr;

    }

    string getGenre() { return Genre; } //getters
    string getDescription() { return Description; }

    //setters
    void setYear(int y)
    {
        if (y < 0) {
            cout << "Invalid value! Setting year to 1950" << endl;
            Year = 1950;
        }
        else Year = y;
    }
    void setLowFreq(double freq)
    {
        if (freq < 0) {
            cout << "Invalid value! Setting the frequency to 0" << endl;
            LowFreq = 0;
        }
        else LowFreq = freq;
    }

    void setPrice1(double pr)
    {
        if (pr < 0) {
            cout << "Invalid value! Setting price to 0" << endl;
            Price1 = 0;
        }
        else Price1 = pr;
    }

    virtual double getTotalPrice() = 0; //calculates the total price for the purchase of the Audios
    virtual void displayInfo() = 0; //displays the different informations about each Audio
    virtual string getName() = 0; //returns the Name of each element and is used to check later on that the user doesn't input the same element twice

};



class InformationalAudio : public Audio
{
protected:

    string Topic;
    int Duration;
    double Price2;
    int Year1;
public:

    InformationalAudio() //constructors
    {
        Topic = "t";
        Duration = 0;
        Price2 = 0;
        Year1 = 1950;
    }
    InformationalAudio(string t, int dur, double pr2, int yr)
    {
        Topic = t;
        Duration = dur;
        Price2 = pr2;
        Year1 = yr;
    }

    string getTopic() { return Topic; } //getter

    //setters
    void setDuration(double dur)
    {
        if (dur < 0) {
            cout << "Invalid value! Setting the duration to 0" << endl;
            Duration = 0;
        }
        else Duration = dur;
    }

    void setPrice2(double pr2)
    {
        if (pr2 < 0) {
            cout << "Invalid value! Setting price to 0" << endl;
            Price2 = 0;
        }
        else Price2 = pr2;
    }

    void setYear1(int yr)
    {
        if (yr < 0) {
            cout << "Invalid value! Setting year to 1950" << endl;
            Year1 = 1950;
        }
        else Year1 = yr;
    }

    virtual double getTotalPrice() = 0; //calculates the total price for the purchase of the Audios
    virtual void displayInfo() = 0; //displays the different informations about each Audio
    virtual string getName() = 0; //returns the Name of each element and is used to check later on that the user doesn't input the same element twice

};

class Albums : public EntertainmentAudio
{
private:
    string ArtistName; //more data members which are specific for Album
    string AlbumName;
    int AlbumSongs;
public:
    Albums() //constructors
    {
        ArtistName = "arn";
        AlbumName = "an";
        AlbumSongs = 1;
    }
    Albums(string g, string des, int y, double freq, double pr, string arn, string an, int as) :EntertainmentAudio(g, des, y, freq, pr)
    {
        ArtistName = arn;
        AlbumName = an;
        AlbumSongs = as;
    }

    string getArtistName() { return ArtistName; } //getters
    string getAlbumName() { return AlbumName; }

    //setters
    void setAlbumSongs(int s)
    {
        if (s < 1) {
            cout << "Invalid value! Setting album songs to 1" << endl;
            AlbumSongs = 1;
        }
        else AlbumSongs = s;
    }

    double getTotalPrice() {
        return Price1 * (AlbumSongs / 3.0); //calculating the total price depending on the price and album songs in the txt file
    }
    void displayInfo() {

        //displays information about an Album
        cout << endl << "The Artist is: " << ArtistName << endl;
        cout << "The Album is: " << AlbumName << endl;
        cout << "Description: " << Description << endl;
        cout << "Genre: " << Genre << endl;
        cout << "Year of creation: " << Year << endl;
        cout << "Price: $" << getTotalPrice() << endl;
    }
    string getName() {
        return AlbumName; //overrides the function to return the Name of an Album
    }
};

class Concerts : public EntertainmentAudio
{
private:
    string ArtistConcertName; //more data members which are specific for Concert
    string ConcertName;
    string Location;
    int ConcertSongs;
public:
    Concerts() //constructors
    {
        ArtistConcertName = "acn";
        ConcertName = "cn";
        Location = "l";
        ConcertSongs = 1;
    }
    Concerts(string g, string des, int y, double freq, double pr, string acn, string cn, string l, int cs) :EntertainmentAudio(g, des, y, freq, pr)
    {
        ArtistConcertName = acn;
        ConcertName = cn;
        Location = l;
        ConcertSongs = cs;
    }

    string getArtistConcertName() { return ArtistConcertName; } //getters
    string getConcertName() { return ConcertName; }
    string getLocation() { return Location; }

    //setters
    void setSongs(int s)
    {
        if (s < 1) {
            cout << "Invalid value! Setting songs to 1" << endl;
            ConcertSongs = 1;
        }
        else ConcertSongs = s;
    }

    double getTotalPrice() {
        return Price1 * (ConcertSongs / 5.0); //calculating the total price depending on the Price and Concert Songs from the txt file
    }
    void displayInfo() {

        //displays information about a Concert
        cout << endl << "The Artist is: " << ArtistConcertName << endl;
        cout << "The Concert Name is: " << ConcertName << endl;
        cout << "Description: " << Description << endl;
        cout << "Genre: " << Genre << endl;
        cout << "The Year of Creation is: " << Year << endl;
        cout << "Price: $" << getTotalPrice() << endl;
    }
    string getName() {
        return ConcertName; //overrides the function to return the Name of a Concert
    }
};

class MovieSoundtracks : public EntertainmentAudio
{
private:
    string MovieName; //more data memebers specific for MovieSoundtracks
    string SoundtrackName;
    string Composer;
    int Soundtracks;
public:
    MovieSoundtracks() //constructors
    {
        MovieName = "mn";
        SoundtrackName = "sn";
        Composer = "c";
        Soundtracks = 1;
    }
    MovieSoundtracks(string g, string des, int y, double freq, double pr, string mn, string sn, string c, int st) :EntertainmentAudio(g, des, y, freq, pr)
    {
        MovieName = mn;
        SoundtrackName = sn;
        Composer = c;
        Soundtracks = st;
    }

    string getMovieName() { return MovieName; } //getters
    string getSoundtrackName() { return SoundtrackName; }
    string getComposer() { return Composer; }

    //setter
    void setSoundtracks(int st)
    {
        if (st < 1) {
            cout << "Invalid value! Setting Soundtracks to 1" << endl;
            Soundtracks = 1;
        }
        else Soundtracks = st;
    }

    double getTotalPrice() {
        return Price1 * (Soundtracks / 4.0);  //calculating the total price depending on the Price and Soundtracks from the txt file
    }
    void displayInfo() {

        //displays information about a MovieSoundtrack
        cout << endl << "The Movie's Name is: " << MovieName << endl;
        cout << "The Soundtrack's Name is: " << SoundtrackName << endl;
        cout << "The Composer is: " << Composer << endl;
        cout << "Description: " << Description << endl;
        cout << "The Year of Creation is: " << Year << endl;
        cout << "Price: $" << getTotalPrice() << endl;
    }
    string getName() {
        return SoundtrackName; //overrides the function to return the name of a MovieSoundtrack
    }
};

class Podcasts : public InformationalAudio
{
private:
    string PodcastName; //more data members specific for Podcasts
    string HostName;

public:
    Podcasts() //constructors
    {
        PodcastName = "pn";
        HostName = "hn";

    }
    Podcasts(string t, int dur, double pr2, int yr, string pn, string hn) :InformationalAudio(t, dur, pr2, yr)
    {
        PodcastName = pn;
        HostName = hn;

    }

    string getPodcastName() { return PodcastName; } //getters
    string getHostName() { return HostName; }


    double getTotalPrice() {
        return Price2 * 4;  //calculating the total price depending on the Price from the txt file multiplied by 4. 
    }
    void displayInfo() {

        //displays information about a Podcast
        cout << endl << "The Podcast Name is: " << PodcastName << endl;
        cout << "The Host Name is: " << HostName << endl;
        cout << "The Topic is: " << Topic << endl;
        cout << "The Year of Creation is: " << Year1 << endl;
        cout << "Price: $" << getTotalPrice() << endl;
    }
    string getName() {
        return PodcastName; //overrides the function to return the name of a Podcast
    }
};

class News : public InformationalAudio
{
private:
    string Title; //more data members specific for News
    string Author;
    string Place;

public:
    News() //constructors
    {
        Title = "tit";
        Author = "sp";
        Place = "pl";

    }
    News(string t, int dur, double pr2, int yr, string tit, string sp, string pl) :InformationalAudio(t, dur, pr2, yr)
    {
        Title = tit;
        Author = sp;
        Place = pl;

    }

    string getTitle() { return Title; } //getters
    string getAuthor() { return Author; }
    string getPlace() { return Place; }


    double getTotalPrice() {
        return Price2 * 3;//calculating the total price depending on the Price from the txt file multiplied by 3. 
    }
    void displayInfo() {

        //displays information about a News Article
        cout << endl << "The News Title is: " << Title << endl;
        cout << "The Author is: " << Author << endl;
        cout << "The Topic is: " << Topic << endl;
        cout << "The Year of Creation is: " << Year1 << endl;
        cout << "Price: $" << getTotalPrice() << endl;
    }
    string getName() {
        return Title; //overrides the function to return the name of a News article
    }
};

//defining vectors for storing the data for each Audio
vector<Audio*> Album;
vector<Audio*> Concert;
vector<Audio*> Soundtrack;
vector<Audio*> Podcast;
vector<Audio*> New;
vector<Audio*> Purchase; //and vector for the purchase

//Mergesort sorting algorithm
//Internal recursive routine, tmpArray is used for placing the merged result
template <class Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmpArray, int left, int right)
{
    if (left < right) {
        int center = (left + right) / 2;
        mergeSort(a, tmpArray, left, center);
        mergeSort(a, tmpArray, center + 1, right);
        merge(a, tmpArray, left, center + 1, right);
    }
}

template <class Comparable>
void mergeSort(vector<Comparable>& a)
{
    vector<Comparable> tmpArray(a.size());
    mergeSort(a, tmpArray, 0, a.size() - 1);
}

template <class Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmpArray, int leftPos, int rightPos, int rightEnd) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while (leftPos <= leftEnd && rightPos <= rightEnd)   // the main loop
        if (a[leftPos]->getTotalPrice() <= a[rightPos]->getTotalPrice()) //Compare the elements based on their total price in order low to high
            tmpArray[tmpPos++] = a[leftPos++];
        else
            tmpArray[tmpPos++] = a[rightPos++];

    while (leftPos <= leftEnd)   //Copy the rest of first half
        tmpArray[tmpPos++] = a[leftPos++];

    while (rightPos <= rightEnd)   //Copy the rest of right half
        tmpArray[tmpPos++] = a[rightPos++];

    for (int i = 0; i < numElements; i++, rightEnd--)   //Copy tmpArray back
        a[rightEnd] = tmpArray[rightEnd];
}

void readInfo(string file) { //function to read the information from the input files
    ifstream ins;
    ins.open(file);
    if (ins.fail()) {
        cout << "Error opening " << file << endl;
    }

    while (!ins.eof()) {
        if (file == "Albums.txt") { //reads the data from the Albums file and stores it into our program for later use
            string g; string des; int y; double freq; double pr; string arn; string an; int as;
            ins >> g >> des >> y >> freq >> pr >> arn >> an >> as; //reads and assigns values for the variables
            Album.push_back(new Albums(g, des, y, freq, pr, arn, an, as));
        }
        if (file == "Concerts.txt") { //reads the data from the Concerts file and stores it into our program for later use
            string g; string des; int y; double freq; double pr; string acn; string cn; string l; int cs;
            ins >> g >> des >> y >> freq >> pr >> acn >> cn >> l >> cs; //reads and assigns values for the variables
            Concert.push_back(new Concerts(g, des, y, freq, pr, acn, cn, l, cs));
        }
        if (file == "Soundtracks.txt") { //reads the data from the Soundtracks file and stores it into our program for later use
            string g; string des; int y; double freq; double pr; string mn; string sn; string c; int st;
            ins >> g >> des >> y >> freq >> pr >> mn >> sn >> c >> st; //reads and assigns values for the variables
            Soundtrack.push_back(new MovieSoundtracks(g, des, y, freq, pr, mn, sn, c, st));
        }
        if (file == "Podcasts.txt") { //reads the data from the Podcasts file and stores it into our program for later use
            string t; int dur; double pr2; int yr; string pn; string hn;
            ins >> t >> dur >> pr2 >> yr >> pn >> hn; //reads and assigns values for the variables
            Podcast.push_back(new Podcasts(t, dur, pr2, yr, pn, hn));
        }
        if (file == "News.txt") { //reads the data from the News file and stores it into our program for later use
            string t; int dur; double pr2; int yr;; string tit; string sp; string pl;
            ins >> t >> dur >> pr2 >> yr >> tit >> sp >> pl; //reads and assigns values for the variables
            New.push_back(new News(t, dur, pr2, yr, tit, sp, pl));
        }
    }
    ins.close();

    //calling mergeSort() to sort each Audio category based on the elements' total price (from low to high)
    mergeSort(Album);
    mergeSort(Concert);
    mergeSort(Soundtrack);
    mergeSort(Podcast);
    mergeSort(New);
}

int main() {
    int n; //random variables to store the users' inputs
    int m;
    double p;


    //the info from each file is read
    readInfo("Albums.txt");
    readInfo("Concerts.txt");
    readInfo("Soundtracks.txt");
    readInfo("Podcasts.txt");
    readInfo("News.txt");

    do {  //repeat the menu until the user decides to purchase
        double sum = 0; //local variable to store the sum of all prices to show a final price 

        cout << endl << "What kind of audio do you want to choose from ? " << endl;
        cout << "If you want to choose from Entertainment Audio ENTER 1, and if you want to choose from Informational Audio ENTER 2. " << endl;
        cout << "To view your cart ENTER 8, if you are ready to purchase ENTER 9. " << endl;
        cout << "If you want to exit the Audio Store ENTER 0. " << endl;
        cout << endl << "Your selection: ";
        cin >> n; //local variable that stores the users' input

        // this clears the screen 
        system("cls");

        if (n == 0) return 0; //if the user enters 0 the program is shut down

        if (n == 1) { //based on the answer different categories to choose from are shown
            cout << "You can choose from Albums, Concerts, and Movie Soundtracks." << endl << "Enter 1 for Albums, 2 for Concerts, 3 for Movie Soundtracks: ";
            cin >> m;
            if (m == 1) { //based on the answers a different data file is opened for the user to choose from - for 1 it is Albums

                for (int i = 0; i < Album.size(); i++) //loop to access each element of Albums vector and display all elements based on their price, in low to high order
                    Album.at(i)->displayInfo();

                cout << endl << "If you want to choose an Audio from this category, ENTER the exact price of the Audio, else ENTER 0 to return to Menu: "; cin >> p;
                if (p != 0) {
                    bool a = false; //bool a for checking if the price was found, starting with false
                    for (int i = 0; i < Album.size(); i++) { //loop for the Albums vector

                        if (Album.at(i)->getTotalPrice() == p) { //if at any point we have a match in price and element we need to check if the element has already been added
                            a = true; //changing a to indicate that the price has been found 

                            bool b = false; //bool variable b to check if the element exists, starting as false
                            for (int j = 0; j < Purchase.size(); j++) //checking all elements in purchases
                            {
                                string z = Album.at(i)->getName(); //adding a string z variable for readability
                                if (Purchase.at(j)->getName() == z) b = true;  // if an element with the same name already exists, the bool b becomes true
                            }
                            if (b == false) { // the element is only added if b is false (if it's not already been added)
                                Purchase.push_back(Album.at(i));

                            }
                            else { //if the user selects the same item twice this message is shown and the user is brought to main menu
                                cout << endl << "This Audio has already been added!" << endl;
                                cout << endl << "Press any key to return to Menu. ";
                                _getch();  //get entry from the user to return them to main menu
                            }
                        }

                    }
                    if (a == false) { //if the price has not been found, a message is displayed to the user
                        cout << "Price not found."; _getch(); //get entry from the user to return them to main menu
                    }
                }
                // this clears the screen 
                system("cls");
            }
            else if (m == 2) { //based on the answers a different data file is opened for the user to choose from - for 2 it is Concerts

                for (int i = 0; i < Concert.size(); i++) //loop to access each element of Concerts vector and display all elements based on their price, in low to high order
                    Concert.at(i)->displayInfo();

                cout << endl << "If you want to choose an Audio from this category, ENTER the exact price of the Audio, else ENTER 0 to return to Menu: "; cin >> p;
                if (p != 0) {
                    bool a = false; //bool a for checking if the price was found, starting with false
                    for (int i = 0; i < Concert.size(); i++) { //loop for the Albums vector

                        if (Concert.at(i)->getTotalPrice() == p) { //if at any point we have a match in price and element we need to check if the element has already been added
                            a = true; //changing a to indicate that the price has been found 

                            bool b = false; //bool variable b to check if the element exists, starting as false
                            for (int j = 0; j < Purchase.size(); j++) //checking all elements in purchases
                            {
                                string z = Concert.at(i)->getName(); //adding a string z variable for readability
                                if (Purchase.at(j)->getName() == z) b = true;  // if an element with the same name already exists, the bool b becomes true
                            }
                            if (b == false) { // the element is only added if b is false (if it's not already been added)
                                Purchase.push_back(Concert.at(i));

                            }
                            else { //if the user selects the same item twice this message is shown and the user is brought to main menu
                                cout << endl << "This Audio has already been added!" << endl;
                                cout << endl << "Press any key to return to Menu. ";
                                _getch();  //Get entry from the user to return them to main menu
                            }
                        }
                    }
                    if (a == false) { //if the price has not been found, a message is displayed to the user
                        cout << "Price not found."; _getch(); //Get entry from the user to return them to main menu
                    }
                }
                // this clears the screen 
                system("cls");
            }
            else if (m == 3) { //based on the answers a different data file is opened for the user to choose from - for 3 it is Soundtracks

                for (int i = 0; i < Soundtrack.size(); i++) //loop to access each element of Soundtracks vector and display all elements based on their price, in low to high order
                    Soundtrack.at(i)->displayInfo();

                cout << endl << "If you want to choose an Audio from this category, ENTER the exact price of the Audio, else ENTER 0 to return to Menu: "; cin >> p;
                if (p != 0) {
                    bool a = false; //bool a for checking if the price was found, starting with false
                    for (int i = 0; i < Soundtrack.size(); i++) { //loop for the Albums vector

                        if (Soundtrack.at(i)->getTotalPrice() == p) { //if at any point we have a match in price and element we need to check if the element has already been added
                            a = true; //changing a to indicate that the price has been found 

                            bool b = false; //bool variable b to check if the element exists, starting as false
                            for (int j = 0; j < Purchase.size(); j++) //checking all elements in purchases
                            {
                                string z = Soundtrack.at(i)->getName(); //adding a string z variable for readability
                                if (Purchase.at(j)->getName() == z) b = true;  // if an element with the same name already exists, the bool b becomes true
                            }
                            if (b == false) { // the element is only added if b is false (if it's not already been added)
                                Purchase.push_back(Soundtrack.at(i));

                            }
                            else { //if the user selects the same item twice this message is shown and the user is brought to main menu
                                cout << endl << "This Audio has already been added!" << endl;
                                cout << endl << "Press any key to return to Menu. ";
                                _getch();  //Get entry from the user to return them to main menu
                            }
                        }

                    }
                    if (a == false) { //if the price has not been found, a message is displayed to the user
                        cout << "Price not found."; _getch(); //get entry from the user to return them to main menu
                    }
                }
                // this clears the screen 
                system("cls");
            }
        }
        else if (n == 2) { //based on the answer different categories to choose from are shown
            cout << "You can choose from Podcasts and News." << endl << "Enter 1 for Podcasts, and 2 for News: ";
            cin >> m;
            if (m == 1) { //based on the answers a different data file is opened for the user to choose from - for 1 it is Podcasts

                for (int i = 0; i < Podcast.size(); i++) //loop to access each element of Podcasts vector and display all elements based on their price, in low to high order
                    Podcast.at(i)->displayInfo();

                cout << endl << "If you want to choose an Audio from this category, ENTER the exact price of the Audio, else ENTER 0 to return to Menu: "; cin >> p;
                if (p != 0) {
                    bool a = false; //bool a for checking if the price was found, starting with false
                    for (int i = 0; i < Podcast.size(); i++) { //loop for the Albums vector

                        if (Podcast.at(i)->getTotalPrice() == p) { //if at any point we have a match in price and element we need to check if the element has already been added
                            a = true; //changing a to indicate that the price has been found 

                            bool b = false; //bool variable b to check if the element exists, starting as false
                            for (int j = 0; j < Purchase.size(); j++) //checking all elements in purchases
                            {
                                string z = Podcast.at(i)->getName(); //adding a string z variable for readability
                                if (Purchase.at(j)->getName() == z) b = true;  // if an element with the same name already exists, the bool b becomes true
                            }
                            if (b == false) { // the element is only added if b is false (if it's not already been added)
                                Purchase.push_back(Podcast.at(i));

                            }
                            else { //if the user selects the same item twice this message is shown and the user is brought to main menu
                                cout << endl << "This Audio has already been added!" << endl;
                                cout << endl << "Press any key to return to Menu. ";
                                _getch();  //Get entry from the user to return them to main menu
                            }
                        }

                    }
                    if (a == false) { //if the price has not been found, a message is displayed to the user
                        cout << "Price not found."; _getch(); //get entry from the user to return them to main menu
                    }
                }
                // this clears the screen 
                system("cls");
            }
            else if (m == 2) { //based on the answers a different data file is opened for the user to choose from - for 2 it is News

                for (int i = 0; i < New.size(); i++) //loop to access each element of News vector and display all elements based on their price, in low to high order
                    New.at(i)->displayInfo();

                cout << endl << "If you want to choose an Audio from this category, ENTER the exact price of the Audio, else ENTER 0 to return to Menu: "; cin >> p;
                if (p != 0) {
                    bool a = false; //bool a for checking if the price was found, starting with false
                    for (int i = 0; i < New.size(); i++) { //loop for the Albums vector

                        if (New.at(i)->getTotalPrice() == p) { //if at any point we have a match in price and element we need to check if the element has already been added
                            a = true; //changing a to indicate that the price has been found 

                            bool b = false; //bool variable b to check if the element exists, starting as false
                            for (int j = 0; j < Purchase.size(); j++) //checking all elements in purchases
                            {
                                string z = New.at(i)->getName(); //adding a string z variable for readability
                                if (Purchase.at(j)->getName() == z) b = true;  // if an element with the same name already exists, the bool b becomes true
                            }
                            if (b == false) { // the element is only added if b is false (if it's not already been added)
                                Purchase.push_back(New.at(i));

                            }
                            else { //if the user selects the same item twice this message is shown and the user is brought to main menu
                                cout << endl << "This Audio has already been added!" << endl;
                                cout << endl << "Press any key to return to Menu. ";
                                _getch();  //Get entry from the user to return them to main menu
                            }
                        }

                    }
                    if (a == false) { //if the price has not been found, a message is displayed to the user
                        cout << "Price not found."; _getch(); //get entry from the user to return them to main menu
                    }
                }
                // this clears the screen 
                system("cls");
            }
        }

        if (n == 8) { // if the user inputs 8 they are shown with the elements they have picked so far for purchase
            if (Purchase.size() == 0) { //if they haven't picked on anything this message will be shown
                cout << "Your cart is empty." << endl;
            }
            else { //their selections are shown
                cout << "Your Audio selections: " << endl;
                for (int i = 0; i < Purchase.size(); i++) { //loop to display the inf. of each Audio that they chose
                    Purchase.at(i)->displayInfo();
                }
                //when they see what they have picked they should press a key to return and continue shopping
                cout << endl << "Press any key to return to Menu. ";
                _getch();  //get char entry from the console to return them to main menu

                system("cls"); //clears the screen 
            }
        }

        if (n == 9) { //if the user is ready to purchase they input 9
            if (Purchase.size() == 0) { //if by any chance the user did not pick anything they will see this message
                cout << "Your cart is empty." << endl;
            }
            else {
                for (int i = 0; i < Purchase.size(); i++) {
                    sum += Purchase.at(i)->getTotalPrice(); //loop to get the price of each element the user chose and sum it 
                }
                cout << "Your Total Price is: $" << sum << endl;
                //promoting different price plans
                if (Purchase.size() > 2 and Purchase.size() < 6) { //if the user picks more than 2 and less than 6 audios they get 5% off the price
                    cout << endl << "You are eligible for 5% discount on your Total Price." << endl;
                    cout << "If you purchase " << (6 - Purchase.size()) << " more Audios, you will be eligible for 10% discount!!!" << endl;
                    sum *= 0.95;
                }
                if (Purchase.size() > 5 and Purchase.size() < 10) { //if the user picks more than 5 and less than 10 audios they get 10% off the price
                    cout << endl << "You are eligible for 10% discount on your Total Price." << endl;
                    cout << "If you purchase " << (10 - Purchase.size()) << " more Audios, you will be eligible for 15% discount!!!" << endl;
                    sum *= 0.9;
                }
                if (Purchase.size() > 9 and Purchase.size() < 15) { //if the user picks more than 9 and less than 15 audios they get 15% off the price
                    cout << endl << "You are eligible for 15% discount on your Total Price." << endl;
                    cout << "If you purchase " << (15 - Purchase.size()) << " more Audios, you will be eligible for 20% discount!!!" << endl;
                    sum *= 0.85;
                }
                if (Purchase.size() > 14 and Purchase.size() < 20) { //if the user picks more than 14 and less than 20 audios they get 20% off the price
                    cout << endl << "You are eligible for 20% discount on your Total Price." << endl;
                    cout << "If you purchase " << (20 - Purchase.size()) << " more Audios, you will be eligible for 25% discount!!!" << endl;
                    sum *= 0.8;
                }
                if (Purchase.size() > 19 and Purchase.size() < 26) { //if the user picks more than 5 and less than 10 audios they get 25% off the price
                    cout << endl << "You are eligible for 25% discount on your Total Price." << endl;
                    cout << "If you purchase " << (26 - Purchase.size()) << " more Audios, you will be eligible for the AMAZING 50% discount!!!" << endl;
                    sum *= 0.75;
                }
                if (Purchase.size() > 25) { //if the user picks more than 25 audios they get 50% on the price
                    cout << endl << "You are eligible for the AMAZING 50% discount on your Total Price!!!!!" << endl;
                    sum *= 0.5;
                }
                cout << endl << "Your Final Price is: $" << sum << endl; //displaying the final price
                cout << "If you want to add more Audios ENTER 0 to return to Menu, if you want to make your Final Purchase ENTER 1: "; //giving different options
                cin >> m;

                //clears screen
                system("cls");
                if (m == 1) {
                    cout << endl << "Thank you for your purchase! Come back again!" << endl;
                    return 0;
                }

            }
        }
    } while (n != 0); //the loop continues and the program runs until the user enters 0

    return 0;
}