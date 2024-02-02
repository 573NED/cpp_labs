#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_RECORDS = 100;  // Максимальное количество записей, можно корректировать

struct MusicRecord {
    string album;
    string track;
    string artist;
    string duration;
};

// Функция для подсчета количества записей в файле
int countRecordsInFile(ifstream& inputFile) {
    int count = 0;
    string line;
    while (getline(inputFile, line)) {
        ++count;
    }
    inputFile.clear();  // Сброс флага конца файла
    inputFile.seekg(0, ios::beg);  // Перемещение указателя файла в начало
    return count;
}

// Функция для вывода списка артистов для указанного альбома
void printArtistList(const MusicRecord records[], int numRecords, const string& album) {
    cout << "artists of the album '" << album << "':\n";
    bool found = false;
    for (int i = 0; i < numRecords; ++i) {
        if (records[i].album == album) {
            cout << records[i].artist << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "no records found for the album '" << album << "'.\n";
    }
}

// Функция для поиска артиста с наибольшим количеством записей
string findArtistWithMostRecords(const MusicRecord records[], int numRecords) {
    string artistWithMostRecords;
    int maxRecordCount = 0;

    for (int i = 0; i < numRecords; ++i) {
        int count = 0;
        for (int j = 0; j < numRecords; ++j) {
            if (records[j].artist == records[i].artist) {
                count++;
            }
        }
        if (count > maxRecordCount) {
            maxRecordCount = count;
            artistWithMostRecords = records[i].artist;
        }
    }

    return artistWithMostRecords;
}

int main() {
    ifstream inputFile("music.txt");
    if (!inputFile.is_open()) {
        cout << "file not found" << endl;
        return 1;
    }

    int numRecords = countRecordsInFile(inputFile);
    cout << "number of records: " << numRecords << endl;

    MusicRecord musicRecords[MAX_RECORDS];

    for (int i = 0; i < numRecords; ++i) {
        MusicRecord record;
        getline(inputFile >> ws, record.album, ',');
        getline(inputFile, record.track, ',');
        getline(inputFile, record.artist, ',');
        getline(inputFile, record.duration, '\n');
        musicRecords[i] = record;
    }

    // Ввод specifiedAlbum с клавиатуры
    cout << "enter the album name: ";
    string specifiedAlbum;
    getline(cin, specifiedAlbum);
    for (char& c : specifiedAlbum) {
        c = tolower(c);
    }

    printArtistList(musicRecords, numRecords, specifiedAlbum);

    string artistWithMostRecords = findArtistWithMostRecords(musicRecords, numRecords);
    cout << "artist with the most records: " << artistWithMostRecords << endl;

    inputFile.close();
    return 0;
}