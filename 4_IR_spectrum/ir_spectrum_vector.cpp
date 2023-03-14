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
        //concatenating the original string with the value of "peak", using the "std::to_string" function.
        if (peak >= 2850 && peak <= 2970) {
            functionalGroups.push_back("Alkenes "  + std::to_string(peak)); 
        }
        
        // Check if the peak falls within any of the ranges for Alkenes (-C=C - H)
        if ((peak >= 1340 && peak <= 1470) || (peak >= 3010 && peak <= 3095) || (peak >= 675 && peak <= 995)) {
            functionalGroups.push_back("Alkenes (-C=C - H) " + std::to_string(peak));
        }
        
        // Check if the peak is equal to the value for Alkynes (-C≡C- H)
        if (peak == 3300) {
            functionalGroups.push_back("Alkynes (-C≡C- H) "+ std::to_string(peak));
        }
        
        // Check if the peak falls within any of the ranges for Aromatic rings
        if ((peak >= 3010 && peak <= 3100) || (peak >= 690 && peak <=900)) {
            functionalGroups.push_back("Aromatic rings " + std::to_string(peak));
        }
        
        // Check if the peak falls within any of the ranges for Monomeric alcohols, phenols or Hydrogen-bonded alcohols, phenols
        if ((peak >=3590 && peak <=3650) || (peak >=3200 && peak <=3600)) {
            functionalGroups.push_back("Monomeric alcohols, phenols or Hydrogen-bonded alcohols, phenols " + std::to_string(peak));
        }
        
         // Check if the peak falls within any of the ranges for Monomeric carboxylic acids or Hydrogen-bonded carboxylic acids
         if ((peak >=3500 && peak <=3650) || (peak >=2500 && peak<=2700)) {
             functionalGroups.push_back("Monomeric carboxylic acids or Hydrogen-bonded carboxylic acids " + std::to_string(peak));
         }

         // Check if the value falls within range for Amines or amides 
         if(peak>=3300&&peak<=3500){
             functionalGroups.push_back("Amines or amides " + std::to_string(peak));
         } 
    }  

    // Return the vector of functional groups
    return functionalGroups;  
}

int main() {

    double userInput;
    vector<string> testFunctionalGroups;
    vector<double> peaks = {468.70, 524.64, 603.72, 682.80, 700.16, 746.45, 779.24, 848.68, 914.26, 948.98, 1024.20, 1074.35, 1161.15, 1226.73, 1305.81, 1409.96, 1508.33, 1560.41, 1625.99, 2117.84, 2360.87, 2964.59, 3037.89};

    testFunctionalGroups = findFunctionalGroups(peaks);
    
    // Print out each element in testFunctionalGroups using a loop 
    cout << "The possible functional groups are: " << endl;
    for (string group : testFunctionalGroups) {
        cout << group << endl;
    }
    return 0;
}
