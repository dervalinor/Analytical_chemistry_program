#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
This code allows you to identify the functional groups present in an IR spectrum by passing its 
peaks as a vector called "peaks". The code defines a function called "identifyGroup" that takes a peak and a vector of pairs, where each pair contains the name of a functional group and its corresponding IR frequency range. The function loops through the vector and returns the name of the functional group if the peak falls 
within the frequency range of that group. If the peak does not match any group, the function returns "Unknown".
*/

vector<string> identifyGroup(double peak, vector<pair<string, pair<double, double>>> data) {
    vector<string> result(3); // initialize the result vector with size 3
    //auto is shorhand to access each element of a pair vector
    for (auto d : data) {
        if (peak >= d.second.first && peak <= d.second.second) {
            result[0] = d.first; // store the first value in the result vector
            result[1] = to_string(d.second.first); // store the second value in the result vector as a string
            result[2] = to_string(d.second.second); // store the third value in the result vector as a string
            return result;
        }
    }

    // if the peak value is not within any of the ranges, return "Unknown" for all three values
    result[0] = "Unknown";
    result[1] = "Unknown";
    result[2] = "Unknown";
    return result;
}


/*
In the main function, the code defines a vector of peaks and a vector of functional groups with 
their corresponding frequency ranges. It then loops through the peaks vector, calling the identifyGroup function for each peak and printing the result. If the peak matches a functional group, the code also prints the intensity of the peak for that group. If the peak does not match any group, 
the code prints a message indicating that it does not match any functional group in the table.

Note:Git version 2.23 introduced two new commands: `git switch` and `git restore`. These commands were introduced to split the functionality of the `git checkout` command into two separate commands⁴.

- `git switch`: This command is used to switch between branches or restore working tree files⁴.

- `git restore`: This command is used to restore working tree files or unstage changes⁴.

These are relatively new commands that were introduced in August 2019. Is there anything else you would like me to explain?

ソース: Bing との会話 3/18/2023(1) Git 2.23 released with two new commands ‘git switch’ and ‘git restore .... https://hub.packtpub.com/git-2-23-released-with-two-new-commands-git-switch-and-git-restore-a-new-tutorial-and-much-more/ アクセス日時 3/18/2023.
(2) Git 2.23 released with two new commands ‘git switch’ and ‘git restore .... https://bing.com/search?q=new+git+commands アクセス日時 3/18/2023.
(3) Basic GIT Commands: A Complete Cheat Sheet for Beginners. https://www.hostinger.com/tutorials/basic-git-commands アクセス日時 3/18/2023.
(4) Git cheatsheet - GitHub Docs. https://docs.github.com/en/get-started/quickstart/git-cheatsheet アクセス日時 3/18/2023. */

int main() {

    vector<double> peaks = {468.70, 524.64, 603.72, 682.80, 700.16, 746.45, 779.24, 848.68, 914.26, 948.98, 1024.20, 1074.35, 1161.15, 1226.73, 1305.81, 1409.96, 1508.33, 1560.41, 1625.99, 2117.84, 2360.87, 2964.59, 3037.89};
    vector<pair<string, pair<double, double>>> data = {
        {"C-H (Alkanes)", {2850, 2970}},
        {"C-H (Alkanes)", {1340, 1470}},
        {"C-H (Alkenes, -C=C-H)", {3010, 3095}},
        {"C-H (Alkenes, -C=C-H)", {675, 995}},
        {"C-H (Alkynes, -C≡C-H)", {3300, 3300}},
        {"C-H (Aromatic rings)", {3010, 3100}},
        {"C-H (Aromatic rings)", {690, 900}},
        {"O-H (Monomeric alcohols, phenols)", {3590, 3650}},
        {"O-H (Hydrogen-bonded alcohols, phenols)", {3200, 3600}},
        {"O-H (Monomeric carboxylic acids)", {3500, 3650}},
        {"O-H (Hydrogen-bonded carboxylic acids)", {2500, 2700}},
        {"N-H (Amines, amides)", {3300, 3500}},
        {"C=C (Alkenes)", {1610, 1680}},
        {"C=C (Aromatic rings)", {1500, 1600}},
        {"C≡C (Alkynes)", {2100, 2260}},
        {"C-N (Amines, amides)", {1180, 1360}},
        {"C≡N (Nitriles)", {2210, 2280}},
        {"C-O (Alcohols, ethers, carboxylic acids, esters)", {1050, 1300}},
        {"C=O (Aldehydes, ketones, carboxylic acids, esters)", {1690, 1760}},
        {"NO2 (Nitro compounds)", {1500, 1570}},
        {"NO2 (Nitro compounds)", {1300, 1370}}
    };

    for (double peak : peaks) {
        vector<string> group = identifyGroup(peak, data); //remember to called a function
        //vector string declare a function vector string
        if (group[0] != "Unknown") { //to access to name of the group functional
            cout << "Peak at " << peak << " cm-1 belongs to [ " << group[0] << ", "<< group[1] << ", " << group[2] << " ]" << endl;
        } else {
            cout << "Peak at " << peak << " cm-1 does not match any functional group in the table." << endl;
        }
    }

    return 0;
}
