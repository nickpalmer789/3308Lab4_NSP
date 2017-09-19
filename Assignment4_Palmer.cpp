#include <iostream>
#include <string>

using namespace std;

void calculateSimilarity(double*, string, string);
void calculateBestMatch(int*, int*, string, string);
void calculateHammingDistance(double*, string, string);
void calculateHammingDistance(int*, string, string);
void promptUser(string);

int main() {
    string humanDNA = "CGCAAATTTGCCGGATTTCCTTTGCTGTTCCTGCATGTAGTTTAAACGAGATTGCCAGCACCGGGTATCATTCACCATTTTTCTTTTCGTTAACTTGCCGTCAGCCTTTTCTTTGACCTCTTCTTTCTGTTCATGTGTATTTGCTGTCTCTTAGCCCAGACTTCCCGTGTCCTTTCCACCGGGCCTTTGAGAGGTCACAGGGTCTTGATGCTGTGGTCTTCATCTGCAGGTGTCTGACTTCCAGCAACTGCTGGCCTGTGCCAGGGTGCAGCTGAGCACTGGAGTGGAGTTTTCCTGTGGAGAGGAGCCATGCCTAGAGTGGGATGGGCCATTGTTCATG";
    string mouseDNA = "CGCAATTTTTACTTAATTCTTTTTCTTTTAATTCATATATTTTTAATATGTTTACTATTAATGGTTATCATTCACCATTTAACTATTTGTTATTTTGACGTCATTTTTTTCTATTTCCTCTTTTTTCAATTCATGTTTATTTTCTGTATTTTTGTTAAGTTTTCACAAGTCTAATATAATTGTCCTTTGAGAGGTTATTTGGTCTATATTTTTTTTTCTTCATCTGTATTTTTATGATTTCATTTAATTGATTTTCATTGACAGGGTTCTGCTGTGTTCTGGATTGTATTTTTCTTGTGGAGAGGAACTATTTCTTGAGTGGGATGTACCTTTGTTCTTG";
    string unknownDNA = "CGCATTTTTGCCGGTTTTCCTTTGCTGTTTATTCATTTATTTTAAACGATATTTATATCATCGGGTTTCATTCACTATTTTTCTTTTCGATAAATTTTTGTCAGCATTTTCTTTTACCTCTTCTTTCTGTTTATGTTAATTTTCTGTTTCTTAACCCAGTCTTCTCGATTCTTATCTACCGGACCTATTATAGGTCACAGGGTCTTGATGCTTTGGTTTTCATCTGCAAGAGTCTGACTTCCTGCTAATGCTGTTCTGTGTCAGGGTGCATCTGAGCACTGATGTGGAGTTTTCTTGTGGATATGAGCCATTCATAGTGTGGGATGTGCCATAGTTCATG";

    //Test the calculateSimilarity function on the strings above
    double similarityToHuman;
    double similarityToMouse;
    calculateSimilarity(&similarityToHuman, unknownDNA, humanDNA);
    calculateSimilarity(&similarityToMouse, unknownDNA, mouseDNA);

    if(similarityToHuman > similarityToMouse) {
        cout<<"Human"<<endl;
    } else if(similarityToMouse > similarityToHuman) {
        cout<<"Mouse"<<endl;
    } else {
        cout<<"Identity cannot be determined."<<endl;
    }

    //Testing the calculateBestMatch function
    cout<<"Which string would you like to search?"<<endl;
    cout<<"1. Human DNA"<<endl;
    cout<<"2. Mouse DNA"<<endl;
    cout<<"3. Unknown DNA"<<endl;
    cout<<"Please enter either 1, 2, or 3: ";
    int choice;
    cin>>choice;

    //Prompt the user based on their choice
    if(choice == 1) {

        promptUser(humanDNA);

    } else if(choice == 2) {

        promptUser(mouseDNA);

    } else if(choice == 3) {

        promptUser(unknownDNA);

    } else {
        cout<<"Invalid input, please try again."<<endl;;
    }

    /*string str1 = "CATCGG";
    string subStr = "DDD";
    int index, hamming;
    calculateBestMatch(&index, &hamming, str1, subStr);
    cout<<"Hamming: "<<hamming<<endl;
    cout<<"Index: "<<index<<endl;

    if(index == -1) {
        cout<<"No match found!"<<endl;
    } else {
        cout<<"Substring: "<<str1.substr(index, subStr.size());
    }*/

    return 0;
}

//Calculate the similarity of two strands of DNA using the hamming distance
void calculateSimilarity(double *similarity, string DNA1, string DNA2) {
    //Get the hamming distance
    double hammingDistance = 0.0;
    calculateHammingDistance(&hammingDistance, DNA1, DNA2);

    //Calculate the similarity score
    *similarity = (DNA1.size() - hammingDistance)/DNA1.size();
}

//Calculates where the best match occurs in a string
void calculateBestMatch(int *index, int *hamming, string dna, string searchString) {
    //Holders for the highest hamming and index found
    int hammingFound = searchString.size();
    int indexFound = -1;

    //Loop through the string to be searched
    for(int i = 0; i < (dna.size() - searchString.size()); i++) {
        //Temporary holder for the hamming score
        int hammingTemp;

        //Get a substring starting at i with length searchString.size()
        string compSubstring = dna.substr(i, searchString.size());


        //Calculate the hamming distance between the substring and the search string
        calculateHammingDistance(&hammingTemp, compSubstring, searchString);

        if(hammingTemp < hammingFound) {
            hammingFound = hammingTemp;
            indexFound = i;

        }
    }

    *index = indexFound;
    *hamming = hammingFound;
}

//Calculates the hamming distance between two strings
//Updates an integer pointer
void calculateHammingDistance(int *hamming, string str1, string str2) {
    int hammingDistance = 0;
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) {
            hammingDistance++;
        }
    }
    *hamming = hammingDistance;
}

//Calculates the hamming distance between two strings
//Updates a double pointer
void calculateHammingDistance(double *hamming, string str1, string str2) {
    double hammingDistance = 0.0;
    for(int i = 0; i < str1.size(); i++) {
        if(str1[i] != str2[i]) {
            hammingDistance++;
        }
    }
    *hamming = hammingDistance;
}

//Handles prompting the user
void promptUser(string compStr) {
    cout<<"Enter a substring: ";
    string subStr;
    cin>>subStr;
    int index, hamming;
    calculateBestMatch(&index, &hamming, compStr,  subStr);

    //Check the hamming score to see if a match was found
    if(hamming < (subStr.size()) && index != -1) {
        //A match was found, so print out some info about it
        cout<<"Match: "<<compStr.substr(index, subStr.size())<<endl;
        cout<<"Index: "<<index<<endl;
        cout<<"Hamming score: "<<hamming<<endl;
        cout<<"Similarity score: "<<(subStr.size() - (double)hamming) / subStr.size();
    } else {
        cout<<"Match not found."<<endl;
    }
}









