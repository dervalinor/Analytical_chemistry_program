#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a function that takes a vector of peaks and returns a vector of functional groups
vector<string> findFunctionalGroups(vector<double> peaks){
    // Define a vector to store possible functional groups
    vector<string> functionalGroups;
    
    // Loop through each peak in the peaks vector
    for (double peak : peaks) {
        // Check if the peak falls within the range for Alkenes
        if (peak >= 2850 && peak <= 2970) {
            functionalGroups.push_back("Alkenes"); 
        }
        
        // Check if the peak falls within any of the ranges for Alkenes (-C=C - H)
        if ((peak >= 1340 && peak <= 1470) || (peak >= 3010 && peak <= 3095) || (peak >= 675 && peak <= 995)) {
            functionalGroups.push_back("Alkenes (-C=C - H)");
        }
        
        // Check if the peak is equal to the value for Alkynes (-C≡C- H)
        if (peak == 3300) {
            functionalGroups.push_back("Alkynes (-C≡C- H)");
        }
        
        // Check if the peak falls within any of the ranges for Aromatic rings
        if ((peak >= 3010 && peak <= 3100) || (peak >= 690 && peak <=900)) {
            functionalGroups.push_back("Aromatic rings");
        }
        
        // Check if the peak falls within any of the ranges for Monomeric alcohols, phenols or Hydrogen-bonded alcohols, phenols
        if ((peak >=3590 && peak <=3650) || (peak >=3200 && peak <=3600)) {
            functionalGroups.push_back("Monomeric alcohols, phenols or Hydrogen-bonded alcohols, phenols");
        }
        
         // Check if the peak falls within any of the ranges for Monomeric carboxylic acids or Hydrogen-bonded carboxylic acids
         if ((peak >=3500 && peak <=3650) || (peak >=2500 && peak<=2700)) {
             functionalGroups.push_back("Monomeric carboxylic acids or Hydrogen-bonded carboxylic acids");
         }

         // Check if the value falls within range for Amines or amides 
         if(peak>=3300&&peak<=3500){
             functionalGroups.push_back("Amines or amides");
         } 
    }  

    // Return the vector of functional groups
    return functionalGroups;  
}

int main() {
    
    int n;
    // Define a vector of absorption peaks
    // Declare a variable to store each user input 
    double userInput;
    vector<string> testFunctionalGroups;
    vector<double> peaks; //no use peaks(n), create problem in memory

    cout << "How many peaks do you want to enter?: "; cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Enter value #" << i << ":"; cin >> userInput; 
        peaks.push_back(userInput);//It makes the vector grow dynamically
    }

    testFunctionalGroups = findFunctionalGroups(peaks);
    
    // Print out each element in testFunctionalGroups using a loop 
    cout << "The possible functional groups are: " << endl;
    for (string group : testFunctionalGroups) {
        cout << group << endl;
    }
    return 0;
}
