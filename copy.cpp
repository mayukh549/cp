#include <bits/stdc++.h>

using namespace std;
int main() {
 // Replace with the destination file name
    cout<<"enter source file name";
    string sourceFilename;
    cin>>sourceFilename;
    cout<<"enter destination Filename";
    string destinationFilename;
    cin>>destinationFilename;

    std::ifstream sourceFile(sourceFilename);
    std::ofstream destinationFile(destinationFilename, std::ios::app);

    if (!sourceFile) {
        std::cout << "Failed to open source file: " << sourceFilename << std::endl;
        return 1;
    }

    if (!destinationFile) {
        std::cout << "Failed to open destination file: " << destinationFilename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(sourceFile, line)) {
        destinationFile << line << std::endl;
    }

    std::cout << "File copied successfully!" << std::endl;

    sourceFile.close();
    destinationFile.close();

    return 0;
}
